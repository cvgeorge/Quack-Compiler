
#ifndef QUACK_STATEMENTS_HPP
#define QUACK_STATEMENTS_HPP

#include "master_include.hpp"
#include "QuackExpressions.hpp"


class MethodClass;


/*

*/


enum ControlStatementType
{
	SequentialStatementType,
	IfElseListStatementType,
	WhileStatementType,
	ReturnStatementType,
	AssignmentStatementType,
	SingleStatementType
};

/*

*/
class ControlStatement : public GraphVizNodeDecorator
{
public:
	ControlStatement(SyntaxNode* ptr);
	~ControlStatement() {}
	virtual ControlStatementType GetStatementType() = 0;
	virtual void Print() = 0;
	virtual ControlStatement *Reduce() { return this; }
	virtual std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren() =0;
	virtual bool TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod) = 0;
	virtual void GenCode(std::stringstream &ss, MethodClass* cur_method)=0;

public:
	SyntaxNode *NearestSyntax;
	static void DoReduce(ControlStatement *&ptr);

};

/*
	One statement followed by another.  List of statements
*/
class SequentialStatement: public ControlStatement
{
public:
	SequentialStatement(SyntaxNode* ptr);
	~SequentialStatement();
	virtual ControlStatementType GetStatementType();
	ControlStatement *Reduce();
	virtual std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren();

	virtual void Print();
	virtual bool TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod);
	virtual void GenCode(std::stringstream &ss, MethodClass* cur_method);
public:
	std::vector<ControlStatement *>	Sequence;

};

/*
	Execute control statements based on the RExpressions
*/

class IfElseListStatement: public ControlStatement
{
public:
	IfElseListStatement(SyntaxNode* ptr);
	~IfElseListStatement();
	virtual ControlStatementType GetStatementType();

	void Add(RExpression *cond, ControlStatement *stmt);

	virtual void Print() ;
	virtual bool TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod);

	ControlStatement *Reduce() ;
	virtual std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren();
	virtual void GenCode(std::stringstream &ss, MethodClass* cur_method);
public:
	std::vector< std::pair<RExpression *,ControlStatement *> > ConditionalList;

};

/*
	Execute control statements repeatedly until the Condition is false
*/
class WhileStatement: public ControlStatement
{
public:
	WhileStatement(SyntaxNode* ptr, RExpression *rexp, ControlStatement *stmt);
	~WhileStatement();
	virtual ControlStatementType GetStatementType();

	ControlStatement *Reduce() ;
	virtual void Print() ;
	virtual bool TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod);

	virtual std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren();
	virtual void GenCode(std::stringstream &ss, MethodClass* cur_method);
public:
	RExpression *Condition;
	ControlStatement *Statements;
};

/*
	Return statement which includes a ReturnValue to evaluate
*/
class ReturnStatement: public ControlStatement
{
public:
	ReturnStatement(SyntaxNode* ptr, RExpression *rexp);
	~ReturnStatement();

	virtual ControlStatementType GetStatementType() ;
	virtual std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren();
	virtual void Print();
	virtual bool TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod);
	virtual void GenCode(std::stringstream &ss, MethodClass* cur_method);
public:
	RExpression *ReturnValue;
};


/*
	Evaluate the RExpression and put it in the LExpression location
*/
class AssignmentStatement: public ControlStatement
{
public:
	AssignmentStatement(SyntaxNode* ptr, LExpression *lexp, RExpression *rexp);
	~AssignmentStatement();

	virtual std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren();

	virtual ControlStatementType GetStatementType();
	virtual void Print();
	virtual bool TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod);
	virtual void GenCode(std::stringstream &ss, MethodClass* cur_method);

public:
	LExpression *Address;
	RExpression *Statement;

};


/*
	Single RExpression evaluates to a value
*/
class SingleStatement: public ControlStatement
{
public: SingleStatement(SyntaxNode* ptr, RExpression *stmt);
	~SingleStatement();
	virtual std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren();

	virtual ControlStatementType GetStatementType();
	virtual void GenCode(std::stringstream &ss, MethodClass* cur_method);
public:
	RExpression *Statement;
	virtual void Print();
	virtual bool TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod);
};





#endif
