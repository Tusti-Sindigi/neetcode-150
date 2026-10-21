#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        vector<int> n(nums.size(), 0);
        int duplicate;

        for(int i=0;i<nums.size();i++)
        {
            if(n[nums[i]]==0)
                n[nums[i]]++;
            else
            {
                duplicate=nums[i];
                break;
            }
        }
        return duplicate;
    }
};