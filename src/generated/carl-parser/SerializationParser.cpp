
// Generated from /home/travis/build/smtrat/carl-parser/src/carl-parser/Serialization.g4 by ANTLR 4.7


#include "SerializationListener.h"
#include "SerializationVisitor.h"

#include "SerializationParser.h"


using namespace antlrcpp;
using namespace carlparser;
using namespace antlr4;

SerializationParser::SerializationParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SerializationParser::~SerializationParser() {
  delete _interpreter;
}

std::string SerializationParser::getGrammarFileName() const {
  return "Serialization.g4";
}

const std::vector<std::string>& SerializationParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SerializationParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StartContext ------------------------------------------------------------------

SerializationParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SerializationParser::Carl_exprContext* SerializationParser::StartContext::carl_expr() {
  return getRuleContext<SerializationParser::Carl_exprContext>(0);
}

tree::TerminalNode* SerializationParser::StartContext::EOF() {
  return getToken(SerializationParser::EOF, 0);
}


size_t SerializationParser::StartContext::getRuleIndex() const {
  return SerializationParser::RuleStart;
}

void SerializationParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void SerializationParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}


antlrcpp::Any SerializationParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SerializationVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

SerializationParser::StartContext* SerializationParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, SerializationParser::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(28);
    carl_expr();
    setState(29);
    match(SerializationParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Carl_exprContext ------------------------------------------------------------------

SerializationParser::Carl_exprContext::Carl_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SerializationParser::Formula_naryContext* SerializationParser::Carl_exprContext::formula_nary() {
  return getRuleContext<SerializationParser::Formula_naryContext>(0);
}

SerializationParser::Formula_unaryContext* SerializationParser::Carl_exprContext::formula_unary() {
  return getRuleContext<SerializationParser::Formula_unaryContext>(0);
}

SerializationParser::ConstraintContext* SerializationParser::Carl_exprContext::constraint() {
  return getRuleContext<SerializationParser::ConstraintContext>(0);
}

SerializationParser::Arith_naryContext* SerializationParser::Carl_exprContext::arith_nary() {
  return getRuleContext<SerializationParser::Arith_naryContext>(0);
}

SerializationParser::Arith_unaryContext* SerializationParser::Carl_exprContext::arith_unary() {
  return getRuleContext<SerializationParser::Arith_unaryContext>(0);
}

SerializationParser::BooleanContext* SerializationParser::Carl_exprContext::boolean() {
  return getRuleContext<SerializationParser::BooleanContext>(0);
}

SerializationParser::NumberContext* SerializationParser::Carl_exprContext::number() {
  return getRuleContext<SerializationParser::NumberContext>(0);
}

SerializationParser::Real_variableContext* SerializationParser::Carl_exprContext::real_variable() {
  return getRuleContext<SerializationParser::Real_variableContext>(0);
}


size_t SerializationParser::Carl_exprContext::getRuleIndex() const {
  return SerializationParser::RuleCarl_expr;
}

void SerializationParser::Carl_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCarl_expr(this);
}

void SerializationParser::Carl_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCarl_expr(this);
}


antlrcpp::Any SerializationParser::Carl_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SerializationVisitor*>(visitor))
    return parserVisitor->visitCarl_expr(this);
  else
    return visitor->visitChildren(this);
}

SerializationParser::Carl_exprContext* SerializationParser::carl_expr() {
  Carl_exprContext *_localctx = _tracker.createInstance<Carl_exprContext>(_ctx, getState());
  enterRule(_localctx, 2, SerializationParser::RuleCarl_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(39);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(31);
      formula_nary();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(32);
      formula_unary();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(33);
      constraint();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(34);
      arith_nary();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(35);
      arith_unary();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(36);
      boolean();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(37);
      number();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(38);
      real_variable();
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

//----------------- Form_exprContext ------------------------------------------------------------------

SerializationParser::Form_exprContext::Form_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SerializationParser::Formula_naryContext* SerializationParser::Form_exprContext::formula_nary() {
  return getRuleContext<SerializationParser::Formula_naryContext>(0);
}

SerializationParser::Formula_unaryContext* SerializationParser::Form_exprContext::formula_unary() {
  return getRuleContext<SerializationParser::Formula_unaryContext>(0);
}

SerializationParser::ConstraintContext* SerializationParser::Form_exprContext::constraint() {
  return getRuleContext<SerializationParser::ConstraintContext>(0);
}

SerializationParser::BooleanContext* SerializationParser::Form_exprContext::boolean() {
  return getRuleContext<SerializationParser::BooleanContext>(0);
}

SerializationParser::Bool_variableContext* SerializationParser::Form_exprContext::bool_variable() {
  return getRuleContext<SerializationParser::Bool_variableContext>(0);
}


size_t SerializationParser::Form_exprContext::getRuleIndex() const {
  return SerializationParser::RuleForm_expr;
}

void SerializationParser::Form_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForm_expr(this);
}

void SerializationParser::Form_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForm_expr(this);
}


