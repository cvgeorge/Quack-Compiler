#include "QuackDefines.hpp"

#include "NativeObject.hpp"
#include "CCodeGenerator.hpp"
#include "QuackProgramValidator.hpp"


bool show_program_tree = false;
bool show_semantic_tree = false;

void PrintVisualization(std::string base_file_name,bool valid)
{
	FUNC_LOG("void PrintVisualization(std::string base_file_name)");
	CompilerDatabase *database= GetDB();

	if(valid)
	{
		VAR_LOG("Before Printing DB.");

		database->PrintDatabase();

		VAR_LOG("After Printing DB." );

	}
	CompleteProgram *program = GetCompleteProgram();

	if(show_semantic_tree)
	{
		program -> GenerateSemanticSyntax(base_file_name);
	}

	if(show_program_tree)
	{
		program -> GenerateProgram(base_file_name);
	}
	//program -> GenerateProgramSemanticSyntax(base_file_name);

}


MethodClass::MethodClass(SyntaxNode* ptr)
{
	FUNC_LOG("MethodClass::MethodClass(SyntaxNode* ptr)");
	NearestSyntax = ptr;
	NameReturn =0;
	Statements = 0;
	UpdatedType = false;
	Parent = NULL;
}

MethodClass::~MethodClass()
{
}


std::vector<GraphVizNodeDecorator *> MethodClass::GenerateGraphvizChildren()
{
	FUNC_LOG("std::vector<GraphVizNodeDecorator *> MethodClass::GenerateGraphvizChildren()");
	std::vector<GraphVizNodeDecorator *> returnValue;

	NodeShape = "record";

	std::stringstream ss;
	
	ss << " {  <F0> "  << NameReturn->Name << " " << NameReturn->Type ;

	for(auto arg = Arguments.begin(); arg != Arguments.end(); arg++)
	{
		if(*arg!=NULL)
		{
			ss << "|" << (*arg)->Name + " : " + (*arg)->Type + "," ;
			returnValue.push_back(*arg);
		}
	}
	returnValue.push_back(Statements);
	ss << "} ";

	NodeLabel = ss.str();

	
	return returnValue;
}

void 	MethodClass::Reduce() 
{
	FUNC_LOG("void 	MethodClass::Reduce()");
	ControlStatement::DoReduce(Statements);
}

bool MethodClass::TypeCheck(SymbolTable *SymTab)
{
	FUNC_LOG("bool MethodClass::TypeCheck(SymbolTable *SymTab: " + this->NameReturn->Name + " : " + this->NameReturn->Type);



	for(auto arg = Arguments.begin(); arg != Arguments.end(); arg++)
	{
		std::string type_lookup = SymTab->Lookup((*arg)->Name);

		if(type_lookup.compare(TOP_STRING)==0)
		{
			SymTab->SymTable[(*arg)->Name] = (*arg)->Type;
		}
		else
		{
			std::string new_type = GetLowestCommonAncestor(type_lookup, (*arg)->Type);

			if(new_type.compare((*arg)->Type) !=0)
			{
				ERR_LOG("Input Argument \"" + (*arg)->Name+ "\" is already defined as a type of :" + (*arg)->Type, this->NearestSyntax);
				return false;
			}
		}
	}


	for(auto arg = VariablesTypes.begin(); arg != VariablesTypes.end(); arg++)
	{
		std::string type_lookup = SymTab->Lookup((*arg).first);

		if(type_lookup.compare(TOP_STRING)==0)
		{
			SymTab->SymTable[ (*arg).first ] = (*arg).second;
 		}
		else
		{
			std::string new_type = GetLowestCommonAncestor(type_lookup, (*arg).second);

			if(new_type.compare(type_lookup) !=0)
			{
				ERR_LOG("Invalid Type Mismatch between Outer symbol table \""+ type_lookup +"\" and usage inside method \"" + (*arg).second+ "\" as derived type is : " + new_type,this->NearestSyntax);
				return false;
			}
		}
	}

	if(!Statements->TypeCheck(SymTab, this))
	{
		ERR_LOG("Method failed to typecheck statements.",this->NearestSyntax);
		return false;
	}
	return true;
}

std::string MethodClass::GetMethodName()
{
	if(FunctionName.compare("") == 0)
	{
		if(Parent == NULL)
		{
			FunctionName = "class_MAIN_method_" + NameReturn->Name;
		}
		else
		{
			FunctionName = "Class_" + Parent->TypeName->Name + "_Method_" + NameReturn->Name;
		}
	}
	return FunctionName;
}

