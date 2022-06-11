
// Generated from LI.g4 by ANTLR 4.9.2


#include "LIVisitor.h"

#include "LIParser.h"


using namespace antlrcpp;
using namespace LI;
using namespace antlr4;

LIParser::LIParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

LIParser::~LIParser() {
  delete _interpreter;
}

std::string LIParser::getGrammarFileName() const {
  return "LI.g4";
}

const std::vector<std::string>& LIParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& LIParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- PtgContext ------------------------------------------------------------------

LIParser::PtgContext::PtgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LIParser::PtgContext::NEWLINE() {
  return getToken(LIParser::NEWLINE, 0);
}

tree::TerminalNode* LIParser::PtgContext::EOF() {
  return getToken(LIParser::EOF, 0);
}

std::vector<LIParser::EntryContext *> LIParser::PtgContext::entry() {
  return getRuleContexts<LIParser::EntryContext>();
}

LIParser::EntryContext* LIParser::PtgContext::entry(size_t i) {
  return getRuleContext<LIParser::EntryContext>(i);
}


size_t LIParser::PtgContext::getRuleIndex() const {
  return LIParser::RulePtg;
}


antlrcpp::Any LIParser::PtgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LIVisitor*>(visitor))
    return parserVisitor->visitPtg(this);
  else
    return visitor->visitChildren(this);
}

LIParser::PtgContext* LIParser::ptg() {
  PtgContext *_localctx = _tracker.createInstance<PtgContext>(_ctx, getState());
  enterRule(_localctx, 0, LIParser::RulePtg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(34);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LIParser::NUMS) {
      setState(26);
      entry();
      setState(31);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == LIParser::T__0) {
        setState(27);
        match(LIParser::T__0);
        setState(28);
        entry();
        setState(33);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(36);
    _la = _input->LA(1);
    if (!(_la == LIParser::EOF

    || _la == LIParser::NEWLINE)) {
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

//----------------- EntryContext ------------------------------------------------------------------

LIParser::EntryContext::EntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LIParser::BciKeyContext* LIParser::EntryContext::bciKey() {
  return getRuleContext<LIParser::BciKeyContext>(0);
}

LIParser::VarsContext* LIParser::EntryContext::vars() {
  return getRuleContext<LIParser::VarsContext>(0);
}

LIParser::FieldsContext* LIParser::EntryContext::fields() {
  return getRuleContext<LIParser::FieldsContext>(0);
}


size_t LIParser::EntryContext::getRuleIndex() const {
  return LIParser::RuleEntry;
}


antlrcpp::Any LIParser::EntryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LIVisitor*>(visitor))
    return parserVisitor->visitEntry(this);
  else
    return visitor->visitChildren(this);
}

LIParser::EntryContext* LIParser::entry() {
  EntryContext *_localctx = _tracker.createInstance<EntryContext>(_ctx, getState());
  enterRule(_localctx, 2, LIParser::RuleEntry);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    bciKey();
    setState(39);
    match(LIParser::T__1);
    setState(40);
    match(LIParser::T__2);
    setState(41);
    vars();
    setState(42);
    match(LIParser::T__3);
    setState(47);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LIParser::T__2) {
      setState(43);
      match(LIParser::T__2);
      setState(44);
      fields();
      setState(45);
      match(LIParser::T__3);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarsContext ------------------------------------------------------------------

LIParser::VarsContext::VarsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LIParser::VarentryContext *> LIParser::VarsContext::varentry() {
  return getRuleContexts<LIParser::VarentryContext>();
}

LIParser::VarentryContext* LIParser::VarsContext::varentry(size_t i) {
  return getRuleContext<LIParser::VarentryContext>(i);
}


size_t LIParser::VarsContext::getRuleIndex() const {
  return LIParser::RuleVars;
}


antlrcpp::Any LIParser::VarsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LIVisitor*>(visitor))
    return parserVisitor->visitVars(this);
  else
    return visitor->visitChildren(this);
}

