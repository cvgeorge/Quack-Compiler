
#include "CompilerDB.hpp"
#include <iostream>
#include <cstdlib>

CompilerDatabase::CompilerDatabase()
{

	ClassStack = new RegisterStack<ClassClass>("ClassStack");
	ArgStack= new RegisterStack<NamedType>("ArgStack");

	MethodStack= new RegisterStack<MethodClass>("MethodStack");

	ControlStack= new RegisterStack<SequentialStatement>("ControlStack");

	ExpContextRSM = new RegisterStack<RegisterStack<Expression> >("ExpContextRSM");
	ExpContextRSM->SetReg(new RegisterStack<Expression>("ExpRSM"));
	Root = 0;
	ProgramStatements =0;
	LastSyntaxNode  =0;
}

CompilerDatabase::~CompilerDatabase()
{

}

void CompilerDatabase::PrintDatabase()
{
	FUNC_LOG(__FUNCTION__);

	VAR_LOG("Printing Entire Database of Compiler Information: ");

	VAR_LOG("Printing syntax type name & numbers: " );
	for(auto itr  = SyntaxNamesToSyntaxTypes.begin(); itr != SyntaxNamesToSyntaxTypes.end(); itr++)
	{
		int temp = (int)itr->second;
		std::string type = itr->first;
		VAR_LOG( type + " : " + INT_STR(temp));
	}
	VAR_LOG("Printing Class definitions: ");

	for(auto itr = FinalProgram.begin(); itr != FinalProgram.end(); itr++)
	{
		VAR_LOG("Printing Class: "  + HEX_STR(*itr));
		if((*itr)!=NULL)
		{
			(*itr)->Print();
		}
	}
	VAR_LOG("Printing Main Program: " + HEX_STR(ProgramStatements));

	if(ProgramStatements!=NULL)
	{
		ProgramStatements->Print();
	}
}

void CompilerDatabase::DoReduce()
{
	for(auto itr = FinalProgram.begin(); itr != FinalProgram.end(); itr++)
	{
		if((*itr)!=NULL)
		{
			(*itr)->Reduce();
		}
	}
	
	ControlStatement::DoReduce(ProgramStatements);

	
}





/*
bool CompilerDatabase::ValidateClassHierarchy()
{
	bool returnValue = true;

	std::vector<std::string> classes;

	for(auto itr = ClassHierarchy.begin(); itr != ClassHierarchy.end(); itr++)
	{
		classes.push_back(itr->first);

	}
	for(auto itr = classes.begin(); itr != classes.end(); itr++)
	{
		std::string class_name = (*itr);
		std::string parent_class = ClassHierarchy[class_name];
		std::vector<std::string> visited_class_list;
		visited_class_list.push_back(class_name);


		bool done = false;
		bool error = false;

		std::stringstream error_string ;
		std::string class_string = class_name;
		
		

		while(!done)
		{
			class_string += " : " + parent_class;

			auto finder = ClassHierarchy.find(parent_class);
			
			if(finder != ClassHierarchy.end())
			{
				class_name = finder->first;
				parent_class = finder->second;

				auto visit_test = std::find(visited_class_list.begin(),visited_class_list.end(),class_name);

				if(visit_test != visited_class_list.end())
				{
					done = true;
				}
				else
				{
					visited_class_list.push_back(class_name);
				}
			}
			else
			{
				done = true;
			}
		}

		if(visited_class_list[visited_class_list.size() -1].compare("Obj")!=0)
		{
			error = true;
		}


		if(error)
		{
			returnValue = false;
			error_string << " Invalid Class Structure: " << class_name << std::endl;
			error_string << " Error on line: " <<   ClassDefinitions[class_name]->NearestSyntax->LineNumber << std::endl;
			error_string << " Class Hierarchy [" << class_string << "]" << std::endl << std::endl;
			ERR_LOG(error_string.str());
		}
		else
		{
			
		}
	}

	return returnValue;

}
*/

