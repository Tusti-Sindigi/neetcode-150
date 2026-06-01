#include <stdio.h>
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        // can do with 26 length array also
        int a[26]={0};

        if(s.size()!=t.size())
            return false;

        for(char c: s)
            a[c-'a']++;

        for(char c: t)
            a[c-'a']--;

        for(int i=0;i<26;i++)
            if(a[i]!=0)
                return false;

        return true;
    }
};