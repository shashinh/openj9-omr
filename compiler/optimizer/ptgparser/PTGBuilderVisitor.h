#include "PTGBaseVisitor.h"
#include <algorithm>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

class PTGBuilderVisitor : public PTGBaseVisitor { 

public:

    antlrcpp::Any visitPtg(PTGParser::PtgContext *ctx) override;
    antlrcpp::Any visitVars(PTGParser::VarsContext *ctx) override;
    antlrcpp::Any visitFields(PTGParser::FieldsContext *ctx) override;
    antlrcpp::Any visitBciVal(PTGParser::BciValContext *ctx) override;
    antlrcpp::Any visitBciKey(PTGParser::BciKeyContext *ctx) override;
    antlrcpp::Any visitBciKeyField(PTGParser::BciKeyFieldContext *ctx) override;
    antlrcpp::Any visitField(PTGParser::FieldContext *ctx) override;

    

};