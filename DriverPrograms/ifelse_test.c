#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Class_Obj Class_Obj;
typedef struct Object_Obj Object_Obj;
typedef struct Class_Nothing Class_Nothing;
typedef struct Object_Nothing Object_Nothing;
typedef struct Class_Str Class_Str;
typedef struct Object_Str Object_Str;
typedef struct Class_Int Class_Int;
typedef struct Object_Int Object_Int;
typedef struct Class_Boolean Class_Boolean;
typedef struct Object_Boolean Object_Boolean;

struct Class_Obj{
	Object_Obj* (*Class_Obj_Method_Obj)();
	Object_Str* (*Class_Obj_Method_STR)(Object_Obj* _this_ptr);
	Object_Nothing* (*Class_Obj_Method_PRINT)(Object_Obj* _this_ptr);
} ;

struct Object_Obj{
	Class_Obj *_class_pointer;
} ;

struct Class_Nothing{
	Object_Nothing* (*Class_Nothing_Method_Nothing)();
	Object_Str* (*Class_Nothing_Method_STR)(Object_Nothing* _this_ptr);
	Object_Nothing* (*Class_Obj_Method_PRINT)(Object_Obj* _this_ptr);
} ;

struct Object_Nothing{
	Class_Nothing *_class_pointer;
} ;

struct Class_Str{
	Object_Str* (*Class_Str_Method_Str)();
	Object_Str* (*Class_Str_Method_STR)(Object_Str* _this_ptr);
	Object_Nothing* (*Class_Obj_Method_PRINT)(Object_Obj* _this_ptr);
	Object_Str* (*Class_Str_Method_PLUS)(Object_Str* _this_ptr, Object_Str* _other_string);
	Object_Str* (*Class_Str_Method_READ)(Object_Str* _this_ptr);
	Object_Boolean* (*Class_Str_Method_EQUALS)(Object_Str* _this_ptr, Object_Str* _other_string);
} ;

struct Object_Str{
	Class_Str *_class_pointer;
	char * _string_value;
} ;

struct Class_Int{
	Object_Int* (*Class_Int_Method_Int)();
	Object_Str* (*Class_Int_Method_STR)(Object_Int* _this_ptr);
	Object_Nothing* (*Class_Obj_Method_PRINT)(Object_Obj* _this_ptr);
	Object_Int* (*Class_Int_Method_PLUS)(Object_Int* _this_ptr, Object_Int* _other_int);
	Object_Int* (*Class_Int_Method_MINUS)(Object_Int* _this_ptr, Object_Int* _other_int);
	Object_Int* (*Class_Int_Method_TIMES)(Object_Int* _this_ptr, Object_Int* _other_int);
	Object_Int* (*Class_Int_Method_DIVIDE)(Object_Int* _this_ptr, Object_Int* _other_int);
	Object_Int* (*Class_Int_Method_READ)(Object_Int* _this_ptr);
	Object_Boolean* (*Class_Int_Method_ATMOST)(Object_Int* _this_ptr, Object_Int* _other_int);
	Object_Boolean* (*Class_Int_Method_ATLEAST)(Object_Int* _this_ptr, Object_Int* _other_int);
	Object_Boolean* (*Class_Int_Method_MORE)(Object_Int* _this_ptr, Object_Int* _other_int);
	Object_Boolean* (*Class_Int_Method_LESS)(Object_Int* _this_ptr, Object_Int* _other_int);
	Object_Boolean* (*Class_Int_Method_EQUALS)(Object_Int* _this_ptr, Object_Int* _other_int);
} ;

struct Object_Int{
	Class_Int *_class_pointer;
	int _int_value;
} ;

