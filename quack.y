%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "quack.tab.hpp"
#include "CompilerDB.hpp"

extern int yylex();
extern int yyparse();
extern int yylineno;
void yyerror(const char *s) { std::cout << "Error on line: " << yylineno << std::endl << s << std::endl; }

int context_count = 0;
int yylex(void);
%}

%union {
	class ProgramNode *node;
	class SemanticNode *semantic;
	class SyntaxNode *syntax;
}

%token CLASS DEFINE EXTENDS 
%token IF ELSEIF ELSE WHILE RETURN COLON ASSIGNMENT SEMICOLON DOT COMMA PLUS MINUS MULTIPLY DIVIDE LPAREN RPAREN LBRACE RBRACE 
%token OPERATOR_AND OPERATOR_OR OPERATOR_NOT OPERATOR_EQUAL OPERATOR_LESS_EQUAL OPERATOR_LESS OPERATOR_GREATER_EQUAL OPERATOR_GREATER 

%token IDENTIFIER FALSE_VALUE TRUE_VALUE NOTHING_VALUE
%token DIGIT_VALUE STRING_LITERAL BAD_STRING_LITERAL 

%type<syntax> CLASS DEFINE EXTENDS FALSE_VALUE TRUE_VALUE NOTHING_VALUE
%type<syntax> IF ELSEIF ELSE WHILE RETURN COLON ASSIGNMENT SEMICOLON DOT COMMA PLUS MINUS MULTIPLY DIVIDE LPAREN RPAREN LBRACE RBRACE 
%type<syntax> OPERATOR_AND OPERATOR_OR OPERATOR_NOT OPERATOR_EQUAL OPERATOR_LESS_EQUAL OPERATOR_LESS OPERATOR_GREATER_EQUAL OPERATOR_GREATER 
%type<syntax> IDENTIFIER 
%type<syntax> DIGIT_VALUE STRING_LITERAL BAD_STRING_LITERAL 


%left OPERATOR_NOT OPERATOR_AND OPERATOR_OR
%left OPERATOR_LESS OPERATOR_GREATER OPERATOR_EQUAL OPERATOR_LESS_EQUAL OPERATOR_GREATER_EQUAL
%left PLUS MINUS 
%left MULTIPLY DIVIDE
%left DOT


%type<semantic> str_lit int_lit literal actual_arg_list actual_args r_exp l_exp elseiflist else_list index_id return_stmt
%type<semantic> statement statement_block method method_list class_body formal_arg formal_arg_list formal_args
%type<semantic> extends class_signature class_declaration statement_list class_declarations returntype
%type<semantic> start bool_lit nothing_lit

%%

start: class_declarations 						{
													FUNC_LOG("Class Declarations Done.");
													GetDB()->FinalProgram = ClassRSM()-> FinalizeStack();
													StmtRSM()->SetReg(new SequentialStatement(LastSyntax()));
												}
				statement_list 
												{
													FUNC_LOG("Main Program Statements Done.");
													GetDB()->Root =MakeSemanticNode("start",$1,$3);
													GetDB()->ProgramStatements = StmtRSM()->FinalizeRegister();
												}	
	;

class_declarations:								{	$$ = MakeSemanticNode("class_declarations");}
	|	class_declaration						{	
													FUNC_LOG("Class Declaration."); 
													ClassRSM()->PushReg(); 
												}
				 class_declarations			
												{
													$$ = MakeSemanticNode("class_declarations",$1,$3);  
												}
	;

class_declaration: class_signature class_body
												{	$$ = MakeSemanticNode("class_declaration",$1,$2);}
	;

class_signature:	CLASS IDENTIFIER			{	ClassRSM()->SetReg(new ClassClass($2));} 
						formal_args				
												{
													FUNC_LOG("Constructor Args." + $2->TextMatch);
													//ClassRSM()->Top()->Arguments = ArgsRSM()->FinalizeStack();
													ClassRSM()->Top()->MethodConstructor = new MethodClass($2);
													ClassRSM()->Top()->MethodConstructor->NameReturn = new NamedType($2,$2->TextMatch,$2->TextMatch);
													ClassRSM()->Top()->MethodConstructor->Arguments =ArgsRSM()->FinalizeStack(); 
												}
							 extends		
												{
													FUNC_LOG("Class Signature Done.");	
													$$ = MakeSemanticNode("class_signature",$1,$2,$4,$6);
												}
	;

