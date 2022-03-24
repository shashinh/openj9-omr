
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct StaticPtg2 {
    std::map <std::string, std::set<std::string>> varsMap;
    std::map <std::string, std::set<std::string>> fieldsMap;
};


enum EntryType {
    String,
    Constant,
    Null,
    Global,
    Reference
};


struct Entry {
    int caller = -1;
    int bci = -1;

    int type;
    bool isString = false;
    bool isConstant = false;
    bool isNull = false;
    bool isGlobal = false;
    bool isRef = false;

    string getString() {
        string res;
        if(type == Reference) {
            res.append(to_string(caller)).append("-").append(to_string(bci));
        } else if (type == String) {
            res = "s";
        } else if (type == Constant) {
            res = "c";
        } else if (type == Global) {
            res = "BOT";
        } else {
            res = "NULL";
        }

        return res;
    }
};
struct StaticPtg {
    //key - stack slot number (i.e. a unique identifier for the variable in a given method)
    //value - a set of Entrys
    std::map <int, std::vector<Entry> > varsMap;
    std::map <int, std::map <std::string, std::vector <Entry>>> fieldsMap;
    //std::map <int, std::vector <Entry>> fieldsMap;
};

