#include "CompilationEngine.h"
#include <iostream>
#include <fstream>
#include <assert.h>

CompilationEngine::CompilationEngine(std::string input, std::string output) {
	out.open(output);
	jt = JackTokenizer(input);
	current_token = "";
}

void CompilationEngine::CompileClass(){
	out << "<class>" << std::endl;
	advance();
	eat("class");
	out << "<keyword> class </keyword>" << std::endl;
	TokenType TT = jt.tokenType();
	assert(TT == IDENTIFIER_);
	out << "<identifier> " << current_token << " </identifier>" << std::endl;
	advance();
	eat("{");
	out << "<symbol> { </symbol>" << std::endl;
	while (current_token == "static" || current_token == "field" || current_token == "function" || current_token == "constructor" || current_token == "method") {
		if (current_token == "static" || current_token == "field")
			CompileClassVarDec();
		else
			CompileSubroutineDec();
	}
	eat("}");
	out << "<symbol> } </symbol>" << std::endl;
	out << "</class>" << std::endl;
	out.close();
}

void CompilationEngine::eat(std::string token) {
	if (token != current_token) {
		//std::cout << "Token: " << token << std::endl;
		//std::cout << "current_token: " << current_token << std::endl;
	}
	assert(token == current_token);

	if (jt.hasMoreTokens()){
		jt.advance();
		current_token = jt.c_token();
	}
	else {
		//std::cout << "EOF!" << std::endl;
	}
}

void CompilationEngine::advance() {
	if (jt.hasMoreTokens()) {
		jt.advance();
		current_token = jt.c_token();
	}
	else {
		//std::cout << "EOF!" << std::endl;
		out.close();
	}
}

void CompilationEngine::CompileClassVarDec() {
	out << "<classVarDec>" << std::endl;
	if(current_token == "static") {
        eat("static");
		out << "<keyword> static </keyword>" << std::endl;
	}
	else {
		eat("field");
		out << "<keyword> field </keyword>" << std::endl;
	}
	//type
	if (current_token == "int") {
		eat("int");
		out << "<keyword> int </keyword>" << std::endl;
	}
	else if (current_token == "char") {
		eat("char");
		out << "<keyword> char </keyword>" << std::endl;
	}
	else if (current_token == "boolean") {
		eat("boolean");
		out << "<keyword> boolean </keyword>" << std::endl;
	}
	else {
		TokenType TT = jt.tokenType();
		assert(TT == IDENTIFIER_);
		out << "<identifier> " << current_token << " </identifier>" << std::endl;
	    advance();
	}
	//varName
	TokenType TT = jt.tokenType();
	assert(TT == IDENTIFIER_);
	out << "<identifier> " << current_token << " </identifier>" << std::endl;
	advance();
	while(current_token == ",") {
		eat(",");
		out << "<symbol> , </symbol>" << std::endl;
		TT = jt.tokenType();
		assert(TT == IDENTIFIER_);
		out << "<identifier> " << current_token << " </identifier>" << std::endl;
		advance();
	}
	eat(";");
	out << "<symbol> ; </symbol>" << std::endl;
	out << "</classVarDec>" << std::endl;
}

void CompilationEngine::CompileSubroutineDec() {
	out << "<subroutineDec>" << std::endl;
	if(current_token == "constructor") {
        eat("constructor");
		out << "<keyword> constructor </keyword>" << std::endl;
	}
	else if (current_token == "function"){
		eat("function");
		out << "<keyword> function </keyword>" << std::endl;
	}
	else{
		eat("method");
		out << "<keyword> method </keyword>" << std::endl;
	}
	//(void|type)
	if (current_token == "void") {
		eat("void");
		out << "<keyword> void </keyword>" << std::endl;
	}
	else {
		//type
		if (current_token == "int") {
			eat("int");
			out << "<keyword> int </keyword>" << std::endl;
		}
		else if (current_token == "char") {
			eat("char");
			out << "<keyword> char </keyword>" << std::endl;
		}
		else if (current_token == "boolean") {
			eat("boolean");
			out << "<keyword> boolean </keyword>" << std::endl;
		}
		else {
			TokenType TT = jt.tokenType();
			assert(TT == IDENTIFIER_);
			out << "<identifier> " << current_token << " </identifier>" << std::endl;
			advance();
		}
	}
	
	//varName
	TokenType TT = jt.tokenType();
	assert(TT == IDENTIFIER_);
	out << "<identifier> " << current_token << " </identifier>" << std::endl;
	advance();
	
	eat("(");
	out << "<symbol> ( </symbol>" << std::endl;
	compileParameterList();
	eat(")");
	out << "<symbol> ) </symbol>" << std::endl;
	compileSubroutineBody();
	out << "</subroutineDec>" << std::endl;
}

