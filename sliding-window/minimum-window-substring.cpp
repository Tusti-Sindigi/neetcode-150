#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) 
    {
        vector<int> v(256, 0);

        int l=0, r=0, start=-1, minlen=INT_MAX, count=0;

        for(char c: t)
            v[c]++;

        while(r<s.size())
        {
            if(v[s[r]]>0)
                count++;

            v[s[r]]--;

            while(count==t.size())
            {
                if(r-l+1<minlen)
                {
                    minlen=r-l+1;
                    start=l;
                }

                v[s[l]]++;

                if(v[s[l]]>0)
                    count--;

                l++;
            }
            r++;
        }
        return start==-1? "" : s.substr(start, minlen);
    }
};