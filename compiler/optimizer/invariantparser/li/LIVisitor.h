
// Generated from LI.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "LIParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by LIParser.
 */
class  LIVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by LIParser.
   */
    virtual antlrcpp::Any visitPtg(LIParser::PtgContext *context) = 0;

    virtual antlrcpp::Any visitEntry(LIParser::EntryContext *context) = 0;

    virtual antlrcpp::Any visitVars(LIParser::VarsContext *context) = 0;

    virtual antlrcpp::Any visitVarentry(LIParser::VarentryContext *context) = 0;

    virtual antlrcpp::Any visitFields(LIParser::FieldsContext *context) = 0;

    virtual antlrcpp::Any visitFieldentry(LIParser::FieldentryContext *context) = 0;

    virtual antlrcpp::Any visitField(LIParser::FieldContext *context) = 0;

    virtual antlrcpp::Any visitCiBciEntry(LIParser::CiBciEntryContext *context) = 0;

    virtual antlrcpp::Any visitCiEntries(LIParser::CiEntriesContext *context) = 0;

    virtual antlrcpp::Any visitCallerIndex(LIParser::CallerIndexContext *context) = 0;

    virtual antlrcpp::Any visitBciKey(LIParser::BciKeyContext *context) = 0;

    virtual antlrcpp::Any visitBciVal(LIParser::BciValContext *context) = 0;

    virtual antlrcpp::Any visitFieldKey(LIParser::FieldKeyContext *context) = 0;


};