struct Class_Boolean{
	Object_Boolean* (*Class_Boolean_Method_Boolean)();
	Object_Str* (*Class_Boolean_Method_STR)(Object_Boolean* _this_ptr);
	Object_Nothing* (*Class_Obj_Method_PRINT)(Object_Obj* _this_ptr);
	Object_Boolean* (*Class_Boolean_Method_EQUALS)(Object_Boolean* _this_ptr, Object_Boolean* _other_bool);
	Object_Boolean* (*Class_Boolean_Method_AND)(Object_Boolean* _this_ptr, Object_Boolean* _other_bool);
	Object_Boolean* (*Class_Boolean_Method_OR)(Object_Boolean* _this_ptr, Object_Boolean* _other_bool);
	Object_Boolean* (*Class_Boolean_Method_NOT)(Object_Boolean* _this_ptr);
} ;

struct Object_Boolean{
	Class_Boolean *_class_pointer;
	unsigned short _bool_value;
} ;

	Class_Obj	GLOBAL_Class_Obj;
	Class_Nothing	GLOBAL_Class_Nothing;
	Class_Str	GLOBAL_Class_Str;
	Class_Int	GLOBAL_Class_Int;
	Class_Boolean	GLOBAL_Class_Boolean;


Object_Obj* Class_Obj_Method_Obj()
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Obj * returnValue = (Object_Obj*)malloc(sizeof(Object_Obj));
	returnValue->_class_pointer = &GLOBAL_Class_Obj;
	return returnValue;

}

Object_Str* Class_Obj_Method_STR(Object_Obj* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Str* returnValue = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	const void * address = (const void*)(_this_ptr);
	size_t needed = snprintf(NULL, 0, "Native Object Pointer Address: %p \n", address ) + 1;
	char  *buffer = (char *)malloc(needed);
	snprintf(buffer, needed, "Native Object Pointer Address: %p \n", address) ;
	returnValue->_string_value = buffer; 
	return returnValue;

}

Object_Nothing* Class_Obj_Method_PRINT(Object_Obj* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Str* print = (*_this_ptr->_class_pointer->Class_Obj_Method_STR)(_this_ptr);
	printf("%s\n",print->_string_value);
	Object_Nothing* returnValue = (*GLOBAL_Class_Nothing.Class_Nothing_Method_Nothing)();
	return returnValue;

}

Object_Nothing* Class_Nothing_Method_Nothing()
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Nothing * returnValue = (Object_Nothing*)malloc(sizeof(Object_Nothing));
	returnValue->_class_pointer = &GLOBAL_Class_Nothing;
	return returnValue;

}

Object_Str* Class_Nothing_Method_STR(Object_Nothing* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Str* returnValue = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	size_t needed = snprintf(NULL, 0, "%s", "none") + 1;
	char  *buffer = (char *)malloc(needed);
	snprintf(buffer, needed, "%s", "none");
	returnValue->_string_value = buffer; 
	return returnValue;

}

Object_Str* Class_Str_Method_Str()
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Str * returnValue = (Object_Str*)malloc(sizeof(Object_Str));
	returnValue->_class_pointer = &GLOBAL_Class_Str;
	returnValue->_string_value = NULL;
	return returnValue;

}

Object_Str* Class_Str_Method_PLUS(Object_Str* _this_ptr, Object_Str* _other_string)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Str* returnValue = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	size_t needed = snprintf(NULL, 0, "%s%s", _this_ptr->_string_value, _other_string->_string_value) + 1;
	char  *buffer = (char *)malloc(needed);
	snprintf(buffer, needed, "%s%s", _this_ptr->_string_value, _other_string->_string_value) ;
	returnValue->_string_value = buffer; 
	return returnValue;

}

Object_Str* Class_Str_Method_READ(Object_Str* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	const int SIZE = 1024;
	char read_buffer[SIZE];
	fgets(read_buffer,SIZE,stdin);
	size_t needed = snprintf(NULL, 0, "%s", read_buffer) + 1;
	char  *write_buffer = (char *)malloc(needed);
	snprintf(write_buffer , needed, "%s", read_buffer);
	_this_ptr->_string_value = write_buffer ; 
	return _this_ptr;

}

Object_Boolean* Class_Str_Method_EQUALS(Object_Str* _this_ptr, Object_Str* _other_string)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	if(strcmp(_this_ptr->_string_value,_other_string->_string_value)==0)
	{
		returnValue->_bool_value = 1;
	}
	else
	{
		returnValue->_bool_value = 0;
	}
	return returnValue;

}

