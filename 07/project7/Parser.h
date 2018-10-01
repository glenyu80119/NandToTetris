
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include "global.h"
using namespace std;


class Parser {
    private:
        ifstream input;
        vector<string> current_command;
		set<string> arithmetic;
		string command1, command2, command3;
    public:
        Parser(string filename);
        bool hasMoreCommands();
        void advance(); 
        CommandType commandType();
        string arg1();
        int arg2();
};