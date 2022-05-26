%{
    #include <stdio.h> 
    #include <stdlib.h> 
    #include <stdarg.h> 
    #include <string.h> 
    #include "header.h"
    FILE *yyin;
    extern int yylex(void);
    extern void yyerror(char *);
    int tokenValId = 0; 
    int tokensVal [10];

    int scopeId = 0;
    
    void DecAndInit(char* VarName, int scopeID, int* type, int* isconst)
    {
        if(strcmp (GetInfo($1.lexeme,scopeId,type,isconst,isset), (char*)"1") != 0)
        {   printf("VAR %s :not declared scopeId:%d",$1.lexeme,scopeId);
            exit(0);
        }else if(isset != 1){
        printf("VAR %s :not initialized scopeId:%d",$1.lexeme,scopeId);
            exit(0);
        }
    }

%}

%union {
    int intVal;    
    char charVal;               
	float floatVal; 
	char* varName; 

    struct mathinfo{
    int typeId; //0-int, 1-float, 2-char, 3-bool
    int ival;
    float fval;
    int bval;
  }mathinfo;    

  struct logicinfo{
    int bval; //0-false, 1-true
  }logicinfo;  
  struct varinfo{
    int typeId; //0-int, 1-float, 2-char, 3-bool
    int ival;
    float fval;
    int bval; //0-false, 1-true
    char cval;
    char* lexeme;
  }varinfo;                           
};



%token SCOPE_OPEN SCOPE_CLOSE CONST BOOL TRUE FALSE INT FLOAT CHAR MULTIPLY DIVISIDE PLUS MINUS EQUAL IF_STATMENT THEN ELSE ELSE_IF WHILE FOR SWITCH_STATEMENT CASE REPEAT_STATEMENT UNTILL VAR END_EXPR
%token BREAK DEFAULT COLON COMMA RETURN IS MATCH
%token GreaterThanOrEqual LessThanOrEqual EqualEqual NotEqual LessThan GreaterThan OR AND NOT
%token <intVal> INT_VALUE
%token <floatVal> DECIMAL_VALUE              
%token <charVal> CHAR_VALUE

%type <mathinfo> factor term math_expr
%type <logicinfo> logic_expr 
%type <varinfo> VAR 

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


var_declaration : INT VAR                           {
                                                        char* res = InserNewElementInitial(0,0,$2.lexeme,scopeId);
                                                        yyerror(res);
                                                    }
                | FLOAT VAR                         {
                                                        char* res = InserNewElementInitial(1,0,$2.lexeme,scopeId);
                                                        yyerror(res);
                                                    }
                | BOOL VAR                          {
                                                        char* res = InserNewElementInitial(3,0,$2.lexeme,scopeId);
                                                        yyerror(res);
                                                    } 
                | CHAR VAR                          {
                                                        char* res = InserNewElementInitial(2,0,$2.lexeme,scopeId);
                                                        yyerror(res);
                                                    }
                | INT VAR EQUAL math_expr           {
                                                        //check math_expr type
                                                        if($4.typeId != 0 && $4.typeId != 1)
                                                            yyerror("ERROR: Invalid variable assignment");
                                                        char  cval[10];
                                                        if($4.typeId == 0)
                                                        {
                                                            sprintf(cval, "%d", $4.ival);
                                                        } 
                                                        else sprintf(cval, "%f", $4.fval);
                                                        char* res = InserNewElement(0,0,$2.lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }
                                                    } 
                | FLOAT VAR EQUAL math_expr         {
                                                        //check math_expr type
                                                        if($4.typeId != 0 && $4.typeId != 1)
                                                            yyerror("ERROR: Invalid variable assignment type mismatch");
                                                        char  cval[15];
                                                        if($4.typeId == 0)
                                                        {
                                                            sprintf(cval, "%d", $4.ival);
                                                        } 
                                                        else sprintf(cval, "%f", $4.fval);
                                                        char* res = InserNewElement(1,0,$2.lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }
                                                    }
                | BOOL VAR EQUAL logic_expr         {
                                                        char  cval[1];
                                                        sprintf(cval, "%d", $4.bval);
                                                        char* res = InserNewElement(3,0,$2.lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }
                                                    }
                | CHAR VAR EQUAL CHAR_VALUE         {
                                                        char  cval[1];
                                                        cval[0] = $4;
                                                        char* res = InserNewElement(2,0,$2.lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }
                                                    }
                | INT VAR EQUAL FUNCTION_CALL 
                | FLOAT VAR EQUAL FUNCTION_CALL
                | BOOL VAR EQUAL FUNCTION_CALL
                | CHAR VAR EQUAL FUNCTION_CALL
                ;

