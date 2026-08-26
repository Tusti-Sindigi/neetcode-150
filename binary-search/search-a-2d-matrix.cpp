#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int rows=matrix.size(), columns=matrix[0].size();
        int i=0, j=rows*columns-1;

        while(i<=j)
        {
            int mid=(i+j)/2;
            int r=mid/columns, c=mid%columns;

            if(target==matrix[r][c])
                return true;
            else if(target<matrix[r][c])
                j=mid-1;
            else
                i=mid+1;
        }
        return false;
    }
};
