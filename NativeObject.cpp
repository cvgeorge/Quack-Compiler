#include "NativeObject.hpp"

#include "CCodeGenerator.hpp"

NativeMethod::NativeMethod(std::string function_name, std::string return_value) : MethodClass(new SyntaxNode(function_name,IDENTIFIER,-999 ))
{
	NameReturn = new NamedType(NearestSyntax,function_name,return_value);
	Statements = GenReturnThis();
}

NativeMethod::NativeMethod(std::string function_name, std::string return_value,std::string param_type, std::string param_name): MethodClass(new SyntaxNode(function_name,IDENTIFIER,-999 ))
{
	NameReturn = new NamedType(NearestSyntax,function_name,return_value);
	NamedType *arg = new NamedType(NearestSyntax,param_name,param_type);

	Arguments.push_back(arg);
	Statements = GenReturnThis();
}

NativeMethod::~NativeMethod()
{

}




class NativeObjectConstructor : public NativeMethod{
public:
	NativeObjectConstructor() : NativeMethod(OBJ_STRING, OBJ_STRING)
	{
		Statements = GenReturnThis();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss <<"\t"<< this->Parent->ObjectTypeName() << " * returnValue = (" + this->Parent->ObjectTypeName() + "*)malloc(sizeof(" + this->Parent->ObjectTypeName() + "));" << std::endl;
		//ss <<"\t" << this->Parent->ObjectTypeName() << " * returnValue = new " + this->Parent->ObjectTypeName() + "();" << std::endl;

		ss <<"\t"<< "returnValue->_class_pointer = &GLOBAL_" +  this->Parent->ClassTypeName() << ";" << std::endl;
		ss <<"\t"<< "return returnValue;" << std::endl;
	}
};

class NativeObjectSTR : public NativeMethod{
public:
	NativeObjectSTR() : NativeMethod("STR", STRING_STRING)
	{
		Statements =  GenEmptyStringReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Str* returnValue = (*GLOBAL_Class_Str.Class_Str_Method_Str)();" << std::endl;
		ss << "\t" << "const void * address = (const void*)(_this_ptr);" << std::endl;
		//ss << "\t" << "unsigned int add_hex = (unsigned int)address;" << std::endl;
		ss << "\t" << "size_t needed = snprintf(NULL, 0, \"Native Object Pointer Address: %p \\n\", address ) + 1;" << std::endl;
		ss << "\t" << "char  *buffer = (char *)malloc(needed);" << std::endl;
		ss << "\t" << "snprintf(buffer, needed, \"Native Object Pointer Address: %p \\n\", address) ;" << std::endl;
		ss << "\t" << "returnValue->_string_value = buffer; " << std::endl;

		ss << "\t" << "return returnValue;" << std::endl;
	}
};

class NativeObjectPRINT : public NativeMethod{
public:
	NativeObjectPRINT() : NativeMethod("PRINT", NOTHING_STRING)
	{
		Statements =  GenNothingValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t" << "Object_Str* print = (*_this_ptr->_class_pointer->Class_Obj_Method_STR)(_this_ptr);" << std::endl;

		ss << "\t" << "printf(\"%s\\n\",print->_string_value);" << std::endl;
		//ss << "\t" << "std::cout << print->_string_value << std::endl;" << std::endl;
		ss << "\t"<< "Object_Nothing* returnValue = (*GLOBAL_Class_Nothing.Class_Nothing_Method_Nothing)();" << std::endl;
		ss << "\t" << "return returnValue;" << std::endl;
	}
};


NativeObject::NativeObject() : ClassClass(new SyntaxNode(OBJ_STRING,CLASS,-999))
{
	FUNC_LOG("NativeObject::NativeObject() : ClassClass(new SyntaxNode(OBJ_STRING,CLASS,-999))");


	MethodConstructor = new NativeObjectConstructor();
	Methods.push_back(new NativeObjectSTR());
	Methods.push_back(new NativeObjectPRINT());

	ParentName = OBJ_STRING;
	TypeName = new NamedType(this->NearestSyntax, OBJ_STRING, OBJ_STRING);
	Reduce();
}

NativeObject::~NativeObject(){

}

