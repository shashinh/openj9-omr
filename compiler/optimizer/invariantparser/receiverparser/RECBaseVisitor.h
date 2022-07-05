
// Generated from REC.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "RECVisitor.h"


namespace REC {

/**
 * This class provides an empty implementation of RECVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  RECBaseVisitor : public RECVisitor {
public:

  virtual antlrcpp::Any visitRecs(RECParser::RecsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntry(RECParser::EntryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClazzes(RECParser::ClazzesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClazz(RECParser::ClazzContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBciKey(RECParser::BciKeyContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace REC
