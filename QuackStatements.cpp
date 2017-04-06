#include "ProgramNode.hpp"
#include "QuackStatements.hpp"

#include "CCodeGenerator.hpp"
#include "QuackProgramValidator.hpp"

ControlStatement::ControlStatement(SyntaxNode* ptr)
{
	FUNC_LOG("ControlStatement::ControlStatement(SyntaxNode* ptr)");
	NearestSyntax = ptr;
}

void ControlStatement::DoReduce(ControlStatement *&ptr)
{
	FUNC_LOG("void ControlStatement::DoReduce(ControlStatement *&ptr)");
	if(ptr != NULL)
	{
		ControlStatement *itr = ptr->Reduce();
		while(itr != ptr)
		{
			delete ptr;
			ptr = itr;
			itr = ptr->Reduce();
		}
	}
}


SequentialStatement::SequentialStatement(SyntaxNode* ptr) : ControlStatement(ptr)
{
	FUNC_LOG("SequentialStatement::SequentialStatement(SyntaxNode* ptr) : ControlStatement(ptr)");
}

SequentialStatement::~SequentialStatement()
{
}

void SequentialStatement::GenCode(std::stringstream &ss, MethodClass* cur_method)
{
	FUNC_LOG("void SequentialStatement::GenCode(std::stringstream &ss)");
	for(auto itr = Sequence.begin(); itr != Sequence.end(); itr++)
	{
		(*itr)->GenCode(ss, cur_method);
	}
}

bool SequentialStatement::TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod)
{
	FUNC_LOG("bool SequentialStatement::TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod)");
	for(size_t i = 0; i < Sequence.size(); i++)
	{
		if(!Sequence[i]->TypeCheck(SymTab, CurMethod))
		{
			return false;
		}
	}
	return true;
}


ControlStatementType SequentialStatement::GetStatementType()
{
	return SequentialStatementType;
}


ControlStatement *SequentialStatement::Reduce()
{
	FUNC_LOG("ControlStatement *SequentialStatement::Reduce()");
	ControlStatement *returnValue = this;
	if(Sequence.size() == 1)
	{
		returnValue = Sequence[0];
		Sequence.clear();
	}
	else
	{
		for(size_t i =0; i < Sequence.size(); i++)
		{
			ControlStatement *ptr = Sequence[i];
			DoReduce(ptr);
			Sequence[i] = ptr;
		}
	}
	return returnValue;
}

std::vector<GraphVizNodeDecorator *> SequentialStatement::GenerateGraphvizChildren()
{
	FUNC_LOG("std::vector<GraphVizNodeDecorator *> SequentialStatement::GenerateGraphvizChildren()");
	std::vector<GraphVizNodeDecorator *> returnValue;
	NodeShape = "box";
	NodeLabel ="Sequence";
	for(auto itr = Sequence.begin(); itr != Sequence.end(); itr++)
	{
		if((*itr)!=NULL)
		{
			returnValue.push_back(*itr);  //Segfault here
		}
	}

	return returnValue;
}


void SequentialStatement::Print()
{
	FUNC_LOG("void SequentialStatement::Print()");

	for(auto itr = Sequence.begin(); itr != Sequence.end(); itr++)
	{
		if((*itr)!=NULL)
		{
			(*itr)->Print();
		}
	}
}




IfElseListStatement::IfElseListStatement(SyntaxNode* ptr) : ControlStatement(ptr)
{
	FUNC_LOG("IfElseListStatement::IfElseListStatement(SyntaxNode* ptr) : ControlStatement(ptr)");
}

IfElseListStatement::~IfElseListStatement()
{
}

