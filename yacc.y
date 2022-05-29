%{
    #include <stdio.h> 
    #include <stdlib.h> 
    #include <stdarg.h> 
    #include <string.h> 
    #include "header.h"
    FILE *yyin;
    extern int yylex(void);
    extern void yyerror(char *);
    extern void quad(char*, char*, char*, char*);
    extern char* fromFloatToChar(float);
    extern char* fromIntToChar(int);
    extern char* fromBoolToChar(int);
    extern char* fromCharToChar(char);
    int tokenValId = 0; 
    int tokensVal [10];

    int scopeId = 0;
    
    void DecAndInit(char* VarName, int scopeID, int* type, int* isconst)
    {
        int isset;
        if(strcmp (GetInfo(VarName,scopeId,type,isconst,&isset), (char*)"1") != 0)
        {   printf("VAR %s :not declared scopeId:%d",VarName,scopeId);
            //exit(0);
        }else if(isset != 1){
        printf("VAR %s :not initialized scopeId:%d",VarName,scopeId);
            //exit(0);
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

  struct FunctionCallInfo{
      int typeId;
      char* lexeme;
  }FunctionCallInfo;            
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
%type <FunctionCallInfo> FUNCTION_CALL

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
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                        }
                                                        printf("var_declaration: INT VAR %s\n",$2.lexeme);
                                                        
                                                    }
                | FLOAT VAR                         {
                                                        char* res = InserNewElementInitial(1,0,$2.lexeme,scopeId);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                        }
                                                    }
                | BOOL VAR                          {
                                                        char* res = InserNewElementInitial(3,0,$2.lexeme,scopeId);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                        }
                                                    } 
                | CHAR VAR                          {
                                                        char* res = InserNewElementInitial(2,0,$2.lexeme,scopeId);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                        }
                                                    }
                | INT VAR EQUAL math_expr           {
                                                        //check math_expr type
                                                        if($4.typeId != 0 && $4.typeId != 1)
                                                            yyerror("ERROR: Invalid variable assignment");
                                                        char  cval[10];
                                                        if($4.typeId == 0)
                                                        {
                                                            sprintf(cval, "%d", $4.ival);
                                                            quad("MOV", $2.lexeme, cval,"");
                                                        } 
                                                        else 
                                                        {
                                                            sprintf(cval, "%f", $4.fval);
                                                            quad("MOV", $2.lexeme, cval,"");
                                                        }
                                                        char* res = InserNewElement(0,0,$2.lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            //exit(0);
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
                                                            quad("MOV", $2.lexeme, cval,"");
                                                        } 
                                                        else
                                                        {
                                                            sprintf(cval, "%f", $4.fval);
                                                            quad("MOV", $2.lexeme, cval,"");
                                                        }
                                                        char* res = InserNewElement(1,0,$2.lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            //exit(0);
                                                        }
                                                    }
                | BOOL VAR EQUAL logic_expr         {
                                                        char  cval[1];
                                                        sprintf(cval, "%d", $4.bval);
                                                        quad("MOV", $2.lexeme, cval,"");
                                                        char* res = InserNewElement(3,0,$2.lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            //exit(0);
                                                        }
                                                    }
                | CHAR VAR EQUAL CHAR_VALUE         {
                                                        char  cval[1];
                                                        cval[0] = $4;
                                                        char* res = InserNewElement(2,0,$2.lexeme,scopeId,cval);
                                                        quad("MOV", $2.lexeme, fromCharToChar($4) ,"");
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            //exit(0);
                                                        }
                                                    }
                | INT VAR EQUAL FUNCTION_CALL       {
                                                        char * res = GetFuncInfo($4.lexeme,scopeId,0);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            ////exit(0);
                                                        }
                                                        else
                                                        {
                                                            res = InserNewElementInitial(0,0,$2.lexeme,scopeId);
                                                            if(strcmp (res, (char *)"1") != 0)
                                                            {
                                                                yyerror(res);
                                                            }
                                                            printf("var_declaration: INT VAR %s\n",$2.lexeme); 
                                                        }
                                                    } 
                | FLOAT VAR EQUAL FUNCTION_CALL     {
                                                        char * res = GetFuncInfo($4.lexeme,scopeId,1);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            ////exit(0);
                                                        }
                                                        else
                                                        {
                                                            res = InserNewElementInitial(1,0,$2.lexeme,scopeId);
                                                            if(strcmp (res, (char *)"1") != 0)
                                                            {
                                                                yyerror(res);
                                                            }
                                                            printf("var_declaration: FLOAT VAR %s\n",$2.lexeme); 
                                                        }
                                                    }
                | BOOL VAR EQUAL FUNCTION_CALL      {
                                                        char * res = GetFuncInfo($4.lexeme,scopeId,3);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            ////exit(0);
                                                        }
                                                        else
                                                        {
                                                            res = InserNewElementInitial(3,0,$2.lexeme,scopeId);
                                                            if(strcmp (res, (char *)"1") != 0)
                                                            {
                                                                yyerror(res);
                                                            }
                                                            printf("var_declaration: BOOL VAR %s\n",$2.lexeme); 
                                                        }
                                                    }
                | CHAR VAR EQUAL FUNCTION_CALL      {
                                                        char * res = GetFuncInfo($4.lexeme,scopeId,2);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            ////exit(0);
                                                        }
                                                        else
                                                        {
                                                            res = InserNewElementInitial(2,0,$2.lexeme,scopeId);
                                                            if(strcmp (res, (char *)"1") != 0)
                                                            {
                                                                yyerror(res);
                                                            }
                                                            printf("var_declaration: CHAR VAR %s\n",$2.lexeme); 
                                                        }
                                                    }    
                ;

