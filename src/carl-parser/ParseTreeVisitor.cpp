#include "ParseTreeVisitor.h"

#include <carl/formula/Formula.h>

using namespace carl;

namespace carlparser {

	template<typename Res, typename Pol>
	class perform_addition: public boost::static_visitor<Res> {
	public:
		template<typename T, typename U>
		Res operator()(const T& lhs, const U& rhs) const {
			return Pol(lhs) + Pol(rhs);
		}

		Res operator()(const typename Pol::CoeffType& lhs, const typename Pol::CoeffType& rhs) const {
			return (lhs) + (rhs);
		}

		Res operator()(const RationalFunction<Pol>& lhs, const Monomial::Arg& rhs) const {
			return (lhs) + Pol(rhs);
		}

		Res operator()(const RationalFunction<Pol>& lhs, const Term<typename Pol::CoeffType>& rhs) const {
			return (lhs) + Pol(rhs);
		}

		template<typename T>
		Res operator()(const RationalFunction<Pol>& lhs, const T& rhs) const {
			return (lhs) + (rhs);
		}

		template<typename T>
		Res operator()(const T& lhs, const RationalFunction<Pol>& rhs) const {
			return (rhs) + Pol(lhs);
		}

		Res operator()(const RationalFunction<Pol>& lhs, const RationalFunction<Pol>& rhs) const {
			return (lhs) + (rhs);
		}
	};

	template<typename Res, typename Pol>
	class perform_subtraction: public boost::static_visitor<Res> {
	public:
		template<typename T, typename U>
		Res operator()(const T& lhs, const U& rhs) const {
			return Pol(lhs) - Pol(rhs);
		}

		Res operator()(const typename Pol::CoeffType& lhs, const typename Pol::CoeffType& rhs) const {
			return (lhs) - (rhs);
		}

		Res operator()(const RationalFunction<Pol>& lhs, const Monomial::Arg& rhs) const {
			return (lhs) - Pol(rhs);
		}

		Res operator()(const RationalFunction<Pol>& lhs, const Term<typename Pol::CoeffType>& rhs) const {
			return (lhs) - Pol(rhs);
		}

		template<typename T>
		Res operator()(const RationalFunction<Pol>& lhs, const T& rhs) const {
			return (lhs) - (rhs);
		}

		template<typename T>
		Res operator()(const T& lhs, const RationalFunction<Pol>& rhs) const {
			return (rhs) - Pol(lhs);
		}

		Res operator()(const RationalFunction<Pol>& lhs, const RationalFunction<Pol>& rhs) const {
			return (lhs) - (rhs);
		}
	};

	template<typename Res, typename Pol>
	class perform_unary_subtraction: public boost::static_visitor<Res> {
	public:
		template<typename T>
		Res operator()(const T& lhs) const {
			return -lhs;
		}

		Res operator()(const Monomial::Arg& lhs) const {
			return -Pol(lhs);
		}

		Res operator()(const Variable& lhs) const {
			return -Pol(lhs);
		}
	};


	template<typename Res, typename Pol>
	class perform_multiplication: public boost::static_visitor<Res> {
	public:
		template<typename T, typename U>
		Res operator()(const T& lhs, const U& rhs) const {
			return lhs * rhs;
		}

		template<typename T>
		Res operator()(const T& lhs, const RationalFunction<Pol>& rhs) const {
			return rhs * lhs;
		}

		Res operator()(const RationalFunction<Pol>& lhs, const Monomial::Arg& rhs) const {
			return (lhs) * Pol(rhs);
		}

		Res operator()(const RationalFunction<Pol>& lhs, const Term<typename Pol::CoeffType>& rhs) const {
			return (lhs) * Pol(rhs);
		}

		Res operator()(const Monomial::Arg& lhs, const RationalFunction<Pol>& rhs) const {
			return (rhs) * Pol(lhs);
		}

		Res operator()(const Term<typename Pol::CoeffType>& lhs, const RationalFunction<Pol>& rhs) const {
			return (rhs) * Pol(lhs);
		}
	};

	template<typename Res, typename Pol>
	class perform_division: public boost::static_visitor<Res> {
	public:
		Res operator()(const RationalFunction<Pol>& lhs, const typename Pol::CoeffType& rhs) const {
			return lhs / rhs;
		}

