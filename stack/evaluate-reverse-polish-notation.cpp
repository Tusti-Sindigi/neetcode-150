#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> s;

        for(string ch: tokens)
        {
            if(ch=="+")
            {
                int y=s.top();
                s.pop();
                int x=s.top();
                s.pop();
                s.push(x+y);
            }
            else if(ch=="-")
            {
                int y=s.top();
                s.pop();
                int x=s.top();
                s.pop();
                s.push(x-y);
            }
            else if(ch=="*")
            {
                int y=s.top();
                s.pop();
                int x=s.top();
                s.pop();
                s.push(x*y);
            }
            else if(ch=="/")
            {
                int y=s.top();
                s.pop();
                int x=s.top();
                s.pop();
                s.push(x/y);
            }
            else
                s.push(stoi(ch));
        }
        return s.top();
    }
};