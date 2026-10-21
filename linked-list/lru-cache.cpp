// Time complexity: O(n) for each put() and get() operation
// Space complexity: O(n)

#include <vector>
using namespace std;

class LRUCache 
{
private:
    vector<pair<int, int>> cache;
    int capacity;

public:
    LRUCache(int capacity) 
    {
        this->capacity=capacity;
    }
    
    int get(int key) 
    {
        for(int i=0;i<cache.size();i++)
        {
            if(cache[i].first==key)
            {
                pair<int, int> temp=cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp);
                return temp.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        for(int i=0;i<cache.size();i++)
        {
            if(cache[i].first==key)
            {
                cache.erase(cache.begin()+i);
                break;
            }
        }

        if(cache.size()==capacity)
            cache.erase(cache.begin());

        cache.push_back({key, value});
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */