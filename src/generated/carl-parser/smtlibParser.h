
// Generated from /home/travis/build/smtrat/carl-parser/src/carl-parser/smtlib.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"


namespace carlparser {


class  smtlibParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, TBINARY = 2, TDECIMAL = 3, THEXADECIMAL = 4, TNUMERAL = 5, 
    TSTRING = 6, LPAREN = 7, RPAREN = 8, INDEXER = 9, ANNOTATION = 10, AS = 11, 
    LET = 12, EXISTS = 13, FORALL = 14, PAR = 15, NUMERAL = 16, DECIMAL = 17, 
    HEXADECIMAL = 18, BINARY = 19, STRING = 20, SYMBOL = 21, KEYWORD = 22, 
    WS = 23
  };

  enum {
    RuleSpec_constant = 0, RuleS_expr = 1, RuleIndex = 2, RuleIdentifier = 3, 
    RuleAttribute_value = 4, RuleAttribute = 5, RuleSort = 6, RuleQual_identifier = 7, 
    RuleVar_binding = 8, RuleSorted_var = 9, RuleTerm = 10, RuleSort_symbol_decl = 11, 
    RuleMeta_spec_constant = 12, RuleFun_symbol_decl = 13, RulePar_fun_symbol_decl = 14, 
    RuleTheory_attribute = 15, RuleTheory_decl = 16
  };

  smtlibParser(antlr4::TokenStream *input);
  ~smtlibParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class Spec_constantContext;
  class S_exprContext;
  class IndexContext;
  class IdentifierContext;
  class Attribute_valueContext;
  class AttributeContext;
  class SortContext;
  class Qual_identifierContext;
  class Var_bindingContext;
  class Sorted_varContext;
  class TermContext;
  class Sort_symbol_declContext;
  class Meta_spec_constantContext;
  class Fun_symbol_declContext;
  class Par_fun_symbol_declContext;
  class Theory_attributeContext;
  class Theory_declContext; 

  class  Spec_constantContext : public antlr4::ParserRuleContext {
  public:
    Spec_constantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMERAL();
    antlr4::tree::TerminalNode *DECIMAL();
    antlr4::tree::TerminalNode *HEXADECIMAL();
    antlr4::tree::TerminalNode *BINARY();
    antlr4::tree::TerminalNode *STRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Spec_constantContext* spec_constant();

  class  S_exprContext : public antlr4::ParserRuleContext {
  public:
    S_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Spec_constantContext *spec_constant();
    antlr4::tree::TerminalNode *SYMBOL();
    antlr4::tree::TerminalNode *KEYWORD();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<S_exprContext *> s_expr();
    S_exprContext* s_expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  S_exprContext* s_expr();

  class  IndexContext : public antlr4::ParserRuleContext {
  public:
    IndexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMERAL();
    antlr4::tree::TerminalNode *SYMBOL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexContext* index();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYMBOL();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *INDEXER();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<IndexContext *> index();
    IndexContext* index(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierContext* identifier();

  class  Attribute_valueContext : public antlr4::ParserRuleContext {
  public:
    Attribute_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Spec_constantContext *spec_constant();
    antlr4::tree::TerminalNode *SYMBOL();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<S_exprContext *> s_expr();
    S_exprContext* s_expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Attribute_valueContext* attribute_value();

  class  AttributeContext : public antlr4::ParserRuleContext {
  public:
    AttributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KEYWORD();
    Attribute_valueContext *attribute_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AttributeContext* attribute();

  class  SortContext : public antlr4::ParserRuleContext {
  public:
    SortContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<SortContext *> sort();
    SortContext* sort(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SortContext* sort();

  class  Qual_identifierContext : public antlr4::ParserRuleContext {
  public:
    Qual_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *AS();
    SortContext *sort();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Qual_identifierContext* qual_identifier();

  class  Var_bindingContext : public antlr4::ParserRuleContext {
  public:
    Var_bindingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *SYMBOL();
    TermContext *term();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_bindingContext* var_binding();

  class  Sorted_varContext : public antlr4::ParserRuleContext {
  public:
    Sorted_varContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *SYMBOL();
    SortContext *sort();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sorted_varContext* sorted_var();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Spec_constantContext *spec_constant();
    Qual_identifierContext *qual_identifier();
    std::vector<antlr4::tree::TerminalNode *> LPAREN();
    antlr4::tree::TerminalNode* LPAREN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAREN();
    antlr4::tree::TerminalNode* RPAREN(size_t i);
    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    antlr4::tree::TerminalNode *LET();
    std::vector<Var_bindingContext *> var_binding();
    Var_bindingContext* var_binding(size_t i);
    antlr4::tree::TerminalNode *FORALL();
    std::vector<Sorted_varContext *> sorted_var();
    Sorted_varContext* sorted_var(size_t i);
    antlr4::tree::TerminalNode *EXISTS();
    antlr4::tree::TerminalNode *ANNOTATION();
    std::vector<AttributeContext *> attribute();
    AttributeContext* attribute(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TermContext* term();

  class  Sort_symbol_declContext : public antlr4::ParserRuleContext {
  public:
    Sort_symbol_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *NUMERAL();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<AttributeContext *> attribute();
    AttributeContext* attribute(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sort_symbol_declContext* sort_symbol_decl();

  class  Meta_spec_constantContext : public antlr4::ParserRuleContext {
  public:
    Meta_spec_constantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TNUMERAL();
    antlr4::tree::TerminalNode *TDECIMAL();
    antlr4::tree::TerminalNode *TSTRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Meta_spec_constantContext* meta_spec_constant();

  class  Fun_symbol_declContext : public antlr4::ParserRuleContext {
  public:
    Fun_symbol_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    Spec_constantContext *spec_constant();
    std::vector<SortContext *> sort();
    SortContext* sort(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<AttributeContext *> attribute();
    AttributeContext* attribute(size_t i);
    Meta_spec_constantContext *meta_spec_constant();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Fun_symbol_declContext* fun_symbol_decl();

  class  Par_fun_symbol_declContext : public antlr4::ParserRuleContext {
  public:
    Par_fun_symbol_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Fun_symbol_declContext *fun_symbol_decl();
    std::vector<antlr4::tree::TerminalNode *> LPAREN();
    antlr4::tree::TerminalNode* LPAREN(size_t i);
    antlr4::tree::TerminalNode *PAR();
    std::vector<antlr4::tree::TerminalNode *> RPAREN();
    antlr4::tree::TerminalNode* RPAREN(size_t i);
    IdentifierContext *identifier();
    std::vector<antlr4::tree::TerminalNode *> SYMBOL();
    antlr4::tree::TerminalNode* SYMBOL(size_t i);
    std::vector<SortContext *> sort();
    SortContext* sort(size_t i);
    std::vector<AttributeContext *> attribute();
    AttributeContext* attribute(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Par_fun_symbol_declContext* par_fun_symbol_decl();

  class  Theory_attributeContext : public antlr4::ParserRuleContext {
  public:
    Theory_attributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AttributeContext *attribute();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Theory_attributeContext* theory_attribute();

  class  Theory_declContext : public antlr4::ParserRuleContext {
  public:
    Theory_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *SYMBOL();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<Theory_attributeContext *> theory_attribute();
    Theory_attributeContext* theory_attribute(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Theory_declContext* theory_decl();


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
