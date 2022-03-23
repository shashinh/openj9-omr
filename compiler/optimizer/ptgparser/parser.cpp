#include <iostream>
#include <fstream> 
#include <strstream>
#include <string>
#include "antlr4-runtime.h"
#include "PTGLexer.h"
#include "PTGParser.h"
#include "structs.h"
#include "PTGBuilderVisitor.h"
#include <bits/stdc++.h>


using namespace std;
using namespace antlr4;

void testMethod(){}

class PTGParseErrorListener : public BaseErrorListener {
        virtual void syntaxError(Recognizer *recognizer, Token * offendingSymbol, size_t line, size_t charPositionInLine,
      const std::string &msg, std::exception_ptr e) {


        cout << "Line(" << line << ":" << charPositionInLine << ") Error(" << msg << ")" << endl;
        throw invalid_argument("Parse Exception");
          

	}
};

int test(int argc, char* argv[]) {
	
	string fileName(argv[1]);
	ifstream ins(fileName, std::ifstream::in); 
	//ins.open("/home/shashin/antlr/demo/test1/test1.log");
	
	ANTLRInputStream input(ins);
	try {
		PTGLexer lexer(&input);
		CommonTokenStream tokens(&lexer);

		PTGParseErrorListener errorListener;

		tokens.fill();
		
			for (Token *token : tokens.getTokens()) 
			{ 
			//std::cout << token->toString() << std::endl; 
			}   
			
		PTGParser parser(&tokens);
		parser.removeErrorListeners();
		parser.addErrorListener(&errorListener);
		
		tree::ParseTree *tree = parser.ptg();
		
		// Print the parse tree in Lisp format. 
		cout << endl << "Parse succesful, parse tree:" << endl; 
		std::cout << tree->toStringTree(&parser) << endl; 


		//cout << "visiting now\n";
		PTGParser::PtgContext *ctx = parser.ptg();
		
		cout << endl;
		
		PTGBuilderVisitor visitor;
	//std::map<int, StaticPtg> res = tree->accept(&visitor).as<std::map<int, StaticPtg>>();
		std::map<int, StaticPtg> res = visitor.visitPtg((PTGParser::PtgContext *) tree).as<std::map<int, StaticPtg>>();
		
		cout << "\n\n" << endl;
	std::map<int, StaticPtg> :: iterator it = res.begin();
		while(it != res.end()) {
			cout << "bci : " << it->first << endl;
			auto vars = it->second.varsMap;
		std::map<int, std::vector<Entry>> :: iterator vIt = vars.begin();
		while(vIt != vars.end()) {
			cout << "\t" << vIt->first << ": ";
			auto vals = vIt->second;
			for (Entry entry : vals) {
				if(entry.isNull) cout << " n";
				else if(entry.isConstant) cout << " c";
				else if(entry.isGlobal) cout << " g";
				else if(entry.isString) cout << " s";
				else {
					cout << " " << entry.caller << "-" << entry.bci;
				}
			}

				cout << endl;
			vIt++;
		}

	//       auto fields = it->second.fieldsMap;
	//       std::map<string, std::set<string>> :: iterator fIt = fields.begin();
	//       while(fIt != fields.end()) {
	//          cout << fIt->first << endl;
	//          fIt++;
	//       }
			it++;
		}
		return 0;
	} catch (invalid_argument &ex) { 
		cout << ex.what() << endl; 
		return 1;
	}
}