class NativeIntegerConstructor : public NativeMethod{
public:
	NativeIntegerConstructor() : NativeMethod(INT_STRING, INT_STRING)
	{
		Statements = GenReturnThis();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss <<"\t" << this->Parent->ObjectTypeName() << " * returnValue = (" + this->Parent->ObjectTypeName() + "*)malloc(sizeof(" + this->Parent->ObjectTypeName() + "));" << std::endl;
		//		ss <<"\t" << this->Parent->ObjectTypeName() << " * returnValue = new " + this->Parent->ObjectTypeName() + "();" << std::endl;
		ss <<"\t" << "returnValue->_class_pointer = &GLOBAL_" +  this->Parent->ClassTypeName() << ";" << std::endl;
		ss <<"\t" << "returnValue->_int_value = 0;" << std::endl;
		ss <<"\t" << "return returnValue;" << std::endl;
	}

};

class NativeIntegerPLUS : public NativeMethod{
public:
	NativeIntegerPLUS() : NativeMethod("PLUS", INT_STRING,INT_STRING, "_other_int")
	{
		Statements = GenZeroValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Int* returnValue = (*GLOBAL_Class_Int.Class_Int_Method_Int)();" << std::endl;
		ss << "\t" << "returnValue->_int_value = (_this_ptr->_int_value + _other_int->_int_value);" << std::endl;
		ss << "\t" << "return returnValue;" << std::endl;

	}

};

class NativeIntegerMINUS : public NativeMethod{
public:
	NativeIntegerMINUS() : NativeMethod("MINUS", INT_STRING,INT_STRING, "_other_int")
	{
		Statements = GenZeroValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Int* returnValue = (*GLOBAL_Class_Int.Class_Int_Method_Int)();" << std::endl;
		ss << "\t" << "returnValue->_int_value = (_this_ptr->_int_value - _other_int->_int_value);" << std::endl;
		ss << "\t" << "return returnValue;" << std::endl;
	}

};

class NativeIntegerTIMES : public NativeMethod{
public:
	NativeIntegerTIMES() : NativeMethod("TIMES", INT_STRING,INT_STRING, "_other_int")
	{
		Statements = GenZeroValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Int* returnValue = (*GLOBAL_Class_Int.Class_Int_Method_Int)();" << std::endl;
		ss << "\t" << "returnValue->_int_value = (_this_ptr->_int_value * _other_int->_int_value);" << std::endl;
		ss << "\t" << "return returnValue;" << std::endl;
	}

};

class NativeIntegerDIVIDE : public NativeMethod{
public:
	NativeIntegerDIVIDE() : NativeMethod("DIVIDE", INT_STRING,INT_STRING, "_other_int")
	{
		Statements = GenZeroValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Int* returnValue = (*GLOBAL_Class_Int.Class_Int_Method_Int)();" << std::endl;
		ss << "\t" << "returnValue->_int_value = (_this_ptr->_int_value / _other_int->_int_value);" << std::endl;
		ss << "\t" << "return returnValue;" << std::endl;
	}

};



class NativeIntegerATMOST : public NativeMethod{
public:
	NativeIntegerATMOST() : NativeMethod("ATMOST", BOOL_STRING,INT_STRING, "_other_int")
	{
		Statements = GenFalseValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();" << std::endl;
		ss << "\t" << "returnValue->_bool_value = (_this_ptr->_int_value <= _other_int->_int_value);" << std::endl;
		ss << "\t" << "return returnValue;" << std::endl;
	}

};

class NativeIntegerATLEAST : public NativeMethod{
public:
	NativeIntegerATLEAST() : NativeMethod("ATLEAST", BOOL_STRING,INT_STRING, "_other_int")
	{
		Statements = GenFalseValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();" << std::endl;
		ss << "\t" << "returnValue->_bool_value = (_this_ptr->_int_value >= _other_int->_int_value);" << std::endl;
		ss << "\t" << "return returnValue;" << std::endl;
	}

};

class NativeIntegerLESS : public NativeMethod{
public:
	NativeIntegerLESS() : NativeMethod("LESS", BOOL_STRING,INT_STRING, "_other_int")
	{
		Statements = GenFalseValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();" << std::endl;
		ss << "\t" << "returnValue->_bool_value = (_this_ptr->_int_value < _other_int->_int_value);" << std::endl;
		ss << "\t" << "return returnValue;" << std::endl;
	}

};