extends:										{	$$ = MakeSemanticNode("extends");		}
	|	EXTENDS IDENTIFIER						{	$$ = MakeSemanticNode("extends",$1,$2);	
													/* Set Class Inheritance here. */
													ClassRSM()->Top()->ParentName = $2->TextMatch;
												}
	;

formal_args: 	LPAREN RPAREN					{	$$ = MakeSemanticNode("formal_args",$1,$2);	/* Set the current formal_args value to new */ }
	|	LPAREN formal_arg_list RPAREN	
												{	$$ = MakeSemanticNode("formal_args",$1,$2,$3);	}
	;

formal_arg_list:	formal_arg					{	$$ = MakeSemanticNode("formal_arg_list",$1); /* Get the current arg_list and add named type to it*/ }
	|		formal_arg_list COMMA formal_arg
												{	$$ = MakeSemanticNode("formal_arg_list",$1,$2,$3);	/* Get the current arg_list and add named type to it*/}
	;

formal_arg:	IDENTIFIER COLON IDENTIFIER	
												{
													$$ = MakeSemanticNode("formal_arg",$1,$2,$3); 
													ArgsRSM()->Push(new NamedType($1, $1->TextMatch, $3->TextMatch));
												}
	;

class_body:	LBRACE								{
													FUNC_LOG("Start Class Constructor.");
													StmtRSM()->SetReg(new SequentialStatement($1));
												} 
				statement_list					{
													FUNC_LOG("Finished Constructor, start methods.");
													ClassRSM()->Top()->MethodConstructor->Statements = StmtRSM()->FinalizeRegister();
													VAR_LOG("Class Constructor Statements Ptr: " + HEX_STR(ClassRSM()->Top()->MethodConstructor->Statements)); 
												} 
					method_list RBRACE		
												{
													FUNC_LOG("Finished Methods.");
													$$ = MakeSemanticNode("class_body",$1,$3,$5, $6);	
													ClassRSM()->Top()->Methods = MethRSM()->FinalizeStack();
													/*set class stm_list and mtd_list */
												}
	;

method_list:									{	$$ = MakeSemanticNode("method_list"); /*no action needed here, current list has mthods.*/}
	|	method_list 							{
													MethRSM()->SetReg(new MethodClass(LastSyntax())); 
												}
					method					
												{
													FUNC_LOG("Create Method");
													$$ = MakeSemanticNode("method_list",$1,$3); /* add current method to current method list*/ 
													MethRSM()->PushReg();									
												}
	;

method:		DEFINE IDENTIFIER formal_args 
												{	
													FUNC_LOG("Method Constructor." + $2->TextMatch);
													MethRSM()->Top()->Arguments = ArgsRSM()->FinalizeStack();
												}
							returntype 
												{ 	StmtRSM()->SetReg(new SequentialStatement($1));} 
							statement_block
												{
													FUNC_LOG("Method Statements Complete.");
													$$ = MakeSemanticNode("method",$1,$2,$3,$5,$7);
														
													MethRSM()->Top()->Statements = StmtRSM()->FinalizeRegister();
													std::string default_return = NOTHING_STRING;
			
													if($5->Children.size() == 2)
													{
														default_return = ((SyntaxNode*)($5->Children[1]))->TextMatch;
													}
													MethRSM()->Top()->NameReturn = new NamedType($2,$2->TextMatch,default_return);
												}
	;

returntype:										{	$$ = MakeSemanticNode("returntype"); /*set current named type to Obj, may not need to be done.*/ }
	|	COLON IDENTIFIER						{	$$ = MakeSemanticNode("returntype",$1,$2); /* set current named type to Identifier*/ }
	;

