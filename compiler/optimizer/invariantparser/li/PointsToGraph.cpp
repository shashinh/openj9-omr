#include "PointsToGraph.h"



std::map <int, std::set <Entry> >  PointsToGraph::getRho() {
    return rho;
}
std::map <Entry, std::map <string, set <Entry> > > PointsToGraph::getSigma() {
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

set <Entry> PointsToGraph::getPointsToSet(Entry target, string field) {
    set <Entry> res;

    map <Entry, map <string, set <Entry> > >::iterator it1 = sigma.find(target);
    if(it1 != sigma.end()) {
        map <string, set <Entry> > m = it1->second;
        map <string, set <Entry> > :: iterator it2 = m.find(field);
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
    entry->type = Global;
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

    std::map <Entry, std::map <string, set <Entry> > >::iterator sigmaIterator = sigma.begin();
    while(sigmaIterator != sigma.end()) {
        res.append("\n");
        Entry target = sigmaIterator->first;
        res.append(target.getString()).append(": ");
        map <string, set <Entry> > fieldMap = sigmaIterator->second;
        map <string, set <Entry> >::iterator fieldIterator = fieldMap.begin();
        while(fieldIterator != fieldMap.end()) {
            string field = fieldIterator->first;
            res.append("\n\t").append(field).append(": ");
            set <Entry> pointsToSet = fieldIterator->second;
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

void PointsToGraph::assign(Entry target, string field, Entry pointee){

    set <Entry> pointees;
    pointees.insert(pointee);
    sigma[target][field] = pointees;
}

void PointsToGraph::assign(Entry target, string field, set <Entry> pointees){
    sigma[target][field] = pointees;
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

PointsToGraph::PointsToGraph(std::map <int, std::set <Entry> > rho,  std::map <Entry, std::map <string, set <Entry> > > sigma) {
    this->rho = rho;
    this->sigma = sigma;
}


PointsToGraph::PointsToGraph(const PointsToGraph &ptg) {
    this->rho = ptg.rho;
    this->sigma = ptg.sigma;
}

void PointsToGraph::printArgs() {
    cout << getArgsString();
}

void PointsToGraph::killRho() {
    this->rho.clear();
}

void PointsToGraph::setBotReturn() {
    assignBot(RETURNLOCAL);
}

void PointsToGraph::summarizeFields(int symRef) {
    set <Entry> targets = getPointsToSet(symRef);
    for(Entry target : targets) {
        //get the entire sigma map for this target
//        std::map <int, std::map <string, vector <Entry> > > sigma;
        map <Entry, std::map <string, set <Entry> > > :: iterator sigmaIterator = this->sigma.find(target);

        if(sigmaIterator != this->sigma.end()) {
            //we have some heap references reachable from this target
            //go ahead and summarize all of them
            map <string, set <Entry> > fieldsMap = sigmaIterator->second;
            map <string, set <Entry> > ::iterator fieldsIterator = fieldsMap.begin();
            while(fieldsIterator != fieldsMap.begin()) {
                string field = fieldsIterator->first;
                assign(target, field, getBotEntry()); 
            }


        }
    }
}