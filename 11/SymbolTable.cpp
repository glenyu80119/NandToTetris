#include "SymbolTable.h"
#include <string>

SymbolTable::SymbolTable (){
	indexofstatic = 0;
	indexoffield = 0;
	indexofvar = 0;
	indexofargument = 0;
	st_class.clear();
	st_subroutine.clear();
}

void SymbolTable::startSubroutine(){
	st_subroutine.clear();
}

void SymbolTable::define(std::string _name, std::string _type, Category _category) {
	if (_category == STATIC_C) {
		IDENTIFIER id = {_type, _category, indexofstatic++};
		st_class[_name] = id;
	}
	else if (_category == FIELD_C) {
		IDENTIFIER id = {_type, _category, indexoffield++};
		st_class[_name] = id;
	}
	else if (_category == ARG_C) {
		IDENTIFIER id = {_type, _category, indexofargument++};
		st_subroutine[_name] = id;
	}
	else if (_category == VAR_C) {
		IDENTIFIER id = {_type, _category, indexofvar++};
		st_subroutine[_name] = id;
	}
}

int SymbolTable::VarCount(Category _category) {
	if (_category == STATIC_C)
		return indexofstatic;
	else if (_category == FIELD_C)
		return indexoffield;
	else if (_category == ARG_C)
		return indexofargument;
	else if (_category == VAR_C)
		return indexofvar;
}

Category SymbolTable::KindOf(std::string _name){
	if (st_subroutine.find(_name) != st_subroutine.end()){
		IDENTIFIER id = st_subroutine[_name];
		return id.category;
	}
	
	if (st_class.find(_name) != st_class.end()){
		IDENTIFIER id = st_class[_name];
		return id.category;
	}
	
	return NONE_C;
}

std::string SymbolTable::TypeOf(std::string _name){
	if (st_subroutine.find(_name) != st_subroutine.end()){
		IDENTIFIER id = st_subroutine[_name];
		return id.type;
	}
	
	if (st_class.find(_name) != st_class.end()){
		IDENTIFIER id = st_class[_name];
		return id.type;
	}
	
	return "none";
}


int SymbolTable::IndexOf(std::string _name) {
	if (st_subroutine.find(_name) != st_subroutine.end()){
		IDENTIFIER id = st_subroutine[_name];
		return id.index;
	}
	
	if (st_class.find(_name) != st_class.end()){
		IDENTIFIER id = st_class[_name];
		return id.index;
	}
	
	return -1;
}