		template<typename T>
		Res operator()(const RationalFunction<Pol>& lhs, const T& rhs) const {
			return lhs / rhs;
		}

		Res operator()(const RationalFunction<Pol>& lhs, const Monomial::Arg& rhs) const {
			return lhs / Pol(rhs);
		}

		Res operator()(const RationalFunction<Pol>& lhs, const Term<typename Pol::CoeffType>& rhs) const {
			return lhs / Pol(rhs);
		}

		Res operator()(const RationalFunction<Pol>& lhs, const RationalFunction<Pol>& rhs) const {
			return lhs / rhs;
		}

		template<typename T>
		Res operator()(const T& lhs, const typename Pol::CoeffType& coeff) const {
			return lhs * reciprocal(coeff);
		}

		template<typename T>
		Res operator()(const T& lhs, const RationalFunction<Pol>& rhs) const {
			// TODO: Not extremely efficient probably
			return  RationalFunction<Pol>(rhs.denominator(), rhs.nominator()) * Pol(lhs);
		}

		template<typename T, typename U>
		Res operator()(const T& lhs, const U& rhs) const {
			return RationalFunction<Pol>(Pol(lhs), Pol(rhs));
		}
	};

	template<typename Pol>
	class make_constraint: public boost::static_visitor<Constraint<Pol>> {
		Relation m_rel;
	public:
		make_constraint(Relation rel) : m_rel(rel) {}

		template<typename T>
		Constraint<Pol> operator()(T const& expr) const {
			return Constraint<Pol>(Pol(expr), m_rel);
		}

		Constraint<Pol> operator()(Pol const& expr) const {
			return Constraint<Pol>(expr, m_rel);
		}

