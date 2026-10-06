//logic is that the we need only the first half (+1 conditional) of the merged array as the median always lies in there

#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int l1=nums1.size(), l2=nums2.size(), i=0, j=0, m1=0, m2=0;

        for(int k=0; k<(l1+l2)/2+1;k++)
        {
            m2=m1;  // median 2 always assumes the previous value of median 1

            if(i<l1 && j<l2)
            {
                if(nums1[i]<nums2[j])
                {
                    m1=nums1[i];
                    i++;
                }
                else
                {
                    m1=nums2[j];
                    j++;
                }
            }
            else if(i<l1)
            {
                m1=nums1[i];
                i++;
            }
            else
            {
                m1=nums2[j];
                j++;
            }
        }

        if((l1+l2)%2==1)
            return m1;
        else
            return (double)(m1+m2)/2;
    }
};