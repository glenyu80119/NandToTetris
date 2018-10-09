#include <assert.h>
#include <sstream>
#include <iostream>
#include "JackTokenizer.h"
#include <ctype.h>

JackTokenizer::JackTokenizer(){};
JackTokenizer::JackTokenizer(string filename) {
	input.open(filename);

	keyword.insert("class");
	keyword.insert("constructor");
	keyword.insert("function");
	keyword.insert("method");
	keyword.insert("field");
	keyword.insert("static");
	keyword.insert("var");
	keyword.insert("int");
	keyword.insert("char");
	keyword.insert("boolean");
	keyword.insert("void");
	keyword.insert("true");
	keyword.insert("false");
	keyword.insert("null");
	keyword.insert("this");
	keyword.insert("let");
	keyword.insert("do");
	keyword.insert("if");
	keyword.insert("else");
	keyword.insert("while");
	keyword.insert("return");

	symbolset.insert("{");
	symbolset.insert("}");
	symbolset.insert("(");
	symbolset.insert(")");
	symbolset.insert("[");
	symbolset.insert("]");
	symbolset.insert(".");
	symbolset.insert(",");
	symbolset.insert(";");
	symbolset.insert("+");
	symbolset.insert("-");
	symbolset.insert("*");
	symbolset.insert("/");
	symbolset.insert("&");
	symbolset.insert("|");
	symbolset.insert(">");
	symbolset.insert("<");
	symbolset.insert("=");
	symbolset.insert("~");

	number.insert("0");
	number.insert("1");
	number.insert("2");
	number.insert("3");
	number.insert("4");
	number.insert("5");
	number.insert("6");
	number.insert("7");
	number.insert("8");
	number.insert("9");
	
}


bool JackTokenizer::hasMoreTokens() {
	if (token_bag.empty()){
		string temp;
		if (input.eof())
			return false;
		do {
		getline(input, temp);
		}while(((temp[0] == '/' && temp[1] == '/') || temp.length() == 0) && !input.eof());
		if (temp.length() == 0)
			return false;
		int start = 0;
		int end = 0;
		while(end < temp.size()) {
			start = end;
			while (isspace(temp[start]) && start < temp.size())
				start++;
			end = start;
			while (!isspace(temp[end]) && end < temp.size())
				end++;
			if(start < end) {
				string temptoken(temp.substr(start, end - start));
				token_bag.push_back(temptoken);
				//cout << temptoken << endl;
			}
		}
		// token bag finish
	}
	if (token_bag.empty())
		return hasMoreTokens();
	current_token = token_bag.front();
	if(current_token.size() >=2 && current_token[0] == '/' && current_token[1] == '/') {
		std::cout << "Encounter double /" << endl;
		token_bag.clear();
		return hasMoreTokens();
	}
	else if (current_token.size() >=2 && current_token[0] == '/' && current_token[1] == '*') {
		if (token_bag.size() != 0) {
			string temp = token_bag.back();
			if (temp[temp.size()-1] == '/' && temp[temp.size()-2] == '*'){
				std::cout << "Encounter /* and */" << endl;
				token_bag.clear();
				return hasMoreTokens();
			}
			else {
				string temp2;
				if (input.eof())
					return false;
				do {
					getline(input, temp2); 
				}while(!input.eof() && ((!(temp2[temp2.size()-1] == '/' && temp2[temp2.size()-2] == '*')) || temp2.length() == 0));
				if (temp2.length() == 0)
					return false;
				token_bag.clear();
				return hasMoreTokens();
			}
		}
		else {
			string temp2;
			if (input.eof())
				return false;
			do {
				getline(input, temp2); 
			}while(!input.eof() && ((!(temp2[temp2.size()-1] == '/' && temp2[temp2.size()-2] == '*')) || temp2.length() == 0));
			if (temp2.length() == 0)
				return false;
			token_bag.clear();
			return hasMoreTokens();
		}
	}
	return true;
}

void JackTokenizer::advance() {
	current_token = "";
	current_token = token_bag.front();
	token_bag.pop_front();
	current_token = parseToken(current_token);
}