		Constraint<Pol> operator()(RationalFunction<Pol> const& expr) const {
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

	template<typename Pol>
	antlrcpp::Any ParseTreeVisitor<Pol>::visitStart(SerializationParser::StartContext *ctx) {
		return ctx->carl_expr()->accept(this);
	}

	template<typename Pol>
	antlrcpp::Any ParseTreeVisitor<Pol>::visitCarl_expr(SerializationParser::Carl_exprContext *ctx) {
		if (ctx->formula_nary()) {
			return ctx->formula_nary()->accept(this);
		} else if (ctx->formula_unary()) {
			return ctx->formula_unary()->accept(this);
		} else if (ctx->constraint()) {
			return ctx->constraint()->accept(this);
		} else if (ctx->arith_nary()) {
			return boost::apply_visitor(to_antlr_any(), ctx->arith_nary()->accept(this).template as<ArithType>());
		} else if (ctx->arith_unary()) {
            return boost::apply_visitor(to_antlr_any(), ctx->arith_unary()->accept(this).template as<ArithType>());
        } else if (ctx->real_variable()) {
			return boost::apply_visitor(to_antlr_any(), ctx->real_variable()->accept(this).template as<ArithType>());
		} else if (ctx->number()) {
			return boost::apply_visitor(to_antlr_any(), ctx->number()->accept(this).template as<ArithType>());
		} else if (ctx->boolean()) {
			return ctx->boolean()->accept(this).template as<Formula<Pol>>();
		}
		throw std::runtime_error("Unknown formula rule");
	}

	template<typename Pol>
	antlrcpp::Any ParseTreeVisitor<Pol>::visitForm_expr(SerializationParser::Form_exprContext *ctx) {
		if (ctx->formula_nary()) {
			return ctx->formula_nary()->accept(this);
		} else if (ctx->formula_unary()) {
			return ctx->formula_unary()->accept(this);
		} else if (ctx->constraint()) {
			return Formula<Pol>(ctx->constraint()->accept(this).template as<Constraint<Pol>>());
		} else if (ctx->boolean()) {
			return ctx->boolean()->accept(this);
		} else if (ctx->bool_variable()) {
			return ctx->bool_variable()->accept(this);
		}
		throw std::runtime_error("Unknown formula rule");
	}

	template<typename Pol>
	antlrcpp::Any ParseTreeVisitor<Pol>::visitFormula_nary(SerializationParser::Formula_naryContext *ctx) {
		FormulaType type = ctx->form_op_nary()->accept(this).template as<FormulaType>();
		if (type == FormulaType::ITE) {
			if (ctx->form_expr().size() != 3) {
				throw std::runtime_error("ITE formula requires 3 subformulae");
			}
			return Formula<Pol>(type, ctx->form_expr(0)->accept(this).template as<Formula<Pol>>(),
			               ctx->form_expr(1)->accept(this).template as<Formula<Pol>>(),
			               ctx->form_expr(2)->accept(this).template as<Formula<Pol>>());
		} else {
			if (ctx->form_expr().size() < 2) {
				if (type != FormulaType::AND && type != FormulaType::OR) {
					throw std::runtime_error("formula requires >1 subformulae");
				}
				return ctx->form_expr(0)->accept(this).template as<Formula<Pol>>();
			}
			size_t index = 0;
			Formula<Pol> form = ctx->form_expr(index)->accept(this).template as<Formula<Pol>>();
			++index;
			for(; index < ctx->form_expr().size(); ++index) {
				form = Formula<Pol>(type, form, ctx->form_expr(index)->accept(this).template as<Formula<Pol>>());
			}
			return form;
		}
	}

	template<typename Pol>
	antlrcpp::Any ParseTreeVisitor<Pol>::visitForm_op_nary(SerializationParser::Form_op_naryContext *ctx) {
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

	template<typename Pol>
	antlrcpp::Any ParseTreeVisitor<Pol>::visitFormula_unary(SerializationParser::Formula_unaryContext *ctx) {
		auto formula = ctx->form_expr()->accept(this).template as<Formula<Pol>>();
		return Formula<Pol>(FormulaType::NOT, formula);
	}

	template<typename Pol>
	antlrcpp::Any ParseTreeVisitor<Pol>::visitConstraint(SerializationParser::ConstraintContext *ctx) {
		auto const& text = ctx->token->getText();
	    auto lhs = ctx->arith_expr(0)->accept(this).template as<ArithType>();
        auto rhs = ctx->arith_expr(1)->accept(this).template as<ArithType>();
		auto arith_expr = boost::apply_visitor(perform_subtraction<ArithType, Pol>(), lhs, rhs);
		if (text == "=") {
			return boost::apply_visitor(make_constraint<Pol>(Relation::EQ), arith_expr);
		} else if (text == "!=") {
			return boost::apply_visitor(make_constraint<Pol>(Relation::NEQ), arith_expr);
		} else if (text == "<") {
			return boost::apply_visitor(make_constraint<Pol>(Relation::LESS), arith_expr);
		} else if (text == "<=") {
			return boost::apply_visitor(make_constraint<Pol>(Relation::LEQ), arith_expr);
		} else if (text == ">") {
			return boost::apply_visitor(make_constraint<Pol>(Relation::GREATER), arith_expr);
		} else if (text == ">=") {
			return boost::apply_visitor(make_constraint<Pol>(Relation::GEQ), arith_expr);
		} else {
			throw std::runtime_error("Unknown constraint operator");
		}
	}

	template<typename Pol>
	antlrcpp::Any ParseTreeVisitor<Pol>::visitArith_expr(SerializationParser::Arith_exprContext *ctx) {
		if (ctx->arith_nary()) {
			return ctx->arith_nary()->accept(this);
		} else if (ctx->arith_unary()) {
            return ctx->arith_unary()->accept(this);
        } else if (ctx->number()) {
			return ctx->number()->accept(this);
		} else if (ctx->real_variable()) {
			return ctx->real_variable()->accept(this);
		}
		throw std::runtime_error("Unknown arithmetic rule");
	}

	template<typename Pol>
	antlrcpp::Any ParseTreeVisitor<Pol>::visitArith_nary(SerializationParser::Arith_naryContext *ctx) {
		auto const& text = ctx->token->getText();
		auto baseExpr = ctx->arith_expr(0)->accept(this).template as<ArithType>();
		if (text == "+") {
			for(size_t i = 1; i < ctx->arith_expr().size(); ++i) {
				auto nextExpr = ctx->arith_expr(i)->accept(this).template as<ArithType>();
				baseExpr = boost::apply_visitor(perform_addition<ArithType, Pol>(), baseExpr, nextExpr);
			}
		} else if (text == "-") {
            for(size_t i = 1; i < ctx->arith_expr().size(); ++i) {
				auto nextExpr = ctx->arith_expr(i)->accept(this);
				baseExpr = boost::apply_visitor(perform_subtraction<ArithType, Pol>(), baseExpr, nextExpr.template as<ArithType>());
			}
		} else if (text == "*") {
			for(size_t i = 1; i < ctx->arith_expr().size(); ++i) {
				auto nextExpr = ctx->arith_expr(i)->accept(this);
				baseExpr = boost::apply_visitor(perform_multiplication<ArithType, Pol>(), baseExpr, nextExpr.template as<ArithType>());
			}
		} else if (text == "/") {
			for(size_t i = 1; i < ctx->arith_expr().size(); ++i) {
				auto nextExpr = ctx->arith_expr(i)->accept(this);
				baseExpr = boost::apply_visitor(perform_division<ArithType, Pol>(), baseExpr, nextExpr.template as<ArithType>());
			}
		} else {
			throw std::runtime_error("Unknown arithmetic operator");
		}
		return baseExpr;
	}

    template<typename Pol>
    antlrcpp::Any ParseTreeVisitor<Pol>::visitArith_unary(SerializationParser::Arith_unaryContext *ctx) {
        auto const& text = ctx->token->getText();
        auto baseExpr = ctx->arith_expr()->accept(this).template as<ArithType>();
        if (text == "+") {
			// Skip.
        } else if (text == "-") {
            baseExpr = boost::apply_visitor(perform_unary_subtraction<ArithType, Pol>(), baseExpr);
        } else {
            throw std::runtime_error("Unknown arithmetic operator");
        }
        return baseExpr;
    }


    template<typename Pol>
	antlrcpp::Any ParseTreeVisitor<Pol>::visitBoolean(SerializationParser::BooleanContext *ctx) {
		if (ctx->TRUE()) {
			return carl::Formula<Pol>(FormulaType::TRUE);
		} else if (ctx->FALSE()) {
			return carl::Formula<Pol>(FormulaType::FALSE);
		}
		throw std::runtime_error("Unknown boolean");
	}

	template<typename Pol>
	antlrcpp::Any ParseTreeVisitor<Pol>::visitNumber(SerializationParser::NumberContext *ctx) {
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

	template<typename Pol>
	antlrcpp::Any ParseTreeVisitor<Pol>::visitBool_variable(SerializationParser::Bool_variableContext *ctx) {
		std::string name = ctx->SYMBOL()->getSymbol()->getText();
		//try and generate new variable from pool
		Variable newVar;
		auto &pool = VariablePool::getInstance();
		Variable res = pool.findVariableWithName(name);
		if (res != Variable::NO_VARIABLE) {
			newVar = res;
			if (newVar.type() != VariableType::VT_BOOL) {
				throw std::runtime_error("Expected Boolean variable");
			}
		} else {
			newVar = freshBooleanVariable(name);
		}

		return Formula<Pol>(newVar);
	}

	template<typename Pol>
	antlrcpp::Any ParseTreeVisitor<Pol>::visitReal_variable(SerializationParser::Real_variableContext *ctx) {
		std::string name = ctx->SYMBOL()->getSymbol()->getText();
		//try and generate new variable from pool
		Variable newVar;
		auto &pool = VariablePool::getInstance();
		Variable res = pool.findVariableWithName(name);
		if (res != Variable::NO_VARIABLE) {
			newVar = res;
			if (newVar.type() != VariableType::VT_REAL) {
				throw std::runtime_error("Expected real variable");
			}
		} else {
			newVar = freshRealVariable(name);
		}

		return ArithType(newVar);
	}

	template
	class ParseTreeVisitor<MultivariatePolynomial<mpq_class>>;
#ifdef USE_CLN_NUMBERS
	template
	class ParseTreeVisitor<MultivariatePolynomial<cln::cl_RA>>;
#endif
#ifdef USE_MPFR_FLOAT
	template
	class ParseTreeVisitor<MultivariatePolynomial<FLOAT_T<mpfr_t>>>;
#endif
#ifdef USE_Z3_NUMBERS
	template
	class ParseTreeVisitor<MultivariatePolynomial<rational>>;
#endif

}
