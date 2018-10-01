
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
	i = 0;
	function_name = "function_name";
	file_name = "file_name";
	static_i = 0;

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
			if(staticmap.find(index) == staticmap.end()) {
				staticmap.insert(pair<int, int>(index, static_i));
				output << "@" << file_name << "." << static_i << endl;
				//output << "@" << (16+index) << endl;
				output << "D = M" << endl;
				output << "@SP"  << endl;
				output << "A = M" << endl;
				output << "M = D" << endl;
				output << "@SP" << endl;
				output << "M = M + 1" << endl;
				static_i++;
			}
			else {
				int ans = staticmap.find(index)->second;
				output << "@" << file_name << "." << ans << endl;
				//output << "@" << (16+index) << endl;
				output << "D = M" << endl;
				output << "@SP"  << endl;
				output << "A = M" << endl;
				output << "M = D" << endl;
				output << "@SP" << endl;
				output << "M = M + 1" << endl;
			}
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
			output << "@R13"  << endl;
			output << "M = D" << endl;
			output << "@SP" << endl;
			output << "M = M - 1" << endl;
			output << "A = M" << endl;
			output << "D = M" << endl;
			output << "@R13"<< endl;
			output << "A = M" << endl;
			output << "M = D" << endl;
		}
		else if (segment == "pointer") {
			output << "@" << index << endl;
			output << "D = A" << endl;
			output << "@" << 3 << endl;
			output << "D = A + D" << endl;
			output << "@R13"  << endl;
			output << "M = D" << endl;
			output << "@SP" << endl;
			output << "M = M - 1" << endl;
			output << "A = M" << endl;
			output << "D = M" << endl;
			output << "@R13"<< endl;
			output << "A = M" << endl;
			output << "M = D" << endl;
		}
		else if (segment == "static") {
			if(staticmap.find(index) == staticmap.end()) {
				staticmap.insert(pair<int, int>(index, static_i));
				output << "@SP" << endl;
				output << "M = M - 1" << endl;
				output << "A = M" << endl;
				output << "D = M" << endl;
				output << "@" << file_name << "." << static_i << endl;
				output << "M = D" << endl;
				static_i++;
			}
			else {
				int ans = staticmap.find(index)->second;
				output << "@SP" << endl;
				output << "M = M - 1" << endl;
				output << "A = M" << endl;
				output << "D = M" << endl;
				output << "@" << file_name << "." << ans << endl;
				output << "M = D" << endl;
			}
			/*output << "@" << index << endl;
			output << "D = A" << endl;
			output << "@" << 16 << endl;
			output << "D = A + D" << endl;
			output << "@R13"  << endl;
			output << "M = D" << endl;
			output << "@SP" << endl;
			output << "M = M - 1" << endl;
			output << "A = M" << endl;
			output << "D = M" << endl;
			output << "@R13"<< endl;
			output << "A = M" << endl;
			output << "M = D" << endl;*/
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
			output << "@R13"  << endl;
			output << "M = D" << endl;
			output << "@SP" << endl;
			output << "M = M - 1" << endl;
			output << "A = M" << endl;
			output << "D = M" << endl;
			output << "@R13"<< endl;
			output << "A = M" << endl;
			output << "M = D" << endl;
		}
	}
}

void CodeWriter::writeLabel(string label) {
	output << "// Label" << label << endl;
	output << "(" << file_name << "." << function_name << "$" << label << ")" << endl;
}

void CodeWriter::writeGoto(string label) {
	output << "// Goto" << label << endl;
	output << "@" << file_name << "." << function_name << "$" << label << endl;
	output << "0; JMP" << endl;
}

void CodeWriter::writeIf(string label) {
	output << "// If-Goto" << label << endl;
	output << "@SP" << endl;
	output << "M = M-1" << endl;
	output << "A = M" << endl;
	output << "D = M" << endl;
	output << "@" << file_name << "." << function_name << "$" << label << endl;
	output << "D; JLT" << endl;
}

void CodeWriter::writeFunction(string functionname, int numVars) {
	output << "//writeFunction " << functionname << endl;
	function_name = functionname;
	output << "(" << functionname << ")" << endl;
	output << "@" << numVars << endl;
	output << "D = A" << endl;
	output << "@" << functionname << "nolocal"  << endl;
	output << "D; JEQ" << endl;
	output << "@R13" << endl;
	output << "M = D" << endl;
	output << "(" << functionname << "loop" << ")" << endl;
	output << "@SP" << endl;
	output << "A = M" << endl;
	output << "M = 0" << endl;
	output << "@SP" << endl;
	output << "M = M+1" << endl;
	output << "@R13" << endl;
	output << "M = M - 1" << endl;
	output << "D = M" << endl;
	output << "@" << functionname << "loop"  << endl;
	output << "D; JGT" << endl;
	output << "(" << functionname << "nolocal)" << endl;
}

