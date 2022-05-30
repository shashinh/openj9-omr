#include <bits/stdc++.h>
#include "structs.h"
using namespace std;

class PointsToGraph {
    private:
        //TOOD: why did I make this a vector instead of a set?
        std::map <int, set <Entry> > rho;
        //TODO: sigma should be keyed by a caller-index--bci pair (to uniquely identify it)
        std::map <int, std::map <string, vector <Entry> > > sigma;
        //this is a hack
        std::map <int, std::set <Entry> > args;
        int summarize(Entry * entry);
        string getHeader();
    public:
        PointsToGraph();
        PointsToGraph(std::map <int, std::set <Entry> > rho,  std::map <int, std::map <string, vector <Entry> > > sigma);

        std::map <int, std::set <Entry> > getRho();
        std::map <int, std::map <string, vector <Entry> > > getSigma();
        void setArg(int argIndex, set <Entry> values);
        set <Entry> getArgPointsToSet(int argIndex);
        set <Entry> getPointsToSet (int symRef);
        vector <Entry> getPointsToSet (int bci, string field);
        int assignBot (int symRef);
        int assignBot (int bci, string field);
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

        //assign a single bci to the points-to set of a symRef
        void assign(int symRef, Entry entry);
        //assign a collection of bcis to the points-to set of a symRef
        void assign(int symRef, set <Entry> entries);

        //assign a single bci to the points-to set of a field
        void assign(int bci, string field, int bciToAssign);
        //assign a collection of bcis to the points-to set of a field
        void assign(int bci, string field, vector <int> bcisToAssign);

        //weak updates
        void extend(int symRef, int bci);
        //weak updates
        void extend(int symRef, vector<int> bcis);
        void killArgs();
        
};