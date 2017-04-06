
#include "QuackExpressions.hpp"
#include "QuackProgramValidator.hpp"
#include "ProgramNode.hpp"



bool ValidateArgs(std::vector<std::string> arg_types, std::vector<NamedType *> arg_params)
{
	FUNC_LOG("bool ValidateArgs(std::vector<std::string> arg_types, std::vector<NamedType *> arg_params)");
	if(arg_types.size() != arg_params.size())
	{
		return false;
	}
	for(size_t i =0; i < arg_types.size(); i++)
	{
		std::string arg_type = arg_types[i];
		std::string param_type = arg_params[i]->Type;

		if(arg_type.compare(param_type)!=0)
		{
			return false;
		}
	}

	return true;
}


VariableIdentifier::VariableIdentifier(SyntaxNode *ptr, std::string name,std::string type) : LExpression(ptr),Name(name),Type(type)
{
	FUNC_LOG("VariableIdentifier::VariableIdentifier(SyntaxNode *ptr, std::string name,std::string type) : LExpression(ptr),Name(name),Type(type)");

}
VariableIdentifier::~VariableIdentifier()
{
}

std::string VariableIdentifier::GenCode(std::stringstream &ss, MethodClass* cur_method)
{
	FUNC_LOG("std::string VariableIdentifier::GenCode(std::stringstream &ss)");
	// Should be safe to do this because Name SHOULD be in mapped_names

	//ss << this->Name << " " << this->Type;

	std::string ret_reg;



	if(cur_method->quack_c_map.find(this->Name) == cur_method->quack_c_map.end())
	{
		ret_reg = AllocVar(this->ExpressionType,ss);
		if(this->Name.compare("this")==0)
		{
			if(cur_method->NameReturn->Name.compare(cur_method->NameReturn->Type)==0)
			{
				ss << "\t" << ret_reg << " =( (" << GetObjPtr(this->ExpressionType) << ")returnValue);" << std::endl;
			}
			else
			{
				ss << "\t" << ret_reg << " =( (" << GetObjPtr(this->ExpressionType) << ")_this_ptr);"  << std::endl;
			}

		}
		else
		{
			if(cur_method->NameReturn->Name.compare(cur_method->NameReturn->Type)==0)
			{
				ss << "\t" << ret_reg << " =( (" << GetObjPtr(this->ExpressionType) << ")returnValue)->" << this->Name <<";" << std::endl;
			}
			else
			{
				ss << "\t" << ret_reg << " =( (" << GetObjPtr(this->ExpressionType) << ")_this_ptr)->" << this->Name <<";" << std::endl;
			}
		}
	}
	else
	{

		ret_reg = AllocVarCast(this->ExpressionType,cur_method->quack_c_map[this->Name],ss);
		ss << "// Setting variable " << cur_method->quack_c_map[this->Name] << " to the new value" << std::endl;
		ss << "\t" << cur_method->quack_c_map[this->Name]  << " = " << ret_reg << ";" << std::endl;

	}
	return ret_reg;
}


std::string VariableIdentifier::Print()
{
	FUNC_LOG("std::string VariableIdentifier::Print()");
	return Name;
}

std::vector<GraphVizNodeDecorator *> VariableIdentifier::GenerateGraphvizChildren()
{
	FUNC_LOG("std::vector<GraphVizNodeDecorator *> VariableIdentifier::GenerateGraphvizChildren()");
	std::vector<GraphVizNodeDecorator *> returnValue;
	NodeLabel = EscapeString(Name) + " : " + EscapeString(Type);
	NodeShape = "box";

	return returnValue;
}

std::string VariableIdentifier::ExtractType(SymbolTable *SymTab)
{
	FUNC_LOG("std::string VariableIdentifier::ExtractType(SymbolTable *SymTab)");

	ExpressionType = SymTab->Lookup(Name);

	return ExpressionType;

	/*
	std::string new_type_name = QuackProgramValidator::LowestCommonAncestor(current_type_name,Type);

	if(new_type_name.compare(current_type_name)!=0)
	{
		SymTab->UpdateTable(Name,new_type_name);
	}
	else
	{
	}
	return new_type_name;
	*/
}











VariableLookup::VariableLookup(SyntaxNode *ptr, Expression *lookup, Expression *variable) : LExpression(ptr)
{
	FUNC_LOG("VariableLookup::VariableLookup(SyntaxNode *ptr, Expression *lookup, Expression *variable) : LExpression(ptr)");
	Lookup = dynamic_cast<RExpression *>(lookup);
	Variable= dynamic_cast<VariableIdentifier*>(variable);
}

