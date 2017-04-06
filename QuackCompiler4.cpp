//============================================================================
// Name        : QuackCompiler2.cpp
// Author      : Roscoe Casita and Connor George
// Version     :
// Copyright   : University of Oregon
// Description : Compiler for CIS 561. This build is with complete makefile.

//				This will be used to port the project over so we have support of an IDE.

//============================================================================
/**
 * Driver for parser with scanner.
 * Usage: ./parser foo.qk
 *
 * Output is mainly error messages.
 */
#include "CCodeGenerator.hpp"
#include "master_include.hpp"
#include "quack.tab.hpp"
#include "ProgramNode.hpp"
#include "QuackStatements.hpp"
#include "QuackExpressions.hpp"
#include "QuackDefines.hpp"
#include "CompilerDB.hpp"
#include "QuackProgramValidator.hpp"
#include "QuackBuiltIns.hpp"

extern int yyparse ();
extern int yydebug;

extern void yyrestart(FILE *f);

extern int yy_flex_debug;





int main(int argc, char **argv)
{
	FILE *f;
	int index;
	yydebug = 0;  // Set to 1 to trace parser
	yy_flex_debug = 0; // Set to 1 to see each rule matched in scanner

	bool function_logging = false;
	bool var_logging = false;
	bool print_dot = false;

	char c;
	while ((c = getopt(argc, argv, "fvtdsp")) != -1)
	{
		switch(c)
		{
		case 'f':
			function_logging = true;
			break;
		case 'v':
			var_logging = true;
			break;
		case 't':
			fprintf(stderr, "Debugging mode");
			yydebug = 1;
			break;
		case 'd':
			print_dot = true;
			break;
		case 's':
			show_semantic_tree = true;
			break;
		case 'p':
			show_program_tree = true;


		}
	}

	for (index = optind; index < argc; ++index)
	{
		SET_LOG_FUNC(function_logging);
		SET_ERROR_LOGGING(true);
		SET_VAR_LOGGING(var_logging);
		if( !(f = fopen(argv[index], "r")))
		{
			perror(argv[index]);
			exit(1);
		}
		yyrestart(f);
		VAR_LOG("Beginning parse of " + std::string(argv[index]));

		int condition = yyparse();


		VAR_LOG("Finished parse with result " + INT_STR(condition));
		if (condition != 0)
		{
			ERR_LOG("Failed to parse file correctly.");
			return condition;
		}

		CompilerDatabase *database= GetDB();



		VAR_LOG("Before Reducing DB.");
		database->DoReduce();
		VAR_LOG("After Reducing DB.");

		if(!Validation())
		{
			ERR_LOG("FAILED VALIDATION");
			PrintVisualization(argv[index],false);
			return -1;
		}
		else
		{
			VAR_LOG("Passed Validation.");
			VAR_LOG("Program passed validation\n");

			PrintVisualization(argv[index],print_dot);
			//	PrintVisualization(argv[index]);
		}

		CCodeGenerator *builder = new CCodeGenerator(GetCompleteProgram());



		std::string fullname = std::string(argv[index]);

		size_t lastindex = fullname.find_last_of(".");
		std::string rawname = fullname.substr(0, lastindex);



		std::string cpp_filename = rawname + ".c";

		builder->GenerateCFile(cpp_filename);


		VAR_LOG("Finished parse with result " + INT_STR(condition));

		VAR_LOG("Compiling CPP into binary:");
		std::string command = "gcc -g " + cpp_filename + " -o " + rawname;
		system(("echo " + command).c_str());
		system(command.c_str());

	}




}