const_declaration : CONST INT VAR EQUAL math_expr  {
                                                        //check math_expr type
                                                        if($5.typeId != 0 && $5.typeId != 1)
                                                            yyerror("ERROR: Invalid CONST assignment");
                                                        char  cval[10];
                                                        if($5.typeId == 0)
                                                        {
                                                            sprintf(cval, "%d", $5.ival);
                                                        } 
                                                        else sprintf(cval, "%f", $5.fval);
                                                        char* res = InserNewElement(0,1,$3.lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }
                                                    } 
                  | CONST FLOAT VAR EQUAL math_expr     {
                                                        //check math_expr type
                                                        if($5.typeId != 0 && $5.typeId != 1)
                                                            yyerror("ERROR: Invalid CONST assignment");
                                                        char  cval[10];
                                                        if($5.typeId == 0)
                                                        {
                                                            sprintf(cval, "%d", $5.ival);
                                                        } 
                                                        else sprintf(cval, "%f", $5.fval);
                                                        char* res = InserNewElement(1,1,$3.lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }
                                                    } 
                  | CONST BOOL VAR EQUAL logic_expr     {
                                                        char  cval[1];
                                                        sprintf(cval, "%d", $5.bval);
                                                        char* res = InserNewElement(3,0,$3.lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }
                                                    } 
                  | CONST CHAR VAR EQUAL CHAR_VALUE     {
                                                        char  cval[1];
                                                        cval[0] = $5;
                                                        char* res = InserNewElement(2,1,$3.lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }
                                                    }
                  | CONST INT VAR EQUAL FUNCTION_CALL
                  | CONST FLOAT VAR EQUAL FUNCTION_CALL
                  | CONST BOOL VAR EQUAL FUNCTION_CALL
                  | CONST CHAR VAR EQUAL FUNCTION_CALL
                  ;
   
math_expr: math_expr PLUS term      {   
                                        //check if the type of the expression is the same as the type of the variable
                                        if($1.typeId != $3.typeId)
                                            {
                                                printf("WARNING: Type mismatch would cause up casting\n");
                                                $$.typeId = 1;
                                                if($1.typeId == 1) $$.fval = $1.fval + $3.ival;
                                                else $$.fval = $1.ival + $3.fval;
                                                printf("float => math_expr: PLUS term() = %f\n", $$.fval);
                                            }
                                        else if($1.typeId == 0)
                                        {
                                            $$.typeId = 0;
                                            $$.ival = $1.ival + $3.ival;
                                            printf("int => math_expr: PLUS term() = %d\n", $$.ival);
                                        }
                                        else if($1.typeId == 1)
                                        {
                                            $$.typeId = 1;
                                            $$.fval = $1.fval + $3.fval;
                                            printf("float => math_expr: PLUS term() = %f\n", $$.fval);
                                        }
                                    } 
         | math_expr MINUS term     {   
                                        //check if the type of the expression is the same as the type of the variable
                                        if($1.typeId != $3.typeId)
                                            {
                                                printf("WARNING: Type mismatch would cause up casting\n");
                                                $$.typeId = 1;
                                                if($1.typeId == 1) $$.fval = $1.fval - $3.ival;
                                                else $$.fval = $1.ival - $3.fval;
                                                printf("float => math_expr: MINUS term() = %f\n", $$.fval);
                                            }
                                        else if($1.typeId == 0)
                                        {
                                            $$.typeId = 0;
                                            $$.ival = $1.ival - $3.ival;
                                            printf("int => math_expr: MINUS term() = %d\n", $$.ival);
                                        }
                                        else if($1.typeId == 1)
                                        {
                                            $$.typeId = 1;
                                            $$.fval = $1.fval - $3.fval;
                                            printf("float => math_expr: MINUS term() = %f\n", $$.fval);
                                        }
                                    } 
         | term                     { 
                                        $$.typeId = $1.typeId;
                                        if($1.typeId == 0)
                                        {   
                                            $$.ival = $1.ival;
                                            printf("int => term = %d and typeId:%d \n" , $1.ival , $1.typeId );
                                        }
                                        else {
                                            $$.fval = $1.fval;
                                            printf("float => term = %f and typeId:%d \n" , $1.fval , $1.typeId );
                                        }
                                    }
         ;

