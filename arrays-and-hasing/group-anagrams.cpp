#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> so;
        unordered_map<string, int> map;
        int k=0;

        for(string st: strs)
        {
            string str=st;
            sort(str.begin(), str.end());
            if(map.find(str)==map.end())
            {
                map.insert({str, k});
                so.push_back({});
                k++;
            }
            so[map.find(str)->second].push_back(st);
        }

        return so;
    }
};