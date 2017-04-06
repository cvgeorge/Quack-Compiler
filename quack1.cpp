#include <iostream>
#include <stdlib.h>
#include <sstream>

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
typedef struct Class_Top Class_Top;
typedef struct Object_Top Object_Top;
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
	Object_Boolean* (*Class_Str_Method_EQUALS)(Object_Str* _this_ptr, Object_Str* _other_string);
	Object_Boolean* (*Class_Str_Method_ATMOST)(Object_Str* _this_ptr, Object_Str* _other_string);
	Object_Boolean* (*Class_Str_Method_ATLEAST)(Object_Str* _this_ptr, Object_Str* _other_string);
	Object_Boolean* (*Class_Str_Method_LESS)(Object_Str* _this_ptr, Object_Str* _other_string);
	Object_Boolean* (*Class_Str_Method_MORE)(Object_Str* _this_ptr, Object_Str* _other_string);
} ;

struct Object_Str{
	Class_Str *_class_pointer;
	std::string _string_value;
} ;

struct Class_Int{
	Object_Int* (*Class_Int_Method_Int)();
	Object_Str* (*Class_Int_Method_STR)(Object_Int* _this_ptr);
	Object_Nothing* (*Class_Obj_Method_PRINT)(Object_Obj* _this_ptr);
	Object_Int* (*Class_Int_Method_PLUS)(Object_Int* _this_ptr, Object_Int* _other_int);
	Object_Int* (*Class_Int_Method_MINUS)(Object_Int* _this_ptr, Object_Int* _other_int);
	Object_Int* (*Class_Int_Method_TIMES)(Object_Int* _this_ptr, Object_Int* _other_int);
	Object_Int* (*Class_Int_Method_DIVIDE)(Object_Int* _this_ptr, Object_Int* _other_int);
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
	bool _bool_value;
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
<<<<<<< HEAD
	Object_Bottom* (*Class_Bottom_Method_RunAlways)(Object_Bottom* _this_ptr);
=======
>>>>>>> 4b6217d8e273d4a1fee1eb2c14853e397372a100
} ;

struct Object_Bottom{
	Class_Bottom *_class_pointer;
	Object_Int *abc;
	Object_Int *xyz;
	Object_Int *defer;
} ;

	Class_Obj	GLOBAL_Class_Obj;
	Class_Nothing	GLOBAL_Class_Nothing;
	Class_Str	GLOBAL_Class_Str;
	Class_Int	GLOBAL_Class_Int;
	Class_Boolean	GLOBAL_Class_Boolean;
	Class_Top	GLOBAL_Class_Top;
	Class_Middle	GLOBAL_Class_Middle;
	Class_Bottom	GLOBAL_Class_Bottom;


Object_Obj* Class_Obj_Method_Obj()
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Obj * returnValue = new Object_Obj();
	returnValue->_class_pointer = &GLOBAL_Class_Obj;
	return returnValue;

}

Object_Str* Class_Obj_Method_STR(Object_Obj* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Str* returnValue = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	const void * address = static_cast<const void*>(_this_ptr);
	std::stringstream str_stream;
	str_stream << address;
	returnValue->_string_value = str_stream.str(); 
	return returnValue;

}

Object_Nothing* Class_Obj_Method_PRINT(Object_Obj* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Str* print = (*_this_ptr->_class_pointer->Class_Obj_Method_STR)(_this_ptr);
	std::cout << print->_string_value << std::endl;
	Object_Nothing* returnValue = (*GLOBAL_Class_Nothing.Class_Nothing_Method_Nothing)();
	return returnValue;

}

Object_Nothing* Class_Nothing_Method_Nothing()
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Nothing * returnValue = new Object_Nothing();
	returnValue->_class_pointer = &GLOBAL_Class_Nothing;
	return returnValue;

}

Object_Str* Class_Nothing_Method_STR(Object_Nothing* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Str* returnValue = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	returnValue->_string_value = "none";
	return returnValue;

}

Object_Str* Class_Str_Method_Str()
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Str * returnValue = new Object_Str();
	returnValue->_class_pointer = &GLOBAL_Class_Str;
	returnValue->_string_value = "";
	return returnValue;

}

Object_Str* Class_Str_Method_PLUS(Object_Str* _this_ptr, Object_Str* _other_string)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Str* returnValue = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	returnValue->_string_value = _this_ptr->_string_value + _other_string->_string_value;
	return returnValue;

}

Object_Boolean* Class_Str_Method_EQUALS(Object_Str* _this_ptr, Object_Str* _other_string)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	returnValue->_bool_value =  _this_ptr->_string_value.compare( _other_string->_string_value)==0;
	return returnValue;

}

Object_Boolean* Class_Str_Method_ATMOST(Object_Str* _this_ptr, Object_Str* _other_string)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	returnValue->_bool_value =  _this_ptr->_string_value.compare( _other_string->_string_value)<=0;
	return returnValue;

}

Object_Boolean* Class_Str_Method_ATLEAST(Object_Str* _this_ptr, Object_Str* _other_string)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	returnValue->_bool_value =  _this_ptr->_string_value.compare( _other_string->_string_value)>=0;
	return returnValue;

}

Object_Boolean* Class_Str_Method_LESS(Object_Str* _this_ptr, Object_Str* _other_string)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	returnValue->_bool_value =  _this_ptr->_string_value.compare( _other_string->_string_value)<0;
	return returnValue;

}

Object_Boolean* Class_Str_Method_MORE(Object_Str* _this_ptr, Object_Str* _other_string)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	returnValue->_bool_value =  _this_ptr->_string_value.compare( _other_string->_string_value)>0;
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
	Object_Int * returnValue = new Object_Int();
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
	std::stringstream str_stream;
	str_stream << _this_ptr->_int_value;
	returnValue->_string_value = str_stream.str(); 
	return returnValue;

}

Object_Boolean* Class_Boolean_Method_Boolean()
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean * returnValue = new Object_Boolean();
	returnValue->_class_pointer = &GLOBAL_Class_Boolean;
	returnValue->_bool_value = false;
	return returnValue;

}

Object_Boolean* Class_Boolean_Method_EQUALS(Object_Boolean* _this_ptr, Object_Boolean* _other_bool)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	returnValue->_bool_value = (_this_ptr->_bool_value == _other_bool->_bool_value);
	return returnValue;

}

Object_Boolean* Class_Boolean_Method_AND(Object_Boolean* _this_ptr, Object_Boolean* _other_bool)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	returnValue->_bool_value = (_this_ptr->_bool_value && _other_bool->_bool_value);
	return returnValue;

}

Object_Boolean* Class_Boolean_Method_OR(Object_Boolean* _this_ptr, Object_Boolean* _other_bool)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	returnValue->_bool_value = (_this_ptr->_bool_value || _other_bool->_bool_value);
	return returnValue;

}

Object_Boolean* Class_Boolean_Method_NOT(Object_Boolean* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Boolean* returnValue = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	returnValue->_bool_value = (!_this_ptr->_bool_value);
	return returnValue;

}

Object_Str* Class_Boolean_Method_STR(Object_Boolean* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Str* returnValue = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	returnValue->_string_value = (_this_ptr->_bool_value ) ? ("true") : ("false") ;
	return returnValue;

}

Object_Top* Class_Top_Method_Top(Object_Int* x)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* Int_gen_0 = NULL; // Default New Var reg of type: Int
	Object_Top * returnValue = new Object_Top();
	returnValue->_class_pointer = &GLOBAL_Class_Top;
// Begin Method Call Generation .
	Object_Str* Str_gen_0 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_1 = NULL; // Default New Var reg of type: Str
	Str_gen_1 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_1->_string_value = "class Top(x:Int)";
Str_gen_0 = Str_gen_1; // generate method left exp complete.
	Object_Obj* Obj_gen_0 = NULL; // Default New Var reg of type: Obj
	Obj_gen_0 = ( (Object_Obj* )Str_gen_0); 
	Object_Nothing* Nothing_gen_0 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_0 = (* Obj_gen_0->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_0);
	Object_Int* Int_gen_1 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_2 = NULL; // Default New Var reg of type: Int
	Int_gen_2 = ( (Object_Int* )x); 
// Setting variable x to the new value
	x = Int_gen_2;
	Int_gen_1 = Int_gen_2 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	returnValue->abc = Int_gen_1; //store into this.
