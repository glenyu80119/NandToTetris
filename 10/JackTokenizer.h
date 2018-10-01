#include <fstream>
#include <string>
#include <deque>
#include <set>
#include "global.h"

using namespace std;

class JackTokenizer {
    private:
	    ifstream input;
		deque<string> token_bag;
		set<string> keyword;
		set<string> symbolset;
		set<string> number;
		string current_token;
		string parseToken(string token);
		string wtf_token;
		

	public:
		JackTokenizer(string filename);
		bool hasMoreTokens();
		void advance();
		TokenType tokenType();
		KeyWord keyWord();
		char symbol();
		string identifier();
		int intVal();
		string stringVal();
};