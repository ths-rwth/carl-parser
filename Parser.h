//
// Created by hbruintjes on 19/06/17.
//

#pragma once

#include <carl/io/serialization/SerializationLexer.h>
#include <carl/io/serialization/SerializationParser.h>
#include <carl/io/serialization/SerializationVisitor.h>
#include <carl/io/serialization/ParseTreeVisitor.h>
#include <carl/formula/Formula.h>

#include <antlr4-runtime.h>
#include <boost/variant.hpp>

using namespace antlr4;

namespace carl {
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

	template<typename Pol>
	using parser_types = boost::variant< typename Pol::CoeffType, Variable, Monomial::Arg,
			Term<typename Pol::CoeffType>, Pol, RationalFunction<Pol>,
			Constraint<Pol>, Formula<Pol> >;

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

		if (resultData.is<Formula<Pol>>()) {
			return resultData.as<Formula<Pol>>();
		} else if (resultData.is<Constraint<Pol>>()) {
			return resultData.as<Constraint<Pol>>();
		} else if (resultData.is<RationalFunction<Pol>>()) {
			return resultData.as<RationalFunction<Pol>>();
		} else if (resultData.is<Pol>()) {
			return resultData.as<Pol>();
		} else if (resultData.is<Term<typename Pol::CoeffType>>()) {
			return resultData.as<Term<typename Pol::CoeffType>>();
		} else if (resultData.is<Monomial::Arg>()) {
			return resultData.as<Monomial::Arg>();
		} else if (resultData.is<typename Pol::CoeffType>()) {
			return resultData.as<typename Pol::CoeffType>();
		} else if (resultData.is<Variable>()) {
			return resultData.as<Variable>();
		} else {
			throw std::runtime_error("Unexpected parser result");
		}
	}
}