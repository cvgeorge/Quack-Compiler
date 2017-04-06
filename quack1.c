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
typedef struct Class_Pt Class_Pt;
typedef struct Object_Pt Object_Pt;
typedef struct Class_Top Class_Top;
typedef struct Object_Top Object_Top;
typedef struct Class_Treta Class_Treta;
typedef struct Object_Treta Object_Treta;
typedef struct Class_Middle Class_Middle;
typedef struct Object_Middle Object_Middle;
typedef struct Class_Bottom Class_Bottom;
typedef struct Object_Bottom Object_Bottom;

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

struct Class_Pt{
	Object_Pt* (*Class_Pt_Method_Pt)(Object_Int* xx, Object_Int* yy);
	Object_Str* (*Class_Pt_Method_STR)(Object_Pt* _this_ptr);
	Object_Nothing* (*Class_Obj_Method_PRINT)(Object_Obj* _this_ptr);
	Object_Nothing* (*Class_Pt_Method_anewtest)(Object_Pt* _this_ptr);
	Object_Pt* (*Class_Pt_Method_PLUS)(Object_Pt* _this_ptr, Object_Pt* other);
	Object_Int* (*Class_Pt_Method__x)(Object_Pt* _this_ptr);
	Object_Int* (*Class_Pt_Method__y)(Object_Pt* _this_ptr);
} ;

struct Object_Pt{
	Class_Pt *_class_pointer;
	Object_Int *x;
	Object_Int *y;
} ;

struct Class_Top{
	Object_Top* (*Class_Top_Method_Top)(Object_Int* x);
	Object_Str* (*Class_Obj_Method_STR)(Object_Obj* _this_ptr);
	Object_Nothing* (*Class_Obj_Method_PRINT)(Object_Obj* _this_ptr);
	Object_Int* (*Class_Top_Method_foo)(Object_Top* _this_ptr);
	Object_Top* (*Class_Top_Method_forever)(Object_Top* _this_ptr);
	Object_Int* (*Class_Top_Method_test)(Object_Top* _this_ptr);
} ;

struct Object_Top{
	Class_Top *_class_pointer;
	Object_Int *abc;
} ;

struct Class_Treta{
	Object_Treta* (*Class_Treta_Method_Treta)();
	Object_Str* (*Class_Obj_Method_STR)(Object_Obj* _this_ptr);
	Object_Nothing* (*Class_Obj_Method_PRINT)(Object_Obj* _this_ptr);
	Object_Obj* (*Class_Treta_Method_test3)(Object_Treta* _this_ptr);
	Object_Int* (*Class_Treta_Method_foo)(Object_Treta* _this_ptr);
	Object_Obj* (*Class_Treta_Method_test1)(Object_Treta* _this_ptr);
	Object_Obj* (*Class_Treta_Method_test2)(Object_Treta* _this_ptr);
} ;

struct Object_Treta{
	Class_Treta *_class_pointer;
	Object_Int *x;
	Object_Int *y;
	Object_Int *z;
} ;

struct Class_Middle{
	Object_Middle* (*Class_Middle_Method_Middle)(Object_Int* x, Object_Int* y);
	Object_Str* (*Class_Obj_Method_STR)(Object_Obj* _this_ptr);
	Object_Nothing* (*Class_Obj_Method_PRINT)(Object_Obj* _this_ptr);
	Object_Int* (*Class_Middle_Method_foo)(Object_Middle* _this_ptr);
	Object_Top* (*Class_Middle_Method_forever)(Object_Middle* _this_ptr);
	Object_Int* (*Class_Top_Method_test)(Object_Top* _this_ptr);
} ;

struct Object_Middle{
	Class_Middle *_class_pointer;
	Object_Int *abc;
	Object_Int *xyz;
} ;

struct Class_Bottom{
	Object_Bottom* (*Class_Bottom_Method_Bottom)(Object_Int* x, Object_Int* y, Object_Int* z);
	Object_Str* (*Class_Obj_Method_STR)(Object_Obj* _this_ptr);
	Object_Nothing* (*Class_Obj_Method_PRINT)(Object_Obj* _this_ptr);
	Object_Int* (*Class_Middle_Method_foo)(Object_Middle* _this_ptr);
	Object_Middle* (*Class_Bottom_Method_forever)(Object_Bottom* _this_ptr);
	Object_Int* (*Class_Top_Method_test)(Object_Top* _this_ptr);
	Object_Int* (*Class_Bottom_Method_bar)(Object_Bottom* _this_ptr);
	Object_Boolean* (*Class_Bottom_Method_boolTest)(Object_Bottom* _this_ptr);
	Object_Bottom* (*Class_Bottom_Method_RunAlways)(Object_Bottom* _this_ptr);
} ;

struct Object_Bottom{
	Class_Bottom *_class_pointer;
	Object_Int *abc;
	Object_Int *xyz;
	Object_Int *defer;
	Object_Int *test;
} ;

	Class_Obj	GLOBAL_Class_Obj;
	Class_Nothing	GLOBAL_Class_Nothing;
	Class_Str	GLOBAL_Class_Str;
	Class_Int	GLOBAL_Class_Int;
	Class_Boolean	GLOBAL_Class_Boolean;
	Class_Pt	GLOBAL_Class_Pt;
	Class_Top	GLOBAL_Class_Top;
	Class_Treta	GLOBAL_Class_Treta;
	Class_Middle	GLOBAL_Class_Middle;
	Class_Bottom	GLOBAL_Class_Bottom;


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

Object_Pt* Class_Pt_Method_Pt(Object_Int* xx, Object_Int* yy)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* Int_gen_0 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_1 = NULL; // Default New Var reg of type: Int
	Object_Pt * returnValue = (Object_Pt * )malloc(sizeof(Object_Pt));
	returnValue->_class_pointer = &GLOBAL_Class_Pt;
	Object_Int* Int_gen_2 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_3 = NULL; // Default New Var reg of type: Int
	Int_gen_3 = ( (Object_Int* )xx); 
// Setting variable xx to the new value
	xx = Int_gen_3;
	Int_gen_2 = Int_gen_3 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	returnValue->x = Int_gen_2; //store into this.
// End Assignment Statment
	Object_Int* Int_gen_4 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_5 = NULL; // Default New Var reg of type: Int
	Int_gen_5 = ( (Object_Int* )yy); 
// Setting variable yy to the new value
	yy = Int_gen_5;
	Int_gen_4 = Int_gen_5 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	returnValue->y = Int_gen_4; //store into this.
// End Assignment Statment
	return returnValue;

}

Object_Nothing* Class_Pt_Method_anewtest(Object_Pt* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// Generate return statement.
	Object_Nothing* Nothing_gen_0 = NULL; // Default New Var reg of type: Nothing
// Generate Typed Value 
	Object_Nothing* Nothing_gen_1 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_1 = (*GLOBAL_Class_Nothing.Class_Nothing_Method_Nothing)();
	Nothing_gen_0 = ((Object_Nothing* )Nothing_gen_1); // return value .
	Nothing_gen_0->_class_pointer= &GLOBAL_Class_Nothing;
	return Nothing_gen_0;

}

Object_Pt* Class_Pt_Method_PLUS(Object_Pt* _this_ptr, Object_Pt* other)
{
// Adding Arguments to the named map 
// allocating variables.
// Generate return statement.
	Object_Pt* Pt_gen_0 = NULL; // Default New Var reg of type: Pt
// Begin Method Call Generation .
	Object_Int* Int_gen_6 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_7 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_8 = NULL; // Default New Var reg of type: Int
	Int_gen_8 = _this_ptr->x;
// After Left Math Eval.
	Int_gen_7 = Int_gen_8; // evaled left of expression.
	Object_Int* Int_gen_9 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_10 = NULL; // Default New Var reg of type: Int
	Object_Pt* Pt_gen_1 = NULL; // Default New Var reg of type: Pt
	Object_Pt* Pt_gen_2 = NULL; // Default New Var reg of type: Pt
	Pt_gen_2 = ( (Object_Pt* )other); 
// Setting variable other to the new value
	other = Pt_gen_2;
	Pt_gen_1 = Pt_gen_2; // Evaluated expression
	Int_gen_10 = Pt_gen_1->x;
// After Right  Math Eval.
	Int_gen_9 = Int_gen_10; // evaled right of expression.
	Object_Int* Int_gen_11 = NULL; // Default New Var reg of type: Int
	Int_gen_11 = (*Int_gen_7->_class_pointer->Class_Int_Method_PLUS)(Int_gen_7, Int_gen_9);
	Int_gen_6 = Int_gen_11; // evaluated argument 
	Object_Int* Int_gen_12 = NULL; // Default New Var reg of type: Int
	Int_gen_12 = ( (Object_Int* )Int_gen_6); 
	Object_Int* Int_gen_13 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_14 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_15 = NULL; // Default New Var reg of type: Int
	Int_gen_15 = _this_ptr->y;
// After Left Math Eval.
	Int_gen_14 = Int_gen_15; // evaled left of expression.
	Object_Int* Int_gen_16 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_17 = NULL; // Default New Var reg of type: Int
	Object_Pt* Pt_gen_3 = NULL; // Default New Var reg of type: Pt
	Object_Pt* Pt_gen_4 = NULL; // Default New Var reg of type: Pt
	Pt_gen_4 = ( (Object_Pt* )other); 
// Setting variable other to the new value
	other = Pt_gen_4;
	Pt_gen_3 = Pt_gen_4; // Evaluated expression
	Int_gen_17 = Pt_gen_3->y;
// After Right  Math Eval.
	Int_gen_16 = Int_gen_17; // evaled right of expression.
	Object_Int* Int_gen_18 = NULL; // Default New Var reg of type: Int
	Int_gen_18 = (*Int_gen_14->_class_pointer->Class_Int_Method_PLUS)(Int_gen_14, Int_gen_16);
	Int_gen_13 = Int_gen_18; // evaluated argument 
	Object_Int* Int_gen_19 = NULL; // Default New Var reg of type: Int
	Int_gen_19 = ( (Object_Int* )Int_gen_13); 
	Object_Pt* Pt_gen_5 = NULL; // Default New Var reg of type: Pt
	Pt_gen_5 = (*GLOBAL_Class_Pt.Class_Pt_Method_Pt)(Int_gen_12,Int_gen_19);
	Pt_gen_0 = ((Object_Pt* )Pt_gen_5); // return value .
	Pt_gen_0->_class_pointer= &GLOBAL_Class_Pt;
	return Pt_gen_0;

}

Object_Int* Class_Pt_Method__x(Object_Pt* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// Generate return statement.
	Object_Int* Int_gen_20 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_21 = NULL; // Default New Var reg of type: Int
	Int_gen_21 = _this_ptr->x;
	Int_gen_20 = ((Object_Int* )Int_gen_21); // return value .
	Int_gen_20->_class_pointer= &GLOBAL_Class_Int;
	return Int_gen_20;

}

Object_Int* Class_Pt_Method__y(Object_Pt* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// Generate return statement.
	Object_Int* Int_gen_22 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_23 = NULL; // Default New Var reg of type: Int
	Int_gen_23 = _this_ptr->y;
	Int_gen_22 = ((Object_Int* )Int_gen_23); // return value .
	Int_gen_22->_class_pointer= &GLOBAL_Class_Int;
	return Int_gen_22;

}

Object_Str* Class_Pt_Method_STR(Object_Pt* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// Generate return statement.
	Object_Str* Str_gen_0 = NULL; // Default New Var reg of type: Str
	Object_Str* Str_gen_1 = NULL; // Default New Var reg of type: Str
// Before Left Math Eval.
	Object_Str* Str_gen_2 = NULL; // Default New Var reg of type: Str
// Before Left Math Eval.
	Object_Str* Str_gen_3 = NULL; // Default New Var reg of type: Str
// Before Left Math Eval.
// Generate Typed Value 
	Object_Str* Str_gen_4 = NULL; // Default New Var reg of type: Str
	Str_gen_4 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_4->_string_value = "X: ";
// After Left Math Eval.
	Str_gen_3 = Str_gen_4; // evaled left of expression.
	Object_Str* Str_gen_5 = NULL; // Default New Var reg of type: Str
// Before Right Math Eval.
// Begin Method Call Generation .
	Object_Int* Int_gen_24 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_25 = NULL; // Default New Var reg of type: Int
	Int_gen_25 = _this_ptr->x;
Int_gen_24 = Int_gen_25; // generate method left exp complete.
	Object_Int* Int_gen_26 = NULL; // Default New Var reg of type: Int
	Int_gen_26 = ( (Object_Int* )Int_gen_24); 
	Object_Str* Str_gen_6 = NULL; // Default New Var reg of type: Str
	Str_gen_6 = (* Int_gen_26->_class_pointer->Class_Int_Method_STR)(Int_gen_26);
// After Right  Math Eval.
	Str_gen_5 = Str_gen_6; // evaled right of expression.
	Object_Str* Str_gen_7 = NULL; // Default New Var reg of type: Str
	Str_gen_7 = (*Str_gen_3->_class_pointer->Class_Str_Method_PLUS)(Str_gen_3, Str_gen_5);
// After Left Math Eval.
	Str_gen_2 = Str_gen_7; // evaled left of expression.
	Object_Str* Str_gen_8 = NULL; // Default New Var reg of type: Str
// Before Right Math Eval.
// Generate Typed Value 
	Object_Str* Str_gen_9 = NULL; // Default New Var reg of type: Str
	Str_gen_9 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_9->_string_value = " Y: ";
// After Right  Math Eval.
	Str_gen_8 = Str_gen_9; // evaled right of expression.
	Object_Str* Str_gen_10 = NULL; // Default New Var reg of type: Str
	Str_gen_10 = (*Str_gen_2->_class_pointer->Class_Str_Method_PLUS)(Str_gen_2, Str_gen_8);
// After Left Math Eval.
	Str_gen_1 = Str_gen_10; // evaled left of expression.
	Object_Str* Str_gen_11 = NULL; // Default New Var reg of type: Str
// Before Right Math Eval.
// Begin Method Call Generation .
	Object_Int* Int_gen_27 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_28 = NULL; // Default New Var reg of type: Int
	Int_gen_28 = _this_ptr->y;
Int_gen_27 = Int_gen_28; // generate method left exp complete.
	Object_Int* Int_gen_29 = NULL; // Default New Var reg of type: Int
	Int_gen_29 = ( (Object_Int* )Int_gen_27); 
	Object_Str* Str_gen_12 = NULL; // Default New Var reg of type: Str
	Str_gen_12 = (* Int_gen_29->_class_pointer->Class_Int_Method_STR)(Int_gen_29);
// After Right  Math Eval.
	Str_gen_11 = Str_gen_12; // evaled right of expression.
	Object_Str* Str_gen_13 = NULL; // Default New Var reg of type: Str
	Str_gen_13 = (*Str_gen_1->_class_pointer->Class_Str_Method_PLUS)(Str_gen_1, Str_gen_11);
	Str_gen_0 = ((Object_Str* )Str_gen_13); // return value .
	Str_gen_0->_class_pointer= &GLOBAL_Class_Str;
	return Str_gen_0;

}

