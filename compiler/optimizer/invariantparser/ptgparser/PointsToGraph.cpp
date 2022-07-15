#include "PointsToGraph.h"


const Entry PointsToGraph::bottomEntry = { .caller = -1, .bci = -1, .type = Global };
const Entry PointsToGraph::nullEntry = { .caller = -1, .bci = -1, .type = Null };

std::map <int, std::set <Entry> >  PointsToGraph::getRho() {
    return rho;
}
std::map <int, std::set <Entry> >  PointsToGraph::getArgs() {
    return args;
}
std::map <Entry, std::map <string, set <Entry> > > PointsToGraph::getSigma() {
    return sigma;
}




set <Entry> PointsToGraph::getPointsToSet(int symRef) {
    set <Entry> res;

    if(rho.find(symRef) != rho.end()) {
        res = rho.find(symRef)->second;
    }

    return res;
}

set <Entry> PointsToGraph::getPointsToSet(Entry target, string field) {
    set <Entry> res;
    
    //dereferencing a global or null yields a global
    if(target.type == Global || target.type == Null) {
        //Entry globalPointee;
        //globalPointee.type = Global;
        //res.insert(globalPointee);

        return PointsToGraph::getBotSet();
    }

    bool nullReference = false;
    // map <Entry, map <string, set <Entry> > >::iterator it1 = sigma.find(target);
    if(sigma.find(target) != sigma.end()) {
        map <string, set <Entry> > m = sigma[target];
        if(m.find(field) != m.end()) {
            // cout << "found " << field << " in sigma" << endl;
            res = m[field];
        }
        else {
            nullReference = true;
        }
    } else {
        nullReference = true;
    }

    if(nullReference) {
        //we interpret the absence of a key in sigma as Null
        // cout << target.getString() << "->" << field << " is null" << endl;
        // Entry pointee;
        // pointee.type = Null;
        // res.insert(pointee);
        return PointsToGraph::getBotSet();
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
    //Entry botEntry;
    //botEntry.type = Global;
    set <Entry> pointsToSet;
    //pointsToSet.insert(botEntry);
    pointsToSet.insert(PointsToGraph::bottomEntry);
    rho[symRef] = pointsToSet;
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
//    cout << "inserting at symref " << symRef << endl;
    //rho.insert(std::pair <int, vector<Entry> > (symRef, entries));
    //rho.insert(std::pair <int, vector <Entry> > (std::pair <int, vector <Entry> > (symRef, entries)));
    rho[symRef] = entries;
    //rho.insert(std::pair <int, vector <Entry> > (std::pair <int, vector <Entry> >(symRef, pointsToSet)));
}

void PointsToGraph::assign(int symRef, set <Entry> entries){
//    for(Entry entry : entries) {
//        assign(symRef, entry);
//    }
    rho[symRef] = entries;
}

void PointsToGraph::assign(Entry target, string field, Entry pointee){

    set <Entry> pointees;
    pointees.insert(pointee);
    sigma[target][field] = pointees;
}

void PointsToGraph::assign(Entry target, string field, set <Entry> pointees){
    sigma[target][field] = pointees;
}

void PointsToGraph::extend(int symRef, Entry pointee){
    rho[symRef].insert(pointee);
}

void PointsToGraph::extend(int symRef, set <Entry> pointees){
    rho[symRef].insert(pointees.begin(), pointees.end());
}

void PointsToGraph::extend(Entry target, string field, Entry pointee) {
    sigma[target][field].insert(pointee);
}
void PointsToGraph::extend(Entry target, string field, set<Entry> pointees) {
    sigma[target][field].insert(pointees.begin(), pointees.end());
}

void PointsToGraph::setArg(int argIndex, set <Entry> values) {
    args[argIndex] = values;
}

void PointsToGraph::killArgs() {
    args.clear(); 
}

PointsToGraph::PointsToGraph() {
    map <int, std::set <Entry> > rho;
    this->rho = rho;
    map <Entry, std::map <string, set <Entry> > > sigma;
    this->sigma = sigma;
}

PointsToGraph::PointsToGraph(std::map <int, std::set <Entry> > rho,  std::map <Entry, std::map <string, set <Entry> > > sigma) {
    this->rho = rho;
    this->sigma = sigma;
}


PointsToGraph::PointsToGraph(const PointsToGraph &ptg) {
    this->rho = ptg.rho;
    this->sigma = ptg.sigma;
    this->args = ptg.args;
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

void PointsToGraph::ptgUnion(PointsToGraph *a, PointsToGraph *b) {

        std::map <int, set <Entry> > rho;
        //TODO: sigma should be keyed by a caller-index--bci pair (to uniquely identify it)
        std::map <Entry, std::map <string, set  <Entry> > > sigma;
    
    set<int> allRhoKeys;
    set<int> rhoKeys_a;
    set<int> rhoKeys_b;

    for(map <int, set<Entry> > ::iterator it = a->rho.begin(); it != a->rho.end(); it++) {
        rhoKeys_a.insert(it->first);
    }
    for(map <int, set<Entry> > ::iterator it = b->rho.begin(); it != b->rho.end(); it++) {
        rhoKeys_b.insert(it->first);
    }

    allRhoKeys.insert(rhoKeys_a.begin(), rhoKeys_a.end());
    allRhoKeys.insert(rhoKeys_b.begin(), rhoKeys_b.end());

    for(int var : allRhoKeys) {
        set <Entry> pointees;
        if(a->rho.find(var) != a->rho.end()) {
            set<Entry> temp = a->rho[var];
            pointees.insert(temp.begin(), temp.end());
        }
        if(b->rho.find(var) != b->rho.end()) {
            set<Entry> temp = b->rho[var];
            pointees.insert(temp.begin(), temp.end());
        }

        rho[var] = pointees;
        this->rho = rho;

    }

    set <Entry> allSigmaKeys;
    set <Entry> sigmaKeys_a;
    set <Entry> sigmaKeys_b;

    for(map <Entry, map<string, set <Entry>>>::iterator it = a->sigma.begin(); it != a->sigma.end(); it++) {
        sigmaKeys_a.insert(it->first);
    }
    for(map <Entry, map<string, set <Entry>>>::iterator it = b->sigma.begin(); it != b->sigma.end(); it++) {
        sigmaKeys_b.insert(it->first);
    }

    allSigmaKeys.insert(sigmaKeys_a.begin(), sigmaKeys_a.end());
    allSigmaKeys.insert(sigmaKeys_b.begin(), sigmaKeys_b.end());

    for(Entry obj : allSigmaKeys) {

        if(a->sigma.find(obj) != a->sigma.end()) {
            for(map <string, set<Entry>>::iterator it = a->sigma[obj].begin(); it != a->sigma[obj].end(); it++) {
                sigma[obj][it->first].insert(it->second.begin(), it->second.end());
            }
        }

        if(b->sigma.find(obj) != b->sigma.end()) {
            for(map <string, set<Entry>>::iterator it = b->sigma[obj].begin(); it != b->sigma[obj].end(); it++) {
                sigma[obj][it->first].insert(it->second.begin(), it->second.end());
            }
        }

    }

    this->sigma = sigma;
    // cout << "printing ptg from ptgunion" << endl;
    // this->print();

}

bool PointsToGraph::subsumes(PointsToGraph *other, bool callSite) {

    cout << "subsumes check requested for ptgs " << endl;
    cout << "lhs : " << endl;
    this->print();
    cout << "rhs :" << endl;
    other->print();

    map <int, set <Entry> > otherRho;
    //if the subsumes check if requested at a callsite, then we compare rho_LHS with args_RHS
    //else rho_LHS with rho_RHS
    if(callSite) {
        // cout << "callsite subsumes requested\n";
        // cout << "lhs\n";
        // this->print();
        // cout << "rhs\n";
        // other->print();
        otherRho = other->args;
    } else {
        otherRho = other->rho;
    }

    //this-ptg needs to subsume other-ptg
    
    //1. check rho subsumes
    for(map<int, set<Entry>>::iterator it = otherRho.begin(); it != otherRho.end(); it++) {
        //we only check subsumes between rho entries that are present in both ptgs
        //because it is entirely possible for the runtime ptg to have extra rho entries (temps, for example)
        if(rho.find(it->first) != rho.end()) {
            set <Entry> rhsPointees = it->second;
            //hack-begin - to account for library functions being summarized
            rhsPointees.erase(PointsToGraph::bottomEntry);
            rhsPointees.erase(PointsToGraph::nullEntry);
            //hack-end
            set <Entry> lhsPointees = rho[it->first];
            if(lhsPointees.find(PointsToGraph::bottomEntry) != lhsPointees.end()  ) {
            // ||                             rhsPointees.find(PointsToGraph::bottomEntry) != rhsPointees.end()) {
                //Bot subsumes anything, no need to check RHS
                //do we need messaging?
                // cout << "found BOT in LHS pointees" << endl;
            } else {
                //lhsPointees should be a superset of rhsPointees
                if(! includes(lhsPointees.begin(),  lhsPointees.end(), 
                                rhsPointees.begin(), rhsPointees.end())) {
                    return false;
                }
            }
        }
    }
    // cout << "rho subsumes passed" << endl;
    //2. check sigma subsumes
    for(map <Entry, map <string, set<Entry>>>::iterator it = other->sigma.begin(); it != other->sigma.end(); it++) {
       if(this->sigma.find(it->first) != this->sigma.end()) {
           map <string, set <Entry>> rhsFields = it->second;
           map <string, set <Entry>> lhsFields = this->sigma[it->first];

           //once again, we only check for object x fields that are present in both ptgs
           for( map <string, set <Entry>>::iterator i = rhsFields.begin(); i != rhsFields.end(); i++) {
               if(lhsFields.find(i->first) != lhsFields.end()) {
                   set <Entry> rhsPointees = i->second;
                   set <Entry> lhsPointees = lhsFields[i->first];
                    //hack-begin - to account for library functions being summarized
                    rhsPointees.erase(PointsToGraph::bottomEntry);
                    rhsPointees.erase(PointsToGraph::nullEntry);
                    //hack-end
                    if(lhsPointees.size() == 1 && lhsPointees.find(PointsToGraph::bottomEntry) != lhsPointees.end()) {
                        //Bot subsumes anything, no need to check RHS
                        //do we need messaging?
                    } else {
                            //lhsPointees should be a superset of rhsPointees
                            if(! includes(lhsPointees.begin(),  lhsPointees.end(), 
                                            rhsPointees.begin(), rhsPointees.end())) {
                                return false;
                            }
                    }
               }
           }
       } 
    }

    // cout << "sigma subsumes passed" << endl;

    //if we made it here, lhs subsumes rhs
    return true;
}

void PointsToGraph::assignReturn(set <Entry> pointees) {
    assign(RETURNLOCAL, pointees);
}

set <Entry> PointsToGraph::getReturnPointsTo() {
    return rho[RETURNLOCAL];
}

set <Entry> PointsToGraph::getBotSet() {
    set <Entry> ret;
    ret.insert(bottomEntry);

    return ret;
}

void PointsToGraph::copySigmaFrom(PointsToGraph *other) {
    this->sigma = other->sigma;
}

map <Entry, map <string, set <Entry> > > PointsToGraph::getReachableHeap (Entry target, map <Entry, map <string, set <Entry> > > sigma) {
    cout << "entered getreachable heap\n";
    map <Entry, map <string, set<Entry> > > res;

    set <Entry> reachedObjects;
    reachedObjects.insert(target);
    if(sigma.find(target) != sigma.end()) {
        map <string, set<Entry> > fields = sigma[target];
        res[target] = fields;
    
        map <string, set<Entry> > :: iterator fieldsIt = fields.begin();
        while(fieldsIt != fields.end()) {
            set <Entry> reachableObjects = fieldsIt->second;
            for(Entry reachable : reachableObjects) {
                cout << "reachable obj " << reachable.getString() << "\n";

                if(reachedObjects.find(reachable) != reachedObjects.end() || reachable == PointsToGraph::bottomEntry || reachable == PointsToGraph::nullEntry) {
                    //make sure we don't end up in an infinite recursion!
                    continue;
                }

                reachedObjects.insert(reachable);

                map <Entry, map <string, set <Entry> > > reachableHeap = getReachableHeap(reachable, sigma);
                res.insert(reachableHeap.begin(), reachableHeap.end());
            }
            fieldsIt++;
        }
    }

    cout << "exiting getreachable heap\n";
    return res;

}

void PointsToGraph::projectReachableHeapFromCallSite(PointsToGraph *other) {
    //this : callsite ptg; other : out flow from callee
    cout << "before projectio\n";
    this->print();
    map <Entry, map <string, set <Entry> > > inSigma = this->sigma;
    map <Entry, map <string, set <Entry>  > > outSigma = other->sigma;

    //weak updates here as well!

    // map <int, set <Entry> > inRho = this->rho;
    map <int, set <Entry> > outRho = other->args;

    //for each arg at the call site, we want to map the reachable heap back to the in-ptg's sigma
    map <int, set <Entry> > :: iterator outRhoIt = outRho.begin();
    while(outRhoIt != outRho.end()) {
        int argIndex = outRhoIt->first;
        set <Entry> argsPointsTo = outRhoIt->second;

        for(Entry pointee : argsPointsTo) {
            //fetch the reachable heap
            map <Entry, map <string, set <Entry> > > reachableHeap = getReachableHeap(pointee, outSigma);
            map <Entry, map <string, set <Entry> > > :: iterator reachableHeapIt = reachableHeap.begin();
            while(reachableHeapIt != reachableHeap.end()) {
                Entry target = reachableHeapIt->first;
                map <string, set <Entry> > targetFields = reachableHeapIt->second;
                map <string, set <Entry> > :: iterator targetFieldsIt = targetFields.begin();

                while(targetFieldsIt != targetFields.end()) {
                    string field = targetFieldsIt->first;
                    set <Entry> pointees = targetFieldsIt->second;

                    //weak updates only!
                    this->sigma[target][field].insert(pointees.begin(), pointees.end());

                    targetFieldsIt++;
                }

                reachableHeapIt++;
            }
            

        }

        outRhoIt++;
    }


    cout << "after projectio\n";
    this->print();
}

const int PointsToGraph::RETURNLOCAL = -99;

//summarizes the heap objects reachable from the given abstract object
void PointsToGraph::summarizeReachableHeap (Entry target) {
    map <string, set <Entry> > reachableHeap = this->sigma[target];

    map <string, set <Entry> > :: iterator reachableHeapIterator = reachableHeap.begin();
    while(reachableHeapIterator != reachableHeap.end()) {
        set <Entry> targets = reachableHeapIterator->second;
        this->sigma[target][reachableHeapIterator->first] = PointsToGraph::getBotSet();

        for(Entry target : targets) {
            this->summarizeReachableHeap(target);
        }

        reachableHeapIterator++;
    }

}

void PointsToGraph::summarizeReachableHeapAtCallSite() {
    cout << "entered summarizereachableheapatcallsite\n";

    //for each reference type argument, summarize its reachable heap
    //summarizing is achieved by marking the abstract object as "escaping"

    // cout << "summarize reachable heap requested for : \n";
    // this->print();

    map <int, set <Entry> > :: iterator argsIterator = this->args.begin();
    while(argsIterator != this->args.end()) {
        for(Entry target : argsIterator->second) {
            this->summarizeReachableHeap(target);
        }
        argsIterator++;
    }
    cout << "exiting summarizereachableheapatcallsite\n";
    // this->print();

}

bool PointsToGraph::isTop() {
    return rho.empty() && sigma.empty() && args.empty();
}

void PointsToGraph::copyArgsFrom(PointsToGraph *other) {
    this->args = other->args;
}

void PointsToGraph::projectReachableHeapFromArgs() {
    cout << "entered projectheap from args\n";
    map <Entry, map <string, set <Entry> > > inSigma = this->sigma;

    this->sigma.clear();
    map <int, set<Entry> > :: iterator argsIterator = this->args.begin();
    while(argsIterator != this->args.end()) {
        for(Entry pointee : argsIterator->second) {
            cout << "pointee: " << pointee.getString() << "\n";
            map <Entry, map <string, set <Entry> > > reachable = getReachableHeap(pointee, inSigma);
            this->sigma.insert(reachable.begin(), reachable.end());
            cout << "done pointee: " << pointee.getString() << "\n" << pointee.getString() << "\n";;
        }

        argsIterator++;
    }
    cout << "exiting projectheap from args\n";
}

void PointsToGraph::mergeSigmaFrom(PointsToGraph *other) {
    // cout << "merging sigma from \n";
    // other->print();
    // cout << "to \n";
    // this->print();
    // this->sigma.insert(other->sigma.begin(), other->sigma.end());
    map <Entry, map <string, set <Entry > > > :: iterator otherSigmaIt = other->sigma.begin();
    while(otherSigmaIt != other->sigma.end()) {
        this->sigma[otherSigmaIt->first] = otherSigmaIt->second;

        otherSigmaIt ++;
    }
}