antlrcpp::Any SerializationParser::Form_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SerializationVisitor*>(visitor))
    return parserVisitor->visitForm_expr(this);
  else
    return visitor->visitChildren(this);
}

SerializationParser::Form_exprContext* SerializationParser::form_expr() {
  Form_exprContext *_localctx = _tracker.createInstance<Form_exprContext>(_ctx, getState());
  enterRule(_localctx, 4, SerializationParser::RuleForm_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(46);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(41);
      formula_nary();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(42);
      formula_unary();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(43);
      constraint();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(44);
      boolean();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(45);
      bool_variable();
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

//----------------- Formula_naryContext ------------------------------------------------------------------

SerializationParser::Formula_naryContext::Formula_naryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SerializationParser::Formula_naryContext::LPAREN() {
  return getToken(SerializationParser::LPAREN, 0);
}

SerializationParser::Form_op_naryContext* SerializationParser::Formula_naryContext::form_op_nary() {
  return getRuleContext<SerializationParser::Form_op_naryContext>(0);
}

tree::TerminalNode* SerializationParser::Formula_naryContext::RPAREN() {
  return getToken(SerializationParser::RPAREN, 0);
}

std::vector<SerializationParser::Form_exprContext *> SerializationParser::Formula_naryContext::form_expr() {
  return getRuleContexts<SerializationParser::Form_exprContext>();
}

SerializationParser::Form_exprContext* SerializationParser::Formula_naryContext::form_expr(size_t i) {
  return getRuleContext<SerializationParser::Form_exprContext>(i);
}


size_t SerializationParser::Formula_naryContext::getRuleIndex() const {
  return SerializationParser::RuleFormula_nary;
}

void SerializationParser::Formula_naryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormula_nary(this);
}

void SerializationParser::Formula_naryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormula_nary(this);
}


antlrcpp::Any SerializationParser::Formula_naryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SerializationVisitor*>(visitor))
    return parserVisitor->visitFormula_nary(this);
  else
    return visitor->visitChildren(this);
}

SerializationParser::Formula_naryContext* SerializationParser::formula_nary() {
  Formula_naryContext *_localctx = _tracker.createInstance<Formula_naryContext>(_ctx, getState());
  enterRule(_localctx, 6, SerializationParser::RuleFormula_nary);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    match(SerializationParser::LPAREN);
    setState(49);
    form_op_nary();
    setState(51); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(50);
      form_expr();
      setState(53); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SerializationParser::LPAREN)
      | (1ULL << SerializationParser::TRUE)
      | (1ULL << SerializationParser::FALSE)
      | (1ULL << SerializationParser::SYMBOL))) != 0));
    setState(55);
    match(SerializationParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Form_op_naryContext ------------------------------------------------------------------

SerializationParser::Form_op_naryContext::Form_op_naryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SerializationParser::Form_op_naryContext::getRuleIndex() const {
  return SerializationParser::RuleForm_op_nary;
}

void SerializationParser::Form_op_naryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForm_op_nary(this);
}

void SerializationParser::Form_op_naryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForm_op_nary(this);
}


antlrcpp::Any SerializationParser::Form_op_naryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SerializationVisitor*>(visitor))
    return parserVisitor->visitForm_op_nary(this);
  else
    return visitor->visitChildren(this);
}

