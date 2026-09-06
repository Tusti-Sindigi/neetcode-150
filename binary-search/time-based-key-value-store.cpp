#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    
    unordered_map<string, map<int, string>> m;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) 
    {
        m[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) 
    {
        auto curr=m[key].upper_bound(timestamp); //say if there is only one element 10 as the timestamp for a particular key the, the upper_bund func stops at and point at strictly greater than 10, which in this case will be m[key].end() .........  10 ... end()
        return curr==m[key].begin() ? "" : prev(curr)->second; //since curr=map[key].end() which is not equal to map[key].begin() ... the ternary operator results in false and the prev element of curr is fetched... similarly if it was empty and no items existed in m[key], then curr whould be map[key].end() which is also map[key].begin() and hence the ternary operator would return true and hence ans would have been an empty string ""
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */