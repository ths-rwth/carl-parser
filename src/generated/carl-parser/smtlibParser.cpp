
// Generated from /home/travis/build/smtrat/carl-parser/src/carl-parser/smtlib.g4 by ANTLR 4.7


#include "smtlibListener.h"
#include "smtlibVisitor.h"

#include "smtlibParser.h"


using namespace antlrcpp;
using namespace carlparser;
using namespace antlr4;

smtlibParser::smtlibParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

smtlibParser::~smtlibParser() {
  delete _interpreter;
}

std::string smtlibParser::getGrammarFileName() const {
  return "smtlib.g4";
}

const std::vector<std::string>& smtlibParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& smtlibParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- Spec_constantContext ------------------------------------------------------------------

smtlibParser::Spec_constantContext::Spec_constantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smtlibParser::Spec_constantContext::NUMERAL() {
  return getToken(smtlibParser::NUMERAL, 0);
}

tree::TerminalNode* smtlibParser::Spec_constantContext::DECIMAL() {
  return getToken(smtlibParser::DECIMAL, 0);
}

tree::TerminalNode* smtlibParser::Spec_constantContext::HEXADECIMAL() {
  return getToken(smtlibParser::HEXADECIMAL, 0);
}

tree::TerminalNode* smtlibParser::Spec_constantContext::BINARY() {
  return getToken(smtlibParser::BINARY, 0);
}

tree::TerminalNode* smtlibParser::Spec_constantContext::STRING() {
  return getToken(smtlibParser::STRING, 0);
}


size_t smtlibParser::Spec_constantContext::getRuleIndex() const {
  return smtlibParser::RuleSpec_constant;
}

void smtlibParser::Spec_constantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpec_constant(this);
}

void smtlibParser::Spec_constantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpec_constant(this);
}


antlrcpp::Any smtlibParser::Spec_constantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smtlibVisitor*>(visitor))
    return parserVisitor->visitSpec_constant(this);
  else
    return visitor->visitChildren(this);
}

smtlibParser::Spec_constantContext* smtlibParser::spec_constant() {
  Spec_constantContext *_localctx = _tracker.createInstance<Spec_constantContext>(_ctx, getState());
  enterRule(_localctx, 0, smtlibParser::RuleSpec_constant);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(34);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << smtlibParser::NUMERAL)
      | (1ULL << smtlibParser::DECIMAL)
      | (1ULL << smtlibParser::HEXADECIMAL)
      | (1ULL << smtlibParser::BINARY)
      | (1ULL << smtlibParser::STRING))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- S_exprContext ------------------------------------------------------------------

smtlibParser::S_exprContext::S_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smtlibParser::Spec_constantContext* smtlibParser::S_exprContext::spec_constant() {
  return getRuleContext<smtlibParser::Spec_constantContext>(0);
}

tree::TerminalNode* smtlibParser::S_exprContext::SYMBOL() {
  return getToken(smtlibParser::SYMBOL, 0);
}

tree::TerminalNode* smtlibParser::S_exprContext::KEYWORD() {
  return getToken(smtlibParser::KEYWORD, 0);
}

tree::TerminalNode* smtlibParser::S_exprContext::LPAREN() {
  return getToken(smtlibParser::LPAREN, 0);
}

tree::TerminalNode* smtlibParser::S_exprContext::RPAREN() {
  return getToken(smtlibParser::RPAREN, 0);
}

std::vector<smtlibParser::S_exprContext *> smtlibParser::S_exprContext::s_expr() {
  return getRuleContexts<smtlibParser::S_exprContext>();
}

smtlibParser::S_exprContext* smtlibParser::S_exprContext::s_expr(size_t i) {
  return getRuleContext<smtlibParser::S_exprContext>(i);
}


size_t smtlibParser::S_exprContext::getRuleIndex() const {
  return smtlibParser::RuleS_expr;
}

void smtlibParser::S_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterS_expr(this);
}

void smtlibParser::S_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitS_expr(this);
}


antlrcpp::Any smtlibParser::S_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smtlibVisitor*>(visitor))
    return parserVisitor->visitS_expr(this);
  else
    return visitor->visitChildren(this);
}

smtlibParser::S_exprContext* smtlibParser::s_expr() {
  S_exprContext *_localctx = _tracker.createInstance<S_exprContext>(_ctx, getState());
  enterRule(_localctx, 2, smtlibParser::RuleS_expr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(47);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smtlibParser::NUMERAL:
      case smtlibParser::DECIMAL:
      case smtlibParser::HEXADECIMAL:
      case smtlibParser::BINARY:
      case smtlibParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(36);
        spec_constant();
        break;
      }

      case smtlibParser::SYMBOL: {
        enterOuterAlt(_localctx, 2);
        setState(37);
        match(smtlibParser::SYMBOL);
        break;
      }

      case smtlibParser::KEYWORD: {
        enterOuterAlt(_localctx, 3);
        setState(38);
        match(smtlibParser::KEYWORD);
        break;
      }

      case smtlibParser::LPAREN: {
        enterOuterAlt(_localctx, 4);
        setState(39);
        match(smtlibParser::LPAREN);
        setState(43);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << smtlibParser::LPAREN)
          | (1ULL << smtlibParser::NUMERAL)
          | (1ULL << smtlibParser::DECIMAL)
          | (1ULL << smtlibParser::HEXADECIMAL)
          | (1ULL << smtlibParser::BINARY)
          | (1ULL << smtlibParser::STRING)
          | (1ULL << smtlibParser::SYMBOL)
          | (1ULL << smtlibParser::KEYWORD))) != 0)) {
          setState(40);
          s_expr();
          setState(45);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(46);
        match(smtlibParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexContext ------------------------------------------------------------------

smtlibParser::IndexContext::IndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smtlibParser::IndexContext::NUMERAL() {
  return getToken(smtlibParser::NUMERAL, 0);
}

tree::TerminalNode* smtlibParser::IndexContext::SYMBOL() {
  return getToken(smtlibParser::SYMBOL, 0);
}


size_t smtlibParser::IndexContext::getRuleIndex() const {
  return smtlibParser::RuleIndex;
}

void smtlibParser::IndexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndex(this);
}

void smtlibParser::IndexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndex(this);
}


antlrcpp::Any smtlibParser::IndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smtlibVisitor*>(visitor))
    return parserVisitor->visitIndex(this);
  else
    return visitor->visitChildren(this);
}