void CompilationEngine::compileParameterList() {
	out << "<parameterList>" << std::endl;
	if(current_token == "int" || current_token == "char" || current_token == "boolean" || jt.tokenType() == IDENTIFIER_) {
		//type
		if (current_token == "int") {
			eat("int");
			out << "<keyword> int </keyword>" << std::endl;
		}
		else if (current_token == "char") {
			eat("char");
			out << "<keyword> char </keyword>" << std::endl;
		}
		else if (current_token == "boolean") {
			eat("boolean");
			out << "<keyword> boolean </keyword>" << std::endl;
		}
		else {
			TokenType TT = jt.tokenType();
			assert(TT == IDENTIFIER_);
			out << "<identifier> " << current_token << " </identifier>" << std::endl;
			advance();
		}
		
		//varName
		TokenType TT = jt.tokenType();
		assert(TT == IDENTIFIER_);
		out << "<identifier> " << current_token << " </identifier>" << std::endl;
		advance();
		
		while(current_token == ",") {
			eat(",");
			out << "<symbol> , </symbol>" << std::endl;
			//type
			if (current_token == "int") {
				eat("int");
				out << "<keyword> int </keyword>" << std::endl;
			}
			else if (current_token == "char") {
				eat("char");
				out << "<keyword> char </keyword>" << std::endl;
			}
			else if (current_token == "boolean") {
				eat("boolean");
				out << "<keyword> boolean </keyword>" << std::endl;
			}
			else {
				TokenType TT = jt.tokenType();
				assert(TT == IDENTIFIER_);
				out << "<identifier> " << current_token << " </identifier>" << std::endl;
				advance();
			}
			TT = jt.tokenType();
			assert(TT == IDENTIFIER_);
			out << "<identifier> " << current_token << " </identifier>" << std::endl;
			advance();
		}
		
	}
	out << "</parameterList>" << std::endl;
}

void CompilationEngine::compileSubroutineBody() {
	out << "<subroutineBody>" << std::endl;
	eat("{");
	out << "<symbol> { </symbol>" << std::endl;
	while(current_token == "var") {
		out << "<varDec>" << std::endl;
		eat("var");
		out << "<keyword> var </keyword>" << std::endl;
		//type
		if (current_token == "int") {
			eat("int");
			out << "<keyword> int </keyword>" << std::endl;
		}
		else if (current_token == "char") {
			eat("char");
			out << "<keyword> char </keyword>" << std::endl;
		}
		else if (current_token == "boolean") {
			eat("boolean");
			out << "<keyword> boolean </keyword>" << std::endl;
		}
		else {
			TokenType TT = jt.tokenType();
			assert(TT == IDENTIFIER_);
			out << "<identifier> " << current_token << " </identifier>" << std::endl;
			advance();
		}
		//varName
		TokenType TT = jt.tokenType();
		assert(TT == IDENTIFIER_);
		out << "<identifier> " << current_token << " </identifier>" << std::endl;
		advance();
		while(current_token == ",") {
			eat(",");
			out << "<symbol> , </symbol>" << std::endl;
			TT = jt.tokenType();
			assert(TT == IDENTIFIER_);
			out << "<identifier> " << current_token << " </identifier>" << std::endl;
			advance();
		}
		eat(";");
		out << "<symbol> ; </symbol>" << std::endl;
		out << "</varDec>" << std::endl;
	}
	
	compileStatements();
	eat("}");
	out << "<symbol> } </symbol>" << std::endl;
	out << "</subroutineBody>" << std::endl;
}

void CompilationEngine::compileStatements() {
	out << "<statements>" << std::endl;
	while(current_token == "let" || current_token == "if" || current_token == "while" || current_token == "do" || current_token == "return") {
		if(current_token == "let")
			compileLet();
		else if (current_token == "if")
			compileIf();
		else if (current_token == "while")
			compileWhile();
		else if (current_token == "do")
			compileDo();
		else if (current_token == "return")
			compileReturn();
	}
	out << "</statements>" << std::endl;
	
}


