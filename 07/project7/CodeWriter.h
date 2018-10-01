

#include <string>
#include <fstream>
#include "global.h"
using namespace std;

class CodeWriter {
    private:
        ofstream output;
		int equal_num;
		int gt_num;
		int lt_num;
        
    public:
        CodeWriter(string filename);
        void writeArithmetic(string command);
        void writePushPop(CommandType command, string segment, int index);
        void Close();
};