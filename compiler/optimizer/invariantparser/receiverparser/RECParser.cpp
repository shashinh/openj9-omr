
// Generated from REC.g4 by ANTLR 4.9.2


#include "RECVisitor.h"

#include "RECParser.h"


using namespace antlrcpp;
using namespace REC;
using namespace antlr4;

RECParser::RECParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

RECParser::~RECParser() {
  delete _interpreter;
}

std::string RECParser::getGrammarFileName() const {
  return "REC.g4";
}

const std::vector<std::string>& RECParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& RECParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- RecsContext ------------------------------------------------------------------

RECParser::RecsContext::RecsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RECParser::RecsContext::NEWLINE() {
  return getToken(RECParser::NEWLINE, 0);
}

tree::TerminalNode* RECParser::RecsContext::EOF() {
  return getToken(RECParser::EOF, 0);
}

std::vector<RECParser::EntryContext *> RECParser::RecsContext::entry() {
  return getRuleContexts<RECParser::EntryContext>();
}

RECParser::EntryContext* RECParser::RecsContext::entry(size_t i) {
  return getRuleContext<RECParser::EntryContext>(i);
}


size_t RECParser::RecsContext::getRuleIndex() const {
  return RECParser::RuleRecs;
}


antlrcpp::Any RECParser::RecsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RECVisitor*>(visitor))
    return parserVisitor->visitRecs(this);
  else
    return visitor->visitChildren(this);
}

RECParser::RecsContext* RECParser::recs() {
  RecsContext *_localctx = _tracker.createInstance<RecsContext>(_ctx, getState());
  enterRule(_localctx, 0, RECParser::RuleRecs);
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
    setState(15);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == RECParser::NUMS) {
      setState(10);
      entry();
      setState(11);
      match(RECParser::T__0);
      setState(17);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(18);
    _la = _input->LA(1);
    if (!(_la == RECParser::EOF

    || _la == RECParser::NEWLINE)) {
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

RECParser::EntryContext::EntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RECParser::BciKeyContext* RECParser::EntryContext::bciKey() {
  return getRuleContext<RECParser::BciKeyContext>(0);
}

RECParser::ClazzesContext* RECParser::EntryContext::clazzes() {
  return getRuleContext<RECParser::ClazzesContext>(0);
}


size_t RECParser::EntryContext::getRuleIndex() const {
  return RECParser::RuleEntry;
}


antlrcpp::Any RECParser::EntryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RECVisitor*>(visitor))
    return parserVisitor->visitEntry(this);
  else
    return visitor->visitChildren(this);
}

RECParser::EntryContext* RECParser::entry() {
  EntryContext *_localctx = _tracker.createInstance<EntryContext>(_ctx, getState());
  enterRule(_localctx, 2, RECParser::RuleEntry);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(20);
    bciKey();
    setState(21);
    match(RECParser::T__1);
    setState(22);
    clazzes();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClazzesContext ------------------------------------------------------------------

RECParser::ClazzesContext::ClazzesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RECParser::ClazzContext *> RECParser::ClazzesContext::clazz() {
  return getRuleContexts<RECParser::ClazzContext>();
}

RECParser::ClazzContext* RECParser::ClazzesContext::clazz(size_t i) {
  return getRuleContext<RECParser::ClazzContext>(i);
}


size_t RECParser::ClazzesContext::getRuleIndex() const {
  return RECParser::RuleClazzes;
}


antlrcpp::Any RECParser::ClazzesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RECVisitor*>(visitor))
    return parserVisitor->visitClazzes(this);
  else
    return visitor->visitChildren(this);
}

RECParser::ClazzesContext* RECParser::clazzes() {
  ClazzesContext *_localctx = _tracker.createInstance<ClazzesContext>(_ctx, getState());
  enterRule(_localctx, 4, RECParser::RuleClazzes);
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
    setState(24);
    clazz();
    setState(32);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RECParser::T__1) {
      setState(25);
      match(RECParser::T__1);
      setState(29);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == RECParser::NUMS) {
        setState(26);
        clazz();
        setState(31);
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

//----------------- ClazzContext ------------------------------------------------------------------

RECParser::ClazzContext::ClazzContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RECParser::ClazzContext::NUMS() {
  return getToken(RECParser::NUMS, 0);
}


size_t RECParser::ClazzContext::getRuleIndex() const {
  return RECParser::RuleClazz;
}


antlrcpp::Any RECParser::ClazzContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RECVisitor*>(visitor))
    return parserVisitor->visitClazz(this);
  else
    return visitor->visitChildren(this);
}

