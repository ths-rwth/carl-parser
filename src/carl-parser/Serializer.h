//
// Created by hbruintjes on 19/06/17.
//

#ifndef CARL_SERIALIZER_H
#define CARL_SERIALIZER_H

#include <string>

#include <carl/core/Variable.h>
#include <carl/core/MultivariatePolynomial.h>
#include <carl/core/RationalFunction.h>
#include <carl/formula/Formula.h>

namespace carlparser {

std::string serialize(Variable const& v) {
	return v.getName();
}

std::string serialize(mpq_class const& rational) {
	return toString(rational);
}

//std::string serialize(cln::RA const& rational);

std::string serialize(Monomial::Arg const& v) {
	if (v->isConstant()) {
		return "0";
	} else if (v->isLinear()) {
		return serialize(v->getSingleVariable());
	}

	std::string res = "(*";
	for(auto const& exp: *v) {
		for(uint i = 0; i < exp.second; ++i) {
			res += ' ' + exp.first.getName();
		}
	}
	res += ")";
	return res;
}

template <typename CoeffType>
std::string serialize(Term<CoeffType> const& t) {
	if (carl::isOne(t.coeff())) {
		return serialize(t.monomial());
	} else {
		std::string res = "(*" + serialize(t.coeff());
		for(auto const& exp: *t.monomial()) {
			for(uint i = 0; i < exp.second; ++i) {
				res += ' ' + exp.first.getName();
			}
		}
		res += ")";
		return res;
	}
}

template <typename CoeffType>
std::string serialize(MultivariatePolynomial<CoeffType> const& poly) {
	if (poly.isConstant()) {
		return serialize(poly.constantPart());
	} else if (poly.nrTerms() == 1) {
		return serialize(*poly.begin());
	} else {
		std::string res = "(+";
		for(auto const& term: poly) {
			res += ' ' + serialize(term);
		}
		res += ")";
		return res;
	}
}

template <typename Poly>
std::string serialize(RationalFunction<Poly> const& rf) {
	return std::string("(/ ") + serialize(rf.nominator()) + ' ' + serialize(rf.denominator()) + ")";
}

template <typename Poly>
std::string serialize(Constraint<Poly> const& c) {
	return std::string("(") + relationToString(c.relation()) + ' ' + serialize(c.lhs()) + "0)";
}

template <typename Poly>
std::string serialize(Formula<Poly> const& f) {
	switch(f.type()) {
		case ITE:
			return std::string("(ite ") + serialize(f.subformulas()[0]) +
					' ' + serialize(f.subformulas()[1]) +
					' ' + serialize(f.subformulas()[2])+ ")";
		case FormulaType::TRUE:
			return "true";
		case FormulaType::FALSE:
			return "true";
		case FormulaType::BOOL:
			return f.boolean().getName();
		case FormulaType::NOT:
		case FormulaType::IMPLIES:
		case FormulaType::AND:
		case FormulaType::OR:
		case FormulaType::XOR:
		case FormulaType::IFF: {
			std::string res = "(" + formulaTypeToString(f.type());
			for (auto const &sub: f) {
				res += ' ' + serialize(sub);
			}
			res += ')';
			return res;
		}
		case FormulaType::CONSTRAINT:
			return serialize(f.constraint());
		default:
			throw std::runtime_error("Unsupported formula type to serialize");
	}
}
}


#endif //CARL_SERIALIZER_H
