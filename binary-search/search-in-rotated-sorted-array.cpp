#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int l=0, r=nums.size()-1;

        if(r==l)
            if(nums[l]==target)
                return l;

        while(r-l>=1)
        {
            int m=(l+r)/2;

            if(r-l==1)
            {
                if(nums[l]==target)
                    return l;
                else if(nums[r]==target)
                    return r;
                else 
                    break;
            }
            if(nums[m]==target)
                return m;
            if(nums[l]<=nums[m])
                if(target>=nums[l] && target<nums[m])
                    r=m;
                else
                    l=m;
            else
                if(target<=nums[r] && target>nums[m])
                    l=m;
                else
                    r=m;
        }   
        return -1; 
    }
};