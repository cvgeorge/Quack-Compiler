#ifndef QUACKDEFINES_HPP
#define QUACKDEFINES_HPP


#include "master_include.hpp"
#include "ProgramNode.hpp"
#include "QuackExpressions.hpp"
#include "QuackStatements.hpp"



void PrintVisualization(std::string base_file_name,bool valid);
extern bool show_semantic_tree;
extern bool show_program_tree;



/*

*/
class ClassClass;


class MethodClass: public GraphVizNodeDecorator
{
public:
	MethodClass(SyntaxNode* ptr);
	~MethodClass();
	virtual std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren();
	void 	Reduce();
	void	Print();
	bool 	TypeCheck(SymbolTable *SymTab);


public:
	NamedType								*NameReturn;
	std::vector<NamedType*>					Arguments;
	std::map<std::string,std::string>		VariablesTypes;	  //NOTE: It will probably be helpful to populate this ONLY with top-level variables.  I.E. if a variable only exists in a while loop, it shouldn't be here.  I think this will make type checking easier with scope
	ControlStatement						*Statements;  //NOTE: I think we can change this from a Control Statement to a Sequential Statement
	SyntaxNode								*NearestSyntax;
	ClassClass								*Parent;
	bool									UpdatedType;

	std::string GenPointer(std::string obj_type_name);

	void GenerateFunction(std::stringstream &ss);

	std::string GetMethodName();
	std::map<std::string, std::string> quack_c_map;
//	std::map<std::string,llvm::Value *> mapped_names;

	virtual void GenerateCode(std::stringstream &ss);

	std::string GetMethodParams();
protected:

	std::string FunctionName;
};


/*

*/
class ClassClass: public GraphVizNodeDecorator
{
public:
	ClassClass(SyntaxNode* ptr);
	~ClassClass();

	virtual std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren();

	void	Reduce() ;
	MethodClass* LookupMethod(std::string method_name);

	void	Print();
	bool	TypeCheck(SymbolTable *SymTab);
	virtual void DefineType(std::stringstream &ss);

public:
	SyntaxNode							*NearestSyntax;
	NamedType 							*TypeName;

	std::string							ParentName;
	ClassClass							*ParentClass;
	std::vector<MethodClass *>			Methods;
	std::map<std::string,std::string>	MemberVariables;

	MethodClass							*MethodConstructor;

	std::vector<std::string> 			GenMethodList();
	std::vector<std::string> 			GenMemberList();

	std::string							ClassTypeName();
	std::string							ObjectTypeName();

};

#endif

