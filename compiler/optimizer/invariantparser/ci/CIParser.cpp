
// Generated from CI.g4 by ANTLR 4.9.2


#include "CIVisitor.h"

#include "CIParser.h"


using namespace antlrcpp;
using namespace CI;
using namespace antlr4;

CIParser::CIParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CIParser::~CIParser() {
  delete _interpreter;
}

std::string CIParser::getGrammarFileName() const {
  return "CI.g4";
}

const std::vector<std::string>& CIParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CIParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CiContext ------------------------------------------------------------------

CIParser::CiContext::CiContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CIParser::CiContext::NEWLINE() {
  return getTokens(CIParser::NEWLINE);
}

tree::TerminalNode* CIParser::CiContext::NEWLINE(size_t i) {
  return getToken(CIParser::NEWLINE, i);
}

tree::TerminalNode* CIParser::CiContext::EOF() {
  return getToken(CIParser::EOF, 0);
}

std::vector<CIParser::CiEntryContext *> CIParser::CiContext::ciEntry() {
  return getRuleContexts<CIParser::CiEntryContext>();
}

CIParser::CiEntryContext* CIParser::CiContext::ciEntry(size_t i) {
  return getRuleContext<CIParser::CiEntryContext>(i);
}


size_t CIParser::CiContext::getRuleIndex() const {
  return CIParser::RuleCi;
}


antlrcpp::Any CIParser::CiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CIVisitor*>(visitor))
    return parserVisitor->visitCi(this);
  else
    return visitor->visitChildren(this);
}

CIParser::CiContext* CIParser::ci() {
  CiContext *_localctx = _tracker.createInstance<CiContext>(_ctx, getState());
  enterRule(_localctx, 0, CIParser::RuleCi);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(26);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CIParser::NIL)
      | (1ULL << CIParser::STRING)
      | (1ULL << CIParser::CONST)
      | (1ULL << CIParser::GLOBAL)
      | (1ULL << CIParser::NUMS))) != 0)) {
      setState(18);
      ciEntry();
      setState(23);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(19);
          match(CIParser::NEWLINE);
          setState(20);
          ciEntry(); 
        }
        setState(25);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
      }
    }
    setState(28);
    _la = _input->LA(1);
    if (!(_la == CIParser::EOF

    || _la == CIParser::NEWLINE)) {
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

//----------------- CiEntryContext ------------------------------------------------------------------

CIParser::CiEntryContext::CiEntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CIParser::CiBciEntryContext *> CIParser::CiEntryContext::ciBciEntry() {
  return getRuleContexts<CIParser::CiBciEntryContext>();
}

CIParser::CiBciEntryContext* CIParser::CiEntryContext::ciBciEntry(size_t i) {
  return getRuleContext<CIParser::CiBciEntryContext>(i);
}


size_t CIParser::CiEntryContext::getRuleIndex() const {
  return CIParser::RuleCiEntry;
}


antlrcpp::Any CIParser::CiEntryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CIVisitor*>(visitor))
    return parserVisitor->visitCiEntry(this);
  else
    return visitor->visitChildren(this);
}

CIParser::CiEntryContext* CIParser::ciEntry() {
  CiEntryContext *_localctx = _tracker.createInstance<CiEntryContext>(_ctx, getState());
  enterRule(_localctx, 2, CIParser::RuleCiEntry);
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
    setState(30);
    ciBciEntry();
    setState(35);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CIParser::T__0) {
      setState(31);
      match(CIParser::T__0);

      setState(32);
      ciBciEntry();
      setState(37);
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

//----------------- CiBciEntry2Context ------------------------------------------------------------------

CIParser::CiBciEntry2Context::CiBciEntry2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CIParser::CiBciEntry2Context::NUMS() {
  return getToken(CIParser::NUMS, 0);
}


size_t CIParser::CiBciEntry2Context::getRuleIndex() const {
  return CIParser::RuleCiBciEntry2;
}


antlrcpp::Any CIParser::CiBciEntry2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CIVisitor*>(visitor))
    return parserVisitor->visitCiBciEntry2(this);
  else
    return visitor->visitChildren(this);
}