VariableLookup::~VariableLookup()
{
}

std::string VariableLookup::GenCode(std::stringstream &ss, MethodClass* cur_method)
{
	FUNC_LOG("llvm::Value* VariableLookup::GenCode(std::stringstream &ss)");


	std::string var_reg = AllocVar(this->Variable->ExpressionType,ss);
	VariableIdentifier *vi =dynamic_cast<VariableIdentifier *>(this->Lookup);
	if((vi == NULL) || (vi->Name.compare("this")!=0))
	{
		std::string ret_reg = AllocVar(this->Lookup->ExpressionType,ss);
		std::string cur_reg = this->Lookup->GenCode(ss, cur_method);
		// might need to cast the type?
		ss << "\t" << ret_reg  << " = " << cur_reg << "; // Evaluated expression" << std::endl;

		ss << "\t" << var_reg << " = " << ret_reg << "->" << this->Variable->Name << ";" << std::endl;
	}
	else
	{
		ss << "\t" << var_reg << " = _this_ptr->" << this->Variable->Name << ";" << std::endl;

	}
	return var_reg;
}

std::string VariableLookup::ExtractType(SymbolTable *SymTab)
{
	FUNC_LOG("std::string VariableLookup::ExtractType(SymbolTable *SymTab)");
	std::string left = Lookup->ExtractType(SymTab);


	if(left.compare(TOP_STRING)==0)
	{
		ERR_LOG("Invalid Variable Lookup on left side of . :",this->NearestSyntax);
		ExpressionType = TOP_STRING;
		return ExpressionType;
	}
	if(0 != SymTab->ClassName.compare(left))
	{
		ERR_LOG("Invalid Member access of Class " + left + " on the left side of . :", this->NearestSyntax);
		ExpressionType = TOP_STRING;
		return ExpressionType;
	}

	std::string returnValue =  SymTab->Lookup(Variable->Name);



	if(0==returnValue.compare(TOP_STRING))
	{
		returnValue = SymTab->Lookup("this." + Variable->Name);
		if(0==returnValue.compare(TOP_STRING))
		{
			ERR_LOG("Member " + Variable->Name + " of Class " + left + " not found:", this->NearestSyntax);
		}
	}
	ExpressionType = returnValue;
	Variable->ExpressionType = ExpressionType;
	return returnValue;
}

std::string VariableLookup::Print()
{
	FUNC_LOG("std::string VariableLookup::Print()");
	std::stringstream ss;

	ss << "(";
	if(Lookup!=NULL)
	{
		ss << Lookup->Print();
	}
	else
	{
		ss << "BADLOOKUP in VariableLookup";
	}
	ss << ".";
	if(Variable != NULL)
	{
		ss << Variable->Print();
	}
	else
	{
		ss << "BADVARIABLE in VariableLookup";
	}
	ss << ") ";
	return ss.str();
}

std::vector<GraphVizNodeDecorator *> VariableLookup::GenerateGraphvizChildren()
{
	FUNC_LOG("std::vector<GraphVizNodeDecorator *> VariableLookup::GenerateGraphvizChildren()");
	std::vector<GraphVizNodeDecorator *> returnValue;

	NodeLabel = "Var Lookup";
	NodeShape = "box";

	if(Lookup!=NULL)
	{
		returnValue.push_back(Lookup);
	}
	if(Variable != NULL)
	{
		returnValue.push_back(Variable);
	}
	return returnValue;
}






TypedValue::TypedValue(SyntaxNode *ptr, std::string type, std::string value) : RExpression(ptr),Type(type),Value(value)
{
	FUNC_LOG("TypedValue::TypedValue(SyntaxNode *ptr, std::string type, std::string value) : RExpression(ptr),Type(type),Value(value)");
}

TypedValue::~TypedValue()
{
}