void MethodClass::GenerateFunction(std::stringstream &ss)
{
	FUNC_LOG("void MethodClass::GenerateFunction(std::stringstream &ss)");

	VAR_LOG("Adding arguments to function signature in method " + NameReturn->Name);


	// GetLLVMType should return the LLVM type we need based on the quack type of the argument
	// It's possible that GetLLVMType should just always return some sort of a class object (since everything is a class in quack)
	//NOTE: Not quite sure on this next line.  Should it be External Linkage?  And is this what we need to do with Twine?


	std::string returnValue = 	"Object_" + this->NameReturn->Type + "* "  + GetMethodName() + "(";

	returnValue += GetMethodParams();

	returnValue += ")";

	ss << returnValue << std::endl;
	ss << "{" << std::endl;

	ss << "// Adding Arguments to the named map " << std::endl;

	for(auto par_itr = Arguments.begin(); par_itr != Arguments.end(); par_itr++)
	{
		quack_c_map[(*par_itr)->Name] = (*par_itr)->Name;
	}

	ss << "// allocating variables." << std::endl;

	for(auto var_itr = VariablesTypes.begin(); var_itr != VariablesTypes.end(); var_itr++ )
	{
		//std::string name = (*var_itr).first;
		//std::string type = (*var_itr).second;


		///llvm::PointerType* arg_type = GetLLVMObjectPointerType(type);
		//llvm::AllocaInst* alloca = new llvm::AllocaInst(arg_type, name, StaticBlock);

		///mapped_names[name] = alloca;
		// potentially map<name,llvm::AllocaInst*>  ... this way you can reference a variable.
		std::string reg_name = AllocVar((*var_itr).second,ss);
		quack_c_map[(*var_itr).first] = reg_name;

	}

	NativeMethod *ptr = dynamic_cast<NativeMethod*>(this);

	if(ptr != NULL)
	{
		ptr->generateNativeCode(ss);

	}
	else
	{
		GenerateCode(ss);
	}

	ss << std::endl << "}" << std::endl;
}


std::string MethodClass::GenPointer(std::string obj_type_name)
{
	std::string returnValue = 	"Object_" + this->NameReturn ->Type + "* " + "(*" + GetMethodName() + ")(";

	returnValue += GetMethodParams();

	returnValue += ")";
	return returnValue;
}

void MethodClass::GenerateCode(std::stringstream &ss)
{
	FUNC_LOG("void MethodClass::GenerateCode(std::stringstream &ss)");

	// emit function here.

	if(this->NameReturn->Name.compare(this->NameReturn->Type)==0)
	{
		ss <<"\t" << this->Parent->ObjectTypeName() << " * returnValue = (" << this->Parent->ObjectTypeName() << " * )malloc(sizeof(" << this->Parent->ObjectTypeName() << "));" << std::endl;
		ss <<"\t" << "returnValue->_class_pointer = &GLOBAL_" +  this->Parent->ClassTypeName() << ";" << std::endl;

		// set each value to null in the constructor object?
		this->Statements->GenCode(ss, this);
		ss << "\t" << "return returnValue;" <<std::endl;

	}
	else
	{
		this->Statements->GenCode(ss, this);
	}
	// StaticExit = llvm::BasicBlock::Create(llvm::getGlobalContext(),llvm::Twine("exit"),StaticFunction,0);
	// llvm::LoadInst *load = new llvm::LoadInst(mapped_names["$returnValue"],"",StaticExit);
}

std::string MethodClass::GetMethodParams()
{
	std::stringstream returnValue;

	bool AddComma = false;
	if(this->Parent!=NULL)
	{
		if(this->NameReturn->Name.compare(this->NameReturn->Type)!=0)
		{
			returnValue << this->Parent->ObjectTypeName() + "* _this_ptr";
			AddComma = true;
		}

		for(auto itr = Arguments.begin(); itr != Arguments.end(); itr++)
		{
			if(AddComma)
			{
				returnValue << ", ";
			}
			returnValue << "Object_" << (*itr)->Type << "* " << (*itr)->Name;
			AddComma = true;
		}
	}
	return returnValue.str();
}


void MethodClass::Print()
{
	FUNC_LOG("void MethodClass::Print()");

	std::stringstream ss;


	ss << "def " << NameReturn->Name << "(" ;


	for(auto param = Arguments.begin(); param != Arguments.end(); param++)
	{

		if((*param) != NULL)
		{
			ss << (*param)->Name << " : " << (*param)->Type << " , ";
		}
	}
	ss<< ") : " << NameReturn->Type;

	VAR_LOG(ss.str());
	VAR_LOG("{");
	VAR_ADD();
	if(Statements!=NULL)
	{
		Statements->Print();
	}
	VAR_SUB();

	VAR_LOG("}");
}



