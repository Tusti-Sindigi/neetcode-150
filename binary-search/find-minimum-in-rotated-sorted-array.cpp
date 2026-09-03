#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int l=0, r=nums.size()-1;

        while(r-l>=1)
        {
            int m=(l+r)/2;
            
            if(r-l==1)
                if(nums[l]<nums[r])
                    return nums[l];
                else
                    return nums[r];
            if((nums[m]<nums[m+1] && nums[m]<nums[m-1]))
                return nums[m];
            if(nums[m-1]<nums[r])
                r=m;
            else
                l=m;
        }
        return nums[l];
    }
};