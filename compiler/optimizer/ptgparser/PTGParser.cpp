
// Generated from PTG.g4 by ANTLR 4.9.2


#include "PTGVisitor.h"

#include "PTGParser.h"


using namespace antlrcpp;
using namespace antlr4;

PTGParser::PTGParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

PTGParser::~PTGParser() {
  delete _interpreter;
}

std::string PTGParser::getGrammarFileName() const {
  return "PTG.g4";
}

const std::vector<std::string>& PTGParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& PTGParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- PtgContext ------------------------------------------------------------------

PTGParser::PtgContext::PtgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PTGParser::PtgContext::NEWLINE() {
  return getToken(PTGParser::NEWLINE, 0);
}

tree::TerminalNode* PTGParser::PtgContext::EOF() {
  return getToken(PTGParser::EOF, 0);
}

std::vector<PTGParser::EntryContext *> PTGParser::PtgContext::entry() {
  return getRuleContexts<PTGParser::EntryContext>();
}

PTGParser::EntryContext* PTGParser::PtgContext::entry(size_t i) {
  return getRuleContext<PTGParser::EntryContext>(i);
}


size_t PTGParser::PtgContext::getRuleIndex() const {
  return PTGParser::RulePtg;
}


antlrcpp::Any PTGParser::PtgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PTGVisitor*>(visitor))
    return parserVisitor->visitPtg(this);
  else
    return visitor->visitChildren(this);
}

PTGParser::PtgContext* PTGParser::ptg() {
  PtgContext *_localctx = _tracker.createInstance<PtgContext>(_ctx, getState());
  enterRule(_localctx, 0, PTGParser::RulePtg);
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
    if (_la == PTGParser::NUMS) {
      setState(26);
      entry();
      setState(31);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PTGParser::T__0) {
        setState(27);
        match(PTGParser::T__0);
        setState(28);
        entry();
        setState(33);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(36);
    _la = _input->LA(1);
    if (!(_la == PTGParser::EOF

    || _la == PTGParser::NEWLINE)) {
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

PTGParser::EntryContext::EntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PTGParser::BciKeyContext* PTGParser::EntryContext::bciKey() {
  return getRuleContext<PTGParser::BciKeyContext>(0);
}

PTGParser::VarsContext* PTGParser::EntryContext::vars() {
  return getRuleContext<PTGParser::VarsContext>(0);
}

PTGParser::FieldsContext* PTGParser::EntryContext::fields() {
  return getRuleContext<PTGParser::FieldsContext>(0);
}


size_t PTGParser::EntryContext::getRuleIndex() const {
  return PTGParser::RuleEntry;
}


antlrcpp::Any PTGParser::EntryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PTGVisitor*>(visitor))
    return parserVisitor->visitEntry(this);
  else
    return visitor->visitChildren(this);
}

PTGParser::EntryContext* PTGParser::entry() {
  EntryContext *_localctx = _tracker.createInstance<EntryContext>(_ctx, getState());
  enterRule(_localctx, 2, PTGParser::RuleEntry);
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
    match(PTGParser::T__1);
    setState(40);
    match(PTGParser::T__2);
    setState(41);
    vars();
    setState(42);
    match(PTGParser::T__3);
    setState(47);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PTGParser::T__2) {
      setState(43);
      match(PTGParser::T__2);
      setState(44);
      fields();
      setState(45);
      match(PTGParser::T__3);
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

PTGParser::VarsContext::VarsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PTGParser::VarentryContext *> PTGParser::VarsContext::varentry() {
  return getRuleContexts<PTGParser::VarentryContext>();
}

PTGParser::VarentryContext* PTGParser::VarsContext::varentry(size_t i) {
  return getRuleContext<PTGParser::VarentryContext>(i);
}


size_t PTGParser::VarsContext::getRuleIndex() const {
  return PTGParser::RuleVars;
}


antlrcpp::Any PTGParser::VarsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PTGVisitor*>(visitor))
    return parserVisitor->visitVars(this);
  else
    return visitor->visitChildren(this);
}

