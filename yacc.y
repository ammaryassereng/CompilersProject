%{
    #include <stdio.h> 
    #include <stdlib.h> 
    #include <stdarg.h> 
    #include <string.h> 
    FILE *yyin;
    extern int yylex(void);
    extern void yyerror(char *);
    int tokenValId = 0; 
    int tokensVal [10];
%}

%union {
    int intVal;    
    char charVal;               
	float floatVal;                            
};



%token SCOPE_OPEN SCOPE_CLOSE CONST BOOL TRUE FALSE INT FLOAT CHAR MULTIPLY DIVISIDE PLUS MINUS EQUAL IF_STATMENT THEN ELSE ELSE_IF WHILE FOR SWITCH_STATEMENT CASE REPEAT_STATEMENT UNTILL VAR END_EXPR
%token BREAK DEFAULT COLON COMMA RETURN IS MATCH
%token GreaterThanOrEqual LessThanOrEqual EqualEqual NotEqual LessThan GreaterThan OR AND NOT
%token <intVal> INT_VALUE
%token <floatVal> DECIMAL_VALUE              
%token <charVal> CHAR_VALUE
%nonassoc OR 
%nonassoc AND
%nonassoc NOT 
%nonassoc IFX      
%nonassoc ELSE
%right EQUAL
%left GreaterThanOrEqual LessThanOrEqual EqualEqual NotEqual GreaterThan LessThan
%left PLUS MINUS
%left MULTIPLY DIVISIDE

%%

program : statements {printf("program: program statements\n\n");}
        |                   {printf("program: Epsilon\n\n");}
        ;
statements : statements statement
           | statement 


statement : var_declaration END_EXPR
          | const_declaration END_EXPR
          | math_expr END_EXPR {printf("statement: expr()\n");} 
          | logic_expr END_EXPR
          | assignment END_EXPR
          | scope
          | if_clause {printf("statement: IF()\n");}
          //| MIF
          //| UIF
          | while_loop
          | for_loop
          | switch_case
          | BREAK END_EXPR
          | REPEATUNTILL
          | FUNCTION_STATEMENT
          | FUNCTION_CALL END_EXPR
          | RETURN_STATEMENT END_EXPR 
        ;


var_declaration : INT VAR 
                | FLOAT VAR 
                | BOOL VAR 
                | CHAR VAR 
                | INT VAR EQUAL math_expr 
                | FLOAT VAR EQUAL math_expr 
                | BOOL VAR EQUAL logic_expr  
                | CHAR VAR EQUAL CHAR_VALUE
                | INT VAR EQUAL FUNCTION_CALL 
                | FLOAT VAR EQUAL FUNCTION_CALL
                | BOOL VAR EQUAL FUNCTION_CALL
                | CHAR VAR EQUAL FUNCTION_CALL
                ;

const_declaration : CONST INT VAR EQUAL math_expr 
                  | CONST FLOAT VAR EQUAL math_expr 
                  | CONST BOOL VAR EQUAL logic_expr 
                  | CONST CHAR VAR EQUAL CHAR_VALUE
                  | CONST INT VAR EQUAL FUNCTION_CALL
                  | CONST FLOAT VAR EQUAL FUNCTION_CALL
                  | CONST BOOL VAR EQUAL FUNCTION_CALL
                  | CONST CHAR VAR EQUAL FUNCTION_CALL
                  ;
   
math_expr: math_expr PLUS term {printf("math_expr: PLUS term() = %d\n",tokensVal[tokenValId-2] + tokensVal[tokenValId-1] );} 
         | math_expr MINUS term {printf("math_expr: MINUS term()\n");} 
         | term {printf("math_expr: term()\n");}
         ;

term: term MULTIPLY factor {printf("term: * factor()\n");} 
    | term DIVISIDE factor {printf("term: / factor()\n");} 
    | factor {printf("factor() = %d \n" , tokensVal[tokenValId - 1]);}
    ;
factor: VAR {printf("factor: VARs\n");} 
      | INT_VALUE { tokensVal[tokenValId++] = $1; printf("factor: INT_VALUE = %d\n",$1);} 
      | DECIMAL_VALUE { printf("factor: DECIMAL_VALUE = %d\n",$1);} 
      | '(' math_expr ')' {printf("factor: (math_expr))\n");}
      ;

//logic_expr:TRUE

