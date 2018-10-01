
#include <iostream>
#include <vector>
#include <assert.h>
#include <string.h>
#include "CodeWriter.h"

using namespace std;

CodeWriter::CodeWriter(string filename) {
	output.open(filename);
	equal_num = 0;
	gt_num = 0;
	lt_num = 0;
}
void CodeWriter::writeArithmetic(string command) {
	output << "//" << command << endl;
	if (command == "add") {
		output << "@SP" << endl;
		output << "M = M-1" << endl;
		output << "A = M" << endl;
		output << "D = M" << endl;
		output << "@SP" << endl;
		output << "M = M-1" << endl;
		output << "A = M" << endl;
		output << "M = D + M" << endl;
		output << "@SP" << endl;
		output << "M = M+1" << endl;
	}
	else if (command == "sub") {
		output << "@SP" << endl;
		output << "M = M-1" << endl;
		output << "A = M" << endl;
		output << "D = M" << endl;
		output << "@SP" << endl;
		output << "M = M-1" << endl;
		output << "A = M" << endl;
		output << "M = M - D" << endl;
		output << "@SP" << endl;
		output << "M = M+1" << endl;
	}
	else if (command == "neg") {
		output << "@SP" << endl;
		output << "M = M-1" << endl;
		output << "A = M" << endl;
		output << "M = -M" << endl;
		output << "@SP" << endl;
		output << "M = M+1" << endl;
	}
	else if (command == "eq") {
		output << "@SP" << endl;
		output << "M = M-1" << endl;
		output << "A = M" << endl;
		output << "D = M" << endl;
		output << "@SP" << endl;
		output << "M = M-1" << endl;
		output << "A = M" << endl;
		output << "D = M - D" << endl;
		output << "@EQUAL" <<equal_num <<endl;
		output << "D; JEQ" << endl;
		output << "@SP" << endl;
		output << "A = M" << endl;
		output << "M = 0" << endl;
		output << "@EQUAL_END" <<equal_num <<endl;
		output << "0; JMP" << endl;
		output << "(EQUAL" << equal_num << ")" <<endl;
		output << "@SP" << endl;
		output << "A = M" << endl;
		output << "M = -1" << endl;
		output << "(EQUAL_END" << equal_num << ")" <<endl;
		output << "@SP" << endl;
		output << "M = M+1" << endl;
		equal_num++;
	}
	else if (command == "gt") {
		output << "@SP" << endl;
		output << "M = M-1" << endl;
		output << "A = M" << endl;
		output << "D = M" << endl;
		output << "@SP" << endl;
		output << "M = M-1" << endl;
		output << "A = M" << endl;
		output << "D = M - D" << endl;
		output << "@GT" << gt_num <<endl;
		output << "D; JGT" << endl;
		output << "@SP" << endl;
		output << "A = M" << endl;
		output << "M = 0" << endl;
		output << "@GT_END" <<gt_num <<endl;
		output << "0; JMP" << endl;
		output << "(GT" << gt_num << ")" <<endl;
		output << "@SP" << endl;
		output << "A = M" << endl;
		output << "M = -1" << endl;
		output << "(GT_END" << gt_num << ")" <<endl;
		output << "@SP" << endl;
		output << "M = M+1" << endl;
		gt_num++;
	}
	else if (command == "lt") {
		output << "@SP" << endl;
		output << "M = M-1" << endl;
		output << "A = M" << endl;
		output << "D = M" << endl;
		output << "@SP" << endl;
		output << "M = M-1" << endl;
		output << "A = M" << endl;
		output << "D = M - D" << endl;
		output << "@LT" << lt_num <<endl;
		output << "D; JLT" << endl;
		output << "@SP" << endl;
		output << "A = M" << endl;
		output << "M = 0" << endl;
		output << "@LT_END" <<lt_num <<endl;
		output << "0; JMP" << endl;
		output << "(LT" << lt_num << ")" <<endl;
		output << "@SP" << endl;
		output << "A = M" << endl;
		output << "M = -1" << endl;
		output << "(LT_END" << lt_num << ")" <<endl;
		output << "@SP" << endl;
		output << "M = M+1" << endl;
		lt_num++;
	}
	else if (command == "and") {
		output << "@SP" << endl;
		output << "M = M-1" << endl;
		output << "A = M" << endl;
		output << "D = M" << endl;
		output << "@SP" << endl;
		output << "M = M-1" << endl;
		output << "A = M" << endl;
		output << "M = M & D" << endl;
		output << "@SP" << endl;
		output << "M = M+1" << endl;
	}
	else if (command == "or") {
		output << "@SP" << endl;
		output << "M = M-1" << endl;
		output << "A = M" << endl;
		output << "D = M" << endl;
		output << "@SP" << endl;
		output << "M = M-1" << endl;
		output << "A = M" << endl;
		output << "M = M | D" << endl;
		output << "@SP" << endl;
		output << "M = M+1" << endl;
	}
	else if (command == "not") {
		output << "@SP" << endl;
		output << "M = M-1" << endl;
		output << "A = M" << endl;
		output << "M = !M" << endl;
		output << "@SP" << endl;
		output << "M = M+1" << endl;
	}
	
}

