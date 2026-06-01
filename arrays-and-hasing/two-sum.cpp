#include<vector>
#include<unordered_map>
using std::vector;
using std::unordered_map;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {   
       unordered_map <int, int> map;
        vector <int> res;
        for(int i=0;i<nums.size();i++)
        {
            int leftout=target-nums[i];

            if(map.find(leftout)!=map.end())
            {
                res.push_back(map[leftout]);
                res.push_back(i);
                break;
            }
            map[nums[i]]=i;
        }
        return res;
    }
};