// End Assignment Statment
	return returnValue;

}

Object_Int* Class_Top_Method_foo(Object_Top* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// Begin Method Call Generation .
	Object_Str* Str_gen_2 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_3 = NULL; // Default New Var reg of type: Str
	Str_gen_3 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_3->_string_value = "def Top foo():Int";
Str_gen_2 = Str_gen_3; // generate method left exp complete.
	Object_Obj* Obj_gen_1 = NULL; // Default New Var reg of type: Obj
	Obj_gen_1 = ( (Object_Obj* )Str_gen_2); 
	Object_Nothing* Nothing_gen_1 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_1 = (* Obj_gen_1->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_1);
// Generate return statement.
	Object_Int* Int_gen_3 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_4 = NULL; // Default New Var reg of type: Int
	Int_gen_4 = _this_ptr->abc;
	Int_gen_3 = ((Object_Int* )Int_gen_4); // return value .
	Int_gen_3->_class_pointer= &GLOBAL_Class_Int;
	return Int_gen_3;

}

Object_Top* Class_Top_Method_forever(Object_Top* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* Int_gen_5 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_6 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_7 = NULL; // Default New Var reg of type: Int
	Int_gen_7 = _this_ptr->abc;
// After Left Math Eval.
	Int_gen_6 = Int_gen_7; // evaled left of expression.
	Object_Int* Int_gen_8 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_9 = NULL; // Default New Var reg of type: Int
	Int_gen_9 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_9->_int_value = 1;
// After Right  Math Eval.
	Int_gen_8 = Int_gen_9; // evaled right of expression.
	Object_Int* Int_gen_10 = NULL; // Default New Var reg of type: Int
	Int_gen_10 = (*Int_gen_6->_class_pointer->Class_Int_Method_MINUS)(Int_gen_6, Int_gen_8);
	Int_gen_5 = Int_gen_10 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	_this_ptr->abc = Int_gen_5; //store into this.
// End Assignment Statment
// Begin Method Call Generation .
	Object_Str* Str_gen_4 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_5 = NULL; // Default New Var reg of type: Str
	Str_gen_5 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_5->_string_value = "forever in () TOP!";
Str_gen_4 = Str_gen_5; // generate method left exp complete.
	Object_Obj* Obj_gen_2 = NULL; // Default New Var reg of type: Obj
	Obj_gen_2 = ( (Object_Obj* )Str_gen_4); 
	Object_Nothing* Nothing_gen_2 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_2 = (* Obj_gen_2->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_2);
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
	Object_Int* Int_gen_11 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_12 = NULL; // Default New Var reg of type: Int
	Int_gen_12 = _this_ptr->abc;
	Int_gen_11 = ((Object_Int* )Int_gen_12); // return value .
	Int_gen_11->_class_pointer= &GLOBAL_Class_Int;
	return Int_gen_11;

}

Object_Middle* Class_Middle_Method_Middle(Object_Int* x, Object_Int* y)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* Int_gen_13 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_14 = NULL; // Default New Var reg of type: Int
	Object_Middle * returnValue = new Object_Middle();
	returnValue->_class_pointer = &GLOBAL_Class_Middle;
// Begin Method Call Generation .
	Object_Str* Str_gen_6 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_7 = NULL; // Default New Var reg of type: Str
	Str_gen_7 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_7->_string_value = "class Middle(x:Int, y:Int) extends Top";
Str_gen_6 = Str_gen_7; // generate method left exp complete.
	Object_Obj* Obj_gen_3 = NULL; // Default New Var reg of type: Obj
	Obj_gen_3 = ( (Object_Obj* )Str_gen_6); 
	Object_Nothing* Nothing_gen_3 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_3 = (* Obj_gen_3->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_3);
	Object_Int* Int_gen_15 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_16 = NULL; // Default New Var reg of type: Int
	Int_gen_16 = ( (Object_Int* )x); 
// Setting variable x to the new value
	x = Int_gen_16;
	Int_gen_15 = Int_gen_16 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	returnValue->abc = Int_gen_15; //store into this.
// End Assignment Statment
	Object_Int* Int_gen_17 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_18 = NULL; // Default New Var reg of type: Int
	Int_gen_18 = ( (Object_Int* )y); 
// Setting variable y to the new value
	y = Int_gen_18;
	Int_gen_17 = Int_gen_18 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	returnValue->xyz = Int_gen_17; //store into this.
// End Assignment Statment
	return returnValue;

}

Object_Int* Class_Middle_Method_foo(Object_Middle* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// Begin Method Call Generation .
	Object_Str* Str_gen_8 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_9 = NULL; // Default New Var reg of type: Str
	Str_gen_9 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_9->_string_value = "def Middle foo():Int";
Str_gen_8 = Str_gen_9; // generate method left exp complete.
	Object_Obj* Obj_gen_4 = NULL; // Default New Var reg of type: Obj
	Obj_gen_4 = ( (Object_Obj* )Str_gen_8); 
	Object_Nothing* Nothing_gen_4 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_4 = (* Obj_gen_4->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_4);
// Generate return statement.
	Object_Int* Int_gen_19 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_20 = NULL; // Default New Var reg of type: Int
	Object_Middle* Middle_gen_0 = NULL; // Default New Var reg of type: Middle
// Begin Method Call Generation .
	Object_Int* Int_gen_21 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_22 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_23 = NULL; // Default New Var reg of type: Int
	Int_gen_23 = _this_ptr->abc;
// After Left Math Eval.
	Int_gen_22 = Int_gen_23; // evaled left of expression.
	Object_Int* Int_gen_24 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_25 = NULL; // Default New Var reg of type: Int
	Int_gen_25 = _this_ptr->xyz;
// After Right  Math Eval.
	Int_gen_24 = Int_gen_25; // evaled right of expression.
	Object_Int* Int_gen_26 = NULL; // Default New Var reg of type: Int
	Int_gen_26 = (*Int_gen_22->_class_pointer->Class_Int_Method_PLUS)(Int_gen_22, Int_gen_24);
	Int_gen_21 = Int_gen_26; // evaluated argument 
	Object_Int* Int_gen_27 = NULL; // Default New Var reg of type: Int
	Int_gen_27 = ( (Object_Int* )Int_gen_21); 
	Object_Int* Int_gen_28 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_29 = NULL; // Default New Var reg of type: Int
	Int_gen_29 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_29->_int_value = 0;
	Int_gen_28 = Int_gen_29; // evaluated argument 
	Object_Int* Int_gen_30 = NULL; // Default New Var reg of type: Int
	Int_gen_30 = ( (Object_Int* )Int_gen_28); 
	Object_Middle* Middle_gen_1 = NULL; // Default New Var reg of type: Middle
	Middle_gen_1 = (*GLOBAL_Class_Middle.Class_Middle_Method_Middle)(Int_gen_27,Int_gen_30);
	Middle_gen_0 = Middle_gen_1; // Evaluated expression
	Int_gen_20 = Middle_gen_0->abc;
	Int_gen_19 = ((Object_Int* )Int_gen_20); // return value .
	Int_gen_19->_class_pointer= &GLOBAL_Class_Int;
	return Int_gen_19;

}