const_declaration : CONST INT VAR EQUAL math_expr  {
                                                        //check math_expr type
                                                        if($5.typeId != 0 && $5.typeId != 1)
                                                            yyerror("ERROR: Invalid CONST assignment");
                                                        char  cval[10];
                                                        if($5.typeId == 0)
                                                        {
                                                            sprintf(cval, "%d", $5.ival);
                                                            quad("MOV", $3.lexeme, cval,"");
                                                        } 
                                                        else 
                                                        {
                                                            sprintf(cval, "%f", $5.fval);
                                                            quad("MOV", $3.lexeme, cval,"");
                                                        }
                                                        char* res = InserNewElement(0,1,$3.lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            //exit(0);
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
                                                            quad("MOV", $3.lexeme, cval,"");
                                                        } 
                                                        else 
                                                        {
                                                            sprintf(cval, "%f", $5.fval);
                                                            quad("MOV", $3.lexeme, cval,"");
                                                        }
                                                        char* res = InserNewElement(1,1,$3.lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            //exit(0);
                                                        }
                                                    } 
                  | CONST BOOL VAR EQUAL logic_expr     {
                                                        char  cval[1];
                                                        sprintf(cval, "%d", $5.bval);
                                                        quad("MOV", $3.lexeme, cval,"");
                                                        char* res = InserNewElement(3,1,$3.lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            //exit(0);
                                                        }
                                                    } 
                  | CONST CHAR VAR EQUAL CHAR_VALUE     {
                                                        char  cval[1];
                                                        cval[0] = $5;
                                                        quad("MOV", $3.lexeme, cval,"");
                                                        char* res = InserNewElement(2,1,$3.lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            //exit(0);
                                                        }
                                                    }
                  | CONST INT VAR EQUAL FUNCTION_CALL   {
                                                            char * res = GetFuncInfo($5.lexeme,scopeId,0);
                                                            if(strcmp (res, (char *)"1") != 0)
                                                            {
                                                                yyerror(res);
                                                                ////exit(0);
                                                            }
                                                            else
                                                            {
                                                                res = InserNewElementInitial(0,1,$3.lexeme,scopeId);
                                                                if(strcmp (res, (char *)"1") != 0)
                                                                {
                                                                    yyerror(res);
                                                                }
                                                                printf("const var_declaration: INT VAR %s\n",$3.lexeme); 
                                                            }
                                                        }  
                  | CONST FLOAT VAR EQUAL FUNCTION_CALL {
                                                            char * res = GetFuncInfo($5.lexeme,scopeId,1);
                                                            if(strcmp (res, (char *)"1") != 0)
                                                            {
                                                                yyerror(res);
                                                                ////exit(0);
                                                            }
                                                            else
                                                            {
                                                                res = InserNewElementInitial(1,1,$3.lexeme,scopeId);
                                                                if(strcmp (res, (char *)"1") != 0)
                                                                {
                                                                    yyerror(res);
                                                                }
                                                                printf("const var_declaration: FLOAT VAR %s\n",$3.lexeme); 
                                                            }
                                                        }
                  | CONST BOOL VAR EQUAL FUNCTION_CALL  {
                                                            char * res = GetFuncInfo($5.lexeme,scopeId,3);
                                                            if(strcmp (res, (char *)"1") != 0)
                                                            {
                                                                yyerror(res);
                                                                ////exit(0);
                                                            }
                                                            else
                                                            {
                                                                res = InserNewElementInitial(3,1,$3.lexeme,scopeId);
                                                                if(strcmp (res, (char *)"1") != 0)
                                                                {
                                                                    yyerror(res);
                                                                }
                                                                printf("const var_declaration: BOOL VAR %s\n",$3.lexeme); 
                                                            }
                                                        }
                  | CONST CHAR VAR EQUAL FUNCTION_CALL  {
                                                            char * res = GetFuncInfo($5.lexeme,scopeId,2);
                                                            if(strcmp (res, (char *)"1") != 0)
                                                            {
                                                                yyerror(res);
                                                                ////exit(0);
                                                            }
                                                            else
                                                            {
                                                                res = InserNewElementInitial(2,1,$3.lexeme,scopeId);
                                                                if(strcmp (res, (char *)"1") != 0)
                                                                {
                                                                    yyerror(res);
                                                                }
                                                                printf("const var_declaration: CHAR VAR %s\n",$3.lexeme); 
                                                            }
                                                        }
                  ;
   