Object_Top* Class_Top_Method_Top(Object_Int* x)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* Int_gen_30 = NULL; // Default New Var reg of type: Int
	Object_Top * returnValue = (Object_Top * )malloc(sizeof(Object_Top));
	returnValue->_class_pointer = &GLOBAL_Class_Top;
// Begin Method Call Generation .
	Object_Str* Str_gen_14 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_15 = NULL; // Default New Var reg of type: Str
	Str_gen_15 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_15->_string_value = "class Top(x:Int)";
Str_gen_14 = Str_gen_15; // generate method left exp complete.
	Object_Obj* Obj_gen_0 = NULL; // Default New Var reg of type: Obj
	Obj_gen_0 = ( (Object_Obj* )Str_gen_14); 
	Object_Nothing* Nothing_gen_2 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_2 = (* Obj_gen_0->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_0);
	Object_Int* Int_gen_31 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_32 = NULL; // Default New Var reg of type: Int
	Int_gen_32 = ( (Object_Int* )x); 
// Setting variable x to the new value
	x = Int_gen_32;
	Int_gen_31 = Int_gen_32 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	returnValue->abc = Int_gen_31; //store into this.
// End Assignment Statment
	return returnValue;

}

Object_Int* Class_Top_Method_foo(Object_Top* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// Begin Method Call Generation .
	Object_Str* Str_gen_16 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_17 = NULL; // Default New Var reg of type: Str
	Str_gen_17 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_17->_string_value = "def Top foo():Int";
Str_gen_16 = Str_gen_17; // generate method left exp complete.
	Object_Obj* Obj_gen_1 = NULL; // Default New Var reg of type: Obj
	Obj_gen_1 = ( (Object_Obj* )Str_gen_16); 
	Object_Nothing* Nothing_gen_3 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_3 = (* Obj_gen_1->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_1);
// Generate return statement.
	Object_Int* Int_gen_33 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_34 = NULL; // Default New Var reg of type: Int
	Int_gen_34 = _this_ptr->abc;
	Int_gen_33 = ((Object_Int* )Int_gen_34); // return value .
	Int_gen_33->_class_pointer= &GLOBAL_Class_Int;
	return Int_gen_33;

}

Object_Top* Class_Top_Method_forever(Object_Top* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* Int_gen_35 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_36 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_37 = NULL; // Default New Var reg of type: Int
	Int_gen_37 = _this_ptr->abc;
// After Left Math Eval.
	Int_gen_36 = Int_gen_37; // evaled left of expression.
	Object_Int* Int_gen_38 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_39 = NULL; // Default New Var reg of type: Int
	Int_gen_39 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_39->_int_value = 1;
// After Right  Math Eval.
	Int_gen_38 = Int_gen_39; // evaled right of expression.
	Object_Int* Int_gen_40 = NULL; // Default New Var reg of type: Int
	Int_gen_40 = (*Int_gen_36->_class_pointer->Class_Int_Method_MINUS)(Int_gen_36, Int_gen_38);
	Int_gen_35 = Int_gen_40 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	_this_ptr->abc = Int_gen_35; //store into this.
// End Assignment Statment
// Begin Method Call Generation .
	Object_Str* Str_gen_18 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_19 = NULL; // Default New Var reg of type: Str
	Str_gen_19 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_19->_string_value = "forever in () TOP!";
Str_gen_18 = Str_gen_19; // generate method left exp complete.
	Object_Obj* Obj_gen_2 = NULL; // Default New Var reg of type: Obj
	Obj_gen_2 = ( (Object_Obj* )Str_gen_18); 
	Object_Nothing* Nothing_gen_4 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_4 = (* Obj_gen_2->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_2);
// Generate return statement.
	Object_Top* Top_gen_0 = NULL; // Default New Var reg of type: Top
	Object_Top* Top_gen_1 = NULL; // Default New Var reg of type: Top
	Top_gen_1 =( (Object_Top* )_this_ptr);
	Top_gen_0 = ((Object_Top* )Top_gen_1); // return value .
	Top_gen_0->_class_pointer= &GLOBAL_Class_Top;
	return Top_gen_0;

}

Object_Int* Class_Top_Method_test(Object_Top* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// Generate return statement.
	Object_Int* Int_gen_41 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_42 = NULL; // Default New Var reg of type: Int
	Int_gen_42 = _this_ptr->abc;
	Int_gen_41 = ((Object_Int* )Int_gen_42); // return value .
	Int_gen_41->_class_pointer= &GLOBAL_Class_Int;
	return Int_gen_41;

}

Object_Treta* Class_Treta_Method_Treta()
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* Int_gen_43 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_44 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_45 = NULL; // Default New Var reg of type: Int
	Object_Treta * returnValue = (Object_Treta * )malloc(sizeof(Object_Treta));
	returnValue->_class_pointer = &GLOBAL_Class_Treta;
	Object_Int* Int_gen_46 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
// Generate Typed Value 
	Object_Int* Int_gen_47 = NULL; // Default New Var reg of type: Int
	Int_gen_47 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_47->_int_value = 5;
	Int_gen_46 = Int_gen_47 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	returnValue->x = Int_gen_46; //store into this.
// End Assignment Statment
	Object_Int* Int_gen_48 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
// Generate Typed Value 
	Object_Int* Int_gen_49 = NULL; // Default New Var reg of type: Int
	Int_gen_49 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_49->_int_value = 0;
	Int_gen_48 = Int_gen_49 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	returnValue->z = Int_gen_48; //store into this.
// End Assignment Statment
	Object_Int* Int_gen_50 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
// Generate Typed Value 
	Object_Int* Int_gen_51 = NULL; // Default New Var reg of type: Int
	Int_gen_51 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_51->_int_value = 1;
	Int_gen_50 = Int_gen_51 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	returnValue->y = Int_gen_50; //store into this.
// End Assignment Statment
	return returnValue;

}

Object_Obj* Class_Treta_Method_test3(Object_Treta* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// If Else List Begin. 
// If test
	label_2_:;
	{
	Object_Boolean* Boolean_gen_0 = NULL; // Default New Var reg of type: Boolean
	Object_Int* Int_gen_52 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_53 = NULL; // Default New Var reg of type: Int
	Int_gen_53 = _this_ptr->x;
// After Left Math Eval.
	Int_gen_52 = Int_gen_53; // evaled left of expression.
	Object_Int* Int_gen_54 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_55 = NULL; // Default New Var reg of type: Int
	Int_gen_55 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_55->_int_value = 10;
// After Right  Math Eval.
	Int_gen_54 = Int_gen_55; // evaled right of expression.
	Object_Boolean* Boolean_gen_1 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_1 = (*Int_gen_52->_class_pointer->Class_Int_Method_LESS)(Int_gen_52, Int_gen_54);
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
// Generate return statement.
	Object_Obj* Obj_gen_3 = NULL; // Default New Var reg of type: Obj
// Generate Typed Value 
	Object_Boolean* Boolean_gen_2 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_2 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_2->_bool_value = 0;
	Obj_gen_3 = ((Object_Obj* )Boolean_gen_2); // return value .
	Obj_gen_3->_class_pointer= &GLOBAL_Class_Obj;
	return Obj_gen_3;
	goto label_0_;
	}
// end code block
// If test
	label_3_:;
	{
	Object_Boolean* Boolean_gen_3 = NULL; // Default New Var reg of type: Boolean
	Object_Int* Int_gen_56 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_57 = NULL; // Default New Var reg of type: Int
	Int_gen_57 = _this_ptr->z;
// After Left Math Eval.
	Int_gen_56 = Int_gen_57; // evaled left of expression.
	Object_Int* Int_gen_58 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_59 = NULL; // Default New Var reg of type: Int
	Int_gen_59 = _this_ptr->z;
// After Right  Math Eval.
	Int_gen_58 = Int_gen_59; // evaled right of expression.
	Object_Boolean* Boolean_gen_4 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_4 = (*Int_gen_56->_class_pointer->Class_Int_Method_EQUALS)(Int_gen_56, Int_gen_58);
		Boolean_gen_3 = Boolean_gen_4;
		if (1==Boolean_gen_3->_bool_value)
		{
			 goto label_4_; 
		}
		else
		{
			 goto label_5_; 
		}
	}
	label_4_:;
// code block
	{
// Generate return statement.
	Object_Obj* Obj_gen_4 = NULL; // Default New Var reg of type: Obj
// Generate Typed Value 
	Object_Int* Int_gen_60 = NULL; // Default New Var reg of type: Int
	Int_gen_60 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_60->_int_value = 5;
	Obj_gen_4 = ((Object_Obj* )Int_gen_60); // return value .
	Obj_gen_4->_class_pointer= &GLOBAL_Class_Obj;
	return Obj_gen_4;
	goto label_0_;
	}
// end code block
// If test
	label_5_:;
	{
	Object_Boolean* Boolean_gen_5 = NULL; // Default New Var reg of type: Boolean
	Object_Int* Int_gen_61 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_62 = NULL; // Default New Var reg of type: Int
	Int_gen_62 = _this_ptr->y;
// After Left Math Eval.
	Int_gen_61 = Int_gen_62; // evaled left of expression.
	Object_Int* Int_gen_63 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_64 = NULL; // Default New Var reg of type: Int
	Int_gen_64 = _this_ptr->z;
// After Right  Math Eval.
	Int_gen_63 = Int_gen_64; // evaled right of expression.
	Object_Boolean* Boolean_gen_6 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_6 = (*Int_gen_61->_class_pointer->Class_Int_Method_EQUALS)(Int_gen_61, Int_gen_63);
		Boolean_gen_5 = Boolean_gen_6;
		if (1==Boolean_gen_5->_bool_value)
		{
			 goto label_6_; 
		}
		else
		{
			 goto label_7_; 
		}
	}
	label_6_:;
// code block
	{
// Generate return statement.
	Object_Obj* Obj_gen_5 = NULL; // Default New Var reg of type: Obj
// Generate Typed Value 
	Object_Boolean* Boolean_gen_7 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_7 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_7->_bool_value = 1;
	Obj_gen_5 = ((Object_Obj* )Boolean_gen_7); // return value .
	Obj_gen_5->_class_pointer= &GLOBAL_Class_Obj;
	return Obj_gen_5;
	goto label_0_;
	}
// end code block
// If test
	label_7_:;
	label_8_:;
// code block
	{
// Generate return statement.
	Object_Obj* Obj_gen_6 = NULL; // Default New Var reg of type: Obj
// Generate Typed Value 
	Object_Int* Int_gen_65 = NULL; // Default New Var reg of type: Int
	Int_gen_65 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_65->_int_value = 1;
	Obj_gen_6 = ((Object_Obj* )Int_gen_65); // return value .
	Obj_gen_6->_class_pointer= &GLOBAL_Class_Obj;
	return Obj_gen_6;
	goto label_0_;
	}
// end code block
	label_0_:;
// If Else List end. 
// Generate return statement.
	Object_Obj* Obj_gen_7 = NULL; // Default New Var reg of type: Obj
// Generate Typed Value 
	Object_Int* Int_gen_66 = NULL; // Default New Var reg of type: Int
	Int_gen_66 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_66->_int_value = 0;
	Obj_gen_7 = ((Object_Obj* )Int_gen_66); // return value .
	Obj_gen_7->_class_pointer= &GLOBAL_Class_Obj;
	return Obj_gen_7;

}

Object_Int* Class_Treta_Method_foo(Object_Treta* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// Generate return statement.
	Object_Int* Int_gen_67 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_68 = NULL; // Default New Var reg of type: Int
	Int_gen_68 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_68->_int_value = 0;
	Int_gen_67 = ((Object_Int* )Int_gen_68); // return value .
	Int_gen_67->_class_pointer= &GLOBAL_Class_Int;
	return Int_gen_67;

}

