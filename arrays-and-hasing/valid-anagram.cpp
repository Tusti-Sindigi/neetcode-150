#include <stdio.h>
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if (s.length()!=t.length()) 
            return false;

        unordered_map<char, int> sc;
        unordered_map<char, int> tc;

        for(int i=0;i<s.length();i++)
        {
            sc[s[i]]++;
            tc[t[i]]++;
        }

        return sc==tc;
    }
};