class NativeIntegerMORE : public NativeMethod{
public:
	NativeIntegerMORE() : NativeMethod("MORE", BOOL_STRING,INT_STRING, "_other_int")
	{
		Statements = GenFalseValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();" << std::endl;
		ss << "\t" << "returnValue->_bool_value = (_this_ptr->_int_value > _other_int->_int_value);" << std::endl;
		ss << "\t" << "return returnValue;" << std::endl;
	}

};

class NativeIntegerEQUALS : public NativeMethod{
public:
	NativeIntegerEQUALS() : NativeMethod("EQUALS", BOOL_STRING,INT_STRING, "_other_int")
	{
		Statements = GenFalseValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();" << std::endl;
		ss << "\t" << "returnValue->_bool_value = (_this_ptr->_int_value == _other_int->_int_value);" << std::endl;
		ss << "\t" << "return returnValue;" << std::endl;
	}

};
class NativeIntegerREAD : public NativeMethod{
public:
	NativeIntegerREAD() : NativeMethod("READ",INT_STRING)
	{
		Statements = GenZeroValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t" << "char buffer =0;" << std::endl;
		ss << "\t" << "scanf(\"%d%c\",&_this_ptr->_int_value,&buffer);" << std::endl;
		ss << "\t" << "return _this_ptr;" << std::endl;
	}

};



class NativeIntegerSTR : public NativeMethod{
public:
	NativeIntegerSTR() : NativeMethod("STR",STRING_STRING)
	{
		Statements = ::GenEmptyStringReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Str* returnValue = (*GLOBAL_Class_Str.Class_Str_Method_Str)();" << std::endl;

		ss << "\t" << "size_t needed = snprintf(NULL, 0, \"%d\", _this_ptr->_int_value) + 1;" << std::endl;
		ss << "\t" << "char  *buffer = (char *)malloc(needed);" << std::endl;
		ss << "\t" << "snprintf(buffer, needed, \"%d\", _this_ptr->_int_value) + 1;" << std::endl;
		ss << "\t" << "returnValue->_string_value = buffer; " << std::endl;


/*		ss << "\t" << "std::stringstream str_stream;" << std::endl;
		ss << "\t" << "str_stream << _this_ptr->_int_value;" << std::endl;
		ss << "\t" << "returnValue->_string_value = str_stream.str(); " << std::endl;
*/
		ss << "\t" << "return returnValue;" << std::endl;
	}

};


NativeInteger::NativeInteger() : ClassClass(new SyntaxNode(INT_STRING,CLASS,-999))
{
	FUNC_LOG("NativeInteger::NativeInteger() : ClassClass(new SyntaxNode(INT_STRING,CLASS,-999))");

	MethodConstructor = new NativeIntegerConstructor;

	//Methods.push_back(GenerateDefaultMethod("PLUS", INT_STRING, INT_STRING, GenZeroValueReturn()));
	Methods.push_back(new NativeIntegerPLUS());
	Methods.push_back(new NativeIntegerMINUS());
	Methods.push_back(new NativeIntegerTIMES());
	Methods.push_back(new NativeIntegerDIVIDE());
	Methods.push_back(new NativeIntegerREAD());
	Methods.push_back(new NativeIntegerATMOST());
	Methods.push_back(new NativeIntegerATLEAST());
	Methods.push_back(new NativeIntegerMORE());
	Methods.push_back(new NativeIntegerLESS());
	Methods.push_back(new NativeIntegerEQUALS());
	Methods.push_back(new NativeIntegerSTR());

	ParentName = OBJ_STRING;
	TypeName = new NamedType(this->NearestSyntax, INT_STRING, INT_STRING);

	Reduce();
}

NativeInteger::~NativeInteger(){

}