Object_Top* Class_Middle_Method_forever(Object_Middle* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* Int_gen_31 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
// Generate Typed Value 
	Object_Int* Int_gen_32 = NULL; // Default New Var reg of type: Int
	Int_gen_32 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_32->_int_value = 2;
	Int_gen_31 = Int_gen_32 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	_this_ptr->abc = Int_gen_31; //store into this.
// End Assignment Statment
// Begin Method Call Generation .
	Object_Str* Str_gen_10 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_11 = NULL; // Default New Var reg of type: Str
	Str_gen_11 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_11->_string_value = " in Middle Onece!";
Str_gen_10 = Str_gen_11; // generate method left exp complete.
	Object_Obj* Obj_gen_5 = NULL; // Default New Var reg of type: Obj
	Obj_gen_5 = ( (Object_Obj* )Str_gen_10); 
	Object_Nothing* Nothing_gen_5 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_5 = (* Obj_gen_5->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_5);
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
	Object_Int* Int_gen_33 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_34 = NULL; // Default New Var reg of type: Int
	Object_Int* Int_gen_35 = NULL; // Default New Var reg of type: Int
	Object_Bottom * returnValue = new Object_Bottom();
	returnValue->_class_pointer = &GLOBAL_Class_Bottom;
// Begin Method Call Generation .
	Object_Str* Str_gen_12 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_13 = NULL; // Default New Var reg of type: Str
	Str_gen_13 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_13->_string_value = "class Bottom(x:Int, y:Int, z:Int) extends Middle";
Str_gen_12 = Str_gen_13; // generate method left exp complete.
	Object_Obj* Obj_gen_6 = NULL; // Default New Var reg of type: Obj
	Obj_gen_6 = ( (Object_Obj* )Str_gen_12); 
	Object_Nothing* Nothing_gen_6 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_6 = (* Obj_gen_6->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_6);
	Object_Int* Int_gen_36 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_37 = NULL; // Default New Var reg of type: Int
	Int_gen_37 = ( (Object_Int* )z); 
// Setting variable z to the new value
	z = Int_gen_37;
	Int_gen_36 = Int_gen_37 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	returnValue->defer = Int_gen_36; //store into this.
// End Assignment Statment
	Object_Int* Int_gen_38 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_39 = NULL; // Default New Var reg of type: Int
	Int_gen_39 = ( (Object_Int* )y); 
// Setting variable y to the new value
	y = Int_gen_39;
	Int_gen_38 = Int_gen_39 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	returnValue->xyz = Int_gen_38; //store into this.
// End Assignment Statment
	Object_Int* Int_gen_40 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_41 = NULL; // Default New Var reg of type: Int
	Int_gen_41 = ( (Object_Int* )x); 
// Setting variable x to the new value
	x = Int_gen_41;
	Int_gen_40 = Int_gen_41 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	returnValue->abc = Int_gen_40; //store into this.
// End Assignment Statment
	return returnValue;

}

Object_Int* Class_Bottom_Method_bar(Object_Bottom* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// Begin Method Call Generation .
	Object_Str* Str_gen_14 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_15 = NULL; // Default New Var reg of type: Str
	Str_gen_15 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_15->_string_value = "def Bottom bar():Int";
Str_gen_14 = Str_gen_15; // generate method left exp complete.
	Object_Obj* Obj_gen_7 = NULL; // Default New Var reg of type: Obj
	Obj_gen_7 = ( (Object_Obj* )Str_gen_14); 
	Object_Nothing* Nothing_gen_7 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_7 = (* Obj_gen_7->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_7);
	Object_Int* Int_gen_42 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_43 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_44 = NULL; // Default New Var reg of type: Int
	Int_gen_44 = _this_ptr->xyz;
// After Left Math Eval.
	Int_gen_43 = Int_gen_44; // evaled left of expression.
	Object_Int* Int_gen_45 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
	Object_Int* Int_gen_46 = NULL; // Default New Var reg of type: Int
	Int_gen_46 = _this_ptr->xyz;
// After Right  Math Eval.
	Int_gen_45 = Int_gen_46; // evaled right of expression.
	Object_Int* Int_gen_47 = NULL; // Default New Var reg of type: Int
	Int_gen_47 = (*Int_gen_43->_class_pointer->Class_Int_Method_TIMES)(Int_gen_43, Int_gen_45);
	Int_gen_42 = Int_gen_47 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	_this_ptr->xyz = Int_gen_42; //store into this.
// End Assignment Statment
// Generate return statement.
	Object_Int* Int_gen_48 = NULL; // Default New Var reg of type: Int
// Begin Method Call Generation .
	Object_Middle* Middle_gen_3 = NULL; // Default New Var reg of type: Middle
	Middle_gen_3 = ( (Object_Middle* )_this_ptr); 
	Object_Int* Int_gen_49 = NULL; // Default New Var reg of type: Int
	Int_gen_49 = (*_this_ptr->_class_pointer->Class_Middle_Method_foo)(Middle_gen_3);
	Int_gen_48 = ((Object_Int* )Int_gen_49); // return value .
	Int_gen_48->_class_pointer= &GLOBAL_Class_Int;
	return Int_gen_48;

}

Object_Boolean* Class_Bottom_Method_boolTest(Object_Bottom* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// Begin Method Call Generation .
	Object_Str* Str_gen_16 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_17 = NULL; // Default New Var reg of type: Str
	Str_gen_17 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_17->_string_value = "def boolTest():Boolean";
Str_gen_16 = Str_gen_17; // generate method left exp complete.
	Object_Obj* Obj_gen_8 = NULL; // Default New Var reg of type: Obj
	Obj_gen_8 = ( (Object_Obj* )Str_gen_16); 
	Object_Nothing* Nothing_gen_8 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_8 = (* Obj_gen_8->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_8);
// Generate return statement.
	Object_Boolean* Boolean_gen_0 = NULL; // Default New Var reg of type: Boolean
// Start Boolean Expression emit.
	Object_Boolean* Boolean_gen_1 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_2 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_3 = NULL; // Default New Var reg of type: Boolean
	{
/// L EXPRESSION OR begin.
// Generate Typed Value 
	Object_Boolean* Boolean_gen_4 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_4 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_4->_bool_value = false;
	Boolean_gen_2 = Boolean_gen_4; // evaled left of OR expression.
	if (true==Boolean_gen_2->_bool_value)
	{
		Boolean_gen_1 = Boolean_gen_2;
		 goto label_0_; 
	}
	else
	{
		 goto label_1_; 
	}
	label_1_:;
/// R expression OR begin.
	{
// Start Boolean Expression emit.
	Object_Boolean* Boolean_gen_5 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_6 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_7 = NULL; // Default New Var reg of type: Boolean
	{
/// L EXPRESSION AND begin.
// Generate Typed Value 
	Object_Boolean* Boolean_gen_8 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_8 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_8->_bool_value = true;
	Boolean_gen_6 = Boolean_gen_8; // evaled left of AND expression.
	if (false==Boolean_gen_6->_bool_value)
	{
		Boolean_gen_5 = Boolean_gen_6;
		 goto label_2_; 
	}
	else
	{
		 goto label_3_; 
	}
	label_3_:;
/// R expression AND begin.
	{
// Start Boolean Expression emit.
	Object_Boolean* Boolean_gen_9 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_10 = NULL; // Default New Var reg of type: Boolean
	Object_Boolean* Boolean_gen_11 = NULL; // Default New Var reg of type: Boolean
	{
// Emitting NOT operator.
// Generate Typed Value 
	Object_Boolean* Boolean_gen_12 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_12 = (*GLOBAL_Class_Boolean.Class_Boolean_Method_Boolean)();
	Boolean_gen_12->_bool_value = false;
	Boolean_gen_11 = Boolean_gen_12 ; // right side NOT evaled.
	Boolean_gen_9 = (*Boolean_gen_11->_class_pointer->Class_Boolean_Method_NOT)(Boolean_gen_11);
// End NOT operator.
	goto label_4_;
	label_4_:;
	}
		Boolean_gen_5 = Boolean_gen_9; // evaled right of AND expression.
	goto label_2_;
	}
// end AND short circuit.
	label_2_:;
	}
		Boolean_gen_1 = Boolean_gen_5; // evaled right of OR expression.
	goto label_0_;
	}
// end OR short circuit.
	label_0_:;
	}
	Boolean_gen_0 = ((Object_Boolean* )Boolean_gen_1); // return value .
	Boolean_gen_0->_class_pointer= &GLOBAL_Class_Boolean;
	return Boolean_gen_0;

}

Object_Middle* Class_Bottom_Method_forever(Object_Bottom* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Int* Int_gen_50 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
// Generate Typed Value 
	Object_Int* Int_gen_51 = NULL; // Default New Var reg of type: Int
	Int_gen_51 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_51->_int_value = 3;
	Int_gen_50 = Int_gen_51 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	_this_ptr->abc = Int_gen_50; //store into this.
// End Assignment Statment
// Begin Method Call Generation .
	Object_Str* Str_gen_18 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_19 = NULL; // Default New Var reg of type: Str
	Str_gen_19 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_19->_string_value = " in Bottom Onece!";
Str_gen_18 = Str_gen_19; // generate method left exp complete.
	Object_Obj* Obj_gen_9 = NULL; // Default New Var reg of type: Obj
	Obj_gen_9 = ( (Object_Obj* )Str_gen_18); 
	Object_Nothing* Nothing_gen_9 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_9 = (* Obj_gen_9->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_9);
// Generate return statement.
	Object_Middle* Middle_gen_4 = NULL; // Default New Var reg of type: Middle
	Object_Bottom* Bottom_gen_0 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_0 =( (Object_Bottom* )_this_ptr);
	Middle_gen_4 = ((Object_Middle* )Bottom_gen_0); // return value .
	Middle_gen_4->_class_pointer= &GLOBAL_Class_Middle;
	return Middle_gen_4;

}

