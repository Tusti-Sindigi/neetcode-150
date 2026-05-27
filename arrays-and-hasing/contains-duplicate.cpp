#include<iostream>
#include<vector>
using std::vector;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
       MergeSort(nums, 0, nums.size()-1);

       for(int i=1;i<nums.size();i++)
       {
            if(nums[i]==nums[i-1])
                return true;
       }

       return false;
    }

    void MergeSort(vector<int>& nums,int l ,int r)
    {
        if(l<r)
        {
            int m=(l+r)/2;
            MergeSort(nums, l, m);
            MergeSort(nums, m+1, r);
            Merge(nums, l, m, r);
        }
    }

    void Merge(vector<int>& nums, int l, int m, int r)
    {
        int k=0;
        int i=l;
        int j=m+1;
        vector<int> tmp(r-l+1);

        while(i<=m && j<=r)
        {
            if(nums[i]<nums[j])
            {
                tmp[k]=nums[i];
                i++;
            }
            else
            {
                tmp[k]=nums[j];
                j++;
            }
            k++;
        }

        if(i>m)
        {
            while(j<=r)
            {
                tmp[k]=nums[j];
                j++;
                k++;
            }
        }
        else
        {
            while(i<=m)
            {
                tmp[k]=nums[i];
                i++;
                k++;
            }
        }

        for(int x=l;x<=r;x++)
            nums[x]=tmp[x-l];
    }
};