void NativeInteger::DefineType(std::stringstream &ss)
{
	FUNC_LOG("void NativeInteger::DefineType(std::stringstream &ss)");
	std::string ClassName = "Class_" + this->TypeName->Type;
	std::string ObjectName = "Object_" + this->TypeName->Type;


	ss << "struct " << ClassName  << "{" << std::endl;

	ss << "\t" << this->MethodConstructor->GenPointer(ObjectName) << ";" <<std::endl;


	std::vector<std::string> method_names = GenMethodList();
	for(auto itr = method_names.begin(); itr != method_names.end(); itr++)
	{
		MethodClass *method = this->LookupMethod(*itr);

		ss << "\t" << method->GenPointer(ObjectName)<< ";" <<std::endl;

	}

	ss << "} ;" <<std::endl<<std::endl;


	ss << "struct " << ObjectName<< "{" << std::endl;

	ss << "\t" << ClassName << " *" << "_class_pointer" << ";" <<std::endl;
	ss << "\t" << "int" << " " << "_int_value" << ";" <<std::endl;

	ss << "} ;" <<std::endl<<std::endl;

}

class NativeBooleanConstructor : public NativeMethod{
public:
	NativeBooleanConstructor() : NativeMethod(BOOL_STRING, BOOL_STRING)
	{
		Statements = GenReturnThis();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss <<"\t" << this->Parent->ObjectTypeName() << " * returnValue = (" + this->Parent->ObjectTypeName() + "*)malloc(sizeof(" + this->Parent->ObjectTypeName() + "));" << std::endl;
		//ss <<"\t" << this->Parent->ObjectTypeName() << " * returnValue = new " + this->Parent->ObjectTypeName() + "();" << std::endl;
		ss <<"\t" << "returnValue->_class_pointer = &GLOBAL_" +  this->Parent->ClassTypeName() << ";" << std::endl;
		ss <<"\t" << "returnValue->_bool_value = 0;" << std::endl;
		ss <<"\t" << "return returnValue;" << std::endl;
	}

};

class NativeBooleanEQUALS : public NativeMethod{
public:
	NativeBooleanEQUALS() : NativeMethod("EQUALS", BOOL_STRING,BOOL_STRING, "_other_bool")
	{
		Statements = GenFalseValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();" << std::endl;
		ss << "\t" << "returnValue->_bool_value = (_this_ptr->_bool_value == _other_bool->_bool_value) ? (1):(0);" << std::endl;
		ss << "\t" << "return returnValue;" << std::endl;
	}

};

class NativeBooleanAND : public NativeMethod{
public:
	NativeBooleanAND() : NativeMethod("AND", BOOL_STRING,BOOL_STRING, "_other_bool")
	{
		Statements = GenFalseValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();" << std::endl;
		ss << "\t" << "returnValue->_bool_value = ((1==_this_ptr->_bool_value) && (1==_other_bool->_bool_value))?(1):(0);" << std::endl;
		ss << "\t" << "return returnValue;" << std::endl;
	}

};

class NativeBooleanOR : public NativeMethod{
public:
	NativeBooleanOR() : NativeMethod("OR", BOOL_STRING,BOOL_STRING, "_other_bool")
	{
		Statements = GenFalseValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();" << std::endl;
		ss << "\t" << "returnValue->_bool_value = ((1 == _this_ptr->_bool_value) ||(1== _other_bool->_bool_value))?(1):(0);" << std::endl;
		ss << "\t" << "return returnValue;" << std::endl;
	}

};

class NativeBooleanNOT : public NativeMethod{
public:
	NativeBooleanNOT() : NativeMethod("NOT", BOOL_STRING)
	{
		Statements = GenFalseValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();" << std::endl;
		ss << "\t" << "returnValue->_bool_value = (0==_this_ptr->_bool_value)?(1):(0);" << std::endl;
		ss << "\t" << "return returnValue;" << std::endl;
	}
};

class NativeBooleanSTR : public NativeMethod{
public:
	NativeBooleanSTR() : NativeMethod("STR",STRING_STRING)
	{
		Statements = ::GenEmptyStringReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Str* returnValue = (*GLOBAL_Class_Str.Class_Str_Method_Str)();" << std::endl;

		ss << "\t" << "char * _true_string = \"true\";" << std::endl;
		ss << "\t" << "char * _false_string = \"false\";" << std::endl;
		ss << "\t" << "char * _bool_string = (0 != _this_ptr->_bool_value ) ? (_true_string) : (_false_string) ;" << std::endl;

		ss << "\t" << "size_t needed = snprintf(NULL, 0, \"%s\", _bool_string) + 1;" << std::endl;
		ss << "\t" << "char  *buffer = (char *)malloc(needed);" << std::endl;
		ss << "\t" << "snprintf(buffer, needed, \"%s\", _bool_string) + 1;" << std::endl;
		ss << "\t" << "returnValue->_string_value = buffer; " << std::endl;

		////ss << "\t" <<  "returnValue->_bool_value =  _this_ptr->_string_value.compare( _other_string->_string_value)>0;" << std::endl;

		ss << "\t" << "return returnValue;" << std::endl;
	}

};

