//
// Created by hbruintjes on 19/06/17.
//

#pragma once


#include <carl/formula/Formula.h>
#include <carl/core/RationalFunction.h>

#include <boost/variant.hpp>


namespace carlparser {


    enum class ParserReturnType {
        Rational, Variable, Monomial, Term, Polynomial, RationalFunction, Constraint, Formula
    };

    template<typename Pol>
    class typechecker: public boost::static_visitor<ParserReturnType> {
    public:
        ParserReturnType operator()(const typename Pol::CoeffType&) const {
            return ParserReturnType::Rational;
        }
        ParserReturnType  operator()(const carl::Variable&) const {
            return ParserReturnType::Variable;
        }
        ParserReturnType  operator()(const carl::Monomial::Arg&) const {
            return ParserReturnType::Monomial;
        }
        ParserReturnType  operator()(const carl::Term<typename Pol::CoeffType>&) const {
            return ParserReturnType::Term;
        }
        ParserReturnType  operator()(const Pol&) const {
            return ParserReturnType::Polynomial;
        }
        ParserReturnType  operator()(const carl::RationalFunction<Pol>&) const {
            return ParserReturnType::RationalFunction;
        }
        ParserReturnType operator()(const carl::Constraint<Pol>&) const {
            return ParserReturnType::Constraint;
        }
        ParserReturnType  operator()(const carl::Formula<Pol>&) const {
            return ParserReturnType::Formula;
        }
    };


    template<typename Pol>
    using parser_types = boost::variant< typename Pol::CoeffType, carl::Variable, carl::Monomial::Arg,
            carl::Term<typename Pol::CoeffType>, Pol, carl::RationalFunction<Pol>,
    carl::Constraint<Pol>, carl::Formula<Pol> >;

    template<typename Pol>
    inline ParserReturnType check_type(const parser_types<Pol>& t) {
        return boost::apply_visitor(typechecker<Pol>(), t);
    }


	template<typename Pol>
	parser_types<Pol> deserialize(std::string input);
}