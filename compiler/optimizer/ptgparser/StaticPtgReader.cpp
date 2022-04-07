#include <iostream>
#include <fstream>
#include <strstream>
#include <string>
#include "antlr4-runtime.h"
#include "PTGLexer.h"
#include "PTGParser.h"
#include "PTGBuilderVisitor.h"
#include "PointsToGraph.h"

using namespace std;
using namespace antlr4;

class PTGParseErrorListener : public BaseErrorListener
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
	char* methodIndicesFileName = "mi.txt";

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

std::map<int, PointsToGraph> readLoopInvariants(string fileName) {
	std::map<int, PointsToGraph> ret;
// }

// int main(int argc, char *argv[])
// {

	//string fileName(argv[1]);
	ifstream ins(fileName, std::ifstream::in);
	// ins.open("/home/shashin/antlr/demo/test1/test1.log");

	ANTLRInputStream input(ins);

		PTGLexer lexer(&input);
		CommonTokenStream tokens(&lexer);

		PTGParseErrorListener errorListener;

		tokens.fill();

		for (Token *token : tokens.getTokens())
		{
			// std::cout << token->toString() << std::endl;
		}

		PTGParser parser(&tokens);
		parser.removeErrorListeners();
		parser.addErrorListener(&errorListener);

		tree::ParseTree *tree = parser.ptg();

		// Print the parse tree in Lisp format.
		cout << endl
			 << "Parse succesful, parse tree:" << endl;
		std::cout << tree->toStringTree(&parser) << endl;

		// cout << "visiting now\n";
		PTGParser::PtgContext *ctx = parser.ptg();

		cout << endl;

		PTGBuilderVisitor visitor;
		// std::map<int, StaticPtg> res = tree->accept(&visitor).as<std::map<int, StaticPtg>>();
		ret = visitor.visitPtg((PTGParser::PtgContext *)tree).as<std::map<int, PointsToGraph>>();

		cout << "\n\n"
			 << endl;
		std::map<int, PointsToGraph>::iterator it = ret.begin();
		while (it != ret.end())
		{
			cout << "bci : " << it->first << endl;
			auto rho = it->second.getRho();
			auto sigma = it->second.getSigma();

			cout << "ROOTs" << endl;
			std::map<int, std::vector<Entry>>::iterator vIt = rho.begin();
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

	return ret;
}
