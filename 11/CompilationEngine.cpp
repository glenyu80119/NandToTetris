#include "CompilationEngine.h"
#include <iostream>
#include <fstream>
#include <assert.h>

CompilationEngine::CompilationEngine(std::string input, std::string output) {
	vw = VMWriter(output);
	jt = JackTokenizer(input);
	current_token = "";
	kind = NONE_C;
	type = "";
	class_name = "";
	function_name = "";
	callee_class_name = "";
	callee_function_name = "";
	expression_list_num = 0;
	subroutine_returntype = "";
	if_label_num = 0;
	while_label_num = 0;
	constructor_or_not = false;
	method = false;
}

void CompilationEngine::CompileClass(){
	advance();
	eat("class");
	TokenType TT = jt.tokenType();
	assert(TT == IDENTIFIER_);
	class_name = current_token;
	
	advance();
	eat("{");
	
	while (current_token == "static" || current_token == "field" || current_token == "function" || current_token == "constructor" || current_token == "method") {
		if (current_token == "static" || current_token == "field")
			CompileClassVarDec();
		else
			CompileSubroutineDec();
	}
	eat("}");
	out.close();
	vw.close();
}

void CompilationEngine::eat(std::string token) {
	if (token != current_token) {
	}
	assert(token == current_token);
	
	if (jt.hasMoreTokens()){
		jt.advance();
		current_token = jt.c_token();
	}
	else {
	}
}

void CompilationEngine::advance() {
	if (jt.hasMoreTokens()) {
		jt.advance();
		current_token = jt.c_token();
	}
	else {
		out.close();
	}
}

void CompilationEngine::CompileClassVarDec() {
	
	if(current_token == "static") {
		kind = STATIC_C;
        eat("static");
	}
	else {
		kind = FIELD_C;
		eat("field");
	}
	//type
	if (current_token == "int") {
		type = "int";
		eat("int");
	}
	else if (current_token == "char") {
		type = "char";
		eat("char");
	}
	else if (current_token == "boolean") {
		type = "boolean";
		eat("boolean");
	}
	else {
		TokenType TT = jt.tokenType();
		assert(TT == IDENTIFIER_);
		out << "<identifier> " << current_token << " </identifier>" << std::endl;
		type = current_token;
	    advance();
	}
	//varName
	TokenType TT = jt.tokenType();
	assert(TT == IDENTIFIER_);
	st.define(current_token, type, kind);
	out << "<identifier> " << current_token << "  type:" << st.TypeOf(current_token) << "  kind:" << st.KindOf(current_token) << " index:" << st.IndexOf(current_token)<< " </identifier>" << std::endl;
	advance();
	while(current_token == ",") {
		eat(",");
		out << "<symbol> , </symbol>" << std::endl;
		TT = jt.tokenType();
		assert(TT == IDENTIFIER_);
		st.define(current_token, type, kind);
		out << "<identifier> " << current_token << "  type:" << st.TypeOf(current_token) << "  kind:" << st.KindOf(current_token) << " index:" << st.IndexOf(current_token)<< " </identifier>" << std::endl;
		advance();
	}
	eat(";");
	out << "</classVarDec>" << std::endl;
}

