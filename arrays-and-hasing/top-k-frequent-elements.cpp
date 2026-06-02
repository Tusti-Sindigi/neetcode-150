#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> res;
        unordered_map<int, int> map;
        for(int n: nums)
        {
            if(map.find(n)==map.end())
                map.insert({n,0});

            map[n]++;
        }

        for(int i=0;i<k;i++)
        {
            int max=0;
            int value;
            for(auto c: map)
            {
                if(c.second>max)
                {
                    max=c.second;
                    value=c.first;
                }

            }
            res.push_back(value);
            map.erase(value);
        }

        return res;
    }
};