Object_Obj* Class_Treta_Method_test1(Object_Treta* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* Int_gen_69 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_70 = NULL; // Default New Var reg of type: Int
	Int_gen_70 = _this_ptr->x;
	Int_gen_69 = Int_gen_70 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	_this_ptr->y = Int_gen_69; //store into this.
// End Assignment Statment
// Begin Method Call Generation .
	Object_Treta* Treta_gen_0 = NULL; // Default New Var reg of type: Treta
	Treta_gen_0 = ( (Object_Treta* )_this_ptr); 
	Object_Int* Int_gen_71 = NULL; // Default New Var reg of type: Int
	Int_gen_71 = (*_this_ptr->_class_pointer->Class_Treta_Method_foo)(Treta_gen_0);
// Generate return statement.
	Object_Obj* Obj_gen_8 = NULL; // Default New Var reg of type: Obj
// Generate Typed Value 
	Object_Int* Int_gen_72 = NULL; // Default New Var reg of type: Int
	Int_gen_72 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_72->_int_value = 0;
	Obj_gen_8 = ((Object_Obj* )Int_gen_72); // return value .
	Obj_gen_8->_class_pointer= &GLOBAL_Class_Obj;
	return Obj_gen_8;

}

Object_Obj* Class_Treta_Method_test2(Object_Treta* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
//While loop start.
	Object_Boolean* Boolean_gen_8 = NULL; // Default New Var reg of type: Boolean
// Condition start
	label_12_:;
	{
	Object_Int* Int_gen_73 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_74 = NULL; // Default New Var reg of type: Int
	Int_gen_74 = _this_ptr->x;
// After Left Math Eval.
	Int_gen_73 = Int_gen_74; // evaled left of expression.
	Object_Int* Int_gen_75 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_76 = NULL; // Default New Var reg of type: Int
	Int_gen_76 = _this_ptr->x;
// After Right  Math Eval.
	Int_gen_75 = Int_gen_76; // evaled right of expression.
	Object_Boolean* Boolean_gen_9 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_9 = (*Int_gen_73->_class_pointer->Class_Int_Method_EQUALS)(Int_gen_73, Int_gen_75);
// Condition test
		Boolean_gen_8 = Boolean_gen_9 ; 
	if (1==Boolean_gen_8->_bool_value)
	{
		 goto label_11_; 
	}
	else
	{
		 goto label_13_; 
	}
	}
// Loop start
	label_11_:;
	{
// Generate return statement.
	Object_Obj* Obj_gen_9 = NULL; // Default New Var reg of type: Obj
// Generate Typed Value 
	Object_Int* Int_gen_77 = NULL; // Default New Var reg of type: Int
	Int_gen_77 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_77->_int_value = 1;
	Obj_gen_9 = ((Object_Obj* )Int_gen_77); // return value .
	Obj_gen_9->_class_pointer= &GLOBAL_Class_Obj;
	return Obj_gen_9;
//While loop start.
	Object_Boolean* Boolean_gen_10 = NULL; // Default New Var reg of type: Boolean
// Condition start
	label_15_:;
	{
	Object_Int* Int_gen_78 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_79 = NULL; // Default New Var reg of type: Int
	Int_gen_79 = _this_ptr->x;
// After Left Math Eval.
	Int_gen_78 = Int_gen_79; // evaled left of expression.
	Object_Int* Int_gen_80 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_81 = NULL; // Default New Var reg of type: Int
	Int_gen_81 = _this_ptr->y;
// After Right  Math Eval.
	Int_gen_80 = Int_gen_81; // evaled right of expression.
	Object_Boolean* Boolean_gen_11 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_11 = (*Int_gen_78->_class_pointer->Class_Int_Method_EQUALS)(Int_gen_78, Int_gen_80);
// Condition test
		Boolean_gen_10 = Boolean_gen_11 ; 
	if (1==Boolean_gen_10->_bool_value)
	{
		 goto label_14_; 
	}
	else
	{
		 goto label_16_; 
	}
	}
// Loop start
	label_14_:;
	{
// Generate return statement.
	Object_Obj* Obj_gen_10 = NULL; // Default New Var reg of type: Obj
// Generate Typed Value 
	Object_Int* Int_gen_82 = NULL; // Default New Var reg of type: Int
	Int_gen_82 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_82->_int_value = 1;
	Obj_gen_10 = ((Object_Obj* )Int_gen_82); // return value .
	Obj_gen_10->_class_pointer= &GLOBAL_Class_Obj;
	return Obj_gen_10;
	goto label_15_; 
	}
// Loop exit
	label_16_:;
	goto label_12_; 
	}
// Loop exit
	label_13_:;
// Generate return statement.
	Object_Obj* Obj_gen_11 = NULL; // Default New Var reg of type: Obj
// Generate Typed Value 
	Object_Int* Int_gen_83 = NULL; // Default New Var reg of type: Int
	Int_gen_83 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_83->_int_value = 0;
	Obj_gen_11 = ((Object_Obj* )Int_gen_83); // return value .
	Obj_gen_11->_class_pointer= &GLOBAL_Class_Obj;
	return Obj_gen_11;

}

Object_Middle* Class_Middle_Method_Middle(Object_Int* x, Object_Int* y)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* Int_gen_84 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_85 = NULL; // Default New Var reg of type: Int
	Object_Middle * returnValue = (Object_Middle * )malloc(sizeof(Object_Middle));
	returnValue->_class_pointer = &GLOBAL_Class_Middle;
// Begin Method Call Generation .
	Object_Str* Str_gen_20 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_21 = NULL; // Default New Var reg of type: Str
	Str_gen_21 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_21->_string_value = "class Middle(x:Int, y:Int) extends Top";
Str_gen_20 = Str_gen_21; // generate method left exp complete.
	Object_Obj* Obj_gen_12 = NULL; // Default New Var reg of type: Obj
	Obj_gen_12 = ( (Object_Obj* )Str_gen_20); 
	Object_Nothing* Nothing_gen_5 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_5 = (* Obj_gen_12->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_12);
	Object_Int* Int_gen_86 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_87 = NULL; // Default New Var reg of type: Int
	Int_gen_87 = ( (Object_Int* )x); 
// Setting variable x to the new value
	x = Int_gen_87;
	Int_gen_86 = Int_gen_87 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	returnValue->abc = Int_gen_86; //store into this.
// End Assignment Statment
	Object_Int* Int_gen_88 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_89 = NULL; // Default New Var reg of type: Int
	Int_gen_89 = ( (Object_Int* )y); 
// Setting variable y to the new value
	y = Int_gen_89;
	Int_gen_88 = Int_gen_89 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	returnValue->xyz = Int_gen_88; //store into this.
// End Assignment Statment
	return returnValue;

}

Object_Int* Class_Middle_Method_foo(Object_Middle* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// Begin Method Call Generation .
	Object_Str* Str_gen_22 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_23 = NULL; // Default New Var reg of type: Str
	Str_gen_23 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_23->_string_value = "def Middle foo():Int";
Str_gen_22 = Str_gen_23; // generate method left exp complete.
	Object_Obj* Obj_gen_13 = NULL; // Default New Var reg of type: Obj
	Obj_gen_13 = ( (Object_Obj* )Str_gen_22); 
	Object_Nothing* Nothing_gen_6 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_6 = (* Obj_gen_13->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_13);
// Generate return statement.
	Object_Int* Int_gen_90 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_91 = NULL; // Default New Var reg of type: Int
	Object_Middle* Middle_gen_0 = NULL; // Default New Var reg of type: Middle
// Begin Method Call Generation .
	Object_Int* Int_gen_92 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_93 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_94 = NULL; // Default New Var reg of type: Int
	Int_gen_94 = _this_ptr->abc;
// After Left Math Eval.
	Int_gen_93 = Int_gen_94; // evaled left of expression.
	Object_Int* Int_gen_95 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_96 = NULL; // Default New Var reg of type: Int
	Int_gen_96 = _this_ptr->xyz;
// After Right  Math Eval.
	Int_gen_95 = Int_gen_96; // evaled right of expression.
	Object_Int* Int_gen_97 = NULL; // Default New Var reg of type: Int
	Int_gen_97 = (*Int_gen_93->_class_pointer->Class_Int_Method_PLUS)(Int_gen_93, Int_gen_95);
	Int_gen_92 = Int_gen_97; // evaluated argument 
	Object_Int* Int_gen_98 = NULL; // Default New Var reg of type: Int
	Int_gen_98 = ( (Object_Int* )Int_gen_92); 
	Object_Int* Int_gen_99 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_100 = NULL; // Default New Var reg of type: Int
	Int_gen_100 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_100->_int_value = 0;
	Int_gen_99 = Int_gen_100; // evaluated argument 
	Object_Int* Int_gen_101 = NULL; // Default New Var reg of type: Int
	Int_gen_101 = ( (Object_Int* )Int_gen_99); 
	Object_Middle* Middle_gen_1 = NULL; // Default New Var reg of type: Middle
	Middle_gen_1 = (*GLOBAL_Class_Middle.Class_Middle_Method_Middle)(Int_gen_98,Int_gen_101);
	Middle_gen_0 = Middle_gen_1; // Evaluated expression
	Int_gen_91 = Middle_gen_0->abc;
	Int_gen_90 = ((Object_Int* )Int_gen_91); // return value .
	Int_gen_90->_class_pointer= &GLOBAL_Class_Int;
	return Int_gen_90;

}

Object_Top* Class_Middle_Method_forever(Object_Middle* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* Int_gen_102 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
// Generate Typed Value 
	Object_Int* Int_gen_103 = NULL; // Default New Var reg of type: Int
	Int_gen_103 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_103->_int_value = 2;
	Int_gen_102 = Int_gen_103 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	_this_ptr->abc = Int_gen_102; //store into this.
// End Assignment Statment
// Begin Method Call Generation .
	Object_Str* Str_gen_24 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_25 = NULL; // Default New Var reg of type: Str
	Str_gen_25 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_25->_string_value = " in Middle Onece!";
Str_gen_24 = Str_gen_25; // generate method left exp complete.
	Object_Obj* Obj_gen_14 = NULL; // Default New Var reg of type: Obj
	Obj_gen_14 = ( (Object_Obj* )Str_gen_24); 
	Object_Nothing* Nothing_gen_7 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_7 = (* Obj_gen_14->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_14);
// Generate return statement.
	Object_Top* Top_gen_2 = NULL; // Default New Var reg of type: Top
	Object_Middle* Middle_gen_2 = NULL; // Default New Var reg of type: Middle
	Middle_gen_2 =( (Object_Middle* )_this_ptr);
	Top_gen_2 = ((Object_Top* )Middle_gen_2); // return value .
	Top_gen_2->_class_pointer= &GLOBAL_Class_Top;
	return Top_gen_2;

}

Object_Bottom* Class_Bottom_Method_Bottom(Object_Int* x, Object_Int* y, Object_Int* z)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* Int_gen_104 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_105 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_106 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_107 = NULL; // Default New Var reg of type: Int
	Object_Bottom * returnValue = (Object_Bottom * )malloc(sizeof(Object_Bottom));
	returnValue->_class_pointer = &GLOBAL_Class_Bottom;
// Begin Method Call Generation .
	Object_Str* Str_gen_26 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_27 = NULL; // Default New Var reg of type: Str
	Str_gen_27 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_27->_string_value = "class Bottom(x:Int, y:Int, z:Int) extends Middle";
Str_gen_26 = Str_gen_27; // generate method left exp complete.
	Object_Obj* Obj_gen_15 = NULL; // Default New Var reg of type: Obj
	Obj_gen_15 = ( (Object_Obj* )Str_gen_26); 
	Object_Nothing* Nothing_gen_8 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_8 = (* Obj_gen_15->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_15);
	Object_Int* Int_gen_108 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_109 = NULL; // Default New Var reg of type: Int
	Int_gen_109 = ( (Object_Int* )z); 
// Setting variable z to the new value
	z = Int_gen_109;
	Int_gen_108 = Int_gen_109 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	returnValue->defer = Int_gen_108; //store into this.
// End Assignment Statment
	Object_Int* Int_gen_110 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_111 = NULL; // Default New Var reg of type: Int
	Int_gen_111 = ( (Object_Int* )y); 
// Setting variable y to the new value
	y = Int_gen_111;
	Int_gen_110 = Int_gen_111 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	returnValue->xyz = Int_gen_110; //store into this.
// End Assignment Statment
	Object_Int* Int_gen_112 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_113 = NULL; // Default New Var reg of type: Int
	Int_gen_113 = ( (Object_Int* )x); 
// Setting variable x to the new value
	x = Int_gen_113;
	Int_gen_112 = Int_gen_113 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	returnValue->abc = Int_gen_112; //store into this.
// End Assignment Statment
	Object_Int* Int_gen_114 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_115 = NULL; // Default New Var reg of type: Int
	Int_gen_115 = ( (Object_Int* )z); 
// Setting variable z to the new value
	z = Int_gen_115;
	Int_gen_114 = Int_gen_115 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	returnValue->test = Int_gen_114; //store into this.
// End Assignment Statment
	return returnValue;

}

