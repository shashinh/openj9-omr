
// Generated from demo/test1/PTG.g4 by ANTLR 4.9.2


#include "PTGListener.h"

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

void PTGParser::PtgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPtg(this);
}

void PTGParser::PtgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPtg(this);
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
    setState(28);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PTGParser::NUMS

    || _la == PTGParser::ALL) {
      setState(20);
      entry();
      setState(25);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PTGParser::T__0) {
        setState(21);
        match(PTGParser::T__0);
        setState(22);
        entry();
        setState(27);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(30);
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

void PTGParser::EntryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntry(this);
}

void PTGParser::EntryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntry(this);
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
    setState(32);
    bciKey();
    setState(33);
    match(PTGParser::T__1);
    setState(34);
    match(PTGParser::T__2);
    setState(35);
    vars();
    setState(36);
    match(PTGParser::T__3);
    setState(41);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PTGParser::T__2) {
      setState(37);
      match(PTGParser::T__2);
      setState(38);
      fields();
      setState(39);
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

void PTGParser::VarsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVars(this);
}

void PTGParser::VarsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVars(this);
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
    setState(51);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PTGParser::NUMS

    || _la == PTGParser::ALL) {
      setState(43);
      varentry();
      setState(48);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PTGParser::T__4) {
        setState(44);
        match(PTGParser::T__4);
        setState(45);
        varentry();
        setState(50);
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

std::vector<PTGParser::BciValContext *> PTGParser::VarentryContext::bciVal() {
  return getRuleContexts<PTGParser::BciValContext>();
}

PTGParser::BciValContext* PTGParser::VarentryContext::bciVal(size_t i) {
  return getRuleContext<PTGParser::BciValContext>(i);
}


size_t PTGParser::VarentryContext::getRuleIndex() const {
  return PTGParser::RuleVarentry;
}

void PTGParser::VarentryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarentry(this);
}

void PTGParser::VarentryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarentry(this);
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
    setState(53);
    bciKey();
    setState(54);
    match(PTGParser::T__1);

    setState(55);
    bciVal();
    setState(60);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PTGParser::T__5) {
      setState(56);
      match(PTGParser::T__5);

      setState(57);
      bciVal();
      setState(62);
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

void PTGParser::FieldsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFields(this);
}

void PTGParser::FieldsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFields(this);
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
    setState(71);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PTGParser::NUMS) {
      setState(63);
      fieldentry();
      setState(68);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PTGParser::T__4) {
        setState(64);
        match(PTGParser::T__4);
        setState(65);
        fieldentry();
        setState(70);
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

void PTGParser::FieldentryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFieldentry(this);
}

void PTGParser::FieldentryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFieldentry(this);
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
    setState(73);
    bciKeyField();
    setState(74);
    match(PTGParser::T__6);
    setState(75);
    field();
    setState(76);
    match(PTGParser::T__1);

    setState(77);
    bciVal();
    setState(82);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PTGParser::T__5) {
      setState(78);
      match(PTGParser::T__5);
      setState(79);
      bciVal();
      setState(84);
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

void PTGParser::BciKeyFieldContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBciKeyField(this);
}

void PTGParser::BciKeyFieldContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBciKeyField(this);
}

PTGParser::BciKeyFieldContext* PTGParser::bciKeyField() {
  BciKeyFieldContext *_localctx = _tracker.createInstance<BciKeyFieldContext>(_ctx, getState());
  enterRule(_localctx, 12, PTGParser::RuleBciKeyField);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
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

void PTGParser::FieldContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterField(this);
}

void PTGParser::FieldContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitField(this);
}

PTGParser::FieldContext* PTGParser::field() {
  FieldContext *_localctx = _tracker.createInstance<FieldContext>(_ctx, getState());
  enterRule(_localctx, 14, PTGParser::RuleField);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    match(PTGParser::ALPHAS);
   
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

void PTGParser::BciKeyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBciKey(this);
}

void PTGParser::BciKeyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBciKey(this);
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
    setState(89);
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

void PTGParser::BciValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBciVal(this);
}

void PTGParser::BciValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PTGListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBciVal(this);
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
    setState(91);
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

// Static vars and initialization.
std::vector<dfa::DFA> PTGParser::_decisionToDFA;
atn::PredictionContextCache PTGParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN PTGParser::_atn;
std::vector<uint16_t> PTGParser::_serializedATN;

