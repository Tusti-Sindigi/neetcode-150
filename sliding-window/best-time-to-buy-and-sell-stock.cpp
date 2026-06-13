#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int p=0;
        int l=0, r=1;

        while(l<r && r<prices.size())
        {
            int ep=prices[r]-prices[l];
            if(ep>0)
            {
                if(ep>p)
                    p=ep;

                r++;
            }
            else
            {
                l++;
                if(l==r)
                    r=l+1;
            }
        }
        return p;
    }
};