Object_Int* Class_Bottom_Method_bar(Object_Bottom* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// Begin Method Call Generation .
	Object_Str* Str_gen_28 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_29 = NULL; // Default New Var reg of type: Str
	Str_gen_29 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_29->_string_value = "def Bottom bar():Int";
Str_gen_28 = Str_gen_29; // generate method left exp complete.
	Object_Obj* Obj_gen_16 = NULL; // Default New Var reg of type: Obj
	Obj_gen_16 = ( (Object_Obj* )Str_gen_28); 
	Object_Nothing* Nothing_gen_9 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_9 = (* Obj_gen_16->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_16);
	Object_Int* Int_gen_116 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_117 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_118 = NULL; // Default New Var reg of type: Int
	Int_gen_118 = _this_ptr->xyz;
// After Left Math Eval.
	Int_gen_117 = Int_gen_118; // evaled left of expression.
	Object_Int* Int_gen_119 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_120 = NULL; // Default New Var reg of type: Int
	Int_gen_120 = _this_ptr->xyz;
// After Right  Math Eval.
	Int_gen_119 = Int_gen_120; // evaled right of expression.
	Object_Int* Int_gen_121 = NULL; // Default New Var reg of type: Int
	Int_gen_121 = (*Int_gen_117->_class_pointer->Class_Int_Method_TIMES)(Int_gen_117, Int_gen_119);
	Int_gen_116 = Int_gen_121 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	_this_ptr->xyz = Int_gen_116; //store into this.
// End Assignment Statment
// Generate return statement.
	Object_Int* Int_gen_122 = NULL; // Default New Var reg of type: Int
// Begin Method Call Generation .
	Object_Middle* Middle_gen_3 = NULL; // Default New Var reg of type: Middle
	Middle_gen_3 = ( (Object_Middle* )_this_ptr); 
	Object_Int* Int_gen_123 = NULL; // Default New Var reg of type: Int
	Int_gen_123 = (*_this_ptr->_class_pointer->Class_Middle_Method_foo)(Middle_gen_3);
	Int_gen_122 = ((Object_Int* )Int_gen_123); // return value .
	Int_gen_122->_class_pointer= &GLOBAL_Class_Int;
	return Int_gen_122;

}

Object_Boolean* Class_Bottom_Method_boolTest(Object_Bottom* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// Begin Method Call Generation .
	Object_Str* Str_gen_30 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_31 = NULL; // Default New Var reg of type: Str
	Str_gen_31 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_31->_string_value = "def boolTest():Boolean";
Str_gen_30 = Str_gen_31; // generate method left exp complete.
	Object_Obj* Obj_gen_17 = NULL; // Default New Var reg of type: Obj
	Obj_gen_17 = ( (Object_Obj* )Str_gen_30); 
	Object_Nothing* Nothing_gen_10 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_10 = (* Obj_gen_17->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_17);
// Generate return statement.
	Object_Boolean* Boolean_gen_12 = NULL; // Default New Var reg of type: Boolean
// Start Boolean Expression emit.
	Object_Boolean* Boolean_gen_13 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_14 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_15 = NULL; // Default New Var reg of type: Boolean
	{
/// L EXPRESSION OR begin.
// Generate Typed Value 
	Object_Boolean* Boolean_gen_16 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_16 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_16->_bool_value = 0;
	Boolean_gen_14 = Boolean_gen_16; // evaled left of OR expression.
	if (1==Boolean_gen_14->_bool_value)
	{
		Boolean_gen_13 = Boolean_gen_14;
		 goto label_17_; 
	}
	else
	{
		 goto label_18_; 
	}
	label_18_:;
/// R expression OR begin.
	{
// Start Boolean Expression emit.
	Object_Boolean* Boolean_gen_17 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_18 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_19 = NULL; // Default New Var reg of type: Boolean
	{
/// L EXPRESSION AND begin.
// Generate Typed Value 
	Object_Boolean* Boolean_gen_20 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_20 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_20->_bool_value = 1;
	Boolean_gen_18 = Boolean_gen_20; // evaled left of AND expression.
	if (0==Boolean_gen_18->_bool_value)
	{
		Boolean_gen_17 = Boolean_gen_18;
		 goto label_19_; 
	}
	else
	{
		 goto label_20_; 
	}
	label_20_:;
/// R expression AND begin.
	{
// Start Boolean Expression emit.
	Object_Boolean* Boolean_gen_21 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_22 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_23 = NULL; // Default New Var reg of type: Boolean
	{
// Emitting NOT operator.
// Generate Typed Value 
	Object_Boolean* Boolean_gen_24 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_24 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_24->_bool_value = 0;
	Boolean_gen_23 = Boolean_gen_24 ; // right side NOT evaled.
	Boolean_gen_21 = (*Boolean_gen_23->_class_pointer->Class_Boolean_Method_NOT)(Boolean_gen_23);
// End NOT operator.
	goto label_21_;
	label_21_:;
	}
		Boolean_gen_17 = Boolean_gen_21; // evaled right of AND expression.
	goto label_19_;
	}
// end AND short circuit.
	label_19_:;
	}
		Boolean_gen_13 = Boolean_gen_17; // evaled right of OR expression.
	goto label_17_;
	}
// end OR short circuit.
	label_17_:;
	}
	Boolean_gen_12 = ((Object_Boolean* )Boolean_gen_13); // return value .
	Boolean_gen_12->_class_pointer= &GLOBAL_Class_Boolean;
	return Boolean_gen_12;

}

Object_Middle* Class_Bottom_Method_forever(Object_Bottom* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* Int_gen_124 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
// Generate Typed Value 
	Object_Int* Int_gen_125 = NULL; // Default New Var reg of type: Int
	Int_gen_125 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_125->_int_value = 3;
	Int_gen_124 = Int_gen_125 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	_this_ptr->abc = Int_gen_124; //store into this.
// End Assignment Statment
// Begin Method Call Generation .
	Object_Str* Str_gen_32 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_33 = NULL; // Default New Var reg of type: Str
	Str_gen_33 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_33->_string_value = " in Bottom Onece!";
Str_gen_32 = Str_gen_33; // generate method left exp complete.
	Object_Obj* Obj_gen_18 = NULL; // Default New Var reg of type: Obj
	Obj_gen_18 = ( (Object_Obj* )Str_gen_32); 
	Object_Nothing* Nothing_gen_11 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_11 = (* Obj_gen_18->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_18);
// Generate return statement.
	Object_Middle* Middle_gen_4 = NULL; // Default New Var reg of type: Middle
	Object_Bottom* Bottom_gen_0 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_0 =( (Object_Bottom* )_this_ptr);
	Middle_gen_4 = ((Object_Middle* )Bottom_gen_0); // return value .
	Middle_gen_4->_class_pointer= &GLOBAL_Class_Middle;
	return Middle_gen_4;

}

Object_Bottom* Class_Bottom_Method_RunAlways(Object_Bottom* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// If Else List Begin. 
// If test
	label_25_:;
	{
	Object_Boolean* Boolean_gen_25 = NULL; // Default New Var reg of type: Boolean
	Object_Int* Int_gen_126 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_127 = NULL; // Default New Var reg of type: Int
	Int_gen_127 = _this_ptr->abc;
// After Left Math Eval.
	Int_gen_126 = Int_gen_127; // evaled left of expression.
	Object_Int* Int_gen_128 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_129 = NULL; // Default New Var reg of type: Int
	Int_gen_129 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_129->_int_value = -1;
// After Right  Math Eval.
	Int_gen_128 = Int_gen_129; // evaled right of expression.
	Object_Boolean* Boolean_gen_26 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_26 = (*Int_gen_126->_class_pointer->Class_Int_Method_MORE)(Int_gen_126, Int_gen_128);
		Boolean_gen_25 = Boolean_gen_26;
		if (1==Boolean_gen_25->_bool_value)
		{
			 goto label_24_; 
		}
		else
		{
			 goto label_26_; 
		}
	}
	label_24_:;
// code block
	{
	Object_Int* Int_gen_130 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_131 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_132 = NULL; // Default New Var reg of type: Int
	Int_gen_132 = _this_ptr->abc;
// After Left Math Eval.
	Int_gen_131 = Int_gen_132; // evaled left of expression.
	Object_Int* Int_gen_133 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_134 = NULL; // Default New Var reg of type: Int
	Int_gen_134 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_134->_int_value = 1;
// After Right  Math Eval.
	Int_gen_133 = Int_gen_134; // evaled right of expression.
	Object_Int* Int_gen_135 = NULL; // Default New Var reg of type: Int
	Int_gen_135 = (*Int_gen_131->_class_pointer->Class_Int_Method_MINUS)(Int_gen_131, Int_gen_133);
	Int_gen_130 = Int_gen_135 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	_this_ptr->abc = Int_gen_130; //store into this.
// End Assignment Statment
	goto label_23_;
	}
// end code block
// If test
	label_26_:;
	label_27_:;
// code block
	{
// Generate return statement.
	Object_Bottom* Bottom_gen_1 = NULL; // Default New Var reg of type: Bottom
	Object_Bottom* Bottom_gen_2 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_2 =( (Object_Bottom* )_this_ptr);
	Bottom_gen_1 = ((Object_Bottom* )Bottom_gen_2); // return value .
	Bottom_gen_1->_class_pointer= &GLOBAL_Class_Bottom;
	return Bottom_gen_1;
	goto label_23_;
	}
// end code block
	label_23_:;
// If Else List end. 
// Begin Method Call Generation .
	Object_Str* Str_gen_34 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_35 = NULL; // Default New Var reg of type: Str
	Str_gen_35 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_35->_string_value = "Infinite Recurson";
Str_gen_34 = Str_gen_35; // generate method left exp complete.
	Object_Obj* Obj_gen_19 = NULL; // Default New Var reg of type: Obj
	Obj_gen_19 = ( (Object_Obj* )Str_gen_34); 
	Object_Nothing* Nothing_gen_12 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_12 = (* Obj_gen_19->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_19);
// Generate return statement.
	Object_Bottom* Bottom_gen_3 = NULL; // Default New Var reg of type: Bottom
// Begin Method Call Generation .
	Object_Bottom* Bottom_gen_4 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_4 = ( (Object_Bottom* )_this_ptr); 
	Object_Bottom* Bottom_gen_5 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_5 = (*_this_ptr->_class_pointer->Class_Bottom_Method_RunAlways)(Bottom_gen_4);
	Bottom_gen_3 = ((Object_Bottom* )Bottom_gen_5); // return value .
	Bottom_gen_3->_class_pointer= &GLOBAL_Class_Bottom;
	return Bottom_gen_3;

}

Object_Nothing* class_MAIN_method_MAIN()
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Top* Top_gen_3 = NULL; // Default New Var reg of type: Top
	Object_Pt* Pt_gen_6 = NULL; // Default New Var reg of type: Pt
	Object_Int* Int_gen_136 = NULL; // Default New Var reg of type: Int
	Object_Middle* Middle_gen_5 = NULL; // Default New Var reg of type: Middle
	Object_Pt* Pt_gen_7 = NULL; // Default New Var reg of type: Pt
	Object_Bottom* Bottom_gen_6 = NULL; // Default New Var reg of type: Bottom
	Object_Pt* Pt_gen_8 = NULL; // Default New Var reg of type: Pt
	Object_Top* Top_gen_4 = NULL; // Default New Var reg of type: Top
	Object_Bottom* Bottom_gen_7 = NULL; // Default New Var reg of type: Bottom
	Object_Str* Str_gen_36 = NULL; // Default New Var reg of type: Str
	Object_Str* Str_gen_37 = NULL; // Default New Var reg of type: Str
// Begin Method Call Generation .
	Object_Str* Str_gen_38 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_39 = NULL; // Default New Var reg of type: Str
	Str_gen_39 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_39->_string_value = " a = Top(12);";
Str_gen_38 = Str_gen_39; // generate method left exp complete.
	Object_Obj* Obj_gen_20 = NULL; // Default New Var reg of type: Obj
	Obj_gen_20 = ( (Object_Obj* )Str_gen_38); 
	Object_Nothing* Nothing_gen_13 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_13 = (* Obj_gen_20->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_20);
	Object_Top* Top_gen_5 = NULL; // Default New Var reg of type: Top
// Begin Assignment Gen Value side. 
// Begin Method Call Generation .
	Object_Int* Int_gen_137 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_138 = NULL; // Default New Var reg of type: Int
	Int_gen_138 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_138->_int_value = 12;
	Int_gen_137 = Int_gen_138; // evaluated argument 
	Object_Int* Int_gen_139 = NULL; // Default New Var reg of type: Int
	Int_gen_139 = ( (Object_Int* )Int_gen_137); 
	Object_Top* Top_gen_6 = NULL; // Default New Var reg of type: Top
	Top_gen_6 = (*GLOBAL_Class_Top.Class_Top_Method_Top)(Int_gen_139);
	Top_gen_5 = Top_gen_6 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Top* Top_gen_7 = NULL; // Default New Var reg of type: Top
	Top_gen_7 = ( (Object_Top* )Top_gen_5); 
	 // Assigning var a to Top_gen_7
	Top_gen_3 = Top_gen_7;
// End Assignment Statment
// Begin Method Call Generation .
	Object_Str* Str_gen_40 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_41 = NULL; // Default New Var reg of type: Str
	Str_gen_41 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_41->_string_value = "b = Middle(13,14);";
Str_gen_40 = Str_gen_41; // generate method left exp complete.
	Object_Obj* Obj_gen_21 = NULL; // Default New Var reg of type: Obj
	Obj_gen_21 = ( (Object_Obj* )Str_gen_40); 
	Object_Nothing* Nothing_gen_14 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_14 = (* Obj_gen_21->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_21);
	Object_Middle* Middle_gen_6 = NULL; // Default New Var reg of type: Middle
// Begin Assignment Gen Value side. 
// Begin Method Call Generation .
	Object_Int* Int_gen_140 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_141 = NULL; // Default New Var reg of type: Int
	Int_gen_141 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_141->_int_value = 13;
	Int_gen_140 = Int_gen_141; // evaluated argument 
	Object_Int* Int_gen_142 = NULL; // Default New Var reg of type: Int
	Int_gen_142 = ( (Object_Int* )Int_gen_140); 
	Object_Int* Int_gen_143 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_144 = NULL; // Default New Var reg of type: Int
	Int_gen_144 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_144->_int_value = 14;
	Int_gen_143 = Int_gen_144; // evaluated argument 
	Object_Int* Int_gen_145 = NULL; // Default New Var reg of type: Int
	Int_gen_145 = ( (Object_Int* )Int_gen_143); 
	Object_Middle* Middle_gen_7 = NULL; // Default New Var reg of type: Middle
	Middle_gen_7 = (*GLOBAL_Class_Middle.Class_Middle_Method_Middle)(Int_gen_142,Int_gen_145);
	Middle_gen_6 = Middle_gen_7 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Middle* Middle_gen_8 = NULL; // Default New Var reg of type: Middle
	Middle_gen_8 = ( (Object_Middle* )Middle_gen_6); 
	 // Assigning var b to Middle_gen_8
	Middle_gen_5 = Middle_gen_8;
