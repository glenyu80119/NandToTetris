
#ifndef GLOBAL_H
#define GLOBAL_H

enum TokenType {KEYWORD_, SYMBOL_, IDENTIFIER_, INT_CONST_, STRING_CONST_};
enum KeyWord {CLASS_, CONSTRUCTOR_, FUNCTION_, METHOD_, FIELD_, STATIC_, VAR_, INT_, CHAR_, BOOLEAN_, VOID_, TRUE_, FALSE_, NUL_, THIS__, LET_, DO_, IF_, ELSE_, WHILE_, RETURN_};
enum Category { STATIC_C, FIELD_C, ARG_C, VAR_C, NONE_C};
enum Segment {CONST_W, ARG_W, LOCAL_W, STATIC_W, THIS_W, THAT_W, POINTER_W, TEMP_W};
enum Command {ADD_C, SUB_C, NEG_C, EQ_C, GT_C, LT_C, AND_C, OR_C, NOT_C};

#endif