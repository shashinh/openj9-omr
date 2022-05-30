#include <iostream>
#include <fstream>
#include <strstream>
#include <string>
#include "antlr4-runtime.h"
#include "CILexer.h"
#include "CIParser.h"
#include "CIBuilderVisitor.h"
#include "structs.h"

using namespace std;
using namespace antlr4;
using namespace CI;

class CIParseErrorListener : public BaseErrorListener 
{
        virtual void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine,
                                                         const std::string &msg, std::exception_ptr e)
        {

                cout << "Line(" << line << ":" << charPositionInLine << ") Error(" << msg << ")" << endl;
                throw invalid_argument("Parse Exception");
        }
};

int readCallerInvariants(string fileName) {
        map <int, set <Entry> > ret;

        ifstream ins(fileName, std::ifstream::in);
        if(ins.fail()) throw invalid_argument("File Open Exception");

        ANTLRInputStream input(ins);
        try
        {
                CILexer lexer(&input);
                CommonTokenStream tokens(&lexer);

                CIParseErrorListener errorListener;

                tokens.fill();

                for (Token *token : tokens.getTokens())
                {
                        // std::cout << token->toString() << std::endl;
                }

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
                ret = visitor.visitCi((CIParser::CiContext *) tree).as<map <int, set<Entry> > > ();

                //now lets print out the parsed callsite invariant
                map<int, set <Entry> > :: iterator it = ret.begin();
                while(it != ret.end()) {
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
                return 1;
        }
        
        return 0;


}

int main (int argc, char * argv[]) {

        string fileName(argv[1]);

        readCallerInvariants(fileName);

}