void CompilationEngine::CompileSubroutineDec() {
	out << "<subroutineDec>" << std::endl;
	if(current_token == "constructor") {
        eat("constructor");
		constructor_or_not = true;
		method = false;
	}
	else if (current_token == "function"){
		eat("function");
		constructor_or_not = false;
		method = false;
	}
	else{
		eat("method");
		constructor_or_not = false;
		method = true;
	}
	//(void|type)
	subroutine_returntype = "";
	if (current_token == "void") {
		eat("void");
		out << "<keyword> void </keyword>" << std::endl;
		subroutine_returntype = "void";
	}
	else {
		//type
		if (current_token == "int") {
			eat("int");
		}
		else if (current_token == "char") {
			eat("char");
		}
		else if (current_token == "boolean") {
			eat("boolean");
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
	function_name = current_token;
	advance();
	st.startSubroutine();
	if_label_num = 0;
	while_label_num = 0;
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
	if(method)
		st.define("this", class_name, ARG_C);
	kind = ARG_C;
	if(current_token == "int" || current_token == "char" || current_token == "boolean" || jt.tokenType() == IDENTIFIER_) {
		//type
		type = current_token;
		if (current_token == "int") {
			eat("int");
		}
		else if (current_token == "char") {
			eat("char");
		}
		else if (current_token == "boolean") {
			eat("boolean");
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
		st.define(current_token, type, kind);
		out << "<identifier> " << current_token << "  type:" << st.TypeOf(current_token) << "  kind:" << st.KindOf(current_token) << " index:" << st.IndexOf(current_token)<< " </identifier>" << std::endl;
		advance();
		
		while(current_token == ",") {
			eat(",");
			out << "<symbol> , </symbol>" << std::endl;
			//type
			type = current_token;
			if (current_token == "int") {
				eat("int");
			}
			else if (current_token == "char") {
				eat("char");
			}
			else if (current_token == "boolean") {
				eat("boolean");
			}
			else {
				TokenType TT = jt.tokenType();
				assert(TT == IDENTIFIER_);
				out << "<identifier> " << current_token << " </identifier>" << std::endl;
				advance();
			}
			TT = jt.tokenType();
			assert(TT == IDENTIFIER_);
			st.define(current_token, type, kind);
			out << "<identifier> " << current_token << "  type:" << st.TypeOf(current_token) << "  kind:" << st.KindOf(current_token) << " index:" << st.IndexOf(current_token)<< " </identifier>" << std::endl;
			advance();
		}
		
	}
	out << "</parameterList>" << std::endl;
}

void CompilationEngine::compileSubroutineBody() {
	
	eat("{");
	while(current_token == "var") {
		kind = VAR_C;
		out << "<varDec>" << std::endl;
		eat("var");
		out << "<keyword> var </keyword>" << std::endl;
		//type
		type = current_token;
		if (current_token == "int") {
			eat("int");
		}
		else if (current_token == "char") {
			eat("char");
		}
		else if (current_token == "boolean") {
			eat("boolean");
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
		st.define(current_token, type, kind);
		out << "<identifier> " << current_token << "  type:" << st.TypeOf(current_token) << "  kind:" << st.KindOf(current_token) << " index:" << st.IndexOf(current_token)<< " </identifier>" << std::endl;
		advance();
		while(current_token == ",") {
			eat(",");
			out << "<symbol> , </symbol>" << std::endl;
			TT = jt.tokenType();
			assert(TT == IDENTIFIER_);
			st.define(current_token, type, kind);
			out << "<identifier> " << current_token << "  type:" << st.TypeOf(current_token) << "  kind:" << st.KindOf(current_token) << " index:" << st.IndexOf(current_token)<< " </identifier>" << std::endl;
			advance();
		}
		eat(";");
		out << "<symbol> ; </symbol>" << std::endl;
		out << "</varDec>" << std::endl;
	}
	Category c = VAR_C;
	int nlocal = st.VarCount(c);
	std::string fn = class_name + "." + function_name;
	cout << fn << "   " << nlocal << std::endl;
	vw.writeFunction(fn, nlocal);
	int nfield = st.VarCount(FIELD_C);
	if (constructor_or_not && nfield > 0) {
		vw.writePush(CONST_W, nfield);
		vw.writeCall("Memory.alloc", 1);
		vw.writePop(POINTER_W, 0);
	}
	if (method) {
		vw.writePush(ARG_W, 0);
		vw.writePop(POINTER_W, 0);
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
	
	eat("let");
	//varname
	TokenType TT = jt.tokenType();
	assert(TT == IDENTIFIER_);
	out << "<identifier> " << current_token << " </identifier>" << std::endl;
	Category c = st.KindOf(current_token);
	int index = st.IndexOf(current_token);
	Segment s = catetoseg(c);
	bool arrayornot = false;
	advance();
	if(current_token == "[") {
		vw.writePush(s, index);
		vw.writePop(POINTER_W, 1);
		eat("[");
		out << "<symbol> [ </symbol>" << std::endl;
		CompileExpression();
		vw.writePush(POINTER_W, 1);
		vw.WriteArithmetic(ADD_C);
		vw.writePop(POINTER_W, 1);
		arrayornot = true;
		eat("]");
		out << "<symbol> ] </symbol>" << std::endl;
	}
	eat("=");
	
	CompileExpression();
	if (arrayornot)
		vw.writePop(THAT_W, 0);
	else
		vw.writePop(s, index);
	eat(";");
	
}

void CompilationEngine::compileIf() {
	//std::cout << "if statement" << std::endl;
	
	eat("if");
	
	eat("(");
	CompileExpression();
	//codeWrite(SYMBOL_, "~", false);
	eat(")");
	
	eat("{");
	std::string labelname = "IF_TRUE" + std::to_string(if_label_num);
	std::string labelname2 = "IF_FALSE" + std::to_string(if_label_num);
	std::string labelname3 = "IF_END" + std::to_string(if_label_num++);
	vw.WriteIf(labelname);
	vw.WriteGoto(labelname2);
	vw.WriteLabel(labelname);
	compileStatements();
	eat("}");
	out << "<symbol> } </symbol>" << std::endl;
	if (current_token == "else") {
		vw.WriteGoto(labelname3);
		vw.WriteLabel(labelname2);
		eat("else");
		out << "<keyword> else </keyword>" << std::endl;
		eat("{");
		out << "<symbol> { </symbol>" << std::endl;
		compileStatements();
		eat("}");
		out << "<symbol> } </symbol>" << std::endl;
		vw.WriteLabel(labelname3);
	}
	else {
		vw.WriteLabel(labelname2);
	}
	//std::cout << "if statement ended" << std::endl;
}

void CompilationEngine::compileWhile() {
	std::string labelname = "WHILE_EXP" + std::to_string(while_label_num);
	vw.WriteLabel(labelname);
	eat("while");
	eat("(");
	
	CompileExpression();
	codeWrite(SYMBOL_, "~", false);
	std::string labelname2 = "WHILE_END" + std::to_string(while_label_num++);
	vw.WriteIf(labelname2);
	eat(")");
	eat("{");
	
	compileStatements();
	eat("}");
	vw.WriteGoto(labelname);
	vw.WriteLabel(labelname2);
}

void CompilationEngine::compileDo() {
	//std::cout << "do statement" << std::endl;
	
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
		callee_class_name = class_name;
		callee_function_name = temp;
		out << "<identifier> " << temp << " </identifier>" << std::endl;
		eat("(");
		vw.writePush(POINTER_W, 0);
		CompileExpressionList();
		std::string calleename = callee_class_name + "." + callee_function_name;
		vw.writeCall(calleename, expression_list_num + 1);
		eat(")");
	}
	else if (next == ".") {
		out << "<identifier> " << temp << " </identifier>" << std::endl;
		if (st.TypeOf(temp) != "none"){
			callee_class_name = st.TypeOf(temp);
			Category ccc = st.KindOf(temp);
			Segment sss = catetoseg(ccc);
			vw.writePush(sss, st.IndexOf(temp));
		}
		else
			callee_class_name = temp;
		eat(".");
		out << "<symbol> . </symbol>" << std::endl;
		TokenType TT = jt.tokenType();
		assert(TT == IDENTIFIER_);
		out << "<identifier> " << current_token << " </identifier>" << std::endl;
		callee_function_name = current_token;
		
		advance();
		eat("(");
		out << "<symbol> ( </symbol>" << std::endl;
		CompileExpressionList();
		eat(")");
		out << "<symbol> ) </symbol>" << std::endl;
		
		std::string calleename = callee_class_name + "." + callee_function_name;
		if (st.TypeOf(temp) != "none"){
			vw.writeCall(calleename, expression_list_num + 1);
		}
		else
			vw.writeCall(calleename, expression_list_num);
	}
	vw.writePop(TEMP_W, 0);
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
	
	
	if (subroutine_returntype == "void") {
		Segment s = CONST_W;
		vw.writePush(s, 0);
	}
	vw.writeReturn();
	//std::cout << "return statement ended" << std::endl;
}

void CompilationEngine::CompileExpression() {
	out << "<expression>" << std::endl;
	CompileTerm();
	while(current_token == "+" || current_token == "-" || current_token == "*" || current_token == "/"
	   || current_token == "&" || current_token == "|" || current_token == ">" || current_token == "<" || current_token == "=") {
		/*if(current_token == ">")
			current_token = "&gt;";
		else if(current_token == "<")
			current_token = "&lt;";
		else if(current_token == "\"")
			current_token = "&quot;";
		else if(current_token == "&")
			current_token = "&amp;";*/
		std::string op = current_token;
		//out << "<symbol> "<< current_token << " </symbol>" << std::endl;
		advance();
		CompileTerm();
		TokenType t = SYMBOL_;
		codeWrite(t, op, true);
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
		std::string op = current_token;
		out << "<term>" << std::endl;
		eat("~");
		out << "<symbol> ~ </symbol>" << std::endl;
		CompileTerm();
		TokenType t = SYMBOL_;
		codeWrite(t, op, false);
		out << "</term>" << std::endl;
	}
	else if (current_token == "-") {
		std::string op = current_token;
		out << "<term>" << std::endl;
		eat("-");
		out << "<symbol> - </symbol>" << std::endl;
		CompileTerm();
		TokenType t = SYMBOL_;
		codeWrite(t, op, false);
		out << "</term>" << std::endl;
	}
	else{
		out << "<term>" << std::endl;
		TokenType TT = jt.tokenType();
		if (TT == INT_CONST_) {
			out << "<integerConstant> " << current_token << " </integerConstant>" <<  std::endl;
			codeWrite(TT, current_token, false);
			advance();
			out << "</term>" << std::endl;
			return;
		}
		if (TT == STRING_CONST_) {
			current_token = jt.c_token();
			out << "<stringConstant> " << current_token << " </stringConstant>" <<  std::endl;
			vw.writePush(CONST_W, current_token.length());
			vw.writeCall("String.new", 1);
			//vw.writePop(TEMP_W, 0);
			for(int i = 0; i < current_token.length(); i++){
				//vw.writePush(TEMP_W, 0);
				vw.writePush(CONST_W, current_token[i]);
				vw.writeCall("String.appendChar", 2);
				//vw.writePop(TEMP_W, 0);
			}
			advance();
			out << "</term>" << std::endl;
			return;
		}
		
		if(current_token == "true" || current_token == "false" || current_token == "null" || current_token == "this") {
			if(current_token == "true") {
				codeWrite(INT_CONST_, "0", false);
				codeWrite(SYMBOL_, "~", false);
			}
			else if (current_token == "null" || current_token == "false")
				codeWrite(INT_CONST_, "0", false);
			else{
				vw.writePush(POINTER_W, 0);
			}
			advance();
			return;
		}
		
		if (TT == IDENTIFIER_) {
			string temp = current_token;
			advance();
			string next = current_token;
			if(next == "[") {
				out << "<identifier> " << temp << " </identifier>" << std::endl;
				eat("[");
				Category c = st.KindOf(temp);
				int index = st.IndexOf(temp);
				Segment s = catetoseg(c);
				out << "<symbol> [ </symbol>" << std::endl;
				vw.writePush(s, index);
				vw.writePop(POINTER_W, 1);
				CompileExpression();
				vw.writePush(POINTER_W, 1);
				vw.WriteArithmetic(ADD_C);
				vw.writePop(POINTER_W, 1);
				vw.writePush(THAT_W, 0);
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
				if (st.TypeOf(temp) != "none"){
					callee_class_name = st.TypeOf(temp);
					Category ccc = st.KindOf(temp);
					Segment sss = catetoseg(ccc);
					vw.writePush(sss, st.IndexOf(temp));
				}
				else
					callee_class_name = temp;
				eat(".");
				TokenType TT = jt.tokenType();
				assert(TT == IDENTIFIER_);
				out << "<identifier> " << current_token << " </identifier>" << std::endl;
				callee_function_name = current_token;
				advance();
				eat("(");
				out << "<symbol> ( </symbol>" << std::endl;
				CompileExpressionList();
				std::string calleename = callee_class_name + "." + callee_function_name;
				if (st.TypeOf(temp) != "none"){
					vw.writeCall(calleename, expression_list_num + 1);
				}
				else
					vw.writeCall(calleename, expression_list_num);
				eat(")");
				out << "<symbol> ) </symbol>" << std::endl;
				out << "</term>" << std::endl;
				return;
			}
			else{
				Category c = st.KindOf(temp);
				int index = st.IndexOf(temp);
				Segment s = catetoseg(c);
				vw.writePush(s, index);
				return;
			}
		}
	}
}

void CompilationEngine::CompileExpressionList() {
	out << "<expressionList>" << std::endl;
	expression_list_num = 0;
	if(current_token != ")") {
		CompileExpression();
		expression_list_num = 1;
		while (current_token == ",") {
			eat(",");
			out << "<symbol> , </symbol>" << std::endl;
			CompileExpression();
			expression_list_num++;
		}
	}
	out << "</expressionList>" << std::endl;
}

void CompilationEngine::codeWrite(TokenType _tokentype, std::string _token, bool _minus) {
	if (_tokentype == INT_CONST_) {
		int temp = std::stoi(_token);
		Segment s = CONST_W;
		vw.writePush(s, temp);
	}
	else if (_tokentype == SYMBOL_) {
		if (_token == "+")
			vw.WriteArithmetic(ADD_C);
		else if (_token == "-") {
			if (_minus)
				vw.WriteArithmetic(SUB_C);
			else
				vw.WriteArithmetic(NEG_C);
		}
		else if (_token == "*")
			vw.writeCall("Math.multiply", 2);
		else if (_token == "/")
			vw.writeCall("Math.divide", 2);
		else if (_token == "&")
			vw.WriteArithmetic(AND_C);
		else if (_token == "|")
			vw.WriteArithmetic(OR_C);
		else if (_token == ">")
			vw.WriteArithmetic(GT_C);
		else if (_token == "<")
			vw.WriteArithmetic(LT_C);
		else if (_token == "=")
			vw.WriteArithmetic(EQ_C);
		else if (_token == "~")
			vw.WriteArithmetic(NOT_C);

	}	
}



Segment CompilationEngine::catetoseg(Category _category){
	if(_category == STATIC_C)
		return STATIC_W;
	else if(_category == FIELD_C)
		return THIS_W;
	else if(_category == ARG_C)
		return ARG_W;
	else if(_category == VAR_C)
		return LOCAL_W;
	else if(_category == NONE_C)
		assert(1 == 0);
}