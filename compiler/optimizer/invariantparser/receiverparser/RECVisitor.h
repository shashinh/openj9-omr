
// Generated from REC.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "RECParser.h"


namespace REC {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by RECParser.
 */
class  RECVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by RECParser.
   */
    virtual antlrcpp::Any visitRecs(RECParser::RecsContext *context) = 0;

    virtual antlrcpp::Any visitEntry(RECParser::EntryContext *context) = 0;

    virtual antlrcpp::Any visitClazzes(RECParser::ClazzesContext *context) = 0;

    virtual antlrcpp::Any visitClazz(RECParser::ClazzContext *context) = 0;

    virtual antlrcpp::Any visitBciKey(RECParser::BciKeyContext *context) = 0;


};

}  // namespace REC
