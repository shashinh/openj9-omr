#include <iostream>
#include <fstream>
#include <strstream>
#include <string>
#include "antlr4-runtime.h"
#include "RECLexer.h"
#include "RECParser.h"
#include "RECBuilderVisitor.h"

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

map <int, set <int> >  readReceivers(string fileName) {
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
    cout << "parser successful\n";
    cout << tree->toStringTree(&parser) << "\n";
    RECParser::RecsContext *ctx = parser.recs();


    RECBuilderVisitor visitor;
    ret = visitor.visitRecs((RECParser::RecsContext *) tree).as<map <int, set <int> > >();

    map <int, set <int> > :: iterator it = ret.begin();
    while(it != ret.end()) {
        cout << it->first << ": ";
        for(auto i : it->second) {
            cout << i << " ";
        } cout << "\n";
        it++;
    }

    return ret;    
}