smtlibParser::IndexContext* smtlibParser::index() {
  IndexContext *_localctx = _tracker.createInstance<IndexContext>(_ctx, getState());
  enterRule(_localctx, 4, smtlibParser::RuleIndex);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    _la = _input->LA(1);
    if (!(_la == smtlibParser::NUMERAL

    || _la == smtlibParser::SYMBOL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

smtlibParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smtlibParser::IdentifierContext::SYMBOL() {
  return getToken(smtlibParser::SYMBOL, 0);
}

tree::TerminalNode* smtlibParser::IdentifierContext::LPAREN() {
  return getToken(smtlibParser::LPAREN, 0);
}

tree::TerminalNode* smtlibParser::IdentifierContext::INDEXER() {
  return getToken(smtlibParser::INDEXER, 0);
}

tree::TerminalNode* smtlibParser::IdentifierContext::RPAREN() {
  return getToken(smtlibParser::RPAREN, 0);
}

std::vector<smtlibParser::IndexContext *> smtlibParser::IdentifierContext::index() {
  return getRuleContexts<smtlibParser::IndexContext>();
}

smtlibParser::IndexContext* smtlibParser::IdentifierContext::index(size_t i) {
  return getRuleContext<smtlibParser::IndexContext>(i);
}


size_t smtlibParser::IdentifierContext::getRuleIndex() const {
  return smtlibParser::RuleIdentifier;
}

void smtlibParser::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}

void smtlibParser::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}


antlrcpp::Any smtlibParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smtlibVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

smtlibParser::IdentifierContext* smtlibParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 6, smtlibParser::RuleIdentifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(62);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smtlibParser::SYMBOL: {
        enterOuterAlt(_localctx, 1);
        setState(51);
        match(smtlibParser::SYMBOL);
        break;
      }

      case smtlibParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(52);
        match(smtlibParser::LPAREN);
        setState(53);
        match(smtlibParser::INDEXER);
        setState(54);
        match(smtlibParser::SYMBOL);
        setState(56); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(55);
          index();
          setState(58); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == smtlibParser::NUMERAL

        || _la == smtlibParser::SYMBOL);
        setState(60);
        match(smtlibParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Attribute_valueContext ------------------------------------------------------------------

smtlibParser::Attribute_valueContext::Attribute_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smtlibParser::Spec_constantContext* smtlibParser::Attribute_valueContext::spec_constant() {
  return getRuleContext<smtlibParser::Spec_constantContext>(0);
}

tree::TerminalNode* smtlibParser::Attribute_valueContext::SYMBOL() {
  return getToken(smtlibParser::SYMBOL, 0);
}

tree::TerminalNode* smtlibParser::Attribute_valueContext::LPAREN() {
  return getToken(smtlibParser::LPAREN, 0);
}

tree::TerminalNode* smtlibParser::Attribute_valueContext::RPAREN() {
  return getToken(smtlibParser::RPAREN, 0);
}

std::vector<smtlibParser::S_exprContext *> smtlibParser::Attribute_valueContext::s_expr() {
  return getRuleContexts<smtlibParser::S_exprContext>();
}

smtlibParser::S_exprContext* smtlibParser::Attribute_valueContext::s_expr(size_t i) {
  return getRuleContext<smtlibParser::S_exprContext>(i);
}


size_t smtlibParser::Attribute_valueContext::getRuleIndex() const {
  return smtlibParser::RuleAttribute_value;
}

void smtlibParser::Attribute_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttribute_value(this);
}

void smtlibParser::Attribute_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttribute_value(this);
}


antlrcpp::Any smtlibParser::Attribute_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smtlibVisitor*>(visitor))
    return parserVisitor->visitAttribute_value(this);
  else
    return visitor->visitChildren(this);
}

smtlibParser::Attribute_valueContext* smtlibParser::attribute_value() {
  Attribute_valueContext *_localctx = _tracker.createInstance<Attribute_valueContext>(_ctx, getState());
  enterRule(_localctx, 8, smtlibParser::RuleAttribute_value);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(74);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smtlibParser::NUMERAL:
      case smtlibParser::DECIMAL:
      case smtlibParser::HEXADECIMAL:
      case smtlibParser::BINARY:
      case smtlibParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(64);
        spec_constant();
        break;
      }

      case smtlibParser::SYMBOL: {
        enterOuterAlt(_localctx, 2);
        setState(65);
        match(smtlibParser::SYMBOL);
        break;
      }

      case smtlibParser::LPAREN: {
        enterOuterAlt(_localctx, 3);
        setState(66);
        match(smtlibParser::LPAREN);
        setState(70);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << smtlibParser::LPAREN)
          | (1ULL << smtlibParser::NUMERAL)
          | (1ULL << smtlibParser::DECIMAL)
          | (1ULL << smtlibParser::HEXADECIMAL)
          | (1ULL << smtlibParser::BINARY)
          | (1ULL << smtlibParser::STRING)
          | (1ULL << smtlibParser::SYMBOL)
          | (1ULL << smtlibParser::KEYWORD))) != 0)) {
          setState(67);
          s_expr();
          setState(72);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(73);
        match(smtlibParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeContext ------------------------------------------------------------------

smtlibParser::AttributeContext::AttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smtlibParser::AttributeContext::KEYWORD() {
  return getToken(smtlibParser::KEYWORD, 0);
}

smtlibParser::Attribute_valueContext* smtlibParser::AttributeContext::attribute_value() {
  return getRuleContext<smtlibParser::Attribute_valueContext>(0);
}


size_t smtlibParser::AttributeContext::getRuleIndex() const {
  return smtlibParser::RuleAttribute;
}

void smtlibParser::AttributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttribute(this);
}

void smtlibParser::AttributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttribute(this);
}


antlrcpp::Any smtlibParser::AttributeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smtlibVisitor*>(visitor))
    return parserVisitor->visitAttribute(this);
  else
    return visitor->visitChildren(this);
}

smtlibParser::AttributeContext* smtlibParser::attribute() {
  AttributeContext *_localctx = _tracker.createInstance<AttributeContext>(_ctx, getState());
  enterRule(_localctx, 10, smtlibParser::RuleAttribute);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    match(smtlibParser::KEYWORD);
    setState(78);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << smtlibParser::LPAREN)
      | (1ULL << smtlibParser::NUMERAL)
      | (1ULL << smtlibParser::DECIMAL)
      | (1ULL << smtlibParser::HEXADECIMAL)
      | (1ULL << smtlibParser::BINARY)
      | (1ULL << smtlibParser::STRING)
      | (1ULL << smtlibParser::SYMBOL))) != 0)) {
      setState(77);
      attribute_value();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SortContext ------------------------------------------------------------------

smtlibParser::SortContext::SortContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smtlibParser::IdentifierContext* smtlibParser::SortContext::identifier() {
  return getRuleContext<smtlibParser::IdentifierContext>(0);
}

tree::TerminalNode* smtlibParser::SortContext::LPAREN() {
  return getToken(smtlibParser::LPAREN, 0);
}

tree::TerminalNode* smtlibParser::SortContext::RPAREN() {
  return getToken(smtlibParser::RPAREN, 0);
}

std::vector<smtlibParser::SortContext *> smtlibParser::SortContext::sort() {
  return getRuleContexts<smtlibParser::SortContext>();
}

smtlibParser::SortContext* smtlibParser::SortContext::sort(size_t i) {
  return getRuleContext<smtlibParser::SortContext>(i);
}


size_t smtlibParser::SortContext::getRuleIndex() const {
  return smtlibParser::RuleSort;
}

void smtlibParser::SortContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSort(this);
}

void smtlibParser::SortContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSort(this);
}


antlrcpp::Any smtlibParser::SortContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smtlibVisitor*>(visitor))
    return parserVisitor->visitSort(this);
  else
    return visitor->visitChildren(this);
}

