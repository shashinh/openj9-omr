#include "PTGBuilderVisitor.h"
#include "PTGBaseVisitor.h"
#include <algorithm>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "PointsToGraph.h"

using namespace std;
using namespace antlrcpp;


antlrcpp::Any PTGBuilderVisitor::visitPtg(PTGParser::PtgContext *ctx)
{
	//a map of ptgs keyed by locations - represented by bci's in the method
	std::map<int, PointsToGraph> staticKeyedPtg;
	for (auto entry : ctx->entry())
	{
		//cout << "invoking bciKey()->accept(this)" << endl;
		int bci = entry->bciKey()->accept(this).as<int>();
		//cout << "completed bciKey()->accept(this)" << endl;
		std::map<int, std::vector<Entry>> varsMap = entry->vars()->accept(this).as<std::map<int, std::vector<Entry>>>();
    std::map <int, std::map <std::string, std::vector <Entry>>> fieldsMap;
		if(entry->fields())
			fieldsMap = entry->fields()->accept(this).as<std::map <int, std::map <std::string, std::vector <Entry>>>>();
//		PointsToGraph ptg(varsMap, fieldsMap);
//		staticKeyedPtg.insert(std::pair <int, PointsToGraph> (bci, ptg));

	}

	return staticKeyedPtg;
}

std::vector<Entry> PTGBuilderVisitor::processciBciEntrys(std::vector<PTGParser::CiBciEntryContext *> ctx) {

		std::vector<Entry> entries;
		for(auto entry : ctx){
			Entry varEntry;
			
			if (entry->STRING() != NULL) {
				//cout << "varEntry is string" << endl;
				varEntry.type = String;
				entries.push_back(varEntry);
			} else if (entry->CONST() != NULL) {
				//cout << "varEntry is const" << endl;
				varEntry.type = Constant;
				entries.push_back(varEntry);
			} else if (entry->GLOBAL() != NULL) {
				//cout << "varEntry is global" << endl;
				varEntry.type = Global;
				entries.push_back(varEntry);
			} else if (entry->NIL() != NULL) {
				//cout << "varEntry is null" << endl;
				//the value is a NIL;
				varEntry.type = Null;
				entries.push_back(varEntry);
			} else {
				int callerIndex = entry->ciEntries()->callerIndex()->accept(this).as<int>();
		//cout << "\t there are " << entry->ciEntries()->bciVal().size() << " entries in entry->ciEntries()->bciVal()" << endl;
				for(auto val : entry->ciEntries()->bciVal()){
					int bciVal = stoi(val->accept(this).as<string>());
					varEntry.type = Reference;
					varEntry.caller = callerIndex;
					varEntry.bci = bciVal;
					entries.push_back(varEntry);
				}
			}

		}

		return entries;
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
				//cout << "varEntry is string" << endl;
				varEntry.type = String;
				entries.push_back(varEntry);
			} else if (entry->CONST() != NULL) {
				//cout << "varEntry is const" << endl;
				varEntry.type = Constant;
				entries.push_back(varEntry);
			} else if (entry->GLOBAL() != NULL) {
				//cout << "varEntry is global" << endl;
				varEntry.type = Global;
				entries.push_back(varEntry);
			} else if (entry->NIL() != NULL) {
				//cout << "varEntry is null" << endl;
				//the value is a NIL;
				varEntry.type = Null;
				entries.push_back(varEntry);
			} else {
				int callerIndex = entry->ciEntries()->callerIndex()->accept(this).as<int>();
		//cout << "\t there are " << entry->ciEntries()->bciVal().size() << " entries in entry->ciEntries()->bciVal()" << endl;
				for(auto val : entry->ciEntries()->bciVal()){
					int bciVal = stoi(val->accept(this).as<string>());
					varEntry.type = Reference;
					varEntry.caller = callerIndex;
					varEntry.bci = bciVal;
					entries.push_back(varEntry);
				}
			}

		}
		//cout << "inserting " << entries.size() << " entries into varsMap" << endl;
		varsMap.insert(std::pair<int, std::vector<Entry>>(varKey, entries));
	}

	return varsMap;
}

antlrcpp::Any PTGBuilderVisitor::visitFields(PTGParser::FieldsContext *ctx)
{
    std::map <int, std::map <std::string, std::vector <Entry>>> fieldsMap;

	for(auto fieldEntry : ctx->fieldentry()){
//		int bciKey = fieldEntry->bciKey()->accept(this).as<int>();
		int ci = fieldEntry->callerIndex()->accept(this).as<int>();
		int bciVal = fieldEntry->bciKey()->accept(this).as<int>();
		//cout << "bci key is " << bciKey << endl;
		//cout << "there are " << fieldEntry->field().size() << " fields" << endl;
		std::map <std::string, std::vector <Entry>> map;
		for(auto field : fieldEntry->field()){
			std::string fieldKey = field->fieldKey()->accept(this).as<string>();
			//std::map <std::string, std::vector <Entry>> map;
			//cout << "the fieldKey is " << fieldKey << endl;
			//cout << "there are " << field->ciBciEntry().size() << " ciBciEntrys" << endl;

			std::vector<Entry> entries = processciBciEntrys(field->ciBciEntry());
			
			map.insert(std::pair<std::string, vector <Entry>> (fieldKey, entries));
 		}		
		
		fieldsMap.insert(std::pair<int, std::map<std::string, std::vector <Entry>>> (bciVal, map));
	}

	return fieldsMap;

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
	//cout << "bci key is " << bci << endl;
	//cout << str << endl;
	return bci;
}

antlrcpp::Any PTGBuilderVisitor::visitBciVal(PTGParser::BciValContext *ctx)
{
	auto res = ctx->NUMS() != NULL ? ctx->NUMS()->toString() : ctx->NIL()->toString();
	//cout << res << endl;

	//cout << "bciVal is " << res << endl;
	return res;
}

// antlrcpp::Any PTGBuilderVisitor::visitBciKeyField(PTGParser::BciKeyFieldContext *ctx) {
//     auto res = ctx->NUMS()->toString();
// 	return res;
//   }

//antlrcpp::Any PTGBuilderVisitor::visitField(PTGParser::FieldContext *ctx) {
	// string field = ctx->fieldKey()->toString();
	// cout << "the field key is " << field << endl;

	// return field;
  //}


antlrcpp::Any PTGBuilderVisitor::visitCallerIndex(PTGParser::CallerIndexContext *ctx) {
    auto res = stoi(ctx->NUMS()->toString());
	//cout << "caller index is " << res << endl;
	return res;
  }


   antlrcpp::Any PTGBuilderVisitor::visitFieldKey(PTGParser::FieldKeyContext *ctx) {
	   string fieldKey = ctx->ALPHAS()->toString();

	   return fieldKey;
   }
  