void IfElseListStatement::GenCode(std::stringstream &ss, MethodClass* cur_method)
{
	FUNC_LOG("void IfElseListStatement::GenCode(std::stringstream &ss)");

	ss << "// If Else List Begin. " << std::endl;
	std::string exit_label = AllocLabel();
	std::string code_label = AllocLabel();
	std::string cond_label = AllocLabel();


	for(auto itr = ConditionalList.begin(); itr != ConditionalList.end(); itr++)
	{

		//NOTE: Probably don't want to pass these 'block'.  Just sticking it in for now so it compiles
		ss << "// If test" << std::endl;
		ss << "\t" << cond_label << ":;" << std::endl;
		cond_label = AllocLabel();

		if((*itr).first!=NULL)
		{
			ss << "\t" << "{" << std::endl;
				std::string cond_reg = AllocVar((*itr).first->ExpressionType,ss);
				// Generate code for bool expression
				std::string test = (*itr).first->GenCode(ss, cur_method);

				ss << "\t\t" << cond_reg << " = " << test << ";" << std::endl;
				ss << "\t\t" << "if (1==" << cond_reg << "->_bool_value)" << std::endl;
				ss << "\t\t" << "{" << std::endl;
				ss << "\t\t\t" << " goto " << code_label << "; " << std::endl;
				ss << "\t\t" << "}" << std::endl;

				if(ConditionalList.size() > 1)
				{
					ss << "\t\t" << "else" << std::endl;
					ss << "\t\t" << "{" << std::endl;
					ss << "\t\t\t" << " goto " << cond_label << "; " << std::endl;
					ss << "\t\t" << "}" << std::endl;
				}
				else
				{
					ss << "\t\t" << "else" << std::endl;
					ss << "\t\t" << "{" << std::endl;
					ss << "\t\t\t" << " goto " << exit_label << "; " << std::endl;
					ss << "\t\t" << "}" << std::endl;
				}
			ss << "\t" << "}" << std::endl;
		}
		ss << "\t" << code_label << ":;" << std::endl;
		code_label = AllocLabel();
		// Generate code for corresponding statement
		ss << "// code block" << std::endl;;

		ss << "\t" << "{" << std::endl;

		(*itr).second->GenCode(ss, cur_method);

		ss << "\t" << "goto " << exit_label << ";" << std::endl;
		ss << "\t" << "}" << std::endl;

		ss << "// end code block" << std::endl;

	}
	ss << "\t" << exit_label << ":;" << std::endl;
	ss << "// If Else List end. " << std::endl;

}

bool IfElseListStatement::TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod)
{
	FUNC_LOG("bool IfElseListStatement::TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod)");

	std::vector<SymbolTable *> paths;

	for(size_t i = 0; i < ConditionalList.size(); i++)
	{
		// Check the condition as long as it isn't the last one and isn't null
		if(ConditionalList[i].first != NULL )
		{
			if(0!=ConditionalList[i].first->ExtractType(SymTab).compare( BOOL_STRING))
			{
				ERR_LOG("Error! If conditional should return a bool", NearestSyntax);
				return false;
			}
		}

		SymbolTable *temp = SymTab->Duplicate();
		paths.push_back(temp);

		if(!ConditionalList[i].second->TypeCheck(temp, CurMethod))
		{
			return false;
		}
	}
	std::vector<std::string> delete_list;
	for(auto sym = SymTab->SymTable.begin(); sym != SymTab->SymTable.end(); sym++)
	{
		std::string symbol_name = sym->first;
		delete_list.push_back(symbol_name);
	}

	for(auto outer = paths.begin(); outer != paths.end(); outer++)
	{
		SymbolTable *path = (*outer);
		for(auto inner = paths.begin(); inner != paths.end(); inner++)
		{

			for(auto match = (*outer)->SymTable.begin(); match != (*outer)->SymTable.end(); match++)
			{
				std::string sym_name = (*match).first;

				auto finder = (*inner)->SymTable.find(sym_name);

				if(finder == (*inner)->SymTable.end())
				{
					ERR_LOG("Not all return paths initialize variable: " + sym_name, this->NearestSyntax);
					return false;
				}
			}
		}
	}

	for(auto itr = paths[0]->SymTable.begin(); itr != paths[0]->SymTable.end(); itr++)
	{
		std::string name = itr->first;

		std::string type = itr->second;

		auto finder = SymTab->SymTable.find(name);

		if(finder == SymTab->SymTable.end())
		{
			SymTab->SymTable[name] = type;
			CurMethod->UpdatedType = true;
		}
	}
	/// validate that all symbol tables are the same size.
	return true;
}


ControlStatementType IfElseListStatement::GetStatementType()
{
	FUNC_LOG("ControlStatementType IfElseListStatement::GetStatementType()");
	return IfElseListStatementType;
}