void CompilationEngine::compileLet() {
	//std::cout << "let statement" << std::endl;
	out << "<letStatement>" << std::endl;
	eat("let");
	out << "<keyword> let </keyword>" << std::endl;
	//varname
	TokenType TT = jt.tokenType();
	assert(TT == IDENTIFIER_);
	out << "<identifier> " << current_token << " </identifier>" << std::endl;
	//std::cout << "identifier current_token:" << current_token << std::endl;
	advance();
	if(current_token == "[") {
		eat("[");
		out << "<symbol> [ </symbol>" << std::endl;
		CompileExpression();
		eat("]");
		out << "<symbol> ] </symbol>" << std::endl;
	}
	eat("=");
	out << "<symbol> = </symbol>" << std::endl;
	//std::cout << "Enter expression" << std::endl;
	CompileExpression();
	eat(";");
	out << "<symbol> ; </symbol>" << std::endl;
	out << "</letStatement>" << std::endl;
	//std::cout << "let statement ended" << std::endl;
}

void CompilationEngine::compileIf() {
	//std::cout << "if statement" << std::endl;
	out << "<ifStatement>" << std::endl;
	eat("if");
	out << "<keyword> if </keyword>" << std::endl;
	eat("(");
	out << "<symbol> ( </symbol>" << std::endl;
	
	CompileExpression();
	eat(")");
	out << "<symbol> ) </symbol>" << std::endl;
	eat("{");
	out << "<symbol> { </symbol>" << std::endl;
	
	compileStatements();
	eat("}");
	out << "<symbol> } </symbol>" << std::endl;
	if (current_token == "else") {
		eat("else");
		out << "<keyword> else </keyword>" << std::endl;
		eat("{");
		out << "<symbol> { </symbol>" << std::endl;
		compileStatements();
		eat("}");
		out << "<symbol> } </symbol>" << std::endl;
	}
	out << "</ifStatement>" << std::endl;
	//std::cout << "if statement ended" << std::endl;
}

void CompilationEngine::compileWhile() {
	//std::cout << "while statement" << std::endl;
	out << "<whileStatement>" << std::endl;
	eat("while");
	out << "<keyword> while </keyword>" << std::endl;
	eat("(");
	out << "<symbol> ( </symbol>" << std::endl;
	
	CompileExpression();
	eat(")");
	out << "<symbol> ) </symbol>" << std::endl;
	eat("{");
	out << "<symbol> { </symbol>" << std::endl;
	
	compileStatements();
	eat("}");
	out << "<symbol> } </symbol>" << std::endl;
	out << "</whileStatement>" << std::endl;
	//std::cout << "while statement ended" << std::endl;
}

void CompilationEngine::compileDo() {
	//std::cout << "do statement" << std::endl;
	out << "<doStatement>" << std::endl;
	eat("do");
	out << "<keyword> do </keyword>" << std::endl;
	//Subroutine call
	string temp = current_token;
	advance();
	string next = current_token;
	if(next == "[") {
		out << "<identifier> " << temp << " </identifier>" << std::endl;
		eat("[");
		out << "<symbol> [ </symbol>" << std::endl;
		CompileExpression();
		eat("]");
		out << "<symbol> ] </symbol>" << std::endl;
	}
	else if (next == "(") {
		out << "<identifier> " << temp << " </identifier>" << std::endl;
		eat("(");
		out << "<symbol> ( </symbol>" << std::endl;
		CompileExpressionList();
		eat(")");
		out << "<symbol> ) </symbol>" << std::endl;
	}
	else if (next == ".") {
		out << "<identifier> " << temp << " </identifier>" << std::endl;
		eat(".");
		out << "<symbol> . </symbol>" << std::endl;
		TokenType TT = jt.tokenType();
		assert(TT == IDENTIFIER_);
		out << "<identifier> " << current_token << " </identifier>" << std::endl;
		advance();
		eat("(");
		out << "<symbol> ( </symbol>" << std::endl;
		CompileExpressionList();
		eat(")");
		out << "<symbol> ) </symbol>" << std::endl;
	}
	
	eat(";");
	out << "<symbol> ; </symbol>" << std::endl;
	out << "</doStatement>" << std::endl;
	//std::cout << "do statement ended" << std::endl;
}