PTGParser::VarsContext* PTGParser::vars() {
  VarsContext *_localctx = _tracker.createInstance<VarsContext>(_ctx, getState());
  enterRule(_localctx, 4, PTGParser::RuleVars);
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
    if (_la == PTGParser::NUMS) {
      setState(49);
      varentry();
      setState(54);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PTGParser::T__4) {
        setState(50);
        match(PTGParser::T__4);
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

PTGParser::VarentryContext::VarentryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PTGParser::BciKeyContext* PTGParser::VarentryContext::bciKey() {
  return getRuleContext<PTGParser::BciKeyContext>(0);
}

std::vector<PTGParser::CiBciEntryContext *> PTGParser::VarentryContext::ciBciEntry() {
  return getRuleContexts<PTGParser::CiBciEntryContext>();
}

PTGParser::CiBciEntryContext* PTGParser::VarentryContext::ciBciEntry(size_t i) {
  return getRuleContext<PTGParser::CiBciEntryContext>(i);
}


size_t PTGParser::VarentryContext::getRuleIndex() const {
  return PTGParser::RuleVarentry;
}


antlrcpp::Any PTGParser::VarentryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PTGVisitor*>(visitor))
    return parserVisitor->visitVarentry(this);
  else
    return visitor->visitChildren(this);
}

PTGParser::VarentryContext* PTGParser::varentry() {
  VarentryContext *_localctx = _tracker.createInstance<VarentryContext>(_ctx, getState());
  enterRule(_localctx, 6, PTGParser::RuleVarentry);
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
    match(PTGParser::T__1);

    setState(61);
    ciBciEntry();
    setState(66);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PTGParser::T__5) {
      setState(62);
      match(PTGParser::T__5);

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

PTGParser::FieldsContext::FieldsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PTGParser::FieldentryContext *> PTGParser::FieldsContext::fieldentry() {
  return getRuleContexts<PTGParser::FieldentryContext>();
}

PTGParser::FieldentryContext* PTGParser::FieldsContext::fieldentry(size_t i) {
  return getRuleContext<PTGParser::FieldentryContext>(i);
}


size_t PTGParser::FieldsContext::getRuleIndex() const {
  return PTGParser::RuleFields;
}


antlrcpp::Any PTGParser::FieldsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PTGVisitor*>(visitor))
    return parserVisitor->visitFields(this);
  else
    return visitor->visitChildren(this);
}

PTGParser::FieldsContext* PTGParser::fields() {
  FieldsContext *_localctx = _tracker.createInstance<FieldsContext>(_ctx, getState());
  enterRule(_localctx, 8, PTGParser::RuleFields);
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
    if (_la == PTGParser::NUMS) {
      setState(69);
      fieldentry();
      setState(74);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PTGParser::T__4) {
        setState(70);
        match(PTGParser::T__4);
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

PTGParser::FieldentryContext::FieldentryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PTGParser::CallerIndexContext* PTGParser::FieldentryContext::callerIndex() {
  return getRuleContext<PTGParser::CallerIndexContext>(0);
}

PTGParser::BciKeyContext* PTGParser::FieldentryContext::bciKey() {
  return getRuleContext<PTGParser::BciKeyContext>(0);
}

std::vector<PTGParser::FieldContext *> PTGParser::FieldentryContext::field() {
  return getRuleContexts<PTGParser::FieldContext>();
}

PTGParser::FieldContext* PTGParser::FieldentryContext::field(size_t i) {
  return getRuleContext<PTGParser::FieldContext>(i);
}


size_t PTGParser::FieldentryContext::getRuleIndex() const {
  return PTGParser::RuleFieldentry;
}


antlrcpp::Any PTGParser::FieldentryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PTGVisitor*>(visitor))
    return parserVisitor->visitFieldentry(this);
  else
    return visitor->visitChildren(this);
}

PTGParser::FieldentryContext* PTGParser::fieldentry() {
  FieldentryContext *_localctx = _tracker.createInstance<FieldentryContext>(_ctx, getState());
  enterRule(_localctx, 10, PTGParser::RuleFieldentry);
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
    match(PTGParser::T__6);
    setState(81);
    bciKey();
    setState(82);
    match(PTGParser::T__2);

    setState(83);
    field();

    setState(88);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PTGParser::T__4) {
      setState(84);
      match(PTGParser::T__4);

      setState(85);
      field();
      setState(90);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(91);
    match(PTGParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldContext ------------------------------------------------------------------

PTGParser::FieldContext::FieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PTGParser::FieldKeyContext* PTGParser::FieldContext::fieldKey() {
  return getRuleContext<PTGParser::FieldKeyContext>(0);
}

std::vector<PTGParser::CiBciEntryContext *> PTGParser::FieldContext::ciBciEntry() {
  return getRuleContexts<PTGParser::CiBciEntryContext>();
}

PTGParser::CiBciEntryContext* PTGParser::FieldContext::ciBciEntry(size_t i) {
  return getRuleContext<PTGParser::CiBciEntryContext>(i);
}


size_t PTGParser::FieldContext::getRuleIndex() const {
  return PTGParser::RuleField;
}


antlrcpp::Any PTGParser::FieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PTGVisitor*>(visitor))
    return parserVisitor->visitField(this);
  else
    return visitor->visitChildren(this);
}

