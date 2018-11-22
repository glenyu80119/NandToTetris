#include <fstream>
#include "global.h"

class VMWriter {
	private:
		std::ofstream output;
	public:
		VMWriter(){};
		VMWriter(std::string _file);
		void writePush(Segment _segment, int _index);
		void writePop(Segment _segment, int _index);
		void WriteArithmetic(Command _command);
		void WriteLabel(std::string _label);
		void WriteGoto(std::string _label);
		void WriteIf(std::string _label);
		void writeCall(std::string _name, int _nArgs);
		void writeFunction(std::string _name, int _nLocals);
		void writeReturn();
		void close();
};