// End Assignment Statment
// Begin Method Call Generation .
	Object_Str* Str_gen_42 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_43 = NULL; // Default New Var reg of type: Str
	Str_gen_43 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_43->_string_value = "c = Bottom(15,16,17);";
Str_gen_42 = Str_gen_43; // generate method left exp complete.
	Object_Obj* Obj_gen_22 = NULL; // Default New Var reg of type: Obj
	Obj_gen_22 = ( (Object_Obj* )Str_gen_42); 
	Object_Nothing* Nothing_gen_15 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_15 = (* Obj_gen_22->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_22);
	Object_Bottom* Bottom_gen_8 = NULL; // Default New Var reg of type: Bottom
// Begin Assignment Gen Value side. 
// Begin Method Call Generation .
	Object_Int* Int_gen_146 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_147 = NULL; // Default New Var reg of type: Int
	Int_gen_147 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_147->_int_value = 15;
	Int_gen_146 = Int_gen_147; // evaluated argument 
	Object_Int* Int_gen_148 = NULL; // Default New Var reg of type: Int
	Int_gen_148 = ( (Object_Int* )Int_gen_146); 
	Object_Int* Int_gen_149 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_150 = NULL; // Default New Var reg of type: Int
	Int_gen_150 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_150->_int_value = 16;
	Int_gen_149 = Int_gen_150; // evaluated argument 
	Object_Int* Int_gen_151 = NULL; // Default New Var reg of type: Int
	Int_gen_151 = ( (Object_Int* )Int_gen_149); 
	Object_Int* Int_gen_152 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_153 = NULL; // Default New Var reg of type: Int
	Int_gen_153 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_153->_int_value = 17;
	Int_gen_152 = Int_gen_153; // evaluated argument 
	Object_Int* Int_gen_154 = NULL; // Default New Var reg of type: Int
	Int_gen_154 = ( (Object_Int* )Int_gen_152); 
	Object_Bottom* Bottom_gen_9 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_9 = (*GLOBAL_Class_Bottom.Class_Bottom_Method_Bottom)(Int_gen_148,Int_gen_151,Int_gen_154);
	Bottom_gen_8 = Bottom_gen_9 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Bottom* Bottom_gen_10 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_10 = ( (Object_Bottom* )Bottom_gen_8); 
	 // Assigning var c to Bottom_gen_10
	Bottom_gen_6 = Bottom_gen_10;
// End Assignment Statment
// Begin Method Call Generation .
	Object_Str* Str_gen_44 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_45 = NULL; // Default New Var reg of type: Str
	Str_gen_45 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_45->_string_value = "xyz.foo().PRINT();";
Str_gen_44 = Str_gen_45; // generate method left exp complete.
	Object_Obj* Obj_gen_23 = NULL; // Default New Var reg of type: Obj
	Obj_gen_23 = ( (Object_Obj* )Str_gen_44); 
	Object_Nothing* Nothing_gen_16 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_16 = (* Obj_gen_23->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_23);
// Begin Method Call Generation .
	Object_Int* Int_gen_155 = NULL; // Default New Var reg of type: Int
// Begin Method Call Generation .
	Object_Top* Top_gen_8 = NULL; // Default New Var reg of type: Top
	Object_Top* Top_gen_9 = NULL; // Default New Var reg of type: Top
	Top_gen_9 = ( (Object_Top* )Top_gen_3); 
// Setting variable Top_gen_3 to the new value
	Top_gen_3 = Top_gen_9;
Top_gen_8 = Top_gen_9; // generate method left exp complete.
	Object_Top* Top_gen_10 = NULL; // Default New Var reg of type: Top
	Top_gen_10 = ( (Object_Top* )Top_gen_8); 
	Object_Int* Int_gen_156 = NULL; // Default New Var reg of type: Int
	Int_gen_156 = (* Top_gen_10->_class_pointer->Class_Top_Method_foo)(Top_gen_10);
Int_gen_155 = Int_gen_156; // generate method left exp complete.
	Object_Obj* Obj_gen_24 = NULL; // Default New Var reg of type: Obj
	Obj_gen_24 = ( (Object_Obj* )Int_gen_155); 
	Object_Nothing* Nothing_gen_17 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_17 = (* Obj_gen_24->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_24);
// Begin Method Call Generation .
	Object_Str* Str_gen_46 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_47 = NULL; // Default New Var reg of type: Str
	Str_gen_47 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_47->_string_value = "b.foo().PRINT();";
Str_gen_46 = Str_gen_47; // generate method left exp complete.
	Object_Obj* Obj_gen_25 = NULL; // Default New Var reg of type: Obj
	Obj_gen_25 = ( (Object_Obj* )Str_gen_46); 
	Object_Nothing* Nothing_gen_18 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_18 = (* Obj_gen_25->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_25);
// Begin Method Call Generation .
	Object_Int* Int_gen_157 = NULL; // Default New Var reg of type: Int
// Begin Method Call Generation .
	Object_Middle* Middle_gen_9 = NULL; // Default New Var reg of type: Middle
	Object_Middle* Middle_gen_10 = NULL; // Default New Var reg of type: Middle
	Middle_gen_10 = ( (Object_Middle* )Middle_gen_5); 
// Setting variable Middle_gen_5 to the new value
	Middle_gen_5 = Middle_gen_10;
Middle_gen_9 = Middle_gen_10; // generate method left exp complete.
	Object_Middle* Middle_gen_11 = NULL; // Default New Var reg of type: Middle
	Middle_gen_11 = ( (Object_Middle* )Middle_gen_9); 
	Object_Int* Int_gen_158 = NULL; // Default New Var reg of type: Int
	Int_gen_158 = (* Middle_gen_11->_class_pointer->Class_Middle_Method_foo)(Middle_gen_11);
Int_gen_157 = Int_gen_158; // generate method left exp complete.
	Object_Obj* Obj_gen_26 = NULL; // Default New Var reg of type: Obj
	Obj_gen_26 = ( (Object_Obj* )Int_gen_157); 
	Object_Nothing* Nothing_gen_19 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_19 = (* Obj_gen_26->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_26);
// Begin Method Call Generation .
	Object_Str* Str_gen_48 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_49 = NULL; // Default New Var reg of type: Str
	Str_gen_49 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_49->_string_value = "c.foo().PRINT();";
Str_gen_48 = Str_gen_49; // generate method left exp complete.
	Object_Obj* Obj_gen_27 = NULL; // Default New Var reg of type: Obj
	Obj_gen_27 = ( (Object_Obj* )Str_gen_48); 
	Object_Nothing* Nothing_gen_20 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_20 = (* Obj_gen_27->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_27);
// Begin Method Call Generation .
	Object_Int* Int_gen_159 = NULL; // Default New Var reg of type: Int
// Begin Method Call Generation .
	Object_Bottom* Bottom_gen_11 = NULL; // Default New Var reg of type: Bottom
	Object_Bottom* Bottom_gen_12 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_12 = ( (Object_Bottom* )Bottom_gen_6); 
// Setting variable Bottom_gen_6 to the new value
	Bottom_gen_6 = Bottom_gen_12;
Bottom_gen_11 = Bottom_gen_12; // generate method left exp complete.
	Object_Middle* Middle_gen_12 = NULL; // Default New Var reg of type: Middle
	Middle_gen_12 = ( (Object_Middle* )Bottom_gen_11); 
	Object_Int* Int_gen_160 = NULL; // Default New Var reg of type: Int
	Int_gen_160 = (* Middle_gen_12->_class_pointer->Class_Middle_Method_foo)(Middle_gen_12);
Int_gen_159 = Int_gen_160; // generate method left exp complete.
	Object_Obj* Obj_gen_28 = NULL; // Default New Var reg of type: Obj
	Obj_gen_28 = ( (Object_Obj* )Int_gen_159); 
	Object_Nothing* Nothing_gen_21 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_21 = (* Obj_gen_28->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_28);
// Begin Method Call Generation .
	Object_Str* Str_gen_50 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_51 = NULL; // Default New Var reg of type: Str
	Str_gen_51 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_51->_string_value = "c.bar().PRINT();";
Str_gen_50 = Str_gen_51; // generate method left exp complete.
	Object_Obj* Obj_gen_29 = NULL; // Default New Var reg of type: Obj
	Obj_gen_29 = ( (Object_Obj* )Str_gen_50); 
	Object_Nothing* Nothing_gen_22 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_22 = (* Obj_gen_29->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_29);
// Begin Method Call Generation .
	Object_Int* Int_gen_161 = NULL; // Default New Var reg of type: Int
// Begin Method Call Generation .
	Object_Bottom* Bottom_gen_13 = NULL; // Default New Var reg of type: Bottom
	Object_Bottom* Bottom_gen_14 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_14 = ( (Object_Bottom* )Bottom_gen_6); 
// Setting variable Bottom_gen_6 to the new value
	Bottom_gen_6 = Bottom_gen_14;
Bottom_gen_13 = Bottom_gen_14; // generate method left exp complete.
	Object_Bottom* Bottom_gen_15 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_15 = ( (Object_Bottom* )Bottom_gen_13); 
	Object_Int* Int_gen_162 = NULL; // Default New Var reg of type: Int
	Int_gen_162 = (* Bottom_gen_15->_class_pointer->Class_Bottom_Method_bar)(Bottom_gen_15);
Int_gen_161 = Int_gen_162; // generate method left exp complete.
	Object_Obj* Obj_gen_30 = NULL; // Default New Var reg of type: Obj
	Obj_gen_30 = ( (Object_Obj* )Int_gen_161); 
	Object_Nothing* Nothing_gen_23 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_23 = (* Obj_gen_30->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_30);
// Begin Method Call Generation .
	Object_Str* Str_gen_52 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_53 = NULL; // Default New Var reg of type: Str
	Str_gen_53 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_53->_string_value = "c.boolTest().PRINT();";
Str_gen_52 = Str_gen_53; // generate method left exp complete.
	Object_Obj* Obj_gen_31 = NULL; // Default New Var reg of type: Obj
	Obj_gen_31 = ( (Object_Obj* )Str_gen_52); 
	Object_Nothing* Nothing_gen_24 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_24 = (* Obj_gen_31->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_31);
// Begin Method Call Generation .
	Object_Boolean* Boolean_gen_27 = NULL; // Default New Var reg of type: Boolean
// Begin Method Call Generation .
	Object_Bottom* Bottom_gen_16 = NULL; // Default New Var reg of type: Bottom
	Object_Bottom* Bottom_gen_17 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_17 = ( (Object_Bottom* )Bottom_gen_6); 
// Setting variable Bottom_gen_6 to the new value
	Bottom_gen_6 = Bottom_gen_17;
Bottom_gen_16 = Bottom_gen_17; // generate method left exp complete.
	Object_Bottom* Bottom_gen_18 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_18 = ( (Object_Bottom* )Bottom_gen_16); 
	Object_Boolean* Boolean_gen_28 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_28 = (* Bottom_gen_18->_class_pointer->Class_Bottom_Method_boolTest)(Bottom_gen_18);
Boolean_gen_27 = Boolean_gen_28; // generate method left exp complete.
	Object_Obj* Obj_gen_32 = NULL; // Default New Var reg of type: Obj
	Obj_gen_32 = ( (Object_Obj* )Boolean_gen_27); 
	Object_Nothing* Nothing_gen_25 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_25 = (* Obj_gen_32->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_32);
// Begin Method Call Generation .
	Object_Str* Str_gen_54 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_55 = NULL; // Default New Var reg of type: Str
	Str_gen_55 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_55->_string_value = "done.";
Str_gen_54 = Str_gen_55; // generate method left exp complete.
	Object_Obj* Obj_gen_33 = NULL; // Default New Var reg of type: Obj
	Obj_gen_33 = ( (Object_Obj* )Str_gen_54); 
	Object_Nothing* Nothing_gen_26 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_26 = (* Obj_gen_33->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_33);
// Begin Method Call Generation .
	Object_Str* Str_gen_56 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_57 = NULL; // Default New Var reg of type: Str
	Str_gen_57 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_57->_string_value = "Printing D Start";
Str_gen_56 = Str_gen_57; // generate method left exp complete.
	Object_Obj* Obj_gen_34 = NULL; // Default New Var reg of type: Obj
	Obj_gen_34 = ( (Object_Obj* )Str_gen_56); 
	Object_Nothing* Nothing_gen_27 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_27 = (* Obj_gen_34->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_34);
	Object_Bottom* Bottom_gen_19 = NULL; // Default New Var reg of type: Bottom