math_expr: math_expr PLUS term      {   
                                        //check if the type of the expression is the same as the type of the variable
                                        if($1.typeId != $3.typeId)
                                            {
                                                yyerror("WARNING: Type mismatch would cause up casting\n");
                                                $$.typeId = 1;
                                                if($1.typeId == 1) 
                                                {
                                                    $$.fval = $1.fval + $3.ival;
                                                    quad("ADD", fromFloatToChar($$.fval), fromFloatToChar($1.fval), fromIntToChar($3.ival));
                                                }
                                                else 
                                                {
                                                    $$.fval = $1.ival + $3.fval;
                                                    quad("ADD", fromFloatToChar($$.fval), fromIntToChar($1.ival), fromFloatToChar($3.fval));
                                                }
                                            }
                                        else if($1.typeId == 0)
                                        {
                                            $$.typeId = 0;
                                            $$.ival = $1.ival + $3.ival;
                                            printf("int => math_expr: PLUS term() = %d\n", $$.ival);
                                            quad("ADD", fromIntToChar($$.ival), fromIntToChar($1.ival), fromIntToChar($3.ival));
                                        }
                                        else if($1.typeId == 1)
                                        {
                                            $$.typeId = 1;
                                            $$.fval = $1.fval + $3.fval;
                                            printf("float => math_expr: PLUS term() = %f\n", $$.fval);
                                            quad("ADD", fromFloatToChar($$.fval), fromFloatToChar($1.fval), fromFloatToChar($3.fval));
                                        }
                                        
                                    } 
         | math_expr MINUS term     {   
                                        //check if the type of the expression is the same as the type of the variable
                                        if($1.typeId != $3.typeId)
                                            {
                                                yyerror("WARNING: Type mismatch would cause up casting\n");
                                                $$.typeId = 1;
                                                if($1.typeId == 1)
                                                {
                                                    $$.fval = $1.fval - $3.ival;
                                                    quad("SUB", fromFloatToChar($$.fval), fromFloatToChar($1.fval), fromIntToChar($3.ival));
                                                } 
                                                else
                                                {
                                                    $$.fval = $1.ival - $3.fval;
                                                    quad("SUB", fromFloatToChar($$.fval), fromIntToChar($1.ival), fromFloatToChar($3.fval));
                                                } 
                                                printf("float => math_expr: MINUS term() = %f\n", $$.fval);
                                            }
                                        else if($1.typeId == 0)
                                        {
                                            $$.typeId = 0;
                                            $$.ival = $1.ival - $3.ival;
                                            printf("int => math_expr: MINUS term() = %d\n", $$.ival);
                                            quad("SUB", fromIntToChar($$.ival), fromIntToChar($1.ival), fromIntToChar($3.ival));
                                        }
                                        else if($1.typeId == 1)
                                        {
                                            $$.typeId = 1;
                                            $$.fval = $1.fval - $3.fval;
                                            printf("float => math_expr: MINUS term() = %f\n", $$.fval);
                                            quad("SUB", fromFloatToChar($$.fval), fromFloatToChar($1.fval), fromFloatToChar($3.fval));
                                        }
                                    } 
         | term                     { 
                                        $$.typeId = $1.typeId;
                                        if($1.typeId == 0)
                                        {   
                                            $$.ival = $1.ival;
                                            printf("int => term = %d and typeId:%d \n" , $1.ival , $1.typeId );
                                            //quad("MOV", fromIntToChar($$.ival), fromIntToChar($1.ival),"");
                                        }
                                        else {
                                            $$.fval = $1.fval;
                                            printf("float => term = %f and typeId:%d \n" , $1.fval , $1.typeId );
                                            //quad("MOV", fromFloatToChar($$.fval), fromFloatToChar($1.fval),"");
                                        }
                                    }
         ;

