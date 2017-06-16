#include "ParseTreeVisitor.h"

#include <carl/core/Monomial.h>
#include <carl/core/VariablePool.h>
#include <carl/core/Term.h>
#include <carl/core/MultivariatePolynomial.h>
#include <carl/formula/Formula.h>

#include "carl/core/Variable.h"
#include "carl/core/Monomial.h"
#include "carl/core/Term.h"
#include "carl/core/RationalFunction.h"
#include "carl/formula/Formula.h"

#include <boost/variant.hpp>
#include <string>

namespace carl {
	typedef mpq_class Rational;
	typedef Rational CoeffType;
	typedef MultivariatePolynomial<CoeffType> Poly;

	template<typename Pol>
	using TArithType = boost::variant< typename Pol::CoeffType, carl::Variable, carl::Monomial::Arg,
			carl::Term<typename Pol::CoeffType>, Pol, RationalFunction<Pol> >;

	typedef TArithType<Poly> ArithType;


	class perform_addition: public boost::static_visitor<ArithType > {
	public:
		template<typename T, typename U>
		ArithType  operator()(const T& lhs, const U& rhs) const {
			return Poly(lhs) + Poly(rhs);
		}

		ArithType  operator()(const CoeffType& lhs, const CoeffType& rhs) const {
			return (lhs) + (rhs);
		}

		ArithType  operator()(const RationalFunction<Poly>& lhs, const Monomial::Arg& rhs) const {
			return (lhs) + Poly(rhs);
		}

		ArithType  operator()(const RationalFunction<Poly>& lhs, const Term<CoeffType>& rhs) const {
			return (lhs) + Poly(rhs);
		}

		template<typename T>
		ArithType operator()(const RationalFunction<Poly>& lhs, const T& rhs) const {
			return (lhs) + (rhs);
		}

		template<typename T>
		ArithType operator()(const T& lhs, const RationalFunction<Poly>& rhs) const {
			return (rhs) + Poly(lhs);
		}

		ArithType  operator()(const RationalFunction<Poly>& lhs, const RationalFunction<Poly>& rhs) const {
			return (lhs) + (rhs);
		}
	};

	class perform_subtraction: public boost::static_visitor<ArithType > {
	public:
		template<typename T, typename U>
		ArithType  operator()(const T& lhs, const U& rhs) const {
			return Poly(lhs) - Poly(rhs);
		}

		ArithType  operator()(const CoeffType& lhs, const CoeffType& rhs) const {
			return (lhs) - (rhs);
		}

		ArithType  operator()(const RationalFunction<Poly>& lhs, const Monomial::Arg& rhs) const {
			return (lhs) - Poly(rhs);
		}

		ArithType  operator()(const RationalFunction<Poly>& lhs, const Term<CoeffType>& rhs) const {
			return (lhs) - Poly(rhs);
		}

		template<typename T>
		ArithType operator()(const RationalFunction<Poly>& lhs, const T& rhs) const {
			return (lhs) - (rhs);
		}

		template<typename T>
		ArithType operator()(const T& lhs, const RationalFunction<Poly>& rhs) const {
			return (rhs) - Poly(lhs);
		}

		ArithType operator()(const RationalFunction<Poly>& lhs, const RationalFunction<Poly>& rhs) const {
			return (lhs) - (rhs);
		}
	};

	class perform_multiplication: public boost::static_visitor<ArithType > {
	public:
		template<typename T, typename U>
		ArithType operator()(const T& lhs, const U& rhs) const {
			return lhs * rhs;
		}

		template<typename T>
		ArithType operator()(const T& lhs, const RationalFunction<Poly>& rhs) const {
			return rhs * lhs;
		}

		ArithType  operator()(const RationalFunction<Poly>& lhs, const Monomial::Arg& rhs) const {
			return (lhs) * Poly(rhs);
		}

		ArithType  operator()(const RationalFunction<Poly>& lhs, const Term<CoeffType>& rhs) const {
			return (lhs) * Poly(rhs);
		}