SerializationParser::Form_op_naryContext* SerializationParser::form_op_nary() {
  Form_op_naryContext *_localctx = _tracker.createInstance<Form_op_naryContext>(_ctx, getState());
  enterRule(_localctx, 8, SerializationParser::RuleForm_op_nary);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SerializationParser::T__0)
      | (1ULL << SerializationParser::T__1)
      | (1ULL << SerializationParser::T__2)
      | (1ULL << SerializationParser::T__3)
      | (1ULL << SerializationParser::T__4)
      | (1ULL << SerializationParser::T__5))) != 0))) {
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

//----------------- Formula_unaryContext ------------------------------------------------------------------

SerializationParser::Formula_unaryContext::Formula_unaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SerializationParser::Formula_unaryContext::LPAREN() {
  return getToken(SerializationParser::LPAREN, 0);
}

SerializationParser::Form_exprContext* SerializationParser::Formula_unaryContext::form_expr() {
  return getRuleContext<SerializationParser::Form_exprContext>(0);
}

tree::TerminalNode* SerializationParser::Formula_unaryContext::RPAREN() {
  return getToken(SerializationParser::RPAREN, 0);
}


size_t SerializationParser::Formula_unaryContext::getRuleIndex() const {
  return SerializationParser::RuleFormula_unary;
}

void SerializationParser::Formula_unaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormula_unary(this);
}

void SerializationParser::Formula_unaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormula_unary(this);
}


antlrcpp::Any SerializationParser::Formula_unaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SerializationVisitor*>(visitor))
    return parserVisitor->visitFormula_unary(this);
  else
    return visitor->visitChildren(this);
}

SerializationParser::Formula_unaryContext* SerializationParser::formula_unary() {
  Formula_unaryContext *_localctx = _tracker.createInstance<Formula_unaryContext>(_ctx, getState());
  enterRule(_localctx, 10, SerializationParser::RuleFormula_unary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    match(SerializationParser::LPAREN);
    setState(60);
    dynamic_cast<Formula_unaryContext *>(_localctx)->token = match(SerializationParser::T__6);
    setState(61);
    form_expr();
    setState(62);
    match(SerializationParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstraintContext ------------------------------------------------------------------

SerializationParser::ConstraintContext::ConstraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SerializationParser::ConstraintContext::LPAREN() {
  return getToken(SerializationParser::LPAREN, 0);
}

std::vector<SerializationParser::Arith_exprContext *> SerializationParser::ConstraintContext::arith_expr() {
  return getRuleContexts<SerializationParser::Arith_exprContext>();
}

SerializationParser::Arith_exprContext* SerializationParser::ConstraintContext::arith_expr(size_t i) {
  return getRuleContext<SerializationParser::Arith_exprContext>(i);
}

tree::TerminalNode* SerializationParser::ConstraintContext::RPAREN() {
  return getToken(SerializationParser::RPAREN, 0);
}


size_t SerializationParser::ConstraintContext::getRuleIndex() const {
  return SerializationParser::RuleConstraint;
}

void SerializationParser::ConstraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstraint(this);
}

void SerializationParser::ConstraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstraint(this);
}


antlrcpp::Any SerializationParser::ConstraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SerializationVisitor*>(visitor))
    return parserVisitor->visitConstraint(this);
  else
    return visitor->visitChildren(this);
}

SerializationParser::ConstraintContext* SerializationParser::constraint() {
  ConstraintContext *_localctx = _tracker.createInstance<ConstraintContext>(_ctx, getState());
  enterRule(_localctx, 12, SerializationParser::RuleConstraint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    match(SerializationParser::LPAREN);
    setState(65);
    dynamic_cast<ConstraintContext *>(_localctx)->token = _input->LT(1);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SerializationParser::T__2)
      | (1ULL << SerializationParser::T__7)
      | (1ULL << SerializationParser::T__8)
      | (1ULL << SerializationParser::T__9)
      | (1ULL << SerializationParser::T__10)
      | (1ULL << SerializationParser::T__11))) != 0))) {
      dynamic_cast<ConstraintContext *>(_localctx)->token = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(66);
    dynamic_cast<ConstraintContext *>(_localctx)->left = arith_expr();
    setState(67);
    arith_expr();
    setState(68);
    match(SerializationParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arith_exprContext ------------------------------------------------------------------

SerializationParser::Arith_exprContext::Arith_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SerializationParser::Arith_naryContext* SerializationParser::Arith_exprContext::arith_nary() {
  return getRuleContext<SerializationParser::Arith_naryContext>(0);
}

SerializationParser::Arith_unaryContext* SerializationParser::Arith_exprContext::arith_unary() {
  return getRuleContext<SerializationParser::Arith_unaryContext>(0);
}

SerializationParser::NumberContext* SerializationParser::Arith_exprContext::number() {
  return getRuleContext<SerializationParser::NumberContext>(0);
}

SerializationParser::Real_variableContext* SerializationParser::Arith_exprContext::real_variable() {
  return getRuleContext<SerializationParser::Real_variableContext>(0);
}


size_t SerializationParser::Arith_exprContext::getRuleIndex() const {
  return SerializationParser::RuleArith_expr;
}

void SerializationParser::Arith_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArith_expr(this);
}

void SerializationParser::Arith_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArith_expr(this);
}


