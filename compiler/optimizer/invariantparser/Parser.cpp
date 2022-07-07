
#include <iostream>
#include <fstream>
#include <strstream>
#include <string>
#include "antlr4-runtime.h"
#include "ptgparser/structs.h"
#include "ptgparser/PointsToGraph.h"
#include "ptgparser/LILexer.h"
#include "ptgparser/LIParser.h"
#include "ptgparser/LIBuilderVisitor.h"
#include "receiverparser/RECLexer.h"
#include "receiverparser/RECParser.h"
#include "receiverparser/RECBuilderVisitor.h"

using namespace std;
using namespace antlr4;

class ParseErrorListener : public BaseErrorListener 
{
        virtual void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine,
                                                         const std::string &msg, std::exception_ptr e)
        {

                cout << "Line(" << line << ":" << charPositionInLine << ") Error(" << msg << ")" << endl;
                throw invalid_argument("Parse Exception");
        }
};


map <string, int> readMethodIndices() {
	map<string, int> ret;
	char* methodIndicesFileName = "invariants/mi.txt";

	ifstream file(methodIndicesFileName);
	string methodName;
	int index = 1;
	while(file >> methodName) {
		// cout << methodName << ":" << index << endl;

		ret[methodName] = index;
		index++;
	}

	return ret;
}

map <int, string> readClassIndices() {
	map<int, string> ret;
	char* classIndicesFileName = "invariants/ci.txt";

	ifstream file(classIndicesFileName);
	string className;
	int index = 1;
	while(file >> className) {
		cout << className << ":" << index << endl;

		ret[index] = className;
		index++;
	}

	return ret;
}

map <int, set <int> >  readReceiversImpl(string fileName) {
    map <int, set <int> >  ret;

    ifstream ins(fileName, ifstream::in);

    ANTLRInputStream input(ins);
    RECLexer lexer(&input);

    CommonTokenStream tokens(&lexer);
    tokens.fill();


    ParseErrorListener errorListener;
    RECParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(&errorListener);

    tree::ParseTree *tree = parser.recs();
    // cout << "parser successful\n";
    // cout << tree->toStringTree(&parser) << "\n";
    RECParser::RecsContext *ctx = parser.recs();


    RECBuilderVisitor visitor;
    ret = visitor.visitRecs((RECParser::RecsContext *) tree).as<map <int, set <int> > >();

    // map <int, set <int> > :: iterator it = ret.begin();
    // while(it != ret.end()) {
    //     cout << it->first << ": ";
    //     for(auto i : it->second) {
    //         cout << i << " ";
    //     } cout << "\n";
    //     it++;
    // }

    return ret;    
}

map <int, set <int> > readReceivers(int methodIndex) {
	map <int, set <int> > ret;

	string fileName = "invariants/cr" + to_string(methodIndex) + ".txt";
	ret = readReceiversImpl(fileName);

	return ret;
}

map <int, PointsToGraph> readInvariant(string fileName) {
	// cout << "reading " << fileName << endl;
	map <int, PointsToGraph> invariant;

	ifstream ins(fileName, std::ifstream::in);

	ANTLRInputStream input(ins);

		LILexer lexer(&input);
		CommonTokenStream tokens(&lexer);

		ParseErrorListener errorListener;

		tokens.fill();

		LIParser parser(&tokens);
		parser.removeErrorListeners();
		parser.addErrorListener(&errorListener);

		tree::ParseTree *tree = parser.ptg();
		LIParser::PtgContext *ctx = parser.ptg();


		LIBuilderVisitor visitor;
		invariant = visitor.visitPtg((LIParser::PtgContext *)tree).as<std::map<int, PointsToGraph>>();

	/*
		std::map<int, PointsToGraph>::iterator it = invariant.begin();
		while (it != invariant.end())
		{
			cout << "bci : " << it->first << endl;
			map <int, set <Entry> > rho = it->second.getRho();
			map <Entry, map <string, set <Entry> > > sigma = it->second.getSigma();

			cout << "ROOTs" << endl;
			map< int, set <Entry> >::iterator vIt = rho.begin();
			while (vIt != rho.end())
			{
				cout << "\t" << vIt->first << ": ";
				set <Entry> pointees = vIt->second;
				for (Entry pointee : pointees)
				{
					cout << pointee.getString();
				}

				cout << endl;
				vIt++;
			}

			cout << "HEAP" << endl;
			map<Entry, map<string, set<Entry> > >::iterator fIt = sigma.begin();
			while (fIt != sigma.end())
			{
				Entry target = fIt->first;
				cout << "\t" << target.getString() << ": ";
				map <string, set <Entry> > fieldsMap = fIt->second;
				map <string, set <Entry> >::iterator fkIt = fieldsMap.begin();
				while (fkIt != fieldsMap.end())
				{
					cout << "\t\t" << fkIt->first << ": ";
					for (Entry pointee : fkIt->second)
					{
						cout << pointee.getString();
					}

					cout << "\t";
					fkIt++;
				}
				cout << endl;
				fIt++;
			}
			it++;
		}
		*/

	return invariant;
}

PointsToGraph readCallsiteInvariant(int methodIndex) {

	PointsToGraph ci;
    std::map<int, PointsToGraph> ciMap;
	string fileName =  "invariants/ci" + to_string(methodIndex) + ".txt";	

	ciMap = readInvariant(fileName);

	if(ciMap.find(0) == ciMap.end()) {
		// cout << "could not find callsite invariant for " << methodIndex << endl;
	} else {
 	   ci = ciMap[0];
	}

	return ci;
}

PointsToGraph readCallsiteOut(int methodIndex) {

	PointsToGraph ci;
    std::map<int, PointsToGraph> ciMap;
	string fileName =  "invariants/co" + to_string(methodIndex) + ".txt";	

	ciMap = readInvariant(fileName);

	if(ciMap.find(0) == ciMap.end()) {
		cout << "could not find callsite invariant for " << methodIndex << endl;
	} else {
 	   ci = ciMap[0];
	}

	set<Entry> returnPointees = ci.getPointsToSet(99);
	ci.killRho();
	ci.assign(-99, returnPointees);

	return ci;
}



std::map<int, PointsToGraph> readLoopInvariant(int methodIndex) { 
    std::map<int, PointsToGraph> li;

	string fileName =  "invariants/li" + to_string(methodIndex) + ".txt";	

	li = readInvariant(fileName);

	return li;
}
