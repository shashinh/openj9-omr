#include "PointsToGraph.h"

vector <Entry> PointsToGraph::getPointsToSet(int bci) {
    cout << "ho ho ho you requested for the ptg set for bci " << bci << endl;
    vector <Entry> res;

    if(rho.find(bci) != rho.end()) {
        res = rho.find(bci)->second;
    }

    return res;
}

vector <Entry> PointsToGraph::getPointsToSetForField(int bci, string field) {
    vector <Entry> res;

    map <int, map <string, vector <Entry> > >::iterator it1 = sigma.find(bci);
    if(it1 != sigma.end()) {
        map <string, vector <Entry> > m = it1->second;
        map <string, vector <Entry> > :: iterator it2 = m.find(field);
        if(it2 != m.end()) {
            res = it2->second;
        }
    }

    return res;
}

int PointsToGraph::summarize(Entry *entry) {
    return 0;
}