antlrcpp::Any SerializationParser::Arith_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SerializationVisitor*>(visitor))
    return parserVisitor->visitArith_expr(this);
  else
    return visitor->visitChildren(this);
}

SerializationParser::Arith_exprContext* SerializationParser::arith_expr() {
  Arith_exprContext *_localctx = _tracker.createInstance<Arith_exprContext>(_ctx, getState());
  enterRule(_localctx, 14, SerializationParser::RuleArith_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(74);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(70);
      arith_nary();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(71);
      arith_unary();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(72);
      number();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(73);
      real_variable();
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

//----------------- Arith_unaryContext ------------------------------------------------------------------

SerializationParser::Arith_unaryContext::Arith_unaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SerializationParser::Arith_unaryContext::LPAREN() {
  return getToken(SerializationParser::LPAREN, 0);
}

SerializationParser::Arith_exprContext* SerializationParser::Arith_unaryContext::arith_expr() {
  return getRuleContext<SerializationParser::Arith_exprContext>(0);
}

tree::TerminalNode* SerializationParser::Arith_unaryContext::RPAREN() {
  return getToken(SerializationParser::RPAREN, 0);
}


size_t SerializationParser::Arith_unaryContext::getRuleIndex() const {
  return SerializationParser::RuleArith_unary;
}

void SerializationParser::Arith_unaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArith_unary(this);
}

void SerializationParser::Arith_unaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArith_unary(this);
}


antlrcpp::Any SerializationParser::Arith_unaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SerializationVisitor*>(visitor))
    return parserVisitor->visitArith_unary(this);
  else
    return visitor->visitChildren(this);
}

SerializationParser::Arith_unaryContext* SerializationParser::arith_unary() {
  Arith_unaryContext *_localctx = _tracker.createInstance<Arith_unaryContext>(_ctx, getState());
  enterRule(_localctx, 16, SerializationParser::RuleArith_unary);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    match(SerializationParser::LPAREN);
    setState(77);
    dynamic_cast<Arith_unaryContext *>(_localctx)->token = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == SerializationParser::T__12

    || _la == SerializationParser::T__13)) {
      dynamic_cast<Arith_unaryContext *>(_localctx)->token = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(78);
    arith_expr();
    setState(79);
    match(SerializationParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arith_naryContext ------------------------------------------------------------------

SerializationParser::Arith_naryContext::Arith_naryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SerializationParser::Arith_naryContext::LPAREN() {
  return getToken(SerializationParser::LPAREN, 0);
}

std::vector<SerializationParser::Arith_exprContext *> SerializationParser::Arith_naryContext::arith_expr() {
  return getRuleContexts<SerializationParser::Arith_exprContext>();
}

SerializationParser::Arith_exprContext* SerializationParser::Arith_naryContext::arith_expr(size_t i) {
  return getRuleContext<SerializationParser::Arith_exprContext>(i);
}

tree::TerminalNode* SerializationParser::Arith_naryContext::RPAREN() {
  return getToken(SerializationParser::RPAREN, 0);
}


size_t SerializationParser::Arith_naryContext::getRuleIndex() const {
  return SerializationParser::RuleArith_nary;
}

void SerializationParser::Arith_naryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArith_nary(this);
}

void SerializationParser::Arith_naryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArith_nary(this);
}


antlrcpp::Any SerializationParser::Arith_naryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SerializationVisitor*>(visitor))
    return parserVisitor->visitArith_nary(this);
  else
    return visitor->visitChildren(this);
}