smtlibParser::SortContext* smtlibParser::sort() {
  SortContext *_localctx = _tracker.createInstance<SortContext>(_ctx, getState());
  enterRule(_localctx, 12, smtlibParser::RuleSort);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(90);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(80);
      identifier();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(81);
      match(smtlibParser::LPAREN);
      setState(82);
      identifier();
      setState(84); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(83);
        sort();
        setState(86); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == smtlibParser::LPAREN

      || _la == smtlibParser::SYMBOL);
      setState(88);
      match(smtlibParser::RPAREN);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Qual_identifierContext ------------------------------------------------------------------

smtlibParser::Qual_identifierContext::Qual_identifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smtlibParser::IdentifierContext* smtlibParser::Qual_identifierContext::identifier() {
  return getRuleContext<smtlibParser::IdentifierContext>(0);
}

tree::TerminalNode* smtlibParser::Qual_identifierContext::LPAREN() {
  return getToken(smtlibParser::LPAREN, 0);
}

tree::TerminalNode* smtlibParser::Qual_identifierContext::AS() {
  return getToken(smtlibParser::AS, 0);
}

smtlibParser::SortContext* smtlibParser::Qual_identifierContext::sort() {
  return getRuleContext<smtlibParser::SortContext>(0);
}

tree::TerminalNode* smtlibParser::Qual_identifierContext::RPAREN() {
  return getToken(smtlibParser::RPAREN, 0);
}


size_t smtlibParser::Qual_identifierContext::getRuleIndex() const {
  return smtlibParser::RuleQual_identifier;
}

void smtlibParser::Qual_identifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQual_identifier(this);
}

void smtlibParser::Qual_identifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQual_identifier(this);
}


antlrcpp::Any smtlibParser::Qual_identifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smtlibVisitor*>(visitor))
    return parserVisitor->visitQual_identifier(this);
  else
    return visitor->visitChildren(this);
}

smtlibParser::Qual_identifierContext* smtlibParser::qual_identifier() {
  Qual_identifierContext *_localctx = _tracker.createInstance<Qual_identifierContext>(_ctx, getState());
  enterRule(_localctx, 14, smtlibParser::RuleQual_identifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(99);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(92);
      identifier();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(93);
      match(smtlibParser::LPAREN);
      setState(94);
      match(smtlibParser::AS);
      setState(95);
      identifier();
      setState(96);
      sort();
      setState(97);
      match(smtlibParser::RPAREN);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_bindingContext ------------------------------------------------------------------

smtlibParser::Var_bindingContext::Var_bindingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smtlibParser::Var_bindingContext::LPAREN() {
  return getToken(smtlibParser::LPAREN, 0);
}

tree::TerminalNode* smtlibParser::Var_bindingContext::SYMBOL() {
  return getToken(smtlibParser::SYMBOL, 0);
}

smtlibParser::TermContext* smtlibParser::Var_bindingContext::term() {
  return getRuleContext<smtlibParser::TermContext>(0);
}

tree::TerminalNode* smtlibParser::Var_bindingContext::RPAREN() {
  return getToken(smtlibParser::RPAREN, 0);
}


size_t smtlibParser::Var_bindingContext::getRuleIndex() const {
  return smtlibParser::RuleVar_binding;
}

void smtlibParser::Var_bindingContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_binding(this);
}

void smtlibParser::Var_bindingContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_binding(this);
}


antlrcpp::Any smtlibParser::Var_bindingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smtlibVisitor*>(visitor))
    return parserVisitor->visitVar_binding(this);
  else
    return visitor->visitChildren(this);
}

smtlibParser::Var_bindingContext* smtlibParser::var_binding() {
  Var_bindingContext *_localctx = _tracker.createInstance<Var_bindingContext>(_ctx, getState());
  enterRule(_localctx, 16, smtlibParser::RuleVar_binding);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    match(smtlibParser::LPAREN);
    setState(102);
    match(smtlibParser::SYMBOL);
    setState(103);
    term();
    setState(104);
    match(smtlibParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sorted_varContext ------------------------------------------------------------------

smtlibParser::Sorted_varContext::Sorted_varContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smtlibParser::Sorted_varContext::LPAREN() {
  return getToken(smtlibParser::LPAREN, 0);
}

tree::TerminalNode* smtlibParser::Sorted_varContext::SYMBOL() {
  return getToken(smtlibParser::SYMBOL, 0);
}

smtlibParser::SortContext* smtlibParser::Sorted_varContext::sort() {
  return getRuleContext<smtlibParser::SortContext>(0);
}

tree::TerminalNode* smtlibParser::Sorted_varContext::RPAREN() {
  return getToken(smtlibParser::RPAREN, 0);
}


size_t smtlibParser::Sorted_varContext::getRuleIndex() const {
  return smtlibParser::RuleSorted_var;
}

void smtlibParser::Sorted_varContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSorted_var(this);
}

void smtlibParser::Sorted_varContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSorted_var(this);
}


antlrcpp::Any smtlibParser::Sorted_varContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smtlibVisitor*>(visitor))
    return parserVisitor->visitSorted_var(this);
  else
    return visitor->visitChildren(this);
}

