
#include <iostream>
#include <fstream>
#include <strstream>
#include <string>
#include "antlr4-runtime.h"
#include "ci/structs.h"
#include "li/structs.h"
#include "ci/CILexer.h"
#include "ci/CIParser.h"
#include "ci/CIBuilderVisitor.h"
#include "li/PointsToGraph.h"
#include "li/LILexer.h"
#include "li/LIParser.h"
#include "li/LIBuilderVisitor.h"



using namespace std;
using namespace antlr4;


map <string, int> readMethodIndices() {
	map<string, int> ret;
	char* methodIndicesFileName = "invariants/mi.txt";

	ifstream file(methodIndicesFileName);
	string methodName;
	int index = 1;
	while(file >> methodName) {
		cout << methodName << ":" << index << endl;

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

map <int, set <Entry> > readCallsiteInvariant(string fileName) {
    map <int, set <Entry> > ci;
        ifstream ins(fileName, std::ifstream::in);
        if(ins.fail()) throw invalid_argument("Callsite Invariant File Open Exception");

        ANTLRInputStream input(ins);
        try
        {
                CILexer lexer(&input);
                CommonTokenStream tokens(&lexer);

                ParseErrorListener errorListener;

                tokens.fill();

                CIParser parser(&tokens);
                parser.removeErrorListeners();
                parser.addErrorListener(&errorListener);

                tree::ParseTree *tree = parser.ci();

                // Print the parse tree in Lisp format.
                cout << endl
                         << "Parse succesful, parse tree:" << endl;
                std::cout << tree->toStringTree(&parser) << endl;

                //invoke the visitor here
                CIParser::CiContext *ctx = parser.ci();

                CIBuilderVisitor visitor;
                ci = visitor.visitCi((CIParser::CiContext *) tree).as<map <int, set<Entry> > > ();

                //now lets print out the parsed callsite invariant
                map<int, set <Entry> > :: iterator it = ci.begin();
                while(it != ci.end()) {
                        cout << "arg index: " << it->first << "\n";
                        set<Entry> entries = it->second;
                        for(auto entry : entries) {
                                cout << "\t" << entry.getString() << " ";
                        }
                        
                        it++;
                        cout << "\n";
                }

        }
        catch (invalid_argument &ex)
        {
                cout << ex.what() << endl;
        }

    return ci;
}



std::map<int, PointsToGraph> readLoopInvariant(string fileName) { 
    std::map<int, PointsToGraph> li;
// }

// int main(int argc, char *argv[])
// {

	//string fileName(argv[1]);
	ifstream ins(fileName, std::ifstream::in);
	// ins.open("/home/shashin/antlr/demo/test1/test1.log");

	ANTLRInputStream input(ins);

		LILexer lexer(&input);
		CommonTokenStream tokens(&lexer);

		ParseErrorListener errorListener;

		tokens.fill();

		LIParser parser(&tokens);
		parser.removeErrorListeners();
		parser.addErrorListener(&errorListener);

		tree::ParseTree *tree = parser.ptg();

		// Print the parse tree in Lisp format.
//		cout << endl
//			 << "Parse succesful, parse tree:" << endl;
//		std::cout << tree->toStringTree(&parser) << endl;

		// cout << "visiting now\n";
		LIParser::PtgContext *ctx = parser.ptg();

//		cout << endl;

		LIBuilderVisitor visitor;
		// std::map<int, StaticPtg> res = tree->accept(&visitor).as<std::map<int, StaticPtg>>();
		li = visitor.visitPtg((LIParser::PtgContext *)tree).as<std::map<int, PointsToGraph>>();

//		cout << "\n\n"
//			 << endl;
		std::map<int, PointsToGraph>::iterator it = li.begin();
		while (it != li.end())
		{
			cout << "bci : " << it->first << endl;
			auto rho = it->second.getRho();
			auto sigma = it->second.getSigma();

			cout << "ROOTs" << endl;
			std::map<int, std::set <Entry>>::iterator vIt = rho.begin();
			while (vIt != rho.end())
			{
				cout << "\t" << vIt->first << ": ";
				auto vals = vIt->second;
				for (Entry entry : vals)
				{
					if (entry.type == Null)
						cout << " n";
					else if (entry.type == Constant)
						cout << " c";
					else if (entry.type == Global)
						cout << " g";
					else if (entry.type == String)
						cout << " s";
					else
					{
						cout << " " << entry.caller << "-" << entry.bci;
					}
				}

				cout << endl;
				vIt++;
			}

			cout << "HEAP" << endl;
			std::map<int, std::map<std::string, std::vector<Entry>>>::iterator fIt = sigma.begin();
			while (fIt != sigma.end())
			{
				cout << "\t" << fIt->first << ": ";
				auto vals = fIt->second;
				auto fkIt = vals.begin();
				while (fkIt != vals.end())
				{
					cout << "\t\t" << fkIt->first << ": ";
					for (auto entry : fkIt->second)
					{
						if (entry.type == Null)
							cout << " n";
						else if (entry.type == Constant)
							cout << " c";
						else if (entry.type == Global)
							cout << " g";
						else if (entry.type == String)
							cout << " s";
						else
						{
							cout << " " << entry.caller << "-" << entry.bci;
						}
					}

					cout << "\t";
					fkIt++;
				}
				cout << endl;
				fIt++;
			}
			it++;
		}

	return li;
}
