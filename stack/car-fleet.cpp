//using stacks

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        vector<pair<int, int>> cars;
        vector<double> s;

        for(int i=0;i<speed.size();i++)
            cars.push_back({position[i], speed[i]});

        sort(cars.rbegin(), cars.rend());

        for(auto c: cars)
        {
            s.push_back((double)(target-c.first)/c.second);

            if(s.size()>1 && s.back()<=s[s.size()-2])
                s.pop_back();
        }
        return s.size();
    }
};