void IfElseListStatement::Add(RExpression *cond, ControlStatement *stmt)
{
	FUNC_LOG("void IfElseListStatement::Add(RExpression *cond, ControlStatement *stmt)");
	ConditionalList.push_back( std::pair<RExpression *,ControlStatement *>(cond,stmt));
}

ControlStatement *IfElseListStatement::Reduce()
{
	FUNC_LOG("ControlStatement *IfElseListStatement::Reduce()");
	for(auto itr = ConditionalList.begin(); itr != ConditionalList.end(); itr++)
	{
		DoReduce(itr->second);
	}
	return this;
}

std::vector<GraphVizNodeDecorator *> IfElseListStatement::GenerateGraphvizChildren()
{
	FUNC_LOG("std::vector<GraphVizNodeDecorator *> IfElseListStatement::GenerateGraphvizChildren()");
	std::vector<GraphVizNodeDecorator *> returnValue;
	NodeShape = "box";
	NodeLabel ="IfElseList";


	for(auto itr = ConditionalList.begin(); itr != ConditionalList.end(); itr++)
	{
		if( itr->first!=NULL)
		{
			returnValue.push_back(itr->first);
		}
		if( itr->second!=NULL)
		{
			returnValue.push_back(itr->second);
		}
	}


	return returnValue;
}

void IfElseListStatement::Print()
{
	FUNC_LOG("void IfElseListStatement::Print()");

	std::stringstream ss;

	ss << " if ( " ;

	for(auto itr = ConditionalList.begin(); itr != ConditionalList.end(); itr++)
	{
		if( itr->first!=0)
		{
			ss << itr->first->Print();
			ss << ")";
			VAR_LOG(ss.str());
			ss.str(std::string());
			ss.clear();
			ss << " elif (";
		}
		else
		{
			VAR_LOG("else");
		}
		VAR_LOG("{");
		VAR_ADD();
		if( itr->second!=NULL)
		{
			itr->second->Print() ;
		}
		VAR_SUB();
		VAR_LOG("}");
	}
}

WhileStatement::WhileStatement(SyntaxNode* ptr, RExpression *rexp, ControlStatement *stmt) : ControlStatement(ptr)
{
	FUNC_LOG("");
	Condition =rexp;
	Statements = stmt;
}
WhileStatement::~WhileStatement()
{
}

void WhileStatement::GenCode(std::stringstream &ss, MethodClass* cur_method)
{
	FUNC_LOG("void WhileStatement::GenCode(std::stringstream &ss)");

	std::string loop_label = AllocLabel();
	std::string cond_label = AllocLabel();
	std::string exit_label = AllocLabel();

	ss << "//While loop start." << std::endl;

	std::string cond_reg = AllocVar(this->Condition->ExpressionType,ss);

	ss << "// Condition start" << std::endl;
	ss << "\t" << cond_label << ":;" << std::endl;
	ss << "\t" <<"{" << std::endl;

		std::string cond = this->Condition->GenCode(ss, cur_method);

		ss << "// Condition test" << std::endl;
		ss << "\t\t" << cond_reg << " = " << cond << " ; " << std::endl;
		ss << "\t" << "if (1==" << cond_reg << "->_bool_value)" << std::endl;

		ss << "\t" << "{" << std::endl;
		ss << "\t\t" << " goto " << loop_label << "; " << std::endl;
		ss << "\t" << "}" << std::endl;
		ss << "\t" << "else" << std::endl;
		ss << "\t" << "{" << std::endl;
		ss << "\t\t" << " goto " << exit_label << "; " << std::endl;
		ss << "\t" << "}" << std::endl;

	ss << "\t" << "}" << std::endl;



	ss << "// Loop start" << std::endl;
	ss << "\t" << loop_label << ":;" << std::endl;
	ss << "\t" <<"{" << std::endl;

			this->Statements->GenCode(ss, cur_method);
	ss << "\t" << "goto " << cond_label << "; "<<std::endl;

	ss << "\t" <<"}" << std::endl;
	ss << "// Loop exit" << std::endl;
	ss << "\t" << exit_label << ":;" << std::endl;

	// Do something similar for the loop block

}