ClassClass::ClassClass(SyntaxNode* ptr)
{
	FUNC_LOG("ClassClass::ClassClass(SyntaxNode* ptr)");
	TypeName =new NamedType(ptr,ptr->TextMatch,ptr->TextMatch); 
	NearestSyntax=ptr;
	ParentName = OBJ_STRING;
	MethodConstructor = NULL;
	ParentClass =NULL;

}
ClassClass::~ClassClass() 
{
}

std::vector<GraphVizNodeDecorator *> ClassClass::GenerateGraphvizChildren()
{
	FUNC_LOG("std::vector<GraphVizNodeDecorator *> ClassClass::GenerateGraphvizChildren()");
	std::vector<GraphVizNodeDecorator *> returnValue;

	NodeShape = "record";

	std::stringstream ss;
	
	ss << " { class "  << TypeName->Name << " : "<< ParentName << " "  ;


	ss  << " | " << MethodConstructor->NameReturn->Name << " ";

	returnValue.push_back(MethodConstructor);

	for(auto method = Methods.begin(); method != Methods.end(); method++)
	{
		if((*method) != NULL)
		{
			ss  << " | " << (*method)->NameReturn->Name << " ";
			returnValue.push_back(*method);
		}
	}

	ss << " } " ;
	NodeLabel = ss.str();

	return returnValue;
}

MethodClass* ClassClass::LookupMethod(std::string method_name)
{
	FUNC_LOG("MethodClass* ClassClass::LookupMethod(std::string method_name)");
	MethodClass *returnValue = NULL;

	if(0==this->MethodConstructor->NameReturn->Name.compare(method_name))
	{
		returnValue = this->MethodConstructor;
	}
	else
	{
		for(auto name_func= Methods.begin(); name_func != Methods.end(); name_func ++)
		{
			if((*name_func)->NameReturn->Name.compare(method_name)==0)
			{
				returnValue = (*name_func);
			}
		}
		if(returnValue == NULL)
		{
			if (ParentClass != this)
			{
				returnValue = ParentClass->LookupMethod(method_name);
			}
		}
	}
	return returnValue;
}


void	ClassClass::Reduce() 
{
	FUNC_LOG("void	ClassClass::Reduce() ");
	for(auto name_func = Methods.begin(); name_func != Methods.end(); name_func ++)
	{
		if((*name_func)!=NULL)
		{
			(*name_func)->Reduce();
			(*name_func)->Parent = this;
		}
	}
	MethodConstructor->Reduce();
	MethodConstructor->Parent = this;
}



bool ClassClass::TypeCheck(SymbolTable *SymTab)
{
	FUNC_LOG("bool ClassClass::TypeCheck(SymbolTable *SymTab) :   " + this->TypeName->Name + " :-> " + this->ParentName);


	// here we need to check the method again if the symbol tabled changed


	SymbolTable *construct = SymTab->Duplicate();
	bool done = false;
	while(!done)
	{
		MethodConstructor->UpdatedType = false;
		if(MethodConstructor->TypeCheck(construct))
		{
			if(true ==MethodConstructor->UpdatedType)
			{
				// type added or changed,
				// run type check on method again.
			}
			else
			{
				// no type changed.
				done = true;
			}
		}
		else
		{
			ERR_LOG("Failed to Type Check Constructor: " , MethodConstructor->NearestSyntax);
			delete construct;
			return false;
		}
	}

	std::string prefix = "this.";

	for(auto var = MethodConstructor->VariablesTypes.begin(); var != MethodConstructor->VariablesTypes.end(); var++)
	{
		std::string var_name = var->first;
		if(construct->Lookup(var_name).compare(TOP_STRING)!=0)
		{
			if(var->first.length() > prefix.length())
			{
				if(var->first.compare(0,prefix.length(),prefix)==0)
				{
					std::string temp = (*var).first;
					temp = temp.substr(prefix.length());
					this->MemberVariables[temp] = (*var).second;
				}
			}
		}
		else
		{
			throw "This should not happen here.";
			return false;
		}
	}
	delete construct;
	// also we need to check to see the types and see if anything is top and stop.

	// this along with the method routines, and anything that has sub spaces that can define
	// variables such as

	//	while(true)
	//	{
	//		a:int = 42;
	//		a.PRINT();
	//	}
	//
	//	thus the method variables captured after this routine need to be set as our members as well.

	for(auto itr = Methods.begin(); itr != Methods.end(); itr++)
	{
		SymbolTable *construct = SymTab->Duplicate();

		done = false;
		while(!done)
		{
			for(auto var = MemberVariables.begin(); var != MemberVariables.end(); var++)
			{
				construct->SymTable["this." + (*var).first] =  (*var).second;
			}


			(*itr)->UpdatedType = false;
			if((*itr)->TypeCheck(construct))
			{
				if(true ==(*itr)->UpdatedType)
				{
					// update the class variable types.

					/*
					for(auto method_var = (*itr)->VariablesTypes.begin();method_var != (*itr)->VariablesTypes.end(); method_var++ )
					{
						auto finder = MemberVariables.find(method_var->first);

						if(finder != MemberVariables.end())
						{
							MemberVariables[finder->first] = finder->second;
						}
					}
					*/

				}
				else
				{
					done = true;
				}
			}
			else
			{
				ERR_LOG("Failed to Type Check Method: " + (*itr)->NameReturn ->Name, (*itr)->NearestSyntax);
				delete construct;
				return false;
			}
		}
		delete construct;
	}
	//broken until this is fixed.
	return true;
}