void CodeWriter::writeReturn() {
	output << "// writeReturn" << endl;
	output << "@LCL" << endl;
	output << "D = M" << endl;
	output << "@endFrame" << endl;
	output << "M = D" << endl;
	output << "@5" << endl;
	output << "D = D - A" << endl;
	output << "A = D" << endl;
	output << "D = M" << endl;
	output << "@retaddr" << endl;
	output << "M = D" << endl;
	output << "@SP" << endl;
	output << "M = M-1" << endl;
	output << "A = M" << endl;
	output << "D = M" << endl;
	output << "@ARG" << endl;
	output << "A = M" << endl;
	output << "M = D" << endl;
	output << "@ARG" << endl;
	output << "D = M + 1" << endl;
	output << "@SP" << endl;
	output << "M = D" << endl;
	output << "@endFrame" << endl;
	output << "M = M - 1" << endl;
	output << "A = M" << endl;
	output << "D = M" << endl;
	output << "@THAT" << endl;
	output << "M = D" << endl;
	output << "@endFrame" << endl;
	output << "M = M - 1" << endl;
	output << "A = M" << endl;
	output << "D = M" << endl;
	output << "@THIS" << endl;
	output << "M = D" << endl;
	output << "@endFrame" << endl;
	output << "M = M - 1" << endl;
	output << "A = M" << endl;
	output << "D = M" << endl;
	output << "@ARG" << endl;
	output << "M = D" << endl;
	output << "@endFrame" << endl;
	output << "M = M - 1" << endl;
	output << "A = M" << endl;
	output << "D = M" << endl;
	output << "@LCL" << endl;
	output << "M = D" << endl;
	output << "@retaddr" << endl;
	output << "A = M" << endl;
	output << "0; JMP" << endl;

}

void CodeWriter::writeCall(string functionname, int numArgs) {
	output << "//writecall" <<  functionname << endl;
	output << "@" << functionname << "$ret" << i << endl;
	output << "D = A" << endl;
	output << "@SP" << endl;
	output << "A = M" << endl;
	output << "M = D" << endl;
	output << "@SP" << endl;
	output << "M = M + 1" << endl;
	output << "@LCL" << endl;
	output << "D = M" << endl;
	output << "@SP" << endl;
	output << "A = M" << endl;
	output << "M = D" << endl;
	output << "@SP" << endl;
	output << "M = M + 1" << endl;
	output << "@ARG" << endl;
	output << "D = M" << endl;
	output << "@SP" << endl;
	output << "A = M" << endl;
	output << "M = D" << endl;
	output << "@SP" << endl;
	output << "M = M + 1" << endl;
	output << "@THIS" << endl;
	output << "D = M" << endl;
	output << "@SP" << endl;
	output << "A = M" << endl;
	output << "M = D" << endl;
	output << "@SP" << endl;
	output << "M = M + 1" << endl;
	output << "@THAT" << endl;
	output << "D = M" << endl;
	output << "@SP" << endl;
	output << "A = M" << endl;
	output << "M = D" << endl;
	output << "@SP" << endl;
	output << "M = M + 1" << endl;
	
	output << "@SP" << endl;
	output << "D = M" << endl;
	output << "@" << (numArgs+5) << endl;
	output << "D = D - A" << endl;
	output << "@ARG" << endl;
	output << "M = D" << endl;
	output << "@SP" << endl;
	output << "D = M" << endl;
	output << "@LCL" << endl;
	output << "M = D" << endl;
	output << "@" << functionname << endl;
	output << "0; JMP" << endl;
	
	output << "(" << functionname << "$ret" << i++ << ")" << endl;
	
}

void CodeWriter::setFileName(string filename) {
	file_name = filename;
	static_i = 0;
}

void CodeWriter::writeInit() {
	output << "@" << 256 << endl;
	output << "D = A" << endl;
	output << "@SP" << endl;
	output << "M = D" << endl;
	
	output << "@" << "Sys.init" << "$ret" << i << endl;
	output << "D = A" << endl;
	output << "@SP" << endl;
	output << "A = M" << endl;
	output << "M = D" << endl;
	output << "@SP" << endl;
	output << "M = M + 1" << endl;
	output << "@LCL" << endl;
	output << "D = M" << endl;
	output << "@SP" << endl;
	output << "A = M" << endl;
	output << "M = D" << endl;
	output << "@SP" << endl;
	output << "M = M + 1" << endl;
	output << "@ARG" << endl;
	output << "D = M" << endl;
	output << "@SP" << endl;
	output << "A = M" << endl;
	output << "M = D" << endl;
	output << "@SP" << endl;
	output << "M = M + 1" << endl;
	output << "@THIS" << endl;
	output << "D = M" << endl;
	output << "@SP" << endl;
	output << "A = M" << endl;
	output << "M = D" << endl;
	output << "@SP" << endl;
	output << "M = M + 1" << endl;
	output << "@THAT" << endl;
	output << "D = M" << endl;
	output << "@SP" << endl;
	output << "A = M" << endl;
	output << "M = D" << endl;
	output << "@SP" << endl;
	output << "M = M + 1" << endl;
	
	output << "@SP" << endl;
	output << "D = M" << endl;
	output << "@" << 5 << endl;
	output << "D = D - A" << endl;
	output << "@ARG" << endl;
	output << "M = D" << endl;
	output << "@SP" << endl;
	output << "D = M" << endl;
	output << "@LCL" << endl;
	output << "M = D" << endl;
	output << "@" << "Sys.init" << endl;
	output << "0; JMP" << endl;
	
	output << "(" << "Sys.init" << "$ret" << i++ << ")" << endl;
}

void CodeWriter::Close() {
	output.close();
}