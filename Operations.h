#pragma once

#include <map>

namespace carl {

enum OpCode {PLUS, MINUS, MUL, DIV};




struct OpTag {};

struct plus_tag : OpTag 
{ };

struct minus_tag : OpTag 
{ };

struct mul_tag : OpTag 
{ };

struct div_tag : OpTag 
{};


//this map maps the string representations of operations to the corresponding OpCode and arity
static const std::map<std::string,std::pair<OpCode,int>> opCodeStrings = { 
        {"PLUS",std::make_pair(OpCode::PLUS,2)},
		{"MINUS", std::make_pair(OpCode::MINUS,2)},
		{"MUL", std::make_pair(OpCode::MUL,2)},
		{"DIV", std::make_pair(OpCode::DIV,2) } }; 




}
