#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int l=1;
        int r=*max_element(piles.begin(), piles.end());
        int k=0;

        while(l<=r)
        {
            int m=(l+r)/2;
            long time=0;
            
            for(int p: piles)
                time+=ceil((double)p/m);

            if(time<=h)
            {
                k=m;
                r=m-1;
            }
            else
                l=m+1;
        }
        return k;
    }
};