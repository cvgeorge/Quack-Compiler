#ifndef __QUACKPROGRAMVALIDATOR__
#define __QUACKPROGRAMVALIDATOR__

//#include "master_include.hpp"
#include "CompilerDB.hpp"
#include "ProgramNode.hpp"
#include "QuackDefines.hpp"


class QuackProgramValidator{

public:
	std::map<std::string,std::string> ClassHeirarchy;
	std::map<std::string,std::vector<std::string>> ClassChildHeirarchy;

private:
	bool CheckInheritedMethods(MethodClass *superMethod, MethodClass *subMethod);
	std::vector<std::string> GetClassPath(std::string pathOf);


public:
		QuackProgramValidator();
		bool CheckClassHeirarchy(CompleteProgram *prog);
		bool ClassCheckHelper(std::string Subclass, std::vector<std::string> VisitedClasses);
		bool CheckClassMethods(ClassClass *MyClass);
		void BuildClassHeirarchy(CompleteProgram *program);
		bool TypeCheckDescendants(CompleteProgram* prog);
		
		std::string LowestCommonAncestor(std::string type1, std::string type2);
		


		bool ValidateClassPolymorphism(CompleteProgram *program);

		bool TypeCheckEverything(CompleteProgram* prog);




};

std::vector<ClassClass *> GetFlattenIterativeList(CompleteProgram* prog);

std::string GetLowestCommonAncestor(std::string left, std::string right);
CompleteProgram *GetCompleteProgram();
QuackProgramValidator *GetQuackProgramValidator ();
bool Validation();

#endif
