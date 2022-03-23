
// Generated from PTG.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  PTGParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    NIL = 8, NUMS = 9, ALPHAS = 10, NEWLINE = 11, ALL = 12
  };

  enum {
    RulePtg = 0, RuleEntry = 1, RuleVars = 2, RuleVarentry = 3, RuleFields = 4, 
    RuleFieldentry = 5, RuleCiBciEntry = 6, RuleCallerIndex = 7, RuleBciKey = 8, 
    RuleBciVal = 9, RuleBciKeyField = 10, RuleField = 11
  };

  explicit PTGParser(antlr4::TokenStream *input);
  ~PTGParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class PtgContext;
  class EntryContext;
  class VarsContext;
  class VarentryContext;
  class FieldsContext;
  class FieldentryContext;
  class CiBciEntryContext;
  class CallerIndexContext;
  class BciKeyContext;
  class BciValContext;
  class BciKeyFieldContext;
  class FieldContext; 

  class  PtgContext : public antlr4::ParserRuleContext {
  public:
    PtgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEWLINE();
    antlr4::tree::TerminalNode *EOF();
    std::vector<EntryContext *> entry();
    EntryContext* entry(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PtgContext* ptg();

  class  EntryContext : public antlr4::ParserRuleContext {
  public:
    EntryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BciKeyContext *bciKey();
    VarsContext *vars();
    FieldsContext *fields();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EntryContext* entry();

  class  VarsContext : public antlr4::ParserRuleContext {
  public:
    VarsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VarentryContext *> varentry();
    VarentryContext* varentry(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarsContext* vars();

  class  VarentryContext : public antlr4::ParserRuleContext {
  public:
    VarentryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BciKeyContext *bciKey();
    std::vector<CiBciEntryContext *> ciBciEntry();
    CiBciEntryContext* ciBciEntry(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarentryContext* varentry();

  class  FieldsContext : public antlr4::ParserRuleContext {
  public:
    FieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FieldentryContext *> fieldentry();
    FieldentryContext* fieldentry(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldsContext* fields();

  class  FieldentryContext : public antlr4::ParserRuleContext {
  public:
    FieldentryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BciKeyFieldContext *bciKeyField();
    FieldContext *field();
    std::vector<BciValContext *> bciVal();
    BciValContext* bciVal(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldentryContext* fieldentry();

  class  CiBciEntryContext : public antlr4::ParserRuleContext {
  public:
    CiBciEntryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NIL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CiBciEntryContext* ciBciEntry();

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
    antlr4::tree::TerminalNode *ALL();
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

  class  BciKeyFieldContext : public antlr4::ParserRuleContext {
  public:
    BciKeyFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BciKeyFieldContext* bciKeyField();

  class  FieldContext : public antlr4::ParserRuleContext {
  public:
    FieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALPHAS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldContext* field();


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

