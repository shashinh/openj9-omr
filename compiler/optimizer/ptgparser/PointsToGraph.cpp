#include "PointsToGraph.h"

vector <Entry> PointsToGraph::getPointsToSet(int symRef) {
    cout << "ho ho ho you requested for the ptg set for bci " << symRef << endl;
    vector <Entry> res;

    if(rho.find(symRef) != rho.end()) {
        res = rho.find(symRef)->second;
    }

    return res;
}

vector <Entry> PointsToGraph::getPointsToSet(int bci, string field) {
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

//TODO: this also has to go into the sigma map and 'bottomize' all assigned fields
int PointsToGraph::assignBot (int symRef) {
    //replace the points to set of the symRef with a singleton - BOT
    Entry botEntry;
    botEntry.type = Global;
    vector<Entry> pointsToSet;
    pointsToSet.push_back(botEntry);

    rho.insert(pair <int, vector<Entry>> (pair <int, vector<Entry> >(symRef, pointsToSet)));

    return 0;

}

string PointsToGraph::getRhoString() {
    string res;
    res.append(getHeader());
    
    auto varIterator = rho.begin();
    while(varIterator != rho.end()) {
        res.append("\n");
        int symRef = varIterator->first;
        res.append(to_string(symRef)).append(": ");
        auto pointsToSet = varIterator->second;
        for(auto i : pointsToSet) {
            res.append(i.getString()).append(" ");
        }
        res.append("\n");
        varIterator++;
    }

    res.append(getHeader());
    return res;
}

void PointsToGraph::print() {
    printRho();
    printSigma();
}

void PointsToGraph::printRho() {
    cout << getRhoString();
}

void PointsToGraph::printSigma() {

}

void PointsToGraph::dump() {

}

void PointsToGraph::dumpRho(){

}

void PointsToGraph::dumpSigma() {

}

string PointsToGraph::getHeader() {
    return "*************************************\n";
}

bool equals(PointsToGraph other) {
    bool equals = true;

    return equals;
}

void PointsToGraph::assign(int symRef, int bci) {
    printRho();
    
    Entry entry;
    entry.bci = bci;
    entry.caller = 99;
    entry.type = Reference;
    vector<Entry> entries;
    entries.push_back(entry);
    cout << "inserting at symref " << symRef << endl;
    //rho.insert(std::pair <int, vector<Entry> > (symRef, entries));
    rho.insert(std::pair <int, vector <Entry> > (std::pair <int, vector <Entry> > (symRef, entries)));
    //rho.insert(std::pair <int, vector <Entry> > (std::pair <int, vector <Entry> >(symRef, pointsToSet)));
}