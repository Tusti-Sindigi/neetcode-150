#include <stdio.h>
#include <string>
using std::string;

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int a[256]={0};

        if(s.size()!=t.size())
            return false;

        for(char c: s)
            a[c]++;

        for(char c: t)
            a[c]--;

        for(int i=0;i<256;i++)
            if(a[i]!=0)
                return false;

        return true;
    }
};