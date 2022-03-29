#include <bits/stdc++.h>
#include "structs.h"
using namespace std;

class PointsToGraph {
    private:
        std::map <int, std::vector<Entry> > rho;
        std::map <int, std::map <string, vector <Entry> > > sigma;
        int summarize(Entry * entry);
        string getHeader();
    public:
        vector<Entry> getPointsToSet (int symRef);
        vector<Entry> getPointsToSet (int bci, string field);
        int assignBot (int symRef);
        int assignBot (int bci, string field);
        void printRho();
        void printSigma();
        void print();
        void dumpRho();
        void dumpSigma();
        void dump();
        string getRhoString();
        string getSigmaString();
        bool equals(PointsToGraph &other);

        PointsToGraph * meet(PointsToGraph &other);

        void assign(int symRef, int bci);
        
};