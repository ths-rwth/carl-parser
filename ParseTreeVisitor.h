#pragma once


#include "./generated/SerializationBaseVisitor.h"
#include "../../core/Monomial.h"
#include "../../core/VariablePool.h"
#include "../../core/Term.h"
#include "../../core/MultivariatePolynomial.h"
#include "BenchmarkOperation.h"


 
namespace carl {

/**
 * This class provides an empty implementation of PolynomialListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class ParseTreeVisitor : public SerializationBaseVisitor {
  

public:

  //virtual antlrcpp::Any visitS(PolynomialParser::SContext *ctx) override {
  //  return visitChildren(ctx);
  //}


  virtual antlrcpp::Any visitS(SerializationParser::SContext *ctx) override {
    return ctx->operationList()->accept(this);
  }


  virtual antlrcpp::Any visitVariable(SerializationParser::VariableContext *ctx) override {
    std::string name = ctx->ID()->getSymbol()->getText(); 
    //try and generate new variable from pool
    Variable newVar;
    auto& pool = VariablePool::getInstance();
    Variable res = pool.findVariableWithName(name);
    if (res != Variable::NO_VARIABLE) {
        newVar = res;
    } else {
     	newVar = freshRealVariable(name);
    }	

    return newVar;	
  }

  //Unfortunately we cannot return a Monomial here, just its content, since antlrcpp::Any can't deal with shared_ptr and Monomial is not copy-constructible
  virtual antlrcpp::Any visitMonomial(SerializationParser::MonomialContext *ctx) override {

    std::vector<std::pair<Variable,uint>> content;
    for (int i = 0; i < ctx->variable().size(); ++i) {
        Variable variable = ctx->variable(i)->accept(this);
        uint exp = std::stoi(ctx->INT(i)->getSymbol()->getText()); 
        content.push_back(std::make_pair(variable,exp)); 
    }

    return content;
  }


  virtual antlrcpp::Any visitTerm(SerializationParser::TermContext *ctx) override {
    
    mpq_class coefficient = parseRational(ctx->RATIONAL());
    std::vector<std::pair<Variable,uint>> content = ctx->monomial()->accept(this);
	/*Monomial::Arg mon = createMonomial();	
	for (int i = 0; i < content.size(); i++) {
		mon = mon * createMonomial(content[i].first,content[i].second);
	} */

    Monomial::Arg mon = createMonomial(std::move(content));
    return Term<mpq_class>(coefficient,mon);
    //return Term<mpq_class>(coefficient,monomial);

  }

  virtual antlrcpp::Any visitPolynomial(SerializationParser::PolynomialContext *ctx) override {

    std::vector<Term<mpq_class>> terms;
    for (int i = 0; i < ctx->term().size(); ++i) {
        Term<mpq_class> term = ctx->term(i)->accept(this);
        terms.push_back(term);
    }
    return MultivariatePolynomial<mpq_class>(terms);
  }
    

  virtual antlrcpp::Any visitOperation(SerializationParser::OperationContext *ctx) override {

    std::string opcode = ctx->ID()->getSymbol()->getText();

//we assume for now there are no operators with mixed operand types:
//determine the type we have here:

	if (ctx->monomial().size() > 0) {

		std::vector<Monomial::Arg> monomials;
		for (int i = 0; i < ctx->monomial().size(); ++i) {
			std::vector<std::pair<Variable,uint>> content = ctx->monomial(i)->accept(this);
			monomials.push_back(createMonomial(std::move(content)));
		}
		
		return BenchmarkOperation<Monomial::Arg>(opCodeStrings.at(opcode).first, opCodeStrings.at(opcode).second ,monomials);

	} else  if (ctx->term().size() > 0) {

		std::vector<Term<mpq_class>> terms;
		for (int i = 0; i < ctx->term().size(); ++i) {
			terms.push_back(ctx->term(i)->accept(this));
		}
		
		return BenchmarkOperation<Term<mpq_class>>(opCodeStrings.at(opcode).first,opCodeStrings.at(opcode).second,terms);

	} else if (ctx->polynomial().size() > 0) {

		std::vector<MultivariatePolynomial<mpq_class>> polynomials;
		for (int i = 0; i < ctx->polynomial().size(); ++i) {
			polynomials.push_back(ctx->polynomial(i)->accept(this));
		}
		
		return BenchmarkOperation<MultivariatePolynomial<mpq_class>>(opCodeStrings.at(opcode).first,opCodeStrings.at(opcode).second,polynomials);
	} 

	return NULL;

  }
    
    

  virtual antlrcpp::Any visitOperationList(SerializationParser::OperationListContext *ctx) override {

	//TODO: this should be generic for any operand type!
	std::vector<BenchmarkOperation<MultivariatePolynomial<mpq_class>>> operationList;
	for (int i = 0; i < ctx->operation().size(); ++i) {
		operationList.push_back(ctx->operation(i)->accept(this));
	}
	return operationList;

  }


private:
  mpq_class parseRational(antlr4::tree::TerminalNode *rationalNode) {
    return mpq_class(rationalNode->getSymbol()->getText());
  }	



};

}  // namespace carl
