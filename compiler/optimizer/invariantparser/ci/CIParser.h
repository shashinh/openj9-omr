
// Generated from CI.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"


namespace CI {


class  CIParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, NIL = 4, STRING = 5, CONST = 6, GLOBAL = 7, 
    NUMS = 8, ALPHAS = 9, NEWLINE = 10, ALL = 11
  };

  enum {
    RuleCi = 0, RuleCiEntry = 1, RuleCiBciEntry2 = 2, RuleCiBciEntry = 3, 
    RuleCiEntries = 4, RuleCallerIndex = 5, RuleBciKey = 6, RuleBciVal = 7, 
    RuleFieldKey = 8
  };

  explicit CIParser(antlr4::TokenStream *input);
  ~CIParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class CiContext;
  class CiEntryContext;
  class CiBciEntry2Context;
  class CiBciEntryContext;
  class CiEntriesContext;
  class CallerIndexContext;
  class BciKeyContext;
  class BciValContext;
  class FieldKeyContext; 

  class  CiContext : public antlr4::ParserRuleContext {
  public:
    CiContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    antlr4::tree::TerminalNode *EOF();
    std::vector<CiEntryContext *> ciEntry();
    CiEntryContext* ciEntry(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CiContext* ci();

  class  CiEntryContext : public antlr4::ParserRuleContext {
  public:
    CiEntryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<CiBciEntryContext *> ciBciEntry();
    CiBciEntryContext* ciBciEntry(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CiEntryContext* ciEntry();

  class  CiBciEntry2Context : public antlr4::ParserRuleContext {
  public:
    CiBciEntry2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CiBciEntry2Context* ciBciEntry2();

  class  CiBciEntryContext : public antlr4::ParserRuleContext {
  public:
    CiBciEntryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CiEntriesContext *ciEntries();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *CONST();
    antlr4::tree::TerminalNode *GLOBAL();
    antlr4::tree::TerminalNode *NIL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CiBciEntryContext* ciBciEntry();

  class  CiEntriesContext : public antlr4::ParserRuleContext {
  public:
    CiEntriesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CallerIndexContext *callerIndex();
    std::vector<BciValContext *> bciVal();
    BciValContext* bciVal(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CiEntriesContext* ciEntries();

  class  CallerIndexContext : public antlr4::ParserRuleContext {
  public:
    CallerIndexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CallerIndexContext* callerIndex();

  class  BciKeyContext : public antlr4::ParserRuleContext {
  public:
    BciKeyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BciKeyContext* bciKey();

  class  BciValContext : public antlr4::ParserRuleContext {
  public:
    BciValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMS();
    antlr4::tree::TerminalNode *NIL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BciValContext* bciVal();

  class  FieldKeyContext : public antlr4::ParserRuleContext {
  public:
    FieldKeyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALPHAS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldKeyContext* fieldKey();


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

}  // namespace CI
