#include "LIBaseVisitor.h"
#include <algorithm>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"

using namespace LI;

class LIBuilderVisitor : public LIBaseVisitor { 

public:

    virtual antlrcpp::Any visitPtg(LIParser::PtgContext *ctx) override;
    virtual antlrcpp::Any visitVars(LIParser::VarsContext *ctx) override;
    virtual antlrcpp::Any visitFields(LIParser::FieldsContext *ctx) override;
    virtual antlrcpp::Any visitBciVal(LIParser::BciValContext *ctx) override;
    virtual antlrcpp::Any visitBciKey(LIParser::BciKeyContext *ctx) override;
    //virtual antlrcpp::Any visitBciKeyField(LIParser::BciKeyFieldContext *ctx) override;
    //virtual antlrcpp::Any visitField(LIParser::FieldContext *ctx) override;
    virtual antlrcpp::Any visitCallerIndex(LIParser::CallerIndexContext *ctx);
    virtual antlrcpp::Any visitFieldKey(LIParser::FieldKeyContext *ctx);
    virtual std::set<Entry> processciBciEntrys(std::vector<LIParser::CiBciEntryContext *> ctx);

    

};