SyntaxNode * CompilerDatabase::AddName(std::string name,yytokentype tokentype,SyntaxNode *ptr)
{
	FUNC_LOG("AddName : " + name + " : " + INT_STR((int)tokentype));
	SyntaxNamesToSyntaxTypes[name] = tokentype;
	SyntaxTypesToSyntaxNames[tokentype] = name;

	SyntaxNodesByType[tokentype].push_back(ptr);

	LastSyntaxNode = ptr;
	return ptr;
}
/*
void CompilerDatabase::MakeCurClassClass(std::string class_name,std::string class_parent, SyntaxNode *ptr)
{
	FUNC_LOG(__FUNCTION__);
	FUNC_LOG("MakeCurClassClass "  + class_name + " : " + class_parent ) ;
	CurClassClassPtr = new ClassClass();
	CurClassClassPtr->NearestSyntax = ptr;
	CurClassClassPtr->TypeName = new NamedType(class_name,class_name);
	CurClassClassPtr->Arguments = CurArgumentList;
	ClearArgList();
	
	auto finder = ClassHierarchy.find(class_name);

	if(finder == ClassHierarchy.end())
	{
		ClassDefinitions[class_name] = CurClassClassPtr;
		ClassHierarchy[class_name]=class_parent;
	}
	else
	{
		ERR_LOG("Error on line:  " + ptr->LineNumber);
		ERR_LOG("Class Type defined already:  " + class_name);
	}
}

void CompilerDatabase::ClearArgList()
{
	FUNC_LOG(__FUNCTION__);
	CurArgumentList.clear();
}

void CompilerDatabase::ClearMethodList()
{
	FUNC_LOG(__FUNCTION__);
	CurMethodClassList.clear();
}

void CompilerDatabase::FinalizeClassClass()
{
	FUNC_LOG(__FUNCTION__);
	// Class name and Args are done during MakeCurClassClass
	
	for(auto itr = CurMethodClassList.begin(); itr != CurMethodClassList.end(); itr++)
	{
		MethodClass *ptr = (*itr);
		CurClassClassPtr->Methods[ptr->NameReturn->Name].push_back(ptr);
	}
	ClearMethodList();
	// pickup statements

	// pickup variables
	CurClassClassPtr =0;
}

void CompilerDatabase::AddArgListItem(std::string name, std::string type)
{
	FUNC_LOG(__FUNCTION__);
	CurArgumentList.push_back(new NamedType(name,type));
}

void CompilerDatabase::MakeCurMethodClass(std::string method_name, std::string method_type,SyntaxNode *ptr)
{
	FUNC_LOG(__FUNCTION__);
	CurMethodClassPtr = new MethodClass();
	CurMethodClassPtr->NearestSyntax = ptr;
	CurMethodClassPtr->NameReturn = new NamedType(method_name,method_type);
	CurMethodClassPtr->Arguments = CurArgumentList;
	ClearArgList();

}

void CompilerDatabase::MakeCurVariableClass(SyntaxNode *ptr)
{
	std::cout << "MakeCurVariableClass " << std::endl;
	CurVariableClassPtr = new VariableClass();
	CurVariableClassPtr->NearestSyntax = ptr;
	
}


void CompilerDatabase::StartSequence()
{
	FUNC_LOG(__FUNCTION__);
	CurrentSequentialStatement = new SequentialStatement();
}


SequentialStatement *CompilerDatabase::FinalizeSequence()
{
	FUNC_LOG(__FUNCTION__);
	SequentialStatement *returnValue = CurrentSequentialStatement;
	CurrentSequentialStatement = NULL;
	return returnValue;
}


void CompilerDatabase::BeginStatementList()
{
	FUNC_LOG(__FUNCTION__);
	ControlFlowStack.push_back(CurrentSequentialStatement);
	CurrentSequentialStatement = new SequentialStatement();
}

void CompilerDatabase::EndStatementList()
{
	FUNC_LOG(__FUNCTION__);
	SequentialStatement * top = ControlFlowStack.back();

	top->Sequence.push_back(CurrentSequentialStatement);
	//top->Sequence.pop_back();
	ControlFlowStack.pop_back();

	CurrentSequentialStatement = top;
}

void CompilerDatabase::AddStatement(ControlStatement *statement)
{
	FUNC_LOG(__FUNCTION__);
	CurrentSequentialStatement->Sequence.push_back(statement);
}
*/

ClassClass *CompleteProgram::LookupClass(std::string class_name)
{
	ClassClass *returnValue = NULL;

	for( auto cls = ClassDefines.begin(); cls != ClassDefines.end(); cls++)
	{
		if((*cls)->TypeName->Name.compare(class_name)==0)
		{
			returnValue = (*cls);
			break;
		}
	}
	return returnValue;
}

MethodClass *CompleteProgram::LookupClassMethod(std::string class_name,std::string method)
{
	ClassClass *cc = LookupClass(class_name);
	if(cc == NULL)
		return NULL;


	MethodClass *mc = cc ->LookupMethod(method);

	if(mc != NULL)
		return mc;

	if(class_name.compare(OBJ_STRING) == 0)
		return NULL;

	return LookupClassMethod(cc->ParentName,method);
}



CompilerDatabase *StaticRoot;

CompilerDatabase *GetDB()
{
	if(StaticRoot == NULL)
	{
		StaticRoot = new CompilerDatabase();
	}
	return StaticRoot;
}


SyntaxNode	*LastSyntax()
{
	return GetDB()->LastSyntaxNode;
}


RegisterStack<ClassClass> *ClassRSM()
{
	return GetDB()->ClassStack;
}

RegisterStack<NamedType> *ArgsRSM()
{
	return GetDB()->ArgStack;
}

RegisterStack<MethodClass> *MethRSM()
{
	return GetDB()->MethodStack;
}

RegisterStack<SequentialStatement> *StmtRSM()
{
	return GetDB()->ControlStack;
}

RegisterStack<Expression> *ExpRSM()
{
	return GetDB()->ExpContextRSM->Top();
}

RegisterStack<RegisterStack<Expression> > *ExpContextRSM()
{
	return GetDB()->ExpContextRSM;
}





