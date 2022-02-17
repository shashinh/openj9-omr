
#include <iostream>
#include <map>
#include <set>

using namespace std;

struct Ptg
{
    std::map<std::string, std::set<std::string>> varsMap;
    std::map<std::string, std::set<std::string>> fieldsMap;

    std::string toString() {
        std::string res;
        res = res + "\tRoots: ";
        std::map<string, std::set<string>>::iterator vIt = varsMap.begin();
        while (vIt != varsMap.end())
        {
            res = res + vIt->first + ": ";
            //cout << vIt->first << ": ";
            auto i = vIt->second.begin();
            while (i != vIt->second.end())
            {   
                res = res + *i + " ";
                i++;
            }
            res = res + ",";
            vIt++;
        }
        res = res + "\n";
        res = res + "\tHeap: ";

        std::map<string, std::set<string>>::iterator fIt = fieldsMap.begin();
        while (fIt != fieldsMap.end())
        {
            res = res + fIt->first + ": ";
            auto f = fIt->second.begin();
            while (f != fIt->second.end())
            {
                res = res + *f + " ";
                f++;
            }
            res = res + ",";
            fIt++;
        }
        res = res + "\n";

        return res;

    }

    void print()
    {
        std::map<string, std::set<string>>::iterator vIt = varsMap.begin();
        while (vIt != varsMap.end())
        {
            cout << vIt->first << ": ";
            auto i = vIt->second.begin();
            while (i != vIt->second.end())
            {
                cout << *i << " ";
                i++;
            }
            cout << ",";
            vIt++;
        }
        cout << endl;

        std::map<string, std::set<string>>::iterator fIt = fieldsMap.begin();
        while (fIt != fieldsMap.end())
        {
            cout << fIt->first << ": ";
            auto f = fIt->second.begin();
            while (f != fIt->second.end())
            {
                cout << *f << " ";
                f++;
            }
            cout << ",";
            fIt++;
        }
        cout << endl;
    }
};