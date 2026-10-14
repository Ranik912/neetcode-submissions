class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;

        for(auto cn : points){
            int x = cn[0];
            int y = cn[1];

            int dist = x * x + y * y;
            pq.push({dist, {x, y}});
            if(pq.size() > k) pq.pop();
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            auto val = pq.top().second;
            pq.pop();
            ans.push_back({val.first, val.second});
        }
        return ans;
    }
};