Object_Str* Class_Str_Method_STR(Object_Str* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	return _this_ptr;

}

Object_Int* Class_Int_Method_Int()
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int * returnValue = (Object_Int*)malloc(sizeof(Object_Int));
	returnValue->_class_pointer = &GLOBAL_Class_Int;
	returnValue->_int_value = 0;
	return returnValue;

}

Object_Int* Class_Int_Method_PLUS(Object_Int* _this_ptr, Object_Int* _other_int)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* returnValue = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	returnValue->_int_value = (_this_ptr->_int_value + _other_int->_int_value);
	return returnValue;

}

Object_Int* Class_Int_Method_MINUS(Object_Int* _this_ptr, Object_Int* _other_int)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* returnValue = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	returnValue->_int_value = (_this_ptr->_int_value - _other_int->_int_value);
	return returnValue;

}

Object_Int* Class_Int_Method_TIMES(Object_Int* _this_ptr, Object_Int* _other_int)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* returnValue = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	returnValue->_int_value = (_this_ptr->_int_value * _other_int->_int_value);
	return returnValue;

}

Object_Int* Class_Int_Method_DIVIDE(Object_Int* _this_ptr, Object_Int* _other_int)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* returnValue = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	returnValue->_int_value = (_this_ptr->_int_value / _other_int->_int_value);
	return returnValue;

}

Object_Int* Class_Int_Method_READ(Object_Int* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	char buffer =0;
	scanf("%d%c",&_this_ptr->_int_value,&buffer);
	return _this_ptr;

}

Object_Boolean* Class_Int_Method_ATMOST(Object_Int* _this_ptr, Object_Int* _other_int)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	returnValue->_bool_value = (_this_ptr->_int_value <= _other_int->_int_value);
	return returnValue;

}

Object_Boolean* Class_Int_Method_ATLEAST(Object_Int* _this_ptr, Object_Int* _other_int)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	returnValue->_bool_value = (_this_ptr->_int_value >= _other_int->_int_value);
	return returnValue;

}

Object_Boolean* Class_Int_Method_MORE(Object_Int* _this_ptr, Object_Int* _other_int)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	returnValue->_bool_value = (_this_ptr->_int_value > _other_int->_int_value);
	return returnValue;

}

Object_Boolean* Class_Int_Method_LESS(Object_Int* _this_ptr, Object_Int* _other_int)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	returnValue->_bool_value = (_this_ptr->_int_value < _other_int->_int_value);
	return returnValue;

}

Object_Boolean* Class_Int_Method_EQUALS(Object_Int* _this_ptr, Object_Int* _other_int)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	returnValue->_bool_value = (_this_ptr->_int_value == _other_int->_int_value);
	return returnValue;

}

Object_Str* Class_Int_Method_STR(Object_Int* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Str* returnValue = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	size_t needed = snprintf(NULL, 0, "%d", _this_ptr->_int_value) + 1;
	char  *buffer = (char *)malloc(needed);
	snprintf(buffer, needed, "%d", _this_ptr->_int_value) + 1;
	returnValue->_string_value = buffer; 
	return returnValue;

}

Object_Boolean* Class_Boolean_Method_Boolean()
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean * returnValue = (Object_Boolean*)malloc(sizeof(Object_Boolean));
	returnValue->_class_pointer = &GLOBAL_Class_Boolean;
	returnValue->_bool_value = 0;
	return returnValue;

}

Object_Boolean* Class_Boolean_Method_EQUALS(Object_Boolean* _this_ptr, Object_Boolean* _other_bool)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	returnValue->_bool_value = (_this_ptr->_bool_value == _other_bool->_bool_value) ? (1):(0);
	return returnValue;

}

Object_Boolean* Class_Boolean_Method_AND(Object_Boolean* _this_ptr, Object_Boolean* _other_bool)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	returnValue->_bool_value = ((1==_this_ptr->_bool_value) && (1==_other_bool->_bool_value))?(1):(0);
	return returnValue;

}

