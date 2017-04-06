#ifndef __LLVMBUILTINS__
#define __LLVMBUILTINS__

#include "master_include.hpp"

#include "quack.tab.hpp"
#include "ProgramNode.hpp"
#include "QuackStatements.hpp"
#include "QuackExpressions.hpp"
#include "QuackDefines.hpp"
#include "CompilerDB.hpp"
#include "QuackProgramValidator.hpp"
#include "QuackBuiltIns.hpp"



class CCodeGenerator
{
public:
	CCodeGenerator(CompleteProgram *cp);
	~CCodeGenerator();

	void GenerateCFile(std::string file_name);

private:
	void BuildCFile();
	void GenerateHeader();
	void MakeTypeMap(std::vector<ClassClass *> FlattenedList);
	void BuildAllGlobals(std::vector<ClassClass *> FlattenedList);
	void BuildAllFunctions(std::vector<ClassClass *> FlattenedList);
	void BuildMainFunc(std::vector<ClassClass *> FlattenedList);

	std::stringstream file_stream;
	CompleteProgram *complete_program;

private:
	void PrintLine(std::string str);
};

#endif
