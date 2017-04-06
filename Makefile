CXXFLAGS = -g -std=c++11 

BISON=bison
FLEX=flex

OBJS =		quack.tab.o lex.yy.o GraphVizNodeDecorator.o ProgramNode.o QuackDefines.o QuackStatements.o QuackExpressions.o CompilerDB.o QuackProgramValidator.o QuackBuiltIns.o NativeObject.o CCodeGenerator.o


TARGET =	quack



$(TARGET):	$(OBJS)
	g++ $(CXXFLAGS) quack.tab.hpp QuackCompiler4.cpp $(OBJS)  -o $(TARGET) 



all:	$(TARGET) 

clean:
	rm -f $(OBJS) $(TARGET) quack.tab.cpp quack.tab.hpp lex.yy.cpp *.orig *.dot


# Add -t for trace mode
quack.tab.cpp quack.tab.hpp lex.yy.cpp:
	$(BISON) -d -t -v quack.y
	mv quack.tab.c quack.tab.cpp 
	mv quack.tab.h quack.tab.hpp	
	$(FLEX) -d quack.lex
	mv lex.yy.c lex.yy.cpp


%.o: %.cpp 
	g++ $(CXXFLAGS) -c -o $@ $<  $(LLVM_CPP_FLAGS) $(LLVM_LD_FLAGS)



