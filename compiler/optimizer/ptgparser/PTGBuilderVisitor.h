#include "PTGBaseVisitor.h"
#include <algorithm>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"

class PTGBuilderVisitor : public PTGBaseVisitor { 

public:

    virtual antlrcpp::Any visitPtg(PTGParser::PtgContext *ctx) override;
    virtual antlrcpp::Any visitVars(PTGParser::VarsContext *ctx) override;
    virtual antlrcpp::Any visitFields(PTGParser::FieldsContext *ctx) override;
    virtual antlrcpp::Any visitBciVal(PTGParser::BciValContext *ctx) override;
    virtual antlrcpp::Any visitBciKey(PTGParser::BciKeyContext *ctx) override;
    //virtual antlrcpp::Any visitBciKeyField(PTGParser::BciKeyFieldContext *ctx) override;
    //virtual antlrcpp::Any visitField(PTGParser::FieldContext *ctx) override;
    virtual antlrcpp::Any visitCallerIndex(PTGParser::CallerIndexContext *ctx);
    virtual antlrcpp::Any visitFieldKey(PTGParser::FieldKeyContext *ctx);
    virtual std::vector<Entry> processciBciEntrys(std::vector<PTGParser::CiBciEntryContext *> ctx);

    

};