term: term MULTIPLY factor          { 
                                        //check if the type of the expression is the same as the type of the variable
                                        if($1.typeId != $3.typeId)
                                            {
                                                yyerror("WARNING: Type mismatch would cause up casting\n");
                                                $$.typeId = 1;
                                                if($1.typeId == 1) $$.fval = $1.fval * $3.ival;
                                                else $$.fval = $1.ival * $3.fval;
                                                printf("float => term MULTIPLY factor() = %f\n", $$.fval);
                                                quad("MUL", fromFloatToChar($$.fval), fromFloatToChar($1.fval), fromIntToChar($3.ival));
                                            }
                                        else if($1.typeId == 0)
                                        {
                                            $$.typeId = 0;
                                            $$.ival = $1.ival * $3.ival;
                                            printf("int => term MULTIPLY factor() = %d\n", $$.ival);
                                            quad("MUL", fromIntToChar($$.ival), fromIntToChar($1.ival), fromIntToChar($3.ival));
                                        }
                                        else if($1.typeId == 1)
                                        {
                                            $$.typeId = 1;
                                            $$.fval = $1.fval * $3.fval;
                                            printf("float => term MULTIPLY factor() = %f\n", $$.fval);
                                            quad("MUL", fromFloatToChar($$.fval), fromFloatToChar($1.fval), fromFloatToChar($3.fval));
                                        }
                                    } 
    | term DIVISIDE factor          {
                                        //check if the type of the expression is the same as the type of the variable
                                        if($1.typeId != $3.typeId)
                                            {
                                                yyerror("WARNING: Type mismatch would cause up casting\n");
                                                $$.typeId = 1;
                                                if($1.typeId == 1)
                                                { 
                                                    if($3.ival == 0)
                                                    {
                                                        yyerror("WARNING: Possible Division By zero\n");
                                                    }
                                                    else
                                                        $$.fval = $1.fval / $3.ival;
                                                }
                                                else
                                                {
                                                    if($3.fval == 0)
                                                    {
                                                        yyerror("WARNING: Possible Division By zero\n");
                                                    }
                                                    else  
                                                        $$.fval = $1.ival / $3.fval;
                                                }
                                                printf("float => term / factor() = %f\n", $$.fval);
                                                quad("DIV", fromFloatToChar($$.fval), fromFloatToChar($1.fval), fromIntToChar($3.ival));
                                            }
                                        else if($1.typeId == 0)
                                        {
                                            $$.typeId = 0;
                                            if($3.ival == 0)
                                            {
                                                yyerror("WARNING: Possible Division By zero\n");
                                            }
                                            else
                                                $$.ival = $1.ival / $3.ival;
                                            quad("DIV", fromIntToChar($$.ival), fromIntToChar($1.ival), fromIntToChar($3.ival));
                                        }
                                        else if($1.typeId == 1)
                                        {
                                            $$.typeId = 1;
                                            if($3.fval == 0)
                                            {
                                                yyerror("WARNING: Possible Division By zero\n");
                                            }
                                            else
                                                $$.fval = $1.fval / $3.fval;
                                            quad("DIV", fromFloatToChar($$.fval), fromFloatToChar($1.fval), fromFloatToChar($3.fval));
                                        }
                                    } 
    | factor                        { 
                                        $$.typeId = $1.typeId;
                                        if($1.typeId == 0)
                                        {   
                                            $$.ival = $1.ival;
                                            printf("int => factor = %d and typeId:%d \n" , $1.ival , $1.typeId );
                                            //quad("MOV", fromIntToChar($$.ival), fromIntToChar($1.ival),"");
                                        }
                                        else if($1.typeId == 1) {
                                            $$.fval = $1.fval;
                                            printf("float => factor = %f and typeId:%d \n" , $1.fval , $1.typeId );
                                            //quad("MOV", fromFloatToChar($$.fval), fromFloatToChar($1.fval),"");
                                        }
                                    }
    ;

