
// Generated from demo/test1/PTG.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "PTGParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by PTGParser.
 */
class  PTGListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterPtg(PTGParser::PtgContext *ctx) = 0;
  virtual void exitPtg(PTGParser::PtgContext *ctx) = 0;

  virtual void enterEntry(PTGParser::EntryContext *ctx) = 0;
  virtual void exitEntry(PTGParser::EntryContext *ctx) = 0;

  virtual void enterVars(PTGParser::VarsContext *ctx) = 0;
  virtual void exitVars(PTGParser::VarsContext *ctx) = 0;

  virtual void enterVarentry(PTGParser::VarentryContext *ctx) = 0;
  virtual void exitVarentry(PTGParser::VarentryContext *ctx) = 0;

  virtual void enterFields(PTGParser::FieldsContext *ctx) = 0;
  virtual void exitFields(PTGParser::FieldsContext *ctx) = 0;

  virtual void enterFieldentry(PTGParser::FieldentryContext *ctx) = 0;
  virtual void exitFieldentry(PTGParser::FieldentryContext *ctx) = 0;

  virtual void enterBciKey(PTGParser::BciKeyContext *ctx) = 0;
  virtual void exitBciKey(PTGParser::BciKeyContext *ctx) = 0;

  virtual void enterBciVal(PTGParser::BciValContext *ctx) = 0;
  virtual void exitBciVal(PTGParser::BciValContext *ctx) = 0;

  virtual void enterBciKeyField(PTGParser::BciKeyFieldContext *ctx) = 0;
  virtual void exitBciKeyField(PTGParser::BciKeyFieldContext *ctx) = 0;

  virtual void enterField(PTGParser::FieldContext *ctx) = 0;
  virtual void exitField(PTGParser::FieldContext *ctx) = 0;


};