logic_expr:'(' logic_expr ')'                              {printf("(logic_expr)\n")}
          |logic_expr OR logic_expr                 {printf("logic_expr || logic_expr\n")}
          |logic_expr AND logic_expr                {printf("logic_expr && logic_expr\n")}
          |NOT logic_expr                           {printf("!logic_expr\n")}
          |math_expr GreaterThanOrEqual math_expr {printf("statement >= statement\n")}
          |math_expr GreaterThan math_expr        {printf("statement > statement\n")}
          |math_expr EqualEqual math_expr         {printf("statement == statement\n")}
          |math_expr LessThanOrEqual math_expr    {printf("statement <= statement\n")}
          |math_expr LessThan math_expr           {printf("statement < statement\n")}
          |math_expr NotEqual math_expr           {printf("statement != statement\n")}
          |VAR IS TRUE
          |VAR IS FALSE
          |VAR MATCH CHAR_VALUE
          |TRUE                                     {printf("True\n")}
          |FALSE                                    {printf("False\n")}
          ;
   
 
assignment: VAR EQUAL math_expr {printf("assignment: VAR = math_expr\n");}
           | VAR EQUAL logic_expr {printf("assignment: VAR = logic_expr\n");}
           | VAR EQUAL CHAR_VALUE {printf("assignment: VAR = CHAR_VALUE\n");}
           | VAR EQUAL FUNCTION_CALL {printf("assignment: VAR = Function call\n");}
          ;

scope: SCOPE_OPEN statements SCOPE_CLOSE {printf("this is a scope\n")}
     ;

if_clause: IF_STATMENT logic_expr THEN statement %prec IFX  {printf("if-then")}
   | IF_STATMENT logic_expr THEN statement ELSE statement   {printf("if-else")}
   ;
/*

MIF: IF_STATMENT '(' logic_expr ')' THEN MIF ELSE MIF
            | OTHER
            ;
UIF: IF_STATMENT '(' logic_expr ')' THEN statement
            | IF_STATMENT '(' logic_expr ')' THEN MIF ELSE UIF
            ;

OTHER : statement;
*/
while_loop: WHILE '(' logic_expr ')' scope

for_loop: FOR '(' assignment END_EXPR logic_expr END_EXPR assignment ')' scope  

switch_case: SWITCH_STATEMENT '(' VAR ')'  switch_body

switch_body: CASE INT_VALUE COLON statements BREAK END_EXPR switch_body
            | CASE TRUE COLON statements BREAK END_EXPR switch_body
            | CASE FALSE COLON statements BREAK END_EXPR switch_body
            | CASE DECIMAL_VALUE COLON statements BREAK END_EXPR switch_body
            | CASE CHAR_VALUE COLON statements BREAK END_EXPR switch_body
            | DEFAULT COLON statements BREAK 
            ;

REPEATUNTILL: REPEAT_STATEMENT scope UNTILL logic_expr 
            ;

FUNCTION_STATEMENT: FUNCTION_DEFINITION scope;

FUNCTION_DEFINITION: INT VAR '(' PARAMETERS ')'
                   | FLOAT VAR '(' PARAMETERS ')'
                   | BOOL VAR '(' PARAMETERS ')'
                   | CHAR VAR '(' PARAMETERS ')'
                   ;

PARAMETERS: PARAMETERS COMMA INT VAR
          | PARAMETERS COMMA FLOAT VAR
          | PARAMETERS COMMA BOOL VAR
          | PARAMETERS COMMA CHAR VAR
          | INT VAR
          | FLOAT VAR
          | BOOL VAR
          | CHAR VAR
          ;

FUNCTION_CALL: VAR '(' CALL_PARAMETERS ')'  {printf("function_call \n");}
             ;

CALL_PARAMETERS: CALL_PARAMETERS COMMA DATA | DATA {printf("call parameters\n");} ;

DATA : VAR              {printf("Data Var \n");}      
     | INT_VALUE        {printf("Data int \n");}
     | DECIMAL_VALUE    {printf("Data floa \nt");}
     | CHAR_VALUE       {printf("Data char \n");}
     | logic_expr       {printf("Data bool \n");}
     ;

RETURN_STATEMENT: RETURN VAR            {printf("return Var \n");}
                | RETURN INT_VALUE      {printf("return int \n");}
                | RETURN DECIMAL_VALUE  {printf("return float \n");}
                | RETURN CHAR_VALUE     {printf("return char \n");}
                | RETURN logic_expr     {printf("return bool \n");}
                | RETURN                {printf("return \n");}
                ;

%%

int main (void) {
    /*yyin = fopen("testfile.txt","r+");
    if(yyin ==NULL){
        printf("File Not Found\n");
    }
    else
    {
        printf(">>>> Parsing the File <<<<\n\n"); 
        yyparse();
    }
    fclose(yyin);*/
    yyparse();
    return 0;
}