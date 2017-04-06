#include "ProgramNode.hpp"
#include <iostream>
#include <cstdlib>

int error_count = 0;
int var_tab_count =0;

bool LOG_FUNC = false;
bool VAR_LOGGING = false;
bool ERROR_LOGGING = false;

std::string TOP_STRING = "$TOP";
std::string OBJ_STRING = "Obj";
std::string INT_STRING = "Int";
std::string BOOL_STRING = "Boolean";
std::string STRING_STRING = "Str";
std::string NOTHING_STRING = "Nothing";
std::string BOTTOM_STRING = "$BOTTOM";

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

std::string EscapeString(std::string str)
{
	std::string returnValue = ReplaceAll(str,std::string("\""),std::string("\\\""));

	return returnValue;
}

void VAR_ADD()
{
	var_tab_count ++;
}

void VAR_SUB()
{
	var_tab_count--;
}

std::string HEX_STR(void* ptr)
{
	std::stringstream ss;
	ss << " " << std::hex << " " << ptr;
	return ss.str();	
}

std::string INT_STR(int val)
{
	std::stringstream ss;
	ss << " " << std::dec << " " << val;
	return ss.str();	
}

std::string INT_STR(size_t val)
{
	std::stringstream ss;
	ss << std::dec << val;
	return ss.str();	
}

void SET_LOG_FUNC(bool v)
{
	LOG_FUNC = v;
}
void SET_VAR_LOGGING(bool v)
{
	VAR_LOGGING = v;
}
void SET_ERROR_LOGGING(bool v)
{
	ERROR_LOGGING = v;
}

void VAR_LOG(std::string log)
{
	if(VAR_LOGGING)
	{
		std::cout << "VAR_LOG:\t" ;

		for(int i =0; i < var_tab_count; i++)
		{
			std::cout << " ";
		}
		std::cout << log << std::endl;
	}
}

void FUNC_LOG(std::string log)
{
	if(LOG_FUNC)
	{
		std::cout << "FUNC_LOG:\t" << log << std::endl;
	}
}

void ERR_LOG(std::string log)
{
	if(ERROR_LOGGING)
	{
		std::cerr << "Error Count: " << error_count++ << " = " << log << std::endl;
	}
}

void ERR_LOG(std::string log, SyntaxNode *node)
{
	if(ERROR_LOGGING)
	{
		std::cerr << "Error Count: " << error_count++ << " = " << log << " ::  Error on line " << node->LineNumber << std::endl;
	}
}

ProgramNode::ProgramNode()
{
	
}


ProgramNode::~ProgramNode()
{
	for(std::vector<ProgramNode *>::iterator itr = Children.begin(); itr != Children.end(); itr++)
	{	
		delete (*itr);
	}
}

std::vector<GraphVizNodeDecorator *> ProgramNode::GenerateGraphvizChildren()
{
	std::vector<GraphVizNodeDecorator *> returnValue;
	for(std::vector<ProgramNode *>::iterator itr = Children.begin(); itr != Children.end(); itr++)
	{	
		returnValue.push_back(*itr);
	}
	return returnValue;
}


SemanticNode::SemanticNode(std::string semantic_name):SemanticName(semantic_name)
{
	NodeLabel = semantic_name;
	NodeShape = "rectangle";
}

SemanticNode::~SemanticNode()
{
}

ProgramNodeType SemanticNode::NodeType()
{
	return SemanticNodeType;
}

SemanticNode * MakeSemanticNode(std::string semantic_name)
{
	//FUNC_LOG("MakeSemanticNode 0 : " + semantic_name+ INT_STR(yylineno));
	return new SemanticNode(semantic_name);
}

SemanticNode * MakeSemanticNode(std::string semantic_name,ProgramNode *child0)
{
	//FUNC_LOG("MakeSemanticNode 1 : " + semantic_name + INT_STR(yylineno));
	SemanticNode *returnValue = new SemanticNode(semantic_name);
	returnValue->Children.push_back(child0);
	return returnValue;
}