LIParser::VarsContext* LIParser::vars() {
  VarsContext *_localctx = _tracker.createInstance<VarsContext>(_ctx, getState());
  enterRule(_localctx, 4, LIParser::RuleVars);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LIParser::NUMS) {
      setState(49);
      varentry();
      setState(54);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == LIParser::T__4) {
        setState(50);
        match(LIParser::T__4);
        setState(51);
        varentry();
        setState(56);
        _errHandler->sync(this);
        _la = _input->LA(1);
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

//----------------- VarentryContext ------------------------------------------------------------------

LIParser::VarentryContext::VarentryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LIParser::BciKeyContext* LIParser::VarentryContext::bciKey() {
  return getRuleContext<LIParser::BciKeyContext>(0);
}

std::vector<LIParser::CiBciEntryContext *> LIParser::VarentryContext::ciBciEntry() {
  return getRuleContexts<LIParser::CiBciEntryContext>();
}

LIParser::CiBciEntryContext* LIParser::VarentryContext::ciBciEntry(size_t i) {
  return getRuleContext<LIParser::CiBciEntryContext>(i);
}


size_t LIParser::VarentryContext::getRuleIndex() const {
  return LIParser::RuleVarentry;
}


antlrcpp::Any LIParser::VarentryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LIVisitor*>(visitor))
    return parserVisitor->visitVarentry(this);
  else
    return visitor->visitChildren(this);
}

LIParser::VarentryContext* LIParser::varentry() {
  VarentryContext *_localctx = _tracker.createInstance<VarentryContext>(_ctx, getState());
  enterRule(_localctx, 6, LIParser::RuleVarentry);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    bciKey();
    setState(60);
    match(LIParser::T__1);

    setState(61);
    ciBciEntry();
    setState(66);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LIParser::T__5) {
      setState(62);
      match(LIParser::T__5);

      setState(63);
      ciBciEntry();
      setState(68);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldsContext ------------------------------------------------------------------

LIParser::FieldsContext::FieldsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LIParser::FieldentryContext *> LIParser::FieldsContext::fieldentry() {
  return getRuleContexts<LIParser::FieldentryContext>();
}

LIParser::FieldentryContext* LIParser::FieldsContext::fieldentry(size_t i) {
  return getRuleContext<LIParser::FieldentryContext>(i);
}


size_t LIParser::FieldsContext::getRuleIndex() const {
  return LIParser::RuleFields;
}


antlrcpp::Any LIParser::FieldsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LIVisitor*>(visitor))
    return parserVisitor->visitFields(this);
  else
    return visitor->visitChildren(this);
}

LIParser::FieldsContext* LIParser::fields() {
  FieldsContext *_localctx = _tracker.createInstance<FieldsContext>(_ctx, getState());
  enterRule(_localctx, 8, LIParser::RuleFields);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LIParser::NUMS) {
      setState(69);
      fieldentry();
      setState(74);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == LIParser::T__4) {
        setState(70);
        match(LIParser::T__4);
        setState(71);
        fieldentry();
        setState(76);
        _errHandler->sync(this);
        _la = _input->LA(1);
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

//----------------- FieldentryContext ------------------------------------------------------------------

LIParser::FieldentryContext::FieldentryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LIParser::CallerIndexContext* LIParser::FieldentryContext::callerIndex() {
  return getRuleContext<LIParser::CallerIndexContext>(0);
}

LIParser::BciKeyContext* LIParser::FieldentryContext::bciKey() {
  return getRuleContext<LIParser::BciKeyContext>(0);
}

std::vector<LIParser::FieldContext *> LIParser::FieldentryContext::field() {
  return getRuleContexts<LIParser::FieldContext>();
}

LIParser::FieldContext* LIParser::FieldentryContext::field(size_t i) {
  return getRuleContext<LIParser::FieldContext>(i);
}


size_t LIParser::FieldentryContext::getRuleIndex() const {
  return LIParser::RuleFieldentry;
}


antlrcpp::Any LIParser::FieldentryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LIVisitor*>(visitor))
    return parserVisitor->visitFieldentry(this);
  else
    return visitor->visitChildren(this);
}