statement_block:	LBRACE 						{ 
													StmtRSM()->PushReg(); 
													StmtRSM()->SetReg(new SequentialStatement($1));
												} 
				statement_list RBRACE
												{
													FUNC_LOG("statement_block");
													$$ = MakeSemanticNode("statement_block",$1,$3,$4);
													SequentialStatement *ss = StmtRSM()->GetReg(); 
													StmtRSM()->PopReg();
													StmtRSM()->Top()->Sequence.push_back(ss);
												}
	;

statement_list:									{	$$ = MakeSemanticNode("statement_list");}
	|	statement_list statement				{	$$ = MakeSemanticNode("statement_list",$1,$2);}
	;

statement:	IF r_exp 							{ 
													FUNC_LOG("If condition");
													ExpRSM()->PushReg();
													StmtRSM()->PushReg(); 
													StmtRSM()->SetReg(new SequentialStatement($1));
												} 	
			statement_block 		
												{
													FUNC_LOG("if statements");
													SequentialStatement *ss = StmtRSM()->GetReg();
													StmtRSM()->PopReg();
													ExpRSM()->PopReg();
													RExpression *rexp = (RExpression*) ExpRSM()->GetReg();
													IfElseListStatement *ptr = new IfElseListStatement($1);
													ptr ->Add(rexp,ss);
													StmtRSM()->Top()->Sequence.push_back(ptr);
			  									} 
					else_list	
												{	
													$$ = MakeSemanticNode("statement",$1,$2,$4,$6);
												}
	|	WHILE r_exp 							{
													FUNC_LOG("While condition"); 
													ExpRSM()->PushReg(); 
													StmtRSM()->PushReg(); 
													StmtRSM()->SetReg(new SequentialStatement($1));  
												}
				 statement_block	
												{
													FUNC_LOG("While statements");
													$$ = MakeSemanticNode("statement",$1,$2,$4);
													ExpRSM()->PopReg();
													RExpression *rexp = (RExpression *)ExpRSM()->GetReg();
													SequentialStatement *ss = StmtRSM()->GetReg();
													StmtRSM()->PopReg();
													StmtRSM()->Top()->Sequence.push_back(new WhileStatement($1,rexp,ss));
												}

	|	RETURN return_stmt SEMICOLON
												{
													FUNC_LOG("Return Statement");
													$$ = MakeSemanticNode("statement",$1,$2,$3);
													RExpression *ptr = NULL; 
													if($2->Children.size()==1)
													{
														ptr = (RExpression*)ExpRSM()->GetReg();
													}
													else
													{
														ptr = new TypedValue($3,NOTHING_STRING,"none");
													}
													StmtRSM()->Top()->Sequence.push_back(new ReturnStatement($1,ptr));
												}

	|	l_exp index_id			 				{	
													FUNC_LOG("Assignment Variable");
													ExpRSM()->PushReg();
												} 
				ASSIGNMENT r_exp SEMICOLON		
												{
													FUNC_LOG("Assignment Statement");
													$$ = MakeSemanticNode("statement",$1,$2,$4,$5,$6);
													RExpression *rexp = dynamic_cast<RExpression *>(ExpRSM()->GetReg());
													ExpRSM()->PopReg();
													LExpression *lexp = dynamic_cast<LExpression *>(ExpRSM()->GetReg());
													StmtRSM()->Top()->Sequence.push_back(new AssignmentStatement($4,lexp,rexp));
												}

	|	r_exp SEMICOLON 			
												{
													FUNC_LOG("Single Statement");
													$$ = MakeSemanticNode("statement",$1,$2);
													StmtRSM()->Top()->Sequence.push_back(new SingleStatement($2,(RExpression*)ExpRSM()->FinalizeRegister()));
												}
	;

return_stmt:		 							{
													$$ = MakeSemanticNode("return_stmt"); 
												}
	|	r_exp									{	$$ = MakeSemanticNode("return_stmt",$1);}
	;

index_id:										{	$$ = MakeSemanticNode("index_id");}
	|	COLON IDENTIFIER						{	$$ = MakeSemanticNode("index_id",$1,$2);}
	;

