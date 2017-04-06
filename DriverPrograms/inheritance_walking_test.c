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
typedef struct Class_A Class_A;
typedef struct Object_A Object_A;
typedef struct Class_B Class_B;
typedef struct Object_B Object_B;
typedef struct Class_C Class_C;
typedef struct Object_C Object_C;
typedef struct Class_D Class_D;
typedef struct Object_D Object_D;

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

struct Class_A{
	Object_A* (*Class_A_Method_A)();
	Object_Str* (*Class_Obj_Method_STR)(Object_Obj* _this_ptr);
	Object_Nothing* (*Class_Obj_Method_PRINT)(Object_Obj* _this_ptr);
	Object_A* (*Class_A_Method_foo)(Object_A* _this_ptr);
} ;

struct Object_A{
	Class_A *_class_pointer;
} ;

struct Class_B{
	Object_B* (*Class_B_Method_B)();
	Object_Str* (*Class_Obj_Method_STR)(Object_Obj* _this_ptr);
	Object_Nothing* (*Class_Obj_Method_PRINT)(Object_Obj* _this_ptr);
	Object_A* (*Class_B_Method_foo)(Object_B* _this_ptr);
} ;

struct Object_B{
	Class_B *_class_pointer;
} ;

struct Class_C{
	Object_C* (*Class_C_Method_C)();
	Object_Str* (*Class_Obj_Method_STR)(Object_Obj* _this_ptr);
	Object_Nothing* (*Class_Obj_Method_PRINT)(Object_Obj* _this_ptr);
	Object_B* (*Class_C_Method_foo)(Object_C* _this_ptr);
} ;

struct Object_C{
	Class_C *_class_pointer;
} ;

struct Class_D{
	Object_D* (*Class_D_Method_D)();
	Object_Str* (*Class_Obj_Method_STR)(Object_Obj* _this_ptr);
	Object_Nothing* (*Class_Obj_Method_PRINT)(Object_Obj* _this_ptr);
	Object_C* (*Class_D_Method_foo)(Object_D* _this_ptr);
} ;

struct Object_D{
	Class_D *_class_pointer;
} ;

	Class_Obj	GLOBAL_Class_Obj;
	Class_Nothing	GLOBAL_Class_Nothing;
	Class_Str	GLOBAL_Class_Str;
	Class_Int	GLOBAL_Class_Int;
	Class_Boolean	GLOBAL_Class_Boolean;
	Class_A	GLOBAL_Class_A;
	Class_B	GLOBAL_Class_B;
	Class_C	GLOBAL_Class_C;
	Class_D	GLOBAL_Class_D;


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

Object_A* Class_A_Method_A()
{
// Adding Arguments to the named map 
// allocating variables.
	Object_A * returnValue = (Object_A * )malloc(sizeof(Object_A));
	returnValue->_class_pointer = &GLOBAL_Class_A;
	return returnValue;

}

Object_A* Class_A_Method_foo(Object_A* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// Begin Method Call Generation .
	Object_Str* Str_gen_0 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_1 = NULL; // Default New Var reg of type: Str
	Str_gen_1 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_1->_string_value = "A Class";
Str_gen_0 = Str_gen_1; // generate method left exp complete.
	Object_Obj* Obj_gen_0 = NULL; // Default New Var reg of type: Obj
	Obj_gen_0 = ( (Object_Obj* )Str_gen_0); 
	Object_Nothing* Nothing_gen_0 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_0 = (* Obj_gen_0->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_0);
// Generate return statement.
	Object_A* A_gen_0 = NULL; // Default New Var reg of type: A
	Object_A* A_gen_1 = NULL; // Default New Var reg of type: A
	A_gen_1 =( (Object_A* )_this_ptr);
	A_gen_0 = ((Object_A* )A_gen_1); // return value .
	A_gen_0->_class_pointer= &GLOBAL_Class_A;
	return A_gen_0;

}

Object_B* Class_B_Method_B()
{
// Adding Arguments to the named map 
// allocating variables.
	Object_B * returnValue = (Object_B * )malloc(sizeof(Object_B));
	returnValue->_class_pointer = &GLOBAL_Class_B;
	return returnValue;

}

Object_A* Class_B_Method_foo(Object_B* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// Begin Method Call Generation .
	Object_Str* Str_gen_2 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_3 = NULL; // Default New Var reg of type: Str
	Str_gen_3 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_3->_string_value = "B Class";
Str_gen_2 = Str_gen_3; // generate method left exp complete.
	Object_Obj* Obj_gen_1 = NULL; // Default New Var reg of type: Obj
	Obj_gen_1 = ( (Object_Obj* )Str_gen_2); 
	Object_Nothing* Nothing_gen_1 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_1 = (* Obj_gen_1->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_1);
// Generate return statement.
	Object_A* A_gen_2 = NULL; // Default New Var reg of type: A
// Begin Method Call Generation .
	Object_A* A_gen_3 = NULL; // Default New Var reg of type: A
	A_gen_3 = (*GLOBAL_Class_A.Class_A_Method_A)();
	A_gen_2 = ((Object_A* )A_gen_3); // return value .
	A_gen_2->_class_pointer= &GLOBAL_Class_A;
	return A_gen_2;

}