//// ALL DONE!
std::string TypedValue::GenCode(std::stringstream &ss, MethodClass* cur_method)
{
	FUNC_LOG("std::string TypedValue::GenCode(std::stringstream &ss)");
	std::string returnValue;
	ss << "// Generate Typed Value " << std::endl;
	if(this->Type == STRING_STRING)
	{
		returnValue = AllocVar(STRING_STRING,ss);
		ss << "\t" << returnValue << " = " << "(*GLOBAL_Class_Str.Class_Str_Method_Str)();" << std::endl;
		ss << "\t" << returnValue << "->_string_value = " << this->Value << ";" << std::endl;
	}
	else if(this->Type == NOTHING_STRING)
	{
		returnValue = AllocVar(NOTHING_STRING,ss);
		ss << "\t"  << returnValue << " = " << "(*GLOBAL_Class_Nothing.Class_Nothing_Method_Nothing)();" << std::endl;
	}
	else if(this->Type == INT_STRING)
	{
		returnValue = AllocVar(INT_STRING,ss);
		ss << "\t" << returnValue << " = " << "(*GLOBAL_Class_Int.Class_Int_Method_Int)();" << std::endl;
		ss << "\t" << returnValue << "->_int_value = " << this->Value << ";" << std::endl;
	}
	else if(this->Type == BOOL_STRING)
	{
		returnValue = AllocVar(BOOL_STRING,ss);
		ss << "\t" << returnValue << " = " << "(*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();" << std::endl;
		if(this->Value.compare("true")==0)
		{
			ss << "\t" << returnValue << "->_bool_value = 1;" << std::endl;
		}
		else
		{
			ss << "\t" << returnValue << "->_bool_value = 0;" << std::endl;
		}
	}


	return returnValue;
}


std::string TypedValue::Print()
{
	FUNC_LOG("std::string TypedValue::Print()");
	return Value ;
}

std::vector<GraphVizNodeDecorator *> TypedValue::GenerateGraphvizChildren()
{
	FUNC_LOG("std::vector<GraphVizNodeDecorator *> TypedValue::GenerateGraphvizChildren()");
	std::vector<GraphVizNodeDecorator *> returnValue;
	NodeShape = "box";
	NodeLabel = EscapeString(Type) + " : " + EscapeString(Value);
	return returnValue;
}

std::string TypedValue::ExtractType(SymbolTable *SymTab)
{
	FUNC_LOG("std::string TypedValue::ExtractType(SymbolTable *SymTab)");
	ExpressionType = Type;
	return Type;
}



FunctionCall::FunctionCall(SyntaxNode *ptr, Expression *call, std::vector<Expression*> args) : RExpression(ptr)
{
	FUNC_LOG("FunctionCall::FunctionCall(SyntaxNode *ptr, Expression *call, std::vector<Expression*> args) : RExpression(ptr)");
	Call = dynamic_cast<LExpression*>(call);
	Arguments = args;
	MethodCall = NULL;
	constructor_call = false;
}

FunctionCall::~FunctionCall()
{

}

std::string FunctionCall::GenCode(std::stringstream &ss, MethodClass* cur_method)
{
	FUNC_LOG("std::string FunctionCall::GenCode(std::stringstream &ss)");

	bool HasComma = false;

	std::stringstream call_string;

	VariableIdentifier *vi = dynamic_cast<VariableIdentifier*>(Call);
	VariableLookup *vl = dynamic_cast<VariableLookup*>(Call);

	std::vector<std::string> arg_vec;

	std::string type= MethodCall->NameReturn->Type;
	std::string method_name = this->MethodCall->GetMethodName();


	ss << "// Begin Method Call Generation ." << std::endl;

	int cur_arg_count = 0;

	if(vl != NULL)
	{
		std::string call_to_reg= AllocVar(vl->Lookup->ExpressionType,ss);


		std::string call_ret_reg = vl->Lookup->GenCode(ss, cur_method);

		ss << call_to_reg << " = " << call_ret_reg << "; // generate method left exp complete." << std::endl;


		std::string cast_reg = AllocVarCast(this->MethodCall->Parent->TypeName->Type,call_to_reg,ss );
		arg_vec.push_back(cast_reg);


		call_string << "(* " << cast_reg << "->_class_pointer->" << method_name << ")";

	}
	else
	{
		if(this->constructor_call)
		{
			call_string << "(*GLOBAL_Class_" << type << "." << method_name << ")";
		}
		else
		{
			call_string << "(*_this_ptr->_class_pointer->"  << method_name<< ")";

			std::string cast_reg= AllocVarCast(this->MethodCall->Parent->TypeName->Type,"_this_ptr",ss);
			arg_vec.push_back(cast_reg);
		}
	}
	for(auto itr = this->Arguments.begin(); itr != Arguments.end(); itr++)
	{
		std::string arg_reg = AllocVar((*itr)->ExpressionType,ss);

		std::string ret_reg = (*itr)->GenCode(ss, cur_method);
		ss << "\t" << arg_reg << " = " << ret_reg << "; // evaluated argument " << std::endl;

		std::string cast_type = this->MethodCall->Arguments[cur_arg_count]->Type;
		std::string cast_reg = AllocVarCast(cast_type,arg_reg,ss);
		arg_vec.push_back(cast_reg);
		cur_arg_count++;
	}
	std::string returnValue = AllocVar(type,ss);
	ss << "\t" << returnValue << " = " ;



	ss << call_string.str();
	ss << "(";
	for(auto itr = arg_vec.begin(); itr != arg_vec.end(); itr++)
	{
		if(HasComma)
		{
			ss << ",";
		}
		ss << (*itr);
		HasComma = true;
	}
	ss << ");" <<std::endl;
	return returnValue;
}