Object_Boolean* Class_Boolean_Method_OR(Object_Boolean* _this_ptr, Object_Boolean* _other_bool)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	returnValue->_bool_value = ((1 == _this_ptr->_bool_value) ||(1== _other_bool->_bool_value))?(1):(0);
	return returnValue;

}

Object_Boolean* Class_Boolean_Method_NOT(Object_Boolean* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	returnValue->_bool_value = (0==_this_ptr->_bool_value)?(1):(0);
	return returnValue;

}

Object_Str* Class_Boolean_Method_STR(Object_Boolean* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Str* returnValue = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	char * _true_string = "true";
	char * _false_string = "false";
	char * _bool_string = (0 != _this_ptr->_bool_value ) ? (_true_string) : (_false_string) ;
	size_t needed = snprintf(NULL, 0, "%s", _bool_string) + 1;
	char  *buffer = (char *)malloc(needed);
	snprintf(buffer, needed, "%s", _bool_string) + 1;
	returnValue->_string_value = buffer; 
	return returnValue;

}

Object_Nothing* class_MAIN_method_MAIN()
{
// Adding Arguments to the named map 
// allocating variables.
// If Else List Begin. 
// If test
	label_2_:;
	{
	Object_Boolean* Boolean_gen_0 = NULL; // Default New Var reg of type: Boolean
// Start Boolean Expression emit.
	Object_Boolean* Boolean_gen_1 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_2 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_3 = NULL; // Default New Var reg of type: Boolean
	{
/// L EXPRESSION AND begin.
// Generate Typed Value 
	Object_Boolean* Boolean_gen_4 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_4 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_4->_bool_value = 1;
	Boolean_gen_2 = Boolean_gen_4; // evaled left of AND expression.
	if (0==Boolean_gen_2->_bool_value)
	{
		Boolean_gen_1 = Boolean_gen_2;
		 goto label_4_; 
	}
	else
	{
		 goto label_5_; 
	}
	label_5_:;
/// R expression AND begin.
	{
// Generate Typed Value 
	Object_Boolean* Boolean_gen_5 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_5 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_5->_bool_value = 0;
		Boolean_gen_1 = Boolean_gen_5; // evaled right of AND expression.
	goto label_4_;
	}
// end AND short circuit.
	label_4_:;
	}
		Boolean_gen_0 = Boolean_gen_1;
		if (1==Boolean_gen_0->_bool_value)
		{
			 goto label_1_; 
		}
		else
		{
			 goto label_3_; 
		}
	}
	label_1_:;
// code block
	{
// If Else List Begin. 
// If test
	label_9_:;
	{
	Object_Boolean* Boolean_gen_6 = NULL; // Default New Var reg of type: Boolean
// Start Boolean Expression emit.
	Object_Boolean* Boolean_gen_7 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_8 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_9 = NULL; // Default New Var reg of type: Boolean
	{
/// L EXPRESSION OR begin.
// Generate Typed Value 
	Object_Boolean* Boolean_gen_10 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_10 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_10->_bool_value = 0;
	Boolean_gen_8 = Boolean_gen_10; // evaled left of OR expression.
	if (1==Boolean_gen_8->_bool_value)
	{
		Boolean_gen_7 = Boolean_gen_8;
		 goto label_11_; 
	}
	else
	{
		 goto label_12_; 
	}
	label_12_:;
/// R expression OR begin.
	{
// Generate Typed Value 
	Object_Boolean* Boolean_gen_11 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_11 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_11->_bool_value = 1;
		Boolean_gen_7 = Boolean_gen_11; // evaled right of OR expression.
	goto label_11_;
	}
// end OR short circuit.
	label_11_:;
	}
		Boolean_gen_6 = Boolean_gen_7;
		if (1==Boolean_gen_6->_bool_value)
		{
			 goto label_8_; 
		}
		else
		{
			 goto label_10_; 
		}
	}
	label_8_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_0 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_1 = NULL; // Default New Var reg of type: Str
	Str_gen_1 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_1->_string_value = "If 1 Nested 1";
Str_gen_0 = Str_gen_1; // generate method left exp complete.
	Object_Obj* Obj_gen_0 = NULL; // Default New Var reg of type: Obj
	Obj_gen_0 = ( (Object_Obj* )Str_gen_0); 
	Object_Nothing* Nothing_gen_0 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_0 = (* Obj_gen_0->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_0);
	goto label_7_;
	}
// end code block
// If test
	label_10_:;
	{
	Object_Boolean* Boolean_gen_12 = NULL; // Default New Var reg of type: Boolean
	Object_Int* Int_gen_0 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_1 = NULL; // Default New Var reg of type: Int
	Int_gen_1 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_1->_int_value = 10;
// After Left Math Eval.
	Int_gen_0 = Int_gen_1; // evaled left of expression.
	Object_Int* Int_gen_2 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_3 = NULL; // Default New Var reg of type: Int
	Int_gen_3 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_3->_int_value = 3;
// After Right  Math Eval.
	Int_gen_2 = Int_gen_3; // evaled right of expression.
	Object_Boolean* Boolean_gen_13 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_13 = (*Int_gen_0->_class_pointer->Class_Int_Method_MORE)(Int_gen_0, Int_gen_2);
		Boolean_gen_12 = Boolean_gen_13;
		if (1==Boolean_gen_12->_bool_value)
		{
			 goto label_13_; 
		}
		else
		{
			 goto label_14_; 
		}
	}
	label_13_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_2 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_3 = NULL; // Default New Var reg of type: Str
	Str_gen_3 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_3->_string_value = "If 1 Nested 2";
Str_gen_2 = Str_gen_3; // generate method left exp complete.
	Object_Obj* Obj_gen_1 = NULL; // Default New Var reg of type: Obj
	Obj_gen_1 = ( (Object_Obj* )Str_gen_2); 
	Object_Nothing* Nothing_gen_1 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_1 = (* Obj_gen_1->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_1);
	goto label_7_;
	}