term: term MULTIPLY factor          { 
                                        //check if the type of the expression is the same as the type of the variable
                                        if($1.typeId != $3.typeId)
                                            {
                                                printf("WARNING: Type mismatch would cause up casting\n");
                                                $$.typeId = 1;
                                                if($1.typeId == 1) $$.fval = $1.fval * $3.ival;
                                                else $$.fval = $1.ival * $3.fval;
                                                printf("float => term MULTIPLY factor() = %f\n", $$.fval);
                                            }
                                        else if($1.typeId == 0)
                                        {
                                            $$.typeId = 0;
                                            $$.ival = $1.ival * $3.ival;
                                            printf("int => term MULTIPLY factor() = %d\n", $$.ival);
                                        }
                                        else if($1.typeId == 1)
                                        {
                                            $$.typeId = 1;
                                            $$.fval = $1.fval * $3.fval;
                                            printf("float => term MULTIPLY factor() = %f\n", $$.fval);
                                        }
                                    } 
    | term DIVISIDE factor          {
                                        //check if the type of the expression is the same as the type of the variable
                                        if($1.typeId != $3.typeId)
                                            {
                                                printf("WARNING: Type mismatch would cause up casting\n");
                                                $$.typeId = 1;
                                                if($1.typeId == 1) $$.fval = $1.fval / $3.ival;
                                                else $$.fval = $1.ival / $3.fval;
                                                printf("float => term / factor() = %f\n", $$.fval);
                                            }
                                        else if($1.typeId == 0)
                                        {
                                            $$.typeId = 0;
                                            $$.ival = $1.ival / $3.ival;
                                            printf("int => term / factor() = %d\n", $$.ival);
                                        }
                                        else if($1.typeId == 1)
                                        {
                                            $$.typeId = 1;
                                            $$.fval = $1.fval / $3.fval;
                                            printf("float => term / factor() = %f\n", $$.fval);
                                        }
                                    } 
    | factor                        { 
                                        $$.typeId = $1.typeId;
                                        if($1.typeId == 0)
                                        {   
                                            $$.ival = $1.ival;
                                            printf("int => factor = %d and typeId:%d \n" , $1.ival , $1.typeId );
                                        }
                                        else if($1.typeId == 0) {
                                            $$.fval = $1.fval;
                                            printf("float => factor = %f and typeId:%d \n" , $1.fval , $1.typeId );
                                        }
                                    }
    ;

factor: VAR                         {   
                                        //check if the variable is defined in the symbol table
                                        int type, isconst, isset;
                                        if(strcmp (GetInfo($1.lexeme,scopeId,&type,&isconst,&isset), (char*)"1") != 0)
                                        {   printf("VAR %s :not declared scopeId:%d",$1.lexeme,scopeId);
                                            exit(0);
                                        }else if(isset != 1){
                                            printf("VAR %s :not initialized scopeId:%d",$1.lexeme,scopeId);
                                            exit(0);
                                        }
                                        else if (type != 2 ){//not char
                                            $$.typeId = type;
                                            if (type == 0)
                                            {
                                                $$.ival = GetIntVal($1.lexeme,scopeId);
                                            }else if(type == 1) 
                                            {
                                                $$.fval = GetFloatVal($1.lexeme,scopeId);
                                            } else {
                                                $$.bval = GetBoolVal($1.lexeme,scopeId);
                                            }
                                        }else   
                                            yyerror("can't use CHAR in math_expr");
                                    } 
      | INT_VALUE                   { 
                                        $$.typeId = 0; // int type
                                        $$.ival = $1;
                                        printf("factor: INT_VALUE = %d\n",$1);
                                    } 
      | DECIMAL_VALUE               {
                                        $$.typeId = 1; // float type
                                        $$.fval = $1; // float type
                                        printf("factor: DECIMAL_VALUE = %f\n",$1);
                                    } 
      | '(' math_expr ')'           {
                                        $$.typeId = $2.typeId;
                                        if($2.typeId == 0)
                                        {   
                                            $$.ival = $2.ival;
                                            printf("int => factor: (math_expr) = %d and typeId:%d \n" , $2.ival , $2.typeId );
                                        }
                                        else {
                                            $$.fval = $2.fval;
                                            printf("float => factor: (math_expr) = %f and typeId:%d \n" , $2.fval , $2.typeId );
                                        }
                                    }
      ;

