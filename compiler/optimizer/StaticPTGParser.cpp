
#include "antlr4-common.h"
#include "antlr4-runtime.h"
#include "ptgparser/PTGLexer.h"
#include "ptgparser/PTGParser.h"
#include "ptgparser/PTGBuilderVisitor.h"
#include "ptgparser/structs.h"
#include <unistd.h>
using namespace std;
using namespace antlr4;

std::map<string, Ptg> parsePTG(string staticFileName) {

   char tmp[256];
   char *t =  getcwd(tmp, 256);

   cout << tmp << "/" << staticFileName << endl;

   ifstream ins(staticFileName, std::ifstream::in);
   
	ANTLRInputStream input(ins);

	PTGLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
   tokens.fill();

   PTGParser parser(&tokens);
   tree::ParseTree *tree = parser.ptg();

   cout << "\nParse succesful, parse tree:\n"; 
   std::cout << tree->toStringTree(&parser) << "\n"; 

   //PTGParser::PtgContext* ctx = parser.ptg();
   PTGBuilderVisitor visitor; 
   //std::map<string, StaticPtg> res = tree->accept(&visitor).as<std::map<string, StaticPtg>>();
   std::map<string, Ptg> res = visitor.visitPtg((PTGParser::PtgContext *) tree).as<std::map<string, Ptg>>();



   std::map<string, Ptg> :: iterator it = res.begin();
	while(it != res.end()) {
		cout << it->first << endl;
      Ptg staticPtg = it->second;
      staticPtg.print();
		it++;
	}

   return res;

}