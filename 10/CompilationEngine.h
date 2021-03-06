#include <string>
#include <fstream>
#include "JackTokenizer.h"
#include "global.h"


class CompilationEngine {
	private:
		std::string current_token;
		void eat(std::string token);
		JackTokenizer jt;
		std::ofstream out;
		void advance();
		
	public:
		CompilationEngine(std::string input, std::string output);
		void CompileClass();
		void CompileClassVarDec();
		void CompileSubroutineDec();
		void compileParameterList();
		void compileSubroutineBody();
		void compileStatements();
		void compileLet();
		void compileDo();
		void compileWhile();
		void compileReturn();
		void compileIf();
		void CompileExpression();
		void CompileTerm();
		void CompileExpressionList();
};