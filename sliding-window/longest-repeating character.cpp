#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k)
    {
        vector<int> m(26,0);

        int res=0, l=0, maxi=0;

        for(int r=0;r<s.size();r++)
        {
            m[s[r]-'A']++;
            maxi=max(maxi, m[s[r]-'A']);

            while((r-l+1)-maxi > k)
            {
                m[s[l]-'A']--;
                l++;
            }

            res=max(res, r-l+1);
        }
        return res;
    }
};