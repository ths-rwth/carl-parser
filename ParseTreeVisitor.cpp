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

	class make_constraint: public boost::static_visitor<Constraint<Poly>> {
		Relation m_rel;
	public:
		make_constraint(Relation rel) : m_rel(rel) {}

		template<typename T>
		Constraint<Poly> operator()(T const& expr) const {
			return Constraint<Poly>(Poly(expr), m_rel);
		}

		Constraint<Poly> operator()(Poly const& expr) const {
			return Constraint<Poly>(expr, m_rel);
		}

		Constraint<Poly> operator()(RationalFunction<Poly> const& expr) const {
			throw std::runtime_error("Cannot compare rational function");
		}
	};

	class to_antlr_any: public boost::static_visitor<antlrcpp::Any> {
	public:
		template<typename T>
		antlrcpp::Any operator()(T const& expr) const {
			return expr;
		}
	};

	antlrcpp::Any ParseTreeVisitor::visitStart(SerializationParser::StartContext *ctx) {
		return ctx->carl_expr()->accept(this);
	}

	antlrcpp::Any ParseTreeVisitor::visitCarl_expr(SerializationParser::Carl_exprContext *ctx) {
		if (ctx->formula_nary()) {
			return ctx->formula_nary()->accept(this);
		} else if (ctx->formula_unary()) {
			return ctx->formula_unary()->accept(this);
		} else if (ctx->constraint()) {
			return ctx->constraint()->accept(this);
		} else if (ctx->arith_nary()) {
			return boost::apply_visitor(to_antlr_any(), ctx->arith_nary()->accept(this).as<ArithType>());
		} else if (ctx->real_variable()) {
			return boost::apply_visitor(to_antlr_any(), ctx->real_variable()->accept(this).as<ArithType>());
		} else if (ctx->number()) {
			return boost::apply_visitor(to_antlr_any(), ctx->number()->accept(this).as<ArithType>());
		} else if (ctx->boolean()) {
			return ctx->boolean()->accept(this).as<Formula<Poly>>();
		}
		throw std::runtime_error("Unknown formula rule");
	}

	antlrcpp::Any ParseTreeVisitor::visitForm_expr(SerializationParser::Form_exprContext *ctx) {
		if (ctx->formula_nary()) {
			return ctx->formula_nary()->accept(this);
		} else if (ctx->formula_unary()) {
			return ctx->formula_unary()->accept(this);
		} else if (ctx->constraint()) {
			return Formula<Poly>(ctx->constraint()->accept(this).as<Constraint<Poly>>());
		} else if (ctx->boolean()) {
			return ctx->boolean()->accept(this);
		} else if (ctx->bool_variable()) {
			return ctx->bool_variable()->accept(this);
		}
		throw std::runtime_error("Unknown formula rule");
	}

	antlrcpp::Any ParseTreeVisitor::visitFormula_nary(SerializationParser::Formula_naryContext *ctx) {
		FormulaType type = ctx->form_op_nary()->accept(this).as<FormulaType>();
		if (type == FormulaType::ITE) {
			if (ctx->form_expr().size() != 3) {
				throw std::runtime_error("ITE formula requires 3 subformulae");
			}
			return Formula<Poly>(type, ctx->form_expr(0)->accept(this).as<Formula<Poly>>(),
			               ctx->form_expr(1)->accept(this).as<Formula<Poly>>(),
			               ctx->form_expr(2)->accept(this).as<Formula<Poly>>());
		} else {
			if (ctx->form_expr().size() < 2) {
				if (type != FormulaType::AND && type != FormulaType::OR) {
					throw std::runtime_error("formula requires >1 subformulae");
				}
				return ctx->form_expr(0)->accept(this).as<Formula<Poly>>();
			}
			size_t index = 0;
			Formula<Poly> form = ctx->form_expr(index)->accept(this).as<Formula<Poly>>();
			++index;
			for(; index < ctx->form_expr().size(); ++index) {
				form = Formula<Poly>(type, form, ctx->form_expr(index)->accept(this).as<Formula<Poly>>());
			}
			return form;
		}
	}

	antlrcpp::Any ParseTreeVisitor::visitForm_op_nary(SerializationParser::Form_op_naryContext *ctx) {
		auto const& text = ctx->getText();
		if (text == "and") {
			return FormulaType::AND;
		} else if (text == "or") {
			return FormulaType::OR;
		} else if (text == "=") {
			return FormulaType::IFF;
		} else if (text == "xor") {
			return FormulaType::XOR;
		} else if (text == "=>") {
			return FormulaType::IMPLIES;
		} else if (text == "ite") {
			return FormulaType::ITE;
		}
		throw std::runtime_error("Unknown formula operator");
	}

	antlrcpp::Any ParseTreeVisitor::visitFormula_unary(SerializationParser::Formula_unaryContext *ctx) {
		auto formula = ctx->form_expr()->accept(this).as<Formula<Poly>>();
		return Formula<Poly>(FormulaType::NOT, formula);
	}

	antlrcpp::Any ParseTreeVisitor::visitConstraint(SerializationParser::ConstraintContext *ctx) {
		auto const& text = ctx->token->getText();
		antlrcpp::Any expr = ctx->arith_expr()->accept(this);
		auto arith_expr = expr.as<ArithType>();
		if (text == "=") {
			return boost::apply_visitor(make_constraint(Relation::EQ), arith_expr);
		} else if (text == "!=") {
			return boost::apply_visitor(make_constraint(Relation::NEQ), arith_expr);
		} else if (text == "<") {
			return boost::apply_visitor(make_constraint(Relation::LESS), arith_expr);
		} else if (text == "<=") {
			return boost::apply_visitor(make_constraint(Relation::LEQ), arith_expr);
		} else if (text == ">") {
			return boost::apply_visitor(make_constraint(Relation::GREATER), arith_expr);
		} else if (text == ">=") {
			return boost::apply_visitor(make_constraint(Relation::GEQ), arith_expr);
		} else {
			throw std::runtime_error("Unknown constraint operator");
		}
	}

	antlrcpp::Any ParseTreeVisitor::visitArith_expr(SerializationParser::Arith_exprContext *ctx) {
		if (ctx->arith_nary()) {
			return ctx->arith_nary()->accept(this);
		} else if (ctx->number()) {
			return ctx->number()->accept(this);
		} else if (ctx->real_variable()) {
			return ctx->real_variable()->accept(this);
		}
		throw std::runtime_error("Unknown arithmetic rule");
	}

	antlrcpp::Any ParseTreeVisitor::visitArith_nary(carl::SerializationParser::Arith_naryContext *ctx) {
		auto const& text = ctx->token->getText();
		auto baseExpr = ctx->arith_expr(0)->accept(this).as<ArithType>();
		if (text == "+") {
			for(size_t i = 1; i < ctx->arith_expr().size(); ++i) {
				auto nextExpr = ctx->arith_expr(i)->accept(this).as<ArithType>();
				baseExpr = boost::apply_visitor(perform_addition(), baseExpr, nextExpr);
			}
		} else if (text == "-") {
			for(size_t i = 1; i < ctx->arith_expr().size(); ++i) {
				auto nextExpr = ctx->arith_expr(i)->accept(this);
				baseExpr = boost::apply_visitor(perform_subtraction(), baseExpr, nextExpr.as<ArithType>());
			}
		} else if (text == "*") {
			for(size_t i = 1; i < ctx->arith_expr().size(); ++i) {
				auto nextExpr = ctx->arith_expr(i)->accept(this);
				baseExpr = boost::apply_visitor(perform_multiplication(), baseExpr, nextExpr.as<ArithType>());
			}
		} else if (text == "/") {
			for(size_t i = 1; i < ctx->arith_expr().size(); ++i) {
				auto nextExpr = ctx->arith_expr(i)->accept(this);
				baseExpr = boost::apply_visitor(perform_division(), baseExpr, nextExpr.as<ArithType>());
			}
		} else {
			throw std::runtime_error("Unknown arithmetic operator");
		}
		return baseExpr;
	}

	antlrcpp::Any ParseTreeVisitor::visitBoolean(SerializationParser::BooleanContext *ctx) {
		if (ctx->TRUE()) {
			return carl::Formula<Poly>(FormulaType::TRUE);
		} else if (ctx->FALSE()) {
			return carl::Formula<Poly>(FormulaType::FALSE);
		}
		throw std::runtime_error("Unknown boolean");
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

	antlrcpp::Any ParseTreeVisitor::visitBool_variable(SerializationParser::Bool_variableContext *ctx) {
		std::string name = ctx->SYMBOL()->getSymbol()->getText();
		//try and generate new variable from pool
		Variable newVar;
		auto &pool = VariablePool::getInstance();
		Variable res = pool.findVariableWithName(name);
		if (res != Variable::NO_VARIABLE) {
			newVar = res;
			if (newVar.getType() != VariableType::VT_BOOL) {
				throw std::runtime_error("Expected Boolean variable");
			}
		} else {
			newVar = freshBooleanVariable(name);
		}

		return Formula<Poly>(newVar);
	}

	antlrcpp::Any ParseTreeVisitor::visitReal_variable(SerializationParser::Real_variableContext *ctx) {
		std::string name = ctx->SYMBOL()->getSymbol()->getText();
		//try and generate new variable from pool
		Variable newVar;
		auto &pool = VariablePool::getInstance();
		Variable res = pool.findVariableWithName(name);
		if (res != Variable::NO_VARIABLE) {
			newVar = res;
			if (newVar.getType() != VariableType::VT_REAL) {
				throw std::runtime_error("Expected real variable");
			}
		} else {
			newVar = freshRealVariable(name);
		}

		return ArithType(newVar);
	}
}
