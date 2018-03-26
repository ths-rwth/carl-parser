
// Generated from /home/travis/build/smtrat/carl-parser/src/carl-parser/Serialization.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "SerializationVisitor.h"


namespace carlparser {

/**
 * This class provides an empty implementation of SerializationVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SerializationBaseVisitor : public SerializationVisitor {
public:

  virtual antlrcpp::Any visitStart(SerializationParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCarl_expr(SerializationParser::Carl_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForm_expr(SerializationParser::Form_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormula_nary(SerializationParser::Formula_naryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForm_op_nary(SerializationParser::Form_op_naryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormula_unary(SerializationParser::Formula_unaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstraint(SerializationParser::ConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArith_expr(SerializationParser::Arith_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArith_unary(SerializationParser::Arith_unaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArith_nary(SerializationParser::Arith_naryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolean(SerializationParser::BooleanContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(SerializationParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReal_variable(SerializationParser::Real_variableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBool_variable(SerializationParser::Bool_variableContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace carlparser
