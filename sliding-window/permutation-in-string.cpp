#include <string>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int n1=s1.size(), n2=s2.size();

        if(n1>n2)
            return false;

        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        int i=0;

        while(i<n1)
        {
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
            i++;
        }
        
        if(v1==v2)
            return true;

        while(i<n2)
        {
            v2[s2[i]-'a']++;
            v2[s2[i-n1]-'a']--;
            i++;

            if(v1==v2)
                return true;
        }
        return false;
    }
};