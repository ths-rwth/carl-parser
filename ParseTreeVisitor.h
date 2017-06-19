#pragma once

#include <carl/io/serialization/SerializationVisitor.h>

namespace carl {

	/**
	 * Visitor for the Serialization grammar that will build
	 * up the CARL data.
	 */
	class ParseTreeVisitor : public SerializationVisitor {
	public:
		antlrcpp::Any visitStart(SerializationParser::StartContext *ctx) override;

		antlrcpp::Any visitCarl_expr(SerializationParser::Carl_exprContext *ctx) override;

		antlrcpp::Any visitForm_expr(SerializationParser::Form_exprContext *ctx) override;

		antlrcpp::Any visitFormula_nary(SerializationParser::Formula_naryContext *ctx) override;

		antlrcpp::Any visitForm_op_nary(SerializationParser::Form_op_naryContext *ctx) override;

		antlrcpp::Any visitFormula_unary(SerializationParser::Formula_unaryContext *ctx) override;

		antlrcpp::Any visitConstraint(SerializationParser::ConstraintContext *ctx) override;

		antlrcpp::Any visitArith_expr(SerializationParser::Arith_exprContext *ctx) override;

		antlrcpp::Any visitArith_nary(carl::SerializationParser::Arith_naryContext *ctx) override;

		antlrcpp::Any visitBoolean(SerializationParser::BooleanContext *ctx) override;

		antlrcpp::Any visitNumber(SerializationParser::NumberContext *ctx) override;

		antlrcpp::Any visitBool_variable(SerializationParser::Bool_variableContext *ctx) override;

		antlrcpp::Any visitReal_variable(SerializationParser::Real_variableContext *ctx) override;

	};

}  // namespace carl