PTGParser::FieldContext* PTGParser::field() {
  FieldContext *_localctx = _tracker.createInstance<FieldContext>(_ctx, getState());
  enterRule(_localctx, 12, PTGParser::RuleField);
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
    match(PTGParser::T__1);

    setState(95);
    ciBciEntry();
    setState(100);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PTGParser::T__5) {
      setState(96);
      match(PTGParser::T__5);

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

PTGParser::CiBciEntryContext::CiBciEntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PTGParser::CiEntriesContext* PTGParser::CiBciEntryContext::ciEntries() {
  return getRuleContext<PTGParser::CiEntriesContext>(0);
}

tree::TerminalNode* PTGParser::CiBciEntryContext::STRING() {
  return getToken(PTGParser::STRING, 0);
}

tree::TerminalNode* PTGParser::CiBciEntryContext::CONST() {
  return getToken(PTGParser::CONST, 0);
}

tree::TerminalNode* PTGParser::CiBciEntryContext::GLOBAL() {
  return getToken(PTGParser::GLOBAL, 0);
}

tree::TerminalNode* PTGParser::CiBciEntryContext::NIL() {
  return getToken(PTGParser::NIL, 0);
}


size_t PTGParser::CiBciEntryContext::getRuleIndex() const {
  return PTGParser::RuleCiBciEntry;
}


antlrcpp::Any PTGParser::CiBciEntryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PTGVisitor*>(visitor))
    return parserVisitor->visitCiBciEntry(this);
  else
    return visitor->visitChildren(this);
}

PTGParser::CiBciEntryContext* PTGParser::ciBciEntry() {
  CiBciEntryContext *_localctx = _tracker.createInstance<CiBciEntryContext>(_ctx, getState());
  enterRule(_localctx, 14, PTGParser::RuleCiBciEntry);

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
      case PTGParser::NUMS: {
        enterOuterAlt(_localctx, 1);
        setState(103);
        ciEntries();
        break;
      }

      case PTGParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(104);
        match(PTGParser::STRING);
        break;
      }

      case PTGParser::CONST: {
        enterOuterAlt(_localctx, 3);
        setState(105);
        match(PTGParser::CONST);
        break;
      }

      case PTGParser::GLOBAL: {
        enterOuterAlt(_localctx, 4);
        setState(106);
        match(PTGParser::GLOBAL);
        break;
      }

      case PTGParser::NIL: {
        enterOuterAlt(_localctx, 5);
        setState(107);
        match(PTGParser::NIL);
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

PTGParser::CiEntriesContext::CiEntriesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PTGParser::CallerIndexContext* PTGParser::CiEntriesContext::callerIndex() {
  return getRuleContext<PTGParser::CallerIndexContext>(0);
}

std::vector<PTGParser::BciValContext *> PTGParser::CiEntriesContext::bciVal() {
  return getRuleContexts<PTGParser::BciValContext>();
}

PTGParser::BciValContext* PTGParser::CiEntriesContext::bciVal(size_t i) {
  return getRuleContext<PTGParser::BciValContext>(i);
}


size_t PTGParser::CiEntriesContext::getRuleIndex() const {
  return PTGParser::RuleCiEntries;
}


antlrcpp::Any PTGParser::CiEntriesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PTGVisitor*>(visitor))
    return parserVisitor->visitCiEntries(this);
  else
    return visitor->visitChildren(this);
}