		ArithType  operator()(const Monomial::Arg& lhs, const RationalFunction<Poly>& rhs) const {
			return (rhs) * Poly(lhs);
		}

		ArithType  operator()(const Term<CoeffType>& lhs, const RationalFunction<Poly>& rhs) const {
			return (rhs) * Poly(lhs);
		}
	};

	class perform_division: public boost::static_visitor<ArithType > {
	public:
		ArithType  operator()(const RationalFunction<Poly>& lhs, const CoeffType& rhs) const {
			return lhs / rhs;
		}

		template<typename T>
		ArithType operator()(const RationalFunction<Poly>& lhs, const T& rhs) const {
			return lhs / rhs;
		}

		ArithType  operator()(const RationalFunction<Poly>& lhs, const Monomial::Arg& rhs) const {
			return lhs / Poly(rhs);
		}

		ArithType  operator()(const RationalFunction<Poly>& lhs, const Term<CoeffType>& rhs) const {
			return lhs / Poly(rhs);
		}

		ArithType  operator()(const RationalFunction<Poly>& lhs, const RationalFunction<Poly>& rhs) const {
			return lhs / rhs;
		}

		template<typename T>
		ArithType operator()(const T& lhs, const CoeffType& coeff) const {
			return lhs * reciprocal(coeff);
		}

		template<typename T>
		ArithType operator()(const T& lhs, const RationalFunction<Poly>& rhs) const {
			// TODO: Not extremely efficient probably
			return  RationalFunction<Poly>(rhs.denominator(), rhs.nominator()) * Poly(lhs);
		}

		template<typename T, typename U>
		ArithType operator()(const T& lhs, const U& rhs) const {
			return RationalFunction<Poly>(Poly(lhs), Poly(rhs));
		}
	};

	antlrcpp::Any ParseTreeVisitor::visitStart(SerializationParser::StartContext *ctx) {
		return ctx->form_expr()->accept(this);
	}

	antlrcpp::Any ParseTreeVisitor::visitForm_expr(SerializationParser::Form_exprContext *ctx) {
		if (ctx->formula_nary()) {
			return ctx->formula_nary()->accept(this);
		} else if (ctx->formula_unary()) {
			return ctx->formula_unary()->accept(this);
		} else if (ctx->constraint()) {
			return ctx->constraint()->accept(this);
		} else if (ctx->arith_expr()) {
			return ctx->arith_expr()->accept(this);
		}
		throw std::runtime_error("Unknown formula rule");
	}

	antlrcpp::Any ParseTreeVisitor::visitFormula_nary(SerializationParser::Formula_naryContext *ctx) {
		return ParseTreeVisitor::visitChildren(ctx);
	}

	antlrcpp::Any ParseTreeVisitor::visitForm_op_nary(SerializationParser::Form_op_naryContext *ctx) {
		return ParseTreeVisitor::visitChildren(ctx);
	}

	antlrcpp::Any ParseTreeVisitor::visitFormula_unary(SerializationParser::Formula_unaryContext *ctx) {
		return ParseTreeVisitor::visitChildren(ctx);
	}

	antlrcpp::Any ParseTreeVisitor::visitConstraint(SerializationParser::ConstraintContext *ctx) {
		return ParseTreeVisitor::visitChildren(ctx);
	}

	antlrcpp::Any ParseTreeVisitor::visitRelation(SerializationParser::RelationContext *ctx) {
		return ParseTreeVisitor::visitChildren(ctx);
	}

	antlrcpp::Any ParseTreeVisitor::visitArith_expr(SerializationParser::Arith_exprContext *ctx) {
		if (ctx->arith_nary()) {
			return ctx->arith_nary()->accept(this);
		} else if (ctx->atom()) {
			return ctx->atom()->accept(this);
		}
		throw std::runtime_error("Unknown arithmetic rule");
	}

