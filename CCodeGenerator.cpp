
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <typeinfo>


#include "quack.tab.hpp"
#include "ProgramNode.hpp"
#include "QuackStatements.hpp"
#include "QuackExpressions.hpp"
#include "QuackDefines.hpp"
#include "CompilerDB.hpp"
#include "QuackProgramValidator.hpp"
#include "QuackBuiltIns.hpp"
#include "NativeObject.hpp"
#include "CCodeGenerator.hpp"





CCodeGenerator::CCodeGenerator(CompleteProgram *cp)
{
	complete_program = cp;
}
CCodeGenerator::~CCodeGenerator()
{

}


void CCodeGenerator::GenerateCFile(std::string file_name)
{
	FUNC_LOG("void CCodeGenerator::GenerateCFile(std::string )" + file_name);


	VAR_LOG("Calling build C BuildCFile()");
	BuildCFile();


	std::ofstream file(file_name);

	std::string reference = file_stream.str();
	file << reference;

	VAR_LOG(reference);

	file.close();
}



void CCodeGenerator::BuildCFile()
{
	FUNC_LOG("void CCodeGenerator::BuildCFile()");

	// Build the build in classes.
	// build all dynamic classes.
	// build main function.

	std::vector<ClassClass *> flat_list = GetFlattenIterativeList(this->complete_program);

	VAR_LOG("Generating Header");

	GenerateHeader();

	VAR_LOG("Making Type Maps.");
	MakeTypeMap(flat_list);

	VAR_LOG("Making all globals.");
	BuildAllGlobals(flat_list);

	VAR_LOG("Making all functions.");
	BuildAllFunctions(flat_list);

	VAR_LOG("Building Main Function.");
	BuildMainFunc(flat_list);

	VAR_LOG("Program Complete:");
	VAR_LOG(file_stream.str());

}

void CCodeGenerator::GenerateHeader()
{
	FUNC_LOG("void CCodeGenerator::GenerateHeader()");

	PrintLine("#include <stdio.h>");
	PrintLine("#include <string.h>");
	PrintLine("#include <stdlib.h>");
	PrintLine("#include <malloc.h>");
	PrintLine("");


}

void CCodeGenerator::PrintLine(std::string str)
{
	file_stream << str << std::endl;

}

/*
std::map<std::string,llvm::PointerType *> ClassTypeMap;
std::map<std::string,llvm::PointerType *> ObjectTypeMap;
std::map<std::string,llvm::StructType *> ClassStructMap;
std::map<std::string,llvm::StructType *> ObjectStructMap;
*/


void CCodeGenerator::MakeTypeMap(std::vector<ClassClass *> FlattenedList)
{
	FUNC_LOG("void CCodeGenerator::MakeTypeMap(std::vector<ClassClass *> FlattenedList)");


	for(auto itr = FlattenedList.begin(); itr != FlattenedList.end(); itr++)
	{
		file_stream << "typedef struct Class_" << (*itr)->TypeName->Type << " Class_"<< (*itr)->TypeName->Type << ";" << std::endl;
		file_stream << "typedef struct Object_" << (*itr)->TypeName->Type << " Object_"<< (*itr)->TypeName->Type << ";" << std::endl;
	}
	file_stream << std::endl;


	for(auto itr = FlattenedList.begin(); itr != FlattenedList.end(); itr++)
	{
		(*itr)->DefineType(this->file_stream);
	}

	/*
	 * this->complete_program->Main->GenerateLLVMFunction(module);
	 *
	 */
}


void CCodeGenerator::BuildAllGlobals(std::vector<ClassClass *> FlattenedList)
{

	for(auto itr = FlattenedList.begin(); itr != FlattenedList.end(); itr++)
	{
		file_stream << "\tClass_" << (*itr) ->TypeName ->Type << "\t" << GetGlobalClass((*itr) ->TypeName ->Type) << ";" << std::endl;
	}
	file_stream << std::endl<< std::endl;
}

void CCodeGenerator::BuildAllFunctions(std::vector<ClassClass *> FlattenedList)
{
	for(auto itr = FlattenedList.begin(); itr != FlattenedList.end(); itr++)
	{

		(*itr)->MethodConstructor->GenerateFunction(file_stream);
		file_stream << std::endl;

		for(auto method_itr = (*itr)->Methods.begin(); method_itr != (*itr)->Methods.end(); method_itr++)
		{

			(*method_itr)->GenerateFunction(file_stream);
			file_stream << std::endl;
		}
	}
	complete_program->Main->GenerateFunction(file_stream);
	file_stream << std::endl;
}


void CCodeGenerator::BuildMainFunc(std::vector<ClassClass *> FlattenedList)
{
	VAR_LOG("Adding main function to module...");


	PrintLine("int main(int argc, char * argv[])");
	PrintLine("{");

	// generate all the global function pointer table sets.


	for(auto itr = FlattenedList.begin(); itr != FlattenedList.end(); itr++)
	{
		ClassClass *cc = (*itr);

		std::string global_class_object = GetGlobalClass(cc->TypeName->Type);

		std::string member_method_name = cc->MethodConstructor->GetMethodName();

		file_stream << "\t" << global_class_object <<  "." << member_method_name  << "=" << member_method_name <<";" << std::endl;

		std::vector<std::string> methods =cc->GenMethodList();
		for(auto method = methods.begin(); method != methods.end(); method++)
		{
			MethodClass *method_ptr = cc->LookupMethod((*method));

			member_method_name = method_ptr->GetMethodName();

			file_stream << "\t" <<global_class_object <<  "." << member_method_name  << "=" << member_method_name <<";" << std::endl;

		}
	}


	PrintLine("\tclass_MAIN_method_MAIN();");
	PrintLine("\treturn 0;");
	PrintLine("}");

}






