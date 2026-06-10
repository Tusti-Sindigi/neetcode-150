#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> res;
        map<vector<int>, int> m;

        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size()-2;i++)
        {
            while(i>0 && nums[i]==nums[i-1] && i<nums.size()-2) // or u can also skip 3rd check and just do continue instead of i++
                i++;

            int l=i+1, r=nums.size()-1;

            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];

                if(sum==0)
                {
                    res.push_back({nums[i],nums[l], nums[r]});

                    while(l<r && nums[l]==nums[l-1])
                        l++;

                    while(l<r && nums[r]==nums[r+1])
                        r--;
                }
                else if(sum>0)
                    r--;
                else
                    l++;
            }
        }

        return res;
    }
};