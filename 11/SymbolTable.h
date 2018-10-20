#include <map>
#include <string>
#include <global.h>

typedef struct identifier {
	string type;
	Category category;
	int index;
	bool defining;
}IDENTIFIER;

class SymbolTable {
	private:
		map<string, IDENTIFIER> st_class;
		map<string, IDENTIFIER> st_subroutine;
	public:
		void startSubroutine();
		void define(string _name, string _type, Category _category);
		int VarCount(Category _category);
		Category KindOf(string _name);
		string TypeOf(string _name);
		int IndexOf(string _name);
};