
#include <iostream>
#include "CompilationEngine.h"
#include <string>
#include <map>
#include <stdio.h>
#include "dirent.h"
#define GetCurrentDir _getcwd 

using namespace std;

string GetCurrentWorkingDir() { 
   char buff[FILENAME_MAX]; 
   GetCurrentDir(buff, FILENAME_MAX); 
   string current_working_dir(buff); 
   return current_working_dir; 
 } 

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("./JackAnalyzer [filename]/[directory]");
        return -1;
    }
	map<KeyWord, string> keywordforjack;
	{
		keywordforjack[CLASS_] = "class";
		keywordforjack[CONSTRUCTOR_] = "constructor";
		keywordforjack[FUNCTION_] = "function";
		keywordforjack[METHOD_] = "method";
		keywordforjack[FIELD_] = "field";
		keywordforjack[STATIC_] = "static";
		keywordforjack[VAR_] = "var";
		keywordforjack[INT_] = "int";
		keywordforjack[CHAR_] = "char";
		keywordforjack[BOOLEAN_] = "boolean";
		keywordforjack[VOID_] = "void";
		keywordforjack[TRUE_] = "true";
		keywordforjack[FALSE_] = "false";
		keywordforjack[NUL_] = "null";
		keywordforjack[THIS__] = "this";
		keywordforjack[LET_] = "let";
		keywordforjack[DO_] = "do"; 
		keywordforjack[IF_] = "if";
		keywordforjack[ELSE_] = "else";
		keywordforjack[WHILE_] = "while";
		keywordforjack[RETURN_] = "return";
	}
	string inputfile = *(argv+1);
	if (inputfile.length() > 5 && inputfile.substr(inputfile.length()-5, inputfile.length()) == ".jack") {
		string outputfile = inputfile.substr(0, inputfile.length()-5) + ".vm";
		CompilationEngine ce = CompilationEngine(inputfile, outputfile);
		ce.CompileClass();	
	}
	else {
		DIR *dir;
		struct dirent *ent;
		string PWD(GetCurrentWorkingDir());
		string directory = PWD + "\\" + inputfile;
		if ((dir = opendir(directory.c_str())) != NULL) {
			while ((ent = readdir(dir)) != NULL) {
				string file_name = ent->d_name;
				if (file_name.length() <= 5)
					continue;
				if (file_name.substr(file_name.length()-5, 5) == ".jack") {
					string fn = inputfile + "\\" + file_name;
					string outputfile = PWD + "\\" + fn.substr(0, fn.length()-5) + ".vm";
					CompilationEngine ce = CompilationEngine(fn, outputfile);
					cout << outputfile << endl;
					ce.CompileClass();
				}
			}
		}
	}
	return 0;
}