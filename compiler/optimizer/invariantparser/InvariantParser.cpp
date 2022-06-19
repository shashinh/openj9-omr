
#include <iostream>
#include <fstream>
#include <strstream>
#include <string>
#include "antlr4-runtime.h"
#include "parser/structs.h"
#include "parser/PointsToGraph.h"
#include "parser/LILexer.h"
#include "parser/LIParser.h"
#include "parser/LIBuilderVisitor.h"

using namespace std;
using namespace antlr4;

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
class ParseErrorListener : public BaseErrorListener 
{
        virtual void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine,
                                                         const std::string &msg, std::exception_ptr e)
        {

                cout << "Line(" << line << ":" << charPositionInLine << ") Error(" << msg << ")" << endl;
                throw invalid_argument("Parse Exception");
        }
};

map <int, PointsToGraph> readInvariant(string fileName) {
	cout << "reading " << fileName << endl;
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

    std::map<int, PointsToGraph> ci;
	string fileName =  "invariants/ci" + to_string(methodIndex) + ".txt";	

	ci = readInvariant(fileName);

	assert(ci.find(0) != ci.end());

    return ci[0];
}



std::map<int, PointsToGraph> readLoopInvariant(int methodIndex) { 
    std::map<int, PointsToGraph> li;

	string fileName =  "invariants/li" + to_string(methodIndex) + ".txt";	

	li = readInvariant(fileName);

	return li;
}
