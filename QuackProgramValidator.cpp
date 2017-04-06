/*
 * QuackProgramValidator.cpp
 *
 *  Created on: Feb 21, 2017
 *      Author: rcasita
 */

#include "QuackProgramValidator.hpp"
#include "NativeObject.hpp"

/*
std::map<std::string,std::string> QuackProgramValidator::ClassHeirarchy;
std::map<std::string,std::vector<std::string>> QuackProgramValidator::ClassChildHeirarchy;
std::map<std::string, SymbolTable*> QuackProgramValidator::GlobalSymbolTable;
*/

QuackProgramValidator *Singleton = NULL;

QuackProgramValidator *GetQuackProgramValidator ()
{
	if(Singleton == NULL)
	{
		Singleton = new QuackProgramValidator ();
	}
	return Singleton;
}

std::string GetLowestCommonAncestor(std::string left, std::string right)
{
	/*
	 *
	 *
	if((left.compare(TOP_STRING)==0) || (right.compare(TOP_STRING)==0)
			return TOP_STRING;
	*/
	return GetQuackProgramValidator()->LowestCommonAncestor(left,right);
}

CompleteProgram *stash = NULL;
CompleteProgram *GetCompleteProgram()
{
	if(stash==NULL)
	{
		CompilerDatabase *database= GetDB();

		stash = new CompleteProgram(database->Root, database->FinalProgram, database->ProgramStatements);
	}
	return stash;
}
QuackProgramValidator::QuackProgramValidator()
{

}

bool Validation()
{
	FUNC_LOG("bool Validation()");

	CompleteProgram *program = GetCompleteProgram();

	//AddDefaultClassesToProgram();

	program->ClassDefines.push_back(new NativeObject());
	program->ClassDefines.push_back(new NativeInteger());
	program->ClassDefines.push_back(new NativeString());
	program->ClassDefines.push_back(new NativeNothing());
	program->ClassDefines.push_back(new NativeBoolean());


	QuackProgramValidator * ProgramValidator = GetQuackProgramValidator();

	ProgramValidator->BuildClassHeirarchy(program);

	//NOTE: This function call requires that the class heirarchy and child class heirarchy has already been built
	VAR_LOG("Validating Polymorphism...");
	if(ProgramValidator->ValidateClassPolymorphism(program))
	{
		VAR_LOG("Polymorphism validation complete!");
	}
	else
	{
		ERR_LOG("Error! Polymorphism validation failed!");
		return false;
	}


	if(!ProgramValidator->CheckClassHeirarchy(program))
	{
		ERR_LOG("Class heirarchy is NOT well formed");
		return false;
	}
	else
	{
		VAR_LOG("Class heirarchy is well formed!");
	}

	return ProgramValidator->TypeCheckEverything(program);
}

bool QuackProgramValidator::TypeCheckEverything(CompleteProgram* prog)
{
	FUNC_LOG("void QuackProgramValidator::TypeCheckEverything(CompleteProgram* prog)");
	std::vector<ClassClass*> classQueue = GetFlattenIterativeList(prog);


	while(!classQueue.empty())
	{
		ClassClass* currentClass = classQueue[0];
		classQueue.erase(classQueue.begin());

		SymbolTable *SymTab = new SymbolTable(currentClass->TypeName->Name);

		for(auto itr = prog->ClassDefines.begin();itr != prog->ClassDefines.end(); itr++)
		{
			SymTab->SymTable[(*itr)->TypeName ->Name] = (*itr)->TypeName ->Type;
		}


		if(currentClass->TypeCheck(SymTab)== false)
		{
			ERR_LOG("Failed to typecheck class: " + currentClass->TypeName->Name,currentClass->NearestSyntax);
			delete SymTab;
			return false;
		}
		delete SymTab;

	}
	MethodClass *main = new MethodClass(prog->Program->NearestSyntax);
	main->NameReturn = new NamedType(prog->Program->NearestSyntax,"MAIN",NOTHING_STRING);
	main->Statements = prog->Program;

	prog->Main = main;


	SymbolTable *SymTab = new SymbolTable("MAIN");

	bool done = false;
	while(!done)
	{
		main->UpdatedType = false;

		for(auto var =main->VariablesTypes.begin(); var != main->VariablesTypes.end(); var++)
		{
			SymTab->SymTable[(*var).first] = (*var).second;
		}


		if(main->TypeCheck(SymTab))
		{
			if(true ==main->UpdatedType)
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
			ERR_LOG("Failed to Type Check main: " , main->NearestSyntax);
			return false;
		}
	}
	return TypeCheckDescendants(prog);
}

