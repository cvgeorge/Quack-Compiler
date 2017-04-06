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
	Object_Int* Int_gen_0 = NULL; // Default New Var reg of type: Int
	Object_Boolean* Boolean_gen_0 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_1 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_2 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_3 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_4 = NULL; // Default New Var reg of type: Boolean
	Object_Int* Int_gen_1 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_2 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_3 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_4 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_5 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_6 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
// Generate Typed Value 
	Object_Int* Int_gen_7 = NULL; // Default New Var reg of type: Int
	Int_gen_7 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_7->_int_value = 10;
	Int_gen_6 = Int_gen_7 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Int* Int_gen_8 = NULL; // Default New Var reg of type: Int
	Int_gen_8 = ( (Object_Int* )Int_gen_6); 
	 // Assigning var number1 to Int_gen_8
	Int_gen_2 = Int_gen_8;
// End Assignment Statment
	Object_Int* Int_gen_9 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
// Generate Typed Value 
	Object_Int* Int_gen_10 = NULL; // Default New Var reg of type: Int
	Int_gen_10 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_10->_int_value = 5;
	Int_gen_9 = Int_gen_10 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Int* Int_gen_11 = NULL; // Default New Var reg of type: Int
	Int_gen_11 = ( (Object_Int* )Int_gen_9); 
	 // Assigning var number2 to Int_gen_11
	Int_gen_3 = Int_gen_11;
// End Assignment Statment
	Object_Int* Int_gen_12 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_13 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_14 = NULL; // Default New Var reg of type: Int
	Int_gen_14 = ( (Object_Int* )Int_gen_2); 
// Setting variable Int_gen_2 to the new value
	Int_gen_2 = Int_gen_14;
// After Left Math Eval.
	Int_gen_13 = Int_gen_14; // evaled left of expression.
	Object_Int* Int_gen_15 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_16 = NULL; // Default New Var reg of type: Int
	Int_gen_16 = ( (Object_Int* )Int_gen_3); 
// Setting variable Int_gen_3 to the new value
	Int_gen_3 = Int_gen_16;
// After Right  Math Eval.
	Int_gen_15 = Int_gen_16; // evaled right of expression.
	Object_Int* Int_gen_17 = NULL; // Default New Var reg of type: Int
	Int_gen_17 = (*Int_gen_13->_class_pointer->Class_Int_Method_PLUS)(Int_gen_13, Int_gen_15);
	Int_gen_12 = Int_gen_17 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Int* Int_gen_18 = NULL; // Default New Var reg of type: Int
	Int_gen_18 = ( (Object_Int* )Int_gen_12); 
	 // Assigning var plus_val to Int_gen_18
	Int_gen_4 = Int_gen_18;
// End Assignment Statment
	Object_Int* Int_gen_19 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_20 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_21 = NULL; // Default New Var reg of type: Int
	Int_gen_21 = ( (Object_Int* )Int_gen_2); 
// Setting variable Int_gen_2 to the new value
	Int_gen_2 = Int_gen_21;
// After Left Math Eval.
	Int_gen_20 = Int_gen_21; // evaled left of expression.
	Object_Int* Int_gen_22 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_23 = NULL; // Default New Var reg of type: Int
	Int_gen_23 = ( (Object_Int* )Int_gen_3); 
// Setting variable Int_gen_3 to the new value
	Int_gen_3 = Int_gen_23;
// After Right  Math Eval.
	Int_gen_22 = Int_gen_23; // evaled right of expression.
	Object_Int* Int_gen_24 = NULL; // Default New Var reg of type: Int
	Int_gen_24 = (*Int_gen_20->_class_pointer->Class_Int_Method_MINUS)(Int_gen_20, Int_gen_22);
	Int_gen_19 = Int_gen_24 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Int* Int_gen_25 = NULL; // Default New Var reg of type: Int
	Int_gen_25 = ( (Object_Int* )Int_gen_19); 
	 // Assigning var minus_val to Int_gen_25
	Int_gen_1 = Int_gen_25;
// End Assignment Statment
	Object_Int* Int_gen_26 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_27 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_28 = NULL; // Default New Var reg of type: Int
	Int_gen_28 = ( (Object_Int* )Int_gen_2); 
// Setting variable Int_gen_2 to the new value
	Int_gen_2 = Int_gen_28;
// After Left Math Eval.
	Int_gen_27 = Int_gen_28; // evaled left of expression.
	Object_Int* Int_gen_29 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_30 = NULL; // Default New Var reg of type: Int
	Int_gen_30 = ( (Object_Int* )Int_gen_3); 
// Setting variable Int_gen_3 to the new value
	Int_gen_3 = Int_gen_30;
