#include "CIBaseVisitor.h"
#include <algorithm>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
//#include "structs.h"
using namespace CI;

class CIBuilderVisitor : public CIBaseVisitor {
public:

  virtual antlrcpp::Any visitCi(CIParser::CiContext *ctx) override; 
  virtual antlrcpp::Any visitCiEntry(CIParser::CiEntryContext *ctx) override;

//  virtual antlrcpp::Any visitCiBciEntry2(CIParser::CiBciEntry2Context *ctx) override;

  virtual antlrcpp::Any visitCiBciEntry(CIParser::CiBciEntryContext *ctx) override;

  virtual antlrcpp::Any visitCiEntries(CIParser::CiEntriesContext *ctx) override;

 virtual antlrcpp::Any visitCallerIndex(CIParser::CallerIndexContext *ctx) override;

//  virtual antlrcpp::Any visitBciKey(CIParser::BciKeyContext *ctx) override;

 virtual antlrcpp::Any visitBciVal(CIParser::BciValContext *ctx) override;

 // virtual antlrcpp::Any visitFieldKey(CIParser::FieldKeyContext *ctx) override;


};