factor: VAR                         {   
                                        //check if the variable is defined in the symbol table
                                        int type, isconst, isset;
                                        if(strcmp (GetInfo($1.lexeme,scopeId,&type,&isconst,&isset), (char*)"1") != 0)
                                        {   char var[4] = "VAR "; char ms[30] = " :not declared";
                                            yyerror(strcat(var,strcat($1.lexeme,ms)));
                                        }else if(isset != 1){
                                            char var[4] = "VAR "; char ms[30] = " :not initialized";
                                            yyerror(strcat(var,strcat($1.lexeme,ms)));
                                        }
                                        else if (type != 2 ){//not char
                                            $$.typeId = type;
                                            if (type == 0)
                                            {
                                                $$.ival = GetIntVal($1.lexeme,scopeId);
                                                //quad("MOV", fromIntToChar($$.ival), fromIntToChar(GetIntVal($1.lexeme,scopeId)),"");
                                            }else if(type == 1) 
                                            {
                                                $$.fval = GetFloatVal($1.lexeme,scopeId);
                                                //quad("MOV", fromFloatToChar($$.fval), fromFloatToChar(GetFloatVal($1.lexeme,scopeId)),"");
                                            } else {
                                                $$.bval = GetBoolVal($1.lexeme,scopeId);
                                                //quad("MOV", fromBoolToChar($$.bval), fromBoolToChar(GetBoolVal($1.lexeme,scopeId)),"");
                                            }
                                        }else   
                                            yyerror("can't use CHAR in math_expr");
                                    } 
      | INT_VALUE                   { 
                                        $$.typeId = 0; // int type
                                        $$.ival = $1;
                                        printf("factor: INT_VALUE = %d\n",$1);
                                        //quad("MOV", fromIntToChar($$.ival), fromIntToChar($1),"");
                                    } 
      | DECIMAL_VALUE               {
                                        $$.typeId = 1; // float type
                                        $$.fval = $1; // float type
                                        printf("factor: DECIMAL_VALUE = %f\n",$1);
                                        //quad("MOV", fromFloatToChar($$.fval), fromFloatToChar($1),"");
                                    } 
      | '(' math_expr ')'           {
                                        $$.typeId = $2.typeId;
                                        if($2.typeId == 0)
                                        {   
                                            $$.ival = $2.ival;
                                            printf("int => factor: (math_expr) = %d and typeId:%d \n" , $2.ival , $2.typeId );
                                            //quad("MOV", fromIntToChar($$.ival), fromIntToChar($2.ival),"");
                                        }
                                        else {
                                            $$.fval = $2.fval;
                                            printf("float => factor: (math_expr) = %f and typeId:%d \n" , $2.fval , $2.typeId );
                                            //quad("MOV", fromFloatToChar($$.fval), fromFloatToChar($2.fval),"");
                                        }
                                    }
      ;

//logic_expr:TRUE