// After Right  Math Eval.
	Int_gen_29 = Int_gen_30; // evaled right of expression.
	Object_Int* Int_gen_31 = NULL; // Default New Var reg of type: Int
	Int_gen_31 = (*Int_gen_27->_class_pointer->Class_Int_Method_TIMES)(Int_gen_27, Int_gen_29);
	Int_gen_26 = Int_gen_31 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Int* Int_gen_32 = NULL; // Default New Var reg of type: Int
	Int_gen_32 = ( (Object_Int* )Int_gen_26); 
	 // Assigning var times_val to Int_gen_32
	Int_gen_5 = Int_gen_32;
// End Assignment Statment
	Object_Int* Int_gen_33 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_34 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_35 = NULL; // Default New Var reg of type: Int
	Int_gen_35 = ( (Object_Int* )Int_gen_2); 
// Setting variable Int_gen_2 to the new value
	Int_gen_2 = Int_gen_35;
// After Left Math Eval.
	Int_gen_34 = Int_gen_35; // evaled left of expression.
	Object_Int* Int_gen_36 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_37 = NULL; // Default New Var reg of type: Int
	Int_gen_37 = ( (Object_Int* )Int_gen_3); 
// Setting variable Int_gen_3 to the new value
	Int_gen_3 = Int_gen_37;
// After Right  Math Eval.
	Int_gen_36 = Int_gen_37; // evaled right of expression.
	Object_Int* Int_gen_38 = NULL; // Default New Var reg of type: Int
	Int_gen_38 = (*Int_gen_34->_class_pointer->Class_Int_Method_DIVIDE)(Int_gen_34, Int_gen_36);
	Int_gen_33 = Int_gen_38 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Int* Int_gen_39 = NULL; // Default New Var reg of type: Int
	Int_gen_39 = ( (Object_Int* )Int_gen_33); 
	 // Assigning var divide_val to Int_gen_39
	Int_gen_0 = Int_gen_39;
// End Assignment Statment
	Object_Boolean* Boolean_gen_5 = NULL; // Default New Var reg of type: Boolean
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_40 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_41 = NULL; // Default New Var reg of type: Int
	Int_gen_41 = ( (Object_Int* )Int_gen_2); 
// Setting variable Int_gen_2 to the new value
	Int_gen_2 = Int_gen_41;
// After Left Math Eval.
	Int_gen_40 = Int_gen_41; // evaled left of expression.
	Object_Int* Int_gen_42 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_43 = NULL; // Default New Var reg of type: Int
	Int_gen_43 = ( (Object_Int* )Int_gen_3); 
// Setting variable Int_gen_3 to the new value
	Int_gen_3 = Int_gen_43;
// After Right  Math Eval.
	Int_gen_42 = Int_gen_43; // evaled right of expression.
	Object_Boolean* Boolean_gen_6 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_6 = (*Int_gen_40->_class_pointer->Class_Int_Method_MORE)(Int_gen_40, Int_gen_42);
	Boolean_gen_5 = Boolean_gen_6 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Boolean* Boolean_gen_7 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_7 = ( (Object_Boolean* )Boolean_gen_5); 
	 // Assigning var greater_val to Boolean_gen_7
	Boolean_gen_2 = Boolean_gen_7;
// End Assignment Statment
	Object_Boolean* Boolean_gen_8 = NULL; // Default New Var reg of type: Boolean
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_44 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_45 = NULL; // Default New Var reg of type: Int
	Int_gen_45 = ( (Object_Int* )Int_gen_2); 
// Setting variable Int_gen_2 to the new value
	Int_gen_2 = Int_gen_45;
// After Left Math Eval.
	Int_gen_44 = Int_gen_45; // evaled left of expression.
	Object_Int* Int_gen_46 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_47 = NULL; // Default New Var reg of type: Int
	Int_gen_47 = ( (Object_Int* )Int_gen_3); 
// Setting variable Int_gen_3 to the new value
	Int_gen_3 = Int_gen_47;
// After Right  Math Eval.
	Int_gen_46 = Int_gen_47; // evaled right of expression.
	Object_Boolean* Boolean_gen_9 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_9 = (*Int_gen_44->_class_pointer->Class_Int_Method_ATLEAST)(Int_gen_44, Int_gen_46);
	Boolean_gen_8 = Boolean_gen_9 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Boolean* Boolean_gen_10 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_10 = ( (Object_Boolean* )Boolean_gen_8); 
	 // Assigning var greater_equal_val to Boolean_gen_10
	Boolean_gen_1 = Boolean_gen_10;
// End Assignment Statment
	Object_Boolean* Boolean_gen_11 = NULL; // Default New Var reg of type: Boolean
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_48 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_49 = NULL; // Default New Var reg of type: Int
	Int_gen_49 = ( (Object_Int* )Int_gen_2); 
