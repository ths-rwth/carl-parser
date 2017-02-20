#pragma once

#include <map>

namespace carl {

enum OpCode {PLUS, MINUS, MUL, DIV};

static const std::map<std::string,OpCode> opCodeStrings = { 
        {"PLUS", PLUS},
		{"MINUS", MINUS},
		{"MUL", MUL},
		{"DIV", DIV } }; 



struct OpTag {};

struct plus_tag : OpTag {};
struct minus_tag : OpTag {};
struct mul_tag : OpTag {};
struct div_tag : OpTag {};



}