else_list:										{	$$ = MakeSemanticNode("else_list");}
	|	elseiflist ELSE 						
												{
													FUNC_LOG("terminal else case.");
													StmtRSM()->PushReg(); StmtRSM()->SetReg(new SequentialStatement($2)); 
												} 
				statement_block 
												{
													FUNC_LOG("else statements.");
													$$ = MakeSemanticNode("else_list",$1,$2,$4);
													SequentialStatement *ss = StmtRSM()->GetReg();
													StmtRSM()->PopReg();
													IfElseListStatement* exp = (IfElseListStatement*)(StmtRSM()->Top()->Sequence.back());
													exp->Add(NULL,ss);
												}
	;

elseiflist:										{	$$ = MakeSemanticNode("elseiflist");}
	|	ELSEIF r_exp 							{ 
													FUNC_LOG("elif condition.");
													ExpRSM()->PushReg(); 
													StmtRSM()->PushReg();
													StmtRSM()->SetReg(new SequentialStatement($1));
												} 
				statement_block 
												{
													FUNC_LOG("elif statements.");
													SequentialStatement *ss = StmtRSM()->GetReg();
													StmtRSM()->PopReg();
													ExpRSM()->PopReg();
													RExpression *rexp = (RExpression*) ExpRSM()->GetReg();
													IfElseListStatement* exp = (IfElseListStatement*)(StmtRSM()->Top()->Sequence.back());
													exp->Add(rexp,ss);
												}
				 elseiflist						{	$$ = MakeSemanticNode("elseiflist",$1,$2,$4,$6); }
	;

l_exp:	r_exp DOT IDENTIFIER					{	
													FUNC_LOG("Lookup Exp.");
													$$ = MakeSemanticNode("l_exp",$1,$2,$3);
													
													Expression *lookup = ExpRSM()->GetReg();
													Expression * id = new VariableIdentifier($3,$3->TextMatch,BOTTOM_STRING);
													VariableLookup *vl = new VariableLookup($2,lookup,id);
													ExpRSM()->SetReg(vl);
													
												}
	|	IDENTIFIER								{
													FUNC_LOG("Variable Exp");
													$$ = MakeSemanticNode("l_exp",$1); 
													ExpRSM()->SetReg(new VariableIdentifier($1,$1->TextMatch,BOTTOM_STRING));
												}
	;

