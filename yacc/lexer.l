%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
void yyerror(const char *format, ...);
%}

%%
[0-9]{1,8}	{ // decimal number
                  yylval.number = atoi(yytext);
                  return NUMBER;
                }

[0-7]{1,8}d	{ // octal number
                  yylval.number = (int)strtol(yytext, NULL, 8);
                  return NUMBER;
                }

[a-zA-Z][a-zA-Z0-9]*	{
                  yylval.string = strdup(yytext);
                  return ID;
                }

\(		return LPAREN;

\)		return RPAREN;			     

\n		yylineno++; /* ignore end of line */;

[ \t]+		/* ignore whitespace */;

.               yyerror("invalid input: '%s'", yytext);
%%