//logic_expr:TRUE

logic_expr:'(' logic_expr ')'                       {
                                                        $$.bval = $2.bval;
                                                        printf("(logic_expr) => %s\n", $$.bval ? "true" : "false");
                                                    }
          |VAR OR VAR                               {  
                                                        int type1,type2, isconst;
                                                        DecAndInit($1.lexeme,scopeId,type,isconst);
                                                        DecAndInit($3.lexeme,scopeId,type2,isconst);
                                                        if (type1 == 3 && type2 == 3 ){//type bool
                                                            $$.bval = GetBoolVal($1.lexeme,scopeId) || GetBoolVal($3.lexeme,scopeId);
                                                        }else   
                                                            yyerror("Type mismatch logic_expr");
                                                    }                              
          |logic_expr OR logic_expr                 {
                                                        $$.bval = $1.bval || $3.bval; 
                                                        printf("logic_expr || logic_expr\n")
                                                    }
          |logic_expr AND logic_expr                { 
                                                        $$.bval = $1.bval && $3.bval;
                                                        printf("logic_expr && logic_expr\n")
                                                    }
          |NOT logic_expr                           {
                                                        $$.bval = !$2.bval;
                                                        printf("!logic_expr\n")
                                                    }
          |NOT VAR                                  {
                                                        int type;
                                                        DecAndInit($2.lexeme,scopeId,type,isconst);
                                                        if (type == 3 ){//type bool
                                                            $$.bval = !GetBoolVal($2.lexeme,scopeId);
                                                        }else   
                                                            yyerror("Type mismatch logic_expr");
                                                    }
          |VAR AND logic_expr                       {
                                                        int type;
                                                        DecAndInit($1.lexeme,scopeId,type,isconst);
                                                        if (type == 3 ){//type bool
                                                            $$.bval = GetBoolVal($1.lexeme,scopeId) && $3.bval;
                                                        }else   
                                                            yyerror("Type mismatch logic_expr");
                                                    }
          |VAR AND VAR                              {
                                                         int type1,type2, isconst;
                                                        DecAndInit($1.lexeme,scopeId,type,isconst);
                                                        DecAndInit($3.lexeme,scopeId,type2,isconst);
                                                        if (type1 == 3 && type2 == 3 ){//type bool
                                                            $$.bval = GetBoolVal($1.lexeme,scopeId) && GetBoolVal($3.lexeme,scopeId);
                                                        }else   
                                                            yyerror("Type mismatch logic_expr");
                                                    }
          |logic_expr AND VAR                       {
                                                        int type;
                                                        DecAndInit($3.lexeme,scopeId,type,isconst);
                                                        if (type == 3 ){//type bool
                                                            $$.bval = GetBoolVal($3.lexeme,scopeId) && $1.bval;
                                                        }else   
                                                            yyerror("Type mismatch logic_expr");
                                                    }
          |math_expr GreaterThanOrEqual math_expr   { 
                                                        $$.bval = (($1.typeId == 0) ? $1.ival :$1.fval) >= (($3.typeId == 0) ? $3.ival :$3.fval);
                                                        printf("statement >= statement\n")
                                                    }
          |math_expr GreaterThan math_expr          {   
                                                        $$.bval = (($1.typeId == 0) ? $1.ival :$1.fval) > (($3.typeId == 0) ? $3.ival :$3.fval);
                                                        printf("statement > statement\n")
                                                    }
          |math_expr EqualEqual math_expr           {   
                                                        $$.bval = (($1.typeId == 0) ? $1.ival :$1.fval) == (($3.typeId == 0) ? $3.ival :$3.fval);
                                                        printf("statement == statement\n")
                                                    }
          |math_expr LessThanOrEqual math_expr      {   
                                                        $$.bval = (($1.typeId == 0) ? $1.ival :$1.fval) <= (($3.typeId == 0) ? $3.ival :$3.fval);
                                                        printf("statement <= statement\n")
                                                    }
          |math_expr LessThan math_expr             {
                                                        $$.bval = (($1.typeId == 0) ? $1.ival :$1.fval) < (($3.typeId == 0) ? $3.ival :$3.fval);   
                                                        printf("statement < statement\n")
                                                    }
          |math_expr NotEqual math_expr             {  
                                                        $$.bval = (($1.typeId == 0) ? $1.ival :$1.fval) != (($3.typeId == 0) ? $3.ival :$3.fval); 
                                                        printf("statement != statement\n")
                                                    }
          |VAR IS TRUE                              {
                                                        //check if the variable is defined in the symbol table
                                                        //getboolvalue($1);
                                                        printf("VAR IS TRUE\n");
                                                    }
          |VAR IS FALSE                             {
                                                        //check if the variable is defined in the symbol table
                                                        //getboolvalue($1);
                                                        printf("VAR IS FALSE\n");
                                                    }
          |VAR MATCH CHAR_VALUE                     {
                                                        //check if the variable is defined in the symbol table
                                                        //getcharvalue($1);
                                                        printf("VAR MATCH CHAR_VALUE\n");
                                                    }
          |TRUE                                     { 
                                                        $$.bval = 1;
                                                        printf("%s\n", $$.bval ? "true" : "false");
                                                    }
          |FALSE                                    {   
                                                        $$.bval = 0;
                                                        printf("%s\n", $$.bval ? "true" : "false");
                                                    }
          ;
   
 
