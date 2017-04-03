#pragma once

#include "../../core/Monomial.h"
#include "../../core/MultivariatePolynomial.h"
#include "../../core/Term.h"
#include "../../core/Variable.h"


#include <iostream>
#include <sstream>
#include <type_traits>

#include "BenchmarkOperation.h"

namespace carl {





class SerializationStream : public boost::static_visitor<> {
private:
	std::stringstream mStream;
	


	void write(const Monomial::Arg& m) {
		if (m) write(*m);
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
		write<Coeff>(t.coeff());
		write(t.monomial());
	}
	


	void write(const Variable& v) {
		*this << v.getName();
	}

	template<typename Coeff>
	void write(const Coeff& c) {
		mStream << c;
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
			case OpCode::PLUS: *this << "PLUS"; *this << ","; boost::apply_visitor(*this,op1); *this << ","; boost::apply_visitor(*this,op2); *this << ","; boost::apply_visitor(*this,result); break;
			case OpCode::MINUS: *this << "MINUS"; *this << ","; boost::apply_visitor(*this,op1); *this << ","; boost::apply_visitor(*this,op2); *this << ","; boost::apply_visitor(*this,result); break;
			case OpCode::MUL: *this << "MUL"; *this << ","; boost::apply_visitor(*this,op1); *this << ","; boost::apply_visitor(*this,op2); *this << ","; boost::apply_visitor(*this,result); break;
			case OpCode::DIV: *this << "DIV"; *this << ","; boost::apply_visitor(*this,op1); *this << ","; boost::apply_visitor(*this,op2); *this << ","; boost::apply_visitor(*this,result); break;
		} 
		*this << "}";

	}



    void operator()(const Poly& x) 
    {
       write<mpq_class>(x);
    }
    
    void operator()(const TermType& x) 
    {
        write(x);
    }

    void operator()(const Monomial::Arg& x) 
    {
        write(x);
    }

    void operator()(const Variable& x) 
    {
        write(x);
    }
};


	template<>
	void SerializationStream::write<mpq_class>(const mpq_class& c) {
		mStream << c;
		if (carl::isInteger(c)) {
			mStream << "/1";
		} 
	}




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
