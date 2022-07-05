#include "RECBuilderVisitor.h"
#include "RECBaseVisitor.h"
#include <algorithm>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

using namespace std;
using namespace antlrcpp;

antlrcpp::Any RECBuilderVisitor::visitRecs(RECParser::RecsContext *ctx) {
	map <int, set<int> > receiverInfo;

	for(auto entry : ctx->entry()) {
		int bci = entry->bciKey()->accept(this).as<int>();

		set <int> receivers = entry->clazzes()->accept(this).as<set <int> >();

		receiverInfo[bci] = receivers;
	}

	return receiverInfo;
}

// antlrcpp::Any RECBuilderVisitor::visitEntry(RECParser::EntryContext *ctx) {
// 	set <int> receivers;

// 	for(auto clazz : ctx->clazzes()) {
		
// 	}

// 	return receivers;
// }

antlrcpp::Any RECBuilderVisitor::visitClazzes(RECParser::ClazzesContext *ctx) {
	set <int> receivers;

	for(auto clazz : ctx->clazz()) {
		int rec = clazz->accept(this).as<int>();
		receivers.insert(rec);
	}

	return receivers;
}

antlrcpp::Any RECBuilderVisitor::visitBciKey(RECParser::BciKeyContext *ctx) {
	return stoi(ctx->NUMS()->toString());
}

antlrcpp::Any RECBuilderVisitor::visitClazz(RECParser::ClazzContext *ctx) {
	return stoi(ctx->NUMS()->toString());
}
