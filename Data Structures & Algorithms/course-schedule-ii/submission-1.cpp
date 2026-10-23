class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        vector<int> ans;
        for(auto e : prereq){
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            auto curr = q.front();
             ans.push_back(curr);
            q.pop();
            for(auto n : adj[curr]){
                indegree[n]--;
                if(indegree[n] == 0) q.push(n);
            }
        }
        return ans.size() == numCourses ? ans : vector<int>{};
    }
};