std::vector<ClassClass *> GetFlattenIterativeList(CompleteProgram* prog)
{
	QuackProgramValidator *valid = GetQuackProgramValidator();


	std::vector<ClassClass*> classQueue;
	std::vector<ClassClass*> visited;

	ClassClass* currentClass = prog->LookupClass(OBJ_STRING);

	visited.push_back(currentClass);

	currentClass =prog->LookupClass(NOTHING_STRING);
	visited.push_back(currentClass);
	currentClass =prog->LookupClass(STRING_STRING);
	visited.push_back(currentClass);
	currentClass =prog->LookupClass(INT_STRING);
	visited.push_back(currentClass);
	currentClass =prog->LookupClass(BOOL_STRING);
	visited.push_back(currentClass);


	std::vector<std::string> children = valid->ClassChildHeirarchy[OBJ_STRING];

	for(auto child = children.begin(); child != children.end(); child++)
	{
		currentClass = prog->LookupClass(*child);
		auto finder = std::find(visited.begin(),visited.end(),currentClass);

		if(finder == visited.end())
		{
			classQueue.push_back(currentClass);
		}
	}

	while(!classQueue.empty())
	{
		currentClass = classQueue[0];
		visited.push_back(currentClass);
		classQueue.erase(classQueue.begin());

		std::vector<std::string> children = valid->ClassChildHeirarchy[currentClass->TypeName->Name];

		for(auto child = children.begin(); child != children.end(); child++)
		{
			currentClass = prog->LookupClass(*child);
			auto finder = std::find(visited.begin(),visited.end(),currentClass);

			if(finder == visited.end())
			{
				classQueue.push_back(currentClass);
			}
		}
	}
	return visited;
}


bool QuackProgramValidator::TypeCheckDescendants(CompleteProgram* prog)
{
	FUNC_LOG("void QuackProgramValidator::TypeCheckEverything(CompleteProgram* prog)");
	std::vector<ClassClass*> classQueue;

	classQueue.push_back(prog->LookupClass("Obj"));

	std::vector<std::string> visited;

	while(!classQueue.empty())
	{
		ClassClass* currentClass = classQueue[0];
		classQueue.erase(classQueue.begin());

		visited.push_back(currentClass->TypeName->Name);



		std::vector<std::string> children = ClassChildHeirarchy[currentClass->TypeName->Name];

		for(auto child = children.begin(); child != children.end(); child++)
		{
			auto finder = std::find(visited.begin(),visited.end(),(*child));
			if(finder == visited.end())
				classQueue.push_back(prog->LookupClass(*child));
			{
			}
		}

		//Check current class descendants
		for(auto child = children.begin(); child != children.end(); child++)
		{
			ClassClass* currentChild= prog->LookupClass(*child);

			for(auto member = currentClass->MemberVariables.begin(); member != currentClass->MemberVariables.end(); member++)
			{
				auto finder = currentChild->MemberVariables.find(member->first);

				if(finder == currentChild->MemberVariables.end())
				{
					ERR_LOG("Type error on " + member->first, currentClass->NearestSyntax);
					return false;
				}
				else
				{
					std::string new_type = ::GetLowestCommonAncestor(member->second,finder->second);
					if(new_type.compare(member->second)!=0)
					{
						ERR_LOG("Type error on " + member->first + " : " + member->second, currentClass->NearestSyntax);
						ERR_LOG("Type error on " + finder->first + " : " + finder->second, currentChild->NearestSyntax);
						return false;
					}
				}
			}

		}

	}
	return true;
}




bool QuackProgramValidator::ClassCheckHelper(std::string Subclass, std::vector<std::string> VisitedClasses)
{
	FUNC_LOG("bool QuackProgramValidator::ClassCheckHelper(std::string Subclass, std::vector<std::string> VisitedClasses)");
	if(Subclass == OBJ_STRING)
	{
		return true;
	}
	if(ClassHeirarchy[Subclass] == INT_STRING || ClassHeirarchy[Subclass] == BOOL_STRING || ClassHeirarchy[Subclass] == STRING_STRING || ClassHeirarchy[Subclass] == NOTHING_STRING)
	{
		ERR_LOG("Error! Class " + Subclass + " inherits from a built-in type");
		return false;
	}
	if ( ClassHeirarchy.find(ClassHeirarchy[Subclass]) == ClassHeirarchy.end() )
	{
		ERR_LOG("Error! Class " + Subclass + " inherits from a non-existent type");
	  	return false;
	}
	for(size_t i = 0; i < VisitedClasses.size(); i++)
	{
		if(Subclass == VisitedClasses[i])
		{
			ERR_LOG("Error! Inheritance cycle found on " + Subclass);
			return false;
		}
	}
	VisitedClasses.push_back(Subclass);
	return ClassCheckHelper(ClassHeirarchy[Subclass], VisitedClasses);
}