bool WhileStatement::TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod)
{
	FUNC_LOG("bool WhileStatement::TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod)");

	std::string condition_type =  Condition->ExtractType(SymTab);
	if(condition_type.compare(BOOL_STRING)!=0)
	{
		ERR_LOG("Error! While conditional should return a bool ", NearestSyntax);
		return false;
	}

	if(!Statements->TypeCheck(SymTab, CurMethod))
	{
		return false;
	}
	return true;
}

ControlStatementType WhileStatement::GetStatementType()
{
	return WhileStatementType;
}

ControlStatement *WhileStatement::Reduce()
{
	FUNC_LOG("ControlStatement *WhileStatement::Reduce()");
	DoReduce(Statements);
	return this;
}

std::vector<GraphVizNodeDecorator *> WhileStatement::GenerateGraphvizChildren()
{
	FUNC_LOG("std::vector<GraphVizNodeDecorator *> WhileStatement::GenerateGraphvizChildren()");
	std::vector<GraphVizNodeDecorator *> returnValue;
	NodeShape = "box";
	NodeLabel ="While";
	if(Condition != NULL)
	{
		returnValue.push_back(Condition);
	}
	if(Statements != NULL)
	{
		returnValue.push_back(Statements);
	}
	return returnValue;
}

void WhileStatement::Print()
{
	FUNC_LOG("void WhileStatement::Print()");
	std::stringstream ss ;

	ss << " while ( ";
	if(Condition!=NULL)
	{
		ss << Condition->Print();
	}
	ss << ")";
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


ReturnStatement::ReturnStatement(SyntaxNode* ptr, RExpression *rexp) : ControlStatement(ptr)
{
	FUNC_LOG("ReturnStatement::ReturnStatement(SyntaxNode* ptr, RExpression *rexp) : ControlStatement(ptr)");
	ReturnValue = rexp;
}

ReturnStatement::~ReturnStatement()
{
}

void ReturnStatement::GenCode(std::stringstream &ss, MethodClass* cur_method)
{
	FUNC_LOG("void ReturnStatement::GenCode(std::stringstream &ss)");
	ss << "// Generate return statement." << std::endl;

	std::string ret_reg = AllocVar(cur_method->NameReturn->Type,ss);
	std::string ret_value = ReturnValue->GenCode(ss, cur_method);

	std::string ret_obj_ptr_type =  GetObjPtr(cur_method->NameReturn->Type);
	std::string global_class = ::GetGlobalClass(cur_method->NameReturn->Type);
	ss << "\t" << ret_reg << " = ((" << ret_obj_ptr_type << ")"<< ret_value << "); // return value ." << std::endl;
	ss << "\t" << ret_reg << "->_class_pointer= &" << global_class << ";" << std::endl;
	// might need to cast to return type here.

	ss << "\treturn " << ret_reg << ";" << std::endl;


}

bool ReturnStatement::TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod)
{
	FUNC_LOG("bool ReturnStatement::TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod, std::map<std::string,SymbolTable *> *GlobalSymTab)");
	std::string methodType = CurMethod->NameReturn->Type;

	std::string returnType = ReturnValue->ExtractType(SymTab);

	if( returnType.compare(TOP_STRING)==0)
	{
		ERR_LOG("Return Type invalid:", NearestSyntax);
		return false;
	}
	std::string lca_return_type = GetLowestCommonAncestor(returnType,methodType );

	if(lca_return_type.compare(methodType))
	{
		ERR_LOG("Error! Return type mismatch: " + lca_return_type + " : Method return Type: " + methodType , NearestSyntax);
		return false;
	}
	return true;
}


ControlStatementType ReturnStatement::GetStatementType()
{
	return ReturnStatementType;
}

std::vector<GraphVizNodeDecorator *> ReturnStatement::GenerateGraphvizChildren()
{
	FUNC_LOG("std::vector<GraphVizNodeDecorator *> ReturnStatement::GenerateGraphvizChildren()");
	std::vector<GraphVizNodeDecorator *> returnValue;
	NodeShape = "box";
	NodeLabel ="Return";
	if(ReturnValue != NULL)
	{
		returnValue.push_back(ReturnValue);
	}
	return returnValue;
}

