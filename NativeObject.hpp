#ifndef __NATIVEOBJECT__
#define __NATIVEOBJECT__

#include "quack.tab.hpp"
#include "ProgramNode.hpp"
#include "QuackStatements.hpp"
#include "QuackExpressions.hpp"
#include "QuackDefines.hpp"
#include "CompilerDB.hpp"
#include "QuackProgramValidator.hpp"
#include "QuackBuiltIns.hpp"

class NativeObject : public ClassClass{
public:
	NativeObject();
	virtual ~NativeObject();
private:

};

class NativeInteger : public ClassClass{
public:
	NativeInteger();
	virtual ~NativeInteger();

	void DefineType(std::stringstream &ss);
private:

};

class NativeString : public ClassClass{
public:
	NativeString();
	virtual ~NativeString();

	void DefineType(std::stringstream &ss);

private:
};

class NativeNothing : public ClassClass{
public:
	NativeNothing();
	virtual ~NativeNothing();

private:

};

class NativeBoolean : public ClassClass{
public:
	NativeBoolean();
	virtual ~NativeBoolean();

	void DefineType(std::stringstream &ss);
private:
};



class NativeMethod : public MethodClass{
public:
	NativeMethod(std::string function_name, std::string return_value);
	NativeMethod(std::string function_name, std::string return_value,std::string param_type, std::string param_name);
	virtual ~NativeMethod();
	virtual void generateNativeCode(std::stringstream &ss)=0;

};







#endif