SemanticNode * MakeSemanticNode(std::string semantic_name,ProgramNode *child0,ProgramNode *child1)
{
//	FUNC_LOG("MakeSemanticNode 2 : " + semantic_name+ INT_STR(yylineno));
	SemanticNode *returnValue = new SemanticNode(semantic_name);
	returnValue->Children.push_back(child0);
	returnValue->Children.push_back(child1);
	return returnValue;
}

SemanticNode * MakeSemanticNode(std::string semantic_name,ProgramNode *child0,ProgramNode *child1,ProgramNode *child2)
{
//	FUNC_LOG("MakeSemanticNode 3 : " + semantic_name+ INT_STR(yylineno));
	SemanticNode *returnValue = new SemanticNode(semantic_name);
	returnValue->Children.push_back(child0);
	returnValue->Children.push_back(child1);
	returnValue->Children.push_back(child2);
	return returnValue;
}

SemanticNode * MakeSemanticNode(std::string semantic_name,ProgramNode *child0,ProgramNode *child1,ProgramNode *child2,ProgramNode *child3)
{
//	FUNC_LOG("MakeSemanticNode 4 : " + semantic_name+ INT_STR(yylineno));
	SemanticNode *returnValue = new SemanticNode(semantic_name);
	returnValue->Children.push_back(child0);
	returnValue->Children.push_back(child1);
	returnValue->Children.push_back(child2);
	returnValue->Children.push_back(child3);
	return returnValue;
}

SemanticNode * MakeSemanticNode(std::string semantic_name,ProgramNode *child0,ProgramNode *child1,ProgramNode *child2,ProgramNode *child3,ProgramNode *child4)
{
//	FUNC_LOG("MakeSemanticNode 5 : " + semantic_name+ INT_STR(yylineno));
	SemanticNode *returnValue = new SemanticNode(semantic_name);
	returnValue->Children.push_back(child0);
	returnValue->Children.push_back(child1);
	returnValue->Children.push_back(child2);
	returnValue->Children.push_back(child3);
	returnValue->Children.push_back(child4);
	return returnValue;
}

SemanticNode * MakeSemanticNode(std::string semantic_name,ProgramNode *child0,ProgramNode *child1,ProgramNode *child2,ProgramNode *child3,ProgramNode *child4,ProgramNode *child5)
{
//	FUNC_LOG("MakeSemanticNode 6 : " + semantic_name + INT_STR(yylineno));
	SemanticNode *returnValue = new SemanticNode(semantic_name);
	returnValue->Children.push_back(child0);
	returnValue->Children.push_back(child1);
	returnValue->Children.push_back(child2);
	returnValue->Children.push_back(child3);
	returnValue->Children.push_back(child4);
	returnValue->Children.push_back(child5);
	return returnValue;
}

std::string ReplaceString(std::string subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
    return subject;
}

SyntaxNode::SyntaxNode(std::string text_match,yytokentype token_type,int line_num):LineNumber(line_num),
											TextMatch(text_match),
											TokenType(token_type)
{
	NodeLabel = ReplaceString(text_match, "\"","\\\"");
}

SyntaxNode::~SyntaxNode()
{
}

ProgramNodeType SyntaxNode::NodeType()
{
	return SyntaxNodeType;
}



NamedType::NamedType(SyntaxNode *ptr, std::string name,std::string type):Name(name),Type(type)
{
	NodeLabel = EscapeString(Name) + " : " + EscapeString(Type);
	NodeShape = "box";
	NearestSyntax = ptr;
}

NamedType::~NamedType()
{
}


bool NamedType::TypeCheck(SymbolTable &SymTab)
{
	return true;
}


std::vector<GraphVizNodeDecorator *>  NamedType::GenerateGraphvizChildren()
{
	std::vector<GraphVizNodeDecorator *> returnValue;
	return returnValue;
}

SymbolTable::SymbolTable(std::string class_name):ClassName(class_name)
{
	this->SymTable["this"] = class_name;
	this->SymTable[class_name] = class_name;
}




void SymbolTable::print()
{
	std::stringstream ss;
	ss << "[\n";
	for(auto itr = SymTable.begin(); itr != SymTable.end(); itr++)
	{
		ss << (*itr).first << "  :  " << (*itr).second << "\n";
	}
	ss << "]\n";
	VAR_LOG(ss.str());
}