bool QuackProgramValidator::CheckClassMethods(ClassClass *MyClass)
{
	FUNC_LOG("bool QuackProgramValidator::CheckClassMethods(ClassClass *MyClass)");
	bool ReturnValue = true;
	for(size_t i = 0; i < MyClass->Methods.size(); i++)
	{
		if(MyClass->Methods[i]->NameReturn != NULL)
		{
			std::string MethodName = MyClass->Methods[i]->NameReturn->Name;

			for(size_t j = i + 1; j < MyClass->Methods.size(); j++)
			{
				if(MethodName == MyClass->Methods[j]->NameReturn->Name)
				{
					ERR_LOG("Error! Class " + MyClass->TypeName->Name + " contains multiple methods with the same name");
					ReturnValue = false;
				}
			}
		}

		for(size_t j = 0; j < MyClass->Methods[i]->Arguments.size(); j++)
		{

			// If the current method contains an argument with an undeclared type
			if(ClassHeirarchy.find(MyClass->Methods[i]->Arguments[j]->Type) == ClassHeirarchy.end())
			{
				ERR_LOG("Error! Method " + MyClass->Methods[i]->NameReturn->Name + " contains argument " + MyClass->Methods[i]->Arguments[j]->Name + " with invalid type " + MyClass->Methods[i]->Arguments[j]->Type);
				ReturnValue = false;
			}

			// Check for duplicate arguments in method
			for(size_t k = j + 1; k< MyClass->Methods[i]->Arguments.size(); k++)
			{
				if(MyClass->Methods[i]->Arguments[j]->Name == MyClass->Methods[i]->Arguments[k]->Name)
				{
					ERR_LOG("Error! Method " + MyClass->Methods[i]->NameReturn->Name + " contains duplicate argument " + MyClass->Methods[i]->Arguments[j]->Name);
					ReturnValue = false;
				}
			}
		}
	}
	return ReturnValue;
}

bool QuackProgramValidator::CheckInheritedMethods(MethodClass *superMethod, MethodClass *subMethod)
{
	//FUNC_LOG("QuackProgramValidator::CheckInheritedMethods Super Method:" + superMethod->NameReturn->Name + " Sub Method: " + subMethod->NameReturn->Name);


	if(superMethod->Arguments.size() != subMethod->Arguments.size())
	{
		ERR_LOG("Error! Different number of args in super and sub classes on method " + superMethod->NameReturn->Name);
		return false;
	}
	for(size_t i = 0; i < superMethod->Arguments.size(); i++)
	{
		if(superMethod->Arguments[i]->Name != subMethod->Arguments[i]->Name)
		{
			ERR_LOG("Error! Different argument name in super and sub classes on method " + superMethod->NameReturn->Name);
			return false;
		}

		// If the super method's ith argument is NOT a subtype of the sub method's ith argument
		std::string lca =LowestCommonAncestor(superMethod->Arguments[i]->Type, subMethod->Arguments[i]->Type);

		if (lca.compare(subMethod->Arguments[i]->Type) != 0)
		{
			ERR_LOG("Error! Different types on arguments name in super and sub classes on method " + superMethod->NameReturn->Name);
			return false;
		}
	}
	std::string super_return_type =superMethod->NameReturn->Type;
	std::string sub_return_type =subMethod->NameReturn->Type;

	FUNC_LOG("Comparing Super and Sub Method Return Types:" + super_return_type + " : " + sub_return_type);

	if (LowestCommonAncestor(super_return_type,sub_return_type).compare(super_return_type) != 0)
	{
		ERR_LOG("Error! Different return type in super and sub classes on method " + superMethod->NameReturn->Name);
		return false;
	}
	return true;

}


