#pragma once


#include "./generated/PolynomialBaseVisitor.h"
#include <carl/core/Monomial.h>
#include <carl/core/VariablePool.h>
#include <carl/core/Term.h>
#include <carl/core/MultivariatePolynomial.h>


 
namespace carl {

/**
 * This class provides an empty implementation of PolynomialListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class PolyVisitor : public PolynomialBaseVisitor {
  

public:

  //virtual antlrcpp::Any visitS(PolynomialParser::SContext *ctx) override {
  //  return visitChildren(ctx);
  //}


  virtual antlrcpp::Any visitS(PolynomialParser::SContext *ctx) override {
    return ctx->polynomial()->accept(this);
  }


  virtual antlrcpp::Any visitVariable(PolynomialParser::VariableContext *ctx) override {
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
    //return freshRealVariable(ctx->ID()->getSymbol()->getText());
  }

  //Unfortunately we cannot return a Monomial here, just its content, since antlrcpp::Any can't deal with shared_ptr and Monomial is not copy-constructible
  virtual antlrcpp::Any visitMonomial(PolynomialParser::MonomialContext *ctx) override {

    std::vector<std::pair<Variable,uint>> content;
    for (int i = 0; i < ctx->variable().size(); ++i) {
        Variable variable = ctx->variable(i)->accept(this);
        uint exp = std::stoi(ctx->INT(i)->getSymbol()->getText()); 
        content.push_back(std::make_pair(variable,exp));
    }
    return content;
    //return carl::createMonomial(std::move(content));

  }


  virtual antlrcpp::Any visitTerm(PolynomialParser::TermContext *ctx) override {
    
    mpq_class coefficient = parseRational(ctx->RATIONAL());
    std::vector<std::pair<Variable,uint>> content = ctx->monomial()->accept(this);
    Monomial::Arg mon = createMonomial(std::move(content));
    return Term<mpq_class>(coefficient,mon);
    //return Term<mpq_class>(coefficient,monomial);

  }

  virtual antlrcpp::Any visitPolynomial(PolynomialParser::PolynomialContext *ctx) override {

    std::vector<Term<mpq_class>> terms;
    for (int i = 0; i < ctx->term().size(); ++i) {
        Term<mpq_class> term = ctx->term(i)->accept(this);
        terms.push_back(term);
    }
    return MultivariatePolynomial<mpq_class>(terms);
  }
    
    




private:
  mpq_class parseRational(antlr4::tree::TerminalNode *rationalNode) {
    return mpq_class(rationalNode->getSymbol()->getText());
  }	



};

}  // namespace carl
