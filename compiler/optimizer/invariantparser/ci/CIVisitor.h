
// Generated from CI.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "CIParser.h"


namespace CI {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by CIParser.
 */
class  CIVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CIParser.
   */
    virtual antlrcpp::Any visitCi(CIParser::CiContext *context) = 0;

    virtual antlrcpp::Any visitCiEntry(CIParser::CiEntryContext *context) = 0;

    virtual antlrcpp::Any visitCiBciEntry2(CIParser::CiBciEntry2Context *context) = 0;

    virtual antlrcpp::Any visitCiBciEntry(CIParser::CiBciEntryContext *context) = 0;

    virtual antlrcpp::Any visitCiEntries(CIParser::CiEntriesContext *context) = 0;

    virtual antlrcpp::Any visitCallerIndex(CIParser::CallerIndexContext *context) = 0;

    virtual antlrcpp::Any visitBciKey(CIParser::BciKeyContext *context) = 0;

    virtual antlrcpp::Any visitBciVal(CIParser::BciValContext *context) = 0;

    virtual antlrcpp::Any visitFieldKey(CIParser::FieldKeyContext *context) = 0;


};

}  // namespace CI
