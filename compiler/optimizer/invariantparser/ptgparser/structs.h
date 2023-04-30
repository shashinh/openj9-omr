#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>
#include <bits/stdc++.h>
#include <env/jittypes.h>
using namespace std;

enum EntryType
{
    String,
    Constant,
    Null,
    Global,
    Reference
};

struct Entry
{
    //encoded in the invariants
    int caller;
    int bci;
    int clazz;
    EntryType type;

    TR_OpaqueClassBlock *clazzPtr;



    string getString()
    {
        string res;
        if (type == Reference)
        {
            res.append(to_string(caller)).append("-").append(to_string(bci).append(" type: ").append(to_string(clazz).append(";")));
        }
        else if (type == String)
        {
            res = "s";
        }
        else if (type == Constant)
        {
            res = "c";
        }
        else if (type == Global)
        {
            res = "BOT";
        }
        else
        {
            res = "NULL";
        }

        return res;
    }
    bool operator<(const Entry &e) const
    {

        if (this->type == Reference && e.type == Reference)
        {
            return this->caller == e.caller ? this->bci < e.bci : this->caller < e.caller;
        }
        else
        {
            return this->type < e.type;
        }
    }

    bool operator==(const Entry &e) const
    {
        if (this->type != e.type)
        {
            return false;
        }
        else if (this->type == Reference)
        {
            return this->caller == e.caller && this->bci == e.bci;
        }
        else
        {
            return true;
        }

        return true;
    }
};

enum ConfigType {
    Avrora,
    Sunflow,
    Lusearch,
    Luindex,

    Fop,
    Pmd,
    Antlr,

    Compress,
    Sparse,
    Sor,
    Lu,
    Fft,
    Monte,

    Spec,

    Unknown
};

#endif