// end code block
// If test
	label_14_:;
	label_15_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_4 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_5 = NULL; // Default New Var reg of type: Str
	Str_gen_5 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_5->_string_value = "If 1 Nested 3";
Str_gen_4 = Str_gen_5; // generate method left exp complete.
	Object_Obj* Obj_gen_2 = NULL; // Default New Var reg of type: Obj
	Obj_gen_2 = ( (Object_Obj* )Str_gen_4); 
	Object_Nothing* Nothing_gen_2 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_2 = (* Obj_gen_2->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_2);
	goto label_7_;
	}
// end code block
	label_7_:;
// If Else List end. 
	goto label_0_;
	}
// end code block
// If test
	label_3_:;
	{
	Object_Boolean* Boolean_gen_14 = NULL; // Default New Var reg of type: Boolean
	Object_Str* Str_gen_6 = NULL; // Default New Var reg of type: Str
// Before Left Math Eval.
// Generate Typed Value 
	Object_Str* Str_gen_7 = NULL; // Default New Var reg of type: Str
	Str_gen_7 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_7->_string_value = "goodbye";
// After Left Math Eval.
	Str_gen_6 = Str_gen_7; // evaled left of expression.
	Object_Str* Str_gen_8 = NULL; // Default New Var reg of type: Str
// Before Right Math Eval.
// Generate Typed Value 
	Object_Str* Str_gen_9 = NULL; // Default New Var reg of type: Str
	Str_gen_9 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_9->_string_value = "goodbye";
// After Right  Math Eval.
	Str_gen_8 = Str_gen_9; // evaled right of expression.
	Object_Boolean* Boolean_gen_15 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_15 = (*Str_gen_6->_class_pointer->Class_Str_Method_EQUALS)(Str_gen_6, Str_gen_8);
		Boolean_gen_14 = Boolean_gen_15;
		if (1==Boolean_gen_14->_bool_value)
		{
			 goto label_6_; 
		}
		else
		{
			 goto label_18_; 
		}
	}
	label_6_:;