std::string FunctionCall::Print()
{
	FUNC_LOG("std::string FunctionCall::Print()");

	std::stringstream ss;

	ss << "[";
	if(Call != NULL)
	{
		ss << Call->Print();
	}
	else
	{
		ss << "BAD_CALL IN FUNC CALL";
	}

	ss << " ( " ;
	for( auto itr = Arguments.begin(); itr != Arguments.end(); itr++)
	{
		if((*itr) != NULL)
		{
			ss << (*itr)->Print() << ",";
		}
		else
		{
			ss << "BAD_ARG in FUNC CALL";
		}
	}
	ss << " ) ";
	ss << "]";

	return ss.str();
}

std::vector<GraphVizNodeDecorator *> FunctionCall::GenerateGraphvizChildren()
{
	FUNC_LOG("std::vector<GraphVizNodeDecorator *> FunctionCall::GenerateGraphvizChildren()");
	std::vector<GraphVizNodeDecorator *> returnValue;

	NodeShape = "box";
	NodeLabel = "Func Call";
	if(Call != NULL)
	{
		returnValue.push_back(Call);
	}

	for( auto itr = Arguments.begin(); itr != Arguments.end(); itr++)
	{
		if((*itr) != NULL)
		{
			returnValue.push_back(*itr);
		}
	}
	return returnValue;
}


std::string FunctionCall::ExtractType(SymbolTable *SymTab)
{
	FUNC_LOG("std::string FunctionCall::ExtractType(SymbolTable *SymTab)");
	VariableIdentifier *vi = dynamic_cast<VariableIdentifier*>(Call);
	VariableLookup *vl = dynamic_cast<VariableLookup*>(Call);
	std::string returnValue = TOP_STRING;

	std::vector<std::string> argTypes;
	std::vector<NamedType *> callArgs;
	for( auto itr = Arguments.begin(); itr != Arguments.end(); itr++)
	{
		std::string exp_type = (*itr)->ExtractType(SymTab);
		argTypes.push_back(exp_type);
	}



	CompleteProgram *cp =GetCompleteProgram();



	if(vi != NULL)
	{
		ClassClass *cc = cp->LookupClass(vi->Name);

		if(cc != NULL)
		{
			// Constructor detected. Variable name is a class constructor.
			// A();

			callArgs = cc->MethodConstructor->Arguments;
			this->MethodCall = cc ->MethodConstructor;
			constructor_call = true;
		}
		else
		{
			// Local Function call detected:   foo()

			MethodClass *mc = cp->LookupClassMethod(SymTab->ClassName,vi->Name);

			if(mc == NULL)
			{
				ERR_LOG("Invalid Local name lookup:" + vi->Name, this->NearestSyntax);
				ExpressionType = TOP_STRING;
				return TOP_STRING;
			}
			else
			{
				callArgs = mc->Arguments;
				this->MethodCall = mc;
			}
		}
	}
	else
	{
		// remote procedure call:
		// this.a.foo().bad()


		std::string lookup_type = vl->Lookup->ExtractType(SymTab);
		if(lookup_type.compare(TOP_STRING)==0)
		{
			ERR_LOG("Invalid expression on left side of . ",vl->NearestSyntax);
			ExpressionType = TOP_STRING;
			return TOP_STRING;
		}
		else
		{
			MethodClass *mc = cp->LookupClassMethod(lookup_type,vl->Variable->Name);

			if(mc == NULL)
			{
				ERR_LOG("Failed to find method " + vl->Variable->Name + " in class " + lookup_type, this->NearestSyntax);
				ExpressionType = TOP_STRING;
				return TOP_STRING;
			}
			else
			{
				callArgs = mc->Arguments;
				this->MethodCall = mc;
			}
		}
	}


	if(!ValidateArgs(argTypes,callArgs))
	{
		ERR_LOG("Invalid Arguments passed to funtion call:", this->NearestSyntax);
		ExpressionType = TOP_STRING;
		return TOP_STRING;

	}
	ExpressionType = this->MethodCall->NameReturn->Type;
	return this->MethodCall->NameReturn->Type;
}


