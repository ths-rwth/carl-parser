
// Generated from /home/travis/build/smtrat/carl-parser/src/carl-parser/smtlib.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"


namespace carlparser {


class  smtlibLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, TBINARY = 2, TDECIMAL = 3, THEXADECIMAL = 4, TNUMERAL = 5, 
    TSTRING = 6, LPAREN = 7, RPAREN = 8, INDEXER = 9, ANNOTATION = 10, AS = 11, 
    LET = 12, EXISTS = 13, FORALL = 14, PAR = 15, NUMERAL = 16, DECIMAL = 17, 
    HEXADECIMAL = 18, BINARY = 19, STRING = 20, SYMBOL = 21, KEYWORD = 22, 
    WS = 23
  };

  smtlibLexer(antlr4::CharStream *input);
  ~smtlibLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace carlparser
