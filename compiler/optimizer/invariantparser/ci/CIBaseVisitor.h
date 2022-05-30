
// Generated from CI.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "CIVisitor.h"


namespace CI {

/**
 * This class provides an empty implementation of CIVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CIBaseVisitor : public CIVisitor {
public:

  virtual antlrcpp::Any visitCi(CIParser::CiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCiEntry(CIParser::CiEntryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCiBciEntry2(CIParser::CiBciEntry2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCiBciEntry(CIParser::CiBciEntryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCiEntries(CIParser::CiEntriesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallerIndex(CIParser::CallerIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBciKey(CIParser::BciKeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBciVal(CIParser::BciValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFieldKey(CIParser::FieldKeyContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace CI
