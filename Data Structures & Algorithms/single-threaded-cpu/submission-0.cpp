class Solution {
public:
    typedef pair<int, int> T;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<array<int, 3>> sortedTasks;
        for(int i = 0; i < n; i++){
            int startTime = tasks[i][0];
            int duration = tasks[i][1];
            sortedTasks.push_back({startTime, duration, i});
        }
        sort(sortedTasks.begin(), sortedTasks.end());
        vector<int> res;
        long long int currTime = 0;
        int idx = 0;
        priority_queue<T, vector<T>, greater<T>> pq;
        while(idx < n || !pq.empty()){
            if(pq.empty() && currTime < sortedTasks[idx][0]){
                currTime = sortedTasks[idx][0];
            }
            while(idx < n && sortedTasks[idx][0] <= currTime){
                pq.push({sortedTasks[idx][1], sortedTasks[idx][2]});
                idx++;
            }
            auto curr = pq.top();
            pq.pop();
            currTime += curr.first;
            res.push_back(curr.second);
        }
        return res;
    }
};