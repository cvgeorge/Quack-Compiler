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
	Boolean_gen_5->_bool_value = 1;
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
			 goto label_0_; 
		}
	}
	label_1_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_0 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_1 = NULL; // Default New Var reg of type: Str
	Str_gen_1 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_1->_string_value = "true and true";
Str_gen_0 = Str_gen_1; // generate method left exp complete.
	Object_Obj* Obj_gen_0 = NULL; // Default New Var reg of type: Obj
	Obj_gen_0 = ( (Object_Obj* )Str_gen_0); 
	Object_Nothing* Nothing_gen_0 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_0 = (* Obj_gen_0->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_0);
	goto label_0_;
	}
// end code block
	label_0_:;
// If Else List end. 
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
/// L EXPRESSION AND begin.
// Generate Typed Value 
	Object_Boolean* Boolean_gen_10 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_10 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_10->_bool_value = 1;
	Boolean_gen_8 = Boolean_gen_10; // evaled left of AND expression.
	if (0==Boolean_gen_8->_bool_value)
	{
		Boolean_gen_7 = Boolean_gen_8;
		 goto label_11_; 
	}
	else
	{
		 goto label_12_; 
	}
	label_12_:;
/// R expression AND begin.
	{
// Generate Typed Value 
	Object_Boolean* Boolean_gen_11 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_11 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_11->_bool_value = 0;
		Boolean_gen_7 = Boolean_gen_11; // evaled right of AND expression.
	goto label_11_;
	}
// end AND short circuit.
	label_11_:;
	}
		Boolean_gen_6 = Boolean_gen_7;
		if (1==Boolean_gen_6->_bool_value)
		{
			 goto label_8_; 
		}
		else
		{
			 goto label_7_; 
		}
	}
	label_8_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_2 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_3 = NULL; // Default New Var reg of type: Str
	Str_gen_3 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_3->_string_value = "true and false";
Str_gen_2 = Str_gen_3; // generate method left exp complete.
	Object_Obj* Obj_gen_1 = NULL; // Default New Var reg of type: Obj
	Obj_gen_1 = ( (Object_Obj* )Str_gen_2); 
	Object_Nothing* Nothing_gen_1 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_1 = (* Obj_gen_1->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_1);
	goto label_7_;
	}
// end code block
	label_7_:;
// If Else List end. 
// If Else List Begin. 
// If test
	label_16_:;
	{
	Object_Boolean* Boolean_gen_12 = NULL; // Default New Var reg of type: Boolean
// Start Boolean Expression emit.
	Object_Boolean* Boolean_gen_13 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_14 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_15 = NULL; // Default New Var reg of type: Boolean
	{
/// L EXPRESSION AND begin.
// Generate Typed Value 
	Object_Boolean* Boolean_gen_16 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_16 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_16->_bool_value = 0;
	Boolean_gen_14 = Boolean_gen_16; // evaled left of AND expression.
	if (0==Boolean_gen_14->_bool_value)
	{
		Boolean_gen_13 = Boolean_gen_14;
		 goto label_18_; 
	}
	else
	{
		 goto label_19_; 
	}
	label_19_:;
/// R expression AND begin.
	{
// Generate Typed Value 
	Object_Boolean* Boolean_gen_17 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_17 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_17->_bool_value = 1;
		Boolean_gen_13 = Boolean_gen_17; // evaled right of AND expression.
	goto label_18_;
	}
// end AND short circuit.
	label_18_:;
	}
		Boolean_gen_12 = Boolean_gen_13;
		if (1==Boolean_gen_12->_bool_value)
		{
			 goto label_15_; 
		}
		else
		{
			 goto label_14_; 
		}
	}
	label_15_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_4 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_5 = NULL; // Default New Var reg of type: Str
	Str_gen_5 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_5->_string_value = "false and true";
Str_gen_4 = Str_gen_5; // generate method left exp complete.
	Object_Obj* Obj_gen_2 = NULL; // Default New Var reg of type: Obj
	Obj_gen_2 = ( (Object_Obj* )Str_gen_4); 
	Object_Nothing* Nothing_gen_2 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_2 = (* Obj_gen_2->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_2);
	goto label_14_;
	}
