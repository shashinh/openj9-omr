#include <bits/stdc++.h>
#include "structs.h"
using namespace std;

class PointsToGraph {
    private:
        //TOOD: why did I make this a vector instead of a set?
        std::map <int, std::vector<Entry> > rho;
        //TODO: sigma should be keyed by a caller-index--bci pair (to uniquely identify it)
       //TODO :  https://stackoverflow.com/questions/1102392/how-can-i-use-stdmaps-with-user-defined-types-as-key
        std::map <Entry, std::map <string, vector <Entry> > > sigma;
        //this is a hack - key is the arg index
        std::map <int, std::vector<int> > args;
        int summarize(Entry * entry);
        string getHeader();
    public:
        PointsToGraph();
        PointsToGraph(std::map <int, std::vector<Entry> > rho,  std::map <Entry, std::map <string, vector <Entry> > > sigma);

        std::map <int, std::vector<Entry> > getRho();
        std::map <Entry, std::map <string, vector <Entry> > > getSigma();
        void setArg(int argIndex, vector<int> values);
        vector<int> getArgPointsToSet(int argIndex);
        vector<Entry> getPointsToSet (int symRef);
        vector<Entry> getPointsToSet (int methodIndex, int bci, string field);
        int assignBot (int symRef);
        int assignBot (int methodIndex, int bci, string field);
        void printRho();
        void printSigma();
        void printArgs();
        void print();
        void dumpRho();
        void dumpSigma();
        void dump();
        string getRhoString();
        string getSigmaString();
        string getArgsString();
        bool equals(PointsToGraph &other);

        PointsToGraph * meet(PointsToGraph &other);
        bool subsumes(PointsToGraph &other);

        //assign a single object to the points-to set of a symRef
        void assign(int symRef, int methodIndex, int bci);
        //assign a collection of objects to the points-to set of a symRef
        void assign(int symRef, vector<Entry> entries);

        //assign a single object to the points-to set of a field
        void assign(int methodIndex, int bci, string field, Entry entry);
        //assign a collection of objects to the points-to set of a field
        void assign(int methodIndex, int bci, string field, vector <Entry> entries);

        //weak updates
        void extend(int symRef, int methodIndex, int bci);
        //weak updates
        void extend(int symRef, vector<Entry> entries);
        void killArgs();
        
};