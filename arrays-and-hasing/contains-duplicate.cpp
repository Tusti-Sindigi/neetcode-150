#include<iostream>
#include<vector>
using std::vector;
#include<unordered_map>
using std::unordered_map;

class Solution {
public:

    //or for pre sorting just use: sort(nums.begin(), nums.end())
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_map<int, int> v;

        for(int num : nums)
        {
            if(v[num])
                return true;
            v[num]++;
        }
        return false;
    }
};