// end code block
	label_14_:;
// If Else List end. 
// If Else List Begin. 
// If test
	label_23_:;
	{
	Object_Boolean* Boolean_gen_18 = NULL; // Default New Var reg of type: Boolean
// Start Boolean Expression emit.
	Object_Boolean* Boolean_gen_19 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_20 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_21 = NULL; // Default New Var reg of type: Boolean
	{
/// L EXPRESSION AND begin.
// Generate Typed Value 
	Object_Boolean* Boolean_gen_22 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_22 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_22->_bool_value = 0;
	Boolean_gen_20 = Boolean_gen_22; // evaled left of AND expression.
	if (0==Boolean_gen_20->_bool_value)
	{
		Boolean_gen_19 = Boolean_gen_20;
		 goto label_25_; 
	}
	else
	{
		 goto label_26_; 
	}
	label_26_:;
/// R expression AND begin.
	{
// Generate Typed Value 
	Object_Boolean* Boolean_gen_23 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_23 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_23->_bool_value = 0;
		Boolean_gen_19 = Boolean_gen_23; // evaled right of AND expression.
	goto label_25_;
	}
// end AND short circuit.
	label_25_:;
	}
		Boolean_gen_18 = Boolean_gen_19;
		if (1==Boolean_gen_18->_bool_value)
		{
			 goto label_22_; 
		}
		else
		{
			 goto label_21_; 
		}
	}
	label_22_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_6 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_7 = NULL; // Default New Var reg of type: Str
	Str_gen_7 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_7->_string_value = "false and false";
Str_gen_6 = Str_gen_7; // generate method left exp complete.
	Object_Obj* Obj_gen_3 = NULL; // Default New Var reg of type: Obj
	Obj_gen_3 = ( (Object_Obj* )Str_gen_6); 
	Object_Nothing* Nothing_gen_3 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_3 = (* Obj_gen_3->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_3);
	goto label_21_;
	}
// end code block
	label_21_:;
// If Else List end. 
// If Else List Begin. 
// If test
	label_30_:;
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
	Boolean_gen_28->_bool_value = 1;
	Boolean_gen_26 = Boolean_gen_28; // evaled left of OR expression.
	if (1==Boolean_gen_26->_bool_value)
	{
		Boolean_gen_25 = Boolean_gen_26;
		 goto label_32_; 
	}
	else
	{
		 goto label_33_; 
	}
	label_33_:;
/// R expression OR begin.
	{
// Generate Typed Value 
	Object_Boolean* Boolean_gen_29 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_29 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_29->_bool_value = 1;
		Boolean_gen_25 = Boolean_gen_29; // evaled right of OR expression.
	goto label_32_;
	}
// end OR short circuit.
	label_32_:;
	}
		Boolean_gen_24 = Boolean_gen_25;
		if (1==Boolean_gen_24->_bool_value)
		{
			 goto label_29_; 
		}
		else
		{
			 goto label_28_; 
		}
	}
	label_29_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_8 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_9 = NULL; // Default New Var reg of type: Str
	Str_gen_9 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_9->_string_value = "true or true";
Str_gen_8 = Str_gen_9; // generate method left exp complete.
	Object_Obj* Obj_gen_4 = NULL; // Default New Var reg of type: Obj
	Obj_gen_4 = ( (Object_Obj* )Str_gen_8); 
	Object_Nothing* Nothing_gen_4 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_4 = (* Obj_gen_4->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_4);
	goto label_28_;
	}
// end code block
	label_28_:;