smtlibParser::Sorted_varContext* smtlibParser::sorted_var() {
  Sorted_varContext *_localctx = _tracker.createInstance<Sorted_varContext>(_ctx, getState());
  enterRule(_localctx, 18, smtlibParser::RuleSorted_var);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106);
    match(smtlibParser::LPAREN);
    setState(107);
    match(smtlibParser::SYMBOL);
    setState(108);
    sort();
    setState(109);
    match(smtlibParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

smtlibParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smtlibParser::Spec_constantContext* smtlibParser::TermContext::spec_constant() {
  return getRuleContext<smtlibParser::Spec_constantContext>(0);
}

smtlibParser::Qual_identifierContext* smtlibParser::TermContext::qual_identifier() {
  return getRuleContext<smtlibParser::Qual_identifierContext>(0);
}

std::vector<tree::TerminalNode *> smtlibParser::TermContext::LPAREN() {
  return getTokens(smtlibParser::LPAREN);
}

tree::TerminalNode* smtlibParser::TermContext::LPAREN(size_t i) {
  return getToken(smtlibParser::LPAREN, i);
}

std::vector<tree::TerminalNode *> smtlibParser::TermContext::RPAREN() {
  return getTokens(smtlibParser::RPAREN);
}

tree::TerminalNode* smtlibParser::TermContext::RPAREN(size_t i) {
  return getToken(smtlibParser::RPAREN, i);
}

std::vector<smtlibParser::TermContext *> smtlibParser::TermContext::term() {
  return getRuleContexts<smtlibParser::TermContext>();
}

smtlibParser::TermContext* smtlibParser::TermContext::term(size_t i) {
  return getRuleContext<smtlibParser::TermContext>(i);
}

tree::TerminalNode* smtlibParser::TermContext::LET() {
  return getToken(smtlibParser::LET, 0);
}

std::vector<smtlibParser::Var_bindingContext *> smtlibParser::TermContext::var_binding() {
  return getRuleContexts<smtlibParser::Var_bindingContext>();
}

smtlibParser::Var_bindingContext* smtlibParser::TermContext::var_binding(size_t i) {
  return getRuleContext<smtlibParser::Var_bindingContext>(i);
}

tree::TerminalNode* smtlibParser::TermContext::FORALL() {
  return getToken(smtlibParser::FORALL, 0);
}

std::vector<smtlibParser::Sorted_varContext *> smtlibParser::TermContext::sorted_var() {
  return getRuleContexts<smtlibParser::Sorted_varContext>();
}

smtlibParser::Sorted_varContext* smtlibParser::TermContext::sorted_var(size_t i) {
  return getRuleContext<smtlibParser::Sorted_varContext>(i);
}

tree::TerminalNode* smtlibParser::TermContext::EXISTS() {
  return getToken(smtlibParser::EXISTS, 0);
}

tree::TerminalNode* smtlibParser::TermContext::ANNOTATION() {
  return getToken(smtlibParser::ANNOTATION, 0);
}

std::vector<smtlibParser::AttributeContext *> smtlibParser::TermContext::attribute() {
  return getRuleContexts<smtlibParser::AttributeContext>();
}

smtlibParser::AttributeContext* smtlibParser::TermContext::attribute(size_t i) {
  return getRuleContext<smtlibParser::AttributeContext>(i);
}


size_t smtlibParser::TermContext::getRuleIndex() const {
  return smtlibParser::RuleTerm;
}

void smtlibParser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void smtlibParser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


antlrcpp::Any smtlibParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smtlibVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

smtlibParser::TermContext* smtlibParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 20, smtlibParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(165);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(111);
      spec_constant();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(112);
      qual_identifier();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(113);
      match(smtlibParser::LPAREN);
      setState(114);
      qual_identifier();
      setState(116); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(115);
        term();
        setState(118); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << smtlibParser::LPAREN)
        | (1ULL << smtlibParser::NUMERAL)
        | (1ULL << smtlibParser::DECIMAL)
        | (1ULL << smtlibParser::HEXADECIMAL)
        | (1ULL << smtlibParser::BINARY)
        | (1ULL << smtlibParser::STRING)
        | (1ULL << smtlibParser::SYMBOL))) != 0));
      setState(120);
      match(smtlibParser::RPAREN);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(122);
      match(smtlibParser::LPAREN);
      setState(123);
      match(smtlibParser::LET);
      setState(124);
      match(smtlibParser::LPAREN);
      setState(126); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(125);
        var_binding();
        setState(128); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == smtlibParser::LPAREN);
      setState(130);
      match(smtlibParser::RPAREN);
      setState(131);
      match(smtlibParser::RPAREN);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(133);
      match(smtlibParser::LPAREN);
      setState(134);
      match(smtlibParser::FORALL);
      setState(136); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(135);
                sorted_var();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(138); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(140);
      match(smtlibParser::LPAREN);
      setState(141);
      match(smtlibParser::RPAREN);
      setState(142);
      match(smtlibParser::RPAREN);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(144);
      match(smtlibParser::LPAREN);
      setState(145);
      match(smtlibParser::EXISTS);
      setState(147); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(146);
                sorted_var();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(149); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(151);
      match(smtlibParser::LPAREN);
      setState(152);
      match(smtlibParser::RPAREN);
      setState(153);
      match(smtlibParser::RPAREN);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(155);
      match(smtlibParser::LPAREN);
      setState(156);
      match(smtlibParser::ANNOTATION);
      setState(157);
      term();
      setState(159); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(158);
        attribute();
        setState(161); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == smtlibParser::KEYWORD);
      setState(163);
      match(smtlibParser::RPAREN);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sort_symbol_declContext ------------------------------------------------------------------

smtlibParser::Sort_symbol_declContext::Sort_symbol_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smtlibParser::Sort_symbol_declContext::LPAREN() {
  return getToken(smtlibParser::LPAREN, 0);
}

smtlibParser::IdentifierContext* smtlibParser::Sort_symbol_declContext::identifier() {
  return getRuleContext<smtlibParser::IdentifierContext>(0);
}

tree::TerminalNode* smtlibParser::Sort_symbol_declContext::NUMERAL() {
  return getToken(smtlibParser::NUMERAL, 0);
}

tree::TerminalNode* smtlibParser::Sort_symbol_declContext::RPAREN() {
  return getToken(smtlibParser::RPAREN, 0);
}

std::vector<smtlibParser::AttributeContext *> smtlibParser::Sort_symbol_declContext::attribute() {
  return getRuleContexts<smtlibParser::AttributeContext>();
}

smtlibParser::AttributeContext* smtlibParser::Sort_symbol_declContext::attribute(size_t i) {
  return getRuleContext<smtlibParser::AttributeContext>(i);
}


size_t smtlibParser::Sort_symbol_declContext::getRuleIndex() const {
  return smtlibParser::RuleSort_symbol_decl;
}

void smtlibParser::Sort_symbol_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSort_symbol_decl(this);
}

void smtlibParser::Sort_symbol_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSort_symbol_decl(this);
}


antlrcpp::Any smtlibParser::Sort_symbol_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smtlibVisitor*>(visitor))
    return parserVisitor->visitSort_symbol_decl(this);
  else
    return visitor->visitChildren(this);
}

smtlibParser::Sort_symbol_declContext* smtlibParser::sort_symbol_decl() {
  Sort_symbol_declContext *_localctx = _tracker.createInstance<Sort_symbol_declContext>(_ctx, getState());
  enterRule(_localctx, 22, smtlibParser::RuleSort_symbol_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    match(smtlibParser::LPAREN);
    setState(168);
    identifier();
    setState(169);
    match(smtlibParser::NUMERAL);
    setState(173);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == smtlibParser::KEYWORD) {
      setState(170);
      attribute();
      setState(175);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(176);
    match(smtlibParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Meta_spec_constantContext ------------------------------------------------------------------

smtlibParser::Meta_spec_constantContext::Meta_spec_constantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smtlibParser::Meta_spec_constantContext::TNUMERAL() {
  return getToken(smtlibParser::TNUMERAL, 0);
}

tree::TerminalNode* smtlibParser::Meta_spec_constantContext::TDECIMAL() {
  return getToken(smtlibParser::TDECIMAL, 0);
}

tree::TerminalNode* smtlibParser::Meta_spec_constantContext::TSTRING() {
  return getToken(smtlibParser::TSTRING, 0);
}


size_t smtlibParser::Meta_spec_constantContext::getRuleIndex() const {
  return smtlibParser::RuleMeta_spec_constant;
}

void smtlibParser::Meta_spec_constantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMeta_spec_constant(this);
}

void smtlibParser::Meta_spec_constantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMeta_spec_constant(this);
}


antlrcpp::Any smtlibParser::Meta_spec_constantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smtlibVisitor*>(visitor))
    return parserVisitor->visitMeta_spec_constant(this);
  else
    return visitor->visitChildren(this);
}

