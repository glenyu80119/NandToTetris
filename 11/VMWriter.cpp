#include "VMWriter.h"

VMWriter::VMWriter(std::string _file) {
	output.open(_file);
}

void VMWriter::writePush(Segment _segment, int _index){
	std::string segment;
	if (_segment == CONST_W)
		segment = "constant";
	else if (_segment == ARG_W)
		segment = "argument";
	else if (_segment == LOCAL_W)
		segment = "local";
	else if (_segment == STATIC_W)
		segment = "static";
	else if (_segment == THIS_W)
		segment = "this";
	else if (_segment == THAT_W)
		segment = "that";
	else if (_segment == POINTER_W)
		segment = "pointer";
	else if (_segment == TEMP_W)
		segment = "temp";
	output << "push " << segment << " " << _index << std::endl;
}

void VMWriter::writePop(Segment _segment, int _index){
	std::string segment;
	if (_segment == CONST_W)
		segment = "constant";
	else if (_segment == ARG_W)
		segment = "argument";
	else if (_segment == LOCAL_W)
		segment = "local";
	else if (_segment == STATIC_W)
		segment = "static";
	else if (_segment == THIS_W)
		segment = "this";
	else if (_segment == THAT_W)
		segment = "that";
	else if (_segment == POINTER_W)
		segment = "pointer";
	else if (_segment == TEMP_W)
		segment = "temp";
	output << "pop " << segment << " " << _index << std::endl;
	
}

void VMWriter::WriteArithmetic(Command _command){
	if (_command == ADD_C)
		output << "add" << std::endl;
	else if (_command == SUB_C)
		output << "sub" << std::endl;
	else if (_command == NEG_C)
		output << "neg" << std::endl;
	else if (_command == EQ_C)
		output << "eq" << std::endl;
	else if (_command == GT_C)
		output << "gt" << std::endl;
	else if (_command == LT_C)
		output << "lt" << std::endl;
	else if (_command == AND_C)
		output << "and" << std::endl;
	else if (_command == OR_C)
		output << "or" << std::endl;
	else if (_command == NOT_C)
		output << "not" << std::endl;
}

void VMWriter::writeFunction(std::string _name, int _nLocals) {
	output << "function " << _name << " " << _nLocals << std::endl;
}

void VMWriter::writeCall(std::string _name, int _nArgs){
	output << "call " << _name << " " << _nArgs << std::endl;
}

void VMWriter::writeReturn() {
	output << "return" << std::endl;
}

void VMWriter::WriteLabel(std::string _label) {
	output << "label " <<  _label << std::endl;
}

void VMWriter::WriteIf(std::string _label) {
	output << "if-goto " << _label << std::endl; 
}

void VMWriter::WriteGoto(std::string _label) {
	output << "goto " << _label << std::endl; 
}

void VMWriter::close() {
	output.close();
}