void CodeWriter::writePushPop(CommandType command, string segment, int index) {
	output << "//" << command << " " << segment << " " << index << endl;
	if (command == C_PUSH) {
		if (segment == "constant") {
			output << "@" << index << endl;
			output << "D = A" << endl;
			output << "@SP" << endl;
			output << "A = M" << endl;
			output << "M = D" << endl;
			output << "@SP" << endl;
			output << "M = M + 1" << endl;
		}
		else if (segment == "temp") {
			output << "@" << (5+index) << endl;
			output << "D = M" << endl;
			output << "@SP"  << endl;
			output << "A = M" << endl;
			output << "M = D" << endl;
			output << "@SP" << endl;
			output << "M = M + 1" << endl;
		}
		else if (segment == "pointer") {
			output << "@" << (3+index) << endl;
			output << "D = M" << endl;
			output << "@SP"  << endl;
			output << "A = M" << endl;
			output << "M = D" << endl;
			output << "@SP" << endl;
			output << "M = M + 1" << endl;
		}
		else if (segment == "static") {
			output << "@" << (16+index) << endl;
			output << "D = M" << endl;
			output << "@SP"  << endl;
			output << "A = M" << endl;
			output << "M = D" << endl;
			output << "@SP" << endl;
			output << "M = M + 1" << endl;
		}
		else {
			if (segment == "local")
				segment = "1";
			else if (segment == "argument")
				segment = "2";
			else if (segment == "this")
				segment = "3";
			else if (segment == "that")
				segment = "4";
			output << "@" << index << endl;
			output << "D = A" << endl;
			output << "@" << segment << endl;
			output << "A = M + D" << endl;
			output << "D = M" << endl;
			output << "@SP"  << endl;
			output << "A = M" << endl;
			output << "M = D" << endl;
			output << "@SP" << endl;
			output << "M = M + 1" << endl;
		}
		
	}
	else if (command == C_POP){
		if (segment == "temp") {
			output << "@" << index << endl;
			output << "D = A" << endl;
			output << "@" << 5 << endl;
			output << "D = A + D" << endl;
			output << "@temp"  << endl;
			output << "M = D" << endl;
			output << "@SP" << endl;
			output << "M = M - 1" << endl;
			output << "A = M" << endl;
			output << "D = M" << endl;
			output << "@temp"<< endl;
			output << "A = M" << endl;
			output << "M = D" << endl;
		}
		else if (segment == "pointer") {
			output << "@" << index << endl;
			output << "D = A" << endl;
			output << "@" << 3 << endl;
			output << "D = A + D" << endl;
			output << "@temp"  << endl;
			output << "M = D" << endl;
			output << "@SP" << endl;
			output << "M = M - 1" << endl;
			output << "A = M" << endl;
			output << "D = M" << endl;
			output << "@temp"<< endl;
			output << "A = M" << endl;
			output << "M = D" << endl;
		}
		else if (segment == "static") {
			output << "@" << index << endl;
			output << "D = A" << endl;
			output << "@" << 16 << endl;
			output << "D = A + D" << endl;
			output << "@temp"  << endl;
			output << "M = D" << endl;
			output << "@SP" << endl;
			output << "M = M - 1" << endl;
			output << "A = M" << endl;
			output << "D = M" << endl;
			output << "@temp"<< endl;
			output << "A = M" << endl;
			output << "M = D" << endl;
		}
		else {
			if (segment == "local")
				segment = "1";
			else if (segment == "argument")
				segment = "2";
			if (segment == "this")
				segment = "3";
			if (segment == "that")
				segment = "4";
			output << "@" << index << endl;
			output << "D = A" << endl;
			output << "@" << segment << endl;
			output << "D = M + D" << endl;
			output << "@temp"  << endl;
			output << "M = D" << endl;
			output << "@SP" << endl;
			output << "M = M - 1" << endl;
			output << "A = M" << endl;
			output << "D = M" << endl;
			output << "@temp"<< endl;
			output << "A = M" << endl;
			output << "M = D" << endl;
		}
	}
}

void CodeWriter::Close() {
	output.close();
}