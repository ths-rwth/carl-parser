
// Generated from /home/travis/build/smtrat/carl-parser/src/carl-parser/Serialization.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "SerializationParser.h"


namespace carlparser {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by SerializationParser.
 */
class  SerializationVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SerializationParser.
   */
    virtual antlrcpp::Any visitStart(SerializationParser::StartContext *context) = 0;

    virtual antlrcpp::Any visitCarl_expr(SerializationParser::Carl_exprContext *context) = 0;

    virtual antlrcpp::Any visitForm_expr(SerializationParser::Form_exprContext *context) = 0;

    virtual antlrcpp::Any visitFormula_nary(SerializationParser::Formula_naryContext *context) = 0;

    virtual antlrcpp::Any visitForm_op_nary(SerializationParser::Form_op_naryContext *context) = 0;

    virtual antlrcpp::Any visitFormula_unary(SerializationParser::Formula_unaryContext *context) = 0;

    virtual antlrcpp::Any visitConstraint(SerializationParser::ConstraintContext *context) = 0;

    virtual antlrcpp::Any visitArith_expr(SerializationParser::Arith_exprContext *context) = 0;

    virtual antlrcpp::Any visitArith_unary(SerializationParser::Arith_unaryContext *context) = 0;

    virtual antlrcpp::Any visitArith_nary(SerializationParser::Arith_naryContext *context) = 0;

    virtual antlrcpp::Any visitBoolean(SerializationParser::BooleanContext *context) = 0;

    virtual antlrcpp::Any visitNumber(SerializationParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitReal_variable(SerializationParser::Real_variableContext *context) = 0;

    virtual antlrcpp::Any visitBool_variable(SerializationParser::Bool_variableContext *context) = 0;


};

}  // namespace carlparser