std::vector<std::string> PTGParser::_ruleNames = {
  "ptg", "entry", "vars", "varentry", "fields", "fieldentry", "bciKeyField", 
  "field", "bciKey", "bciVal"
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
       0x3, 0xe, 0x60, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x1a, 
       0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x1d, 0xb, 0x2, 0x5, 0x2, 0x1f, 0xa, 
       0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2c, 
       0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x31, 0xa, 0x4, 
       0xc, 0x4, 0xe, 0x4, 0x34, 0xb, 0x4, 0x5, 0x4, 0x36, 0xa, 0x4, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x3d, 0xa, 
       0x5, 0xc, 0x5, 0xe, 0x5, 0x40, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
       0x6, 0x7, 0x6, 0x45, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x48, 0xb, 0x6, 
       0x5, 0x6, 0x4a, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
       0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x53, 0xa, 0x7, 0xc, 0x7, 
       0xe, 0x7, 0x56, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x2, 0x2, 0xc, 
       0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x2, 0x5, 0x3, 
       0x3, 0xd, 0xd, 0x4, 0x2, 0xb, 0xb, 0xe, 0xe, 0x3, 0x2, 0xa, 0xb, 
       0x2, 0x5e, 0x2, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x4, 0x22, 0x3, 0x2, 0x2, 
       0x2, 0x6, 0x35, 0x3, 0x2, 0x2, 0x2, 0x8, 0x37, 0x3, 0x2, 0x2, 0x2, 
       0xa, 0x49, 0x3, 0x2, 0x2, 0x2, 0xc, 0x4b, 0x3, 0x2, 0x2, 0x2, 0xe, 
       0x57, 0x3, 0x2, 0x2, 0x2, 0x10, 0x59, 0x3, 0x2, 0x2, 0x2, 0x12, 0x5b, 
       0x3, 0x2, 0x2, 0x2, 0x14, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x16, 0x1b, 0x5, 
       0x4, 0x3, 0x2, 0x17, 0x18, 0x7, 0x3, 0x2, 0x2, 0x18, 0x1a, 0x5, 0x4, 
       0x3, 0x2, 0x19, 0x17, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1d, 0x3, 0x2, 0x2, 
       0x2, 0x1b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 0x3, 0x2, 0x2, 0x2, 
       0x1c, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1e, 
       0x16, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 
       0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x9, 0x2, 0x2, 0x2, 0x21, 0x3, 0x3, 
       0x2, 0x2, 0x2, 0x22, 0x23, 0x5, 0x12, 0xa, 0x2, 0x23, 0x24, 0x7, 
       0x4, 0x2, 0x2, 0x24, 0x25, 0x7, 0x5, 0x2, 0x2, 0x25, 0x26, 0x5, 0x6, 
       0x4, 0x2, 0x26, 0x2b, 0x7, 0x6, 0x2, 0x2, 0x27, 0x28, 0x7, 0x5, 0x2, 
       0x2, 0x28, 0x29, 0x5, 0xa, 0x6, 0x2, 0x29, 0x2a, 0x7, 0x6, 0x2, 0x2, 
       0x2a, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x27, 0x3, 0x2, 0x2, 0x2, 0x2b, 
       0x2c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x32, 
       0x5, 0x8, 0x5, 0x2, 0x2e, 0x2f, 0x7, 0x7, 0x2, 0x2, 0x2f, 0x31, 0x5, 
       0x8, 0x5, 0x2, 0x30, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x31, 0x34, 0x3, 0x2, 
       0x2, 0x2, 0x32, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x3, 0x2, 0x2, 
       0x2, 0x33, 0x36, 0x3, 0x2, 0x2, 0x2, 0x34, 0x32, 0x3, 0x2, 0x2, 0x2, 
       0x35, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 
       0x7, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x5, 0x12, 0xa, 0x2, 0x38, 0x39, 
       0x7, 0x4, 0x2, 0x2, 0x39, 0x3e, 0x5, 0x14, 0xb, 0x2, 0x3a, 0x3b, 
       0x7, 0x8, 0x2, 0x2, 0x3b, 0x3d, 0x5, 0x14, 0xb, 0x2, 0x3c, 0x3a, 
       0x3, 0x2, 0x2, 0x2, 0x3d, 0x40, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3c, 0x3, 
       0x2, 0x2, 0x2, 0x3e, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x9, 0x3, 0x2, 
       0x2, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x41, 0x46, 0x5, 0xc, 0x7, 
       0x2, 0x42, 0x43, 0x7, 0x7, 0x2, 0x2, 0x43, 0x45, 0x5, 0xc, 0x7, 0x2, 
       0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x45, 0x48, 0x3, 0x2, 0x2, 0x2, 0x46, 
       0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x3, 0x2, 0x2, 0x2, 0x47, 0x4a, 
       0x3, 0x2, 0x2, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 0x49, 0x41, 0x3, 
       0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 0xb, 0x3, 0x2, 
       0x2, 0x2, 0x4b, 0x4c, 0x5, 0xe, 0x8, 0x2, 0x4c, 0x4d, 0x7, 0x9, 0x2, 
       0x2, 0x4d, 0x4e, 0x5, 0x10, 0x9, 0x2, 0x4e, 0x4f, 0x7, 0x4, 0x2, 
       0x2, 0x4f, 0x54, 0x5, 0x14, 0xb, 0x2, 0x50, 0x51, 0x7, 0x8, 0x2, 
       0x2, 0x51, 0x53, 0x5, 0x14, 0xb, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 
       0x2, 0x53, 0x56, 0x3, 0x2, 0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 
       0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0xd, 0x3, 0x2, 0x2, 0x2, 0x56, 
       0x54, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x7, 0xb, 0x2, 0x2, 0x58, 0xf, 
       0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x7, 0xc, 0x2, 0x2, 0x5a, 0x11, 0x3, 
       0x2, 0x2, 0x2, 0x5b, 0x5c, 0x9, 0x3, 0x2, 0x2, 0x5c, 0x13, 0x3, 0x2, 
       0x2, 0x2, 0x5d, 0x5e, 0x9, 0x4, 0x2, 0x2, 0x5e, 0x15, 0x3, 0x2, 0x2, 
       0x2, 0xb, 0x1b, 0x1e, 0x2b, 0x32, 0x35, 0x3e, 0x46, 0x49, 0x54, 
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