// Setting variable Int_gen_2 to the new value
	Int_gen_2 = Int_gen_49;
// After Left Math Eval.
	Int_gen_48 = Int_gen_49; // evaled left of expression.
	Object_Int* Int_gen_50 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_51 = NULL; // Default New Var reg of type: Int
	Int_gen_51 = ( (Object_Int* )Int_gen_3); 
// Setting variable Int_gen_3 to the new value
	Int_gen_3 = Int_gen_51;
// After Right  Math Eval.
	Int_gen_50 = Int_gen_51; // evaled right of expression.
	Object_Boolean* Boolean_gen_12 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_12 = (*Int_gen_48->_class_pointer->Class_Int_Method_LESS)(Int_gen_48, Int_gen_50);
	Boolean_gen_11 = Boolean_gen_12 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Boolean* Boolean_gen_13 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_13 = ( (Object_Boolean* )Boolean_gen_11); 
	 // Assigning var less_val to Boolean_gen_13
	Boolean_gen_4 = Boolean_gen_13;
// End Assignment Statment
	Object_Boolean* Boolean_gen_14 = NULL; // Default New Var reg of type: Boolean
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_52 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_53 = NULL; // Default New Var reg of type: Int
	Int_gen_53 = ( (Object_Int* )Int_gen_2); 
// Setting variable Int_gen_2 to the new value
	Int_gen_2 = Int_gen_53;
// After Left Math Eval.
	Int_gen_52 = Int_gen_53; // evaled left of expression.
	Object_Int* Int_gen_54 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_55 = NULL; // Default New Var reg of type: Int
	Int_gen_55 = ( (Object_Int* )Int_gen_3); 
// Setting variable Int_gen_3 to the new value
	Int_gen_3 = Int_gen_55;
// After Right  Math Eval.
	Int_gen_54 = Int_gen_55; // evaled right of expression.
	Object_Boolean* Boolean_gen_15 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_15 = (*Int_gen_52->_class_pointer->Class_Int_Method_ATMOST)(Int_gen_52, Int_gen_54);
	Boolean_gen_14 = Boolean_gen_15 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Boolean* Boolean_gen_16 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_16 = ( (Object_Boolean* )Boolean_gen_14); 
	 // Assigning var less_equal_val to Boolean_gen_16
	Boolean_gen_3 = Boolean_gen_16;
// End Assignment Statment
	Object_Boolean* Boolean_gen_17 = NULL; // Default New Var reg of type: Boolean
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_56 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_57 = NULL; // Default New Var reg of type: Int
	Int_gen_57 = ( (Object_Int* )Int_gen_2); 
// Setting variable Int_gen_2 to the new value
	Int_gen_2 = Int_gen_57;
// After Left Math Eval.
	Int_gen_56 = Int_gen_57; // evaled left of expression.
	Object_Int* Int_gen_58 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_59 = NULL; // Default New Var reg of type: Int
	Int_gen_59 = ( (Object_Int* )Int_gen_3); 
// Setting variable Int_gen_3 to the new value
	Int_gen_3 = Int_gen_59;
// After Right  Math Eval.
	Int_gen_58 = Int_gen_59; // evaled right of expression.
	Object_Boolean* Boolean_gen_18 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_18 = (*Int_gen_56->_class_pointer->Class_Int_Method_EQUALS)(Int_gen_56, Int_gen_58);
	Boolean_gen_17 = Boolean_gen_18 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Boolean* Boolean_gen_19 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_19 = ( (Object_Boolean* )Boolean_gen_17); 
	 // Assigning var equal_val to Boolean_gen_19
	Boolean_gen_0 = Boolean_gen_19;
// End Assignment Statment
// Begin Method Call Generation .
	Object_Int* Int_gen_60 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_61 = NULL; // Default New Var reg of type: Int
	Int_gen_61 = ( (Object_Int* )Int_gen_4); 
// Setting variable Int_gen_4 to the new value
	Int_gen_4 = Int_gen_61;
Int_gen_60 = Int_gen_61; // generate method left exp complete.
	Object_Obj* Obj_gen_0 = NULL; // Default New Var reg of type: Obj
	Obj_gen_0 = ( (Object_Obj* )Int_gen_60); 
	Object_Nothing* Nothing_gen_0 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_0 = (* Obj_gen_0->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_0);
// Begin Method Call Generation .
	Object_Int* Int_gen_62 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_63 = NULL; // Default New Var reg of type: Int
	Int_gen_63 = ( (Object_Int* )Int_gen_1); 
// Setting variable Int_gen_1 to the new value
	Int_gen_1 = Int_gen_63;
