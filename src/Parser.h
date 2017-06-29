//
// Created by hbruintjes on 19/06/17.
//

#pragma once

#include "SerializationLexer.h"
#include "SerializationParser.h"
#include "SerializationVisitor.h"
#include "ParseTreeVisitor.h"
#include <carl/formula/Formula.h>

#include <antlr4-runtime.h>
#include <boost/variant.hpp>

using namespace antlr4;

namespace carlparser {
	class ErrorListener: public antlr4::ANTLRErrorListener {
	public:
		void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
		                 size_t charPositionInLine, const std::string &msg, std::exception_ptr e) override {
			throw std::runtime_error(std::string("Parser error: ") + msg);
		}

		void reportAmbiguity(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, size_t startIndex,
		                     size_t stopIndex, bool exact, const antlrcpp::BitSet &ambigAlts,
		                     antlr4::atn::ATNConfigSet *configs) override {
			throw std::runtime_error("Parser error");
		}

		void reportAttemptingFullContext(Parser *recognizer, const dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
		                                 const antlrcpp::BitSet &conflictingAlts,
		                                 antlr4::atn::ATNConfigSet *configs) override {
			throw std::runtime_error("Parser error");
		}

		void reportContextSensitivity(Parser *recognizer, const dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
		                              size_t prediction, atn::ATNConfigSet *configs) override {
			throw std::runtime_error("Parser error");
		}
	};

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
	parser_types<Pol> deserialize(std::string input) {
		ANTLRInputStream input_stream(input);
		SerializationLexer lexer(&input_stream);
		CommonTokenStream tokens(&lexer);
		SerializationParser parser(&tokens);
		ParseTreeVisitor<Pol> visitor;

		auto errListener = ErrorListener();
		lexer.removeErrorListeners();
		lexer.addErrorListener(&errListener);
		parser.removeErrorListeners();
		parser.addErrorListener(&errListener);

		tree::ParseTree* tree = parser.start();
		antlrcpp::Any resultData = tree->accept(&visitor);

		if (resultData.is<carl::Formula<Pol>>()) {
			return resultData.as<carl::Formula<Pol>>();
		} else if (resultData.is<carl::Constraint<Pol>>()) {
			return resultData.as<carl::Constraint<Pol>>();
		} else if (resultData.is<carl::RationalFunction<Pol>>()) {
			return resultData.as<carl::RationalFunction<Pol>>();
		} else if (resultData.is<Pol>()) {
			return resultData.as<Pol>();
		} else if (resultData.is<carl::Term<typename Pol::CoeffType>>()) {
			return resultData.as<carl::Term<typename Pol::CoeffType>>();
		} else if (resultData.is<carl::Monomial::Arg>()) {
			return resultData.as<carl::Monomial::Arg>();
		} else if (resultData.is<typename Pol::CoeffType>()) {
			return resultData.as<typename Pol::CoeffType>();
		} else if (resultData.is<carl::Variable>()) {
			return resultData.as<carl::Variable>();
		} else {
			throw std::runtime_error("Unexpected parser result");
		}
	}
}