// code block
	{
// If Else List Begin. 
// If test
	label_22_:;
	{
	Object_Boolean* Boolean_gen_16 = NULL; // Default New Var reg of type: Boolean
// Start Boolean Expression emit.
	Object_Boolean* Boolean_gen_17 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_18 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_19 = NULL; // Default New Var reg of type: Boolean
	{
/// L EXPRESSION OR begin.
// Generate Typed Value 
	Object_Boolean* Boolean_gen_20 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_20 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_20->_bool_value = 0;
	Boolean_gen_18 = Boolean_gen_20; // evaled left of OR expression.
	if (1==Boolean_gen_18->_bool_value)
	{
		Boolean_gen_17 = Boolean_gen_18;
		 goto label_24_; 
	}
	else
	{
		 goto label_25_; 
	}
	label_25_:;
/// R expression OR begin.
	{
// Generate Typed Value 
	Object_Boolean* Boolean_gen_21 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_21 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_21->_bool_value = 0;
		Boolean_gen_17 = Boolean_gen_21; // evaled right of OR expression.
	goto label_24_;
	}
// end OR short circuit.
	label_24_:;
	}
		Boolean_gen_16 = Boolean_gen_17;
		if (1==Boolean_gen_16->_bool_value)
		{
			 goto label_21_; 
		}
		else
		{
			 goto label_23_; 
		}
	}
	label_21_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_10 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_11 = NULL; // Default New Var reg of type: Str
	Str_gen_11 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_11->_string_value = "If 2 Nested 1";
Str_gen_10 = Str_gen_11; // generate method left exp complete.
	Object_Obj* Obj_gen_3 = NULL; // Default New Var reg of type: Obj
	Obj_gen_3 = ( (Object_Obj* )Str_gen_10); 
	Object_Nothing* Nothing_gen_3 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_3 = (* Obj_gen_3->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_3);
	goto label_20_;
	}
// end code block
// If test
	label_23_:;
	{
	Object_Boolean* Boolean_gen_22 = NULL; // Default New Var reg of type: Boolean
	Object_Int* Int_gen_4 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_5 = NULL; // Default New Var reg of type: Int
	Int_gen_5 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_5->_int_value = 10;
// After Left Math Eval.
	Int_gen_4 = Int_gen_5; // evaled left of expression.
	Object_Int* Int_gen_6 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_7 = NULL; // Default New Var reg of type: Int
	Int_gen_7 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_7->_int_value = 3;
// After Right  Math Eval.
	Int_gen_6 = Int_gen_7; // evaled right of expression.
	Object_Boolean* Boolean_gen_23 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_23 = (*Int_gen_4->_class_pointer->Class_Int_Method_LESS)(Int_gen_4, Int_gen_6);
		Boolean_gen_22 = Boolean_gen_23;
		if (1==Boolean_gen_22->_bool_value)
		{
			 goto label_26_; 
		}
		else
		{
			 goto label_27_; 
		}
	}
	label_26_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_12 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_13 = NULL; // Default New Var reg of type: Str
	Str_gen_13 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_13->_string_value = "If 2 Nested 2";
Str_gen_12 = Str_gen_13; // generate method left exp complete.
	Object_Obj* Obj_gen_4 = NULL; // Default New Var reg of type: Obj
	Obj_gen_4 = ( (Object_Obj* )Str_gen_12); 
	Object_Nothing* Nothing_gen_4 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_4 = (* Obj_gen_4->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_4);
	goto label_20_;
	}
// end code block
// If test
	label_27_:;
	label_28_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_14 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_15 = NULL; // Default New Var reg of type: Str
	Str_gen_15 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_15->_string_value = "If 2 Nested 3";
Str_gen_14 = Str_gen_15; // generate method left exp complete.
	Object_Obj* Obj_gen_5 = NULL; // Default New Var reg of type: Obj
	Obj_gen_5 = ( (Object_Obj* )Str_gen_14); 
	Object_Nothing* Nothing_gen_5 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_5 = (* Obj_gen_5->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_5);
	goto label_20_;
	}