PTGParser::CiEntriesContext* PTGParser::ciEntries() {
  CiEntriesContext *_localctx = _tracker.createInstance<CiEntriesContext>(_ctx, getState());
  enterRule(_localctx, 16, PTGParser::RuleCiEntries);
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
    match(PTGParser::T__6);

    setState(112);
    bciVal();
    setState(117);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PTGParser::T__7) {
      setState(113);
      match(PTGParser::T__7);

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

PTGParser::CallerIndexContext::CallerIndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PTGParser::CallerIndexContext::NUMS() {
  return getToken(PTGParser::NUMS, 0);
}


size_t PTGParser::CallerIndexContext::getRuleIndex() const {
  return PTGParser::RuleCallerIndex;
}


antlrcpp::Any PTGParser::CallerIndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PTGVisitor*>(visitor))
    return parserVisitor->visitCallerIndex(this);
  else
    return visitor->visitChildren(this);
}

PTGParser::CallerIndexContext* PTGParser::callerIndex() {
  CallerIndexContext *_localctx = _tracker.createInstance<CallerIndexContext>(_ctx, getState());
  enterRule(_localctx, 18, PTGParser::RuleCallerIndex);

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
    match(PTGParser::NUMS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BciKeyContext ------------------------------------------------------------------

PTGParser::BciKeyContext::BciKeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PTGParser::BciKeyContext::NUMS() {
  return getToken(PTGParser::NUMS, 0);
}


size_t PTGParser::BciKeyContext::getRuleIndex() const {
  return PTGParser::RuleBciKey;
}


antlrcpp::Any PTGParser::BciKeyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PTGVisitor*>(visitor))
    return parserVisitor->visitBciKey(this);
  else
    return visitor->visitChildren(this);
}

PTGParser::BciKeyContext* PTGParser::bciKey() {
  BciKeyContext *_localctx = _tracker.createInstance<BciKeyContext>(_ctx, getState());
  enterRule(_localctx, 20, PTGParser::RuleBciKey);

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
    match(PTGParser::NUMS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BciValContext ------------------------------------------------------------------

PTGParser::BciValContext::BciValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PTGParser::BciValContext::NUMS() {
  return getToken(PTGParser::NUMS, 0);
}

tree::TerminalNode* PTGParser::BciValContext::NIL() {
  return getToken(PTGParser::NIL, 0);
}


size_t PTGParser::BciValContext::getRuleIndex() const {
  return PTGParser::RuleBciVal;
}


antlrcpp::Any PTGParser::BciValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PTGVisitor*>(visitor))
    return parserVisitor->visitBciVal(this);
  else
    return visitor->visitChildren(this);
}

PTGParser::BciValContext* PTGParser::bciVal() {
  BciValContext *_localctx = _tracker.createInstance<BciValContext>(_ctx, getState());
  enterRule(_localctx, 22, PTGParser::RuleBciVal);
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
    if (!(_la == PTGParser::NIL

    || _la == PTGParser::NUMS)) {
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

PTGParser::FieldKeyContext::FieldKeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PTGParser::FieldKeyContext::ALPHAS() {
  return getToken(PTGParser::ALPHAS, 0);
}


size_t PTGParser::FieldKeyContext::getRuleIndex() const {
  return PTGParser::RuleFieldKey;
}


antlrcpp::Any PTGParser::FieldKeyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PTGVisitor*>(visitor))
    return parserVisitor->visitFieldKey(this);
  else
    return visitor->visitChildren(this);
}

PTGParser::FieldKeyContext* PTGParser::fieldKey() {
  FieldKeyContext *_localctx = _tracker.createInstance<FieldKeyContext>(_ctx, getState());
  enterRule(_localctx, 24, PTGParser::RuleFieldKey);

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
    match(PTGParser::ALPHAS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> PTGParser::_decisionToDFA;
atn::PredictionContextCache PTGParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN PTGParser::_atn;
std::vector<uint16_t> PTGParser::_serializedATN;

std::vector<std::string> PTGParser::_ruleNames = {
  "ptg", "entry", "vars", "varentry", "fields", "fieldentry", "field", "ciBciEntry", 
  "ciEntries", "callerIndex", "bciKey", "bciVal", "fieldKey"
};

std::vector<std::string> PTGParser::_literalNames = {
  "", "';'", "':'", "'('", "')'", "','", "' '", "'-'", "'.'", "'N'", "'S'", 
  "'C'", "'G'"
};

std::vector<std::string> PTGParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "NIL", "STRING", "CONST", "GLOBAL", 
  "NUMS", "ALPHAS", "NEWLINE", "ALL"
};

dfa::Vocabulary PTGParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> PTGParser::_tokenNames;

PTGParser::Initializer::Initializer() {
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

PTGParser::Initializer PTGParser::_init;
