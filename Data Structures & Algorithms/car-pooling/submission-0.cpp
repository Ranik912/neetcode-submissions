class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> events;
        for(auto t : trips){
            int count = t[0];
            int start = t[1];
            int end = t[2];

            events[start] += count;
            events[end] -= count;
        }
        int cap = 0;
        for(auto e : events){
            cap += e.second;
            if(cap > capacity) return false;
        }
        return true;
    }
};