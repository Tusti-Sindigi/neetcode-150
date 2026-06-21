#include <string>
#include<unordered_map>
using namespace std;

//v bad executuion time

class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        unordered_map<char, int> m2;

        for(char c:s1)
            m2[c]++;

        unordered_map<char, int> m=m2;

        int i=0;
        while(i<s2.length())
        {
            int k=i+1;

            while(i<s2.length() && m2.find(s2[i])!=m2.end())
            {
                m2[s2[i]]--;

                if(m2[s2[i]]==0)
                    m2.erase(s2[i]);

                i++;
            }
            if(m2.empty())
                return true;
            else
            {
                i=k;
                m2=m;
            }   
        }
        return false;
    }
};