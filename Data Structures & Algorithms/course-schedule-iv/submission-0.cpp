class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
       vector<vector<int>> adj(numCourses);
       vector<int> indegree(numCourses);
       unordered_map<int, unordered_set<int>> mp;
       for(auto e : prereq){
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        indegree[v]++;
       }
       queue<int> q;
       for(int i = 0; i < numCourses; i++){
        if(indegree[i] == 0) q.push(i);
       }
       while(!q.empty()){
        auto curr = q.front();
        q.pop();
        for(auto n : adj[curr]){
            mp[n].insert(curr);
            for(auto preq : mp[curr]){
                mp[n].insert(preq);
            }
            indegree[n]--;
            if(indegree[n] == 0) q.push(n);
        }
        }
        int s = queries.size();
        vector<bool> res(s, false);
        for(int i = 0; i < s; i++){
            int src = queries[i][0];
            int des = queries[i][1];
            bool rechable = mp[des].contains(src);
            res[i] = rechable;
       }
       return res;
    }
};