SerializationParser::Arith_naryContext* SerializationParser::arith_nary() {
  Arith_naryContext *_localctx = _tracker.createInstance<Arith_naryContext>(_ctx, getState());
  enterRule(_localctx, 18, SerializationParser::RuleArith_nary);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(81);
    match(SerializationParser::LPAREN);
    setState(82);
    dynamic_cast<Arith_naryContext *>(_localctx)->token = _input->LT(1);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SerializationParser::T__12)
      | (1ULL << SerializationParser::T__13)
      | (1ULL << SerializationParser::T__14)
      | (1ULL << SerializationParser::T__15))) != 0))) {
      dynamic_cast<Arith_naryContext *>(_localctx)->token = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(83);
    arith_expr();
    setState(85); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(84);
      arith_expr();
      setState(87); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SerializationParser::LPAREN)
      | (1ULL << SerializationParser::NUMERAL)
      | (1ULL << SerializationParser::DECIMAL)
      | (1ULL << SerializationParser::HEXADECIMAL)
      | (1ULL << SerializationParser::BINARY)
      | (1ULL << SerializationParser::SYMBOL))) != 0));
    setState(89);
    match(SerializationParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanContext ------------------------------------------------------------------

SerializationParser::BooleanContext::BooleanContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SerializationParser::BooleanContext::TRUE() {
  return getToken(SerializationParser::TRUE, 0);
}

tree::TerminalNode* SerializationParser::BooleanContext::FALSE() {
  return getToken(SerializationParser::FALSE, 0);
}


size_t SerializationParser::BooleanContext::getRuleIndex() const {
  return SerializationParser::RuleBoolean;
}

void SerializationParser::BooleanContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolean(this);
}

void SerializationParser::BooleanContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolean(this);
}


antlrcpp::Any SerializationParser::BooleanContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SerializationVisitor*>(visitor))
    return parserVisitor->visitBoolean(this);
  else
    return visitor->visitChildren(this);
}

SerializationParser::BooleanContext* SerializationParser::boolean() {
  BooleanContext *_localctx = _tracker.createInstance<BooleanContext>(_ctx, getState());
  enterRule(_localctx, 20, SerializationParser::RuleBoolean);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
    _la = _input->LA(1);
    if (!(_la == SerializationParser::TRUE

    || _la == SerializationParser::FALSE)) {
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

//----------------- NumberContext ------------------------------------------------------------------

SerializationParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SerializationParser::NumberContext::NUMERAL() {
  return getToken(SerializationParser::NUMERAL, 0);
}

tree::TerminalNode* SerializationParser::NumberContext::DECIMAL() {
  return getToken(SerializationParser::DECIMAL, 0);
}

tree::TerminalNode* SerializationParser::NumberContext::HEXADECIMAL() {
  return getToken(SerializationParser::HEXADECIMAL, 0);
}

tree::TerminalNode* SerializationParser::NumberContext::BINARY() {
  return getToken(SerializationParser::BINARY, 0);
}


size_t SerializationParser::NumberContext::getRuleIndex() const {
  return SerializationParser::RuleNumber;
}

void SerializationParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void SerializationParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}


antlrcpp::Any SerializationParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SerializationVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

SerializationParser::NumberContext* SerializationParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 22, SerializationParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SerializationParser::NUMERAL)
      | (1ULL << SerializationParser::DECIMAL)
      | (1ULL << SerializationParser::HEXADECIMAL)
      | (1ULL << SerializationParser::BINARY))) != 0))) {
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

//----------------- Real_variableContext ------------------------------------------------------------------

SerializationParser::Real_variableContext::Real_variableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SerializationParser::Real_variableContext::SYMBOL() {
  return getToken(SerializationParser::SYMBOL, 0);
}


size_t SerializationParser::Real_variableContext::getRuleIndex() const {
  return SerializationParser::RuleReal_variable;
}

void SerializationParser::Real_variableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReal_variable(this);
}

void SerializationParser::Real_variableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReal_variable(this);
}


antlrcpp::Any SerializationParser::Real_variableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SerializationVisitor*>(visitor))
    return parserVisitor->visitReal_variable(this);
  else
    return visitor->visitChildren(this);
}

