
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <string.h>
#include "Parser.h"
#include "CodeWriter.h" 

using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("./VMTranslator [filename]");
        return -1;
    }
    string inputfile = *(argv+1);
    Parser ps = Parser(inputfile);
    string ouputfile = inputfile.substr(0, inputfile.length()-3) + ".asm";
    CodeWriter cw = CodeWriter(ouputfile);
    while(ps.hasMoreCommands()) {
        ps.advance();
        if(ps.commandType() == C_ARITHMETIC)
            cw.writeArithmetic(ps.arg1());
        else if(ps.commandType() == C_PUSH || ps.commandType() == C_POP)
            cw.writePushPop(ps.commandType(), ps.arg1(), ps.arg2());
    }
    cw.Close();

    return 0;
}