Expression::Expression(SyntaxNode *ptr)
{
	NearestSyntax = ptr;
	ExpressionType = "";
}

RExpression::RExpression(SyntaxNode *ptr) : Expression(ptr)
{

}

LExpression::LExpression(SyntaxNode *ptr) : RExpression(ptr)
{

}


MathExpression::MathExpression(SyntaxNode *ptr, Expression *left, std::string operation, Expression *right) : RExpression(ptr),Operation(operation)
{
	FUNC_LOG("MathExpression::MathExpression(SyntaxNode *ptr, Expression *left, std::string operation, Expression *right) : RExpression(ptr),Operation(operation)");
	LeftSide = left;
	RightSide =right;
}

MathExpression::~MathExpression()
{
}

std::string MathExpression::GenCode(std::stringstream &ss, MethodClass* cur_method)
{
	FUNC_LOG("std::string MathExpression::GenCode(std::stringstream &ss)");

	std::string l_exp_reg = AllocVar(LeftSide->ExpressionType,ss);

	ss << "// Before Left Math Eval." << std::endl;
	std::string l_exp_ret_reg = LeftSide->GenCode(ss, cur_method);
	ss << "// After Left Math Eval." << std::endl;

	ss << "\t" << l_exp_reg << " = " << l_exp_ret_reg << "; // evaled left of expression." << std::endl;



	std::string r_exp_reg = AllocVar(RightSide->ExpressionType,ss);
	ss << "// Before Right Math Eval." << std::endl;

	std::string r_exp_ret_reg = RightSide->GenCode(ss, cur_method);
	ss << "// After Right  Math Eval." << std::endl;

	ss << "\t" << r_exp_reg << " = " << r_exp_ret_reg << "; // evaled right of expression." << std::endl;

	std::string ret_var = AllocVar(ExpressionType,ss);

	ss << "\t" << ret_var << " = (*"  << l_exp_reg << "->_class_pointer->Class_" << LeftSide->ExpressionType << "_Method_" << this->Operation << ")";


	ss << "(" << l_exp_reg << ", " << r_exp_reg << ");" << std::endl;


	return ret_var;
}

std::string MathExpression::Print()
{
	FUNC_LOG("std::string MathExpression::Print()");
	std::stringstream ss;
	ss << " (";
	if(LeftSide !=NULL)
	{
		ss << LeftSide->Print() ;
	}
	ss << " " << Operation << " " ;
	if(RightSide != NULL)
	{
		ss << RightSide->Print();
	}
	ss << ")";
	return ss.str();
}

std::vector<GraphVizNodeDecorator *> MathExpression::GenerateGraphvizChildren()
{
	FUNC_LOG("std::vector<GraphVizNodeDecorator *> MathExpression::GenerateGraphvizChildren()");
	std::vector<GraphVizNodeDecorator *> returnValue;
	NodeShape = "box";
	NodeLabel = Operation;
	if(LeftSide != NULL)
	{
		returnValue.push_back(LeftSide);
	}
	if(RightSide != NULL)
	{
		returnValue.push_back(RightSide);
	}
	return returnValue;
}

