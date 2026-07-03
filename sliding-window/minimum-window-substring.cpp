#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char, int> vt;
        unordered_map<char, int> vs;

        for(char c: t)
            vt[c]++;

        int l=-1, minl=-1, minr=-1, req=vt.size(), curr=0;

        for(int r=0;r<s.size();r++)
        {
            if(vt.find(s[r])!=vt.end())
            {
                vs[s[r]]++;
                if(l==-1)
                    l=r;
            
                if(vt[s[r]]==vs[s[r]])
                    curr++;

                while(l<=r && curr==req)
                {
                    if((minl==-1 && minr==-1) || (r-l < minr-minl))   // or (r-l+ < minr-minl+1) is also okay for 2nd expression
                        {
                            minl=l;
                            minr=r;
                        }

                    if(vt[s[l]]==vs[s[l]])
                        curr--;
                    
                    vs[s[l]]--;
                    l++;

                    while(l<=r && vt.find(s[l])==vt.end())
                        l++;
                }
            }
        }

        if(minl==-1 && minr==-1)
            return "";
        return s.substr(minl, minr-minl+1);
    }
};