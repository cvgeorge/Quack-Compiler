#ifndef QUACK_EXPRESSIONS_HPP
#define QUACK_EXPRESSIONS_HPP

#include "master_include.hpp"
#include "ProgramNode.hpp"

class ClassClass;
class MethodClass;

/*
 *

*/
class Expression: public GraphVizNodeDecorator
{
public:
	Expression(SyntaxNode* ptr);
	~Expression() {}
	virtual std::string Print() =0;
	virtual	std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren()=0;
	virtual std::string ExtractType(SymbolTable *SymTab)=0;
	virtual std::string GenCode(std::stringstream &ss, MethodClass* cur_method)=0;
public:
	//const std::string TypeValue;
	SyntaxNode *NearestSyntax;
	//ProgramNode *NearestNode;
	std::string ExpressionType;
protected:

};

/*

*/
class RExpression:public Expression
{
public:
	RExpression(SyntaxNode* ptr);
	~RExpression() {}
	virtual std::string Print() =0;
	virtual	std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren()=0;
	virtual std::string ExtractType(SymbolTable *SymTab)=0;
	virtual std::string GenCode(std::stringstream &ss, MethodClass* cur_method)=0;
};


/*

*/
class LExpression:public RExpression
{
public:
	LExpression(SyntaxNode* ptr);
	~LExpression() {}
	virtual std::string Print() = 0;
	virtual	std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren()=0;
	virtual std::string ExtractType(SymbolTable *SymTab)=0;
	virtual std::string GenCode(std::stringstream &ss, MethodClass* cur_method)=0;
};

/*

*/
class VariableIdentifier:public LExpression
{
public:
	VariableIdentifier(SyntaxNode* ptr, std::string name,std::string type);
	~VariableIdentifier();
	virtual std::string Print();
	virtual std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren();
	virtual std::string ExtractType(SymbolTable *SymTab);
	virtual std::string GenCode(std::stringstream &ss, MethodClass* cur_method);
public:
	const std::string	Name;
	const std::string	Type;
};

/*

*/
class VariableLookup:public LExpression
{
public:
	VariableLookup(SyntaxNode* ptr, Expression *lookup, Expression *variable);
	~VariableLookup();
	virtual std::string Print();
	virtual std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren();
	virtual std::string ExtractType(SymbolTable *SymTab);
	virtual std::string GenCode(std::stringstream &ss, MethodClass* cur_method);
public:
	RExpression		*Lookup;
	VariableIdentifier	*Variable;
};

/*

*/
class TypedValue: public RExpression
{
public:
	TypedValue(SyntaxNode* ptr, std::string type, std::string value);
	~TypedValue();

	virtual std::string Print();
	virtual	std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren();
	virtual std::string ExtractType(SymbolTable *SymTab);
	virtual std::string GenCode(std::stringstream &ss, MethodClass* cur_method);
public:
	const std::string Type;
	const std::string Value;
};

/*

*/
class MethodClass;

class FunctionCall: public RExpression
{
public:
	FunctionCall(SyntaxNode* ptr, Expression *call, std::vector<Expression*> args);
	~FunctionCall();
	virtual std::string Print();
	virtual std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren();
	virtual std::string ExtractType(SymbolTable *SymTab);
	virtual std::string GenCode(std::stringstream &ss, MethodClass* cur_method);
public:
	LExpression			*Call;
	std::vector<Expression *>	Arguments;
	MethodClass			*MethodCall;

	bool constructor_call;
};

/*

*/
class MathExpression: public RExpression
{
public:
	MathExpression(SyntaxNode* ptr, Expression *left, std::string operation,Expression *right);
	~MathExpression();
	virtual std::string Print();
	virtual std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren();
	virtual std::string ExtractType(SymbolTable *SymTab);
	virtual std::string GenCode(std::stringstream &ss, MethodClass* cur_method);
public:
	Expression			*LeftSide;
	const std::string			Operation;
	Expression			*RightSide;
};

/*

*/
class BoolExpression: public RExpression
{
public:
	BoolExpression(SyntaxNode* ptr, Expression *left, std::string operation,Expression *right);
	~BoolExpression() {}
	virtual std::string Print();
	virtual std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren();
	virtual std::string ExtractType(SymbolTable *SymTab);
	virtual std::string GenCode(std::stringstream &ss, MethodClass* cur_method);
public:
	Expression			*LeftSide;
	const std::string			Operator;
	Expression			*RightSide;

};


#endif
