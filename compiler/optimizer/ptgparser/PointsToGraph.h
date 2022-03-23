#include <bits/stdc++.h>
#include "structs.h"
using namespace std;

class PointsToGraph {
    private:
        std::map <int, std::vector<Entry> > rho;
        std::map <int, std::map <string, vector <Entry> > > sigma;
        int summarize(Entry * entry);
    public:
        vector<Entry> getPointsToSet (int bci);
        vector<Entry> getPointsToSetForField (int bci, string field);
        
};