CIParser::CiBciEntry2Context* CIParser::ciBciEntry2() {
  CiBciEntry2Context *_localctx = _tracker.createInstance<CiBciEntry2Context>(_ctx, getState());
  enterRule(_localctx, 4, CIParser::RuleCiBciEntry2);

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
    match(CIParser::NUMS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CiBciEntryContext ------------------------------------------------------------------

CIParser::CiBciEntryContext::CiBciEntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CIParser::CiEntriesContext* CIParser::CiBciEntryContext::ciEntries() {
  return getRuleContext<CIParser::CiEntriesContext>(0);
}

tree::TerminalNode* CIParser::CiBciEntryContext::STRING() {
  return getToken(CIParser::STRING, 0);
}

tree::TerminalNode* CIParser::CiBciEntryContext::CONST() {
  return getToken(CIParser::CONST, 0);
}

tree::TerminalNode* CIParser::CiBciEntryContext::GLOBAL() {
  return getToken(CIParser::GLOBAL, 0);
}

tree::TerminalNode* CIParser::CiBciEntryContext::NIL() {
  return getToken(CIParser::NIL, 0);
}


size_t CIParser::CiBciEntryContext::getRuleIndex() const {
  return CIParser::RuleCiBciEntry;
}


antlrcpp::Any CIParser::CiBciEntryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CIVisitor*>(visitor))
    return parserVisitor->visitCiBciEntry(this);
  else
    return visitor->visitChildren(this);
}

CIParser::CiBciEntryContext* CIParser::ciBciEntry() {
  CiBciEntryContext *_localctx = _tracker.createInstance<CiBciEntryContext>(_ctx, getState());
  enterRule(_localctx, 6, CIParser::RuleCiBciEntry);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(45);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CIParser::NUMS: {
        enterOuterAlt(_localctx, 1);
        setState(40);
        ciEntries();
        break;
      }

      case CIParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(41);
        match(CIParser::STRING);
        break;
      }

      case CIParser::CONST: {
        enterOuterAlt(_localctx, 3);
        setState(42);
        match(CIParser::CONST);
        break;
      }

      case CIParser::GLOBAL: {
        enterOuterAlt(_localctx, 4);
        setState(43);
        match(CIParser::GLOBAL);
        break;
      }

      case CIParser::NIL: {
        enterOuterAlt(_localctx, 5);
        setState(44);
        match(CIParser::NIL);
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

CIParser::CiEntriesContext::CiEntriesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CIParser::CallerIndexContext* CIParser::CiEntriesContext::callerIndex() {
  return getRuleContext<CIParser::CallerIndexContext>(0);
}

std::vector<CIParser::BciValContext *> CIParser::CiEntriesContext::bciVal() {
  return getRuleContexts<CIParser::BciValContext>();
}

CIParser::BciValContext* CIParser::CiEntriesContext::bciVal(size_t i) {
  return getRuleContext<CIParser::BciValContext>(i);
}


size_t CIParser::CiEntriesContext::getRuleIndex() const {
  return CIParser::RuleCiEntries;
}


antlrcpp::Any CIParser::CiEntriesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CIVisitor*>(visitor))
    return parserVisitor->visitCiEntries(this);
  else
    return visitor->visitChildren(this);
}

CIParser::CiEntriesContext* CIParser::ciEntries() {
  CiEntriesContext *_localctx = _tracker.createInstance<CiEntriesContext>(_ctx, getState());
  enterRule(_localctx, 8, CIParser::RuleCiEntries);
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
    setState(47);
    callerIndex();
    setState(48);
    match(CIParser::T__1);

    setState(49);
    bciVal();
    setState(54);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CIParser::T__2) {
      setState(50);
      match(CIParser::T__2);

      setState(51);
      bciVal();
      setState(56);
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

CIParser::CallerIndexContext::CallerIndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CIParser::CallerIndexContext::NUMS() {
  return getToken(CIParser::NUMS, 0);
}


size_t CIParser::CallerIndexContext::getRuleIndex() const {
  return CIParser::RuleCallerIndex;
}


antlrcpp::Any CIParser::CallerIndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CIVisitor*>(visitor))
    return parserVisitor->visitCallerIndex(this);
  else
    return visitor->visitChildren(this);
}

