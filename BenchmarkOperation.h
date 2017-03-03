
#pragma once


#include "Operations.h"
#include <vector>
#include <boost/variant.hpp>
#include <boost/variant/multivisitors.hpp>
#include <boost/optional.hpp>




namespace carl {





template <typename T1,typename T2,typename R>
using PlusOperation = std::tuple<plus_tag, T1, T2,boost::optional<R>>;

template<typename T1,typename T2,typename R>
using MinusOperation = std::tuple<minus_tag, T1, T2,boost::optional<R>>;

template<typename T1,typename T2,typename R>
using MulOperation = std::tuple<mul_tag, T1,T2, boost::optional<R>>;

template<typename T1,typename T2,typename R>
using DivOperation = std::tuple<div_tag, T1,T2, boost::optional<R>>;


typedef MultivariatePolynomial<mpq_class> Poly;
typedef Term<mpq_class> TermType;



using OperationVariant = boost::variant<plus_tag,minus_tag,mul_tag,div_tag>;
using OperandVariant = boost::variant<Poly,TermType,Monomial::Arg,Variable>; 

using OperationTuple = std::tuple<OperationVariant,OperandVariant,OperandVariant,OperandVariant>;



struct OperationExecutor : public boost::static_visitor<> {


  template <typename T1, typename T2, typename R>
  void operator()(plus_tag& tag, T1& op1, T2& op2, R& result) const {
  }

  template <typename T1, typename T2, typename R>
  void operator()(minus_tag& tag, T1& op1, T2& op2, R& result) const {
  }


  template<typename T1,typename T2, typename R>
  void operator()(mul_tag& tag, T1& op1, T2& op2, R& result) const {
  }

  template<typename T1,typename T2, typename R>
  void operator()(div_tag& tag, T1& op1, T2& op2, R& result) const {
  }


};


