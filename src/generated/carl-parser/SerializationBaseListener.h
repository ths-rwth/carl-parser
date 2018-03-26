
// Generated from /home/travis/build/smtrat/carl-parser/src/carl-parser/Serialization.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "SerializationListener.h"


namespace carlparser {

/**
 * This class provides an empty implementation of SerializationListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SerializationBaseListener : public SerializationListener {
public:

  virtual void enterStart(SerializationParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(SerializationParser::StartContext * /*ctx*/) override { }

  virtual void enterCarl_expr(SerializationParser::Carl_exprContext * /*ctx*/) override { }
  virtual void exitCarl_expr(SerializationParser::Carl_exprContext * /*ctx*/) override { }

  virtual void enterForm_expr(SerializationParser::Form_exprContext * /*ctx*/) override { }
  virtual void exitForm_expr(SerializationParser::Form_exprContext * /*ctx*/) override { }

  virtual void enterFormula_nary(SerializationParser::Formula_naryContext * /*ctx*/) override { }
  virtual void exitFormula_nary(SerializationParser::Formula_naryContext * /*ctx*/) override { }

  virtual void enterForm_op_nary(SerializationParser::Form_op_naryContext * /*ctx*/) override { }
  virtual void exitForm_op_nary(SerializationParser::Form_op_naryContext * /*ctx*/) override { }

  virtual void enterFormula_unary(SerializationParser::Formula_unaryContext * /*ctx*/) override { }
  virtual void exitFormula_unary(SerializationParser::Formula_unaryContext * /*ctx*/) override { }

  virtual void enterConstraint(SerializationParser::ConstraintContext * /*ctx*/) override { }
  virtual void exitConstraint(SerializationParser::ConstraintContext * /*ctx*/) override { }

  virtual void enterArith_expr(SerializationParser::Arith_exprContext * /*ctx*/) override { }
  virtual void exitArith_expr(SerializationParser::Arith_exprContext * /*ctx*/) override { }

  virtual void enterArith_unary(SerializationParser::Arith_unaryContext * /*ctx*/) override { }
  virtual void exitArith_unary(SerializationParser::Arith_unaryContext * /*ctx*/) override { }

  virtual void enterArith_nary(SerializationParser::Arith_naryContext * /*ctx*/) override { }
  virtual void exitArith_nary(SerializationParser::Arith_naryContext * /*ctx*/) override { }

  virtual void enterBoolean(SerializationParser::BooleanContext * /*ctx*/) override { }
  virtual void exitBoolean(SerializationParser::BooleanContext * /*ctx*/) override { }

  virtual void enterNumber(SerializationParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(SerializationParser::NumberContext * /*ctx*/) override { }

  virtual void enterReal_variable(SerializationParser::Real_variableContext * /*ctx*/) override { }
  virtual void exitReal_variable(SerializationParser::Real_variableContext * /*ctx*/) override { }

  virtual void enterBool_variable(SerializationParser::Bool_variableContext * /*ctx*/) override { }
  virtual void exitBool_variable(SerializationParser::Bool_variableContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace carlparser