<<<<<<< HEAD
Object_Bottom* Class_Bottom_Method_RunAlways(Object_Bottom* _this_ptr)
{
// Adding Arguments to the named map 
// allocating variables.
// If Else List Begin. 
// If test
	label_8_:;
	{
	Object_Boolean* Boolean_gen_13 = NULL; // Default New Var reg of type: Boolean
	Object_Int* Int_gen_52 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_53 = NULL; // Default New Var reg of type: Int
	Int_gen_53 = _this_ptr->abc;
// After Left Math Eval.
	Int_gen_52 = Int_gen_53; // evaled left of expression.
	Object_Int* Int_gen_54 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_55 = NULL; // Default New Var reg of type: Int
	Int_gen_55 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_55->_int_value = -1;
// After Right  Math Eval.
	Int_gen_54 = Int_gen_55; // evaled right of expression.
	Object_Boolean* Boolean_gen_14 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_14 = (*Int_gen_52->_class_pointer->Class_Int_Method_MORE)(Int_gen_52, Int_gen_54);
		Boolean_gen_13 = Boolean_gen_14;
		if (true==Boolean_gen_13->_bool_value)
		{
			 goto label_7_; 
		}
		else
		{
			 goto label_9_; 
		}
	}
	label_7_:;
// code block
	{
	Object_Int* Int_gen_56 = NULL; // Default New Var reg of type: Int
// Begin Assignment Gen Value side. 
	Object_Int* Int_gen_57 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
	Object_Int* Int_gen_58 = NULL; // Default New Var reg of type: Int
	Int_gen_58 = _this_ptr->abc;
// After Left Math Eval.
	Int_gen_57 = Int_gen_58; // evaled left of expression.
	Object_Int* Int_gen_59 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_60 = NULL; // Default New Var reg of type: Int
	Int_gen_60 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_60->_int_value = 1;
// After Right  Math Eval.
	Int_gen_59 = Int_gen_60; // evaled right of expression.
	Object_Int* Int_gen_61 = NULL; // Default New Var reg of type: Int
	Int_gen_61 = (*Int_gen_57->_class_pointer->Class_Int_Method_MINUS)(Int_gen_57, Int_gen_59);
	Int_gen_56 = Int_gen_61 ; // Assignment value, evaled.
// Emit a Store Instruction into the this pointer.
	_this_ptr->abc = Int_gen_56; //store into this.
// End Assignment Statment
	goto label_6_;
	}
// end code block
// If test
	label_9_:;
	label_10_:;
// code block
	{
// Generate return statement.
	Object_Bottom* Bottom_gen_1 = NULL; // Default New Var reg of type: Bottom
	Object_Bottom* Bottom_gen_2 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_2 =( (Object_Bottom* )_this_ptr);
	Bottom_gen_1 = ((Object_Bottom* )Bottom_gen_2); // return value .
	Bottom_gen_1->_class_pointer= &GLOBAL_Class_Bottom;
	return Bottom_gen_1;
	goto label_6_;
	}
// end code block
	label_6_:;
// If Else List end. 
=======
Object_Nothing* class_MAIN_method_MAIN()
{
// Adding Arguments to the named map 
// allocating variables.
	Object_Top* Top_gen_3 = NULL; // Default New Var reg of type: Top
>>>>>>> 4b6217d8e273d4a1fee1eb2c14853e397372a100
// Begin Method Call Generation .
	Object_Str* Str_gen_20 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_21 = NULL; // Default New Var reg of type: Str
	Str_gen_21 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
<<<<<<< HEAD
	Str_gen_21->_string_value = "Infinite Recurson";
=======
	Str_gen_21->_string_value = "Printing D Start";
>>>>>>> 4b6217d8e273d4a1fee1eb2c14853e397372a100
Str_gen_20 = Str_gen_21; // generate method left exp complete.
	Object_Obj* Obj_gen_10 = NULL; // Default New Var reg of type: Obj
	Obj_gen_10 = ( (Object_Obj* )Str_gen_20); 
	Object_Nothing* Nothing_gen_10 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_10 = (* Obj_gen_10->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_10);
<<<<<<< HEAD
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
	Object_Bottom* Bottom_gen_6 = NULL; // Default New Var reg of type: Bottom
// Begin Method Call Generation .
	Object_Str* Str_gen_22 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_23 = NULL; // Default New Var reg of type: Str
	Str_gen_23 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_23->_string_value = "Printing D Start";
Str_gen_22 = Str_gen_23; // generate method left exp complete.
	Object_Obj* Obj_gen_11 = NULL; // Default New Var reg of type: Obj
	Obj_gen_11 = ( (Object_Obj* )Str_gen_22); 
	Object_Nothing* Nothing_gen_11 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_11 = (* Obj_gen_11->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_11);
	Object_Bottom* Bottom_gen_7 = NULL; // Default New Var reg of type: Bottom
// Begin Assignment Gen Value side. 
// Begin Method Call Generation .
	Object_Int* Int_gen_62 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_63 = NULL; // Default New Var reg of type: Int
	Int_gen_63 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_63->_int_value = 1;
	Int_gen_62 = Int_gen_63; // evaluated argument 
	Object_Int* Int_gen_64 = NULL; // Default New Var reg of type: Int
	Int_gen_64 = ( (Object_Int* )Int_gen_62); 
	Object_Int* Int_gen_65 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_66 = NULL; // Default New Var reg of type: Int
	Int_gen_66 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_66->_int_value = 2;
	Int_gen_65 = Int_gen_66; // evaluated argument 
	Object_Int* Int_gen_67 = NULL; // Default New Var reg of type: Int
	Int_gen_67 = ( (Object_Int* )Int_gen_65); 
	Object_Int* Int_gen_68 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_69 = NULL; // Default New Var reg of type: Int
	Int_gen_69 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_69->_int_value = 3;
	Int_gen_68 = Int_gen_69; // evaluated argument 
	Object_Int* Int_gen_70 = NULL; // Default New Var reg of type: Int
	Int_gen_70 = ( (Object_Int* )Int_gen_68); 
	Object_Bottom* Bottom_gen_8 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_8 = (*GLOBAL_Class_Bottom.Class_Bottom_Method_Bottom)(Int_gen_64,Int_gen_67,Int_gen_70);
	Bottom_gen_7 = Bottom_gen_8 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Top* Top_gen_4 = NULL; // Default New Var reg of type: Top
	Top_gen_4 = ( (Object_Top* )Bottom_gen_7); 
=======
	Object_Bottom* Bottom_gen_1 = NULL; // Default New Var reg of type: Bottom
// Begin Assignment Gen Value side. 
// Begin Method Call Generation .
	Object_Int* Int_gen_52 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_53 = NULL; // Default New Var reg of type: Int
	Int_gen_53 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_53->_int_value = 1;
	Int_gen_52 = Int_gen_53; // evaluated argument 
	Object_Int* Int_gen_54 = NULL; // Default New Var reg of type: Int
	Int_gen_54 = ( (Object_Int* )Int_gen_52); 
	Object_Int* Int_gen_55 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_56 = NULL; // Default New Var reg of type: Int
	Int_gen_56 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_56->_int_value = 2;
	Int_gen_55 = Int_gen_56; // evaluated argument 
	Object_Int* Int_gen_57 = NULL; // Default New Var reg of type: Int
	Int_gen_57 = ( (Object_Int* )Int_gen_55); 
	Object_Int* Int_gen_58 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_59 = NULL; // Default New Var reg of type: Int
	Int_gen_59 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_59->_int_value = 3;
	Int_gen_58 = Int_gen_59; // evaluated argument 
	Object_Int* Int_gen_60 = NULL; // Default New Var reg of type: Int
	Int_gen_60 = ( (Object_Int* )Int_gen_58); 
	Object_Bottom* Bottom_gen_2 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_2 = (*GLOBAL_Class_Bottom.Class_Bottom_Method_Bottom)(Int_gen_54,Int_gen_57,Int_gen_60);
	Bottom_gen_1 = Bottom_gen_2 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Top* Top_gen_4 = NULL; // Default New Var reg of type: Top
	Top_gen_4 = ( (Object_Top* )Bottom_gen_1); 
>>>>>>> 4b6217d8e273d4a1fee1eb2c14853e397372a100
	 // Assigning var d to Top_gen_4
	Top_gen_3 = Top_gen_4;
// End Assignment Statment
//While loop start.
<<<<<<< HEAD
	Object_Boolean* Boolean_gen_15 = NULL; // Default New Var reg of type: Boolean
// Condition start
	label_14_:;
	{
	Object_Int* Int_gen_71 = NULL; // Default New Var reg of type: Int
=======
	Object_Boolean* Boolean_gen_13 = NULL; // Default New Var reg of type: Boolean
// Condition start
	label_7_:;
	{
	Object_Int* Int_gen_61 = NULL; // Default New Var reg of type: Int
>>>>>>> 4b6217d8e273d4a1fee1eb2c14853e397372a100
// Before Left Math Eval.
// Begin Method Call Generation .
	Object_Top* Top_gen_5 = NULL; // Default New Var reg of type: Top
	Object_Top* Top_gen_6 = NULL; // Default New Var reg of type: Top
	Top_gen_6 = ( (Object_Top* )Top_gen_3); 
// Setting variable Top_gen_3 to the new value
	Top_gen_3 = Top_gen_6;
Top_gen_5 = Top_gen_6; // generate method left exp complete.
	Object_Top* Top_gen_7 = NULL; // Default New Var reg of type: Top
	Top_gen_7 = ( (Object_Top* )Top_gen_5); 
<<<<<<< HEAD
	Object_Int* Int_gen_72 = NULL; // Default New Var reg of type: Int
	Int_gen_72 = (* Top_gen_7->_class_pointer->Class_Top_Method_test)(Top_gen_7);
// After Left Math Eval.
	Int_gen_71 = Int_gen_72; // evaled left of expression.
	Object_Int* Int_gen_73 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_74 = NULL; // Default New Var reg of type: Int
	Int_gen_74 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_74->_int_value = -5;
// After Right  Math Eval.
	Int_gen_73 = Int_gen_74; // evaled right of expression.
	Object_Boolean* Boolean_gen_16 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_16 = (*Int_gen_71->_class_pointer->Class_Int_Method_MORE)(Int_gen_71, Int_gen_73);
// Condition test
		Boolean_gen_15 = Boolean_gen_16 ; 
	if (true==Boolean_gen_15->_bool_value)
	{
		 goto label_13_; 
	}
	else
	{
		 goto label_15_; 
	}
	}
// Loop start
	label_13_:;
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_24 = NULL; // Default New Var reg of type: Str
	Object_Str* Str_gen_25 = NULL; // Default New Var reg of type: Str
// Before Left Math Eval.
	Object_Str* Str_gen_26 = NULL; // Default New Var reg of type: Str
// Before Left Math Eval.
// Generate Typed Value 
	Object_Str* Str_gen_27 = NULL; // Default New Var reg of type: Str
	Str_gen_27 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_27->_string_value = "Printing d";
// After Left Math Eval.
	Str_gen_26 = Str_gen_27; // evaled left of expression.
	Object_Str* Str_gen_28 = NULL; // Default New Var reg of type: Str
// Before Right Math Eval.
// Begin Method Call Generation .
	Object_Int* Int_gen_75 = NULL; // Default New Var reg of type: Int
=======
	Object_Int* Int_gen_62 = NULL; // Default New Var reg of type: Int
	Int_gen_62 = (* Top_gen_7->_class_pointer->Class_Top_Method_test)(Top_gen_7);
// After Left Math Eval.
	Int_gen_61 = Int_gen_62; // evaled left of expression.
	Object_Int* Int_gen_63 = NULL; // Default New Var reg of type: Int
// Before Right Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_64 = NULL; // Default New Var reg of type: Int
	Int_gen_64 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_64->_int_value = -5;
// After Right  Math Eval.
	Int_gen_63 = Int_gen_64; // evaled right of expression.
	Object_Boolean* Boolean_gen_14 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_14 = (*Int_gen_61->_class_pointer->Class_Int_Method_MORE)(Int_gen_61, Int_gen_63);
// Condition test
		Boolean_gen_13 = Boolean_gen_14 ; 
	if (true==Boolean_gen_13->_bool_value)
	{
		 goto label_6_; 
	}
	else
	{
		 goto label_8_; 
	}
	}
// Loop start
	label_6_:;
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_22 = NULL; // Default New Var reg of type: Str
	Object_Str* Str_gen_23 = NULL; // Default New Var reg of type: Str
// Before Left Math Eval.
	Object_Str* Str_gen_24 = NULL; // Default New Var reg of type: Str
// Before Left Math Eval.
// Generate Typed Value 
	Object_Str* Str_gen_25 = NULL; // Default New Var reg of type: Str
	Str_gen_25 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_25->_string_value = "Printing d";
// After Left Math Eval.
	Str_gen_24 = Str_gen_25; // evaled left of expression.
	Object_Str* Str_gen_26 = NULL; // Default New Var reg of type: Str
// Before Right Math Eval.
// Begin Method Call Generation .
	Object_Int* Int_gen_65 = NULL; // Default New Var reg of type: Int
>>>>>>> 4b6217d8e273d4a1fee1eb2c14853e397372a100
// Begin Method Call Generation .
	Object_Top* Top_gen_8 = NULL; // Default New Var reg of type: Top
	Object_Top* Top_gen_9 = NULL; // Default New Var reg of type: Top
	Top_gen_9 = ( (Object_Top* )Top_gen_3); 
// Setting variable Top_gen_3 to the new value
	Top_gen_3 = Top_gen_9;
Top_gen_8 = Top_gen_9; // generate method left exp complete.
	Object_Top* Top_gen_10 = NULL; // Default New Var reg of type: Top
	Top_gen_10 = ( (Object_Top* )Top_gen_8); 
<<<<<<< HEAD
	Object_Int* Int_gen_76 = NULL; // Default New Var reg of type: Int
	Int_gen_76 = (* Top_gen_10->_class_pointer->Class_Top_Method_test)(Top_gen_10);
Int_gen_75 = Int_gen_76; // generate method left exp complete.
	Object_Int* Int_gen_77 = NULL; // Default New Var reg of type: Int
	Int_gen_77 = ( (Object_Int* )Int_gen_75); 
	Object_Str* Str_gen_29 = NULL; // Default New Var reg of type: Str
	Str_gen_29 = (* Int_gen_77->_class_pointer->Class_Int_Method_STR)(Int_gen_77);
// After Right  Math Eval.
	Str_gen_28 = Str_gen_29; // evaled right of expression.
	Object_Str* Str_gen_30 = NULL; // Default New Var reg of type: Str
	Str_gen_30 = (*Str_gen_26->_class_pointer->Class_Str_Method_PLUS)(Str_gen_26, Str_gen_28);
// After Left Math Eval.
	Str_gen_25 = Str_gen_30; // evaled left of expression.
	Object_Str* Str_gen_31 = NULL; // Default New Var reg of type: Str
// Before Right Math Eval.
// Generate Typed Value 
	Object_Str* Str_gen_32 = NULL; // Default New Var reg of type: Str
	Str_gen_32 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_32->_string_value = " value";
// After Right  Math Eval.
	Str_gen_31 = Str_gen_32; // evaled right of expression.
	Object_Str* Str_gen_33 = NULL; // Default New Var reg of type: Str
	Str_gen_33 = (*Str_gen_25->_class_pointer->Class_Str_Method_PLUS)(Str_gen_25, Str_gen_31);
Str_gen_24 = Str_gen_33; // generate method left exp complete.
	Object_Obj* Obj_gen_12 = NULL; // Default New Var reg of type: Obj
	Obj_gen_12 = ( (Object_Obj* )Str_gen_24); 
	Object_Nothing* Nothing_gen_12 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_12 = (* Obj_gen_12->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_12);
=======
	Object_Int* Int_gen_66 = NULL; // Default New Var reg of type: Int
	Int_gen_66 = (* Top_gen_10->_class_pointer->Class_Top_Method_test)(Top_gen_10);
Int_gen_65 = Int_gen_66; // generate method left exp complete.
	Object_Int* Int_gen_67 = NULL; // Default New Var reg of type: Int
	Int_gen_67 = ( (Object_Int* )Int_gen_65); 
	Object_Str* Str_gen_27 = NULL; // Default New Var reg of type: Str
	Str_gen_27 = (* Int_gen_67->_class_pointer->Class_Int_Method_STR)(Int_gen_67);
// After Right  Math Eval.
	Str_gen_26 = Str_gen_27; // evaled right of expression.
	Object_Str* Str_gen_28 = NULL; // Default New Var reg of type: Str
	Str_gen_28 = (*Str_gen_24->_class_pointer->Class_Str_Method_PLUS)(Str_gen_24, Str_gen_26);
// After Left Math Eval.
	Str_gen_23 = Str_gen_28; // evaled left of expression.
	Object_Str* Str_gen_29 = NULL; // Default New Var reg of type: Str
// Before Right Math Eval.
// Generate Typed Value 
	Object_Str* Str_gen_30 = NULL; // Default New Var reg of type: Str
	Str_gen_30 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_30->_string_value = " value";
// After Right  Math Eval.
	Str_gen_29 = Str_gen_30; // evaled right of expression.
	Object_Str* Str_gen_31 = NULL; // Default New Var reg of type: Str
	Str_gen_31 = (*Str_gen_23->_class_pointer->Class_Str_Method_PLUS)(Str_gen_23, Str_gen_29);
Str_gen_22 = Str_gen_31; // generate method left exp complete.
	Object_Obj* Obj_gen_11 = NULL; // Default New Var reg of type: Obj
	Obj_gen_11 = ( (Object_Obj* )Str_gen_22); 
	Object_Nothing* Nothing_gen_11 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_11 = (* Obj_gen_11->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_11);
>>>>>>> 4b6217d8e273d4a1fee1eb2c14853e397372a100
	Object_Top* Top_gen_11 = NULL; // Default New Var reg of type: Top
// Begin Assignment Gen Value side. 
// Begin Method Call Generation .
	Object_Top* Top_gen_12 = NULL; // Default New Var reg of type: Top
	Object_Top* Top_gen_13 = NULL; // Default New Var reg of type: Top
	Top_gen_13 = ( (Object_Top* )Top_gen_3); 
// Setting variable Top_gen_3 to the new value
	Top_gen_3 = Top_gen_13;
Top_gen_12 = Top_gen_13; // generate method left exp complete.
	Object_Top* Top_gen_14 = NULL; // Default New Var reg of type: Top
	Top_gen_14 = ( (Object_Top* )Top_gen_12); 
	Object_Top* Top_gen_15 = NULL; // Default New Var reg of type: Top
	Top_gen_15 = (* Top_gen_14->_class_pointer->Class_Top_Method_forever)(Top_gen_14);
	Top_gen_11 = Top_gen_15 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Top* Top_gen_16 = NULL; // Default New Var reg of type: Top
	Top_gen_16 = ( (Object_Top* )Top_gen_11); 
	 // Assigning var d to Top_gen_16
	Top_gen_3 = Top_gen_16;
// End Assignment Statment
<<<<<<< HEAD
	goto label_14_; 
	}
// Loop exit
	label_15_:;
// Begin Method Call Generation .
	Object_Str* Str_gen_34 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_35 = NULL; // Default New Var reg of type: Str
	Str_gen_35 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_35->_string_value = "Loops appear to work.";
Str_gen_34 = Str_gen_35; // generate method left exp complete.
	Object_Obj* Obj_gen_13 = NULL; // Default New Var reg of type: Obj
	Obj_gen_13 = ( (Object_Obj* )Str_gen_34); 
	Object_Nothing* Nothing_gen_13 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_13 = (* Obj_gen_13->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_13);
// If Else List Begin. 
// If test
	label_18_:;
	{
	Object_Boolean* Boolean_gen_17 = NULL; // Default New Var reg of type: Boolean
	Object_Int* Int_gen_78 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_79 = NULL; // Default New Var reg of type: Int
	Int_gen_79 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_79->_int_value = 1;
// After Left Math Eval.
	Int_gen_78 = Int_gen_79; // evaled left of expression.
	Object_Int* Int_gen_80 = NULL; // Default New Var reg of type: Int
=======
	goto label_7_; 
	}
// Loop exit
	label_8_:;
// Begin Method Call Generation .
	Object_Str* Str_gen_32 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_33 = NULL; // Default New Var reg of type: Str
	Str_gen_33 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_33->_string_value = "Loops appear to work.";
Str_gen_32 = Str_gen_33; // generate method left exp complete.
	Object_Obj* Obj_gen_12 = NULL; // Default New Var reg of type: Obj
	Obj_gen_12 = ( (Object_Obj* )Str_gen_32); 
	Object_Nothing* Nothing_gen_12 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_12 = (* Obj_gen_12->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_12);
// If Else List Begin. 
// If test
	label_11_:;
	{
	Object_Boolean* Boolean_gen_15 = NULL; // Default New Var reg of type: Boolean
	Object_Int* Int_gen_68 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_69 = NULL; // Default New Var reg of type: Int
	Int_gen_69 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_69->_int_value = 1;
// After Left Math Eval.
	Int_gen_68 = Int_gen_69; // evaled left of expression.
	Object_Int* Int_gen_70 = NULL; // Default New Var reg of type: Int
>>>>>>> 4b6217d8e273d4a1fee1eb2c14853e397372a100
// Before Right Math Eval.
// Begin Method Call Generation .
	Object_Top* Top_gen_17 = NULL; // Default New Var reg of type: Top
	Object_Top* Top_gen_18 = NULL; // Default New Var reg of type: Top
	Top_gen_18 = ( (Object_Top* )Top_gen_3); 
// Setting variable Top_gen_3 to the new value
	Top_gen_3 = Top_gen_18;
Top_gen_17 = Top_gen_18; // generate method left exp complete.
	Object_Top* Top_gen_19 = NULL; // Default New Var reg of type: Top
	Top_gen_19 = ( (Object_Top* )Top_gen_17); 
<<<<<<< HEAD
	Object_Int* Int_gen_81 = NULL; // Default New Var reg of type: Int
	Int_gen_81 = (* Top_gen_19->_class_pointer->Class_Top_Method_test)(Top_gen_19);
// After Right  Math Eval.
	Int_gen_80 = Int_gen_81; // evaled right of expression.
	Object_Boolean* Boolean_gen_18 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_18 = (*Int_gen_78->_class_pointer->Class_Int_Method_LESS)(Int_gen_78, Int_gen_80);
		Boolean_gen_17 = Boolean_gen_18;
		if (true==Boolean_gen_17->_bool_value)
		{
			 goto label_17_; 
		}
		else
		{
			 goto label_19_; 
		}
	}
	label_17_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_36 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_37 = NULL; // Default New Var reg of type: Str
	Str_gen_37 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_37->_string_value = "First If Block";
Str_gen_36 = Str_gen_37; // generate method left exp complete.
	Object_Obj* Obj_gen_14 = NULL; // Default New Var reg of type: Obj
	Obj_gen_14 = ( (Object_Obj* )Str_gen_36); 
	Object_Nothing* Nothing_gen_14 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_14 = (* Obj_gen_14->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_14);
	goto label_16_;
	}