r_exp:		literal								{	FUNC_LOG("Literal Exp"); $$ = MakeSemanticNode("r_exp: literal",$1); /* */ }
	|	l_exp actual_args						{	
													FUNC_LOG("Func Call args.");
													
													$$ = MakeSemanticNode("r_exp: function call",$1,$2);
													
													RegisterStack<Expression> *stack = ExpContextRSM()->GetReg();
													ExpContextRSM()->PopReg();
													
													Expression *lexp = ExpRSM()->GetReg();
													
													std::vector<Expression *> args = stack->FinalizeStack();
													delete stack;
													
													FunctionCall *ptr = new FunctionCall(LastSyntax(),lexp,args);
													ExpRSM()->SetReg(ptr);
												}
	|	r_exp PLUS			 					{	FUNC_LOG("Math +"); ExpRSM()->PushReg();}
			   r_exp	
												{
													$$ = MakeSemanticNode("r_exp: plus",$1,$2,$4); 
													Expression* right_side = ExpRSM()->GetReg();
													ExpRSM()->PopReg();
													Expression* left_side = ExpRSM()->GetReg();
													ExpRSM()->SetReg(new MathExpression($2,left_side,"PLUS",right_side));
												}
	|	r_exp MINUS				 				{	FUNC_LOG("Math -"); ExpRSM()->PushReg();} 
			   r_exp			
						   						{				
													$$ = MakeSemanticNode("r_exp: minus",$1,$2,$4); 
													Expression* right_side = ExpRSM()->GetReg();
													ExpRSM()->PopReg();
													Expression* left_side = ExpRSM()->GetReg();
													ExpRSM()->SetReg(new MathExpression($2,left_side,"MINUS",right_side));
												}
	|	r_exp MULTIPLY			 				{	FUNC_LOG("Math *"); ExpRSM()->PushReg();} 
			   r_exp			
						   						{				
													$$ = MakeSemanticNode("r_exp: multiply",$1,$2,$4); 
													Expression* right_side = ExpRSM()->GetReg();
													ExpRSM()->PopReg();
													Expression* left_side = ExpRSM()->GetReg();
													ExpRSM()->SetReg(new MathExpression($2,left_side,"TIMES",right_side));
												}
	|	r_exp DIVIDE 							{	FUNC_LOG("Math /"); ExpRSM()->PushReg();} 
			   r_exp							{				
													$$ = MakeSemanticNode("r_exp: divide",$1,$2,$4); 
													Expression* right_side = ExpRSM()->GetReg();
													ExpRSM()->PopReg();
													Expression* left_side = ExpRSM()->GetReg();
													ExpRSM()->SetReg(new MathExpression($2,left_side,"DIVIDE",right_side));
												}
	|	LPAREN r_exp RPAREN						{	FUNC_LOG("Sub Nested Exp"); $$ = MakeSemanticNode("r_exp: Precidence",$1,$2,$3); }
	|	r_exp OPERATOR_EQUAL 					{	FUNC_LOG("Boolean =="); ExpRSM()->PushReg();} 
			   		r_exp						{				
													$$ = MakeSemanticNode("r_exp : EQUAL",$1,$2,$4); 
													Expression* right_side = ExpRSM()->GetReg();
													ExpRSM()->PopReg();
													Expression* left_side = ExpRSM()->GetReg();
													ExpRSM()->SetReg(new MathExpression($2,left_side,"EQUALS",right_side));
												}
												
	|	r_exp OPERATOR_LESS_EQUAL 				{	FUNC_LOG("Boolean <=");ExpRSM()->PushReg();} 
			   		r_exp						{				
													$$ = MakeSemanticNode("r_exp: LE",$1,$2,$4); 
													Expression* right_side = ExpRSM()->GetReg();
													ExpRSM()->PopReg();
													Expression* left_side = ExpRSM()->GetReg();
													ExpRSM()->SetReg(new MathExpression($2,left_side,"ATMOST",right_side));
												}
	|	r_exp OPERATOR_LESS 					{	FUNC_LOG("Boolean <");ExpRSM()->PushReg();} 
			   		r_exp						{				
													$$ = MakeSemanticNode("r_exp: Less",$1,$2,$4); 
													Expression* right_side = ExpRSM()->GetReg();
													ExpRSM()->PopReg();
													Expression* left_side = ExpRSM()->GetReg();
													ExpRSM()->SetReg(new MathExpression($2,left_side,"LESS",right_side));
												}
	|	r_exp OPERATOR_GREATER_EQUAL 			{	FUNC_LOG("Boolean >=");ExpRSM()->PushReg();} 
			   		r_exp						{				
													$$ = MakeSemanticNode("r_exp: GE",$1,$2,$4); 
													Expression* right_side = ExpRSM()->GetReg();
													ExpRSM()->PopReg();
													Expression* left_side = ExpRSM()->GetReg();
													ExpRSM()->SetReg(new MathExpression($2,left_side,"ATLEAST",right_side));
												}
	|	r_exp OPERATOR_GREATER		 			{	FUNC_LOG("Boolean >");ExpRSM()->PushReg();} 
			   		r_exp						{				
													$$ = MakeSemanticNode("r_exp: Greater",$1,$2,$4); 
													Expression* right_side = ExpRSM()->GetReg();
													ExpRSM()->PopReg();
													Expression* left_side = ExpRSM()->GetReg();
													ExpRSM()->SetReg(new MathExpression($2,left_side,"MORE",right_side));
												}
	|	r_exp OPERATOR_AND		 				{	FUNC_LOG("Boolean &&");ExpRSM()->PushReg();} 
			   		r_exp						{				
													$$ = MakeSemanticNode("r_exp: AND",$1,$2,$4); 
													Expression* right_side = ExpRSM()->GetReg();
													ExpRSM()->PopReg();
													Expression* left_side = ExpRSM()->GetReg();
													ExpRSM()->SetReg(new BoolExpression($2,left_side,"AND",right_side));
												}
	|	r_exp OPERATOR_OR 						{	FUNC_LOG("Boolean ||");ExpRSM()->PushReg();} 
			   		r_exp						{				
													$$ = MakeSemanticNode("r_exp: OR",$1,$2,$4); 
													Expression* right_side = ExpRSM()->GetReg();
													ExpRSM()->PopReg();
													Expression* left_side = ExpRSM()->GetReg();
													ExpRSM()->SetReg(new BoolExpression($2,left_side,"OR",right_side));
												}
	|	OPERATOR_NOT		 				     
			   		r_exp						{	FUNC_LOG("Boolean !!");			
													$$ = MakeSemanticNode("r_exp: NOT",$1,$2); 
													Expression* right_side = ExpRSM()->GetReg();
													ExpRSM()->SetReg(new BoolExpression($1,NULL,"NOT",right_side));
												}
	|	l_exp 									{	FUNC_LOG("Lexp"); $$ = MakeSemanticNode("r_exp: l_exp",$1); /* */}
	
	;