// Begin Assignment Gen Value side. 
// Begin Method Call Generation .
	Object_Int* Int_gen_163 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_164 = NULL; // Default New Var reg of type: Int
	Int_gen_164 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_164->_int_value = 1;
	Int_gen_163 = Int_gen_164; // evaluated argument 
	Object_Int* Int_gen_165 = NULL; // Default New Var reg of type: Int
	Int_gen_165 = ( (Object_Int* )Int_gen_163); 
	Object_Int* Int_gen_166 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_167 = NULL; // Default New Var reg of type: Int
	Int_gen_167 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_167->_int_value = 2;
	Int_gen_166 = Int_gen_167; // evaluated argument 
	Object_Int* Int_gen_168 = NULL; // Default New Var reg of type: Int
	Int_gen_168 = ( (Object_Int* )Int_gen_166); 
	Object_Int* Int_gen_169 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_170 = NULL; // Default New Var reg of type: Int
	Int_gen_170 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_170->_int_value = 3;
	Int_gen_169 = Int_gen_170; // evaluated argument 
	Object_Int* Int_gen_171 = NULL; // Default New Var reg of type: Int
	Int_gen_171 = ( (Object_Int* )Int_gen_169); 
	Object_Bottom* Bottom_gen_20 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_20 = (*GLOBAL_Class_Bottom.Class_Bottom_Method_Bottom)(Int_gen_165,Int_gen_168,Int_gen_171);
	Bottom_gen_19 = Bottom_gen_20 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Top* Top_gen_11 = NULL; // Default New Var reg of type: Top
	Top_gen_11 = ( (Object_Top* )Bottom_gen_19); 
	 // Assigning var d to Top_gen_11
	Top_gen_4 = Top_gen_11;
// End Assignment Statment
//While loop start.
	Object_Boolean* Boolean_gen_29 = NULL; // Default New Var reg of type: Boolean
// Condition start
	label_31_:;
	{
	Object_Int* Int_gen_172 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
// Begin Method Call Generation .
	Object_Top* Top_gen_12 = NULL; // Default New Var reg of type: Top
	Object_Top* Top_gen_13 = NULL; // Default New Var reg of type: Top
	Top_gen_13 = ( (Object_Top* )Top_gen_4); 
// Setting variable Top_gen_4 to the new value
	Top_gen_4 = Top_gen_13;
Top_gen_12 = Top_gen_13; // generate method left exp complete.
	Object_Top* Top_gen_14 = NULL; // Default New Var reg of type: Top
	Top_gen_14 = ( (Object_Top* )Top_gen_12); 
	Object_Int* Int_gen_173 = NULL; // Default New Var reg of type: Int
	Int_gen_173 = (* Top_gen_14->_class_pointer->Class_Top_Method_test)(Top_gen_14);
// After Left Math Eval.
	Int_gen_172 = Int_gen_173; // evaled left of expression.
	Object_Int* Int_gen_174 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_175 = NULL; // Default New Var reg of type: Int
	Int_gen_175 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_175->_int_value = -5;
// After Right  Math Eval.
	Int_gen_174 = Int_gen_175; // evaled right of expression.
	Object_Boolean* Boolean_gen_30 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_30 = (*Int_gen_172->_class_pointer->Class_Int_Method_MORE)(Int_gen_172, Int_gen_174);
// Condition test
		Boolean_gen_29 = Boolean_gen_30 ; 
	if (1==Boolean_gen_29->_bool_value)
	{
		 goto label_30_; 
	}
	else
	{
		 goto label_32_; 
	}
	}
// Loop start
	label_30_:;
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_58 = NULL; // Default New Var reg of type: Str
	Object_Str* Str_gen_59 = NULL; // Default New Var reg of type: Str
// Before Left Math Eval.
	Object_Str* Str_gen_60 = NULL; // Default New Var reg of type: Str
// Before Left Math Eval.
// Generate Typed Value 
	Object_Str* Str_gen_61 = NULL; // Default New Var reg of type: Str
	Str_gen_61 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_61->_string_value = "Printing d";
// After Left Math Eval.
	Str_gen_60 = Str_gen_61; // evaled left of expression.
	Object_Str* Str_gen_62 = NULL; // Default New Var reg of type: Str
// Before Right Math Eval.
// Begin Method Call Generation .
	Object_Int* Int_gen_176 = NULL; // Default New Var reg of type: Int
// Begin Method Call Generation .
	Object_Top* Top_gen_15 = NULL; // Default New Var reg of type: Top
	Object_Top* Top_gen_16 = NULL; // Default New Var reg of type: Top
	Top_gen_16 = ( (Object_Top* )Top_gen_4); 
// Setting variable Top_gen_4 to the new value
	Top_gen_4 = Top_gen_16;
Top_gen_15 = Top_gen_16; // generate method left exp complete.
	Object_Top* Top_gen_17 = NULL; // Default New Var reg of type: Top
	Top_gen_17 = ( (Object_Top* )Top_gen_15); 
	Object_Int* Int_gen_177 = NULL; // Default New Var reg of type: Int
	Int_gen_177 = (* Top_gen_17->_class_pointer->Class_Top_Method_test)(Top_gen_17);
Int_gen_176 = Int_gen_177; // generate method left exp complete.
	Object_Int* Int_gen_178 = NULL; // Default New Var reg of type: Int
	Int_gen_178 = ( (Object_Int* )Int_gen_176); 
	Object_Str* Str_gen_63 = NULL; // Default New Var reg of type: Str
	Str_gen_63 = (* Int_gen_178->_class_pointer->Class_Int_Method_STR)(Int_gen_178);
// After Right  Math Eval.
	Str_gen_62 = Str_gen_63; // evaled right of expression.
	Object_Str* Str_gen_64 = NULL; // Default New Var reg of type: Str
	Str_gen_64 = (*Str_gen_60->_class_pointer->Class_Str_Method_PLUS)(Str_gen_60, Str_gen_62);
// After Left Math Eval.
	Str_gen_59 = Str_gen_64; // evaled left of expression.
	Object_Str* Str_gen_65 = NULL; // Default New Var reg of type: Str
// Before Right Math Eval.
// Generate Typed Value 
	Object_Str* Str_gen_66 = NULL; // Default New Var reg of type: Str
	Str_gen_66 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_66->_string_value = " value";
// After Right  Math Eval.
	Str_gen_65 = Str_gen_66; // evaled right of expression.
	Object_Str* Str_gen_67 = NULL; // Default New Var reg of type: Str
	Str_gen_67 = (*Str_gen_59->_class_pointer->Class_Str_Method_PLUS)(Str_gen_59, Str_gen_65);
Str_gen_58 = Str_gen_67; // generate method left exp complete.
	Object_Obj* Obj_gen_35 = NULL; // Default New Var reg of type: Obj
	Obj_gen_35 = ( (Object_Obj* )Str_gen_58); 
	Object_Nothing* Nothing_gen_28 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_28 = (* Obj_gen_35->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_35);
	Object_Top* Top_gen_18 = NULL; // Default New Var reg of type: Top
// Begin Assignment Gen Value side. 
// Begin Method Call Generation .
	Object_Top* Top_gen_19 = NULL; // Default New Var reg of type: Top
	Object_Top* Top_gen_20 = NULL; // Default New Var reg of type: Top
	Top_gen_20 = ( (Object_Top* )Top_gen_4); 
// Setting variable Top_gen_4 to the new value
	Top_gen_4 = Top_gen_20;
Top_gen_19 = Top_gen_20; // generate method left exp complete.
	Object_Top* Top_gen_21 = NULL; // Default New Var reg of type: Top
	Top_gen_21 = ( (Object_Top* )Top_gen_19); 
	Object_Top* Top_gen_22 = NULL; // Default New Var reg of type: Top
	Top_gen_22 = (* Top_gen_21->_class_pointer->Class_Top_Method_forever)(Top_gen_21);
	Top_gen_18 = Top_gen_22 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Top* Top_gen_23 = NULL; // Default New Var reg of type: Top
	Top_gen_23 = ( (Object_Top* )Top_gen_18); 
	 // Assigning var d to Top_gen_23
	Top_gen_4 = Top_gen_23;
// End Assignment Statment
	goto label_31_; 
	}
// Loop exit
	label_32_:;
// Begin Method Call Generation .
	Object_Str* Str_gen_68 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_69 = NULL; // Default New Var reg of type: Str
	Str_gen_69 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_69->_string_value = "Loops appear to work.";
Str_gen_68 = Str_gen_69; // generate method left exp complete.
	Object_Obj* Obj_gen_36 = NULL; // Default New Var reg of type: Obj
	Obj_gen_36 = ( (Object_Obj* )Str_gen_68); 
	Object_Nothing* Nothing_gen_29 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_29 = (* Obj_gen_36->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_36);
// If Else List Begin. 
// If test
	label_35_:;
	{
	Object_Boolean* Boolean_gen_31 = NULL; // Default New Var reg of type: Boolean
	Object_Int* Int_gen_179 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_180 = NULL; // Default New Var reg of type: Int
	Int_gen_180 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_180->_int_value = 1;
// After Left Math Eval.
	Int_gen_179 = Int_gen_180; // evaled left of expression.
	Object_Int* Int_gen_181 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Begin Method Call Generation .
	Object_Top* Top_gen_24 = NULL; // Default New Var reg of type: Top
	Object_Top* Top_gen_25 = NULL; // Default New Var reg of type: Top
	Top_gen_25 = ( (Object_Top* )Top_gen_4); 
// Setting variable Top_gen_4 to the new value
	Top_gen_4 = Top_gen_25;
Top_gen_24 = Top_gen_25; // generate method left exp complete.
	Object_Top* Top_gen_26 = NULL; // Default New Var reg of type: Top
	Top_gen_26 = ( (Object_Top* )Top_gen_24); 
	Object_Int* Int_gen_182 = NULL; // Default New Var reg of type: Int
	Int_gen_182 = (* Top_gen_26->_class_pointer->Class_Top_Method_test)(Top_gen_26);
// After Right  Math Eval.
	Int_gen_181 = Int_gen_182; // evaled right of expression.
	Object_Boolean* Boolean_gen_32 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_32 = (*Int_gen_179->_class_pointer->Class_Int_Method_LESS)(Int_gen_179, Int_gen_181);
		Boolean_gen_31 = Boolean_gen_32;
		if (1==Boolean_gen_31->_bool_value)
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
	Object_Str* Str_gen_70 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_71 = NULL; // Default New Var reg of type: Str
	Str_gen_71 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_71->_string_value = "First If Block";
Str_gen_70 = Str_gen_71; // generate method left exp complete.
	Object_Obj* Obj_gen_37 = NULL; // Default New Var reg of type: Obj
	Obj_gen_37 = ( (Object_Obj* )Str_gen_70); 
	Object_Nothing* Nothing_gen_30 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_30 = (* Obj_gen_37->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_37);
	goto label_33_;
	}
// end code block
// If test
	label_36_:;
	{
	Object_Boolean* Boolean_gen_33 = NULL; // Default New Var reg of type: Boolean
	Object_Int* Int_gen_183 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_184 = NULL; // Default New Var reg of type: Int
	Int_gen_184 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_184->_int_value = 1;
// After Left Math Eval.
	Int_gen_183 = Int_gen_184; // evaled left of expression.
	Object_Int* Int_gen_185 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Begin Method Call Generation .
	Object_Top* Top_gen_27 = NULL; // Default New Var reg of type: Top
	Object_Top* Top_gen_28 = NULL; // Default New Var reg of type: Top
	Top_gen_28 = ( (Object_Top* )Top_gen_4); 
// Setting variable Top_gen_4 to the new value
	Top_gen_4 = Top_gen_28;
Top_gen_27 = Top_gen_28; // generate method left exp complete.
	Object_Top* Top_gen_29 = NULL; // Default New Var reg of type: Top
	Top_gen_29 = ( (Object_Top* )Top_gen_27); 
	Object_Int* Int_gen_186 = NULL; // Default New Var reg of type: Int
	Int_gen_186 = (* Top_gen_29->_class_pointer->Class_Top_Method_test)(Top_gen_29);
// After Right  Math Eval.
	Int_gen_185 = Int_gen_186; // evaled right of expression.
	Object_Boolean* Boolean_gen_34 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_34 = (*Int_gen_183->_class_pointer->Class_Int_Method_EQUALS)(Int_gen_183, Int_gen_185);
		Boolean_gen_33 = Boolean_gen_34;
		if (1==Boolean_gen_33->_bool_value)
		{
			 goto label_37_; 
		}
		else
		{
			 goto label_38_; 
		}
	}
	label_37_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_72 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_73 = NULL; // Default New Var reg of type: Str
	Str_gen_73 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_73->_string_value = "second If Block";
Str_gen_72 = Str_gen_73; // generate method left exp complete.
	Object_Obj* Obj_gen_38 = NULL; // Default New Var reg of type: Obj
	Obj_gen_38 = ( (Object_Obj* )Str_gen_72); 
	Object_Nothing* Nothing_gen_31 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_31 = (* Obj_gen_38->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_38);
	goto label_33_;
	}
// end code block
// If test
	label_38_:;
	{
	Object_Boolean* Boolean_gen_35 = NULL; // Default New Var reg of type: Boolean
	Object_Int* Int_gen_187 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_188 = NULL; // Default New Var reg of type: Int
	Int_gen_188 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_188->_int_value = 1;
// After Left Math Eval.
	Int_gen_187 = Int_gen_188; // evaled left of expression.
	Object_Int* Int_gen_189 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Begin Method Call Generation .
	Object_Top* Top_gen_30 = NULL; // Default New Var reg of type: Top
	Object_Top* Top_gen_31 = NULL; // Default New Var reg of type: Top
	Top_gen_31 = ( (Object_Top* )Top_gen_4); 
// Setting variable Top_gen_4 to the new value
	Top_gen_4 = Top_gen_31;
Top_gen_30 = Top_gen_31; // generate method left exp complete.
	Object_Top* Top_gen_32 = NULL; // Default New Var reg of type: Top
	Top_gen_32 = ( (Object_Top* )Top_gen_30); 
	Object_Int* Int_gen_190 = NULL; // Default New Var reg of type: Int
	Int_gen_190 = (* Top_gen_32->_class_pointer->Class_Top_Method_test)(Top_gen_32);
// After Right  Math Eval.
	Int_gen_189 = Int_gen_190; // evaled right of expression.
	Object_Boolean* Boolean_gen_36 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_36 = (*Int_gen_187->_class_pointer->Class_Int_Method_ATMOST)(Int_gen_187, Int_gen_189);
		Boolean_gen_35 = Boolean_gen_36;
		if (1==Boolean_gen_35->_bool_value)
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
	Object_Str* Str_gen_74 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_75 = NULL; // Default New Var reg of type: Str
	Str_gen_75 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_75->_string_value = "thrirs If Block";
Str_gen_74 = Str_gen_75; // generate method left exp complete.
	Object_Obj* Obj_gen_39 = NULL; // Default New Var reg of type: Obj
	Obj_gen_39 = ( (Object_Obj* )Str_gen_74); 
	Object_Nothing* Nothing_gen_32 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_32 = (* Obj_gen_39->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_39);
	goto label_33_;
	}
