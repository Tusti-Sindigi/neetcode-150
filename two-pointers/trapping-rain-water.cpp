#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) 
    {
        int l=0, r=height.size()-1;
        int lh=0, rh=0;
        int trap=0;

        while(l<r)
        {
            lh=max(lh, height[l]);
            rh=max(rh, height[r]);

            if(lh<=rh)
            {
                trap+=lh-height[l];
                l++;
            }
            else
            {
                trap+=rh-height[r];
                r--;
            }
        }
        return trap;
    }
};