std::string MathExpression::ExtractType(SymbolTable *SymTab)
{
	FUNC_LOG("std::string MathExpression::ExtractType(SymbolTable *SymTab)");
	std::string left = LeftSide->ExtractType(SymTab);
	std::string right = RightSide ->ExtractType(SymTab);

	if(left.compare(TOP_STRING)==0)
	{
		ERR_LOG("Invalid Expression to the left of " + this->Operation , this->NearestSyntax);
		ExpressionType = TOP_STRING;
		return TOP_STRING;
	}
	if(right.compare(TOP_STRING)==0)
	{
		ERR_LOG("Invalid Expression to the right of " + this->Operation , this->NearestSyntax);
		ExpressionType = TOP_STRING;
		return TOP_STRING;
	}

	std::string new_type = GetLowestCommonAncestor(left,right);


	CompleteProgram *cp = GetCompleteProgram();

	MethodClass *mc = cp->LookupClassMethod(new_type,this->Operation);

	if(mc == NULL)
	{
		ERR_LOG("TYPE CHECK ERROR: " + this->Operation + " is not supported by "+ new_type,this->NearestSyntax);
		ExpressionType = TOP_STRING;
		return TOP_STRING;
	}
	ExpressionType = mc->NameReturn->Type;

	return ExpressionType ;
}



BoolExpression::BoolExpression(SyntaxNode *ptr, Expression *left, std::string operation,Expression *right) : RExpression(ptr),Operator(operation)
{
	FUNC_LOG("BoolExpression::BoolExpression(SyntaxNode *ptr, Expression *left, std::string operation,Expression *right) : RExpression(ptr),Operator(operation)");
	LeftSide = left;
	RightSide =right;
}

std::string BoolExpression::GenCode(std::stringstream &ss, MethodClass* cur_method)
{
	FUNC_LOG("llvm::Value* BoolExpression::GenCode(std::stringstream &ss)");


	ss << "// Start Boolean Expression emit." << std::endl;

	std::string ret_reg = AllocVar(ExpressionType,ss);

	std::string l_exp_reg = AllocVar(ExpressionType,ss);
	std::string r_exp_reg = AllocVar(ExpressionType,ss);

	std::string exit_label = AllocLabel();
	std::string middle_label = AllocLabel();

	ss << "\t{" << std::endl;

	if(this->Operator.compare("NOT") == 0)
	{
		ss << "// Emitting NOT operator." << std::endl;
		std::string r_expression = RightSide->GenCode(ss, cur_method);
		ss << "\t" << r_exp_reg << " = " << r_expression << " ; // right side NOT evaled." << std::endl;

		ss << "\t" << ret_reg << " = (*" << r_exp_reg << "->_class_pointer->Class_" << RightSide->ExpressionType << "_Method_" << this->Operator << ")";

		ss << "(" << r_exp_reg << ");" << std::endl;

		ss << "// End NOT operator." << std::endl;
		ss << "\tgoto " << exit_label << ";" << std::endl;

	}
	else if(this->Operator.compare("OR") == 0)
	{
		ss << "/// L EXPRESSION OR begin." << std::endl;
		std::string l_exp_ret_reg = LeftSide->GenCode(ss, cur_method);
		ss << "\t" << l_exp_reg << " = " << l_exp_ret_reg << "; // evaled left of OR expression." << std::endl;

		ss << "\t" << "if (1==" << l_exp_reg << "->_bool_value)" << std::endl;

		ss << "\t" << "{" << std::endl;
		ss << "\t\t" << ret_reg << " = " << l_exp_reg << ";" << std::endl;
		ss << "\t\t" << " goto " << exit_label << "; " << std::endl;
		ss << "\t" << "}" << std::endl;
		ss << "\t" << "else" << std::endl;
		ss << "\t" << "{" << std::endl;
		ss << "\t\t" << " goto " << middle_label << "; " << std::endl;
		ss << "\t" << "}" << std::endl;


		ss << "\t" << middle_label << ":;" << std::endl;

		ss << "/// R expression OR begin." << std::endl;
		ss << "\t{" << std::endl;
		std::string r_exp_ret_reg = RightSide->GenCode(ss, cur_method);
		ss << "\t\t" << ret_reg << " = " << r_exp_ret_reg << "; // evaled right of OR expression." << std::endl;
		ss << "\tgoto " << exit_label << ";" << std::endl;
		ss << "\t}" << std::endl;
		ss << "// end OR short circuit." << std::endl;
	}
	else if(this->Operator.compare("AND") == 0)
	{
		ss << "/// L EXPRESSION AND begin." << std::endl;
		std::string l_exp_ret_reg = LeftSide->GenCode(ss, cur_method);
		ss << "\t" << l_exp_reg << " = " << l_exp_ret_reg << "; // evaled left of AND expression." << std::endl;

		ss << "\t" << "if (0==" << l_exp_reg << "->_bool_value)" << std::endl;

		ss << "\t" << "{" << std::endl;
		ss << "\t\t" << ret_reg << " = " << l_exp_reg << ";" << std::endl;
		ss << "\t\t" << " goto " << exit_label << "; " << std::endl;
		ss << "\t" << "}" << std::endl;
		ss << "\t" << "else" << std::endl;
		ss << "\t" << "{" << std::endl;
		ss << "\t\t" << " goto " << middle_label << "; " << std::endl;
		ss << "\t" << "}" << std::endl;


		ss << "\t" << middle_label << ":;" << std::endl;

		ss << "/// R expression AND begin." << std::endl;
		ss << "\t{" << std::endl;
		std::string r_exp_ret_reg = RightSide->GenCode(ss, cur_method);
		ss << "\t\t" << ret_reg << " = " << r_exp_ret_reg << "; // evaled right of AND expression." << std::endl;
		ss << "\tgoto " << exit_label << ";" << std::endl;
		ss << "\t}" << std::endl;
		ss << "// end AND short circuit." << std::endl;	}
	else
	{
		throw  "/****  ERROR IN Gneeration.";

	}
	ss << "\t" << exit_label << ":;" << std::endl;
	ss << "\t}" << std::endl;

	return ret_reg;
}

