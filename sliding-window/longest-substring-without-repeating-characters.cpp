#include <unordered_map>
#include <string.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> map;
        int l=0, count=0;

        for(int r=0;r<s.size();r++)
        {
            if(map.find(s[r])!=map.end())
                l=max(map[s[r]]+1, l);

            map[s[r]]=r;
            count=max(r-l+1, count);
        }

        return count;
    }
};