NativeBoolean::NativeBoolean() : ClassClass(new SyntaxNode(BOOL_STRING,CLASS,-999))
{
	FUNC_LOG("NativeBoolean::NativeBoolean() : ClassClass(new SyntaxNode(BOOL_STRING,CLASS,-999))");

	MethodConstructor = new NativeBooleanConstructor();

	Methods.push_back(new NativeBooleanEQUALS());
	Methods.push_back(new NativeBooleanAND());
	Methods.push_back(new NativeBooleanOR());
	Methods.push_back(new NativeBooleanNOT());
	Methods.push_back(new NativeBooleanSTR());


	ParentName = OBJ_STRING;
	TypeName = new NamedType(this->NearestSyntax, BOOL_STRING, BOOL_STRING);
	Reduce();
}

NativeBoolean::~NativeBoolean(){

}

void NativeBoolean::DefineType(std::stringstream &ss)
{
	FUNC_LOG("void NativeBoolean::DefineType(std::stringstream &ss)");

	std::string ClassName = "Class_" + this->TypeName->Type;
	std::string ObjectName = "Object_" + this->TypeName->Type;

	ss << "struct " << ClassName  << "{" << std::endl;

	ss << "\t" << this->MethodConstructor->GenPointer(ObjectName) << ";" <<std::endl;


	std::vector<std::string> method_names = GenMethodList();
	for(auto itr = method_names.begin(); itr != method_names.end(); itr++)
	{
		MethodClass *method = this->LookupMethod(*itr);

		ss << "\t" << method->GenPointer(ObjectName)<< ";" <<std::endl;

	}

	ss << "} ;" <<std::endl<<std::endl;


	ss << "struct " << ObjectName<< "{" << std::endl;

	ss << "\t" << ClassName << " *" << "_class_pointer" << ";" <<std::endl;
	ss << "\t" << "unsigned short" << " " << "_bool_value" << ";" <<std::endl;

	ss << "} ;" <<std::endl<<std::endl;
}

class NativeNothingConstructor : public NativeMethod{
public:
	NativeNothingConstructor() : NativeMethod(NOTHING_STRING, NOTHING_STRING)
	{
		Statements = GenReturnThis();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss <<"\t" << this->Parent->ObjectTypeName() << " * returnValue = (" + this->Parent->ObjectTypeName() + "*)malloc(sizeof(" + this->Parent->ObjectTypeName() + "));" << std::endl;
		//ss <<"\t" << this->Parent->ObjectTypeName() << " * returnValue = new " + this->Parent->ObjectTypeName() + "();" << std::endl;
		ss <<"\t" << "returnValue->_class_pointer = &GLOBAL_" +  this->Parent->ClassTypeName() << ";" << std::endl;
		ss <<"\t" << "return returnValue;" << std::endl;
	}
};

class NativeNothingSTR : public NativeMethod{
public:
	NativeNothingSTR() : NativeMethod("STR",STRING_STRING)
	{
		Statements = ::GenEmptyStringReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Str* returnValue = (*GLOBAL_Class_Str.Class_Str_Method_Str)();" << std::endl;

		ss << "\t" << "size_t needed = snprintf(NULL, 0, \"%s\", \"none\") + 1;" << std::endl;
		ss << "\t" << "char  *buffer = (char *)malloc(needed);" << std::endl;
		ss << "\t" << "snprintf(buffer, needed, \"%s\", \"none\");" << std::endl;
		ss << "\t" << "returnValue->_string_value = buffer; " << std::endl;
		ss << "\t" << "return returnValue;" << std::endl;
	}

};