// If Else List end. 
// If Else List Begin. 
// If test
	label_37_:;
	{
	Object_Boolean* Boolean_gen_30 = NULL; // Default New Var reg of type: Boolean
// Start Boolean Expression emit.
	Object_Boolean* Boolean_gen_31 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_32 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_33 = NULL; // Default New Var reg of type: Boolean
	{
/// L EXPRESSION OR begin.
// Generate Typed Value 
	Object_Boolean* Boolean_gen_34 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_34 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_34->_bool_value = 1;
	Boolean_gen_32 = Boolean_gen_34; // evaled left of OR expression.
	if (1==Boolean_gen_32->_bool_value)
	{
		Boolean_gen_31 = Boolean_gen_32;
		 goto label_39_; 
	}
	else
	{
		 goto label_40_; 
	}
	label_40_:;
/// R expression OR begin.
	{
// Generate Typed Value 
	Object_Boolean* Boolean_gen_35 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_35 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_35->_bool_value = 0;
		Boolean_gen_31 = Boolean_gen_35; // evaled right of OR expression.
	goto label_39_;
	}
// end OR short circuit.
	label_39_:;
	}
		Boolean_gen_30 = Boolean_gen_31;
		if (1==Boolean_gen_30->_bool_value)
		{
			 goto label_36_; 
		}
		else
		{
			 goto label_35_; 
		}
	}
	label_36_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_10 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_11 = NULL; // Default New Var reg of type: Str
	Str_gen_11 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_11->_string_value = "true or false";
Str_gen_10 = Str_gen_11; // generate method left exp complete.
	Object_Obj* Obj_gen_5 = NULL; // Default New Var reg of type: Obj
	Obj_gen_5 = ( (Object_Obj* )Str_gen_10); 
	Object_Nothing* Nothing_gen_5 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_5 = (* Obj_gen_5->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_5);
	goto label_35_;
	}
// end code block
	label_35_:;
// If Else List end. 
// If Else List Begin. 
// If test
	label_44_:;
	{
	Object_Boolean* Boolean_gen_36 = NULL; // Default New Var reg of type: Boolean
// Start Boolean Expression emit.
	Object_Boolean* Boolean_gen_37 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_38 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_39 = NULL; // Default New Var reg of type: Boolean
	{
/// L EXPRESSION OR begin.
// Generate Typed Value 
	Object_Boolean* Boolean_gen_40 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_40 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_40->_bool_value = 0;
	Boolean_gen_38 = Boolean_gen_40; // evaled left of OR expression.
	if (1==Boolean_gen_38->_bool_value)
	{
		Boolean_gen_37 = Boolean_gen_38;
		 goto label_46_; 
	}
	else
	{
		 goto label_47_; 
	}
	label_47_:;
/// R expression OR begin.
	{
// Generate Typed Value 
	Object_Boolean* Boolean_gen_41 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_41 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_41->_bool_value = 1;
		Boolean_gen_37 = Boolean_gen_41; // evaled right of OR expression.
	goto label_46_;
	}
// end OR short circuit.
	label_46_:;
	}
		Boolean_gen_36 = Boolean_gen_37;
		if (1==Boolean_gen_36->_bool_value)
		{
			 goto label_43_; 
		}
		else
		{
			 goto label_42_; 
		}
	}
	label_43_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_12 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_13 = NULL; // Default New Var reg of type: Str
	Str_gen_13 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_13->_string_value = "false or true";
Str_gen_12 = Str_gen_13; // generate method left exp complete.
	Object_Obj* Obj_gen_6 = NULL; // Default New Var reg of type: Obj
	Obj_gen_6 = ( (Object_Obj* )Str_gen_12); 
	Object_Nothing* Nothing_gen_6 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_6 = (* Obj_gen_6->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_6);
	goto label_42_;
	}
// end code block
	label_42_:;
// If Else List end. 
// If Else List Begin. 
// If test
	label_51_:;
	{
	Object_Boolean* Boolean_gen_42 = NULL; // Default New Var reg of type: Boolean
// Start Boolean Expression emit.
	Object_Boolean* Boolean_gen_43 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_44 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_45 = NULL; // Default New Var reg of type: Boolean
	{
/// L EXPRESSION OR begin.
// Generate Typed Value 
	Object_Boolean* Boolean_gen_46 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_46 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_46->_bool_value = 0;
	Boolean_gen_44 = Boolean_gen_46; // evaled left of OR expression.
	if (1==Boolean_gen_44->_bool_value)
	{
		Boolean_gen_43 = Boolean_gen_44;
		 goto label_53_; 
	}
	else
	{
		 goto label_54_; 
	}
	label_54_:;
/// R expression OR begin.
	{
// Generate Typed Value 
	Object_Boolean* Boolean_gen_47 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_47 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_47->_bool_value = 0;
		Boolean_gen_43 = Boolean_gen_47; // evaled right of OR expression.
	goto label_53_;
	}
// end OR short circuit.
	label_53_:;
	}
		Boolean_gen_42 = Boolean_gen_43;
		if (1==Boolean_gen_42->_bool_value)
		{
			 goto label_50_; 
		}
		else
		{
			 goto label_49_; 
		}
	}
	label_50_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_14 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_15 = NULL; // Default New Var reg of type: Str
	Str_gen_15 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_15->_string_value = "false or false";
