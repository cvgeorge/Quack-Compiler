#ifndef __QUACKBUILTINS__
#define __QUACKBUILTINS__

#include "master_include.hpp"
#include "quack.tab.hpp"
#include "ProgramNode.hpp"
#include "QuackStatements.hpp"
#include "QuackExpressions.hpp"
#include "QuackDefines.hpp"
#include "CompilerDB.hpp"
#include "QuackProgramValidator.hpp"

ReturnStatement *GenReturnThis();
ReturnStatement *GenEmptyStringReturn();
ReturnStatement *GenFalseValueReturn();
ReturnStatement *GenNothingValueReturn();
ReturnStatement *GenZeroValueReturn();
MethodClass* GenerateConstructor(std::string class_name);
MethodClass* GenerateDefaultMethod(std::string method_name, std::string parameter_type, std::string return_type, ReturnStatement *return_stmt);
ClassClass* GenerateObjectClass();
ClassClass* GenerateIntegerClass();
ClassClass* GenerateBooleanClass();
ClassClass* GenerateNothingClass();
ClassClass* GenerateStringClass();
void AddDefaultClassesToProgram();




#endif
