#include <bits/stdc++.h>
#include "structs.h"
using namespace std;


class PointsToGraph {
    private:
        //TODO: why did I make this a vector instead of a set?
        std::map <int, set <Entry> > rho;
        //TODO: sigma should be keyed by a caller-index--bci pair (to uniquely identify it)
        std::map <Entry, std::map <string, set  <Entry> > > sigma;
        //this is a hack
        std::map <int, std::set <Entry> > args;
        int summarize(Entry * entry);
        string getHeader();
        Entry getBotEntry();
    public:
        PointsToGraph();
        PointsToGraph(std::map <int, std::set <Entry> > rho,  std::map <Entry, std::map <string, set <Entry> > > sigma);
        PointsToGraph(const PointsToGraph &ptg);
        static const Entry bottomEntry;
        static const Entry nullEntry;
        static const int RETURNLOCAL;
        static set<Entry> getBotSet();
        std::map <int, std::set <Entry> > getRho();
        std::map <Entry, std::map <string, set <Entry> > > getSigma();
        void setArg(int argIndex, set <Entry> values);
        set <Entry> getArgPointsToSet(int argIndex);
        set <Entry> getPointsToSet (int symRef);
        set <Entry> getPointsToSet (Entry target, string field);
        set <Entry> getReturnPointsTo ();
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

        void ptgUnion(PointsToGraph *a, PointsToGraph *b);

        //assign a single bci to the points-to set of a symRef
        void assign(int symRef, Entry entry);
        //assign a collection of bcis to the points-to set of a symRef
        void assign(int symRef, set <Entry> entries);

        //assign a single bci to the points-to set of a field
        void assign(Entry target, string field, Entry entry);
        //assign a collection of bcis to the points-to set of a field
        void assign(Entry target, string field, set <Entry> entries);

        //assign to the return variable
        void assignReturn(set <Entry> pointees);

        //weak updates
        void extend(int symRef, Entry pointee);
        //weak updates
        void extend(int symRef, set <Entry> pointees);
        void killArgs();

        void killRho();

        void setBotReturn();

        void summarizeFields(int symRef);

        bool subsumes(PointsToGraph * other, bool callSite = false);

        void copySigmaFrom(PointsToGraph *other);
        
};