LIParser::FieldentryContext* LIParser::fieldentry() {
  FieldentryContext *_localctx = _tracker.createInstance<FieldentryContext>(_ctx, getState());
  enterRule(_localctx, 10, LIParser::RuleFieldentry);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    callerIndex();
    setState(80);
    match(LIParser::T__6);
    setState(81);
    bciKey();
    setState(82);
    match(LIParser::T__2);

    setState(83);
    field();

    setState(88);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LIParser::T__4) {
      setState(84);
      match(LIParser::T__4);

      setState(85);
      field();
      setState(90);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(91);
    match(LIParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldContext ------------------------------------------------------------------

LIParser::FieldContext::FieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LIParser::FieldKeyContext* LIParser::FieldContext::fieldKey() {
  return getRuleContext<LIParser::FieldKeyContext>(0);
}

std::vector<LIParser::CiBciEntryContext *> LIParser::FieldContext::ciBciEntry() {
  return getRuleContexts<LIParser::CiBciEntryContext>();
}

LIParser::CiBciEntryContext* LIParser::FieldContext::ciBciEntry(size_t i) {
  return getRuleContext<LIParser::CiBciEntryContext>(i);
}


size_t LIParser::FieldContext::getRuleIndex() const {
  return LIParser::RuleField;
}


antlrcpp::Any LIParser::FieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LIVisitor*>(visitor))
    return parserVisitor->visitField(this);
  else
    return visitor->visitChildren(this);
}

LIParser::FieldContext* LIParser::field() {
  FieldContext *_localctx = _tracker.createInstance<FieldContext>(_ctx, getState());
  enterRule(_localctx, 12, LIParser::RuleField);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    fieldKey();
    setState(94);
    match(LIParser::T__1);

    setState(95);
    ciBciEntry();
    setState(100);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LIParser::T__5) {
      setState(96);
      match(LIParser::T__5);

      setState(97);
      ciBciEntry();
      setState(102);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CiBciEntryContext ------------------------------------------------------------------

LIParser::CiBciEntryContext::CiBciEntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LIParser::CiEntriesContext* LIParser::CiBciEntryContext::ciEntries() {
  return getRuleContext<LIParser::CiEntriesContext>(0);
}

tree::TerminalNode* LIParser::CiBciEntryContext::STRING() {
  return getToken(LIParser::STRING, 0);
}

tree::TerminalNode* LIParser::CiBciEntryContext::CONST() {
  return getToken(LIParser::CONST, 0);
}

tree::TerminalNode* LIParser::CiBciEntryContext::GLOBAL() {
  return getToken(LIParser::GLOBAL, 0);
}

tree::TerminalNode* LIParser::CiBciEntryContext::NIL() {
  return getToken(LIParser::NIL, 0);
}


size_t LIParser::CiBciEntryContext::getRuleIndex() const {
  return LIParser::RuleCiBciEntry;
}


antlrcpp::Any LIParser::CiBciEntryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LIVisitor*>(visitor))
    return parserVisitor->visitCiBciEntry(this);
  else
    return visitor->visitChildren(this);
}

LIParser::CiBciEntryContext* LIParser::ciBciEntry() {
  CiBciEntryContext *_localctx = _tracker.createInstance<CiBciEntryContext>(_ctx, getState());
  enterRule(_localctx, 14, LIParser::RuleCiBciEntry);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LIParser::NUMS: {
        enterOuterAlt(_localctx, 1);
        setState(103);
        ciEntries();
        break;
      }

      case LIParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(104);
        match(LIParser::STRING);
        break;
      }

      case LIParser::CONST: {
        enterOuterAlt(_localctx, 3);
        setState(105);
        match(LIParser::CONST);
        break;
      }

      case LIParser::GLOBAL: {
        enterOuterAlt(_localctx, 4);
        setState(106);
        match(LIParser::GLOBAL);
        break;
      }

      case LIParser::NIL: {
        enterOuterAlt(_localctx, 5);
        setState(107);
        match(LIParser::NIL);
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

//----------------- CiEntriesContext ------------------------------------------------------------------

LIParser::CiEntriesContext::CiEntriesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LIParser::CallerIndexContext* LIParser::CiEntriesContext::callerIndex() {
  return getRuleContext<LIParser::CallerIndexContext>(0);
}

std::vector<LIParser::BciValContext *> LIParser::CiEntriesContext::bciVal() {
  return getRuleContexts<LIParser::BciValContext>();
}

LIParser::BciValContext* LIParser::CiEntriesContext::bciVal(size_t i) {
  return getRuleContext<LIParser::BciValContext>(i);
}


size_t LIParser::CiEntriesContext::getRuleIndex() const {
  return LIParser::RuleCiEntries;
}


antlrcpp::Any LIParser::CiEntriesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LIVisitor*>(visitor))
    return parserVisitor->visitCiEntries(this);
  else
    return visitor->visitChildren(this);
}