std::string BoolExpression::Print()
{
	FUNC_LOG("std::string BoolExpression::Print()");
	std::stringstream ss;

	ss << "(";
	if(LeftSide != NULL)
	{
		ss << LeftSide->Print();
	}
	else
	{
		ss <<"BAD_LEFT_EXP in BoolExpression";
	}

	ss << " " << Operator << " ";

	if(RightSide != NULL)
	{
		ss << RightSide->Print();
	}
	else
	{
		ss <<"BAD_RIGHT_EXP in BoolExpression";
	}
	ss << ")";
	return ss.str();
}

std::vector<GraphVizNodeDecorator *> BoolExpression::GenerateGraphvizChildren()
{
	FUNC_LOG("std::vector<GraphVizNodeDecorator *> BoolExpression::GenerateGraphvizChildren()");

	std::vector<GraphVizNodeDecorator *> returnValue;

	NodeShape = "box";
	NodeLabel = Operator;
	if(LeftSide != NULL)
	{
		returnValue.push_back(LeftSide);
	}
	if(RightSide != NULL)
	{
		returnValue.push_back(RightSide);
	}
	return returnValue;
}


std::string BoolExpression::ExtractType(SymbolTable *SymTab)
{
	FUNC_LOG("std::string BoolExpression::ExtractType(SymbolTable *SymTab)");
	std::string new_type = TOP_STRING;

	if(LeftSide != NULL)
	{
		std::string left = LeftSide->ExtractType(SymTab);
		std::string right = RightSide ->ExtractType(SymTab);
		if(left.compare(TOP_STRING)==0)
		{
			ERR_LOG("Invalid Expression to the left of " + this->Operator , this->NearestSyntax);
			ExpressionType = TOP_STRING;
			return TOP_STRING;
		}
		if(right.compare(TOP_STRING)==0)
		{
			ERR_LOG("Invalid Expression to the right of " + this->Operator , this->NearestSyntax);
			ExpressionType = TOP_STRING;
			return TOP_STRING;
		}
		new_type = GetLowestCommonAncestor(left,right);
	}
	else
	{
		std::string right = RightSide ->ExtractType(SymTab);
		if(right.compare(TOP_STRING)==0)
		{
			ERR_LOG("Invalid Expression to the right of " + this->Operator , this->NearestSyntax);
			ExpressionType = TOP_STRING;
			return TOP_STRING;
		}
		new_type = right;
	}


	CompleteProgram *cp = GetCompleteProgram();

	MethodClass *mc = cp->LookupClassMethod(new_type,this->Operator);

	if(mc == NULL)
	{
		ERR_LOG("TYPE CHECK ERROR: " + this->Operator+ " is not supported by "+ new_type,this->NearestSyntax);
		ExpressionType = TOP_STRING;
		return TOP_STRING;
	}

	if(new_type.compare(BOOL_STRING) != 0)
	{
		ERR_LOG("TYPE CHECK ERROR: Both sides do not evaluate to BOOL types. The Operatior: " + this->Operator + " is not supported as a overloaded method type." + new_type,this->NearestSyntax);
		ExpressionType = TOP_STRING;
		return TOP_STRING;
	}
	ExpressionType = BOOL_STRING;
	return BOOL_STRING;
}



