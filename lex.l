%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "yacc.tab.h"
    void yyerror(char *);
%}


%%

[ \n\t\r]+                      ;/* ignore new lines and whitespaces */

"{"                             {return SCOPE_OPEN;}
"}"                             {return SCOPE_CLOSE;}


"const"                         {return CONST;}
"bool"							{return BOOL;}
"true"                          {return TRUE;}
"false"                         {return FALSE;}
"int"                           {return INT;}
"float"                         {return FLOAT;}
"char"							{return CHAR;}
"break"                         {return BREAK;}
"default"                       {return DEFAULT;}

"("								{return '(';}
")"								{return ')';}
"*"                             {return MULTIPLY;}
"/"                             {return DIVISIDE;}
"+"                             {return PLUS;}
"-"                             {return MINUS;}
"=="                            {return EqualEqual;}
"="                             {return EQUAL;}

">="                            {return GreaterThanOrEqual;}
"<="                            {return LessThanOrEqual;}
"!="                            {return NotEqual;}
"<"                             {return LessThan;}
">"                             {return GreaterThan;}
"is"                            {return IS;}
"match"                         {return MATCH;}

"||"                            {return OR;}
"&&"                            {return AND;}
"!"                             {return NOT;}

"if"                            {return IF_STATMENT;}
"then"                          {return THEN;}
"else"                          {return ELSE;}
"elif"                          {return ELSE_IF;}
"while"                         {return WHILE;}
"for"                           {return FOR;}
"switch"                        {return SWITCH_STATEMENT;}
"case"                          {return CASE;}
"repeat"                        {return REPEAT_STATEMENT;}
"untill"                        {return UNTILL;}
"return"                        {return RETURN;}
","                             {return COMMA;}

[a-zA-Z_][a-zA-Z_0-9]*          {return VAR;}
0|[-]?[1-9][0-9]*               {yylval.intVal = atoi(yytext);  return INT_VALUE;}
[-]?[0-9]+['.'][0-9]*           {yylval.floatVal = atof(yytext); return DECIMAL_VALUE;}
\'.?\'                          {yylval.charVal = yytext[1]; return CHAR_VALUE;}

";"                             {return END_EXPR;}
":"                             {return COLON;}

.                               yyerror("Unknown Token");
%%

void yyerror(char *s) { 
    printf("%s\n", s); 
}

int yywrap(void){
    return 1;
}