
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <string.h>
#include "Parser.h"
#include "CodeWriter.h" 
#include "dirent.h"
#include <windows.h>

using namespace std;

string ExePath() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}

int line = 0;

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("./VMTranslator [filename]");
        return -1;
    }
    string inputfile = *(argv+1);
	if (inputfile.substr(inputfile.length()-3, inputfile.length()) == ".vm") {
		Parser ps = Parser(inputfile);
		string ouputfile = inputfile.substr(0, inputfile.length()-3) + ".asm";
		CodeWriter cw = CodeWriter(ouputfile);
		while(ps.hasMoreCommands()) {
			ps.advance();
			CommandType cm = ps.commandType();
			cout << cm << endl;
			if(cm == C_ARITHMETIC)
				cw.writeArithmetic(ps.arg1());
			else if(cm == C_PUSH || cm == C_POP)
				cw.writePushPop(ps.commandType(), ps.arg1(), ps.arg2());
			else if (cm == C_IF) 
				cw.writeIf(ps.arg1());
			else if (cm == C_LABEL)
				cw.writeLabel(ps.arg1());
			else if (cm == C_GOTO) 
				cw.writeGoto(ps.arg1());
			else if (cm == C_FUNCTION) 
				cw.writeFunction(ps.arg1(), ps.arg2());
			else if (cm == C_RETURN)
				cw.writeReturn();
			else if (cm == C_CALL)
				cw.writeCall(ps.arg1(), ps.arg2());
		}
		cw.Close();
	}
	else {
		string ouputfile = inputfile + ".asm";
		CodeWriter cw = CodeWriter(ouputfile);
		DIR *dir;
		struct dirent *ent;
		string PWD(ExePath());
		string directory = PWD + "\\" + inputfile;
		if ((dir = opendir(directory.c_str())) != NULL) {
			cw.writeInit();
			while ((ent = readdir(dir)) != NULL) {
				string file_name = ent->d_name;
				if (file_name.length() <= 3)
					continue;
				if (file_name.substr(file_name.length()-3, file_name.length()) == ".vm") {
					string fn = inputfile + "\\" + file_name;
					Parser ps = Parser(fn);
					cw.setFileName(file_name.substr(0,file_name.length()-3));
					while(ps.hasMoreCommands()) {
						cout << line++ << endl;
						ps.advance();
						CommandType cm = ps.commandType();
						cout << cm << endl;
						if(cm == C_ARITHMETIC)
							cw.writeArithmetic(ps.arg1());
						else if(cm == C_PUSH || cm == C_POP)
							cw.writePushPop(ps.commandType(), ps.arg1(), ps.arg2());
						else if (cm == C_IF) 
							cw.writeIf(ps.arg1());
						else if (cm == C_LABEL)
							cw.writeLabel(ps.arg1());
						else if (cm == C_GOTO) 
							cw.writeGoto(ps.arg1());
						else if (cm == C_FUNCTION) 
							cw.writeFunction(ps.arg1(), ps.arg2());
						else if (cm == C_RETURN)
							cw.writeReturn();
						else if (cm == C_CALL)
							cw.writeCall(ps.arg1(), ps.arg2());
					}
				}
			}
			cw.Close();
			closedir(dir);
		}
	    else {
			printf("No such directory!!!!\n");
		}
	}

    return 0;
}