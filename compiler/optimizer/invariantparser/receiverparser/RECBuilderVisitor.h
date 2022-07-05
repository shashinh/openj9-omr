#include "RECBaseVisitor.h"
#include <algorithm>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

using namespace REC;

class RECBuilderVisitor : public RECBaseVisitor { 

public:
  virtual antlrcpp::Any visitRecs(RECParser::RecsContext *ctx) override;
  virtual antlrcpp::Any visitClazzes(RECParser::ClazzesContext *ctx) override;
  virtual antlrcpp::Any visitBciKey(RECParser::BciKeyContext *ctx) override;
  virtual antlrcpp::Any visitClazz(RECParser::ClazzContext *ctx) override;

};