// end code block
// If test
	label_40_:;
	label_41_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_76 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_77 = NULL; // Default New Var reg of type: Str
	Str_gen_77 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_77->_string_value = "How did we get here?";
Str_gen_76 = Str_gen_77; // generate method left exp complete.
	Object_Obj* Obj_gen_40 = NULL; // Default New Var reg of type: Obj
	Obj_gen_40 = ( (Object_Obj* )Str_gen_76); 
	Object_Nothing* Nothing_gen_33 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_33 = (* Obj_gen_40->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_40);
	goto label_33_;
	}
// end code block
	label_33_:;
// If Else List end. 
// If Else List Begin. 
// If test
	label_46_:;
	{
	Object_Boolean* Boolean_gen_37 = NULL; // Default New Var reg of type: Boolean
// Generate Typed Value 
	Object_Boolean* Boolean_gen_38 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_38 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_38->_bool_value = 1;
		Boolean_gen_37 = Boolean_gen_38;
		if (1==Boolean_gen_37->_bool_value)
		{
			 goto label_45_; 
		}
		else
		{
			 goto label_44_; 
		}
	}
	label_45_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_78 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_79 = NULL; // Default New Var reg of type: Str
	Str_gen_79 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_79->_string_value = "Error";
Str_gen_78 = Str_gen_79; // generate method left exp complete.
	Object_Obj* Obj_gen_41 = NULL; // Default New Var reg of type: Obj
	Obj_gen_41 = ( (Object_Obj* )Str_gen_78); 
	Object_Nothing* Nothing_gen_34 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_34 = (* Obj_gen_41->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_41);
	goto label_44_;
	}
// end code block
	label_44_:;
// If Else List end. 
// Begin Method Call Generation .
	Object_Str* Str_gen_80 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_81 = NULL; // Default New Var reg of type: Str
	Str_gen_81 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_81->_string_value = "After If Block";
Str_gen_80 = Str_gen_81; // generate method left exp complete.
	Object_Obj* Obj_gen_42 = NULL; // Default New Var reg of type: Obj
	Obj_gen_42 = ( (Object_Obj* )Str_gen_80); 
	Object_Nothing* Nothing_gen_35 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_35 = (* Obj_gen_42->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_42);
	Object_Bottom* Bottom_gen_21 = NULL; // Default New Var reg of type: Bottom
// Begin Assignment Gen Value side. 
// Begin Method Call Generation .
	Object_Int* Int_gen_191 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_192 = NULL; // Default New Var reg of type: Int
	Int_gen_192 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_192->_int_value = 10;
	Int_gen_191 = Int_gen_192; // evaluated argument 
	Object_Int* Int_gen_193 = NULL; // Default New Var reg of type: Int
	Int_gen_193 = ( (Object_Int* )Int_gen_191); 
	Object_Int* Int_gen_194 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_195 = NULL; // Default New Var reg of type: Int
	Int_gen_195 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_195->_int_value = 2;
	Int_gen_194 = Int_gen_195; // evaluated argument 
	Object_Int* Int_gen_196 = NULL; // Default New Var reg of type: Int
	Int_gen_196 = ( (Object_Int* )Int_gen_194); 
	Object_Int* Int_gen_197 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_198 = NULL; // Default New Var reg of type: Int
	Int_gen_198 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_198->_int_value = 3;
	Int_gen_197 = Int_gen_198; // evaluated argument 
	Object_Int* Int_gen_199 = NULL; // Default New Var reg of type: Int
	Int_gen_199 = ( (Object_Int* )Int_gen_197); 
	Object_Bottom* Bottom_gen_22 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_22 = (*GLOBAL_Class_Bottom.Class_Bottom_Method_Bottom)(Int_gen_193,Int_gen_196,Int_gen_199);
	Bottom_gen_21 = Bottom_gen_22 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Bottom* Bottom_gen_23 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_23 = ( (Object_Bottom* )Bottom_gen_21); 
	 // Assigning var e to Bottom_gen_23
	Bottom_gen_7 = Bottom_gen_23;
// End Assignment Statment
// Begin Method Call Generation .
	Object_Bottom* Bottom_gen_24 = NULL; // Default New Var reg of type: Bottom
	Object_Bottom* Bottom_gen_25 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_25 = ( (Object_Bottom* )Bottom_gen_7); 
// Setting variable Bottom_gen_7 to the new value
	Bottom_gen_7 = Bottom_gen_25;
Bottom_gen_24 = Bottom_gen_25; // generate method left exp complete.
	Object_Bottom* Bottom_gen_26 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_26 = ( (Object_Bottom* )Bottom_gen_24); 
	Object_Bottom* Bottom_gen_27 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_27 = (* Bottom_gen_26->_class_pointer->Class_Bottom_Method_RunAlways)(Bottom_gen_26);
// If Else List Begin. 
// If test
	label_51_:;
	{
	Object_Boolean* Boolean_gen_39 = NULL; // Default New Var reg of type: Boolean
// Start Boolean Expression emit.
	Object_Boolean* Boolean_gen_40 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_41 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_42 = NULL; // Default New Var reg of type: Boolean
	{
/// L EXPRESSION AND begin.
	Object_Int* Int_gen_200 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_201 = NULL; // Default New Var reg of type: Int
	Int_gen_201 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_201->_int_value = 3;
// After Left Math Eval.
	Int_gen_200 = Int_gen_201; // evaled left of expression.
	Object_Int* Int_gen_202 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_203 = NULL; // Default New Var reg of type: Int
	Int_gen_203 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_203->_int_value = 5;
// After Right  Math Eval.
	Int_gen_202 = Int_gen_203; // evaled right of expression.
	Object_Boolean* Boolean_gen_43 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_43 = (*Int_gen_200->_class_pointer->Class_Int_Method_LESS)(Int_gen_200, Int_gen_202);
	Boolean_gen_41 = Boolean_gen_43; // evaled left of AND expression.
	if (0==Boolean_gen_41->_bool_value)
	{
		Boolean_gen_40 = Boolean_gen_41;
		 goto label_53_; 
	}
	else
	{
		 goto label_54_; 
	}
	label_54_:;
/// R expression AND begin.
	{
	Object_Int* Int_gen_204 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_205 = NULL; // Default New Var reg of type: Int
	Int_gen_205 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_205->_int_value = 14;
// After Left Math Eval.
	Int_gen_204 = Int_gen_205; // evaled left of expression.
	Object_Int* Int_gen_206 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_207 = NULL; // Default New Var reg of type: Int
	Int_gen_207 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_207->_int_value = 1;
// After Right  Math Eval.
	Int_gen_206 = Int_gen_207; // evaled right of expression.
	Object_Boolean* Boolean_gen_44 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_44 = (*Int_gen_204->_class_pointer->Class_Int_Method_MORE)(Int_gen_204, Int_gen_206);
		Boolean_gen_40 = Boolean_gen_44; // evaled right of AND expression.
	goto label_53_;
	}
// end AND short circuit.
	label_53_:;
	}
		Boolean_gen_39 = Boolean_gen_40;
		if (1==Boolean_gen_39->_bool_value)
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
	Object_Str* Str_gen_82 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_83 = NULL; // Default New Var reg of type: Str
	Str_gen_83 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_83->_string_value = "Good Result.";
Str_gen_82 = Str_gen_83; // generate method left exp complete.
	Object_Obj* Obj_gen_43 = NULL; // Default New Var reg of type: Obj
	Obj_gen_43 = ( (Object_Obj* )Str_gen_82); 
	Object_Nothing* Nothing_gen_36 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_36 = (* Obj_gen_43->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_43);
	goto label_49_;
	}
// end code block
	label_49_:;
// If Else List end. 
	Object_Int* Int_gen_208 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
// Generate Typed Value 
	Object_Int* Int_gen_209 = NULL; // Default New Var reg of type: Int
	Int_gen_209 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_209->_int_value = 5;
	Int_gen_208 = Int_gen_209 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Int* Int_gen_210 = NULL; // Default New Var reg of type: Int
	Int_gen_210 = ( (Object_Int* )Int_gen_208); 
	 // Assigning var abc to Int_gen_210
	Int_gen_136 = Int_gen_210;
// End Assignment Statment
// Begin Method Call Generation .
	Object_Str* Str_gen_84 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_85 = NULL; // Default New Var reg of type: Str
	Str_gen_85 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_85->_string_value = "Waiting for User Input, enter a number:";
Str_gen_84 = Str_gen_85; // generate method left exp complete.
	Object_Obj* Obj_gen_44 = NULL; // Default New Var reg of type: Obj
	Obj_gen_44 = ( (Object_Obj* )Str_gen_84); 
	Object_Nothing* Nothing_gen_37 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_37 = (* Obj_gen_44->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_44);
// Begin Method Call Generation .
	Object_Int* Int_gen_211 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_212 = NULL; // Default New Var reg of type: Int
	Int_gen_212 = ( (Object_Int* )Int_gen_136); 
// Setting variable Int_gen_136 to the new value
	Int_gen_136 = Int_gen_212;
Int_gen_211 = Int_gen_212; // generate method left exp complete.
	Object_Int* Int_gen_213 = NULL; // Default New Var reg of type: Int
	Int_gen_213 = ( (Object_Int* )Int_gen_211); 
	Object_Int* Int_gen_214 = NULL; // Default New Var reg of type: Int
	Int_gen_214 = (* Int_gen_213->_class_pointer->Class_Int_Method_READ)(Int_gen_213);
//While loop start.
	Object_Boolean* Boolean_gen_45 = NULL; // Default New Var reg of type: Boolean
// Condition start
	label_57_:;
	{
	Object_Int* Int_gen_215 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_216 = NULL; // Default New Var reg of type: Int
	Int_gen_216 = ( (Object_Int* )Int_gen_136); 
// Setting variable Int_gen_136 to the new value
	Int_gen_136 = Int_gen_216;
// After Left Math Eval.
	Int_gen_215 = Int_gen_216; // evaled left of expression.
	Object_Int* Int_gen_217 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_218 = NULL; // Default New Var reg of type: Int
	Int_gen_218 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_218->_int_value = 5;
// After Right  Math Eval.
	Int_gen_217 = Int_gen_218; // evaled right of expression.
	Object_Boolean* Boolean_gen_46 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_46 = (*Int_gen_215->_class_pointer->Class_Int_Method_MORE)(Int_gen_215, Int_gen_217);
// Condition test
		Boolean_gen_45 = Boolean_gen_46 ; 
	if (1==Boolean_gen_45->_bool_value)
	{
		 goto label_56_; 
	}
	else
	{
		 goto label_58_; 
	}
	}
// Loop start
	label_56_:;
	{
	Object_Int* Int_gen_219 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_220 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_221 = NULL; // Default New Var reg of type: Int
	Int_gen_221 = ( (Object_Int* )Int_gen_136); 
// Setting variable Int_gen_136 to the new value
	Int_gen_136 = Int_gen_221;
// After Left Math Eval.
	Int_gen_220 = Int_gen_221; // evaled left of expression.
	Object_Int* Int_gen_222 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_223 = NULL; // Default New Var reg of type: Int
	Int_gen_223 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_223->_int_value = 1;
// After Right  Math Eval.
	Int_gen_222 = Int_gen_223; // evaled right of expression.
	Object_Int* Int_gen_224 = NULL; // Default New Var reg of type: Int
	Int_gen_224 = (*Int_gen_220->_class_pointer->Class_Int_Method_MINUS)(Int_gen_220, Int_gen_222);
	Int_gen_219 = Int_gen_224 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Int* Int_gen_225 = NULL; // Default New Var reg of type: Int
	Int_gen_225 = ( (Object_Int* )Int_gen_219); 
	 // Assigning var abc to Int_gen_225
	Int_gen_136 = Int_gen_225;
// End Assignment Statment
// Begin Method Call Generation .
	Object_Str* Str_gen_86 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_87 = NULL; // Default New Var reg of type: Str
	Str_gen_87 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_87->_string_value = "Input Test Complete.";
Str_gen_86 = Str_gen_87; // generate method left exp complete.
	Object_Obj* Obj_gen_45 = NULL; // Default New Var reg of type: Obj
	Obj_gen_45 = ( (Object_Obj* )Str_gen_86); 
	Object_Nothing* Nothing_gen_38 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_38 = (* Obj_gen_45->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_45);
	goto label_57_; 
	}
// Loop exit
	label_58_:;
	Object_Str* Str_gen_88 = NULL; // Default New Var reg of type: Str
// Begin Assignment Gen Value side. 
// Generate Typed Value 
	Object_Str* Str_gen_89 = NULL; // Default New Var reg of type: Str
	Str_gen_89 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_89->_string_value = "Hello";
	Str_gen_88 = Str_gen_89 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Str* Str_gen_90 = NULL; // Default New Var reg of type: Str
	Str_gen_90 = ( (Object_Str* )Str_gen_88); 
	 // Assigning var xyz to Str_gen_90
	Str_gen_36 = Str_gen_90;