assignment: VAR EQUAL math_expr {printf("assignment: VAR = math_expr\n");}
           | VAR EQUAL logic_expr {printf("assignment: VAR = logic_expr\n");}
           | VAR EQUAL CHAR_VALUE {printf("assignment: VAR = CHAR_VALUE\n");}
           | VAR EQUAL FUNCTION_CALL {printf("assignment: VAR = Function call\n");}
          ;

StartScope: SCOPE_OPEN  {scopeId++; NewLevel();};
EndScope: SCOPE_CLOSE  {scopeId--; removeLevel();};

scope: StartScope statements EndScope {printf("this is a scope\n")}
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
    
    PrintFunc(1000);
    NewLevel();

    /*PrintFunc(1000);
    NewLevel();
    printf("%d\n",InserNewElement(0,0,"x",0,"5"));
    
    int type;
    int isconst;
    int isset;

    GetInfo("x",0,&type,&isconst,&isset);

    printf("%d\n",type);
    printf("%d\n",isconst);
    printf("%d\n",isset);
    printf("%d\n",GetIntVal("x",0));
    printf("%d\n",UpdateVal(0,"x",0,"6"));
    printf("%d\n",GetIntVal("x",0));

    printf("%d\n",InserNewElement(1,0,"y",0,"5.3"));
    printf("%f\n",GetFloatVal("y",0));
    printf("%d\n",UpdateVal(1,"y",0,"6.7"));
    printf("%f\n",GetFloatVal("y",0));

    printf("%d\n",InserNewElement(2,0,"z",0,"a"));
    printf("%c\n",GetCharVal("z",0));
    printf("%d\n",UpdateVal(2,"z",0,"b"));
    printf("%c\n",GetCharVal("z",0));

    printf("%d\n",InserNewElement(3,0,"m",0,"1"));
    printf("%d\n",GetBoolVal("m",0));
    printf("%d\n",UpdateVal(3,"m",0,"0"));
    printf("%d\n",GetBoolVal("m",0));*/


    /*PrintFunc(1000);
    NewLevel();*

    /*printf("declared new varable %d\n",InsertNewIntElement(0,0,"y",0,0));
    printf("declared new varable %d\n",InsertNewIntElement(0,0,"y",0,0));
    printf("declared new varable %d\n",InsertNewIntElement(0,0,"y",0,0));
    printf("declared new varable %d\n",InsertNewIntElement(0,0,"y",0,0));
    printf("declared new varable %d\n",InsertNewIntElement(0,0,"x",0,0));
    printf("declared new varable %d\n",InsertNewIntElement(0,0,"x",0,0));*/

    /*printf("%d\n",InsertNewIntElement(0,0,"x",0,5));
    printf("%d\n",InsertNewIntElement(0,0,"x",0,6));
    printf("%d\n",UpdateIntVal(0,0,"x",0,6));
    NewLevel();
    printf("%d\n",InsertNewIntElement(0,0,"x",1,5));
    printf("%d\n",InsertNewIntElement(0,0,"x",1,5));
    removeLevel();
    printf("%d\n",InsertNewIntElement(0,0,"x",0,5));
    removeLevel();*/

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