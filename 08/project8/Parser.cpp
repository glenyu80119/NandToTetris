

#include <iostream>
#include <assert.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include "Parser.h"

Parser::Parser(string filename) {
	input.open(filename);
	if (!input) 
		cout << "File open failed" << endl;
	
	arithmetic.insert("add");
	arithmetic.insert("sub");
	arithmetic.insert("neg");
	arithmetic.insert("eq");
	arithmetic.insert("gt");
	arithmetic.insert("lt");
	arithmetic.insert("and");
	arithmetic.insert("or");
	arithmetic.insert("not");
	arithmetic.insert("return");
	pushpop.insert("push");
	pushpop.insert("pop");
	pushpop.insert("call");
	pushpop.insert("function");
	pushpop.insert("call");
	branch.insert("label");
	branch.insert("if-goto");
	branch.insert("goto");
	
}

bool Parser::hasMoreCommands() {
	return !input.eof();
}

void Parser::advance() {
	command1 = "";
	command2 = "";
	command3 = "";
	string temp;
	do {
	getline(input, temp); 
	}while(((temp[0] == '/' && temp[1] == '/') || temp.length() == 0) && !input.eof());
	if (temp.length() == 0)
		return;
	stringstream ss(temp);
	string token;
	while(getline(ss, token,' ')) {
		current_command.push_back(token);
	}
	if (arithmetic.find(current_command.front()) != arithmetic.end()) {
		command1 = current_command.front();
		current_command.pop_front();
	}
	else if (pushpop.find(current_command.front()) != pushpop.end()){
		command1 = current_command.front();
		current_command.pop_front();
		command2 = current_command.front();
		current_command.pop_front();
		command3 = current_command.front();
		current_command.pop_front();
	}
	else if (branch.find(current_command.front()) != branch.end()) {
		command1 = current_command.front();
		current_command.pop_front();
		command2 = current_command.front();
		current_command.pop_front();
	}
	current_command.clear();
}

CommandType Parser::commandType() {
	CommandType cm;
	if (command1 == "return")
		cm = C_RETURN;
	else if (command1 == "push")
		cm = C_PUSH;
	else if (command1 == "pop")
		cm = C_POP;
	else if (command1 == "label")
		cm = C_LABEL;
	else if (command1 == "goto")
		cm = C_GOTO;
	else if (command1 == "if-goto")
		cm = C_IF;
	else if (command1 == "function")
		cm = C_FUNCTION;
	else if (command1 == "call")
		cm = C_CALL;
	else if (arithmetic.find(command1) != arithmetic.end())
		cm = C_ARITHMETIC;
	return  cm;
}

string Parser::arg1() {
	assert(commandType() != C_RETURN);
	if (commandType() == C_ARITHMETIC)
		return command1;
	else {
		return command2;
	}
}

int Parser::arg2() {
	assert(commandType() == C_PUSH || commandType() == C_POP ||commandType() == C_FUNCTION || commandType() == C_CALL);
	return atoi(command3.c_str());
}
