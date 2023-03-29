#include "LIBuilderVisitor.h"
#include "LIBaseVisitor.h"
#include <algorithm>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "PointsToGraph.h"

using namespace std;
using namespace antlrcpp;


antlrcpp::Any LIBuilderVisitor::visitPtg(LIParser::PtgContext *ctx)
{
	//a map of ptgs keyed by locations - represented by bci's in the method
	map<int, PointsToGraph> staticKeyedPtg;
	for (auto entry : ctx->entry())
	{
		//cout << "invoking bciKey()->accept(this)" << endl;
		int bci = entry->bciKey()->accept(this).as<int>();
		//cout << "completed bciKey()->accept(this)" << endl;
		map<int, set <Entry> > varsMap = entry->vars()->accept(this).as<map <int, set <Entry> > >();
    map <Entry, map <string, set <Entry>>> fieldsMap;
		if(entry->fields())
			fieldsMap = entry->fields()->accept(this).as<map <Entry, map <string, set <Entry> > > >();
		PointsToGraph ptg(varsMap, fieldsMap);
		staticKeyedPtg.insert(pair <int, PointsToGraph> (bci, ptg));

	}

	return staticKeyedPtg;
}

set <Entry> LIBuilderVisitor::processciBciEntrys(vector<LIParser::CiBciEntryContext *> ctx) {

		set <Entry> entries;
		for(auto entry : ctx){
			Entry varEntry;
			
			if (entry->STRING() != NULL) {
				//cout << "varEntry is string" << endl;
				varEntry.type = String;
				entries.insert(varEntry);
			} else if (entry->CONST() != NULL) {
				//cout << "varEntry is const" << endl;
				varEntry.type = Constant;
				entries.insert(varEntry);
			} else if (entry->GLOBAL() != NULL) {
				//cout << "varEntry is global" << endl;
				varEntry.type = Global;
				entries.insert(varEntry);
			} else if (entry->NIL() != NULL) {
				//cout << "varEntry is null" << endl;
				//the value is a NIL;
				varEntry.type = Null;
				entries.insert(varEntry);
			} else {
				int callerIndex = entry->ciEntries()->callerIndex()->accept(this).as<int>();
		//cout << "\t there are " << entry->ciEntries()->bciVal().size() << " entries in entry->ciEntries()->bciVal()" << endl;

				for(auto valWithType : entry->ciEntries()->bciValWithType()) {
					int bciVal = stoi(valWithType->bciKey()->NUMS()->toString());
					int clazz = stoi(valWithType->type()->NUMS()->toString());
					varEntry.type = Reference;
					varEntry.caller = callerIndex;
					varEntry.bci = bciVal;
					varEntry.clazz = clazz;
					entries.insert(varEntry);
				}		  


//				for(auto val : entry->ciEntries()->bciVal()){
//					int bciVal = stoi(val->accept(this).as<string>());
//					varEntry.type = Reference;
//					varEntry.caller = callerIndex;
//					varEntry.bci = bciVal;
//					entries.insert(varEntry);
//				}
			}

		}

		return entries;
}
antlrcpp::Any LIBuilderVisitor::visitVars(LIParser::VarsContext *ctx)
{
	map<int, set <Entry>> varsMap; //rho








	for(auto varEntry : ctx->varentry()){
		int varKey = varEntry->bciKey()->accept(this).as<int>();
		set <Entry> entries;
		for(auto entry : varEntry->ciBciEntry()){
			Entry varEntry;
			
			if (entry->STRING() != NULL) {
				//cout << "varEntry is string" << endl;
				varEntry.type = String;
				entries.insert(varEntry);
			} else if (entry->CONST() != NULL) {
				//cout << "varEntry is const" << endl;
				varEntry.type = Constant;
				entries.insert(varEntry);
			} else if (entry->GLOBAL() != NULL) {
				//cout << "varEntry is global" << endl;
				varEntry.type = Global;
				entries.insert(varEntry);
			} else if (entry->NIL() != NULL) {
				//cout << "varEntry is null" << endl;
				//the value is a NIL;
				varEntry.type = Null;
				entries.insert(varEntry);
			} else {
				int callerIndex = entry->ciEntries()->callerIndex()->accept(this).as<int>();
		//cout << "\t there are " << entry->ciEntries()->bciVal().size() << " entries in entry->ciEntries()->bciVal()" << endl;
				for(auto valWithType : entry->ciEntries()->bciValWithType()) {
					int bciVal = stoi(valWithType->bciKey()->NUMS()->toString());
					int clazz = stoi(valWithType->type()->NUMS()->toString());
					varEntry.type = Reference;
					varEntry.caller = callerIndex;
					varEntry.bci = bciVal;
					varEntry.clazz = clazz;
					entries.insert(varEntry);
				}		  

//				for(auto val : entry->ciEntries()->bciVal()){
//					int bciVal = stoi(val->accept(this).as<string>());
//					varEntry.type = Reference;
//					varEntry.caller = callerIndex;
//					varEntry.bci = bciVal;
//					entries.insert(varEntry);
//				}
			}

		}
		//cout << "inserting " << entries.size() << " entries into varsMap" << endl;
		varsMap.insert(pair<int, set<Entry>>(varKey, entries));
	}

	return varsMap;
}