// end code block
// If test
	label_19_:;
	{
	Object_Boolean* Boolean_gen_19 = NULL; // Default New Var reg of type: Boolean
	Object_Int* Int_gen_82 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_83 = NULL; // Default New Var reg of type: Int
	Int_gen_83 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_83->_int_value = 1;
// After Left Math Eval.
	Int_gen_82 = Int_gen_83; // evaled left of expression.
	Object_Int* Int_gen_84 = NULL; // Default New Var reg of type: Int
=======
	Object_Int* Int_gen_71 = NULL; // Default New Var reg of type: Int
	Int_gen_71 = (* Top_gen_19->_class_pointer->Class_Top_Method_test)(Top_gen_19);
// After Right  Math Eval.
	Int_gen_70 = Int_gen_71; // evaled right of expression.
	Object_Boolean* Boolean_gen_16 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_16 = (*Int_gen_68->_class_pointer->Class_Int_Method_LESS)(Int_gen_68, Int_gen_70);
		Boolean_gen_15 = Boolean_gen_16;
		if (true==Boolean_gen_15->_bool_value)
		{
			 goto label_10_; 
		}
		else
		{
			 goto label_12_; 
		}
	}
	label_10_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_34 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_35 = NULL; // Default New Var reg of type: Str
	Str_gen_35 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_35->_string_value = "First If Block";
