#pragma once

#include "../../core/Monomial.h"
#include "../../core/MultivariatePolynomial.h"
#include "../../core/Term.h"
#include "../../core/Variable.h"


#include <iostream>
#include <sstream>
#include <type_traits>

namespace carl {

class SerializationStream {
private:
	std::stringstream mStream;
	


	void write(const Monomial::Arg& m) {
		if (m) *this << *m;
		else *this << "()";
	}
	
/*
	void write(const Monomial::Content::value_type& m) {
		if (m.second == 0) *this << "1";
		else if (m.second == 1) *this << m.first;
		else {
			*this << "(*";
			for (std::size_t i = 0; i < m.second; i++) *this << " " << m.first;
			*this << ")";
		}
	}
*/

	void write(const Monomial& m) {
		*this << "(";
		for (const auto& e: m.exponents()) {
			write(e.first);
			*this << "^";
			write(e.second);
		}
		*this << ")";
	}
	
	template<typename Coeff>
	void write(const MultivariatePolynomial<Coeff>& mp) {
		*this << "[";
		for (auto it = mp.rbegin(); it != mp.rend(); it++) {
			write(*it);
		}
		*this << "]";
	}
	


	template<typename Coeff>
	void write(const Term<Coeff>& t) {
		write(t.coeff());
		write(t.monomial());
	}
	


	void write(const Variable& v) {
		*this << v.getName();
	}

	
	template<typename T>
	void write(T&& t) {
		mStream << t;
	}


	
public:
	SerializationStream(): mStream() {
	}
	
	template<typename T>
	SerializationStream& operator<<(T&& t) {
		write(static_cast<const std::decay_t<T>&>(t));
		return *this;
	}
	//
	SerializationStream& operator<<(std::ostream& (*os)(std::ostream&)) {
		write(os);
		return *this;
	}
	
	auto content() const {
		return mStream.rdbuf();
	}


	void benchmark(const OpCode& opCode, const OperandVariant& op1, const OperandVariant& op2, const OperandVariant& result) {

		*this << "{";
		switch (opCode) {
			case OpCode::PLUS: *this << "PLUS"; write(op1); write(op2); break;
			case OpCode::MINUS: *this << "MINUS"; write(op1); write(op2); break;
			case OpCode::MUL: *this << "MUL"; write(op1); write(op2); break;
			case OpCode::DIV: *this << "DIV"; write(op1); write(op2); break;
		} 
		*this << "}";

	}
};

std::ostream& operator<<(std::ostream& os, const SerializationStream& ss) {
	return os << ss.content();
}





namespace logging {

void logBenchmark(OpCode opCode, OperandVariant op1, OperandVariant op2, OperandVariant result) {
	SerializationStream os;
	os.benchmark(opCode,op1,op2,result);
	__CARL_LOG(carl::logging::LogLevel::LVL_INFO, "carl.benchmark", os);
} 

}


}
