#include "CIBuilderVisitor.h"
#include "CIBaseVisitor.h"
#include <algorithm>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"

using namespace std;
using namespace antlrcpp;


//TODO: what should the return of this be? a map keyed by arg index, and an object that encodes the multiple ci-bci pairs for that arg
antlrcpp::Any CIBuilderVisitor :: visitCi(CIParser::CiContext *ctx) {
    map<int, set <Entry> > args;

    int argIndex = 1;
    for(auto ciEntry : ctx->ciEntry()) {
        set <Entry> entries = ciEntry->accept(this).as<set <Entry> >();
        args.insert(pair<int, set<Entry> > (argIndex, entries));
        argIndex++;
    }

    return args;
}

antlrcpp::Any CIBuilderVisitor :: visitCiEntry(CIParser::CiEntryContext *ctx) {
    set<Entry> entries;

    for(auto ciBciEntry : ctx->ciBciEntry()) {
        set <Entry> t = ciBciEntry->accept(this).as<set <Entry> >();
        entries.insert(t.begin(), t.end());
    }

    return entries;
}


antlrcpp::Any CIBuilderVisitor :: visitCiBciEntry(CIParser::CiBciEntryContext *ctx) {
    set <Entry> entries;
    if(ctx->ciEntries()) {
        set <Entry> t = ctx->ciEntries()->accept(this).as<set <Entry> >();
        entries.insert(t.begin(), t.end());
    } else {
        Entry entry;
        if(ctx->STRING()) {
            entry.type = String;
        } else if (ctx->CONST()) {
            entry.type = Constant;
        } else if (ctx->GLOBAL()) {
            entry.type = Global;
        } else if (ctx->NIL()) {
            entry.type = Null;
        }

        entries.insert(entry);
    }

    return entries;
}

antlrcpp::Any CIBuilderVisitor :: visitCiEntries(CIParser::CiEntriesContext *ctx) {
    set <Entry> entries;

    int callerIndex = ctx->callerIndex()->accept(this).as<int>();
    for(auto bciVal : ctx->bciVal()) {
        int bci = bciVal->accept(this).as<int>();
        Entry entry;
        entry.type = Reference;
        entry.caller = callerIndex;
        entry.bci = bci;

        entries.insert(entry); 
    }

    return entries;
}

antlrcpp::Any CIBuilderVisitor :: visitCallerIndex(CIParser::CallerIndexContext *ctx) {
    auto ci = stoi(ctx->NUMS()->toString());
    return ci;
}

antlrcpp::Any CIBuilderVisitor :: visitBciVal(CIParser::BciValContext *ctx) {
    auto ci = stoi(ctx->NUMS()->toString());
    return ci;
}