Str_gen_34 = Str_gen_35; // generate method left exp complete.
	Object_Obj* Obj_gen_13 = NULL; // Default New Var reg of type: Obj
	Obj_gen_13 = ( (Object_Obj* )Str_gen_34); 
	Object_Nothing* Nothing_gen_13 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_13 = (* Obj_gen_13->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_13);
	goto label_9_;
	}
// end code block
// If test
	label_12_:;
	{
	Object_Boolean* Boolean_gen_17 = NULL; // Default New Var reg of type: Boolean
	Object_Int* Int_gen_72 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_73 = NULL; // Default New Var reg of type: Int
	Int_gen_73 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_73->_int_value = 1;
// After Left Math Eval.
	Int_gen_72 = Int_gen_73; // evaled left of expression.
	Object_Int* Int_gen_74 = NULL; // Default New Var reg of type: Int
>>>>>>> 4b6217d8e273d4a1fee1eb2c14853e397372a100
// Before Right Math Eval.
// Begin Method Call Generation .
	Object_Top* Top_gen_20 = NULL; // Default New Var reg of type: Top
	Object_Top* Top_gen_21 = NULL; // Default New Var reg of type: Top
	Top_gen_21 = ( (Object_Top* )Top_gen_3); 
// Setting variable Top_gen_3 to the new value
	Top_gen_3 = Top_gen_21;
Top_gen_20 = Top_gen_21; // generate method left exp complete.
	Object_Top* Top_gen_22 = NULL; // Default New Var reg of type: Top
	Top_gen_22 = ( (Object_Top* )Top_gen_20); 
<<<<<<< HEAD
	Object_Int* Int_gen_85 = NULL; // Default New Var reg of type: Int
	Int_gen_85 = (* Top_gen_22->_class_pointer->Class_Top_Method_test)(Top_gen_22);
// After Right  Math Eval.
	Int_gen_84 = Int_gen_85; // evaled right of expression.
	Object_Boolean* Boolean_gen_20 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_20 = (*Int_gen_82->_class_pointer->Class_Int_Method_EQUALS)(Int_gen_82, Int_gen_84);
		Boolean_gen_19 = Boolean_gen_20;
		if (true==Boolean_gen_19->_bool_value)
		{
			 goto label_20_; 
		}
		else
		{
			 goto label_21_; 
		}
	}
	label_20_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_38 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_39 = NULL; // Default New Var reg of type: Str
	Str_gen_39 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_39->_string_value = "second If Block";
