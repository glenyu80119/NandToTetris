
#include <iostream>
#include "JackTokenizer.h"
#include <string>
#include <map>
#include <stdio.h>
//include <windows.h>
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
	if (inputfile.substr(inputfile.length()-5, inputfile.length()) == ".jack") {
		JackTokenizer jt = JackTokenizer(inputfile);
		//string middlefile = "middle.xml";
		string ouputfile = inputfile.substr(0, inputfile.length()-5) + ".xml";
		ofstream test;
		test.open(ouputfile);
		test << "<tokens>" << endl;
		while(jt.hasMoreTokens()) {
			jt.advance();
			TokenType TT = jt.tokenType();
			if(TT == KEYWORD_) {
				test << "<keyword> " << keywordforjack[jt.keyWord()] << " </keyword>" << endl;
			}
			else if(TT == SYMBOL_){
				if (jt.symbol() == '>')
					test << "<symbol> " << "&gt;" << " </symbol>" << endl;
				else if (jt.symbol() == '<')
					test << "<symbol> " << "&lt;" << " </symbol>" << endl;
				else if (jt.symbol() == '"')
					test << "<symbol> " << "&quot;" << " </symbol>" << endl;
				else if (jt.symbol() == '&')
					test << "<symbol> " << "&amp;" << " </symbol>" << endl;
				else
					test << "<symbol> " << jt.symbol() << " </symbol>" << endl;
			}
			else if (TT == STRING_CONST_) 
				test << "<stringConstant> " << jt.stringVal() << " </stringConstant>" << endl;
			else if (TT == INT_CONST_)
				test << "<integerConstant> " << jt.intVal() << " </integerConstant>" << endl;
			else if (TT == IDENTIFIER_) 
				test << "<identifier> " << jt.identifier() << " </identifier>" << endl;
			else
				cout << "no type" << endl;
		}
		test << "</tokens>";
		test.close();
		/*CompilationEngine ce = CompilationEngine(middlefile, ouputfile);
		CompilationEngine.CompileClass();*/
		
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
				if (file_name.substr(file_name.length()-5, file_name.length()) == ".jack") {
					string fn = inputfile + "\\" + file_name;
					JackTokenizer jt = JackTokenizer(fn);
					string ouputfile = PWD + "\\" + fn.substr(0, fn.length()-5) + ".xml";
					cout << ouputfile << endl;
					ofstream test;
					test.open(ouputfile);
					test << "<tokens>" << endl;
					while(jt.hasMoreTokens()) {
						jt.advance();
						TokenType TT = jt.tokenType();
						if(TT == KEYWORD_) {
							test << "<keyword> " << keywordforjack[jt.keyWord()] << " </keyword>" << endl;
						}
						else if(TT == SYMBOL_){
							if (jt.symbol() == '>')
								test << "<symbol> " << "&gt;" << " </symbol>" << endl;
							else if (jt.symbol() == '<')
								test << "<symbol> " << "&lt;" << " </symbol>" << endl;
							else if (jt.symbol() == '"')
								test << "<symbol> " << "&quot;" << " </symbol>" << endl;
							else if (jt.symbol() == '&')
								test << "<symbol> " << "&amp;" << " </symbol>" << endl;
							else
								test << "<symbol> " << jt.symbol() << " </symbol>" << endl;
						}
						else if (TT == STRING_CONST_) 
							test << "<stringConstant> " << jt.stringVal() << " </stringConstant>" << endl;
						else if (TT == INT_CONST_)
							test << "<integerConstant> " << jt.intVal() << " </integerConstant>" << endl;
						else if (TT == IDENTIFIER_) 
							test << "<identifier> " << jt.identifier() << " </identifier>" << endl;
						else
							cout << "no type" << endl;

					}
					test << "</tokens>";
					test.close();
				}
			}
		}
	}
	return 0;
}