SerializationParser::Real_variableContext* SerializationParser::real_variable() {
  Real_variableContext *_localctx = _tracker.createInstance<Real_variableContext>(_ctx, getState());
  enterRule(_localctx, 24, SerializationParser::RuleReal_variable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    match(SerializationParser::SYMBOL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bool_variableContext ------------------------------------------------------------------

SerializationParser::Bool_variableContext::Bool_variableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SerializationParser::Bool_variableContext::SYMBOL() {
  return getToken(SerializationParser::SYMBOL, 0);
}


size_t SerializationParser::Bool_variableContext::getRuleIndex() const {
  return SerializationParser::RuleBool_variable;
}

void SerializationParser::Bool_variableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBool_variable(this);
}

void SerializationParser::Bool_variableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SerializationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBool_variable(this);
}


antlrcpp::Any SerializationParser::Bool_variableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SerializationVisitor*>(visitor))
    return parserVisitor->visitBool_variable(this);
  else
    return visitor->visitChildren(this);
}

SerializationParser::Bool_variableContext* SerializationParser::bool_variable() {
  Bool_variableContext *_localctx = _tracker.createInstance<Bool_variableContext>(_ctx, getState());
  enterRule(_localctx, 26, SerializationParser::RuleBool_variable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    match(SerializationParser::SYMBOL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> SerializationParser::_decisionToDFA;
atn::PredictionContextCache SerializationParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SerializationParser::_atn;
std::vector<uint16_t> SerializationParser::_serializedATN;

std::vector<std::string> SerializationParser::_ruleNames = {
  "start", "carl_expr", "form_expr", "formula_nary", "form_op_nary", "formula_unary", 
  "constraint", "arith_expr", "arith_unary", "arith_nary", "boolean", "number", 
  "real_variable", "bool_variable"
};

std::vector<std::string> SerializationParser::_literalNames = {
  "", "'and'", "'or'", "'='", "'xor'", "'=>'", "'ite'", "'not'", "'<'", 
  "'<='", "'>'", "'>='", "'!='", "'+'", "'-'", "'*'", "'/'", "'BINARY'", 
  "'DECIMAL'", "'HEXADECIMAL'", "'NUMERAL'", "'STRING'", "'('", "')'", "'_'", 
  "'!'", "'as'", "'let'", "'exists'", "'forall'", "'par'", "'true'", "'false'"
};

std::vector<std::string> SerializationParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "TBINARY", 
  "TDECIMAL", "THEXADECIMAL", "TNUMERAL", "TSTRING", "LPAREN", "RPAREN", 
  "INDEXER", "ANNOTATION", "AS", "LET", "EXISTS", "FORALL", "PAR", "TRUE", 
  "FALSE", "NUMERAL", "DECIMAL", "HEXADECIMAL", "BINARY", "STRING", "SYMBOL", 
  "KEYWORD", "WS"
};

dfa::Vocabulary SerializationParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SerializationParser::_tokenNames;

SerializationParser::Initializer::Initializer() {
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
    0x3, 0x2a, 0x66, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2a, 
    0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x31, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x6, 0x5, 0x36, 0xa, 0x5, 
    0xd, 0x5, 0xe, 0x5, 0x37, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x5, 0x9, 0x4d, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x6, 0xb, 0x58, 0xa, 
    0xb, 0xd, 0xb, 0xe, 0xb, 0x59, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x2, 0x2, 0x10, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x2, 0x8, 0x3, 0x2, 0x3, 0x8, 0x4, 0x2, 0x5, 
    0x5, 0xa, 0xe, 0x3, 0x2, 0xf, 0x10, 0x3, 0x2, 0xf, 0x12, 0x3, 0x2, 0x21, 
    0x22, 0x3, 0x2, 0x23, 0x26, 0x2, 0x67, 0x2, 0x1e, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x29, 0x3, 0x2, 0x2, 0x2, 0x6, 0x30, 0x3, 0x2, 0x2, 0x2, 0x8, 0x32, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x3b, 0x3, 0x2, 0x2, 0x2, 0xc, 0x3d, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x42, 0x3, 0x2, 0x2, 0x2, 0x10, 0x4c, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x14, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x18, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x61, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x63, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 
    0x5, 0x4, 0x3, 0x2, 0x1f, 0x20, 0x7, 0x2, 0x2, 0x3, 0x20, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x21, 0x2a, 0x5, 0x8, 0x5, 0x2, 0x22, 0x2a, 0x5, 0xc, 
    0x7, 0x2, 0x23, 0x2a, 0x5, 0xe, 0x8, 0x2, 0x24, 0x2a, 0x5, 0x14, 0xb, 
    0x2, 0x25, 0x2a, 0x5, 0x12, 0xa, 0x2, 0x26, 0x2a, 0x5, 0x16, 0xc, 0x2, 
    0x27, 0x2a, 0x5, 0x18, 0xd, 0x2, 0x28, 0x2a, 0x5, 0x1a, 0xe, 0x2, 0x29, 
    0x21, 0x3, 0x2, 0x2, 0x2, 0x29, 0x22, 0x3, 0x2, 0x2, 0x2, 0x29, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0x29, 0x24, 0x3, 0x2, 0x2, 0x2, 0x29, 0x25, 0x3, 
    0x2, 0x2, 0x2, 0x29, 0x26, 0x3, 0x2, 0x2, 0x2, 0x29, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x29, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x2b, 0x31, 0x5, 0x8, 0x5, 0x2, 0x2c, 0x31, 0x5, 0xc, 0x7, 0x2, 
    0x2d, 0x31, 0x5, 0xe, 0x8, 0x2, 0x2e, 0x31, 0x5, 0x16, 0xc, 0x2, 0x2f, 
    0x31, 0x5, 0x1c, 0xf, 0x2, 0x30, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2c, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2e, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x33, 0x7, 0x18, 0x2, 0x2, 0x33, 0x35, 0x5, 0xa, 0x6, 
    0x2, 0x34, 0x36, 0x5, 0x6, 0x4, 0x2, 0x35, 0x34, 0x3, 0x2, 0x2, 0x2, 
    0x36, 0x37, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x37, 
    0x38, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 
    0x7, 0x19, 0x2, 0x2, 0x3a, 0x9, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x9, 
    0x2, 0x2, 0x2, 0x3c, 0xb, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0x18, 
    0x2, 0x2, 0x3e, 0x3f, 0x7, 0x9, 0x2, 0x2, 0x3f, 0x40, 0x5, 0x6, 0x4, 
    0x2, 0x40, 0x41, 0x7, 0x19, 0x2, 0x2, 0x41, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x43, 0x7, 0x18, 0x2, 0x2, 0x43, 0x44, 0x9, 0x3, 0x2, 0x2, 0x44, 
    0x45, 0x5, 0x10, 0x9, 0x2, 0x45, 0x46, 0x5, 0x10, 0x9, 0x2, 0x46, 0x47, 
    0x7, 0x19, 0x2, 0x2, 0x47, 0xf, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4d, 0x5, 
    0x14, 0xb, 0x2, 0x49, 0x4d, 0x5, 0x12, 0xa, 0x2, 0x4a, 0x4d, 0x5, 0x18, 
    0xd, 0x2, 0x4b, 0x4d, 0x5, 0x1a, 0xe, 0x2, 0x4c, 0x48, 0x3, 0x2, 0x2, 
    0x2, 0x4c, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x11, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x4f, 0x7, 0x18, 0x2, 0x2, 0x4f, 0x50, 0x9, 0x4, 0x2, 0x2, 0x50, 0x51, 
    0x5, 0x10, 0x9, 0x2, 0x51, 0x52, 0x7, 0x19, 0x2, 0x2, 0x52, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0x18, 0x2, 0x2, 0x54, 0x55, 0x9, 0x5, 
    0x2, 0x2, 0x55, 0x57, 0x5, 0x10, 0x9, 0x2, 0x56, 0x58, 0x5, 0x10, 0x9, 
    0x2, 0x57, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 0x2, 0x2, 
    0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0x19, 0x2, 0x2, 0x5c, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x9, 0x6, 0x2, 0x2, 0x5e, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x5f, 0x60, 0x9, 0x7, 0x2, 0x2, 0x60, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x61, 0x62, 0x7, 0x28, 0x2, 0x2, 0x62, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x63, 0x64, 0x7, 0x28, 0x2, 0x2, 0x64, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x7, 0x29, 0x30, 0x37, 0x4c, 0x59, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SerializationParser::Initializer SerializationParser::_init;