LIParser::CiEntriesContext* LIParser::ciEntries() {
  CiEntriesContext *_localctx = _tracker.createInstance<CiEntriesContext>(_ctx, getState());
  enterRule(_localctx, 16, LIParser::RuleCiEntries);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    callerIndex();
    setState(111);
    match(LIParser::T__6);

    setState(112);
    bciVal();
    setState(117);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LIParser::T__7) {
      setState(113);
      match(LIParser::T__7);

      setState(114);
      bciVal();
      setState(119);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallerIndexContext ------------------------------------------------------------------

LIParser::CallerIndexContext::CallerIndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LIParser::CallerIndexContext::NUMS() {
  return getToken(LIParser::NUMS, 0);
}


size_t LIParser::CallerIndexContext::getRuleIndex() const {
  return LIParser::RuleCallerIndex;
}


antlrcpp::Any LIParser::CallerIndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LIVisitor*>(visitor))
    return parserVisitor->visitCallerIndex(this);
  else
    return visitor->visitChildren(this);
}

LIParser::CallerIndexContext* LIParser::callerIndex() {
  CallerIndexContext *_localctx = _tracker.createInstance<CallerIndexContext>(_ctx, getState());
  enterRule(_localctx, 18, LIParser::RuleCallerIndex);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    match(LIParser::NUMS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BciKeyContext ------------------------------------------------------------------

LIParser::BciKeyContext::BciKeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LIParser::BciKeyContext::NUMS() {
  return getToken(LIParser::NUMS, 0);
}


size_t LIParser::BciKeyContext::getRuleIndex() const {
  return LIParser::RuleBciKey;
}


antlrcpp::Any LIParser::BciKeyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LIVisitor*>(visitor))
    return parserVisitor->visitBciKey(this);
  else
    return visitor->visitChildren(this);
}

LIParser::BciKeyContext* LIParser::bciKey() {
  BciKeyContext *_localctx = _tracker.createInstance<BciKeyContext>(_ctx, getState());
  enterRule(_localctx, 20, LIParser::RuleBciKey);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    match(LIParser::NUMS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BciValContext ------------------------------------------------------------------

LIParser::BciValContext::BciValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LIParser::BciValContext::NUMS() {
  return getToken(LIParser::NUMS, 0);
}

tree::TerminalNode* LIParser::BciValContext::NIL() {
  return getToken(LIParser::NIL, 0);
}


size_t LIParser::BciValContext::getRuleIndex() const {
  return LIParser::RuleBciVal;
}


antlrcpp::Any LIParser::BciValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LIVisitor*>(visitor))
    return parserVisitor->visitBciVal(this);
  else
    return visitor->visitChildren(this);
}

