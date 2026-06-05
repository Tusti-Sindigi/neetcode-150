
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int prod=1;
        int zero_exists=0;
        int non_zero_exists=0;

        for(int n:nums)
        {
            if(n==0)
            {
                zero_exists+=1;
                continue;
            }
            prod*=n;
            non_zero_exists=1;
        }

        vector<int> res;

        if(zero_exists)
        {
            if(non_zero_exists==1 && zero_exists==1)
            {
                for(int n:nums)
                {
                    if(n==0)
                    {   
                        res.push_back(prod);
                        continue;
                    }
                    res.push_back(0);
                }
            }
            else
            {
                for(int i=0;i<nums.size();i++)
                    res.push_back(0);
            }
        }
        else
        {
            for(int n:nums)
            {
                res.push_back(prod/n);
            }
        }
        return res;
    }
};