smtlibParser::Meta_spec_constantContext* smtlibParser::meta_spec_constant() {
  Meta_spec_constantContext *_localctx = _tracker.createInstance<Meta_spec_constantContext>(_ctx, getState());
  enterRule(_localctx, 24, smtlibParser::RuleMeta_spec_constant);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << smtlibParser::TDECIMAL)
      | (1ULL << smtlibParser::TNUMERAL)
      | (1ULL << smtlibParser::TSTRING))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fun_symbol_declContext ------------------------------------------------------------------

smtlibParser::Fun_symbol_declContext::Fun_symbol_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smtlibParser::Fun_symbol_declContext::LPAREN() {
  return getToken(smtlibParser::LPAREN, 0);
}

smtlibParser::Spec_constantContext* smtlibParser::Fun_symbol_declContext::spec_constant() {
  return getRuleContext<smtlibParser::Spec_constantContext>(0);
}

std::vector<smtlibParser::SortContext *> smtlibParser::Fun_symbol_declContext::sort() {
  return getRuleContexts<smtlibParser::SortContext>();
}

smtlibParser::SortContext* smtlibParser::Fun_symbol_declContext::sort(size_t i) {
  return getRuleContext<smtlibParser::SortContext>(i);
}

tree::TerminalNode* smtlibParser::Fun_symbol_declContext::RPAREN() {
  return getToken(smtlibParser::RPAREN, 0);
}

std::vector<smtlibParser::AttributeContext *> smtlibParser::Fun_symbol_declContext::attribute() {
  return getRuleContexts<smtlibParser::AttributeContext>();
}

smtlibParser::AttributeContext* smtlibParser::Fun_symbol_declContext::attribute(size_t i) {
  return getRuleContext<smtlibParser::AttributeContext>(i);
}

smtlibParser::Meta_spec_constantContext* smtlibParser::Fun_symbol_declContext::meta_spec_constant() {
  return getRuleContext<smtlibParser::Meta_spec_constantContext>(0);
}

smtlibParser::IdentifierContext* smtlibParser::Fun_symbol_declContext::identifier() {
  return getRuleContext<smtlibParser::IdentifierContext>(0);
}


size_t smtlibParser::Fun_symbol_declContext::getRuleIndex() const {
  return smtlibParser::RuleFun_symbol_decl;
}

void smtlibParser::Fun_symbol_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFun_symbol_decl(this);
}

void smtlibParser::Fun_symbol_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFun_symbol_decl(this);
}


antlrcpp::Any smtlibParser::Fun_symbol_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smtlibVisitor*>(visitor))
    return parserVisitor->visitFun_symbol_decl(this);
  else
    return visitor->visitChildren(this);
}

smtlibParser::Fun_symbol_declContext* smtlibParser::fun_symbol_decl() {
  Fun_symbol_declContext *_localctx = _tracker.createInstance<Fun_symbol_declContext>(_ctx, getState());
  enterRule(_localctx, 26, smtlibParser::RuleFun_symbol_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(217);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(180);
      match(smtlibParser::LPAREN);
      setState(181);
      spec_constant();
      setState(182);
      sort();
      setState(186);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == smtlibParser::KEYWORD) {
        setState(183);
        attribute();
        setState(188);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(189);
      match(smtlibParser::RPAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(191);
      match(smtlibParser::LPAREN);
      setState(192);
      meta_spec_constant();
      setState(193);
      sort();
      setState(197);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == smtlibParser::KEYWORD) {
        setState(194);
        attribute();
        setState(199);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(200);
      match(smtlibParser::RPAREN);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(202);
      match(smtlibParser::LPAREN);
      setState(203);
      identifier();
      setState(205); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(204);
        sort();
        setState(207); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == smtlibParser::LPAREN

      || _la == smtlibParser::SYMBOL);
      setState(212);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == smtlibParser::KEYWORD) {
        setState(209);
        attribute();
        setState(214);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(215);
      match(smtlibParser::RPAREN);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Par_fun_symbol_declContext ------------------------------------------------------------------

smtlibParser::Par_fun_symbol_declContext::Par_fun_symbol_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smtlibParser::Fun_symbol_declContext* smtlibParser::Par_fun_symbol_declContext::fun_symbol_decl() {
  return getRuleContext<smtlibParser::Fun_symbol_declContext>(0);
}

std::vector<tree::TerminalNode *> smtlibParser::Par_fun_symbol_declContext::LPAREN() {
  return getTokens(smtlibParser::LPAREN);
}

tree::TerminalNode* smtlibParser::Par_fun_symbol_declContext::LPAREN(size_t i) {
  return getToken(smtlibParser::LPAREN, i);
}

tree::TerminalNode* smtlibParser::Par_fun_symbol_declContext::PAR() {
  return getToken(smtlibParser::PAR, 0);
}

std::vector<tree::TerminalNode *> smtlibParser::Par_fun_symbol_declContext::RPAREN() {
  return getTokens(smtlibParser::RPAREN);
}

tree::TerminalNode* smtlibParser::Par_fun_symbol_declContext::RPAREN(size_t i) {
  return getToken(smtlibParser::RPAREN, i);
}

smtlibParser::IdentifierContext* smtlibParser::Par_fun_symbol_declContext::identifier() {
  return getRuleContext<smtlibParser::IdentifierContext>(0);
}

std::vector<tree::TerminalNode *> smtlibParser::Par_fun_symbol_declContext::SYMBOL() {
  return getTokens(smtlibParser::SYMBOL);
}

tree::TerminalNode* smtlibParser::Par_fun_symbol_declContext::SYMBOL(size_t i) {
  return getToken(smtlibParser::SYMBOL, i);
}

std::vector<smtlibParser::SortContext *> smtlibParser::Par_fun_symbol_declContext::sort() {
  return getRuleContexts<smtlibParser::SortContext>();
}

smtlibParser::SortContext* smtlibParser::Par_fun_symbol_declContext::sort(size_t i) {
  return getRuleContext<smtlibParser::SortContext>(i);
}

std::vector<smtlibParser::AttributeContext *> smtlibParser::Par_fun_symbol_declContext::attribute() {
  return getRuleContexts<smtlibParser::AttributeContext>();
}

smtlibParser::AttributeContext* smtlibParser::Par_fun_symbol_declContext::attribute(size_t i) {
  return getRuleContext<smtlibParser::AttributeContext>(i);
}


size_t smtlibParser::Par_fun_symbol_declContext::getRuleIndex() const {
  return smtlibParser::RulePar_fun_symbol_decl;
}

void smtlibParser::Par_fun_symbol_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPar_fun_symbol_decl(this);
}

void smtlibParser::Par_fun_symbol_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPar_fun_symbol_decl(this);
}


antlrcpp::Any smtlibParser::Par_fun_symbol_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smtlibVisitor*>(visitor))
    return parserVisitor->visitPar_fun_symbol_decl(this);
  else
    return visitor->visitChildren(this);
}