	antlrcpp::Any ParseTreeVisitor::visitArith_nary(carl::SerializationParser::Arith_naryContext *ctx) {
		auto const& text = ctx->token->getText();
		auto baseExpr = ctx->arith_expr(0)->accept(this);
		if (text == "+") {
			for(size_t i = 1; i < ctx->arith_expr().size(); ++i) {
				auto nextExpr = ctx->arith_expr(0)->accept(this);
				baseExpr = boost::apply_visitor(perform_addition(), baseExpr.as<ArithType>(), nextExpr.as<ArithType>());
			}
		} else if (text == "-") {
			for(size_t i = 1; i < ctx->arith_expr().size(); ++i) {
				auto nextExpr = ctx->arith_expr(0)->accept(this);
				baseExpr = boost::apply_visitor(perform_subtraction(), baseExpr.as<ArithType>(), nextExpr.as<ArithType>());
			}
		} else if (text == "*") {
			for(size_t i = 1; i < ctx->arith_expr().size(); ++i) {
				auto nextExpr = ctx->arith_expr(0)->accept(this);
				baseExpr = boost::apply_visitor(perform_multiplication(), baseExpr.as<ArithType>(), nextExpr.as<ArithType>());
			}
		} else if (text == "/") {
			for(size_t i = 1; i < ctx->arith_expr().size(); ++i) {
				auto nextExpr = ctx->arith_expr(0)->accept(this);
				baseExpr = boost::apply_visitor(perform_division(), baseExpr.as<ArithType>(), nextExpr.as<ArithType>());
			}
		} else {
			throw std::runtime_error("Unknown arithmetic operator");
		}
		return baseExpr;
	}

	antlrcpp::Any ParseTreeVisitor::visitAtom(SerializationParser::AtomContext *ctx) {
		if (ctx->number()) {
			return ctx->number()->accept(this);
		} else if (ctx->variable()) {
			return ctx->variable()->accept(this);
		} else if (ctx->TRUE()) {
			return carl::Formula<carl::MultivariatePolynomial<Rational>>(FormulaType::TRUE);
		} else if (ctx->FALSE()) {
			return carl::Formula<carl::MultivariatePolynomial<Rational>>(FormulaType::FALSE);
		}
		throw std::runtime_error("Unknown atom");
	}

	antlrcpp::Any ParseTreeVisitor::visitNumber(SerializationParser::NumberContext *ctx) {
		Rational tmp;
		if (ctx->NUMERAL()) {
			bool suc = carl::try_parse<Rational>(ctx->NUMERAL()->getText(), tmp);
			if(!suc) {
				throw std::invalid_argument("Cannot translate " + ctx->NUMERAL()->getText() + " into a rational.");
			}
			return ArithType(tmp);
		} else if (ctx->DECIMAL()) {
			bool suc = carl::try_parse<Rational>(ctx->DECIMAL()->getText(), tmp);
			if(!suc) {
				throw std::invalid_argument("Cannot translate " + ctx->DECIMAL()->getText() + " into a rational.");
			}
			return ArithType(tmp);
		} else if (ctx->HEXADECIMAL()) {
			long v = std::stol(ctx->HEXADECIMAL()->getText().substr(2), nullptr, 16);
			tmp = v;
			return ArithType(tmp);
		} else if (ctx->BINARY()) {
			long v = std::stol(ctx->BINARY()->getText().substr(2), nullptr, 2);
			tmp = v;
			return ArithType(tmp);
		}
		throw std::runtime_error("Unknown number");
	}

	antlrcpp::Any ParseTreeVisitor::visitVariable(SerializationParser::VariableContext *ctx) {
		std::string name = ctx->SYMBOL()->getSymbol()->getText();
		//try and generate new variable from pool
		Variable newVar;
		auto &pool = VariablePool::getInstance();
		Variable res = pool.findVariableWithName(name);
		if (res != Variable::NO_VARIABLE) {
			newVar = res;
		} else {
			newVar = freshRealVariable(name);
		}

		return ArithType(newVar);
	}
}