CIParser::CallerIndexContext* CIParser::callerIndex() {
  CallerIndexContext *_localctx = _tracker.createInstance<CallerIndexContext>(_ctx, getState());
  enterRule(_localctx, 10, CIParser::RuleCallerIndex);

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
    match(CIParser::NUMS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BciKeyContext ------------------------------------------------------------------

CIParser::BciKeyContext::BciKeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CIParser::BciKeyContext::NUMS() {
  return getToken(CIParser::NUMS, 0);
}


size_t CIParser::BciKeyContext::getRuleIndex() const {
  return CIParser::RuleBciKey;
}


antlrcpp::Any CIParser::BciKeyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CIVisitor*>(visitor))
    return parserVisitor->visitBciKey(this);
  else
    return visitor->visitChildren(this);
}

CIParser::BciKeyContext* CIParser::bciKey() {
  BciKeyContext *_localctx = _tracker.createInstance<BciKeyContext>(_ctx, getState());
  enterRule(_localctx, 12, CIParser::RuleBciKey);

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
    match(CIParser::NUMS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BciValContext ------------------------------------------------------------------

CIParser::BciValContext::BciValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CIParser::BciValContext::NUMS() {
  return getToken(CIParser::NUMS, 0);
}

tree::TerminalNode* CIParser::BciValContext::NIL() {
  return getToken(CIParser::NIL, 0);
}


size_t CIParser::BciValContext::getRuleIndex() const {
  return CIParser::RuleBciVal;
}


antlrcpp::Any CIParser::BciValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CIVisitor*>(visitor))
    return parserVisitor->visitBciVal(this);
  else
    return visitor->visitChildren(this);
}

CIParser::BciValContext* CIParser::bciVal() {
  BciValContext *_localctx = _tracker.createInstance<BciValContext>(_ctx, getState());
  enterRule(_localctx, 14, CIParser::RuleBciVal);
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
    setState(61);
    _la = _input->LA(1);
    if (!(_la == CIParser::NIL

    || _la == CIParser::NUMS)) {
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

CIParser::FieldKeyContext::FieldKeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CIParser::FieldKeyContext::ALPHAS() {
  return getToken(CIParser::ALPHAS, 0);
}


size_t CIParser::FieldKeyContext::getRuleIndex() const {
  return CIParser::RuleFieldKey;
}


antlrcpp::Any CIParser::FieldKeyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CIVisitor*>(visitor))
    return parserVisitor->visitFieldKey(this);
  else
    return visitor->visitChildren(this);
}