Str_gen_14 = Str_gen_15; // generate method left exp complete.
	Object_Obj* Obj_gen_7 = NULL; // Default New Var reg of type: Obj
	Obj_gen_7 = ( (Object_Obj* )Str_gen_14); 
	Object_Nothing* Nothing_gen_7 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_7 = (* Obj_gen_7->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_7);
	goto label_49_;
	}
// end code block
	label_49_:;
// If Else List end. 
// If Else List Begin. 
// If test
	label_58_:;
	{
	Object_Boolean* Boolean_gen_48 = NULL; // Default New Var reg of type: Boolean
// Start Boolean Expression emit.
	Object_Boolean* Boolean_gen_49 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_50 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_51 = NULL; // Default New Var reg of type: Boolean
	{
// Emitting NOT operator.
// Generate Typed Value 
	Object_Boolean* Boolean_gen_52 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_52 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_52->_bool_value = 0;
	Boolean_gen_51 = Boolean_gen_52 ; // right side NOT evaled.
	Boolean_gen_49 = (*Boolean_gen_51->_class_pointer->Class_Boolean_Method_NOT)(Boolean_gen_51);
// End NOT operator.
	goto label_60_;
	label_60_:;
	}
		Boolean_gen_48 = Boolean_gen_49;
		if (1==Boolean_gen_48->_bool_value)
		{
			 goto label_57_; 
		}
		else
		{
			 goto label_56_; 
		}
	}
	label_57_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_16 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_17 = NULL; // Default New Var reg of type: Str
	Str_gen_17 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_17->_string_value = "not false";
Str_gen_16 = Str_gen_17; // generate method left exp complete.
	Object_Obj* Obj_gen_8 = NULL; // Default New Var reg of type: Obj
	Obj_gen_8 = ( (Object_Obj* )Str_gen_16); 
	Object_Nothing* Nothing_gen_8 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_8 = (* Obj_gen_8->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_8);
	goto label_56_;
	}
// end code block
	label_56_:;
// If Else List end. 
// If Else List Begin. 
// If test
	label_65_:;
	{
	Object_Boolean* Boolean_gen_53 = NULL; // Default New Var reg of type: Boolean
// Start Boolean Expression emit.
	Object_Boolean* Boolean_gen_54 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_55 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_56 = NULL; // Default New Var reg of type: Boolean
	{
// Emitting NOT operator.
// Generate Typed Value 
	Object_Boolean* Boolean_gen_57 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_57 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_57->_bool_value = 1;
	Boolean_gen_56 = Boolean_gen_57 ; // right side NOT evaled.
	Boolean_gen_54 = (*Boolean_gen_56->_class_pointer->Class_Boolean_Method_NOT)(Boolean_gen_56);
// End NOT operator.
	goto label_67_;
	label_67_:;
	}
		Boolean_gen_53 = Boolean_gen_54;
		if (1==Boolean_gen_53->_bool_value)
		{
			 goto label_64_; 
		}
		else
		{
			 goto label_63_; 
		}
	}
	label_64_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_18 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_19 = NULL; // Default New Var reg of type: Str
	Str_gen_19 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_19->_string_value = "not true";
Str_gen_18 = Str_gen_19; // generate method left exp complete.
	Object_Obj* Obj_gen_9 = NULL; // Default New Var reg of type: Obj
	Obj_gen_9 = ( (Object_Obj* )Str_gen_18); 
	Object_Nothing* Nothing_gen_9 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_9 = (* Obj_gen_9->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_9);
	goto label_63_;
	}
// end code block
	label_63_:;
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
