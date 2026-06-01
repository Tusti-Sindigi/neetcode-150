#include<stdio.h>
#include<vector>
#include<algorithm>
using std::vector;
using std::pair;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {   
        vector<pair<int, int>> m;
        for(int i=0;i<nums.size();i++)
            m.push_back({nums[i], i});

        sort(m.begin(), m.end());
        int l=0, r=nums.size()-1;
        vector<int> res;
        while(l<r)
        {
            int sum=m[l].first+m[r].first;
            if(sum==target)
            {
                res.push_back(m[l].second);
                res.push_back(m[r].second);
                break;
            }
            else if(sum>target)
                r--;
            else
                l++;
        }
        return res;
    }
};