Str_gen_38 = Str_gen_39; // generate method left exp complete.
	Object_Obj* Obj_gen_15 = NULL; // Default New Var reg of type: Obj
	Obj_gen_15 = ( (Object_Obj* )Str_gen_38); 
	Object_Nothing* Nothing_gen_15 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_15 = (* Obj_gen_15->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_15);
	goto label_16_;
	}
// end code block
// If test
	label_21_:;
	{
	Object_Boolean* Boolean_gen_21 = NULL; // Default New Var reg of type: Boolean
	Object_Int* Int_gen_86 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_87 = NULL; // Default New Var reg of type: Int
	Int_gen_87 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_87->_int_value = 1;
// After Left Math Eval.
	Int_gen_86 = Int_gen_87; // evaled left of expression.
	Object_Int* Int_gen_88 = NULL; // Default New Var reg of type: Int
=======
	Object_Int* Int_gen_75 = NULL; // Default New Var reg of type: Int
	Int_gen_75 = (* Top_gen_22->_class_pointer->Class_Top_Method_test)(Top_gen_22);
// After Right  Math Eval.
	Int_gen_74 = Int_gen_75; // evaled right of expression.
	Object_Boolean* Boolean_gen_18 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_18 = (*Int_gen_72->_class_pointer->Class_Int_Method_EQUALS)(Int_gen_72, Int_gen_74);
		Boolean_gen_17 = Boolean_gen_18;
		if (true==Boolean_gen_17->_bool_value)
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
	Object_Str* Str_gen_36 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_37 = NULL; // Default New Var reg of type: Str
	Str_gen_37 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_37->_string_value = "second If Block";
Str_gen_36 = Str_gen_37; // generate method left exp complete.
	Object_Obj* Obj_gen_14 = NULL; // Default New Var reg of type: Obj
	Obj_gen_14 = ( (Object_Obj* )Str_gen_36); 
	Object_Nothing* Nothing_gen_14 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_14 = (* Obj_gen_14->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_14);
	goto label_9_;
	}
// end code block
// If test
	label_14_:;
	{
	Object_Boolean* Boolean_gen_19 = NULL; // Default New Var reg of type: Boolean
	Object_Int* Int_gen_76 = NULL; // Default New Var reg of type: Int
// Before Left Math Eval.
// Generate Typed Value 
	Object_Int* Int_gen_77 = NULL; // Default New Var reg of type: Int
	Int_gen_77 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_77->_int_value = 1;
// After Left Math Eval.
	Int_gen_76 = Int_gen_77; // evaled left of expression.
	Object_Int* Int_gen_78 = NULL; // Default New Var reg of type: Int
>>>>>>> 4b6217d8e273d4a1fee1eb2c14853e397372a100
// Before Right Math Eval.
// Begin Method Call Generation .
	Object_Top* Top_gen_23 = NULL; // Default New Var reg of type: Top
	Object_Top* Top_gen_24 = NULL; // Default New Var reg of type: Top
	Top_gen_24 = ( (Object_Top* )Top_gen_3); 
// Setting variable Top_gen_3 to the new value
	Top_gen_3 = Top_gen_24;
Top_gen_23 = Top_gen_24; // generate method left exp complete.
	Object_Top* Top_gen_25 = NULL; // Default New Var reg of type: Top
	Top_gen_25 = ( (Object_Top* )Top_gen_23); 
<<<<<<< HEAD
	Object_Int* Int_gen_89 = NULL; // Default New Var reg of type: Int
	Int_gen_89 = (* Top_gen_25->_class_pointer->Class_Top_Method_test)(Top_gen_25);
// After Right  Math Eval.
	Int_gen_88 = Int_gen_89; // evaled right of expression.
	Object_Boolean* Boolean_gen_22 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_22 = (*Int_gen_86->_class_pointer->Class_Int_Method_ATMOST)(Int_gen_86, Int_gen_88);
		Boolean_gen_21 = Boolean_gen_22;
		if (true==Boolean_gen_21->_bool_value)
		{
			 goto label_22_; 
		}
		else
		{
			 goto label_23_; 
		}
	}
	label_22_:;
=======
	Object_Int* Int_gen_79 = NULL; // Default New Var reg of type: Int
	Int_gen_79 = (* Top_gen_25->_class_pointer->Class_Top_Method_test)(Top_gen_25);
// After Right  Math Eval.
	Int_gen_78 = Int_gen_79; // evaled right of expression.
	Object_Boolean* Boolean_gen_20 = NULL; // Default New Var reg of type: Boolean
	Boolean_gen_20 = (*Int_gen_76->_class_pointer->Class_Int_Method_ATMOST)(Int_gen_76, Int_gen_78);
		Boolean_gen_19 = Boolean_gen_20;
		if (true==Boolean_gen_19->_bool_value)
		{
			 goto label_15_; 
		}
		else
		{
			 goto label_16_; 
		}
	}
	label_15_:;
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_38 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_39 = NULL; // Default New Var reg of type: Str
	Str_gen_39 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_39->_string_value = "thrirs If Block";
Str_gen_38 = Str_gen_39; // generate method left exp complete.
	Object_Obj* Obj_gen_15 = NULL; // Default New Var reg of type: Obj
	Obj_gen_15 = ( (Object_Obj* )Str_gen_38); 
	Object_Nothing* Nothing_gen_15 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_15 = (* Obj_gen_15->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_15);
	goto label_9_;
	}