LIParser::BciValContext* LIParser::bciVal() {
  BciValContext *_localctx = _tracker.createInstance<BciValContext>(_ctx, getState());
  enterRule(_localctx, 22, LIParser::RuleBciVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    _la = _input->LA(1);
    if (!(_la == LIParser::NIL

    || _la == LIParser::NUMS)) {
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

//----------------- FieldKeyContext ------------------------------------------------------------------

LIParser::FieldKeyContext::FieldKeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LIParser::FieldKeyContext::ALPHAS() {
  return getToken(LIParser::ALPHAS, 0);
}


size_t LIParser::FieldKeyContext::getRuleIndex() const {
  return LIParser::RuleFieldKey;
}


antlrcpp::Any LIParser::FieldKeyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LIVisitor*>(visitor))
    return parserVisitor->visitFieldKey(this);
  else
    return visitor->visitChildren(this);
}

LIParser::FieldKeyContext* LIParser::fieldKey() {
  FieldKeyContext *_localctx = _tracker.createInstance<FieldKeyContext>(_ctx, getState());
  enterRule(_localctx, 24, LIParser::RuleFieldKey);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(126);
    match(LIParser::ALPHAS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> LIParser::_decisionToDFA;
atn::PredictionContextCache LIParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN LIParser::_atn;
std::vector<uint16_t> LIParser::_serializedATN;

std::vector<std::string> LIParser::_ruleNames = {
  "ptg", "entry", "vars", "varentry", "fields", "fieldentry", "field", "ciBciEntry", 
  "ciEntries", "callerIndex", "bciKey", "bciVal", "fieldKey"
};

std::vector<std::string> LIParser::_literalNames = {
  "", "';'", "':'", "'('", "')'", "','", "' '", "'-'", "'.'", "'N'", "'S'", 
  "'C'", "'G'"
};

std::vector<std::string> LIParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "NIL", "STRING", "CONST", "GLOBAL", 
  "NUMS", "ALPHAS", "NEWLINE", "ALL"
};

dfa::Vocabulary LIParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> LIParser::_tokenNames;

LIParser::Initializer::Initializer() {
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

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x12, 0x83, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x20, 0xa, 
       0x2, 0xc, 0x2, 0xe, 0x2, 0x23, 0xb, 0x2, 0x5, 0x2, 0x25, 0xa, 0x2, 
       0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x32, 0xa, 
       0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x37, 0xa, 0x4, 0xc, 
       0x4, 0xe, 0x4, 0x3a, 0xb, 0x4, 0x5, 0x4, 0x3c, 0xa, 0x4, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x43, 0xa, 0x5, 
       0xc, 0x5, 0xe, 0x5, 0x46, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
       0x7, 0x6, 0x4b, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x4e, 0xb, 0x6, 0x5, 
       0x6, 0x50, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x59, 0xa, 0x7, 0xc, 0x7, 0xe, 
       0x7, 0x5c, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x65, 0xa, 0x8, 0xc, 0x8, 0xe, 
       0x8, 0x68, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x5, 0x9, 0x6f, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
       0xa, 0x3, 0xa, 0x7, 0xa, 0x76, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x79, 
       0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 
       0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x2, 0x2, 0xf, 0x2, 0x4, 0x6, 
       0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x2, 0x4, 
       0x3, 0x3, 0x11, 0x11, 0x4, 0x2, 0xb, 0xb, 0xf, 0xf, 0x2, 0x84, 0x2, 
       0x24, 0x3, 0x2, 0x2, 0x2, 0x4, 0x28, 0x3, 0x2, 0x2, 0x2, 0x6, 0x3b, 
       0x3, 0x2, 0x2, 0x2, 0x8, 0x3d, 0x3, 0x2, 0x2, 0x2, 0xa, 0x4f, 0x3, 
       0x2, 0x2, 0x2, 0xc, 0x51, 0x3, 0x2, 0x2, 0x2, 0xe, 0x5f, 0x3, 0x2, 
       0x2, 0x2, 0x10, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x12, 0x70, 0x3, 0x2, 0x2, 
       0x2, 0x14, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x16, 0x7c, 0x3, 0x2, 0x2, 0x2, 
       0x18, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x80, 0x3, 0x2, 0x2, 0x2, 0x1c, 
       0x21, 0x5, 0x4, 0x3, 0x2, 0x1d, 0x1e, 0x7, 0x3, 0x2, 0x2, 0x1e, 0x20, 
       0x5, 0x4, 0x3, 0x2, 0x1f, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x20, 0x23, 0x3, 
       0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 0x3, 0x2, 
       0x2, 0x2, 0x22, 0x25, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 0x2, 0x2, 
       0x2, 0x24, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x3, 0x2, 0x2, 0x2, 
       0x25, 0x26, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x9, 0x2, 0x2, 0x2, 0x27, 
       0x3, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x5, 0x16, 0xc, 0x2, 0x29, 0x2a, 
       0x7, 0x4, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0x5, 0x2, 0x2, 0x2b, 0x2c, 0x5, 
       0x6, 0x4, 0x2, 0x2c, 0x31, 0x7, 0x6, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0x5, 
       0x2, 0x2, 0x2e, 0x2f, 0x5, 0xa, 0x6, 0x2, 0x2f, 0x30, 0x7, 0x6, 0x2, 
       0x2, 0x30, 0x32, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2d, 0x3, 0x2, 0x2, 0x2, 
       0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 0x32, 0x5, 0x3, 0x2, 0x2, 0x2, 0x33, 
       0x38, 0x5, 0x8, 0x5, 0x2, 0x34, 0x35, 0x7, 0x7, 0x2, 0x2, 0x35, 0x37, 
       0x5, 0x8, 0x5, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x37, 0x3a, 0x3, 
       0x2, 0x2, 0x2, 0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x3, 0x2, 
       0x2, 0x2, 0x39, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x38, 0x3, 0x2, 0x2, 
       0x2, 0x3b, 0x33, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x3, 0x2, 0x2, 0x2, 
       0x3c, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x5, 0x16, 0xc, 0x2, 0x3e, 
       0x3f, 0x7, 0x4, 0x2, 0x2, 0x3f, 0x44, 0x5, 0x10, 0x9, 0x2, 0x40, 
       0x41, 0x7, 0x8, 0x2, 0x2, 0x41, 0x43, 0x5, 0x10, 0x9, 0x2, 0x42, 
       0x40, 0x3, 0x2, 0x2, 0x2, 0x43, 0x46, 0x3, 0x2, 0x2, 0x2, 0x44, 0x42, 
       0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x3, 0x2, 0x2, 0x2, 0x45, 0x9, 0x3, 
       0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 0x2, 0x2, 0x47, 0x4c, 0x5, 0xc, 
       0x7, 0x2, 0x48, 0x49, 0x7, 0x7, 0x2, 0x2, 0x49, 0x4b, 0x5, 0xc, 0x7, 
       0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4e, 0x3, 0x2, 0x2, 0x2, 
       0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4d, 
       0x50, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x47, 
       0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0xb, 0x3, 
       0x2, 0x2, 0x2, 0x51, 0x52, 0x5, 0x14, 0xb, 0x2, 0x52, 0x53, 0x7, 
       0x9, 0x2, 0x2, 0x53, 0x54, 0x5, 0x16, 0xc, 0x2, 0x54, 0x55, 0x7, 
       0x5, 0x2, 0x2, 0x55, 0x5a, 0x5, 0xe, 0x8, 0x2, 0x56, 0x57, 0x7, 0x7, 
       0x2, 0x2, 0x57, 0x59, 0x5, 0xe, 0x8, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 
       0x2, 0x59, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 0x2, 
       0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5c, 
       0x5a, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0x6, 0x2, 0x2, 0x5e, 0xd, 
       0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x5, 0x1a, 0xe, 0x2, 0x60, 0x61, 
       0x7, 0x4, 0x2, 0x2, 0x61, 0x66, 0x5, 0x10, 0x9, 0x2, 0x62, 0x63, 
       0x7, 0x8, 0x2, 0x2, 0x63, 0x65, 0x5, 0x10, 0x9, 0x2, 0x64, 0x62, 
       0x3, 0x2, 0x2, 0x2, 0x65, 0x68, 0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 
       0x2, 0x2, 0x2, 0x66, 0x67, 0x3, 0x2, 0x2, 0x2, 0x67, 0xf, 0x3, 0x2, 
       0x2, 0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6f, 0x5, 0x12, 
       0xa, 0x2, 0x6a, 0x6f, 0x7, 0xc, 0x2, 0x2, 0x6b, 0x6f, 0x7, 0xd, 0x2, 
       0x2, 0x6c, 0x6f, 0x7, 0xe, 0x2, 0x2, 0x6d, 0x6f, 0x7, 0xb, 0x2, 0x2, 
       0x6e, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6e, 
       0x6b, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6d, 
       0x3, 0x2, 0x2, 0x2, 0x6f, 0x11, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x5, 
       0x14, 0xb, 0x2, 0x71, 0x72, 0x7, 0x9, 0x2, 0x2, 0x72, 0x77, 0x5, 
       0x18, 0xd, 0x2, 0x73, 0x74, 0x7, 0xa, 0x2, 0x2, 0x74, 0x76, 0x5, 
       0x18, 0xd, 0x2, 0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x76, 0x79, 0x3, 
       0x2, 0x2, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x3, 0x2, 
       0x2, 0x2, 0x78, 0x13, 0x3, 0x2, 0x2, 0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 
       0x2, 0x7a, 0x7b, 0x7, 0xf, 0x2, 0x2, 0x7b, 0x15, 0x3, 0x2, 0x2, 0x2, 
       0x7c, 0x7d, 0x7, 0xf, 0x2, 0x2, 0x7d, 0x17, 0x3, 0x2, 0x2, 0x2, 0x7e, 
       0x7f, 0x9, 0x3, 0x2, 0x2, 0x7f, 0x19, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 
       0x7, 0x10, 0x2, 0x2, 0x81, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xe, 0x21, 0x24, 
       0x31, 0x38, 0x3b, 0x44, 0x4c, 0x4f, 0x5a, 0x66, 0x6e, 0x77, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

LIParser::Initializer LIParser::_init;