NativeNothing::NativeNothing() : ClassClass(new SyntaxNode(NOTHING_STRING,CLASS,-999))
{
	FUNC_LOG("NativeNothing::NativeNothing() : ClassClass(new SyntaxNode(NOTHING_STRING,CLASS,-999))");

	MethodConstructor = new NativeNothingConstructor();
	Methods.push_back(new NativeNothingSTR());

	ParentName = OBJ_STRING;
	TypeName = new NamedType(this->NearestSyntax, NOTHING_STRING, NOTHING_STRING);
	Reduce();
}

NativeNothing::~NativeNothing(){

}


class NativeStringConstructor : public NativeMethod{
public:
	NativeStringConstructor() : NativeMethod(STRING_STRING, STRING_STRING)
	{
		Statements = GenReturnThis();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss <<"\t" << this->Parent->ObjectTypeName() << " * returnValue = (" + this->Parent->ObjectTypeName() + "*)malloc(sizeof(" + this->Parent->ObjectTypeName() + "));" << std::endl;
		//ss <<"\t" << this->Parent->ObjectTypeName() << " * returnValue = new " + this->Parent->ObjectTypeName() + "();" << std::endl;
		ss <<"\t" << "returnValue->_class_pointer = &GLOBAL_" +  this->Parent->ClassTypeName() << ";" << std::endl;
		ss <<"\t" << "returnValue->_string_value = NULL;" << std::endl;
		ss <<"\t" << "return returnValue;" << std::endl;
	}
};

class NativeStringREAD : public NativeMethod{
public:
	NativeStringREAD() : NativeMethod("READ",STRING_STRING)
	{
		Statements = GenEmptyStringReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t" << "const int SIZE = 1024;" << std::endl;
		ss << "\t" << "char read_buffer[SIZE];" << std::endl;
		ss << "\t" << "fgets(read_buffer,SIZE,stdin);" << std::endl;

		ss << "\t" << "size_t needed = snprintf(NULL, 0, \"%s\", read_buffer) + 1;" << std::endl;
		ss << "\t" << "char  *write_buffer = (char *)malloc(needed);" << std::endl;
		ss << "\t" << "snprintf(write_buffer , needed, \"%s\", read_buffer);" << std::endl;
		ss << "\t" << "_this_ptr->_string_value = write_buffer ; " << std::endl;

		ss << "\t" << "return _this_ptr;" << std::endl;
	}

};

class NativeStringPLUS : public NativeMethod{
public:
	NativeStringPLUS() : NativeMethod("PLUS", STRING_STRING,STRING_STRING, "_other_string")
	{
		Statements = GenEmptyStringReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Str* returnValue = (*GLOBAL_Class_Str.Class_Str_Method_Str)();" << std::endl;
		ss << "\t" << "size_t needed = snprintf(NULL, 0, \"%s%s\", _this_ptr->_string_value, _other_string->_string_value) + 1;" << std::endl;
		ss << "\t" << "char  *buffer = (char *)malloc(needed);" << std::endl;
		ss << "\t" << "snprintf(buffer, needed, \"%s%s\", _this_ptr->_string_value, _other_string->_string_value) ;" << std::endl;
		ss << "\t" << "returnValue->_string_value = buffer; " << std::endl;
		ss << "\t" << "return returnValue;" << std::endl;
	}

};

class NativeStringEQUALS : public NativeMethod{
public:
	NativeStringEQUALS() : NativeMethod("EQUALS", BOOL_STRING,STRING_STRING, "_other_string")
	{
		Statements = GenFalseValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();" << std::endl;

		ss << "\t" << "if(strcmp(_this_ptr->_string_value,_other_string->_string_value)==0)" << std::endl;
 		ss << "\t" << "{" << std::endl;
 		ss << "\t\t" << "returnValue->_bool_value = 1;" << std::endl;
 		ss << "\t" << "}" << std::endl;
 		ss << "\t" << "else" << std::endl;
 		ss << "\t" <<"{" << std::endl;
 		ss << "\t\t" << "returnValue->_bool_value = 0;" << std::endl;
 		ss << "\t" << "}" << std::endl;
		ss << "\t" << "return returnValue;" << std::endl;
	}

};