smtlibParser::Par_fun_symbol_declContext* smtlibParser::par_fun_symbol_decl() {
  Par_fun_symbol_declContext *_localctx = _tracker.createInstance<Par_fun_symbol_declContext>(_ctx, getState());
  enterRule(_localctx, 28, smtlibParser::RulePar_fun_symbol_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(245);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(219);
      fun_symbol_decl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(220);
      match(smtlibParser::LPAREN);
      setState(221);
      match(smtlibParser::PAR);
      setState(222);
      match(smtlibParser::LPAREN);
      setState(224); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(223);
        match(smtlibParser::SYMBOL);
        setState(226); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == smtlibParser::SYMBOL);
      setState(228);
      match(smtlibParser::RPAREN);
      setState(229);
      match(smtlibParser::LPAREN);
      setState(230);
      identifier();
      setState(232); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(231);
        sort();
        setState(234); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == smtlibParser::LPAREN

      || _la == smtlibParser::SYMBOL);
      setState(239);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == smtlibParser::KEYWORD) {
        setState(236);
        attribute();
        setState(241);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(242);
      match(smtlibParser::RPAREN);
      setState(243);
      match(smtlibParser::RPAREN);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Theory_attributeContext ------------------------------------------------------------------

smtlibParser::Theory_attributeContext::Theory_attributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smtlibParser::AttributeContext* smtlibParser::Theory_attributeContext::attribute() {
  return getRuleContext<smtlibParser::AttributeContext>(0);
}


size_t smtlibParser::Theory_attributeContext::getRuleIndex() const {
  return smtlibParser::RuleTheory_attribute;
}

void smtlibParser::Theory_attributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTheory_attribute(this);
}

void smtlibParser::Theory_attributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTheory_attribute(this);
}


antlrcpp::Any smtlibParser::Theory_attributeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smtlibVisitor*>(visitor))
    return parserVisitor->visitTheory_attribute(this);
  else
    return visitor->visitChildren(this);
}

smtlibParser::Theory_attributeContext* smtlibParser::theory_attribute() {
  Theory_attributeContext *_localctx = _tracker.createInstance<Theory_attributeContext>(_ctx, getState());
  enterRule(_localctx, 30, smtlibParser::RuleTheory_attribute);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(247);
    attribute();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Theory_declContext ------------------------------------------------------------------

smtlibParser::Theory_declContext::Theory_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smtlibParser::Theory_declContext::LPAREN() {
  return getToken(smtlibParser::LPAREN, 0);
}

tree::TerminalNode* smtlibParser::Theory_declContext::SYMBOL() {
  return getToken(smtlibParser::SYMBOL, 0);
}

tree::TerminalNode* smtlibParser::Theory_declContext::RPAREN() {
  return getToken(smtlibParser::RPAREN, 0);
}

std::vector<smtlibParser::Theory_attributeContext *> smtlibParser::Theory_declContext::theory_attribute() {
  return getRuleContexts<smtlibParser::Theory_attributeContext>();
}

smtlibParser::Theory_attributeContext* smtlibParser::Theory_declContext::theory_attribute(size_t i) {
  return getRuleContext<smtlibParser::Theory_attributeContext>(i);
}


size_t smtlibParser::Theory_declContext::getRuleIndex() const {
  return smtlibParser::RuleTheory_decl;
}

void smtlibParser::Theory_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTheory_decl(this);
}

void smtlibParser::Theory_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<smtlibListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTheory_decl(this);
}


antlrcpp::Any smtlibParser::Theory_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smtlibVisitor*>(visitor))
    return parserVisitor->visitTheory_decl(this);
  else
    return visitor->visitChildren(this);
}

