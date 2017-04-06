#ifndef COMPILERDB_HPP
#define COMPILERDB_HPP

#include "master_include.hpp"

#include "ProgramNode.hpp"
#include "QuackDefines.hpp"


template<class T>
class RegisterStack
{
public:
	RegisterStack(std::string name):Name(name)
	{
		Register = 0;
	}

	//
	//
	T	*Top()
	{
		if (Register==0) 
		{
			ERR_LOG(Name + " : TOP IS NULL ERROR");
		}
		return Register;
	}

	//
	//
	void	SetReg(T *reg) 
	{
		if (Register!=0)
		{
			ERR_LOG(Name + " :SET REG REGISTER IS NOT NULL");
		} 
		if (reg ==0)
		{
			ERR_LOG(Name + " :SET REG REGISTER TO NULL");
		} 
		Register = reg;
	}

	//
	//
	T *	GetReg() 
	{
		if (Register==0)
		{
			ERR_LOG(Name + " :GET REGISTER ERROR");
		} 
		T * returnValue = Register;
		Register = 0;
		return returnValue;
	}

	//
	//
	void 	Push(T *store)
	{
		if(store == 0)
		{
			ERR_LOG(Name + " :PUSH NULL STACK ERROR");
		}
		Stack.push_back(store);
	}

	//
	//
	T 	*Pop()
	{
		T *load = Stack.back();
		Stack.pop_back();
		return load;
	}

	//
	//
	void	PopReg()
	{	
		SetReg(Pop());
	}

	//
	//
	void	PushReg()
	{
		Push(GetReg());
	}

	//
	//
	T	*FinalizeRegister()
	{
		T	*last = Register;
		Register  =0;
		if(Stack.size() > 0)
		{
			//ERR_LOG(Name + " :STACK NOT EMPTY IN FINALIZE REGISTER.");
		}
		return last;
	}

	//
	//
	std::vector<T *> FinalizeStack()
	{
		std::vector<T *> returnValue = Stack;
		if(Register != 0)
		{
			//ERR_LOG(Name + " :REGISTER NOT EMPTY IN FINALIZE STACK.");
		}
		Stack.clear();
		return returnValue;
	}


private:
	const std::string	Name;
	T	*Register;
	std::vector<T *> Stack;
};

class CompleteProgram: public GraphVizNodeDecorator
{
public:
	CompleteProgram(ProgramNode *semantic_syntax, std::vector<ClassClass *> class_definitions, ControlStatement *program)
	{
		FUNC_LOG("CompleteProgram(ProgramNode *semantic_syntax, std::vector<ClassClass *> class_definitions, ControlStatement *program)");
		NodeLabel = "none";
		NodeShape = "point\", style=\"invis";
		SyntaxSemanticTree = semantic_syntax;
		ClassDefines = class_definitions;
		Program = program;
		Mode = 0;
		Main = NULL;
	}
	~CompleteProgram(){}

	void GenerateSemanticSyntax(std::string base_file_name)
	{
		FUNC_LOG("void GenerateSemanticSyntax(std::string base_file_name)");
		base_file_name += "SemanticSyntax.dot";

		std::ofstream file(base_file_name, std::ofstream::out);

		std::string buf = GenerateGraphviz(SyntaxSemanticTree,true,base_file_name );

		file << buf;
		file.close();
	}

	void GenerateProgram(std::string base_file_name)
	{
		FUNC_LOG("void GenerateProgram(std::string base_file_name)");
		base_file_name += "Program.dot";
		std::ofstream file(base_file_name, std::ofstream::out);

		Mode = 1;
		std::string buf = GenerateGraphviz(this,true,base_file_name);

		file << buf;
		file.close();
	}

	void GenerateProgramSemanticSyntax(std::string base_file_name)
	{
		FUNC_LOG("void GenerateProgramSemanticSyntax(std::string base_file_name)");
/*
		std::ofstream file(base_file_name + "ProgramSemanticSyntax.dot", std::ofstream::out);

		std::string buf = GenerateGraphviz(SyntaxSemanticTree);

		file << buf;
		file.close();
*/
	}

	virtual std::string GenerateGravizEdgeDecoration(GraphVizNodeDecorator *edge)
	{
		return "[style =invis]";
	}

	std::vector<GraphVizNodeDecorator *> GenerateGraphvizChildren()
	{
		std::vector<GraphVizNodeDecorator *> returnValue;
		for(std::vector<ClassClass *>::iterator itr = ClassDefines.begin(); itr != ClassDefines.end(); itr++)
		{
			if((*itr)!= NULL)	
			{
				returnValue.push_back(*itr);
			}
		}
		if(Program != NULL)
		{
			returnValue.push_back(Program);
		}

		return returnValue;
	}
	

	ClassClass *LookupClass(std::string class_name);
	MethodClass *LookupClassMethod(std::string class_name,std::string method);

public:

	int Mode;

	ProgramNode *SyntaxSemanticTree;
	std::vector<ClassClass *> ClassDefines;
	ControlStatement *Program;

	MethodClass *Main;

};


class CompilerDatabase
{
	public:
		CompilerDatabase();
		virtual ~CompilerDatabase();

		void PrintDatabase();
		//bool ValidateClassHierarchy();
		void DoReduce();
	
	public:
		// Syntax node and primitive representation tools.
		ProgramNode *Root;
		SyntaxNode *AddName(std::string name,yytokentype tokentype,SyntaxNode *ptr);


		// Class and method tools.
	public:
		RegisterStack<ClassClass>		*ClassStack;
		RegisterStack<NamedType>		*ArgStack;

		RegisterStack<MethodClass>		*MethodStack;

		RegisterStack<SequentialStatement>	*ControlStack;


	public:
		std::map<std::string,yytokentype> SyntaxNamesToSyntaxTypes;
		std::map<yytokentype,std::string> SyntaxTypesToSyntaxNames;
		std::map<yytokentype,std::vector<SyntaxNode *> > SyntaxNodesByType;
		

	public:	
//		RegisterStack<Expression>	*ExpRSM;
		RegisterStack<RegisterStack<Expression>>	*ExpContextRSM;

	public:

		std::vector<ClassClass *>		FinalProgram;
		ControlStatement *			ProgramStatements;

		SyntaxNode *				LastSyntaxNode;
};

SyntaxNode	*LastSyntax();
CompilerDatabase *GetDB();

RegisterStack<ClassClass> *ClassRSM();
RegisterStack<NamedType> *ArgsRSM();
RegisterStack<MethodClass> *MethRSM();
RegisterStack<SequentialStatement> *StmtRSM();
RegisterStack<Expression> *ExpRSM();
RegisterStack<RegisterStack<Expression> > *ExpContextRSM();




#endif
