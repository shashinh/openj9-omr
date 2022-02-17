#include "PTGBuilderVisitor.h"
#include <algorithm>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"

using namespace std;
using namespace antlrcpp;

string getBCIKeyString(PTGParser::BciKeyContext * ctx) {
	auto res = ctx->ALL() ? ctx->ALL()->toString() : ctx->NUMS()->toString();

	return res;
}
string getBCFieldIKeyString(PTGParser::BciKeyFieldContext * ctx) {
	auto res =  ctx->NUMS()->toString();

	return res;
}
string getBCIValString(PTGParser::BciValContext * ctx) {
	auto res = ctx->NUMS() ? ctx->NUMS()->toString() : "n";

	return res;
}

antlrcpp::Any PTGBuilderVisitor::visitPtg(PTGParser::PtgContext *ctx)
{
	std::map<std::string, Ptg> staticKeyedPtg;
	for(auto entry : ctx->entry()) {
		PTGParser::BciKeyContext * bciKey = entry->bciKey();
		auto staticLocationBCI = getBCIKeyString(bciKey);
		cout << "static bci : " << staticLocationBCI << endl;

		std::map<std::string, std::set<string>> varsMap;
		std::map<std::string, std::set<string>> fieldsMap;

		if(entry->vars()){
			auto vars = entry->vars();
			for(auto var : vars->varentry()){
				auto varEntryKey = getBCIKeyString(var->bciKey());
				std::set<string> varEntryBciVals;
				for(auto bciVal : var->bciVal()){
					auto varEntryBCIVal = getBCIValString(bciVal);
					varEntryBciVals.insert(varEntryBCIVal);
				}
				varsMap.insert(std::pair<std::string, std::set<string>>(varEntryKey, varEntryBciVals));
			}
		}

		if(entry->fields()){
			auto fields = entry->fields();
			for(auto field : fields->fieldentry()){
				auto fieldEntryKey = field->bciKeyField()->NUMS()->toString() + "." + field->field()->ALPHAS()->toString();
				std::set<string> fieldEntryBciVals;
				for(auto bciVal : field->bciVal()){
					auto fieldEntryBCIVal = getBCIValString(bciVal);
					fieldEntryBciVals.insert(fieldEntryBCIVal);
				}
				fieldsMap.insert(std::pair<std::string, std::set<string>>(fieldEntryKey, fieldEntryBciVals));
			}
		}

		Ptg staticPtg = {varsMap, fieldsMap};
		staticKeyedPtg.insert(std::pair<std::string, Ptg>(staticLocationBCI, staticPtg));

	}
	/*
	std::map<std::string, StaticPtg> staticKeyedPtg;
	for (auto entry : ctx->entry()){
		PTGParser::BciKeyContext * bciKey = entry->bciKey();
		cout << "bciKey has " << bciKey->children.size() << "children" << endl;

		cout << bciKey->NUMS()->toString() << endl;
		antlrcpp::Any res = bciKey->accept(this);
		cout << "1" << bciKey->NUMS()->toString() << res.isNull() << endl;


		std::string bci = res.as<std::string>();
		cout << "2" << bciKey->NUMS()->toString() << endl;



		//string bci = "blah";
		//string bci = entry->bciKey()->accept(this).as<string>();
		std::map<std::string, std::set<string>> varsMap = entry->vars()->accept(this).as<std::map<std::string, std::set<string>>>();
		cout << "3" << bciKey->NUMS()->toString() << endl;
		std::map<std::string, std::set<string>> fieldsMap;
		cout << "4" << bciKey->NUMS()->toString() << endl;
		if(entry->fields()) {
			fieldsMap = entry->fields()->accept(this).as<std::map<std::string, std::set<string>>>();

			cout << "5" << bciKey->NUMS()->toString() << endl;
		}


		StaticPtg ptg = {varsMap, fieldsMap};
		staticKeyedPtg.insert(std::pair <std::string, StaticPtg> (bci, ptg));

	}

	return staticKeyedPtg;
	*/

	return staticKeyedPtg;
}

antlrcpp::Any PTGBuilderVisitor::visitVars(PTGParser::VarsContext *ctx)
{
	std::map<string, std::set<string>> varsMap;
	for(auto varEntry : ctx->varentry()){
		string varKey = varEntry->bciKey()->accept(this).as<string>();
		std::set<string> vals;
		for(auto val : varEntry->bciVal()) {
			string v = val->accept(this).as<string>();
			vals.insert(v);
		}
		varsMap.insert(std::pair<string, std::set<string>> (varKey, vals));

	}

	return varsMap;
}

antlrcpp::Any PTGBuilderVisitor::visitFields(PTGParser::FieldsContext *ctx)
{
	std::map<string, std::set<string>> fieldsMap;
	for(auto fieldEntry : ctx->fieldentry()){
		string fieldReceiver = fieldEntry->bciKeyField()->accept(this).as<string>();
		string field = fieldEntry->field()->accept(this).as<string>();
		string fieldKey = fieldReceiver + "." + field;
		std::set<string> vals;
		for(auto val : fieldEntry->bciVal()) {
			string v = val->accept(this).as<string>();
			vals.insert(v);
		}
		fieldsMap.insert(std::pair<string, std::set<string>> (fieldKey, vals));

	}

	return fieldsMap;
	
}

antlrcpp::Any PTGBuilderVisitor::visitBciKey(PTGParser::BciKeyContext *ctx)
{
	//ctx->accept(this);

	std::string str;
	if (ctx->NUMS()) {
		str = ctx->NUMS()->toString();
		cout << "****IF" << str << endl;
	}
	else {
		str = ctx->ALL()->toString();
		cout << "****ELSE" << str << endl;
	}
	return str;
}

antlrcpp::Any PTGBuilderVisitor::visitBciVal(PTGParser::BciValContext *ctx)
{
	auto res = ctx->NUMS() != NULL ? ctx->NUMS()->toString() : ctx->NIL()->toString();
	//cout << res << endl;
	return res;
}

antlrcpp::Any PTGBuilderVisitor::visitBciKeyField(PTGParser::BciKeyFieldContext *ctx) {
    auto res = ctx->NUMS()->toString();
	return res;
  }

antlrcpp::Any PTGBuilderVisitor::visitField(PTGParser::FieldContext *ctx) {
    auto res = ctx->ALPHAS()->toString();
	return res;
  }

