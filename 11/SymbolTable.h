#include <map>
#include <string>
#include "global.h"

typedef struct identifier {
	std::string type;
	Category category;
	int index;
	bool define;
}IDENTIFIER;

class SymbolTable {
	private:
		std::map<std::string, IDENTIFIER> st_class;
		std::map<std::string, IDENTIFIER> st_subroutine;
		int indexofstatic;
		int indexoffield;
		int indexofvar;
		int indexofargument;
	public:
		SymbolTable();
		void startSubroutine();
		void define(std::string _name, std::string _type, Category _category);
		int VarCount(Category _category);
		Category KindOf(std::string _name);
		std::string TypeOf(std::string _name);
		int IndexOf(std::string _name);
};