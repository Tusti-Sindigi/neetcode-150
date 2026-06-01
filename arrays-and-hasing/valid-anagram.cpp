#include <stdio.h>
#include <string>
#include <map>
using std::string;
using std::map;

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size()!=t.size())
            return false;

        map<char, int> m;

        for(char c: s)
            m[c]++;
        for(char c: t)
            m[c]--;

        //auto --> tells figure out the type urself
        for(auto c: m)
            if(c.second!=0)
                return false;
        
        return true;
    }
};