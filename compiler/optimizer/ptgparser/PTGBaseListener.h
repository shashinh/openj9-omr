
// Generated from demo/test1/PTG.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "PTGListener.h"


/**
 * This class provides an empty implementation of PTGListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  PTGBaseListener : public PTGListener {
public:

  virtual void enterPtg(PTGParser::PtgContext * /*ctx*/) override { }
  virtual void exitPtg(PTGParser::PtgContext * /*ctx*/) override { }

  virtual void enterEntry(PTGParser::EntryContext * /*ctx*/) override { }
  virtual void exitEntry(PTGParser::EntryContext * /*ctx*/) override { }

  virtual void enterVars(PTGParser::VarsContext * /*ctx*/) override { }
  virtual void exitVars(PTGParser::VarsContext * /*ctx*/) override { }

  virtual void enterVarentry(PTGParser::VarentryContext * /*ctx*/) override { }
  virtual void exitVarentry(PTGParser::VarentryContext * /*ctx*/) override { }

  virtual void enterFields(PTGParser::FieldsContext * /*ctx*/) override { }
  virtual void exitFields(PTGParser::FieldsContext * /*ctx*/) override { }

  virtual void enterFieldentry(PTGParser::FieldentryContext * /*ctx*/) override { }
  virtual void exitFieldentry(PTGParser::FieldentryContext * /*ctx*/) override { }

  virtual void enterBciKey(PTGParser::BciKeyContext * /*ctx*/) override { }
  virtual void exitBciKey(PTGParser::BciKeyContext * /*ctx*/) override { }

  virtual void enterBciVal(PTGParser::BciValContext * /*ctx*/) override { }
  virtual void exitBciVal(PTGParser::BciValContext * /*ctx*/) override { }

  virtual void enterBciKeyField(PTGParser::BciKeyFieldContext * /*ctx*/) override { }
  virtual void exitBciKeyField(PTGParser::BciKeyFieldContext * /*ctx*/) override { }

  virtual void enterField(PTGParser::FieldContext * /*ctx*/) override { }
  virtual void exitField(PTGParser::FieldContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};