actual_args:	LPAREN	RPAREN					{	$$ = MakeSemanticNode("actual_args",$1,$2);
													ExpContextRSM()->PushReg();
													ExpContextRSM()->SetReg(new RegisterStack<Expression>(" "));
												}
	|	LPAREN 									{
													ExpContextRSM()->PushReg();
													ExpContextRSM()->SetReg(new RegisterStack<Expression>(" "));
												}
				actual_arg_list RPAREN			{	$$ = MakeSemanticNode("actual_args",$1,$3,$4);}
	;

actual_arg_list:r_exp							{
													FUNC_LOG("Func Call Arg.");
													$$ = MakeSemanticNode("actual_arg_list",$1);
													ExpRSM()->PushReg();
												}
	|	actual_arg_list COMMA r_exp				
												{
													FUNC_LOG("Func Call, Last Arg.");
													$$ = MakeSemanticNode("actual_arg_list",$1,$2,$3);
													ExpRSM()->PushReg();
													/*
														Last context.
													*/
												}
	;


literal:	int_lit								{	$$ = MakeSemanticNode("literal",$1);}
	|	str_lit									{	$$ = MakeSemanticNode("literal",$1);}
	|	bool_lit								{	$$ = MakeSemanticNode("literal",$1);}
	|	nothing_lit								{	$$ = MakeSemanticNode("literal",$1);}
	;

int_lit:	DIGIT_VALUE							{	
													FUNC_LOG("DIGIT_VALUE");
													$$ = MakeSemanticNode("int_lit",$1);
													ExpRSM()->SetReg(new TypedValue($1,INT_STRING,$1->TextMatch));
												}
	|	MINUS DIGIT_VALUE						{	
													FUNC_LOG("DIGIT_VALUE");
													$$ = MakeSemanticNode("int_lit",$1,$2);
													ExpRSM()->SetReg(new TypedValue($2,INT_STRING,$1->TextMatch + $2->TextMatch));
												}
		;


str_lit:	STRING_LITERAL						{
													FUNC_LOG("STRING_LITERAL");
													$$ = MakeSemanticNode("str_lit",$1);
													ExpRSM()->SetReg(new TypedValue($1,STRING_STRING,$1->TextMatch));
												}
	|	BAD_STRING_LITERAL 						{
													FUNC_LOG("BAD_STRING_LITERAL");
													$$ = MakeSemanticNode("str_lit",$1);
													ExpRSM()->SetReg(new TypedValue($1,STRING_STRING,$1->TextMatch));
												}
	;



bool_lit:	FALSE_VALUE							{
													FUNC_LOG("FALSE Value.");
													$$ = MakeSemanticNode("bool_false_lit",$1);  
													ExpRSM()->SetReg(new TypedValue($1,BOOL_STRING,$1->TextMatch));
												}
	|	TRUE_VALUE								{
													FUNC_LOG("TRUE Value.");
													$$ = MakeSemanticNode("bool_true_lit",$1);
													ExpRSM()->SetReg(new TypedValue($1,BOOL_STRING,$1->TextMatch));
												}
	;

nothing_lit:	NOTHING_VALUE					{	
													FUNC_LOG("Nothing Value.");
													$$ = MakeSemanticNode("nothing_lit",$1);
													ExpRSM()->SetReg(new TypedValue($1,NOTHING_STRING,$1->TextMatch));
												}
	;
%%




