#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    
    unordered_map<string, vector<pair<int, string>>> m;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) 
    {
        m[key].push_back({timestamp, value});   //or m[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) 
    {
        auto& tv=m[key];   // pls use & with auto to create a reference else tv takes a deep copy of m[key] and eveytime u call get the copy is created and hence time complexity increases dramatically for copying which is almost equal to O(N*L) where N is the no.of elements in m[key] and L is the string length
        int l=0, r=tv.size()-1;
        string res="";

        while(l<=r)
        {
            int mid=(l+r)/2;

            if(tv[mid].first<=timestamp)
            {
                res=tv[mid].second;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */