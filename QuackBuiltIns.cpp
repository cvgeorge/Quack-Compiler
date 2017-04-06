#include "QuackBuiltIns.hpp"


ReturnStatement *GenReturnThis()
{
	SyntaxNode *node = new SyntaxNode("this",IDENTIFIER,-999);
	VariableIdentifier *ptr = new VariableIdentifier(node,"this",BOTTOM_STRING);

	return new ReturnStatement(node,ptr);
}

ReturnStatement *GenEmptyStringReturn()
{
	SyntaxNode *node = new SyntaxNode("",STRING_LITERAL,-999);
	TypedValue *ptr = new TypedValue(node,STRING_STRING,"");

	return new ReturnStatement(node,ptr);
}

ReturnStatement *GenFalseValueReturn()
{
	SyntaxNode *node = new SyntaxNode("false",FALSE_VALUE,-999);
	TypedValue *ptr = new TypedValue(node,BOOL_STRING,"false");
	return new ReturnStatement(node,ptr);
}

ReturnStatement *GenNothingValueReturn()
{
	SyntaxNode *node = new SyntaxNode("none",NOTHING_VALUE,-999);
	TypedValue *ptr = new TypedValue(node,NOTHING_STRING,"none");
	return new ReturnStatement(node,ptr);
}

ReturnStatement *GenZeroValueReturn()
{
	SyntaxNode *node = new SyntaxNode("0",DIGIT_VALUE,-999);
	TypedValue *ptr = new TypedValue(node,INT_STRING,"0");
	return new ReturnStatement(node,ptr);
}

MethodClass* GenerateConstructor(std::string class_name)
{
	SyntaxNode *node = new SyntaxNode(class_name,CLASS,-999 );
	MethodClass *constructor = new MethodClass(node);
	constructor->NameReturn = new NamedType(node,class_name,class_name);
	constructor->Statements = GenReturnThis();
	return constructor;
}

MethodClass* GenerateDefaultMethod(std::string method_name, std::string parameter_type, std::string return_type, ReturnStatement *return_stmt)
{
	SyntaxNode *node = new SyntaxNode(method_name,IDENTIFIER,-999 );
	MethodClass *default_method = new MethodClass(node);
	default_method->NameReturn = new NamedType(node,method_name,return_type);

	SyntaxNode *arg = new SyntaxNode("other",IDENTIFIER,-999);
	NamedType *argument = new NamedType(arg,"other",parameter_type);
	default_method->Arguments.push_back(argument);
	default_method->Statements = return_stmt;
	return default_method;
}