logic_expr:'(' logic_expr ')'                       {
                                                        $$.bval = $2.bval;
                                                        printf("(logic_expr) => %s\n", $$.bval ? "true" : "false");
                                                        //quad("MOV", fromBoolToChar($$.bval), fromBoolToChar($2.bval),"");
                                                    }                              
          |logic_expr OR logic_expr                 {
                                                        $$.bval = $1.bval || $3.bval; 
                                                        quad("OR", fromBoolToChar($$.bval), fromBoolToChar($1.bval), fromBoolToChar($3.bval));
                                                    }
          |logic_expr AND logic_expr                { 
                                                        $$.bval = $1.bval && $3.bval;
                                                        quad("AND", fromBoolToChar($$.bval), fromBoolToChar($1.bval), fromBoolToChar($3.bval));
                                                    }
          |NOT logic_expr                           {
                                                        $$.bval = !$2.bval;
                                                        quad("NOT", fromBoolToChar($$.bval), fromBoolToChar($2.bval),"");
                                                    }
          |NOT VAR                                  {
                                                        int type,isconst;
                                                        DecAndInit($2.lexeme,scopeId,&type,&isconst);
                                                        if (type == 3 ){//type bool
                                                            $$.bval = !GetBoolVal($2.lexeme,scopeId);
                                                            quad("NOT", fromBoolToChar($$.bval), $2.lexeme,"");
                                                        }else   
                                                            yyerror("Type mismatch logic_expr");
                                                    }
          |math_expr GreaterThanOrEqual math_expr   { 
                                                        $$.bval = (($1.typeId == 0) ? $1.ival :$1.fval) >= (($3.typeId == 0) ? $3.ival :$3.fval);
                                                        printf("statement >= statement\n");
                                                        quad("GE", fromBoolToChar($$.bval), ($1.typeId == 0 ? fromIntToChar($1.ival) : fromFloatToChar($1.fval)), ($3.typeId == 0 ? fromIntToChar($3.ival) : fromFloatToChar($3.fval)));
                                                    }
          |math_expr GreaterThan math_expr          {   
                                                        $$.bval = (($1.typeId == 0) ? $1.ival :$1.fval) > (($3.typeId == 0) ? $3.ival :$3.fval);
                                                        printf("statement > statement\n");
                                                        quad("GT", fromBoolToChar($$.bval), ($1.typeId == 0 ? fromIntToChar($1.ival) : fromFloatToChar($1.fval)), ($3.typeId == 0 ? fromIntToChar($3.ival) : fromFloatToChar($3.fval)));
                                                    }
          |math_expr EqualEqual math_expr           {   
                                                        $$.bval = (($1.typeId == 0) ? $1.ival :$1.fval) == (($3.typeId == 0) ? $3.ival :$3.fval);
                                                        printf("statement == statement\n");
                                                        quad("EQ", fromBoolToChar($$.bval), ($1.typeId == 0 ? fromIntToChar($1.ival) : fromFloatToChar($1.fval)), ($3.typeId == 0 ? fromIntToChar($3.ival) : fromFloatToChar($3.fval)));                                                    }
          |math_expr LessThanOrEqual math_expr      {   
                                                        $$.bval = (($1.typeId == 0) ? $1.ival :$1.fval) <= (($3.typeId == 0) ? $3.ival :$3.fval);
                                                        printf("statement <= statement\n");
                                                        quad("LE", fromBoolToChar($$.bval), ($1.typeId == 0 ? fromIntToChar($1.ival) : fromFloatToChar($1.fval)), ($3.typeId == 0 ? fromIntToChar($3.ival) : fromFloatToChar($3.fval)));
                                                    }
          |math_expr LessThan math_expr             {
                                                        $$.bval = (($1.typeId == 0) ? $1.ival :$1.fval) < (($3.typeId == 0) ? $3.ival :$3.fval);   
                                                        printf("statement < statement\n");
                                                        quad("LT", fromBoolToChar($$.bval), ($1.typeId == 0 ? fromIntToChar($1.ival) : fromFloatToChar($1.fval)), ($3.typeId == 0 ? fromIntToChar($3.ival) : fromFloatToChar($3.fval)));
                                                    }
          |math_expr NotEqual math_expr             {  
                                                        $$.bval = (($1.typeId == 0) ? $1.ival :$1.fval) != (($3.typeId == 0) ? $3.ival :$3.fval); 
                                                        printf("statement != statement\n");
                                                        quad("NE", fromBoolToChar($$.bval), ($1.typeId == 0 ? fromIntToChar($1.ival) : fromFloatToChar($1.fval)), ($3.typeId == 0 ? fromIntToChar($3.ival) : fromFloatToChar($3.fval)));
                                                    }
          |VAR IS TRUE                              {
                                                        int type,isconst;
                                                        DecAndInit($1.lexeme,scopeId,&type,&isconst);
                                                        if (type == 3 ){//type bool
                                                            //$$.bval = !GetBoolVal($1.lexeme,scopeId);
                                                            if(GetBoolVal($1.lexeme,scopeId) == 1)
                                                                $$.bval = 1;
                                                            else
                                                                $$.bval = 0;
                                                        }else   
                                                            yyerror("Type mismatch logic_expr");   
                                                    }
          |VAR IS FALSE                             {
                                                        int type,isconst;
                                                        DecAndInit($1.lexeme,scopeId,&type,&isconst);
                                                        if (type == 3 ){//type bool
                                                            $$.bval = !GetBoolVal($1.lexeme,scopeId) ? 1 : 0;
                                                        }else   
                                                            yyerror("Type mismatch logic_expr");
                                                    }
          |VAR MATCH CHAR_VALUE                     {
                                                        int type,isconst;
                                                        DecAndInit($1.lexeme,scopeId,&type,&isconst);
                                                        if (type == 2 ){//type char
                                                            if(GetCharVal($1.lexeme,scopeId) == $3) 
                                                                $$.bval = 1;
                                                            else 
                                                                $$.bval = 0;
                                                        }else   
                                                            yyerror("Type mismatch logic_expr");
                                                    }
          |TRUE                                     { 
                                                        $$.bval = 1;
                                                    }
          |FALSE                                    {   
                                                        $$.bval = 0;
                                                    }
          ;
   
 
assignment: VAR EQUAL math_expr                     {
                                                        int type, isconst, isset;
                                                        if(strcmp (GetInfo($1.lexeme,scopeId,&type,&isconst,&isset), (char*)"1") != 0)
                                                        {   printf("VAR %s :not declared scopeId:%d",$1.lexeme,scopeId);
                                                            //exit(0);
                                                        }
                                                    if ((type == 3 && $3.typeId != 3) || (type != 3 && $3.typeId == 3 ))
                                                        yyerror("ERROR: Invalid variable assignment");     
                                                    if (type != 0 && type != 1) 
                                                        yyerror("ERROR: Invalid variable assignment");   
                                                    char cval[10];
                                                    if ($3.typeId == 0)
                                                    {
                                                        sprintf(cval, "%d", $3.ival);
                                                        quad("MOV", $1.lexeme, cval, "");
                                                    }
                                                    else if ($3.typeId == 1)
                                                    {
                                                        sprintf(cval, "%d", $3.fval);
                                                        quad("MOV", $1.lexeme, cval, "");
                                                    }
                                                    else if ($3.typeId == 3)
                                                    {
                                                        sprintf(cval, "%d", $3.bval);
                                                        quad("MOV", $1.lexeme, cval, "");
                                                    }
                                                    char *res = UpdateVal(type, $1.lexeme, scopeId, cval);
                                                    if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                        }
                                                    printf("assignment: VAR = math_expr\n");
                                                    }
           | VAR EQUAL logic_expr                   {
                                                     int type, isconst, isset;
                                                    if(strcmp (GetInfo($1.lexeme,scopeId,&type,&isconst,&isset), (char*)"1") != 0)
                                                        {   printf("VAR %s :not declared scopeId:%d",$1.lexeme,scopeId);
                                                            //exit(0);
                                                        }
                                                     if (type != 3)
                                                        yyerror("ERROR: Invalid variable assignment");
                                                    char cval[10];
                                                    sprintf(cval, "%d", $3.bval);
                                                    quad("MOV", $1.lexeme, cval, "");
                                                    char *res = UpdateVal(type, $1.lexeme, scopeId, cval);
                                                    if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            //exit(0);
                                                        }  
                                                        printf("assignment: VAR = logic_expr\n");
                                                    }
           | VAR EQUAL CHAR_VALUE                   {
                                                    int type, isconst, isset;
                                                    if(strcmp (GetInfo($1.lexeme,scopeId,&type,&isconst,&isset), (char*)"1") != 0)
                                                        {   printf("VAR %s :not declared scopeId:%d",$1.lexeme,scopeId);
                                                            //exit(0);
                                                        }
                                                     if (type != 2)
                                                        yyerror("ERROR: Invalid variable assignment");
                                                    char cval[1];
                                                    cval[0] = $3;
                                                    quad("MOV", $1.lexeme, fromCharToChar($3) ,"");
                                                    char *res = UpdateVal(type, $1.lexeme, scopeId, cval);
                                                    if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            ////exit(0);
                                                        }  
                                                        printf("assignment: VAR = CHAR_VALUE\n");
                                                    }
           | VAR EQUAL FUNCTION_CALL                {   printf("assignment: VAR = Function call\n");
                                                        int type, isconst, isset;
                                                        if(strcmp (GetInfo($1.lexeme,scopeId,&type,&isconst,&isset), (char*)"1") != 0)
                                                        {   printf("VAR %s :not declared scopeId:%d",$1.lexeme,scopeId);
                                                            //exit(0);
                                                        }
                                                        else
                                                        {
                                                            char * res = GetFuncInfo($3.lexeme,scopeId,type);
                                                            if(strcmp (res, (char *)"1") != 0)
                                                            {
                                                                yyerror(res);
                                                                ////exit(0);
                                                            }
                                                        }
                                                    }
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

FUNCTION_DEFINITION: INT VAR '(' PARAMETERS ')'     {   char* res = InserNewFunction(0,$2.lexeme,scopeId);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                        }
                                                        printf("Function_declaration: INT VAR %s\n",$2.lexeme);
                                                    }
                   | FLOAT VAR '(' PARAMETERS ')'   {   char* res = InserNewFunction(1,$2.lexeme,scopeId);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                        }
                                                        printf("Function_declaration: FLOAT VAR %s\n",$2.lexeme);
                                                    }
                   | BOOL VAR '(' PARAMETERS ')'    {   char* res = InserNewFunction(3,$2.lexeme,scopeId);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                        }
                                                        printf("Function_declaration: BOOL VAR %s\n",$2.lexeme);
                                                    }
                   | CHAR VAR '(' PARAMETERS ')'    {   char* res = InserNewFunction(2,$2.lexeme,scopeId);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                        }
                                                        printf("Function_declaration: CHAR VAR %s\n",$2.lexeme);
                                                    }
                   ;

