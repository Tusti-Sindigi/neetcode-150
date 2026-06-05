#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) 
    {
        string concat="";
        for(string s:strs)
            concat+=s+";";

        return concat;
    }

    vector<string> decode(string s) 
    {
        vector<string> str;
        string st;
        for(char c:s)
        {
            if(c==';')
            {
                str.push_back(st);
                st="";
                continue;
            }
            st+=c;
        }
        return str;
    }
};