#ifndef PROGRAMNODE_HPP
#define PROGRAMNODE_HPP

#include "master_include.hpp"

#include "GraphVizNodeDecorator.hpp"
#include "quack.tab.hpp"

extern int yylineno;

enum ProgramNodeType
{
	SyntaxNodeType,
	SemanticNodeType
};

extern std::string TOP_STRING;
extern std::string OBJ_STRING;
extern std::string INT_STRING;
extern std::string BOOL_STRING;
extern std::string STRING_STRING ;
extern std::string NOTHING_STRING;
extern std::string BOTTOM_STRING;

//
//
//	This is where the syntax and semantic tree definition begins.
//
//


class ProgramNode: public GraphVizNodeDecorator
{
	public: 
		ProgramNode();
		virtual	~ProgramNode();
	
		std::vector<ProgramNode *> Children;
		virtual std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren();
	public:
		virtual ProgramNodeType NodeType() = 0;
};

class SyntaxNode: public ProgramNode
{
	public:
		SyntaxNode(std::string text_match,yytokentype token_type,int line_num);
		virtual ~SyntaxNode();
		ProgramNodeType NodeType();
	public:
		const int LineNumber;
		const std::string TextMatch;
		const yytokentype TokenType;
};


class SemanticNode: public ProgramNode
{
	public:
		SemanticNode(std::string semantic_name);
		virtual ~SemanticNode();
		virtual ProgramNodeType NodeType();
	public:
		const std::string SemanticName;
		
		
};

SemanticNode * MakeSemanticNode(std::string semantic_name);
SemanticNode * MakeSemanticNode(std::string semantic_name,ProgramNode *child0);
SemanticNode * MakeSemanticNode(std::string semantic_name,ProgramNode *child0,ProgramNode *child1);
SemanticNode * MakeSemanticNode(std::string semantic_name,ProgramNode *child0,ProgramNode *child1,ProgramNode *child2);
SemanticNode * MakeSemanticNode(std::string semantic_name,ProgramNode *child0,ProgramNode *child1,ProgramNode *child2,ProgramNode *child3);
SemanticNode * MakeSemanticNode(std::string semantic_name,ProgramNode *child0,ProgramNode *child1,ProgramNode *child2,ProgramNode *child3,ProgramNode *child4);
SemanticNode * MakeSemanticNode(std::string semantic_name,ProgramNode *child0,ProgramNode *child1,ProgramNode *child2,ProgramNode *child3,ProgramNode *child4,ProgramNode *child5);




std::string ReplaceAll(std::string str, const std::string& from, const std::string& to);
std::string AllocVar(std::string class_type, std::stringstream &ss);
std::string AllocVarCast(std::string class_type, std::string old_reg, std::stringstream &ss );
std::string AllocLabel();
std::string GetObjPtr(std::string type_name);
std::string EscapeString(std::string str);
std::string GetClassPtr(std::string type_name);
std::string GetGlobalClass(std::string type_name);



void SET_LOG_FUNC(bool v);
void SET_ERROR_LOGGING(bool v);
void SET_VAR_LOGGING(bool v);
void FUNC_LOG(std::string log);
void ERR_LOG(std::string log);
void ERR_LOG(std::string log, SyntaxNode *node);
void VAR_LOG(std::string log);
std::string HEX_STR(void* ptr);
std::string INT_STR(int val);
std::string INT_STR(size_t val);

void VAR_ADD();
void VAR_SUB();



class SymbolTable
{


public:
	SymbolTable(std::string class_name);
	std::string Lookup(std::string name);

	void print();
	SymbolTable *Duplicate();

public:

	std::map<std::string, std::string> SymTable;
	const std::string ClassName;

};


class NamedType: public GraphVizNodeDecorator
{
public:
	NamedType(SyntaxNode* ptr, std::string name,std::string type);
	~NamedType();
	//void Print();
	virtual std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren();

	void ExtractSymbolTable(SymbolTable &table);
	bool TypeCheck(SymbolTable &SymTab);

public:
	const std::string Name;
	const std::string Type;
	SyntaxNode *NearestSyntax;
};




#endif
