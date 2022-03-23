
// Generated from PTG.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "PTGParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PTGParser.
 */
class  PTGVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PTGParser.
   */
    virtual antlrcpp::Any visitPtg(PTGParser::PtgContext *context) = 0;

    virtual antlrcpp::Any visitEntry(PTGParser::EntryContext *context) = 0;

    virtual antlrcpp::Any visitVars(PTGParser::VarsContext *context) = 0;

    virtual antlrcpp::Any visitVarentry(PTGParser::VarentryContext *context) = 0;

    virtual antlrcpp::Any visitFields(PTGParser::FieldsContext *context) = 0;

    virtual antlrcpp::Any visitFieldentry(PTGParser::FieldentryContext *context) = 0;

    virtual antlrcpp::Any visitCiBciEntry(PTGParser::CiBciEntryContext *context) = 0;

    virtual antlrcpp::Any visitCallerIndex(PTGParser::CallerIndexContext *context) = 0;

    virtual antlrcpp::Any visitBciKey(PTGParser::BciKeyContext *context) = 0;

    virtual antlrcpp::Any visitBciVal(PTGParser::BciValContext *context) = 0;

    virtual antlrcpp::Any visitBciKeyField(PTGParser::BciKeyFieldContext *context) = 0;

    virtual antlrcpp::Any visitField(PTGParser::FieldContext *context) = 0;


};

