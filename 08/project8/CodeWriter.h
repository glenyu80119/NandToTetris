

#include <string>
#include <fstream>
#include "global.h"
#include <map>
using namespace std;

class CodeWriter {
    private:
        ofstream output;
		int equal_num;
		int gt_num;
		int lt_num;
		int i;
		int static_i;
		string function_name;
		string file_name;
		map<int, int> staticmap;
        
    public:
        CodeWriter(string filename);
        void writeArithmetic(string command);
        void writePushPop(CommandType command, string segment, int index);
		void writeLabel(string label);
		void writeGoto(string label);
		void writeIf(string label);
		void writeFunction(string functionname, int numVars);
		void writeReturn();
		void writeCall(string functionname, int numArgs);
        void Close();
		void setFileName(string filename);
		void writeInit();
};