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
            map[n]++;

        vector<vector<int>> temp(nums.size()+1);

        for(auto c: map)
            temp[c.second].push_back(c.first);

        for(int i=temp.size()-1;i>0;i--)
        {
            for(int c: temp[i])
            {
                k--;
                res.push_back(c);
                if(k==0)
                    return res;
            }
            if(k==0)
                break;
        }
        return res;
    }
};