void CompilationEngine::compileReturn() {
	//std::cout << "return statement" << std::endl;
	out << "<returnStatement>" << std::endl;
	eat("return");
	out << "<keyword> return </keyword>" << std::endl;
	if (current_token != ";")
		CompileExpression();
	eat(";");
	out << "<symbol> ; </symbol>" << std::endl;
	out << "</returnStatement>" << std::endl;
	//std::cout << "return statement ended" << std::endl;
}

void CompilationEngine::CompileExpression() {
	out << "<expression>" << std::endl;
	CompileTerm();
	while(current_token == "+" || current_token == "-" || current_token == "*" || current_token == "/"
	   || current_token == "&" || current_token == "|" || current_token == ">" || current_token == "<" || current_token == "=") {
		if(current_token == ">")
			current_token = "&gt;";
		else if(current_token == "<")
			current_token = "&lt;";
		else if(current_token == "\"")
			current_token = "&quot;";
		else if(current_token == "&")
			current_token = "&amp;";
		out << "<symbol> "<< current_token << " </symbol>" << std::endl;
		advance();
		CompileTerm();
	   }
	out << "</expression>" << std::endl;
}

void CompilationEngine::CompileTerm() {
	if (current_token == "(") {
		out << "<term>" << std::endl;
		eat("(");
		out << "<symbol> ( </symbol>" << std::endl;
		CompileExpression();
		eat(")");
		out << "<symbol> ) </symbol>" << std::endl;
		out << "</term>" << std::endl;
	}
	else if (current_token == "~") {
		out << "<term>" << std::endl;
		eat("~");
		out << "<symbol> ~ </symbol>" << std::endl;
		CompileTerm();
		out << "</term>" << std::endl;
	}
	else if (current_token == "-") {
		
		out << "<term>" << std::endl;
		eat("-");
		out << "<symbol> - </symbol>" << std::endl;
		CompileTerm();
		out << "</term>" << std::endl;
	}
	else{
		out << "<term>" << std::endl;
		TokenType TT = jt.tokenType();
		if (TT == INT_CONST_) {
			out << "<integerConstant> " << current_token << " </integerConstant>" <<  std::endl;
			advance();
			out << "</term>" << std::endl;
			return;
		}
		if (TT == STRING_CONST_) {
			current_token = jt.c_token();
			out << "<stringConstant> " << current_token << " </stringConstant>" <<  std::endl;
			advance();
			out << "</term>" << std::endl;
			return;
		}
		
		if(current_token == "true" || current_token == "false" || current_token == "null" || current_token == "this") {
			out << "<keyword> " << current_token << " </keyword>" <<  std::endl;
			advance();
			out << "</term>" << std::endl;
			return;
		}
		
		if (TT == IDENTIFIER_) {
			string temp = current_token;
			advance();
			string next = current_token;
			if(next == "[") {
				out << "<identifier> " << temp << " </identifier>" << std::endl;
				eat("[");
				out << "<symbol> [ </symbol>" << std::endl;
				CompileExpression();
				eat("]");
				out << "<symbol> ] </symbol>" << std::endl;
				out << "</term>" << std::endl;
				return;
			}
			else if (next == "(") {
				out << "<identifier> " << temp << " </identifier>" << std::endl;
				eat("(");
				out << "<symbol> ( </symbol>" << std::endl;
				CompileExpressionList();
				eat(")");
				out << "<symbol> ) </symbol>" << std::endl;
				out << "</term>" << std::endl;
				return;
			}
			else if (next == ".") {
				out << "<identifier> " << temp << " </identifier>" << std::endl;
				eat(".");
				out << "<symbol> . </symbol>" << std::endl;
				TokenType TT = jt.tokenType();
				assert(TT == IDENTIFIER_);
				out << "<identifier> " << current_token << " </identifier>" << std::endl;
				advance();
				eat("(");
				out << "<symbol> ( </symbol>" << std::endl;
				CompileExpressionList();
				eat(")");
				out << "<symbol> ) </symbol>" << std::endl;
				out << "</term>" << std::endl;
				return;
			}
			else{
				out << "<identifier> " << temp << " </identifier>" << std::endl;
				out << "</term>" << std::endl;
				return;
			}
		}
	}
}

void CompilationEngine::CompileExpressionList() {
	out << "<expressionList>" << std::endl;
	if(current_token != ")") {
		CompileExpression();
		while (current_token == ",") {
			eat(",");
			out << "<symbol> , </symbol>" << std::endl;
			CompileExpression();
		}
	}
	
	out << "</expressionList>" << std::endl;
	
}