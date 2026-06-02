#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> so;
        unordered_map<string, vector<string>> map;

        for(string st: strs)
        {
            vector <int> k(26, 0);
            for(char c: st)
                k[c-'a']++;

            string s=to_string(k[0]);
            for(int i=1;i<26;i++)
                s+=','+to_string(k[i]);

            map[s].push_back(st);
        }

        for(auto st: map)
            so.push_back(st.second);

        return so;
    }
};