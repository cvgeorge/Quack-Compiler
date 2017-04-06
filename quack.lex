/* 
 This is the quack language lexical definition file for flex.

*/

%{
#include "quack.tab.hpp"
#include <string>
#include <iostream>
#include "ProgramNode.hpp"
#include "CompilerDB.hpp"
#include "QuackExpressions.hpp"
#include "QuackStatements.hpp"
#include "QuackDefines.hpp"

#define MAKE_RETURN(x) yylval.syntax = GetDB()->AddName(#x,x, new SyntaxNode(yytext,x,yylineno));return x
/*
extern "C" {

	ProgramNode *currentNode;
}
*/

/*
start_sequence (exception cases | normal case) end_sequence
start_sequence generalized -> yyerror (non-quoted)
start_sequence 
*/
%}



alpha		[A-Za-z]
digit		[0-9]
underscore 	[_]
ws		[ \t]

nottqts		([^"]|\"([^"]|\"[^"]))
quotes  	\"\"\"

ml_start 	\/\*
nml_char  	([^\*]|\*[^\/])
ml_end   	\*\/

slq_begin	\"
slq_char	(\\(0|b|t|n|r|f|\"|\\)|[^\\"\r\n])
slq_char_bad	(\\.|[^\\"\r\n])
slq_end		\"


%option yylineno noyywrap
%%
"class"		{ 	MAKE_RETURN(CLASS); }
"def"		{	MAKE_RETURN(DEFINE); }
"extends"	{	MAKE_RETURN(EXTENDS); }
"if"		{	MAKE_RETURN(IF); }
"elif"		{	MAKE_RETURN(ELSEIF); }
"else"		{	MAKE_RETURN(ELSE); }
"while"		{	MAKE_RETURN(WHILE); }
"return"	{	MAKE_RETURN(RETURN); }
":"		{	MAKE_RETURN(COLON); }
"="		{	MAKE_RETURN(ASSIGNMENT); }
";"		{	MAKE_RETURN(SEMICOLON); }
"."		{	MAKE_RETURN(DOT); }
","		{	MAKE_RETURN(COMMA); }
"+"		{	MAKE_RETURN(PLUS); }
"-"		{	MAKE_RETURN(MINUS); }
"*"		{	MAKE_RETURN(MULTIPLY); }
"/"		{	MAKE_RETURN(DIVIDE); }
"("		{	MAKE_RETURN(LPAREN); }
")"		{	MAKE_RETURN(RPAREN); }
"{"		{	MAKE_RETURN(LBRACE); }
"}"		{	MAKE_RETURN(RBRACE); }
"and"		{	MAKE_RETURN(OPERATOR_AND); }
"or"		{	MAKE_RETURN(OPERATOR_OR); }
"not"		{	MAKE_RETURN(OPERATOR_NOT); }
"=="		{	MAKE_RETURN(OPERATOR_EQUAL); }
"<="		{	MAKE_RETURN(OPERATOR_LESS_EQUAL); }
"<"		{	MAKE_RETURN(OPERATOR_LESS); }
">="		{	MAKE_RETURN(OPERATOR_GREATER_EQUAL); }
">"		{	MAKE_RETURN(OPERATOR_GREATER); }
"true"		{	MAKE_RETURN(TRUE_VALUE); }
"false"		{	MAKE_RETURN(FALSE_VALUE); }
"nothing"	{	MAKE_RETURN(NOTHING_VALUE);}


[A-Za-z_][A-Za-z0-9_]*		{	MAKE_RETURN(IDENTIFIER); }
[0-9]+				{	MAKE_RETURN(DIGIT_VALUE); }


{quotes}{nottqts}*{quotes}	{ 	MAKE_RETURN(STRING_LITERAL);/* https://stackoverflow.com/questions/25960801/f-lex-how-do-i-match-negation/25964178#25964178 */}


{slq_begin}{slq_char}*{slq_end}	{	MAKE_RETURN(STRING_LITERAL); }
{slq_begin}{slq_char_bad}*({slq_end}|(\r|\n|\\)+)	{	MAKE_RETURN(BAD_STRING_LITERAL); /*ERROR("BAD_STRING_LITERAL");*/}


{ml_start}{nml_char}*{ml_end}	{	/*MAKE_RETURN(LINE_COMMENT);*/ /*https://stackoverflow.com/questions/25960801/f-lex-how-do-i-match-negation/25964178#25964178 */ }

\/\/[^\n]*			{	/*MAKE_RETURN(LINE_COMMENT);*/}
{ws}+				{	}
\n				{	}
<<EOF>>				{yyterminate();}

%%

