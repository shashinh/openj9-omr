#include "PointsToGraph.h"



std::map <int, std::set <Entry> >  PointsToGraph::getRho() {
    return rho;
}
std::map <int, std::map <string, vector <Entry> > > PointsToGraph::getSigma() {
    return sigma;
}




set <Entry> PointsToGraph::getPointsToSet(int symRef) {
    cout << "ho ho ho you requested for the ptg set for bci " << symRef << endl;
    set <Entry> res;

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

set <Entry> PointsToGraph::getArgPointsToSet(int argIndex) {
    return args[argIndex];
}

int PointsToGraph::summarize(Entry *entry) {
    return 0;
}

//TODO: this also has to go into the sigma map and 'bottomize' all assigned fields
int PointsToGraph::assignBot (int symRef) {
    //replace the points to set of the symRef with a singleton - BOT
    Entry botEntry;
    botEntry.type = Global;
    set <Entry> pointsToSet;
    pointsToSet.insert(botEntry);

    rho.insert(pair <int,  set <Entry>> (pair <int, set <Entry> >(symRef, pointsToSet)));

    return 0;

}

string PointsToGraph::getRhoString() {
    string res;
    res.append("RHO:\n");
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

    res.append("\n");
    return res;
}

string PointsToGraph::getSigmaString() {
    string res;
    res.append("SIGMA:\n");

    std::map <int, std::map <string, vector <Entry> > >::iterator sigmaIterator = sigma.begin();
    while(sigmaIterator != sigma.end()) {
        res.append("\n");
        int bci = sigmaIterator->first;
        res.append(to_string(bci)).append(": ");
        map <string, vector <Entry> > fieldMap = sigmaIterator->second;
        map <string, vector <Entry> >::iterator fieldIterator = fieldMap.begin();
        while(fieldIterator != fieldMap.end()) {
            string field = fieldIterator->first;
            res.append("\n\t").append(field).append(": ");
            vector<Entry> pointsToSet = fieldIterator->second;
            for(auto i : pointsToSet) {
                res.append(i.getString()).append(" ");
            }
            res.append("\n");
            fieldIterator++;
        }

        sigmaIterator++;        
    }
    
    res.append("\n");

    return res;
}

string PointsToGraph::getArgsString(){
    string res;
    res.append("ARGS:\n");
    auto varIterator = args.begin();
    while(varIterator != args.end()) {
        res.append("\n");
        int symRef = varIterator->first;
        res.append(to_string(symRef)).append(": ");
        set <Entry> pointsToSet = varIterator->second;
        for(auto i : pointsToSet) {
            res.append(i.getString()).append(" ");
        }
        res.append("\n");
        varIterator++;
    }

    res.append("\n");
    return res;

}
void PointsToGraph::print() {
    cout << getHeader();
    printRho();
    printSigma();
    printArgs();
    cout << getHeader();
}

void PointsToGraph::printRho() {
    cout << getRhoString();
}

void PointsToGraph::printSigma() {
    cout << getSigmaString();

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

void PointsToGraph::assign(int symRef, Entry entry) {
    printRho();
    
    set <Entry> entries;
    entries.insert(entry);
    cout << "inserting at symref " << symRef << endl;
    //rho.insert(std::pair <int, vector<Entry> > (symRef, entries));
    //rho.insert(std::pair <int, vector <Entry> > (std::pair <int, vector <Entry> > (symRef, entries)));
    rho[symRef] = entries;
    //rho.insert(std::pair <int, vector <Entry> > (std::pair <int, vector <Entry> >(symRef, pointsToSet)));
}

void PointsToGraph::assign(int symRef, set <Entry> entries){
    for(Entry entry : entries) {
        assign(symRef, entry);
    }
}

void PointsToGraph::assign(int bci, string field, int bciToAssign){
 
    Entry entry;
    entry.bci = bciToAssign;
    entry.caller = 99;
    entry.type = Reference;
    vector<Entry> entries;
    entries.push_back(entry);

    map <string, vector <Entry> > fieldsMap = sigma[bci];
    fieldsMap[field] = entries;
    sigma[bci] = fieldsMap;
}

void PointsToGraph::assign(int bci, string field, vector<int> bcisToAssign){
    for(int bciToAssign : bcisToAssign) {
        assign(bci, field, bciToAssign);
    }
 
}

void PointsToGraph::extend(int symRef, int bci){
    set <Entry> entries = rho[symRef];
    Entry entry;
    entry.bci = bci;
    entry.caller = 99;
    entry.type = Reference;

    entries.insert(entry);

    rho[symRef] = entries;
}

void PointsToGraph::extend(int symRef, vector<int> bcis){
    for(auto bci : bcis) {
        extend(symRef, bci);
    }
}

void PointsToGraph::setArg(int argIndex, set <Entry> values) {
    args[argIndex] = values;
}

void PointsToGraph::killArgs() {
    args.clear(); 
}

PointsToGraph::PointsToGraph() {
    
}

PointsToGraph::PointsToGraph(std::map <int, std::set <Entry> > rho,  std::map <int, std::map <string, vector <Entry> > > sigma) {
    this->rho = rho;
    this->sigma = sigma;
}


void PointsToGraph::printArgs() {
    cout << getArgsString();
}