/*
class NativeStringATLEAST : public NativeMethod{
public:
	NativeStringATLEAST() : NativeMethod("ATLEAST", BOOL_STRING,STRING_STRING, "_other_string")
	{
		Statements = GenFalseValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();" << std::endl;

		ss << "\t" <<  "returnValue->_bool_value =  _this_ptr->_string_value.compare( _other_string->_string_value)>=0;" << std::endl;

		ss << "\t" << "return returnValue;" << std::endl;
	}

};

class NativeStringATMOST : public NativeMethod{
public:
	NativeStringATMOST() : NativeMethod("ATMOST", BOOL_STRING,STRING_STRING, "_other_string")
	{
		Statements = GenFalseValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();" << std::endl;

		ss << "\t" <<  "returnValue->_bool_value =  _this_ptr->_string_value.compare( _other_string->_string_value)<=0;" << std::endl;

		ss << "\t" << "return returnValue;" << std::endl;
	}

};

class NativeStringLESS : public NativeMethod{
public:
	NativeStringLESS() : NativeMethod("LESS", BOOL_STRING,STRING_STRING, "_other_string")
	{
		Statements = GenFalseValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();" << std::endl;

		ss << "\t" <<  "returnValue->_bool_value =  _this_ptr->_string_value.compare( _other_string->_string_value)<0;" << std::endl;

		ss << "\t" << "return returnValue;" << std::endl;
	}

};

class NativeStringMORE : public NativeMethod{
public:
	NativeStringMORE() : NativeMethod("MORE", BOOL_STRING,STRING_STRING, "_other_string")
	{
		Statements = GenFalseValueReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		ss << "\t"<< "Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();" << std::endl;

		ss << "\t" <<  "returnValue->_bool_value =  _this_ptr->_string_value.compare( _other_string->_string_value)>0;" << std::endl;

		ss << "\t" << "return returnValue;" << std::endl;
	}

};
*/


class NativeStringSTR : public NativeMethod{
public:
	NativeStringSTR() : NativeMethod("STR",STRING_STRING)
	{
		Statements = ::GenEmptyStringReturn();
	}
	virtual void generateNativeCode(std::stringstream &ss)
	{
		//ss << "\t"<< "Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();" << std::endl;

		//ss << "\t" <<  "returnValue->_bool_value =  _this_ptr->_string_value.compare( _other_string->_string_value)>0;" << std::endl;

		ss << "\t" << "return _this_ptr;" << std::endl;
	}

};



NativeString::NativeString() : ClassClass(new SyntaxNode(STRING_STRING,CLASS,-999))
{
	FUNC_LOG("NativeString::NativeString() : ClassClass(new SyntaxNode(STRING_STRING,CLASS,-999))");

	MethodConstructor = new NativeStringConstructor();

	Methods.push_back(new NativeStringPLUS());
	Methods.push_back(new NativeStringREAD());
	Methods.push_back(new NativeStringEQUALS());
/*	Methods.push_back(new NativeStringATMOST());
	Methods.push_back(new NativeStringATLEAST());
	Methods.push_back(new NativeStringLESS());
	Methods.push_back(new NativeStringMORE());
	*/
	Methods.push_back(new NativeStringSTR());

	Reduce();
}

NativeString::~NativeString(){

}


void NativeString::DefineType(std::stringstream &ss)
{
	FUNC_LOG("void NativeString::DefineType(std::stringstream &ss)");

	std::string ClassName = "Class_" + this->TypeName->Type;
	std::string ObjectName = "Object_" + this->TypeName->Type;

	ss << "struct " << ClassName  << "{" << std::endl;

	ss << "\t" << this->MethodConstructor->GenPointer(ObjectName) << ";" <<std::endl;


	std::vector<std::string> method_names = GenMethodList();
	for(auto itr = method_names.begin(); itr != method_names.end(); itr++)
	{
		MethodClass *method = this->LookupMethod(*itr);

		ss << "\t" << method->GenPointer(ObjectName)<< ";" <<std::endl;

	}

	ss << "} ;" <<std::endl<<std::endl;


	ss << "struct " << ObjectName<< "{" << std::endl;

	ss << "\t" << ClassName << " *" << "_class_pointer" << ";" <<std::endl;
	ss << "\t" << "char *" << " " << "_string_value" << ";" <<std::endl;

	ss << "} ;" <<std::endl<<std::endl;

}