smtlibParser::Theory_declContext* smtlibParser::theory_decl() {
  Theory_declContext *_localctx = _tracker.createInstance<Theory_declContext>(_ctx, getState());
  enterRule(_localctx, 32, smtlibParser::RuleTheory_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    match(smtlibParser::LPAREN);
    setState(250);
    match(smtlibParser::T__0);
    setState(251);
    match(smtlibParser::SYMBOL);
    setState(253); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(252);
      theory_attribute();
      setState(255); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == smtlibParser::KEYWORD);
    setState(257);
    match(smtlibParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> smtlibParser::_decisionToDFA;
atn::PredictionContextCache smtlibParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN smtlibParser::_atn;
std::vector<uint16_t> smtlibParser::_serializedATN;

std::vector<std::string> smtlibParser::_ruleNames = {
  "spec_constant", "s_expr", "index", "identifier", "attribute_value", "attribute", 
  "sort", "qual_identifier", "var_binding", "sorted_var", "term", "sort_symbol_decl", 
  "meta_spec_constant", "fun_symbol_decl", "par_fun_symbol_decl", "theory_attribute", 
  "theory_decl"
};

std::vector<std::string> smtlibParser::_literalNames = {
  "", "'theory'", "'BINARY'", "'DECIMAL'", "'HEXADECIMAL'", "'NUMERAL'", 
  "'STRING'", "'('", "')'", "'_'", "'!'", "'as'", "'let'", "'exists'", "'forall'", 
  "'par'"
};

std::vector<std::string> smtlibParser::_symbolicNames = {
  "", "", "TBINARY", "TDECIMAL", "THEXADECIMAL", "TNUMERAL", "TSTRING", 
  "LPAREN", "RPAREN", "INDEXER", "ANNOTATION", "AS", "LET", "EXISTS", "FORALL", 
  "PAR", "NUMERAL", "DECIMAL", "HEXADECIMAL", "BINARY", "STRING", "SYMBOL", 
  "KEYWORD", "WS"
};

dfa::Vocabulary smtlibParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> smtlibParser::_tokenNames;

smtlibParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x19, 0x106, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x7, 0x3, 0x2c, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x2f, 0xb, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x32, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x6, 0x5, 0x3b, 0xa, 0x5, 0xd, 
    0x5, 0xe, 0x5, 0x3c, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x41, 0xa, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x47, 0xa, 0x6, 0xc, 0x6, 
    0xe, 0x6, 0x4a, 0xb, 0x6, 0x3, 0x6, 0x5, 0x6, 0x4d, 0xa, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x5, 0x7, 0x51, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x6, 0x8, 0x57, 0xa, 0x8, 0xd, 0x8, 0xe, 0x8, 0x58, 0x3, 0x8, 0x3, 
    0x8, 0x5, 0x8, 0x5d, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x66, 0xa, 0x9, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x6, 
    0xc, 0x77, 0xa, 0xc, 0xd, 0xc, 0xe, 0xc, 0x78, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x6, 0xc, 0x81, 0xa, 0xc, 0xd, 0xc, 
    0xe, 0xc, 0x82, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x6, 0xc, 0x8b, 0xa, 0xc, 0xd, 0xc, 0xe, 0xc, 0x8c, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x6, 0xc, 0x96, 
    0xa, 0xc, 0xd, 0xc, 0xe, 0xc, 0x97, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x6, 0xc, 0xa2, 0xa, 0xc, 
    0xd, 0xc, 0xe, 0xc, 0xa3, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xa8, 0xa, 0xc, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xae, 0xa, 0xd, 0xc, 
    0xd, 0xe, 0xd, 0xb1, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xbb, 0xa, 0xf, 0xc, 
    0xf, 0xe, 0xf, 0xbe, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xc6, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xc9, 
    0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x6, 0xf, 
    0xd0, 0xa, 0xf, 0xd, 0xf, 0xe, 0xf, 0xd1, 0x3, 0xf, 0x7, 0xf, 0xd5, 
    0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xd8, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 
    0xf, 0xdc, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x6, 0x10, 0xe3, 0xa, 0x10, 0xd, 0x10, 0xe, 0x10, 0xe4, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x6, 0x10, 0xeb, 0xa, 0x10, 0xd, 0x10, 
    0xe, 0x10, 0xec, 0x3, 0x10, 0x7, 0x10, 0xf0, 0xa, 0x10, 0xc, 0x10, 0xe, 
    0x10, 0xf3, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xf8, 
    0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x6, 0x12, 0x100, 0xa, 0x12, 0xd, 0x12, 0xe, 0x12, 0x101, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x2, 0x2, 0x13, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
    0x2, 0x5, 0x3, 0x2, 0x12, 0x16, 0x4, 0x2, 0x12, 0x12, 0x17, 0x17, 0x4, 
    0x2, 0x5, 0x5, 0x7, 0x8, 0x2, 0x118, 0x2, 0x24, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x31, 0x3, 0x2, 0x2, 0x2, 0x6, 0x33, 0x3, 0x2, 0x2, 0x2, 0x8, 0x40, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x4c, 0x3, 0x2, 0x2, 0x2, 0xc, 0x4e, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x10, 0x65, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x67, 0x3, 0x2, 0x2, 0x2, 0x14, 0x6c, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x18, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0xb4, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xf7, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x22, 0xfb, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x25, 0x9, 0x2, 0x2, 0x2, 0x25, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x26, 0x32, 0x5, 0x2, 0x2, 0x2, 0x27, 0x32, 0x7, 0x17, 0x2, 
    0x2, 0x28, 0x32, 0x7, 0x18, 0x2, 0x2, 0x29, 0x2d, 0x7, 0x9, 0x2, 0x2, 
    0x2a, 0x2c, 0x5, 0x4, 0x3, 0x2, 0x2b, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0x30, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x32, 0x7, 0xa, 0x2, 0x2, 0x31, 0x26, 0x3, 0x2, 
    0x2, 0x2, 0x31, 0x27, 0x3, 0x2, 0x2, 0x2, 0x31, 0x28, 0x3, 0x2, 0x2, 
    0x2, 0x31, 0x29, 0x3, 0x2, 0x2, 0x2, 0x32, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x33, 0x34, 0x9, 0x3, 0x2, 0x2, 0x34, 0x7, 0x3, 0x2, 0x2, 0x2, 0x35, 
    0x41, 0x7, 0x17, 0x2, 0x2, 0x36, 0x37, 0x7, 0x9, 0x2, 0x2, 0x37, 0x38, 
    0x7, 0xb, 0x2, 0x2, 0x38, 0x3a, 0x7, 0x17, 0x2, 0x2, 0x39, 0x3b, 0x5, 
    0x6, 0x4, 0x2, 0x3a, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x3d, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0xa, 0x2, 0x2, 
    0x3f, 0x41, 0x3, 0x2, 0x2, 0x2, 0x40, 0x35, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x36, 0x3, 0x2, 0x2, 0x2, 0x41, 0x9, 0x3, 0x2, 0x2, 0x2, 0x42, 0x4d, 
    0x5, 0x2, 0x2, 0x2, 0x43, 0x4d, 0x7, 0x17, 0x2, 0x2, 0x44, 0x48, 0x7, 
    0x9, 0x2, 0x2, 0x45, 0x47, 0x5, 0x4, 0x3, 0x2, 0x46, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x47, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0x48, 0x49, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4d, 0x7, 0xa, 0x2, 0x2, 0x4c, 
    0x42, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x43, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x44, 
    0x3, 0x2, 0x2, 0x2, 0x4d, 0xb, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x50, 0x7, 
    0x18, 0x2, 0x2, 0x4f, 0x51, 0x5, 0xa, 0x6, 0x2, 0x50, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x50, 0x51, 0x3, 0x2, 0x2, 0x2, 0x51, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x5d, 0x5, 0x8, 0x5, 0x2, 0x53, 0x54, 0x7, 0x9, 0x2, 0x2, 
    0x54, 0x56, 0x5, 0x8, 0x5, 0x2, 0x55, 0x57, 0x5, 0xe, 0x8, 0x2, 0x56, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x56, 
    0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 
    0x2, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0xa, 0x2, 0x2, 0x5b, 0x5d, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x52, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x5d, 0xf, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x66, 0x5, 0x8, 0x5, 0x2, 
    0x5f, 0x60, 0x7, 0x9, 0x2, 0x2, 0x60, 0x61, 0x7, 0xd, 0x2, 0x2, 0x61, 
    0x62, 0x5, 0x8, 0x5, 0x2, 0x62, 0x63, 0x5, 0xe, 0x8, 0x2, 0x63, 0x64, 
    0x7, 0xa, 0x2, 0x2, 0x64, 0x66, 0x3, 0x2, 0x2, 0x2, 0x65, 0x5e, 0x3, 
    0x2, 0x2, 0x2, 0x65, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x66, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0x67, 0x68, 0x7, 0x9, 0x2, 0x2, 0x68, 0x69, 0x7, 0x17, 0x2, 
    0x2, 0x69, 0x6a, 0x5, 0x16, 0xc, 0x2, 0x6a, 0x6b, 0x7, 0xa, 0x2, 0x2, 
    0x6b, 0x13, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x9, 0x2, 0x2, 0x6d, 
    0x6e, 0x7, 0x17, 0x2, 0x2, 0x6e, 0x6f, 0x5, 0xe, 0x8, 0x2, 0x6f, 0x70, 
    0x7, 0xa, 0x2, 0x2, 0x70, 0x15, 0x3, 0x2, 0x2, 0x2, 0x71, 0xa8, 0x5, 
    0x2, 0x2, 0x2, 0x72, 0xa8, 0x5, 0x10, 0x9, 0x2, 0x73, 0x74, 0x7, 0x9, 
    0x2, 0x2, 0x74, 0x76, 0x5, 0x10, 0x9, 0x2, 0x75, 0x77, 0x5, 0x16, 0xc, 
    0x2, 0x76, 0x75, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x3, 0x2, 0x2, 0x2, 
    0x78, 0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 0x2, 0x2, 0x79, 
    0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0xa, 0x2, 0x2, 0x7b, 0xa8, 
    0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0x9, 0x2, 0x2, 0x7d, 0x7e, 0x7, 
    0xe, 0x2, 0x2, 0x7e, 0x80, 0x7, 0x9, 0x2, 0x2, 0x7f, 0x81, 0x5, 0x12, 
    0xa, 0x2, 0x80, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0x80, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 
    0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x7, 0xa, 0x2, 0x2, 0x85, 
    0x86, 0x7, 0xa, 0x2, 0x2, 0x86, 0xa8, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 
    0x7, 0x9, 0x2, 0x2, 0x88, 0x8a, 0x7, 0x10, 0x2, 0x2, 0x89, 0x8b, 0x5, 
    0x14, 0xb, 0x2, 0x8a, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 
    0x2, 0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x3, 0x2, 0x2, 
    0x2, 0x8d, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0x9, 0x2, 0x2, 
    0x8f, 0x90, 0x7, 0xa, 0x2, 0x2, 0x90, 0x91, 0x7, 0xa, 0x2, 0x2, 0x91, 
    0xa8, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x7, 0x9, 0x2, 0x2, 0x93, 0x95, 
    0x7, 0xf, 0x2, 0x2, 0x94, 0x96, 0x5, 0x14, 0xb, 0x2, 0x95, 0x94, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 
    0x2, 0x2, 0x97, 0x98, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x3, 0x2, 0x2, 
    0x2, 0x99, 0x9a, 0x7, 0x9, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0xa, 0x2, 0x2, 
    0x9b, 0x9c, 0x7, 0xa, 0x2, 0x2, 0x9c, 0xa8, 0x3, 0x2, 0x2, 0x2, 0x9d, 
    0x9e, 0x7, 0x9, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0xc, 0x2, 0x2, 0x9f, 0xa1, 
    0x5, 0x16, 0xc, 0x2, 0xa0, 0xa2, 0x5, 0xc, 0x7, 0x2, 0xa1, 0xa0, 0x3, 
    0x2, 0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa1, 0x3, 0x2, 
    0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 
    0x2, 0xa5, 0xa6, 0x7, 0xa, 0x2, 0x2, 0xa6, 0xa8, 0x3, 0x2, 0x2, 0x2, 
    0xa7, 0x71, 0x3, 0x2, 0x2, 0x2, 0xa7, 0x72, 0x3, 0x2, 0x2, 0x2, 0xa7, 
    0x73, 0x3, 0x2, 0x2, 0x2, 0xa7, 0x7c, 0x3, 0x2, 0x2, 0x2, 0xa7, 0x87, 
    0x3, 0x2, 0x2, 0x2, 0xa7, 0x92, 0x3, 0x2, 0x2, 0x2, 0xa7, 0x9d, 0x3, 
    0x2, 0x2, 0x2, 0xa8, 0x17, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x9, 
    0x2, 0x2, 0xaa, 0xab, 0x5, 0x8, 0x5, 0x2, 0xab, 0xaf, 0x7, 0x12, 0x2, 
    0x2, 0xac, 0xae, 0x5, 0xc, 0x7, 0x2, 0xad, 0xac, 0x3, 0x2, 0x2, 0x2, 
    0xae, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 
    0xb0, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xaf, 
    0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x7, 0xa, 0x2, 0x2, 0xb3, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0xb4, 0xb5, 0x9, 0x4, 0x2, 0x2, 0xb5, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0xb7, 0x7, 0x9, 0x2, 0x2, 0xb7, 0xb8, 0x5, 0x2, 0x2, 
    0x2, 0xb8, 0xbc, 0x5, 0xe, 0x8, 0x2, 0xb9, 0xbb, 0x5, 0xc, 0x7, 0x2, 
    0xba, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbc, 
    0xba, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbf, 
    0x3, 0x2, 0x2, 0x2, 0xbe, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x7, 
    0xa, 0x2, 0x2, 0xc0, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x9, 
    0x2, 0x2, 0xc2, 0xc3, 0x5, 0x1a, 0xe, 0x2, 0xc3, 0xc7, 0x5, 0xe, 0x8, 
    0x2, 0xc4, 0xc6, 0x5, 0xc, 0x7, 0x2, 0xc5, 0xc4, 0x3, 0x2, 0x2, 0x2, 
    0xc6, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 
    0xc8, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xca, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc7, 
    0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x7, 0xa, 0x2, 0x2, 0xcb, 0xdc, 0x3, 
    0x2, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x9, 0x2, 0x2, 0xcd, 0xcf, 0x5, 0x8, 
    0x5, 0x2, 0xce, 0xd0, 0x5, 0xe, 0x8, 0x2, 0xcf, 0xce, 0x3, 0x2, 0x2, 
    0x2, 0xd0, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xcf, 0x3, 0x2, 0x2, 0x2, 
    0xd1, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd3, 
    0xd5, 0x5, 0xc, 0x7, 0x2, 0xd4, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd8, 
    0x3, 0x2, 0x2, 0x2, 0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 
    0x2, 0x2, 0x2, 0xd7, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd6, 0x3, 0x2, 
    0x2, 0x2, 0xd9, 0xda, 0x7, 0xa, 0x2, 0x2, 0xda, 0xdc, 0x3, 0x2, 0x2, 
    0x2, 0xdb, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xc1, 0x3, 0x2, 0x2, 0x2, 
    0xdb, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xdc, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xdd, 
    0xf8, 0x5, 0x1c, 0xf, 0x2, 0xde, 0xdf, 0x7, 0x9, 0x2, 0x2, 0xdf, 0xe0, 
    0x7, 0x11, 0x2, 0x2, 0xe0, 0xe2, 0x7, 0x9, 0x2, 0x2, 0xe1, 0xe3, 0x7, 
    0x17, 0x2, 0x2, 0xe2, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x3, 0x2, 
    0x2, 0x2, 0xe4, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x3, 0x2, 0x2, 
    0x2, 0xe5, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x7, 0xa, 0x2, 0x2, 
    0xe7, 0xe8, 0x7, 0x9, 0x2, 0x2, 0xe8, 0xea, 0x5, 0x8, 0x5, 0x2, 0xe9, 
    0xeb, 0x5, 0xe, 0x8, 0x2, 0xea, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 
    0x3, 0x2, 0x2, 0x2, 0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 
    0x2, 0x2, 0x2, 0xed, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf0, 0x5, 0xc, 
    0x7, 0x2, 0xef, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf3, 0x3, 0x2, 0x2, 
    0x2, 0xf1, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x3, 0x2, 0x2, 0x2, 
    0xf2, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf4, 
    0xf5, 0x7, 0xa, 0x2, 0x2, 0xf5, 0xf6, 0x7, 0xa, 0x2, 0x2, 0xf6, 0xf8, 
    0x3, 0x2, 0x2, 0x2, 0xf7, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xde, 0x3, 
    0x2, 0x2, 0x2, 0xf8, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x5, 0xc, 
    0x7, 0x2, 0xfa, 0x21, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0x9, 0x2, 
    0x2, 0xfc, 0xfd, 0x7, 0x3, 0x2, 0x2, 0xfd, 0xff, 0x7, 0x17, 0x2, 0x2, 
    0xfe, 0x100, 0x5, 0x20, 0x11, 0x2, 0xff, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x100, 
    0x101, 0x3, 0x2, 0x2, 0x2, 0x101, 0xff, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 
    0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 
    0x7, 0xa, 0x2, 0x2, 0x104, 0x23, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x2d, 0x31, 
    0x3c, 0x40, 0x48, 0x4c, 0x50, 0x58, 0x5c, 0x65, 0x78, 0x82, 0x8c, 0x97, 
    0xa3, 0xa7, 0xaf, 0xbc, 0xc7, 0xd1, 0xd6, 0xdb, 0xe4, 0xec, 0xf1, 0xf7, 
    0x101, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

smtlibParser::Initializer smtlibParser::_init;
