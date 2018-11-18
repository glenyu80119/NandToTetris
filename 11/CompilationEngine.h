#include <string>
#include <fstream>
#include "JackTokenizer.h"
#include "SymbolTable.h"
#include "VMWriter.h"
#include "global.h"


class CompilationEngine {
	private:
		std::string current_token;
		std::string class_name;
		std::string function_name;
		std::string callee_class_name;
		std::string callee_function_name;
		int expression_list_num;
		std::string subroutine_returntype;
		bool constructor_or_not;
		bool method;
		int label_num;
		Category kind;
		std::string type;
		void eat(std::string token);
		JackTokenizer jt;
		SymbolTable st;
		VMWriter vw;
		std::ofstream out;
		void advance();
		void codeWrite(TokenType _tokentype, std::string _token, bool _minus);
		Segment catetoseg(Category _category);
		
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