Object_C* Class_C_Method_C()
{
// Adding Arguments to the named map 
// allocating variables.
	Object_C * returnValue = (Object_C * )malloc(sizeof(Object_C));
	returnValue->_class_pointer = &GLOBAL_Class_C;
	return returnValue;

}

Object_B* Class_C_Method_foo(Object_C* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// Begin Method Call Generation .
	Object_Str* Str_gen_4 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_5 = NULL; // Default New Var reg of type: Str
	Str_gen_5 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_5->_string_value = "C Class";
Str_gen_4 = Str_gen_5; // generate method left exp complete.
	Object_Obj* Obj_gen_2 = NULL; // Default New Var reg of type: Obj
	Obj_gen_2 = ( (Object_Obj* )Str_gen_4); 
	Object_Nothing* Nothing_gen_2 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_2 = (* Obj_gen_2->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_2);
// Generate return statement.
	Object_B* B_gen_0 = NULL; // Default New Var reg of type: B
// Begin Method Call Generation .
	Object_B* B_gen_1 = NULL; // Default New Var reg of type: B
	B_gen_1 = (*GLOBAL_Class_B.Class_B_Method_B)();
	B_gen_0 = ((Object_B* )B_gen_1); // return value .
	B_gen_0->_class_pointer= &GLOBAL_Class_B;
	return B_gen_0;

}

Object_D* Class_D_Method_D()
{
// Adding Arguments to the named map 
// allocating variables.
	Object_D * returnValue = (Object_D * )malloc(sizeof(Object_D));
	returnValue->_class_pointer = &GLOBAL_Class_D;
	return returnValue;

}

Object_C* Class_D_Method_foo(Object_D* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// Begin Method Call Generation .
	Object_Str* Str_gen_6 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_7 = NULL; // Default New Var reg of type: Str
	Str_gen_7 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_7->_string_value = "D Class";
Str_gen_6 = Str_gen_7; // generate method left exp complete.
	Object_Obj* Obj_gen_3 = NULL; // Default New Var reg of type: Obj
	Obj_gen_3 = ( (Object_Obj* )Str_gen_6); 
	Object_Nothing* Nothing_gen_3 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_3 = (* Obj_gen_3->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_3);
// Generate return statement.
	Object_C* C_gen_0 = NULL; // Default New Var reg of type: C
// Begin Method Call Generation .
	Object_C* C_gen_1 = NULL; // Default New Var reg of type: C
	C_gen_1 = (*GLOBAL_Class_C.Class_C_Method_C)();
	C_gen_0 = ((Object_C* )C_gen_1); // return value .
	C_gen_0->_class_pointer= &GLOBAL_Class_C;
	return C_gen_0;

}

Object_Nothing* class_MAIN_method_MAIN()
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* Int_gen_0 = NULL; // Default New Var reg of type: Int
	Object_A* A_gen_4 = NULL; // Default New Var reg of type: A
	Object_Int* Int_gen_1 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
// Generate Typed Value 
	Object_Int* Int_gen_2 = NULL; // Default New Var reg of type: Int
	Int_gen_2 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_2->_int_value = 15;
	Int_gen_1 = Int_gen_2 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Int* Int_gen_3 = NULL; // Default New Var reg of type: Int
	Int_gen_3 = ( (Object_Int* )Int_gen_1); 
	 // Assigning var counter to Int_gen_3
	Int_gen_0 = Int_gen_3;
// End Assignment Statment
	Object_D* D_gen_0 = NULL; // Default New Var reg of type: D
// Begin Assignment Gen Value side. 
// Begin Method Call Generation .
	Object_D* D_gen_1 = NULL; // Default New Var reg of type: D
	D_gen_1 = (*GLOBAL_Class_D.Class_D_Method_D)();
	D_gen_0 = D_gen_1 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_A* A_gen_5 = NULL; // Default New Var reg of type: A
	A_gen_5 = ( (Object_A* )D_gen_0); 
	 // Assigning var myClass to A_gen_5
	A_gen_4 = A_gen_5;
// End Assignment Statment
//While loop start.
	Object_Boolean* Boolean_gen_0 = NULL; // Default New Var reg of type: Boolean
