#include "PTGBuilderVisitor.h"
#include "PTGBaseVisitor.h"
#include <algorithm>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"

using namespace std;
using namespace antlrcpp;


antlrcpp::Any PTGBuilderVisitor::visitPtg(PTGParser::PtgContext *ctx)
{
	//a map of ptgs keyed by locations - represented by bci's in the method
	std::map<int, StaticPtg> staticKeyedPtg;
	for (auto entry : ctx->entry())
	{
		//cout << "invoking bciKey()->accept(this)" << endl;
		int bci = entry->bciKey()->accept(this).as<int>();
		//cout << "completed bciKey()->accept(this)" << endl;
		std::map<int, std::vector<Entry>> varsMap = entry->vars()->accept(this).as<std::map<int, std::vector<Entry>>>();
		std::map<int, std::vector<Entry>> fieldsMap;
		if(entry->fields())
			fieldsMap = entry->fields()->accept(this).as<std::map<int, std::vector<Entry>>>();
		StaticPtg ptg = {varsMap, fieldsMap};
		staticKeyedPtg.insert(std::pair <int, StaticPtg> (bci, ptg));

	}

	return staticKeyedPtg;
}

antlrcpp::Any PTGBuilderVisitor::visitVars(PTGParser::VarsContext *ctx)
{
	std::map<int, std::vector<Entry>> varsMap;
	for(auto varEntry : ctx->varentry()){
		int varKey = varEntry->bciKey()->accept(this).as<int>();
		std::vector<Entry> entries;
		for(auto entry : varEntry->ciBciEntry()){
			Entry varEntry;
			
			if (entry->STRING() != NULL) {
				cout << "varEntry is string" << endl;
				varEntry.isString = true;
				entries.push_back(varEntry);
			} else if (entry->CONST() != NULL) {
				cout << "varEntry is const" << endl;
				varEntry.isConstant = true;
				entries.push_back(varEntry);
			} else if (entry->GLOBAL() != NULL) {
				cout << "varEntry is global" << endl;
				varEntry.isGlobal = true;
				entries.push_back(varEntry);
			} else if (entry->NIL() != NULL) {
				cout << "varEntry is null" << endl;
				//the value is a NIL;
				varEntry.isNull = true;
				entries.push_back(varEntry);
			} else {
				int callerIndex = entry->ciEntries()->callerIndex()->accept(this).as<int>();
		cout << "\t there are " << entry->ciEntries()->bciVal().size() << " entries in entry->ciEntries()->bciVal()" << endl;
				for(auto val : entry->ciEntries()->bciVal()){
					int bciVal = stoi(val->accept(this).as<string>());
					varEntry.isRef = true;
					varEntry.caller = callerIndex;
					varEntry.bci = bciVal;
					entries.push_back(varEntry);
				}
			}

		}
		cout << "inserting " << entries.size() << " entries into varsMap" << endl;
		varsMap.insert(std::pair<int, std::vector<Entry>>(varKey, entries));
	}

	return varsMap;
}

antlrcpp::Any PTGBuilderVisitor::visitFields(PTGParser::FieldsContext *ctx)
{
	// std::map<string, std::set<string>> fieldsMap;
	// for(auto fieldEntry : ctx->fieldentry()){
	// 	string fieldReceiver = fieldEntry->bciKeyField()->accept(this).as<string>();
	// 	string field = fieldEntry->field()->accept(this).as<string>();
	// 	string fieldKey = fieldReceiver + "." + field;
	// 	std::set<string> vals;
	// 	for(auto val : fieldEntry->bciVal()) {
	// 		string v = val->accept(this).as<string>();
	// 		vals.insert(v);
	// 	}
	// 	fieldsMap.insert(std::pair<string, std::set<string>> (fieldKey, vals));

	// }

	// return fieldsMap;
	
}

antlrcpp::Any PTGBuilderVisitor::visitBciKey(PTGParser::BciKeyContext *ctx)
{
	//cout << "entered visitBciKey(PTGParser::BciKeyContext *ctx)" << endl;
	int bci = stoi(ctx->NUMS()->toString());
	cout << "bci key is " << bci << endl;
	//cout << str << endl;
	return bci;
}

antlrcpp::Any PTGBuilderVisitor::visitBciVal(PTGParser::BciValContext *ctx)
{
	auto res = ctx->NUMS() != NULL ? ctx->NUMS()->toString() : ctx->NIL()->toString();
	//cout << res << endl;

	cout << "bciVal is " << res << endl;
	return res;
}

// antlrcpp::Any PTGBuilderVisitor::visitBciKeyField(PTGParser::BciKeyFieldContext *ctx) {
//     auto res = ctx->NUMS()->toString();
// 	return res;
//   }

antlrcpp::Any PTGBuilderVisitor::visitField(PTGParser::FieldContext *ctx) {
    // auto res = ctx->ALPHAS()->toString();
	// return res;
  }


antlrcpp::Any PTGBuilderVisitor::visitCallerIndex(PTGParser::CallerIndexContext *ctx) {
    auto res = stoi(ctx->NUMS()->toString());
	cout << "caller index is " << res << endl;
	return res;
  }
  