antlrcpp::Any LIBuilderVisitor::visitFields(LIParser::FieldsContext *ctx) //build sigma
{
    map <Entry, map <string, set <Entry>>> fieldsMap;

	for(auto fieldEntry : ctx->fieldentry()){
//		int bciKey = fieldEntry->bciKey()->accept(this).as<int>();
		int ci = fieldEntry->callerIndex()->accept(this).as<int>();
		int bciVal = fieldEntry->bciKey()->accept(this).as<int>();
		Entry target;
		target.type = Reference;
		target.bci = bciVal;
		target.caller = ci;
		//cout << "bci key is " << bciKey << endl;
		//cout << "there are " << fieldEntry->field().size() << " fields" << endl;
		map <string, set <Entry>> map;
		for(auto field : fieldEntry->field()){
			string fieldKey = field->fieldKey()->accept(this).as<string>();
			//map <string, vector <Entry>> map;
			//cout << "the fieldKey is " << fieldKey << endl;
			//cout << "there are " << field->ciBciEntry().size() << " ciBciEntrys" << endl;

			set<Entry> entries = processciBciEntrys(field->ciBciEntry());
			fieldsMap[target][fieldKey] = entries;
			
//			map.insert(pair<string, set <Entry>> (fieldKey, entries));
 		}		
		
	//	fieldsMap.insert(pair <Entry, map <string, set <Entry> > > (target, map));
	}

	return fieldsMap;

	// map<string, set<string>> fieldsMap;
	// for(auto fieldEntry : ctx->fieldentry()){
	// 	string fieldReceiver = fieldEntry->bciKeyField()->accept(this).as<string>();
	// 	string field = fieldEntry->field()->accept(this).as<string>();
	// 	string fieldKey = fieldReceiver + "." + field;
	// 	set<string> vals;
	// 	for(auto val : fieldEntry->bciVal()) {
	// 		string v = val->accept(this).as<string>();
	// 		vals.insert(v);
	// 	}
	// 	fieldsMap.insert(pair<string, set<string>> (fieldKey, vals));

	// }

	// return fieldsMap;
	
}

antlrcpp::Any LIBuilderVisitor::visitBciKey(LIParser::BciKeyContext *ctx)
{
	//cout << "entered visitBciKey(LIParser::BciKeyContext *ctx)" << endl;
	int bci = stoi(ctx->NUMS()->toString());
	//cout << "bci key is " << bci << endl;
	//cout << str << endl;
	return bci;
}

//TODO: not used, remove?
antlrcpp::Any LIBuilderVisitor::visitBciValWithType(LIParser::BciValWithTypeContext *ctx)
{
	auto res = "";
	//auto res = ctx->NUMS() != NULL ? ctx->NUMS()->toString() : ctx->NIL()->toString();
	//cout << res << endl;

	//cout << "bciVal is " << res << endl;
	return res;
}

// antlrcpp::Any LIBuilderVisitor::visitBciKeyField(LIParser::BciKeyFieldContext *ctx) {
//     auto res = ctx->NUMS()->toString();
// 	return res;
//   }

//antlrcpp::Any LIBuilderVisitor::visitField(LIParser::FieldContext *ctx) {
	// string field = ctx->fieldKey()->toString();
	// cout << "the field key is " << field << endl;

	// return field;
  //}


antlrcpp::Any LIBuilderVisitor::visitCallerIndex(LIParser::CallerIndexContext *ctx) {
    auto res = stoi(ctx->NUMS()->toString());
	//cout << "caller index is " << res << endl;
	return res;
  }


   antlrcpp::Any LIBuilderVisitor::visitFieldKey(LIParser::FieldKeyContext *ctx) {
	   string fieldKey = ctx->ALPHAS()->toString();

	   return fieldKey;
   }
  