RECParser::ClazzContext* RECParser::clazz() {
  ClazzContext *_localctx = _tracker.createInstance<ClazzContext>(_ctx, getState());
  enterRule(_localctx, 6, RECParser::RuleClazz);

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
    match(RECParser::NUMS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BciKeyContext ------------------------------------------------------------------

RECParser::BciKeyContext::BciKeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RECParser::BciKeyContext::NUMS() {
  return getToken(RECParser::NUMS, 0);
}


size_t RECParser::BciKeyContext::getRuleIndex() const {
  return RECParser::RuleBciKey;
}


antlrcpp::Any RECParser::BciKeyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RECVisitor*>(visitor))
    return parserVisitor->visitBciKey(this);
  else
    return visitor->visitChildren(this);
}

RECParser::BciKeyContext* RECParser::bciKey() {
  BciKeyContext *_localctx = _tracker.createInstance<BciKeyContext>(_ctx, getState());
  enterRule(_localctx, 8, RECParser::RuleBciKey);

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
    match(RECParser::NUMS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> RECParser::_decisionToDFA;
atn::PredictionContextCache RECParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN RECParser::_atn;
std::vector<uint16_t> RECParser::_serializedATN;

std::vector<std::string> RECParser::_ruleNames = {
  "recs", "entry", "clazzes", "clazz", "bciKey"
};

std::vector<std::string> RECParser::_literalNames = {
  "", "';'", "' '"
};

std::vector<std::string> RECParser::_symbolicNames = {
  "", "", "", "NUMS", "NEWLINE"
};

dfa::Vocabulary RECParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> RECParser::_tokenNames;

RECParser::Initializer::Initializer() {
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
       0x3, 0x6, 0x29, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x3, 0x2, 0x3, 
       0x2, 0x3, 0x2, 0x7, 0x2, 0x10, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x13, 
       0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x1e, 0xa, 0x4, 0xc, 
       0x4, 0xe, 0x4, 0x21, 0xb, 0x4, 0x5, 0x4, 0x23, 0xa, 0x4, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x2, 0x2, 0x7, 0x2, 0x4, 
       0x6, 0x8, 0xa, 0x2, 0x3, 0x3, 0x3, 0x6, 0x6, 0x2, 0x26, 0x2, 0x11, 
       0x3, 0x2, 0x2, 0x2, 0x4, 0x16, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1a, 0x3, 
       0x2, 0x2, 0x2, 0x8, 0x24, 0x3, 0x2, 0x2, 0x2, 0xa, 0x26, 0x3, 0x2, 
       0x2, 0x2, 0xc, 0xd, 0x5, 0x4, 0x3, 0x2, 0xd, 0xe, 0x7, 0x3, 0x2, 
       0x2, 0xe, 0x10, 0x3, 0x2, 0x2, 0x2, 0xf, 0xc, 0x3, 0x2, 0x2, 0x2, 
       0x10, 0x13, 0x3, 0x2, 0x2, 0x2, 0x11, 0xf, 0x3, 0x2, 0x2, 0x2, 0x11, 
       0x12, 0x3, 0x2, 0x2, 0x2, 0x12, 0x14, 0x3, 0x2, 0x2, 0x2, 0x13, 0x11, 
       0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x9, 0x2, 0x2, 0x2, 0x15, 0x3, 0x3, 
       0x2, 0x2, 0x2, 0x16, 0x17, 0x5, 0xa, 0x6, 0x2, 0x17, 0x18, 0x7, 0x4, 
       0x2, 0x2, 0x18, 0x19, 0x5, 0x6, 0x4, 0x2, 0x19, 0x5, 0x3, 0x2, 0x2, 
       0x2, 0x1a, 0x22, 0x5, 0x8, 0x5, 0x2, 0x1b, 0x1f, 0x7, 0x4, 0x2, 0x2, 
       0x1c, 0x1e, 0x5, 0x8, 0x5, 0x2, 0x1d, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1e, 
       0x21, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 
       0x3, 0x2, 0x2, 0x2, 0x20, 0x23, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 
       0x2, 0x2, 0x2, 0x22, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x3, 0x2, 
       0x2, 0x2, 0x23, 0x7, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x7, 0x5, 0x2, 
       0x2, 0x25, 0x9, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x7, 0x5, 0x2, 0x2, 
       0x27, 0xb, 0x3, 0x2, 0x2, 0x2, 0x5, 0x11, 0x1f, 0x22, 
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

RECParser::Initializer RECParser::_init;
