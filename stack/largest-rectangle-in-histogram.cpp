#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        vector<int> l(heights.size(), 0);
        vector<int> r(heights.size(), heights.size()-1);
        stack<int> stack;

        int area=0;

        for(int i=0;i<heights.size();i++)
        {
            while(!stack.empty() && heights[stack.top()]>=heights[i])
                stack.pop();

            if(!stack.empty())
                l[i]=stack.top()+1;

            stack.push(i);
        }

        while(!stack.empty())
            stack.pop();

        for(int i=heights.size()-1;i>=0;i--)
        {
            while(!stack.empty() && heights[stack.top()]>=heights[i])
                stack.pop();

            if(!stack.empty())
                r[i]=stack.top()-1;

            stack.push(i);
        }

        for(int i=0;i<heights.size();i++)
            area=max(area, heights[i]*(r[i]-l[i]+1));

        return area;
    }
};