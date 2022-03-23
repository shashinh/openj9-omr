
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
    setState(32);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PTGParser::NUMS

    || _la == PTGParser::ALL) {
      setState(24);
      entry();
      setState(29);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PTGParser::T__0) {
        setState(25);
        match(PTGParser::T__0);
        setState(26);
        entry();
        setState(31);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(34);
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
    setState(36);
    bciKey();
    setState(37);
    match(PTGParser::T__1);
    setState(38);
    match(PTGParser::T__2);
    setState(39);
    vars();
    setState(40);
    match(PTGParser::T__3);
    setState(45);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PTGParser::T__2) {
      setState(41);
      match(PTGParser::T__2);
      setState(42);
      fields();
      setState(43);
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
    setState(55);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PTGParser::NUMS

    || _la == PTGParser::ALL) {
      setState(47);
      varentry();
      setState(52);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PTGParser::T__4) {
        setState(48);
        match(PTGParser::T__4);
        setState(49);
        varentry();
        setState(54);
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
    setState(57);
    bciKey();
    setState(58);
    match(PTGParser::T__1);

    setState(59);
    ciBciEntry();
    setState(64);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PTGParser::T__5) {
      setState(60);
      match(PTGParser::T__5);

      setState(61);
      ciBciEntry();
      setState(66);
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
    setState(75);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PTGParser::NUMS) {
      setState(67);
      fieldentry();
      setState(72);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PTGParser::T__4) {
        setState(68);
        match(PTGParser::T__4);
        setState(69);
        fieldentry();
        setState(74);
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

PTGParser::BciKeyFieldContext* PTGParser::FieldentryContext::bciKeyField() {
  return getRuleContext<PTGParser::BciKeyFieldContext>(0);
}

PTGParser::FieldContext* PTGParser::FieldentryContext::field() {
  return getRuleContext<PTGParser::FieldContext>(0);
}

std::vector<PTGParser::BciValContext *> PTGParser::FieldentryContext::bciVal() {
  return getRuleContexts<PTGParser::BciValContext>();
}

PTGParser::BciValContext* PTGParser::FieldentryContext::bciVal(size_t i) {
  return getRuleContext<PTGParser::BciValContext>(i);
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
    setState(77);
    bciKeyField();
    setState(78);
    match(PTGParser::T__6);
    setState(79);
    field();
    setState(80);
    match(PTGParser::T__1);

    setState(81);
    bciVal();
    setState(86);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PTGParser::T__5) {
      setState(82);
      match(PTGParser::T__5);
      setState(83);
      bciVal();
      setState(88);
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
  enterRule(_localctx, 12, PTGParser::RuleCiBciEntry);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    match(PTGParser::NIL);
   
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
  enterRule(_localctx, 14, PTGParser::RuleCallerIndex);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
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

tree::TerminalNode* PTGParser::BciKeyContext::ALL() {
  return getToken(PTGParser::ALL, 0);
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
  enterRule(_localctx, 16, PTGParser::RuleBciKey);
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
    _la = _input->LA(1);
    if (!(_la == PTGParser::NUMS

    || _la == PTGParser::ALL)) {
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
  enterRule(_localctx, 18, PTGParser::RuleBciVal);
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
    setState(95);
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

//----------------- BciKeyFieldContext ------------------------------------------------------------------

PTGParser::BciKeyFieldContext::BciKeyFieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PTGParser::BciKeyFieldContext::NUMS() {
  return getToken(PTGParser::NUMS, 0);
}


size_t PTGParser::BciKeyFieldContext::getRuleIndex() const {
  return PTGParser::RuleBciKeyField;
}


antlrcpp::Any PTGParser::BciKeyFieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PTGVisitor*>(visitor))
    return parserVisitor->visitBciKeyField(this);
  else
    return visitor->visitChildren(this);
}

PTGParser::BciKeyFieldContext* PTGParser::bciKeyField() {
  BciKeyFieldContext *_localctx = _tracker.createInstance<BciKeyFieldContext>(_ctx, getState());
  enterRule(_localctx, 20, PTGParser::RuleBciKeyField);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    match(PTGParser::NUMS);
   
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

tree::TerminalNode* PTGParser::FieldContext::ALPHAS() {
  return getToken(PTGParser::ALPHAS, 0);
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
  enterRule(_localctx, 22, PTGParser::RuleField);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
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
  "ptg", "entry", "vars", "varentry", "fields", "fieldentry", "ciBciEntry", 
  "callerIndex", "bciKey", "bciVal", "bciKeyField", "field"
};

std::vector<std::string> PTGParser::_literalNames = {
  "", "';'", "':'", "'('", "')'", "','", "' '", "'.'", "'n'"
};

std::vector<std::string> PTGParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "NIL", "NUMS", "ALPHAS", "NEWLINE", "ALL"
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
       0x3, 0xe, 0x68, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x3, 
       0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x1e, 0xa, 0x2, 0xc, 0x2, 0xe, 
       0x2, 0x21, 0xb, 0x2, 0x5, 0x2, 0x23, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x30, 0xa, 0x3, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x7, 0x4, 0x35, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x38, 
       0xb, 0x4, 0x5, 0x4, 0x3a, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x41, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
       0x44, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x49, 0xa, 
       0x6, 0xc, 0x6, 0xe, 0x6, 0x4c, 0xb, 0x6, 0x5, 0x6, 0x4e, 0xa, 0x6, 
       0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x7, 0x7, 0x57, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x5a, 0xb, 0x7, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
       0x2, 0x2, 0xe, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
       0x16, 0x18, 0x2, 0x5, 0x3, 0x3, 0xd, 0xd, 0x4, 0x2, 0xb, 0xb, 0xe, 
       0xe, 0x3, 0x2, 0xa, 0xb, 0x2, 0x64, 0x2, 0x22, 0x3, 0x2, 0x2, 0x2, 
       0x4, 0x26, 0x3, 0x2, 0x2, 0x2, 0x6, 0x39, 0x3, 0x2, 0x2, 0x2, 0x8, 
       0x3b, 0x3, 0x2, 0x2, 0x2, 0xa, 0x4d, 0x3, 0x2, 0x2, 0x2, 0xc, 0x4f, 
       0x3, 0x2, 0x2, 0x2, 0xe, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x10, 0x5d, 0x3, 
       0x2, 0x2, 0x2, 0x12, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x14, 0x61, 0x3, 0x2, 
       0x2, 0x2, 0x16, 0x63, 0x3, 0x2, 0x2, 0x2, 0x18, 0x65, 0x3, 0x2, 0x2, 
       0x2, 0x1a, 0x1f, 0x5, 0x4, 0x3, 0x2, 0x1b, 0x1c, 0x7, 0x3, 0x2, 0x2, 
       0x1c, 0x1e, 0x5, 0x4, 0x3, 0x2, 0x1d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1e, 
       0x21, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 
       0x3, 0x2, 0x2, 0x2, 0x20, 0x23, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 
       0x2, 0x2, 0x2, 0x22, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x3, 0x2, 
       0x2, 0x2, 0x23, 0x24, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x9, 0x2, 0x2, 
       0x2, 0x25, 0x3, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x5, 0x12, 0xa, 0x2, 
       0x27, 0x28, 0x7, 0x4, 0x2, 0x2, 0x28, 0x29, 0x7, 0x5, 0x2, 0x2, 0x29, 
       0x2a, 0x5, 0x6, 0x4, 0x2, 0x2a, 0x2f, 0x7, 0x6, 0x2, 0x2, 0x2b, 0x2c, 
       0x7, 0x5, 0x2, 0x2, 0x2c, 0x2d, 0x5, 0xa, 0x6, 0x2, 0x2d, 0x2e, 0x7, 
       0x6, 0x2, 0x2, 0x2e, 0x30, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2b, 0x3, 0x2, 
       0x2, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x2, 0x2, 0x30, 0x5, 0x3, 0x2, 0x2, 
       0x2, 0x31, 0x36, 0x5, 0x8, 0x5, 0x2, 0x32, 0x33, 0x7, 0x7, 0x2, 0x2, 
       0x33, 0x35, 0x5, 0x8, 0x5, 0x2, 0x34, 0x32, 0x3, 0x2, 0x2, 0x2, 0x35, 
       0x38, 0x3, 0x2, 0x2, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 
       0x3, 0x2, 0x2, 0x2, 0x37, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x38, 0x36, 0x3, 
       0x2, 0x2, 0x2, 0x39, 0x31, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 0x2, 
       0x2, 0x2, 0x3a, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x5, 0x12, 0xa, 
       0x2, 0x3c, 0x3d, 0x7, 0x4, 0x2, 0x2, 0x3d, 0x42, 0x5, 0xe, 0x8, 0x2, 
       0x3e, 0x3f, 0x7, 0x8, 0x2, 0x2, 0x3f, 0x41, 0x5, 0xe, 0x8, 0x2, 0x40, 
       0x3e, 0x3, 0x2, 0x2, 0x2, 0x41, 0x44, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 
       0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x3, 0x2, 0x2, 0x2, 0x43, 0x9, 0x3, 
       0x2, 0x2, 0x2, 0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x45, 0x4a, 0x5, 0xc, 
       0x7, 0x2, 0x46, 0x47, 0x7, 0x7, 0x2, 0x2, 0x47, 0x49, 0x5, 0xc, 0x7, 
       0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4c, 0x3, 0x2, 0x2, 0x2, 
       0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4b, 
       0x4e, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x45, 
       0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4e, 0xb, 0x3, 
       0x2, 0x2, 0x2, 0x4f, 0x50, 0x5, 0x16, 0xc, 0x2, 0x50, 0x51, 0x7, 
       0x9, 0x2, 0x2, 0x51, 0x52, 0x5, 0x18, 0xd, 0x2, 0x52, 0x53, 0x7, 
       0x4, 0x2, 0x2, 0x53, 0x58, 0x5, 0x14, 0xb, 0x2, 0x54, 0x55, 0x7, 
       0x8, 0x2, 0x2, 0x55, 0x57, 0x5, 0x14, 0xb, 0x2, 0x56, 0x54, 0x3, 
       0x2, 0x2, 0x2, 0x57, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 
       0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 0x2, 0x2, 0x59, 0xd, 0x3, 0x2, 0x2, 
       0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0xa, 0x2, 0x2, 
       0x5c, 0xf, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0xb, 0x2, 0x2, 0x5e, 
       0x11, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x9, 0x3, 0x2, 0x2, 0x60, 0x13, 
       0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x9, 0x4, 0x2, 0x2, 0x62, 0x15, 0x3, 
       0x2, 0x2, 0x2, 0x63, 0x64, 0x7, 0xb, 0x2, 0x2, 0x64, 0x17, 0x3, 0x2, 
       0x2, 0x2, 0x65, 0x66, 0x7, 0xc, 0x2, 0x2, 0x66, 0x19, 0x3, 0x2, 0x2, 
       0x2, 0xb, 0x1f, 0x22, 0x2f, 0x36, 0x39, 0x42, 0x4a, 0x4d, 0x58, 
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
