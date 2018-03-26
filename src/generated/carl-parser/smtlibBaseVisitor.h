
// Generated from /home/travis/build/smtrat/carl-parser/src/carl-parser/smtlib.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "smtlibVisitor.h"


namespace carlparser {

/**
 * This class provides an empty implementation of smtlibVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  smtlibBaseVisitor : public smtlibVisitor {
public:

  virtual antlrcpp::Any visitSpec_constant(smtlibParser::Spec_constantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitS_expr(smtlibParser::S_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndex(smtlibParser::IndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier(smtlibParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttribute_value(smtlibParser::Attribute_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttribute(smtlibParser::AttributeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSort(smtlibParser::SortContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQual_identifier(smtlibParser::Qual_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_binding(smtlibParser::Var_bindingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSorted_var(smtlibParser::Sorted_varContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerm(smtlibParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSort_symbol_decl(smtlibParser::Sort_symbol_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMeta_spec_constant(smtlibParser::Meta_spec_constantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFun_symbol_decl(smtlibParser::Fun_symbol_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPar_fun_symbol_decl(smtlibParser::Par_fun_symbol_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTheory_attribute(smtlibParser::Theory_attributeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTheory_decl(smtlibParser::Theory_declContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace carlparser