// end code block
	label_20_:;
// If Else List end. 
	goto label_0_;
	}
// end code block
// If test
	label_18_:;
	label_19_:;
// code block
	{
// If Else List Begin. 
// If test
	label_35_:;
	{
	Object_Boolean* Boolean_gen_24 = NULL; // Default New Var reg of type: Boolean
// Start Boolean Expression emit.
	Object_Boolean* Boolean_gen_25 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_26 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_27 = NULL; // Default New Var reg of type: Boolean
	{
/// L EXPRESSION OR begin.
// Generate Typed Value 
	Object_Boolean* Boolean_gen_28 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_28 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_28->_bool_value = 0;
	Boolean_gen_26 = Boolean_gen_28; // evaled left of OR expression.
	if (1==Boolean_gen_26->_bool_value)
	{
		Boolean_gen_25 = Boolean_gen_26;
		 goto label_37_; 
	}
	else
	{
		 goto label_38_; 
	}
	label_38_:;
/// R expression OR begin.
	{
// Generate Typed Value 
	Object_Boolean* Boolean_gen_29 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_29 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_29->_bool_value = 1;
		Boolean_gen_25 = Boolean_gen_29; // evaled right of OR expression.
	goto label_37_;
	}
// end OR short circuit.
	label_37_:;
	}
		Boolean_gen_24 = Boolean_gen_25;
		if (1==Boolean_gen_24->_bool_value)
		{
			 goto label_34_; 
		}
		else
		{
			 goto label_36_; 
		}
	}
	label_34_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_16 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_17 = NULL; // Default New Var reg of type: Str
	Str_gen_17 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_17->_string_value = "If 3 Nested 1";
Str_gen_16 = Str_gen_17; // generate method left exp complete.
	Object_Obj* Obj_gen_6 = NULL; // Default New Var reg of type: Obj
	Obj_gen_6 = ( (Object_Obj* )Str_gen_16); 
	Object_Nothing* Nothing_gen_6 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_6 = (* Obj_gen_6->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_6);
	goto label_33_;
	}
// end code block
// If test
	label_36_:;
	{
	Object_Boolean* Boolean_gen_30 = NULL; // Default New Var reg of type: Boolean
	Object_Int* Int_gen_8 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_9 = NULL; // Default New Var reg of type: Int
	Int_gen_9 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_9->_int_value = 10;
// After Left Math Eval.
	Int_gen_8 = Int_gen_9; // evaled left of expression.
	Object_Int* Int_gen_10 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_11 = NULL; // Default New Var reg of type: Int
	Int_gen_11 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_11->_int_value = 3;
// After Right  Math Eval.
	Int_gen_10 = Int_gen_11; // evaled right of expression.
	Object_Boolean* Boolean_gen_31 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_31 = (*Int_gen_8->_class_pointer->Class_Int_Method_MORE)(Int_gen_8, Int_gen_10);
		Boolean_gen_30 = Boolean_gen_31;
		if (1==Boolean_gen_30->_bool_value)
		{
			 goto label_39_; 
		}
		else
		{
			 goto label_40_; 
		}
	}
	label_39_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_18 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_19 = NULL; // Default New Var reg of type: Str
	Str_gen_19 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_19->_string_value = "If 3 Nested 2";
Str_gen_18 = Str_gen_19; // generate method left exp complete.
	Object_Obj* Obj_gen_7 = NULL; // Default New Var reg of type: Obj
	Obj_gen_7 = ( (Object_Obj* )Str_gen_18); 
	Object_Nothing* Nothing_gen_7 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_7 = (* Obj_gen_7->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_7);
	goto label_33_;
	}
// end code block
// If test
	label_40_:;
	label_41_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_20 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_21 = NULL; // Default New Var reg of type: Str
	Str_gen_21 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_21->_string_value = "If 3 Nested 3";