void ReturnStatement::Print()
{
	FUNC_LOG("void ReturnStatement::Print()");
	VAR_ADD();
	std::stringstream ss ;
	ss << "return ";
	if(ReturnValue!=NULL)
	{
		ss << ReturnValue->Print();
	}
	ss << ";";
	VAR_LOG(ss.str());
	VAR_SUB();
}

AssignmentStatement:: AssignmentStatement(SyntaxNode* ptr, LExpression *lexp, RExpression *rexp) : ControlStatement(ptr)
{
	FUNC_LOG("AssignmentStatement:: AssignmentStatement(SyntaxNode* ptr, LExpression *lexp, RExpression *rexp) : ControlStatement(ptr)");
	Address = lexp;
	Statement = rexp;
}

AssignmentStatement::~AssignmentStatement()
{
}

void AssignmentStatement::GenCode(std::stringstream &ss, MethodClass* cur_method)
{
	FUNC_LOG("void AssignmentStatement::GenCode(std::stringstream &ss)");
	// Generate code for assignment location
	std::string val_reg = AllocVar(Statement->ExpressionType,ss);

	ss << "// Begin Assignment Gen Value side. " << std::endl;
	// Generate code for assignment value
	// Note - 'Statement' is actually an rexpression.  Maybe rename?
	std::string statement_val = Statement->GenCode(ss, cur_method);

	ss << "\t" << val_reg << " = " << statement_val<< " ; // Assignment value, evaled." << std::endl;



	VariableLookup *vl = dynamic_cast<VariableLookup *>(this->Address);
	VariableIdentifier *vi = dynamic_cast<VariableIdentifier *>(this->Address);

//	std::string var_class_ptr = GetClassPtr(this->Address->ExpressionType);

	if(vi != NULL)
	{
		ss << "// emit a store instruction into a local 'variable' " << std::endl;
		std::string new_value_reg = AllocVarCast(Address->ExpressionType,val_reg,ss);

		ss << "\t" << " // Assigning var " << vi->Name << " to " << new_value_reg << std::endl;

		ss << "\t" << cur_method->quack_c_map[vi->Name] << " = " << new_value_reg << ";" << std::endl;
	}
	else if(vl != NULL)
	{
		VariableIdentifier *lexp = dynamic_cast<VariableIdentifier *>(vl->Lookup);
		if((lexp == NULL) || (lexp->Name.compare("this") !=0))
		{
			ss << "// emit a store instruction into a different object variable " << std::endl;
			std::string remote_ptr_reg = AllocVar(vl->Lookup->ExpressionType,ss);
			std::string resolve_ptr = vl->GenCode(ss,cur_method);

			ss << "\t" << remote_ptr_reg << " = "  << resolve_ptr << " ; " << std::endl;

			ss << "\t" << remote_ptr_reg << "->" << vl->Variable->Name << " = " << val_reg << ";" << std::endl;
		//std::string resolve_l_exp = vl->Lookup->GenCode(ss,cur_method);
		}
		else
		{
			ss << "// Emit a Store Instruction into the this pointer." << std::endl;


			if(cur_method->NameReturn->Name.compare(cur_method->NameReturn->Type) ==0)
			{
				ss << "\t" << "returnValue->" << vl->Variable->Name << " = " << val_reg <<"; //store into this." << std::endl;
			}
			else
			{
				ss << "\t" << "_this_ptr->" << vl->Variable->Name << " = " << val_reg <<"; //store into this." << std::endl;
			}
		}
	}
	else
	{
		throw "Invalide if-else block in assignment statement.";
	}

	ss << "// End Assignment Statment" << std::endl;

}


