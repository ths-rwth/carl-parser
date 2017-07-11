#pragma once

// generated files
#include "carl-parser/SerializationVisitor.h"

#include <carl/core/MultivariatePolynomial.h>
#include <carl/core/RationalFunction.h>

#include <boost/variant.hpp>

namespace carlparser {

	/**
	 * Visitor for the Serialization grammar that will build
	 * up the CARL data.
	 */
	template<typename Pol>
	class ParseTreeVisitor : public SerializationVisitor {
		typedef typename Pol::CoeffType Rational;

		using ArithType = boost::variant<Rational, carl::Variable, carl::Monomial::Arg,
				carl::Term<Rational>, Pol, carl::RationalFunction<Pol> >;

	public:
		antlrcpp::Any visitStart(SerializationParser::StartContext *ctx) override;

		antlrcpp::Any visitCarl_expr(SerializationParser::Carl_exprContext *ctx) override;

		antlrcpp::Any visitForm_expr(SerializationParser::Form_exprContext *ctx) override;

		antlrcpp::Any visitFormula_nary(SerializationParser::Formula_naryContext *ctx) override;

		antlrcpp::Any visitForm_op_nary(SerializationParser::Form_op_naryContext *ctx) override;

		antlrcpp::Any visitFormula_unary(SerializationParser::Formula_unaryContext *ctx) override;

		antlrcpp::Any visitConstraint(SerializationParser::ConstraintContext *ctx) override;

		antlrcpp::Any visitArith_expr(SerializationParser::Arith_exprContext *ctx) override;

		antlrcpp::Any visitArith_nary(SerializationParser::Arith_naryContext *ctx) override;

        antlrcpp::Any visitArith_unary(SerializationParser::Arith_unaryContext *ctx) override;

        antlrcpp::Any visitBoolean(SerializationParser::BooleanContext *ctx) override;

		antlrcpp::Any visitNumber(SerializationParser::NumberContext *ctx) override;

		antlrcpp::Any visitBool_variable(SerializationParser::Bool_variableContext *ctx) override;

		antlrcpp::Any visitReal_variable(SerializationParser::Real_variableContext *ctx) override;

	};

}  // namespace carl
