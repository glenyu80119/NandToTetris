#include <string>
#include <fstream>
#include "JackTokenizer.h"
#include "SymbolTable.h"
#include "global.h"


class CompilationEngine {
	private:
		std::string current_token;
		Category kind;
		std::string type;
		void eat(std::string token);
		JackTokenizer jt;
		SymbolTable st;
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