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
        auto curr=m[key].upper_bound(timestamp);
        return curr==m[key].begin() ? "" : prev(curr)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */