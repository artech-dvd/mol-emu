%{
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

extern int yylineno; // Line number, provided by Lex
extern char *yytext; // The current token, provided by Lex

void yyerror(const char *format, ...) {
    va_list args;
    va_start(args, format); 

    fprintf(stderr, "line %d, near '%s': ", yylineno, yytext);
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    
    va_end(args); 
}
 
int yywrap() {
        return 1;
} 

int yylex();
int yyparse(); 

int main() {
    yyparse();
} 

%}
			
%token LPAREN RPAREN

%union 
{
        int number;
        char *string;
}

%token <number> NUMBER
%token <string> ID

%%

/* start of temporary scaffolding */
commands: /* empty */
        | commands command
        ;

command:
        num
        |
        parid
        ;
/* end of temporary scaffolding */

num:			
	NUMBER	
	{
	    printf("\tnumber: %d\n", $1);
	}		
	;
parid:
	LPAREN ID RPAREN
        {
	    printf("\tparid: %s\n", $2);
        }
        ;
