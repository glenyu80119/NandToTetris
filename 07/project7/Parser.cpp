

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
	
}

bool Parser::hasMoreCommands() {
	return !input.eof();
}

void Parser::advance() {
	string temp;
	do {
	getline(input, temp); 
	}while((temp[0] == '/' && temp[1] == '/') || temp.length() == 0);
	stringstream ss(temp);
	string token;
	while(getline(ss, token,' ')) {
		current_command.push_back(token);
		cout << token << endl;
	}
	if (arithmetic.find(current_command.front()) == arithmetic.end()) {
		command3 = current_command.back();
		current_command.pop_back();
		command2 = current_command.back();
		current_command.pop_back();
		command1 = current_command.back();
		current_command.pop_back();
	}
	else {
		command1 = current_command.back();
		current_command.pop_back();
	}
		
	
}

CommandType Parser::commandType() {
	CommandType cm;
	if (arithmetic.find(command1) != arithmetic.end())
		cm = C_ARITHMETIC;
	else if (command1 == "push")
		cm = C_PUSH;
	else if (command1 == "pop")
		cm = C_POP;
	return  cm;
}

string Parser::arg1() {
	//assert(commandType() == C_CALL);
	if (commandType() == C_ARITHMETIC)
		return command1;//test
	else {
		return command2;
	}
}

int Parser::arg2() {
	assert(commandType() == C_PUSH || commandType() == C_POP ||commandType() == C_FUNCTION || commandType() == C_CALL);
	return atoi(command3.c_str());
}
