
// Generated from LI.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "LIVisitor.h"


/**
 * This class provides an empty implementation of LIVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  LIBaseVisitor : public LIVisitor {
public:

  virtual antlrcpp::Any visitPtg(LIParser::PtgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntry(LIParser::EntryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVars(LIParser::VarsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarentry(LIParser::VarentryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFields(LIParser::FieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFieldentry(LIParser::FieldentryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitField(LIParser::FieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCiBciEntry(LIParser::CiBciEntryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCiEntries(LIParser::CiEntriesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallerIndex(LIParser::CallerIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBciKey(LIParser::BciKeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBciVal(LIParser::BciValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFieldKey(LIParser::FieldKeyContext *ctx) override {
    return visitChildren(ctx);
  }


};

