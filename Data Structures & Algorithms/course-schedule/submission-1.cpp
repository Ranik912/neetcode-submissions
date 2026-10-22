class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(int i = 0; i < prereq.size(); i++){
            int u = prereq[i][0];
            int v = prereq[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            count++;
            for(auto n : adj[curr]){
                indegree[n]--;
                if(indegree[n] == 0) q.push(n);
            }
        }
        return count == numCourses;
    }
};