  template<>
  void OperationExecutor::operator()<Poly,Poly,Poly>(plus_tag& tag, Poly& op1, Poly& op2, Poly& result) const {
    auto res = op1 + op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<TermType,Poly,Poly>(plus_tag& tag, TermType& op1, Poly& op2, Poly& result) const {
    auto res = op1 + op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<Monomial::Arg,Poly,Poly>(plus_tag& tag, Monomial::Arg& op1, Poly& op2, Poly& result) const {
    auto res = op1 + op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<Variable,Poly,Poly>(plus_tag& tag, Variable& op1, Poly& op2, Poly& result) const {
    auto res = op1 + op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<TermType,TermType,Poly>(plus_tag& tag, TermType& op1, TermType& op2, Poly& result) const {
    auto res = op1 + op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<Variable,TermType,Poly>(plus_tag& tag, Variable& op1, TermType& op2, Poly& result) const {
    auto res = op1 + op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<Monomial::Arg,TermType,Poly>(plus_tag& tag, Monomial::Arg& op1, TermType& op2, Poly& result) const {
    auto res = op1 + op2;
    assert(res == result);
  }

/* NOT WORKING FOR SOME REASON, TODO: fix this
  template<>
  void OperationExecutor::operator()<Variable,Monomial::Arg,Poly>(plus_tag& tag, Variable& op1, Monomial::Arg& op2, Poly& result) const {
    auto res = op1 + op2;
    assert(res == result);
  }



  template<>
  void OperationExecutor::operator()<Variable,Variable,Poly>(plus_tag& tag, Variable& op1, Variable& op2, Poly& result) const {
    auto res = op1 + op2;
    assert(res == result);
  }

/* 
  template<>
  void OperationExecutor::operator()<Monomial::Arg,Monomial::Arg,Poly>(plus_tag& tag, Monomial::Arg& op1, Monomial::Arg& op2, Poly& result) const {
    Poly res = op1 + op2;
    assert(res == result);
  }
*/










  template<>
  void OperationExecutor::operator()<Poly,Poly,Poly>(minus_tag& tag, Poly& op1, Poly& op2, Poly& result) const {
    auto res = op1 - op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<TermType,Poly,Poly>(minus_tag& tag, TermType& op1, Poly& op2, Poly& result) const {
    auto res = op1 - op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<Monomial::Arg,Poly,Poly>(minus_tag& tag, Monomial::Arg& op1, Poly& op2, Poly& result) const {
    auto res = op1 - op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<Variable,Poly,Poly>(minus_tag& tag, Variable& op1, Poly& op2, Poly& result) const {
    auto res = op1 - op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<TermType,TermType,Poly>(minus_tag& tag, TermType& op1, TermType& op2, Poly& result) const {
    auto res = op1 - op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<Variable,TermType,Poly>(minus_tag& tag, Variable& op1, TermType& op2, Poly& result) const {
    auto res = op1 - op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<Monomial::Arg,TermType,Poly>(minus_tag& tag, Monomial::Arg& op1, TermType& op2, Poly& result) const {
    auto res = op1 - op2;
    assert(res == result);
  }

/* NOT WORKING: TODO: Fix
  template<>
  void OperationExecutor::operator()<Variable,Monomial::Arg,Poly>(minus_tag& tag, Variable& op1, Monomial::Arg& op2, Poly& result) const {
    auto res = op1 - op2;
    assert(res == result);
  }



  template<>
  void OperationExecutor::operator()<Variable,Variable,Poly>(minus_tag& tag, Variable& op1, Variable& op2, Poly& result) const {
    auto res = op1 - op2;
    assert(res == result);
  }

/* 
  template<>
  void OperationExecutor::operator()<Monomial::Arg,Monomial::Arg,Poly>(minus_tag& tag, Monomial::Arg& op1, Monomial::Arg& op2, Poly& result) const {
    Poly res = op1 - op2;
    assert(res == result);
  }


*/










  template<>
  void OperationExecutor::operator()<Poly,Poly,Poly>(mul_tag& tag, Poly& op1, Poly& op2, Poly& result) const {
    auto res = op1 * op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<TermType,Poly,Poly>(mul_tag& tag, TermType& op1, Poly& op2, Poly& result) const {
    auto res = op1 * op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<Monomial::Arg,Poly,Poly>(mul_tag& tag, Monomial::Arg& op1, Poly& op2, Poly& result) const {
    auto res = op1 * op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<Variable,Poly,Poly>(mul_tag& tag, Variable& op1, Poly& op2, Poly& result) const {
    auto res = op1 * op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<TermType,TermType,TermType>(mul_tag& tag, TermType& op1, TermType& op2, TermType& result) const {
    auto res = op1 * op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<Monomial::Arg,TermType,TermType>(mul_tag& tag, Monomial::Arg& op1, TermType& op2, TermType& result) const {
    auto res = op1 * op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<Variable,TermType,TermType>(mul_tag& tag, Variable& op1, TermType& op2, TermType& result) const {
    auto res = op1 * op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<Monomial::Arg,Monomial::Arg,Monomial::Arg>(mul_tag& tag, Monomial::Arg& op1, Monomial::Arg& op2, Monomial::Arg& result) const {
    auto res = op1 * op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<Variable,Monomial::Arg,Monomial::Arg>(mul_tag& tag, Variable& op1, Monomial::Arg& op2, Monomial::Arg& result) const {
    auto res = op1 * op2;
    assert(res == result);
  }

  template<>
  void OperationExecutor::operator()<Variable,Variable,Monomial::Arg>(mul_tag& tag, Variable& op1, Variable& op2, Monomial::Arg& result) const {
    auto res = op1 * op2;
    assert(res == result);
  }






  template<>
  void OperationExecutor::operator()<Poly,Poly,Poly>(div_tag& tag, Poly& op1, Poly& op2, Poly& result) const {
    auto res = op1 / op2;
    assert(res == result);
  }





class BenchmarkOperation {
private:
  OperationTuple mData;
public:

  BenchmarkOperation(const OpCode& opCode, const int& arity, const std::vector<OperandVariant>& operandsAndResult) {
	
	//boost::optional<OperandVariant> expectedResult;
	//if (operandsAndResult.size() > arity) {
	OperandVariant	expectedResult = operandsAndResult[arity];
	//} else {
	//	expectedResult = boost::none;
	//}

	switch (opCode) {
		case OpCode::PLUS: mData = std::make_tuple(plus_tag(),operandsAndResult[0],operandsAndResult[1],expectedResult); break;	
		case OpCode::MINUS: mData = std::make_tuple(minus_tag(),operandsAndResult[0],operandsAndResult[1],expectedResult); break;	
		case OpCode::MUL: mData = std::make_tuple(mul_tag(),operandsAndResult[0],operandsAndResult[1],expectedResult); break;	
		case OpCode::DIV: mData = std::make_tuple(div_tag(),operandsAndResult[0],operandsAndResult[1],expectedResult); break;	

	}

  }
	


  void execute() {
    boost::apply_visitor(OperationExecutor(), std::get<0>(mData), std::get<1>(mData), std::get<2>(mData), std::get<3>(mData));
  }
};


}



