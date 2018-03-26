
// Generated from /home/travis/build/smtrat/carl-parser/src/carl-parser/Serialization.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"


namespace carlparser {


class  SerializationParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, TBINARY = 17, TDECIMAL = 18, THEXADECIMAL = 19, 
    TNUMERAL = 20, TSTRING = 21, LPAREN = 22, RPAREN = 23, INDEXER = 24, 
    ANNOTATION = 25, AS = 26, LET = 27, EXISTS = 28, FORALL = 29, PAR = 30, 
    TRUE = 31, FALSE = 32, NUMERAL = 33, DECIMAL = 34, HEXADECIMAL = 35, 
    BINARY = 36, STRING = 37, SYMBOL = 38, KEYWORD = 39, WS = 40
  };

  enum {
    RuleStart = 0, RuleCarl_expr = 1, RuleForm_expr = 2, RuleFormula_nary = 3, 
    RuleForm_op_nary = 4, RuleFormula_unary = 5, RuleConstraint = 6, RuleArith_expr = 7, 
    RuleArith_unary = 8, RuleArith_nary = 9, RuleBoolean = 10, RuleNumber = 11, 
    RuleReal_variable = 12, RuleBool_variable = 13
  };

  SerializationParser(antlr4::TokenStream *input);
  ~SerializationParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class StartContext;
  class Carl_exprContext;
  class Form_exprContext;
  class Formula_naryContext;
  class Form_op_naryContext;
  class Formula_unaryContext;
  class ConstraintContext;
  class Arith_exprContext;
  class Arith_unaryContext;
  class Arith_naryContext;
  class BooleanContext;
  class NumberContext;
  class Real_variableContext;
  class Bool_variableContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Carl_exprContext *carl_expr();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StartContext* start();

  class  Carl_exprContext : public antlr4::ParserRuleContext {
  public:
    Carl_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Formula_naryContext *formula_nary();
    Formula_unaryContext *formula_unary();
    ConstraintContext *constraint();
    Arith_naryContext *arith_nary();
    Arith_unaryContext *arith_unary();
    BooleanContext *boolean();
    NumberContext *number();
    Real_variableContext *real_variable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Carl_exprContext* carl_expr();

  class  Form_exprContext : public antlr4::ParserRuleContext {
  public:
    Form_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Formula_naryContext *formula_nary();
    Formula_unaryContext *formula_unary();
    ConstraintContext *constraint();
    BooleanContext *boolean();
    Bool_variableContext *bool_variable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Form_exprContext* form_expr();

  class  Formula_naryContext : public antlr4::ParserRuleContext {
  public:
    Formula_naryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    Form_op_naryContext *form_op_nary();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<Form_exprContext *> form_expr();
    Form_exprContext* form_expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Formula_naryContext* formula_nary();

  class  Form_op_naryContext : public antlr4::ParserRuleContext {
  public:
    Form_op_naryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Form_op_naryContext* form_op_nary();

  class  Formula_unaryContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *token = nullptr;;
    Formula_unaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    Form_exprContext *form_expr();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Formula_unaryContext* formula_unary();

  class  ConstraintContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *token = nullptr;;
    SerializationParser::Arith_exprContext *left = nullptr;;
    ConstraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<Arith_exprContext *> arith_expr();
    Arith_exprContext* arith_expr(size_t i);
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstraintContext* constraint();

  class  Arith_exprContext : public antlr4::ParserRuleContext {
  public:
    Arith_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Arith_naryContext *arith_nary();
    Arith_unaryContext *arith_unary();
    NumberContext *number();
    Real_variableContext *real_variable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arith_exprContext* arith_expr();

  class  Arith_unaryContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *token = nullptr;;
    Arith_unaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    Arith_exprContext *arith_expr();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arith_unaryContext* arith_unary();

  class  Arith_naryContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *token = nullptr;;
    Arith_naryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<Arith_exprContext *> arith_expr();
    Arith_exprContext* arith_expr(size_t i);
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arith_naryContext* arith_nary();

  class  BooleanContext : public antlr4::ParserRuleContext {
  public:
    BooleanContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BooleanContext* boolean();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMERAL();
    antlr4::tree::TerminalNode *DECIMAL();
    antlr4::tree::TerminalNode *HEXADECIMAL();
    antlr4::tree::TerminalNode *BINARY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();

  class  Real_variableContext : public antlr4::ParserRuleContext {
  public:
    Real_variableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYMBOL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Real_variableContext* real_variable();

  class  Bool_variableContext : public antlr4::ParserRuleContext {
  public:
    Bool_variableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYMBOL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bool_variableContext* bool_variable();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace carlparser
