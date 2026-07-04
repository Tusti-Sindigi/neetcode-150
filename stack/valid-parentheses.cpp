#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) 
    {
        vector<char> stk;
        for(char ch: s)
        {
            if(ch=='(' || ch=='[' || ch=='{')
                stk.push_back(ch);

            if(stk.empty() && (ch==']' || ch==')' || ch=='}'))
                return false;

            if(ch==')')
                if(stk.back()=='(')
                    stk.pop_back();
                else
                    return false;

            if(ch==']')
                if(stk.back()=='[')
                    stk.pop_back();
                else
                    return false;

            if(ch=='}')
                if(stk.back()=='{')
                    stk.pop_back();
                else
                    return false;
        }
        return stk.empty()? true : false;
    }
};