// Condition start
	label_1_:;
	{
	Object_Int* Int_gen_4 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_5 = NULL; // Default New Var reg of type: Int
	Int_gen_5 = ( (Object_Int* )Int_gen_0); 
// Setting variable Int_gen_0 to the new value
	Int_gen_0 = Int_gen_5;
// After Left Math Eval.
	Int_gen_4 = Int_gen_5; // evaled left of expression.
	Object_Int* Int_gen_6 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_7 = NULL; // Default New Var reg of type: Int
	Int_gen_7 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_7->_int_value = 0;
// After Right  Math Eval.
	Int_gen_6 = Int_gen_7; // evaled right of expression.
	Object_Boolean* Boolean_gen_1 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_1 = (*Int_gen_4->_class_pointer->Class_Int_Method_MORE)(Int_gen_4, Int_gen_6);
// Condition test
		Boolean_gen_0 = Boolean_gen_1 ; 
	if (1==Boolean_gen_0->_bool_value)
	{
		 goto label_0_; 
	}
	else
	{
		 goto label_2_; 
	}
	}
// Loop start
	label_0_:;
	{
	Object_A* A_gen_6 = NULL; // Default New Var reg of type: A
// Begin Assignment Gen Value side. 
// Begin Method Call Generation .
	Object_A* A_gen_7 = NULL; // Default New Var reg of type: A
	Object_A* A_gen_8 = NULL; // Default New Var reg of type: A
	A_gen_8 = ( (Object_A* )A_gen_4); 
// Setting variable A_gen_4 to the new value
	A_gen_4 = A_gen_8;
A_gen_7 = A_gen_8; // generate method left exp complete.
	Object_A* A_gen_9 = NULL; // Default New Var reg of type: A
	A_gen_9 = ( (Object_A* )A_gen_7); 
	Object_A* A_gen_10 = NULL; // Default New Var reg of type: A
	A_gen_10 = (* A_gen_9->_class_pointer->Class_A_Method_foo)(A_gen_9);
	A_gen_6 = A_gen_10 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_A* A_gen_11 = NULL; // Default New Var reg of type: A
	A_gen_11 = ( (Object_A* )A_gen_6); 
	 // Assigning var myClass to A_gen_11
	A_gen_4 = A_gen_11;
// End Assignment Statment
	Object_Int* Int_gen_8 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_9 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_10 = NULL; // Default New Var reg of type: Int
	Int_gen_10 = ( (Object_Int* )Int_gen_0); 
// Setting variable Int_gen_0 to the new value
	Int_gen_0 = Int_gen_10;
// After Left Math Eval.
	Int_gen_9 = Int_gen_10; // evaled left of expression.
	Object_Int* Int_gen_11 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_12 = NULL; // Default New Var reg of type: Int
	Int_gen_12 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_12->_int_value = 1;
// After Right  Math Eval.
	Int_gen_11 = Int_gen_12; // evaled right of expression.
	Object_Int* Int_gen_13 = NULL; // Default New Var reg of type: Int
	Int_gen_13 = (*Int_gen_9->_class_pointer->Class_Int_Method_MINUS)(Int_gen_9, Int_gen_11);
	Int_gen_8 = Int_gen_13 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Int* Int_gen_14 = NULL; // Default New Var reg of type: Int
	Int_gen_14 = ( (Object_Int* )Int_gen_8); 
	 // Assigning var counter to Int_gen_14
	Int_gen_0 = Int_gen_14;
// End Assignment Statment
	goto label_1_; 
	}
// Loop exit
	label_2_:;

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
	GLOBAL_Class_A.Class_A_Method_A=Class_A_Method_A;
	GLOBAL_Class_A.Class_Obj_Method_STR=Class_Obj_Method_STR;
	GLOBAL_Class_A.Class_Obj_Method_PRINT=Class_Obj_Method_PRINT;
	GLOBAL_Class_A.Class_A_Method_foo=Class_A_Method_foo;
	GLOBAL_Class_B.Class_B_Method_B=Class_B_Method_B;
	GLOBAL_Class_B.Class_Obj_Method_STR=Class_Obj_Method_STR;
	GLOBAL_Class_B.Class_Obj_Method_PRINT=Class_Obj_Method_PRINT;
	GLOBAL_Class_B.Class_B_Method_foo=Class_B_Method_foo;
	GLOBAL_Class_C.Class_C_Method_C=Class_C_Method_C;
	GLOBAL_Class_C.Class_Obj_Method_STR=Class_Obj_Method_STR;
	GLOBAL_Class_C.Class_Obj_Method_PRINT=Class_Obj_Method_PRINT;
	GLOBAL_Class_C.Class_C_Method_foo=Class_C_Method_foo;
	GLOBAL_Class_D.Class_D_Method_D=Class_D_Method_D;
	GLOBAL_Class_D.Class_Obj_Method_STR=Class_Obj_Method_STR;
	GLOBAL_Class_D.Class_Obj_Method_PRINT=Class_Obj_Method_PRINT;
	GLOBAL_Class_D.Class_D_Method_foo=Class_D_Method_foo;
	class_MAIN_method_MAIN();
	return 0;
}
