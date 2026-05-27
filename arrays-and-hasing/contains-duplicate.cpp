#include<iostream>
#include<vector>
using std::vector;
#include<unordered_set>
using std::unordered_set;

class Solution {
public:

    //or for pre sorting just use: sort(nums.begin(), nums.end())
    bool containsDuplicate(vector<int>& nums)
    {
       return unordered_set<int>(nums.begin(), nums.end()).size()<nums.size();
    }
};