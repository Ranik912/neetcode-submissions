class Solution {
public:
    bool isCycle(int node, int parent, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        for(auto n : adj[node]){
            if(!vis[n]){
                if(isCycle(n, node, adj, vis) == true) return true;
            }
            else if(n != parent) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count++;
                if(isCycle(i, -1, adj, vis)) return false;
            }
        }
        return count == 1;
    }
};