/*
 * GetLLVMType
 *
 * Params ~ llvm::StructType - Type of class ; llvm::StructType - Type of object
 *
 * Returns ~ none
 *
 */

void ClassClass::DefineType(std::stringstream &ss)
{
	FUNC_LOG("void ClassClass::DefineType(std::stringstream &ss)");
	/// function definitions

	std::string ClassName = ClassTypeName();
	std::string ObjectName = ObjectTypeName();


	ss << "struct " << ClassTypeName()  << "{" << std::endl;

	ss << "\t" << this->MethodConstructor->GenPointer(ObjectName) << ";" <<std::endl;


	std::vector<std::string> method_names = GenMethodList();
	for(auto itr = method_names.begin(); itr != method_names.end(); itr++)
	{
		MethodClass *method = this->LookupMethod(*itr);

		ss << "\t" << method->GenPointer(ObjectName)<< ";" <<std::endl;

	}

	ss << "} ;" <<std::endl<<std::endl;


	ss << "struct " << ObjectName<< "{" << std::endl;

	ss << "\t" << ClassTypeName() << " *" << "_class_pointer" << ";" <<std::endl;

	std::vector<std::string> member_names = GenMemberList();

	for(auto itr = member_names.begin(); itr != member_names.end(); itr++)
	{
		std::string member = (*itr);
		std::string type = this->MemberVariables[member];

		ss << "\tObject_" << type << " *" << member << ";" <<std::endl;

	}

	ss << "} ;" <<std::endl<<std::endl;


}

std::string	ClassClass::ClassTypeName()
{
	return "Class_" + this->TypeName->Type;

}

std::string	ClassClass::ObjectTypeName()
{
	return "Object_" + this->TypeName->Type;

}


std::vector<std::string> ClassClass::GenMethodList()
{
	std::vector<std::string> returnValue;

	if((ParentClass != NULL) && (ParentClass != this))
	{
		returnValue = ParentClass->GenMethodList();
	}

	for(auto itr = Methods.begin(); itr != Methods.end(); itr++)
	{
		auto finder = std::find(returnValue.begin(),returnValue.end(),(*itr)->NameReturn->Name);

		if(finder == returnValue.end())
		{
			returnValue.push_back((*itr)->NameReturn->Name);
		}
	}

	return returnValue;
}

std::vector<std::string> ClassClass::GenMemberList()
{
	std::vector<std::string> returnValue;

	if((ParentClass != NULL) && (ParentClass != this))
	{
		returnValue = ParentClass->GenMemberList();
	}

	for(auto itr = MemberVariables.begin(); itr != MemberVariables.end(); itr++)
	{
		auto finder = std::find(returnValue.begin(),returnValue.end(),(*itr).first);

		if(finder == returnValue.end())
		{
			returnValue.push_back((*itr).first);
		}
	}
	return returnValue;
}


void ClassClass::Print()
{
	VAR_ADD();

	// print the
	FUNC_LOG("void ClassClass::Print()");
	
	VAR_LOG( "class " + TypeName->Type + " : "  + ParentName  );

	// Print out the constructor here.
	VAR_LOG("{");
	VAR_ADD();
	MethodConstructor->Print();
	VAR_SUB();
	VAR_LOG("}");
	// here print out the methods

	for(auto method = Methods.begin(); method != Methods.end(); method++)
	{ 
		if((*method)!=NULL)
		{
			(*method)->Print();
		}
	}

	VAR_LOG("Printing Symbol Table:");
	//this->ClassSymbolTable->print();
	//this->ConstructorSymbolTable->print();
	VAR_LOG("}");
	VAR_SUB();
}

