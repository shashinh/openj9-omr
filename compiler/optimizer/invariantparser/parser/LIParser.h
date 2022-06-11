
// Generated from LI.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"


namespace LI {


class  LIParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, NIL = 9, STRING = 10, CONST = 11, GLOBAL = 12, NUMS = 13, 
    ALPHAS = 14, NEWLINE = 15, ALL = 16
  };

  enum {
    RulePtg = 0, RuleEntry = 1, RuleVars = 2, RuleVarentry = 3, RuleFields = 4, 
    RuleFieldentry = 5, RuleField = 6, RuleCiBciEntry = 7, RuleCiEntries = 8, 
    RuleCallerIndex = 9, RuleBciKey = 10, RuleBciVal = 11, RuleFieldKey = 12
  };

  explicit LIParser(antlr4::TokenStream *input);
  ~LIParser();

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
  class FieldContext;
  class CiBciEntryContext;
  class CiEntriesContext;
  class CallerIndexContext;
  class BciKeyContext;
  class BciValContext;
  class FieldKeyContext; 

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
    CallerIndexContext *callerIndex();
    BciKeyContext *bciKey();
    std::vector<FieldContext *> field();
    FieldContext* field(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldentryContext* fieldentry();

  class  FieldContext : public antlr4::ParserRuleContext {
  public:
    FieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FieldKeyContext *fieldKey();
    std::vector<CiBciEntryContext *> ciBciEntry();
    CiBciEntryContext* ciBciEntry(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldContext* field();

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

}  // namespace LI
