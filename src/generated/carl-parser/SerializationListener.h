
// Generated from /home/travis/build/smtrat/carl-parser/src/carl-parser/Serialization.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "SerializationParser.h"


namespace carlparser {

/**
 * This interface defines an abstract listener for a parse tree produced by SerializationParser.
 */
class  SerializationListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(SerializationParser::StartContext *ctx) = 0;
  virtual void exitStart(SerializationParser::StartContext *ctx) = 0;

  virtual void enterCarl_expr(SerializationParser::Carl_exprContext *ctx) = 0;
  virtual void exitCarl_expr(SerializationParser::Carl_exprContext *ctx) = 0;

  virtual void enterForm_expr(SerializationParser::Form_exprContext *ctx) = 0;
  virtual void exitForm_expr(SerializationParser::Form_exprContext *ctx) = 0;

  virtual void enterFormula_nary(SerializationParser::Formula_naryContext *ctx) = 0;
  virtual void exitFormula_nary(SerializationParser::Formula_naryContext *ctx) = 0;

  virtual void enterForm_op_nary(SerializationParser::Form_op_naryContext *ctx) = 0;
  virtual void exitForm_op_nary(SerializationParser::Form_op_naryContext *ctx) = 0;

  virtual void enterFormula_unary(SerializationParser::Formula_unaryContext *ctx) = 0;
  virtual void exitFormula_unary(SerializationParser::Formula_unaryContext *ctx) = 0;

  virtual void enterConstraint(SerializationParser::ConstraintContext *ctx) = 0;
  virtual void exitConstraint(SerializationParser::ConstraintContext *ctx) = 0;

  virtual void enterArith_expr(SerializationParser::Arith_exprContext *ctx) = 0;
  virtual void exitArith_expr(SerializationParser::Arith_exprContext *ctx) = 0;

  virtual void enterArith_unary(SerializationParser::Arith_unaryContext *ctx) = 0;
  virtual void exitArith_unary(SerializationParser::Arith_unaryContext *ctx) = 0;

  virtual void enterArith_nary(SerializationParser::Arith_naryContext *ctx) = 0;
  virtual void exitArith_nary(SerializationParser::Arith_naryContext *ctx) = 0;

  virtual void enterBoolean(SerializationParser::BooleanContext *ctx) = 0;
  virtual void exitBoolean(SerializationParser::BooleanContext *ctx) = 0;

  virtual void enterNumber(SerializationParser::NumberContext *ctx) = 0;
  virtual void exitNumber(SerializationParser::NumberContext *ctx) = 0;

  virtual void enterReal_variable(SerializationParser::Real_variableContext *ctx) = 0;
  virtual void exitReal_variable(SerializationParser::Real_variableContext *ctx) = 0;

  virtual void enterBool_variable(SerializationParser::Bool_variableContext *ctx) = 0;
  virtual void exitBool_variable(SerializationParser::Bool_variableContext *ctx) = 0;


};

}  // namespace carlparser