Int_gen_62 = Int_gen_63; // generate method left exp complete.
	Object_Obj* Obj_gen_1 = NULL; // Default New Var reg of type: Obj
	Obj_gen_1 = ( (Object_Obj* )Int_gen_62); 
	Object_Nothing* Nothing_gen_1 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_1 = (* Obj_gen_1->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_1);
// Begin Method Call Generation .
	Object_Int* Int_gen_64 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_65 = NULL; // Default New Var reg of type: Int
	Int_gen_65 = ( (Object_Int* )Int_gen_5); 
// Setting variable Int_gen_5 to the new value
	Int_gen_5 = Int_gen_65;
Int_gen_64 = Int_gen_65; // generate method left exp complete.
	Object_Obj* Obj_gen_2 = NULL; // Default New Var reg of type: Obj
	Obj_gen_2 = ( (Object_Obj* )Int_gen_64); 
	Object_Nothing* Nothing_gen_2 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_2 = (* Obj_gen_2->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_2);
// Begin Method Call Generation .
	Object_Int* Int_gen_66 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_67 = NULL; // Default New Var reg of type: Int
	Int_gen_67 = ( (Object_Int* )Int_gen_0); 
// Setting variable Int_gen_0 to the new value
	Int_gen_0 = Int_gen_67;
Int_gen_66 = Int_gen_67; // generate method left exp complete.
	Object_Obj* Obj_gen_3 = NULL; // Default New Var reg of type: Obj
	Obj_gen_3 = ( (Object_Obj* )Int_gen_66); 
	Object_Nothing* Nothing_gen_3 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_3 = (* Obj_gen_3->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_3);
// Begin Method Call Generation .
	Object_Boolean* Boolean_gen_20 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_21 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_21 = ( (Object_Boolean* )Boolean_gen_2); 
// Setting variable Boolean_gen_2 to the new value
	Boolean_gen_2 = Boolean_gen_21;
Boolean_gen_20 = Boolean_gen_21; // generate method left exp complete.
	Object_Obj* Obj_gen_4 = NULL; // Default New Var reg of type: Obj
	Obj_gen_4 = ( (Object_Obj* )Boolean_gen_20); 
	Object_Nothing* Nothing_gen_4 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_4 = (* Obj_gen_4->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_4);
// Begin Method Call Generation .
	Object_Boolean* Boolean_gen_22 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_23 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_23 = ( (Object_Boolean* )Boolean_gen_1); 
// Setting variable Boolean_gen_1 to the new value
	Boolean_gen_1 = Boolean_gen_23;
Boolean_gen_22 = Boolean_gen_23; // generate method left exp complete.
	Object_Obj* Obj_gen_5 = NULL; // Default New Var reg of type: Obj
	Obj_gen_5 = ( (Object_Obj* )Boolean_gen_22); 
	Object_Nothing* Nothing_gen_5 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_5 = (* Obj_gen_5->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_5);
// Begin Method Call Generation .
	Object_Boolean* Boolean_gen_24 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_25 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_25 = ( (Object_Boolean* )Boolean_gen_4); 
// Setting variable Boolean_gen_4 to the new value
	Boolean_gen_4 = Boolean_gen_25;
Boolean_gen_24 = Boolean_gen_25; // generate method left exp complete.
	Object_Obj* Obj_gen_6 = NULL; // Default New Var reg of type: Obj
	Obj_gen_6 = ( (Object_Obj* )Boolean_gen_24); 
	Object_Nothing* Nothing_gen_6 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_6 = (* Obj_gen_6->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_6);
// Begin Method Call Generation .
	Object_Boolean* Boolean_gen_26 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_27 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_27 = ( (Object_Boolean* )Boolean_gen_3); 
// Setting variable Boolean_gen_3 to the new value
	Boolean_gen_3 = Boolean_gen_27;
Boolean_gen_26 = Boolean_gen_27; // generate method left exp complete.
	Object_Obj* Obj_gen_7 = NULL; // Default New Var reg of type: Obj
	Obj_gen_7 = ( (Object_Obj* )Boolean_gen_26); 
	Object_Nothing* Nothing_gen_7 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_7 = (* Obj_gen_7->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_7);
// Begin Method Call Generation .
	Object_Boolean* Boolean_gen_28 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_29 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_29 = ( (Object_Boolean* )Boolean_gen_0); 
// Setting variable Boolean_gen_0 to the new value
	Boolean_gen_0 = Boolean_gen_29;
Boolean_gen_28 = Boolean_gen_29; // generate method left exp complete.
	Object_Obj* Obj_gen_8 = NULL; // Default New Var reg of type: Obj
	Obj_gen_8 = ( (Object_Obj* )Boolean_gen_28); 
	Object_Nothing* Nothing_gen_8 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_8 = (* Obj_gen_8->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_8);

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