Str_gen_20 = Str_gen_21; // generate method left exp complete.
	Object_Obj* Obj_gen_8 = NULL; // Default New Var reg of type: Obj
	Obj_gen_8 = ( (Object_Obj* )Str_gen_20); 
	Object_Nothing* Nothing_gen_8 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_8 = (* Obj_gen_8->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_8);
	goto label_33_;
	}
// end code block
	label_33_:;
// If Else List end. 
	goto label_0_;
	}
// end code block
	label_0_:;
// If Else List end. 

}

int main(int argc, char * argv[])
{
	GLOBAL_Class_Obj.Class_Obj_Method_Obj=Class_Obj_Method_Obj;
	GLOBAL_Class_Obj.Class_Obj_Method_STR=Class_Obj_Method_STR;
	GLOBAL_Class_Obj.Class_Obj_Method_PRINT=Class_Obj_Method_PRINT;
	GLOBAL_Class_Nothing.Class_Nothing_Method_Nothing=Class_Nothing_Method_Nothing;
	GLOBAL_Class_Nothing.Class_Nothing_Method_STR=Class_Nothing_Method_STR;
	GLOBAL_Class_Nothing.Class_Obj_Method_PRINT=Class_Obj_Method_PRINT;
	GLOBAL_Class_Str.Class_Str_Method_Str=Class_Str_Method_Str;
	GLOBAL_Class_Str.Class_Str_Method_STR=Class_Str_Method_STR;
	GLOBAL_Class_Str.Class_Obj_Method_PRINT=Class_Obj_Method_PRINT;
	GLOBAL_Class_Str.Class_Str_Method_PLUS=Class_Str_Method_PLUS;
	GLOBAL_Class_Str.Class_Str_Method_READ=Class_Str_Method_READ;
	GLOBAL_Class_Str.Class_Str_Method_EQUALS=Class_Str_Method_EQUALS;
	GLOBAL_Class_Int.Class_Int_Method_Int=Class_Int_Method_Int;
	GLOBAL_Class_Int.Class_Int_Method_STR=Class_Int_Method_STR;
	GLOBAL_Class_Int.Class_Obj_Method_PRINT=Class_Obj_Method_PRINT;
	GLOBAL_Class_Int.Class_Int_Method_PLUS=Class_Int_Method_PLUS;
	GLOBAL_Class_Int.Class_Int_Method_MINUS=Class_Int_Method_MINUS;
	GLOBAL_Class_Int.Class_Int_Method_TIMES=Class_Int_Method_TIMES;
	GLOBAL_Class_Int.Class_Int_Method_DIVIDE=Class_Int_Method_DIVIDE;
	GLOBAL_Class_Int.Class_Int_Method_READ=Class_Int_Method_READ;
	GLOBAL_Class_Int.Class_Int_Method_ATMOST=Class_Int_Method_ATMOST;
	GLOBAL_Class_Int.Class_Int_Method_ATLEAST=Class_Int_Method_ATLEAST;
	GLOBAL_Class_Int.Class_Int_Method_MORE=Class_Int_Method_MORE;
	GLOBAL_Class_Int.Class_Int_Method_LESS=Class_Int_Method_LESS;
	GLOBAL_Class_Int.Class_Int_Method_EQUALS=Class_Int_Method_EQUALS;
	GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean=Class_Boolean_Method_Boolean;
	GLOBAL_Class_Boolean.Class_Boolean_Method_STR=Class_Boolean_Method_STR;
	GLOBAL_Class_Boolean.Class_Obj_Method_PRINT=Class_Obj_Method_PRINT;
	GLOBAL_Class_Boolean.Class_Boolean_Method_EQUALS=Class_Boolean_Method_EQUALS;
	GLOBAL_Class_Boolean.Class_Boolean_Method_AND=Class_Boolean_Method_AND;
	GLOBAL_Class_Boolean.Class_Boolean_Method_OR=Class_Boolean_Method_OR;
	GLOBAL_Class_Boolean.Class_Boolean_Method_NOT=Class_Boolean_Method_NOT;
	class_MAIN_method_MAIN();
	return 0;
}