// end code block
// If test
	label_16_:;
	label_17_:;
>>>>>>> 4b6217d8e273d4a1fee1eb2c14853e397372a100
// code block
	{
// Begin Method Call Generation .
	Object_Str* Str_gen_40 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_41 = NULL; // Default New Var reg of type: Str
	Str_gen_41 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
<<<<<<< HEAD
	Str_gen_41->_string_value = "thrirs If Block";
=======
	Str_gen_41->_string_value = "How did we get here?";
>>>>>>> 4b6217d8e273d4a1fee1eb2c14853e397372a100
Str_gen_40 = Str_gen_41; // generate method left exp complete.
	Object_Obj* Obj_gen_16 = NULL; // Default New Var reg of type: Obj
	Obj_gen_16 = ( (Object_Obj* )Str_gen_40); 
	Object_Nothing* Nothing_gen_16 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_16 = (* Obj_gen_16->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_16);
<<<<<<< HEAD
	goto label_16_;
	}
// end code block
// If test
	label_23_:;
	label_24_:;
// code block
	{
=======
	goto label_9_;
	}
// end code block
	label_9_:;
// If Else List end. 
>>>>>>> 4b6217d8e273d4a1fee1eb2c14853e397372a100
// Begin Method Call Generation .
	Object_Str* Str_gen_42 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_43 = NULL; // Default New Var reg of type: Str
	Str_gen_43 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
<<<<<<< HEAD
	Str_gen_43->_string_value = "How did we get here?";
=======
	Str_gen_43->_string_value = "After If Block";
>>>>>>> 4b6217d8e273d4a1fee1eb2c14853e397372a100
Str_gen_42 = Str_gen_43; // generate method left exp complete.
	Object_Obj* Obj_gen_17 = NULL; // Default New Var reg of type: Obj
	Obj_gen_17 = ( (Object_Obj* )Str_gen_42); 
	Object_Nothing* Nothing_gen_17 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_17 = (* Obj_gen_17->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_17);
<<<<<<< HEAD
	goto label_16_;
	}
// end code block
	label_16_:;
// If Else List end. 
// Begin Method Call Generation .
	Object_Str* Str_gen_44 = NULL; // Default New Var reg of type: Str
// Generate Typed Value 
	Object_Str* Str_gen_45 = NULL; // Default New Var reg of type: Str
	Str_gen_45 = (*GLOBAL_Class_Str.Class_Str_Method_Str)();
	Str_gen_45->_string_value = "After If Block";
Str_gen_44 = Str_gen_45; // generate method left exp complete.
	Object_Obj* Obj_gen_18 = NULL; // Default New Var reg of type: Obj
	Obj_gen_18 = ( (Object_Obj* )Str_gen_44); 
	Object_Nothing* Nothing_gen_18 = NULL; // Default New Var reg of type: Nothing
	Nothing_gen_18 = (* Obj_gen_18->_class_pointer->Class_Obj_Method_PRINT)(Obj_gen_18);
	Object_Bottom* Bottom_gen_9 = NULL; // Default New Var reg of type: Bottom
// Begin Assignment Gen Value side. 
// Begin Method Call Generation .
	Object_Int* Int_gen_90 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_91 = NULL; // Default New Var reg of type: Int
	Int_gen_91 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_91->_int_value = 10;
	Int_gen_90 = Int_gen_91; // evaluated argument 
	Object_Int* Int_gen_92 = NULL; // Default New Var reg of type: Int
	Int_gen_92 = ( (Object_Int* )Int_gen_90); 
	Object_Int* Int_gen_93 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_94 = NULL; // Default New Var reg of type: Int
	Int_gen_94 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_94->_int_value = 2;
	Int_gen_93 = Int_gen_94; // evaluated argument 
	Object_Int* Int_gen_95 = NULL; // Default New Var reg of type: Int
	Int_gen_95 = ( (Object_Int* )Int_gen_93); 
	Object_Int* Int_gen_96 = NULL; // Default New Var reg of type: Int
// Generate Typed Value 
	Object_Int* Int_gen_97 = NULL; // Default New Var reg of type: Int
	Int_gen_97 = (*GLOBAL_Class_Int.Class_Int_Method_Int)();
	Int_gen_97->_int_value = 3;
	Int_gen_96 = Int_gen_97; // evaluated argument 
	Object_Int* Int_gen_98 = NULL; // Default New Var reg of type: Int
	Int_gen_98 = ( (Object_Int* )Int_gen_96); 
	Object_Bottom* Bottom_gen_10 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_10 = (*GLOBAL_Class_Bottom.Class_Bottom_Method_Bottom)(Int_gen_92,Int_gen_95,Int_gen_98);
	Bottom_gen_9 = Bottom_gen_10 ; // Assignment value, evaled.
// emit a store instruction into a local 'variable' 
	Object_Bottom* Bottom_gen_11 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_11 = ( (Object_Bottom* )Bottom_gen_9); 
	 // Assigning var e to Bottom_gen_11
	Bottom_gen_6 = Bottom_gen_11;
// End Assignment Statment
// Begin Method Call Generation .
	Object_Bottom* Bottom_gen_12 = NULL; // Default New Var reg of type: Bottom
	Object_Bottom* Bottom_gen_13 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_13 = ( (Object_Bottom* )Bottom_gen_6); 
// Setting variable Bottom_gen_6 to the new value
	Bottom_gen_6 = Bottom_gen_13;
Bottom_gen_12 = Bottom_gen_13; // generate method left exp complete.
	Object_Bottom* Bottom_gen_14 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_14 = ( (Object_Bottom* )Bottom_gen_12); 
	Object_Bottom* Bottom_gen_15 = NULL; // Default New Var reg of type: Bottom
	Bottom_gen_15 = (* Bottom_gen_14->_class_pointer->Class_Bottom_Method_RunAlways)(Bottom_gen_14);
=======
>>>>>>> 4b6217d8e273d4a1fee1eb2c14853e397372a100

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
	GLOBAL_Class_Str.Class_Str_Method_EQUALS=Class_Str_Method_EQUALS;
	GLOBAL_Class_Str.Class_Str_Method_ATMOST=Class_Str_Method_ATMOST;
	GLOBAL_Class_Str.Class_Str_Method_ATLEAST=Class_Str_Method_ATLEAST;
	GLOBAL_Class_Str.Class_Str_Method_LESS=Class_Str_Method_LESS;
	GLOBAL_Class_Str.Class_Str_Method_MORE=Class_Str_Method_MORE;
	GLOBAL_Class_Int.Class_Int_Method_Int=Class_Int_Method_Int;
	GLOBAL_Class_Int.Class_Int_Method_STR=Class_Int_Method_STR;
	GLOBAL_Class_Int.Class_Obj_Method_PRINT=Class_Obj_Method_PRINT;
	GLOBAL_Class_Int.Class_Int_Method_PLUS=Class_Int_Method_PLUS;
	GLOBAL_Class_Int.Class_Int_Method_MINUS=Class_Int_Method_MINUS;
	GLOBAL_Class_Int.Class_Int_Method_TIMES=Class_Int_Method_TIMES;
	GLOBAL_Class_Int.Class_Int_Method_DIVIDE=Class_Int_Method_DIVIDE;
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
	GLOBAL_Class_Top.Class_Top_Method_Top=Class_Top_Method_Top;
	GLOBAL_Class_Top.Class_Obj_Method_STR=Class_Obj_Method_STR;
	GLOBAL_Class_Top.Class_Obj_Method_PRINT=Class_Obj_Method_PRINT;
	GLOBAL_Class_Top.Class_Top_Method_foo=Class_Top_Method_foo;
	GLOBAL_Class_Top.Class_Top_Method_forever=Class_Top_Method_forever;
	GLOBAL_Class_Top.Class_Top_Method_test=Class_Top_Method_test;
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
<<<<<<< HEAD
	GLOBAL_Class_Bottom.Class_Bottom_Method_RunAlways=Class_Bottom_Method_RunAlways;
=======
>>>>>>> 4b6217d8e273d4a1fee1eb2c14853e397372a100
	class_MAIN_method_MAIN();
	return 0;
}