bool AssignmentStatement::TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod)
{
	FUNC_LOG("bool AssignmentStatement::TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod, std::map<std::string,SymbolTable *> *GlobalSymTab)");

	std::string right_type = Statement->ExtractType(SymTab);

	if(right_type.compare(TOP_STRING)==0)
	{
		ERR_LOG("Invalid Right Side of statement:",NearestSyntax);
		return false;
	}



	VariableIdentifier *vi = dynamic_cast<VariableIdentifier*>(Address);
	VariableLookup *vl = dynamic_cast<VariableLookup *>(Address);

	std::string str_type = TOP_STRING;
	std::string var_name;

	if(vl != NULL)
	{

		std::string ltype = vl->Lookup->ExtractType(SymTab);

		if(0 != SymTab->ClassName.compare(ltype))
		{
			ERR_LOG("Assignment to variable " + vl->Variable->Name + " in another class: " + ltype);
			return false;
		}
		var_name = "this." + vl->Variable->Name;
		vl->Variable->ExpressionType = ltype;
		vl->ExpressionType = ltype;
	}
	else
	{
		var_name = vi->Name;
	}

	std::string current_type = SymTab->Lookup(var_name);

	Address->ExpressionType =current_type;

	if(current_type.compare(TOP_STRING)==0)
	{
		SymTab->SymTable[var_name] = right_type;
		CurMethod->VariablesTypes[var_name] = right_type;
		CurMethod->UpdatedType = true;
	}
	else
	{

		std::string new_type = GetLowestCommonAncestor(current_type,right_type);

		if(0!=new_type.compare(current_type))
		{
			SymTab->SymTable[var_name] = new_type ;
			CurMethod->VariablesTypes[var_name] = new_type ;
			CurMethod->UpdatedType = true;
		}
		current_type = new_type;
	}
	Address->ExpressionType = current_type;
	return true;
}

std::vector<GraphVizNodeDecorator *> AssignmentStatement::GenerateGraphvizChildren()
{
	FUNC_LOG("std::vector<GraphVizNodeDecorator *> AssignmentStatement::GenerateGraphvizChildren()");
	NodeShape = "box";
	NodeLabel ="Assignment";

	std::vector<GraphVizNodeDecorator *> returnValue;
	if(Address!=NULL)
	{
		returnValue.push_back(Address);
	}
	if(Statement!=NULL)
	{
		returnValue.push_back(Statement);
	}
	return returnValue;
}

ControlStatementType AssignmentStatement::GetStatementType()
{
	return AssignmentStatementType;
}

void AssignmentStatement::Print()
{
	FUNC_LOG("void AssignmentStatement::Print()");

	std::stringstream ss ;
	if(Address!=NULL)
	{
		ss << Address->Print();
	}
	 ss << " = " ;
	if(Statement!=NULL)
	{
		ss << Statement->Print();
	}
	ss << ";";
	VAR_LOG(ss.str());
}

SingleStatement::SingleStatement(SyntaxNode* ptr, RExpression *stmt) : ControlStatement(ptr)
{
	FUNC_LOG("SingleStatement::SingleStatement(SyntaxNode* ptr, RExpression *stmt) : ControlStatement(ptr)");
	Statement = stmt;
}

SingleStatement::~SingleStatement()
{
}

void SingleStatement::GenCode(std::stringstream &ss, MethodClass* cur_method)
{
	FUNC_LOG("void SingleStatement::GenCode(std::stringstream &ss)");
	// Note - 'Statement' is actually an rexpression.  Maybe rename?

	this->Statement->GenCode(ss, cur_method);

}

bool SingleStatement::TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod)
{
	FUNC_LOG("bool SingleStatement::TypeCheck(SymbolTable *SymTab, MethodClass *CurMethod)");

	if(Statement->ExtractType(SymTab) != TOP_STRING)
	{
		return true;
	}
	ERR_LOG("Error! Invalid identifier ", NearestSyntax);
	return false;
}

std::vector<GraphVizNodeDecorator *> SingleStatement::GenerateGraphvizChildren()
{
	FUNC_LOG("std::vector<GraphVizNodeDecorator *> SingleStatement::GenerateGraphvizChildren()");
	std::vector<GraphVizNodeDecorator *> returnValue;

	NodeShape = "box";
	NodeLabel ="Single";
	returnValue.push_back(Statement);

	return returnValue;
}

ControlStatementType SingleStatement::GetStatementType()
{
	return SingleStatementType;
}


void SingleStatement::Print()
{
	FUNC_LOG("void SingleStatement::Print()");


	//VAR_LOG("SingleStatement : RExp " + HEX_STR(Statement));
	std::stringstream ss ;

	if(Statement!=NULL)
	{
		ss << Statement->Print();
	}
	ss << " ;";
	VAR_LOG(ss.str());
}