PARAMETERS: PARAMETERS COMMA INT VAR    {   char* res = InserNewArgument(0,$4.lexeme,scopeId);
                                            if(strcmp (res, (char *)"1") != 0)
                                            {
                                                yyerror(res);
                                            }
                                            printf("Argument_declaration: INT VAR %s\n",$4.lexeme);
                                        }
          | PARAMETERS COMMA FLOAT VAR  {   char* res = InserNewArgument(1,$4.lexeme,scopeId);
                                            if(strcmp (res, (char *)"1") != 0)
                                            {
                                                yyerror(res);
                                            }
                                            printf("Argument_declaration: FLOAT VAR %s\n",$4.lexeme);
                                        }
          | PARAMETERS COMMA BOOL VAR   {   char* res = InserNewArgument(3,$4.lexeme,scopeId);
                                            if(strcmp (res, (char *)"1") != 0)
                                            {
                                                yyerror(res);
                                            }
                                            printf("Argument_declaration: BOOL VAR %s\n",$4.lexeme);
                                        }
          | PARAMETERS COMMA CHAR VAR   {   char* res = InserNewArgument(2,$4.lexeme,scopeId);
                                            if(strcmp (res, (char *)"1") != 0)
                                            {
                                                yyerror(res);
                                            }
                                            printf("Argument_declaration: CHAR VAR %s\n",$4.lexeme);
                                        }
          | INT VAR                     {   char* res = InserNewArgument(0,$2.lexeme,scopeId);
                                            if(strcmp (res, (char *)"1") != 0)
                                            {
                                                yyerror(res);
                                            }
                                            printf("Argument_declaration: INT VAR %s\n",$2.lexeme);
                                        }
          | FLOAT VAR                   {   char* res = InserNewArgument(1,$2.lexeme,scopeId);
                                            if(strcmp (res, (char *)"1") != 0)
                                            {
                                                yyerror(res);
                                            }
                                            printf("Argument_declaration: FLOAT VAR %s\n",$2.lexeme);
                                        }
          | BOOL VAR                    {   char* res = InserNewArgument(3,$2.lexeme,scopeId);
                                            if(strcmp (res, (char *)"1") != 0)
                                            {
                                                yyerror(res);
                                            }
                                            printf("Argument_declaration: BOOL VAR %s\n",$2.lexeme);
                                        }
          | CHAR VAR                    {   char* res = InserNewArgument(2,$2.lexeme,scopeId);
                                            if(strcmp (res, (char *)"1") != 0)
                                            {
                                                yyerror(res);
                                            }
                                            printf("Argument_declaration: CHAR VAR %s\n",$2.lexeme);
                                        }
          ;

FUNCTION_CALL: VAR '(' CALL_PARAMETERS ')'  {   printf("function_call \n");
                                                $$.lexeme = $1.lexeme;
                                            }
             ;

CALL_PARAMETERS: CALL_PARAMETERS COMMA DATA | DATA {printf("call parameters\n");} ;

DATA : VAR              {printf("Data Var \n"); 
                        int type, isconst;
                        DecAndInit($1.lexeme, scopeId, &type, &isconst);}      
     | INT_VALUE        {printf("Data int \n");}
     | DECIMAL_VALUE    {printf("Data floa \nt");}
     | CHAR_VALUE       {printf("Data char \n");}
     | logic_expr       {printf("Data bool \n");}
     ;

RETURN_STATEMENT: RETURN VAR            {printf("return Var \n");
                                        int type, isconst;
                                        DecAndInit($2.lexeme, scopeId, &type, &isconst);} 
                | RETURN INT_VALUE      {printf("return int \n");}
                | RETURN DECIMAL_VALUE  {printf("return float \n");}
                | RETURN CHAR_VALUE     {printf("return char \n");}
                | RETURN logic_expr     {printf("return bool \n");}
                | RETURN                {printf("return \n");}
                ;

%%
void quad(char* operation, char* destination, char* source1, char* source2) {
char *filename = "quad.txt";

    // open the file for writing
    FILE *fptr = fopen(filename, "ab");
    if (fptr == NULL)
    {
        printf("Error opening the file %s", filename);
    }
    // write to the text file

    fprintf(fptr,"%s \t",operation);
    fprintf(fptr,"%s \t",source1);
    if (source2 != "")
        fprintf(fptr,"%s \t",source2);
    fprintf(fptr,"%s \t",destination);
    fprintf(fptr,"\n");
    // close the file
    fclose(fptr);
}
char* fromFloatToChar(float f)
{
    char *str = (char*)malloc(sizeof(char)*10);
    sprintf(str, "%f", f);
    return str;
}
char* fromIntToChar(int i)
{
    char *str = (char*)malloc(sizeof(char)*10);
    sprintf(str, "%d", i);
    return str;
}
char* fromBoolToChar(int b)
{
    char *str = (char*)malloc(sizeof(char)*10);
    if (b == 0)
        sprintf(str, "false");
    else
        sprintf(str, "true");
    return str;
}
char* fromCharToChar(char c)
{
    char *str = (char*)malloc(sizeof(char)*10);
    sprintf(str, "%c", c);
    return str;
}
int main (void) {
    
    NewLevel();
    FILE* ftrans = fopen("transcript.txt","w");
    FILE* fquad = fopen("quad.txt","w");
    fclose(fquad);
    fprintf(ftrans,"------------- transcript ----------\n");
    fclose(ftrans);
    yyin = fopen("testfile.txt","r+");
    if(yyin ==NULL){
        printf("File Not Found\n");
    }
    else
    {
        printf(">>>> Parsing the File <<<<\n\n"); 
        yyparse();
    }
    fclose(yyin);
    //yyparse();
    removeLevel();
    return 0;
}