// End Assignment Statment
// Begin Method Call Generation .
	Object_Str* Str_gen_91 = NULL; // Default New Var reg of type: Str
	Object_Str* Str_gen_92 = NULL; // Default New Var reg of type: Str
	Str_gen_92 = ( (Object_Str* )Str_gen_36); 
// Setting variable Str_gen_36 to the new value
	Str_gen_36 = Str_gen_92;
Str_gen_91 = Str_gen_92; // generate method left exp complete.
	Object_Obj* Obj_gen_46 = NULL; // Default New Var reg of type: Obj
	Obj_gen_46 = ( (Object_Obj* )Str_gen_91); 
	Object_Nothing* Nothing_gen_39 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_39 = (* Obj_gen_46->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_46);
	Object_Str* Str_gen_93 = NULL; // Default New Var reg of type: Str
// Begin Assignment Gen Value side. 
// Generate Typed Value 
	Object_Str* Str_gen_94 = NULL; // Default New Var reg of type: Str
	Str_gen_94 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_94->_string_value = "world";
	Str_gen_93 = Str_gen_94 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Str* Str_gen_95 = NULL; // Default New Var reg of type: Str
	Str_gen_95 = ( (Object_Str* )Str_gen_93); 
	 // Assigning var xyza to Str_gen_95
	Str_gen_37 = Str_gen_95;
// End Assignment Statment
// Begin Method Call Generation .
	Object_Str* Str_gen_96 = NULL; // Default New Var reg of type: Str
	Object_Str* Str_gen_97 = NULL; // Default New Var reg of type: Str
	Str_gen_97 = ( (Object_Str* )Str_gen_37); 
// Setting variable Str_gen_37 to the new value
	Str_gen_37 = Str_gen_97;
Str_gen_96 = Str_gen_97; // generate method left exp complete.
	Object_Str* Str_gen_98 = NULL; // Default New Var reg of type: Str
	Str_gen_98 = ( (Object_Str* )Str_gen_96); 
	Object_Str* Str_gen_99 = NULL; // Default New Var reg of type: Str
	Str_gen_99 = (* Str_gen_98->_class_pointer->Class_Str_Method_READ)(Str_gen_98);
// Begin Method Call Generation .
	Object_Str* Str_gen_100 = NULL; // Default New Var reg of type: Str
	Object_Str* Str_gen_101 = NULL; // Default New Var reg of type: Str
// Before Left Math Eval.
	Object_Str* Str_gen_102 = NULL; // Default New Var reg of type: Str
	Str_gen_102 = ( (Object_Str* )Str_gen_36); 
// Setting variable Str_gen_36 to the new value
	Str_gen_36 = Str_gen_102;
// After Left Math Eval.
	Str_gen_101 = Str_gen_102; // evaled left of expression.
	Object_Str* Str_gen_103 = NULL; // Default New Var reg of type: Str
// Before Right Math Eval.
	Object_Str* Str_gen_104 = NULL; // Default New Var reg of type: Str
	Str_gen_104 = ( (Object_Str* )Str_gen_37); 
// Setting variable Str_gen_37 to the new value
	Str_gen_37 = Str_gen_104;
// After Right  Math Eval.
	Str_gen_103 = Str_gen_104; // evaled right of expression.
	Object_Str* Str_gen_105 = NULL; // Default New Var reg of type: Str
	Str_gen_105 = (*Str_gen_101->_class_pointer->Class_Str_Method_PLUS)(Str_gen_101, Str_gen_103);
Str_gen_100 = Str_gen_105; // generate method left exp complete.
	Object_Obj* Obj_gen_47 = NULL; // Default New Var reg of type: Obj
	Obj_gen_47 = ( (Object_Obj* )Str_gen_100); 
	Object_Nothing* Nothing_gen_40 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_40 = (* Obj_gen_47->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_47);
// Begin Method Call Generation .
	Object_Obj* Obj_gen_48 = NULL; // Default New Var reg of type: Obj
// Begin Method Call Generation .
	Object_Obj* Obj_gen_49 = NULL; // Default New Var reg of type: Obj
	Obj_gen_49 = (*GLOBAL_Class_Obj.Class_Obj_Method_Obj)();
Obj_gen_48 = Obj_gen_49; // generate method left exp complete.
	Object_Obj* Obj_gen_50 = NULL; // Default New Var reg of type: Obj
	Obj_gen_50 = ( (Object_Obj* )Obj_gen_48); 
	Object_Nothing* Nothing_gen_41 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_41 = (* Obj_gen_50->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_50);
	Object_Pt* Pt_gen_9 = NULL; // Default New Var reg of type: Pt
// Begin Assignment Gen Value side. 
// Begin Method Call Generation .
	Object_Int* Int_gen_226 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_227 = NULL; // Default New Var reg of type: Int
	Int_gen_227 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_227->_int_value = 3;
	Int_gen_226 = Int_gen_227; // evaluated argument 
	Object_Int* Int_gen_228 = NULL; // Default New Var reg of type: Int
	Int_gen_228 = ( (Object_Int* )Int_gen_226); 
	Object_Int* Int_gen_229 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_230 = NULL; // Default New Var reg of type: Int
	Int_gen_230 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_230->_int_value = 4;
	Int_gen_229 = Int_gen_230; // evaluated argument 
	Object_Int* Int_gen_231 = NULL; // Default New Var reg of type: Int
	Int_gen_231 = ( (Object_Int* )Int_gen_229); 
	Object_Pt* Pt_gen_10 = NULL; // Default New Var reg of type: Pt
	Pt_gen_10 = (*GLOBAL_Class_Pt.Class_Pt_Method_Pt)(Int_gen_228,Int_gen_231);
	Pt_gen_9 = Pt_gen_10 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Pt* Pt_gen_11 = NULL; // Default New Var reg of type: Pt
	Pt_gen_11 = ( (Object_Pt* )Pt_gen_9); 
	 // Assigning var a_point to Pt_gen_11
	Pt_gen_6 = Pt_gen_11;
// End Assignment Statment
	Object_Pt* Pt_gen_12 = NULL; // Default New Var reg of type: Pt
// Begin Assignment Gen Value side. 
// Begin Method Call Generation .
	Object_Int* Int_gen_232 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_233 = NULL; // Default New Var reg of type: Int
	Int_gen_233 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_233->_int_value = 10;
	Int_gen_232 = Int_gen_233; // evaluated argument 
	Object_Int* Int_gen_234 = NULL; // Default New Var reg of type: Int
	Int_gen_234 = ( (Object_Int* )Int_gen_232); 
	Object_Int* Int_gen_235 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_236 = NULL; // Default New Var reg of type: Int
	Int_gen_236 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_236->_int_value = 100;
	Int_gen_235 = Int_gen_236; // evaluated argument 
	Object_Int* Int_gen_237 = NULL; // Default New Var reg of type: Int
	Int_gen_237 = ( (Object_Int* )Int_gen_235); 
	Object_Pt* Pt_gen_13 = NULL; // Default New Var reg of type: Pt
	Pt_gen_13 = (*GLOBAL_Class_Pt.Class_Pt_Method_Pt)(Int_gen_234,Int_gen_237);
	Pt_gen_12 = Pt_gen_13 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Pt* Pt_gen_14 = NULL; // Default New Var reg of type: Pt
	Pt_gen_14 = ( (Object_Pt* )Pt_gen_12); 
	 // Assigning var b_point to Pt_gen_14
	Pt_gen_7 = Pt_gen_14;
// End Assignment Statment
	Object_Pt* Pt_gen_15 = NULL; // Default New Var reg of type: Pt
// Begin Assignment Gen Value side. 
	Object_Pt* Pt_gen_16 = NULL; // Default New Var reg of type: Pt
// Before Left Math Eval.
	Object_Pt* Pt_gen_17 = NULL; // Default New Var reg of type: Pt
	Pt_gen_17 = ( (Object_Pt* )Pt_gen_6); 
// Setting variable Pt_gen_6 to the new value
	Pt_gen_6 = Pt_gen_17;
// After Left Math Eval.
	Pt_gen_16 = Pt_gen_17; // evaled left of expression.
	Object_Pt* Pt_gen_18 = NULL; // Default New Var reg of type: Pt
// Before Right Math Eval.
	Object_Pt* Pt_gen_19 = NULL; // Default New Var reg of type: Pt
	Pt_gen_19 = ( (Object_Pt* )Pt_gen_7); 
// Setting variable Pt_gen_7 to the new value
	Pt_gen_7 = Pt_gen_19;
// After Right  Math Eval.
	Pt_gen_18 = Pt_gen_19; // evaled right of expression.
	Object_Pt* Pt_gen_20 = NULL; // Default New Var reg of type: Pt
	Pt_gen_20 = (*Pt_gen_16->_class_pointer->Class_Pt_Method_PLUS)(Pt_gen_16, Pt_gen_18);
	Pt_gen_15 = Pt_gen_20 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Pt* Pt_gen_21 = NULL; // Default New Var reg of type: Pt
	Pt_gen_21 = ( (Object_Pt* )Pt_gen_15); 
	 // Assigning var c_point to Pt_gen_21
	Pt_gen_8 = Pt_gen_21;
// End Assignment Statment
// Begin Method Call Generation .
	Object_Pt* Pt_gen_22 = NULL; // Default New Var reg of type: Pt
	Object_Pt* Pt_gen_23 = NULL; // Default New Var reg of type: Pt
	Pt_gen_23 = ( (Object_Pt* )Pt_gen_8); 
// Setting variable Pt_gen_8 to the new value
	Pt_gen_8 = Pt_gen_23;
Pt_gen_22 = Pt_gen_23; // generate method left exp complete.
	Object_Obj* Obj_gen_51 = NULL; // Default New Var reg of type: Obj
	Obj_gen_51 = ( (Object_Obj* )Pt_gen_22); 
	Object_Nothing* Nothing_gen_42 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_42 = (* Obj_gen_51->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_51);

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
	GLOBAL_Class_Pt.Class_Pt_Method_Pt=Class_Pt_Method_Pt;
	GLOBAL_Class_Pt.Class_Pt_Method_STR=Class_Pt_Method_STR;
	GLOBAL_Class_Pt.Class_Obj_Method_PRINT=Class_Obj_Method_PRINT;
	GLOBAL_Class_Pt.Class_Pt_Method_anewtest=Class_Pt_Method_anewtest;
	GLOBAL_Class_Pt.Class_Pt_Method_PLUS=Class_Pt_Method_PLUS;
	GLOBAL_Class_Pt.Class_Pt_Method__x=Class_Pt_Method__x;
	GLOBAL_Class_Pt.Class_Pt_Method__y=Class_Pt_Method__y;
	GLOBAL_Class_Top.Class_Top_Method_Top=Class_Top_Method_Top;
	GLOBAL_Class_Top.Class_Obj_Method_STR=Class_Obj_Method_STR;
	GLOBAL_Class_Top.Class_Obj_Method_PRINT=Class_Obj_Method_PRINT;
	GLOBAL_Class_Top.Class_Top_Method_foo=Class_Top_Method_foo;
	GLOBAL_Class_Top.Class_Top_Method_forever=Class_Top_Method_forever;
	GLOBAL_Class_Top.Class_Top_Method_test=Class_Top_Method_test;
	GLOBAL_Class_Treta.Class_Treta_Method_Treta=Class_Treta_Method_Treta;
	GLOBAL_Class_Treta.Class_Obj_Method_STR=Class_Obj_Method_STR;
	GLOBAL_Class_Treta.Class_Obj_Method_PRINT=Class_Obj_Method_PRINT;
	GLOBAL_Class_Treta.Class_Treta_Method_test3=Class_Treta_Method_test3;
	GLOBAL_Class_Treta.Class_Treta_Method_foo=Class_Treta_Method_foo;
	GLOBAL_Class_Treta.Class_Treta_Method_test1=Class_Treta_Method_test1;
	GLOBAL_Class_Treta.Class_Treta_Method_test2=Class_Treta_Method_test2;
	GLOBAL_Class_Middle.Class_Middle_Method_Middle=Class_Middle_Method_Middle;
	GLOBAL_Class_Middle.Class_Obj_Method_STR=Class_Obj_Method_STR;
	GLOBAL_Class_Middle.Class_Obj_Method_PRINT=Class_Obj_Method_PRINT;
	GLOBAL_Class_Middle.Class_Middle_Method_foo=Class_Middle_Method_foo;
	GLOBAL_Class_Middle.Class_Middle_Method_forever=Class_Middle_Method_forever;
	GLOBAL_Class_Middle.Class_Top_Method_test=Class_Top_Method_test;
	GLOBAL_Class_Bottom.Class_Bottom_Method_Bottom=Class_Bottom_Method_Bottom;
	GLOBAL_Class_Bottom.Class_Obj_Method_STR=Class_Obj_Method_STR;
	GLOBAL_Class_Bottom.Class_Obj_Method_PRINT=Class_Obj_Method_PRINT;
	GLOBAL_Class_Bottom.Class_Middle_Method_foo=Class_Middle_Method_foo;
	GLOBAL_Class_Bottom.Class_Bottom_Method_forever=Class_Bottom_Method_forever;
	GLOBAL_Class_Bottom.Class_Top_Method_test=Class_Top_Method_test;
	GLOBAL_Class_Bottom.Class_Bottom_Method_bar=Class_Bottom_Method_bar;
	GLOBAL_Class_Bottom.Class_Bottom_Method_boolTest=Class_Bottom_Method_boolTest;
	GLOBAL_Class_Bottom.Class_Bottom_Method_RunAlways=Class_Bottom_Method_RunAlways;
	class_MAIN_method_MAIN();
	return 0;
}