bool QuackProgramValidator::ValidateClassPolymorphism(CompleteProgram *program)
{
	FUNC_LOG("bool QuackProgramValidator::ValidateClassPolymorphism(CompleteProgram *program)");

	// For each class in the program...
	for(auto currentClass = program->ClassDefines.begin(); currentClass != program->ClassDefines.end(); currentClass++)
	{
		FUNC_LOG("Checking Class: " + (*currentClass)->TypeName->Name);
		// Get a list of the names of its children
		std::vector<std::string> childNames = ClassChildHeirarchy[(*currentClass)->TypeName->Name];

		// For each of those child names...
		for(size_t i = 0; i < childNames.size(); i++)
		{
			// Pick out the current child name
			std::string childName = childNames[i];

			// Get the classclass object that corresponds to the current child name
			ClassClass* childClass = program->LookupClass(childName);

			VAR_LOG("Checking Class: " + (*currentClass)->TypeName->Name + " subchild " + childName);
			// If that object is NULL, it means that there is an error somewhere.  This one should theoretically never happen
			if(childClass == NULL)
			{
				ERR_LOG("Error! Could not find class " + childName + " in program");
				return false;
			}

			// For each method in the current class AND in the current child class
			for(auto method = (*currentClass)->Methods.begin(); method != (*currentClass)->Methods.end(); method++)
			{
				std::string method_name = (*method)->NameReturn->Name;

				MethodClass *lookup = program->LookupClassMethod( childName,method_name);

				if(lookup != NULL)
				{
					// Check if the methods validate with each other
					bool MethodsValidate = CheckInheritedMethods( (*method) , lookup);

					// If the methods do not validate, we have an error
					if(!MethodsValidate)
					{
						ERR_LOG("Error! Method signature mismatch on method " + method_name + " between classes " + childName + " and " + (*currentClass)->TypeName->Name);
						return false;
					}
				}
			}
		}
	}
	// If we check all methods of all children of all classes and NONE of them cause an error, then the class methods validate and we return true
	return true;
}

void QuackProgramValidator::BuildClassHeirarchy(CompleteProgram *program)
{
	FUNC_LOG("void QuackProgramValidator::BuildClassHeirarchy(CompleteProgram *program)");


	for(auto itr = program->ClassDefines.begin(); itr != program->ClassDefines.end(); itr++)
	{
		VAR_LOG("Examining Class Ptr: " + HEX_STR(*itr));
		VAR_LOG("Class Name: " + (*itr)->TypeName->Name);

		// If the key to add is not in the map, add it
		if ( ClassHeirarchy.find((*itr)->TypeName->Name) == ClassHeirarchy.end() )
		{
			ClassHeirarchy[(*itr)->TypeName->Name] = (*itr)->ParentName;
		}
		// If the key is already in the map, we have two objects with the same name
		else
		{
			ERR_LOG("Error! Duplicate class name " + (*itr)->TypeName->Name + " is defined multiple times", (*itr)->TypeName->NearestSyntax);
		}
	}

	for(std::map<std::string,std::string>::const_iterator it = ClassHeirarchy.begin(); it != ClassHeirarchy.end(); it++)
	{
	    ClassChildHeirarchy[it->second].push_back(it->first);
	}

	for(auto itr = program->ClassDefines.begin(); itr != program->ClassDefines.end(); itr++)
	{

		(*itr)->ParentClass = GetCompleteProgram()->LookupClass((*itr)->ParentName);
	}
}

std::vector<std::string> QuackProgramValidator::GetClassPath(std::string pathOf)
{
	std::vector<std::string> returnValue;

	/*
	if(pathOf.compare(TOP_STRING))
	{
		returnValue.push_back(TOP_STRING);
		return returnValue;
	}
	*/

	returnValue.push_back(pathOf);

	while(pathOf.compare(OBJ_STRING)!=0)
	{
		if(ClassHeirarchy.find(pathOf) == ClassHeirarchy.end())
		{
			returnValue.push_back(TOP_STRING);
			return returnValue;
		}
		pathOf = ClassHeirarchy[pathOf];
		returnValue.push_back(pathOf);
	}
	return returnValue;
}

std::string QuackProgramValidator::LowestCommonAncestor(std::string type1, std::string type2)
{
	std::vector<std::string> path1 =GetClassPath(type1);
	std::vector<std::string> path2 =GetClassPath(type2);

	for(auto p1 = path1.begin(); p1 != path1.end(); p1++)
	{
		for(auto p2 = path2.begin(); p2 != path2.end(); p2++)
		{
			if( (*p1).compare(*p2)==0)
			{
				return *p1;
			}
		}
	}
	return TOP_STRING;
}


/*
 * Function Checks classes for well structured heirarchy, no duplicate method or class names, no inheritance from base
 */
bool QuackProgramValidator::CheckClassHeirarchy(CompleteProgram *program)
{
	FUNC_LOG("bool QuackProgramValidator::CheckClassHeirarchy(CompleteProgram *program)");
	bool ReturnVariable = true;

	for(auto itr = program->ClassDefines.begin(); itr != program->ClassDefines.end(); itr++)
		{
		// Check class methods
		if(! CheckClassMethods((*itr)))
		{
			ReturnVariable = false;
		}

	}
	for(auto itr = ClassHeirarchy.begin(); itr != ClassHeirarchy.end(); itr++)
	{
		std::vector<std::string> VisitedClasses;
		VisitedClasses.clear();
		if(!ClassCheckHelper(itr->first, VisitedClasses))
		{
			ReturnVariable = false;
		}
	}
	return ReturnVariable;
}