std::string SymbolTable::Lookup(std::string name)
{

	if ( SymTable.find(name) == SymTable.end() )
	{
	  	//ERR_LOG("Symbol not found!");
	  	return TOP_STRING;
	}
	else
	{
		return SymTable[name];
	}

}


SymbolTable *SymbolTable::Duplicate()
{
	SymbolTable *returnValue = new SymbolTable(this->ClassName);

	for(auto itr = this->SymTable.begin();itr != this->SymTable.end(); itr++)
	{
		returnValue->SymTable[(*itr).first] = (*itr).second;
	}
	return returnValue;
}

/*
bool SymbolTable::UpdateTable(std::string name, std::string type)
{

	// If the NameTag is already in the table
	if ( SymTable.find(name) != SymTable.end() )
	{
		// False indicates that there was a change in the table
		//  SymTable[nt] = QuackProgramValidator.LowestCommonAncestor(type, SymTable[nt]);  UNCOMMENT THIS
		SymTable[name] = type;
		ContainsChanges = true;
		return false;
	}
	else
	{
		SymTable[name] = type;
		return true;
	}
}


std::vector<std::string> SymbolTable::GetKeys()
{
	std::vector<std::string> keyList;
	for(auto itr = SymTable.begin(); itr != SymTable.end(); itr++)
	{
		keyList.push_back(itr->first);
	}
	return keyList;
}

bool SymbolTable::MergeTables(SymbolTable &table)
{
	std::vector<std::string> MergingTableKeys = table.GetKeys();
	for(size_t i = 0; i < MergingTableKeys.size(); i++)
	{
		if(SymTable.find(MergingTableKeys[i]) != SymTable.end())
		{
			// If the key is already in the table
			ERR_LOG("Error! Attempted to add key " + MergingTableKeys[i] + " to the symbol table");
			return false;
		}
		else
		{
			SymTable[MergingTableKeys[i]] = table.SymTable[MergingTableKeys[i]];
		}
	}
	return true;
}

void SymbolTable::UnmergeTables(SymbolTable &table)
{
	std::vector<std::string> MergingTableKeys = table.GetKeys();

	for(size_t i = 0; i < MergingTableKeys.size(); i++)
	{
		SymTable.erase(MergingTableKeys[i]);
	}
}



*/
int LabelCount = 0;

std::string AllocLabel()
{
	std::stringstream temp;
	temp << "label_" << std::dec << LabelCount++ << "_";

	std::string var_name = temp.str();
	return var_name;
}

std::map<std::string, int> var_name_map;

std::string AllocVarCast(std::string class_type, std::string old_reg, std::stringstream &ss )
{
	if(class_type.compare("")==0) { throw "Bad AllocVarCast";}
	if(old_reg.compare("")==0) { throw "Bad AllocVarCast";}
	std::string cast_reg= AllocVar(class_type,ss);
	std::string obj_ptr = GetObjPtr(class_type);
	std::string arg_cast = "( (" + obj_ptr +")"+old_reg + ")";
	ss << "\t" << cast_reg << " = " << arg_cast <<  "; " << std::endl;
	return cast_reg;
}

std::string AllocVar(std::string class_type, std::stringstream &ss)
{
	if(class_type.compare("")==0) { throw "Bad AllocVar";}

	int i = var_name_map[class_type];
	var_name_map[class_type]++;

	std::stringstream temp;
	temp << class_type << "_gen_" << std::dec << i;

	std::string var_name = temp.str();

	ss << "\t" << GetObjPtr(class_type) << var_name << " = NULL; // Default New Var reg of type: " << class_type << std::endl;
	return var_name;
}

std::string GetObjPtr(std::string type_name)
{
	if(type_name.compare("")==0) { throw "Bad GetObjPtr";}
	return std::string("Object_") + type_name + "* ";
}

std::string GetClassPtr(std::string type_name)
{
	if(type_name.compare("")==0){ throw "Bad GetClassPtr";}
	return std::string("Class_") + type_name +"* ";
}

std::string GetGlobalClass(std::string type_name)
{
	if(type_name.compare("")==0){ throw "Bad GetGlobalClass";}
	return std::string("GLOBAL_Class_") + type_name;
}