CIParser::FieldKeyContext* CIParser::fieldKey() {
  FieldKeyContext *_localctx = _tracker.createInstance<FieldKeyContext>(_ctx, getState());
  enterRule(_localctx, 16, CIParser::RuleFieldKey);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    match(CIParser::ALPHAS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> CIParser::_decisionToDFA;
atn::PredictionContextCache CIParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CIParser::_atn;
std::vector<uint16_t> CIParser::_serializedATN;

std::vector<std::string> CIParser::_ruleNames = {
  "ci", "ciEntry", "ciBciEntry2", "ciBciEntry", "ciEntries", "callerIndex", 
  "bciKey", "bciVal", "fieldKey"
};

std::vector<std::string> CIParser::_literalNames = {
  "", "' '", "'-'", "'.'", "'N'", "'S'", "'C'", "'G'"
};

std::vector<std::string> CIParser::_symbolicNames = {
  "", "", "", "", "NIL", "STRING", "CONST", "GLOBAL", "NUMS", "ALPHAS", 
  "NEWLINE", "ALL"
};

dfa::Vocabulary CIParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CIParser::_tokenNames;

CIParser::Initializer::Initializer() {
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
       0x3, 0xd, 0x44, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x18, 0xa, 0x2, 0xc, 0x2, 
       0xe, 0x2, 0x1b, 0xb, 0x2, 0x5, 0x2, 0x1d, 0xa, 0x2, 0x3, 0x2, 0x3, 
       0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x24, 0xa, 0x3, 0xc, 
       0x3, 0xe, 0x3, 0x27, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x30, 0xa, 0x5, 0x3, 
       0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x37, 0xa, 
       0x6, 0xc, 0x6, 0xe, 0x6, 0x3a, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
       0x2, 0x2, 0xb, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x2, 
       0x4, 0x3, 0x3, 0xc, 0xc, 0x4, 0x2, 0x6, 0x6, 0xa, 0xa, 0x2, 0x42, 
       0x2, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x4, 0x20, 0x3, 0x2, 0x2, 0x2, 0x6, 
       0x28, 0x3, 0x2, 0x2, 0x2, 0x8, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xa, 0x31, 
       0x3, 0x2, 0x2, 0x2, 0xc, 0x3b, 0x3, 0x2, 0x2, 0x2, 0xe, 0x3d, 0x3, 
       0x2, 0x2, 0x2, 0x10, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x12, 0x41, 0x3, 0x2, 
       0x2, 0x2, 0x14, 0x19, 0x5, 0x4, 0x3, 0x2, 0x15, 0x16, 0x7, 0xc, 0x2, 
       0x2, 0x16, 0x18, 0x5, 0x4, 0x3, 0x2, 0x17, 0x15, 0x3, 0x2, 0x2, 0x2, 
       0x18, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x19, 0x17, 0x3, 0x2, 0x2, 0x2, 0x19, 
       0x1a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x19, 
       0x3, 0x2, 0x2, 0x2, 0x1c, 0x14, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x3, 
       0x2, 0x2, 0x2, 0x1d, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x9, 0x2, 
       0x2, 0x2, 0x1f, 0x3, 0x3, 0x2, 0x2, 0x2, 0x20, 0x25, 0x5, 0x8, 0x5, 
       0x2, 0x21, 0x22, 0x7, 0x3, 0x2, 0x2, 0x22, 0x24, 0x5, 0x8, 0x5, 0x2, 
       0x23, 0x21, 0x3, 0x2, 0x2, 0x2, 0x24, 0x27, 0x3, 0x2, 0x2, 0x2, 0x25, 
       0x23, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x3, 0x2, 0x2, 0x2, 0x26, 0x5, 
       0x3, 0x2, 0x2, 0x2, 0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x7, 
       0xa, 0x2, 0x2, 0x29, 0x7, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x30, 0x5, 0xa, 
       0x6, 0x2, 0x2b, 0x30, 0x7, 0x7, 0x2, 0x2, 0x2c, 0x30, 0x7, 0x8, 0x2, 
       0x2, 0x2d, 0x30, 0x7, 0x9, 0x2, 0x2, 0x2e, 0x30, 0x7, 0x6, 0x2, 0x2, 
       0x2f, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2f, 
       0x2c, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2e, 
       0x3, 0x2, 0x2, 0x2, 0x30, 0x9, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x5, 
       0xc, 0x7, 0x2, 0x32, 0x33, 0x7, 0x4, 0x2, 0x2, 0x33, 0x38, 0x5, 0x10, 
       0x9, 0x2, 0x34, 0x35, 0x7, 0x5, 0x2, 0x2, 0x35, 0x37, 0x5, 0x10, 
       0x9, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x37, 0x3a, 0x3, 0x2, 0x2, 
       0x2, 0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x3, 0x2, 0x2, 0x2, 
       0x39, 0xb, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3b, 
       0x3c, 0x7, 0xa, 0x2, 0x2, 0x3c, 0xd, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 
       0x7, 0xa, 0x2, 0x2, 0x3e, 0xf, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x9, 
       0x3, 0x2, 0x2, 0x40, 0x11, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x7, 0xb, 
       0x2, 0x2, 0x42, 0x13, 0x3, 0x2, 0x2, 0x2, 0x7, 0x19, 0x1c, 0x25, 
       0x2f, 0x38, 
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

CIParser::Initializer CIParser::_init;
