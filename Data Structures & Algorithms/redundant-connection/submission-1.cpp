class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        for(auto n : adj[node]){
            if(!vis[n]){
                if(dfs(n, node, adj, vis) == true) return true;
            }
            else if(n != parent) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<int> vis(n, 0);
            if(dfs(u, v, adj, vis) == true) return {u, v};
        }
        return {};
    }
};