string JackTokenizer::parseToken(string token) {
	if (keyword.find(token) != keyword.end())
		return token;
	if (symbolset.find(token) != symbolset.end())
		return token;
	int s = token.size();
	int pointer_last = s - 1;
	while (pointer_last >= 0){
		for(int i = pointer_last; i >= 0; i--) {
			string temp(1, token[i]);
			if (symbolset.find(temp) != symbolset.end() && pointer_last == i){
				string token_temp(1, token[i]);
				if(i == 0)
					return token_temp;
				else
					token_bag.push_front(token_temp);
			}
			else
				break;
			pointer_last--;
		}
		int temp_end = pointer_last;
		for(int i = pointer_last; i >= 0; i--) {
			string temp(1, token[i]);
			if (symbolset.find(temp) == symbolset.end()){
				if(pointer_last != 0)
					pointer_last--;
				else if(pointer_last == 0)
					return token.substr(0, temp_end + 1);
			}
			else {
				string token_temp = token.substr(pointer_last + 1, temp_end - pointer_last);
				token_bag.push_front(token_temp);
				break;
			}
		}
	}
}

TokenType JackTokenizer::tokenType() {
	TokenType tt;
	string temp(1, current_token[0]);
	if (keyword.find(current_token) != keyword.end())
		tt = KEYWORD_;
	else if (symbolset.find(current_token) != symbolset.end())
		tt = SYMBOL_;
	else if (current_token[0] == '\"'){
		if (current_token[current_token.size()-1] == '\"') 
			tt = STRING_CONST_;
		else {
			do {
			string temp = current_token;
			advance();
			current_token = temp + " " + current_token;
			//std::cout << current_token << endl;
			}while(current_token[current_token.size()-1] != '\"');
			current_token = current_token.substr(1, current_token.size() - 2);
			tt = STRING_CONST_;
		}
	}
	else if (number.find(temp) == number.end())
		tt = IDENTIFIER_;
	else if (number.find(temp) != number.end())
		tt = INT_CONST_;
	else 
		std::cout << "notype" << std::endl;
	return tt;
}

KeyWord JackTokenizer::keyWord() {
	assert(tokenType() == KEYWORD_);
	KeyWord kw;
	if(current_token == "class")
		kw = CLASS_;
	else if(current_token == "constructor")
		kw = CONSTRUCTOR_;
	else if(current_token == "function")
		kw = FUNCTION_;
	else if(current_token == "method")
		kw = METHOD_;
	else if(current_token == "field")
		kw = FIELD_;
	else if(current_token == "static")
		kw = STATIC_;
	else if(current_token == "var")
		kw = VAR_;
	else if(current_token == "int")
		kw = INT_;
	else if(current_token == "char")
		kw = CHAR_;
	else if(current_token == "boolean")
		kw = BOOLEAN_;
	else if(current_token == "void")
		kw = VOID_;
	else if(current_token == "true")
		kw = TRUE_;
	else if(current_token == "false")
		kw = FALSE_;
	else if(current_token == "null")
		kw = NUL_;
	else if(current_token == "this")
		kw = THIS__;
	else if(current_token == "let")
		kw = LET_;
	else if(current_token == "do")
		kw = DO_;
	else if(current_token == "if")
		kw = IF_;
	else if(current_token == "else")
		kw = ELSE_;
	else if(current_token == "while")
		kw = WHILE_;
	else if(current_token == "return")
		kw = RETURN_;
	
	return kw;
}

char JackTokenizer::symbol() {
	assert(tokenType() == SYMBOL_);
	if(current_token == "{")
		return '{';
	else if(current_token == "}")
		return '}';
	else if(current_token == "(")
		return '(';
	else if(current_token == ")")
		return ')';
	else if(current_token == "[")
		return '[';
	else if(current_token == "]")
		return ']';
	else if(current_token == ".")
		return '.';
	else if(current_token == ",")
		return ',';
	else if(current_token == ";")
		return ';';
	else if(current_token == "+")
		return '+';
	else if(current_token == "-")
		return '-';
	else if(current_token == "*")
		return '*';
	else if(current_token == "/")
		return '/';
	else if(current_token == "&")
		return '&';
	else if(current_token == "|")
		return '|';
	else if(current_token == ">")
		return '>';
	else if(current_token == "<")
		return '<';
	else if(current_token == "=")
		return '=';
	else if(current_token == "~")
		return '~';

}

string JackTokenizer::identifier() {
	assert(tokenType() == IDENTIFIER_);
	return current_token;
}

int JackTokenizer::intVal() {
	assert(tokenType() == INT_CONST_);
	return atoi(current_token.c_str());
}
string JackTokenizer::stringVal() {
	return current_token.substr(1, current_token.size() - 2);
}

string JackTokenizer::c_token() {
	return current_token;
}