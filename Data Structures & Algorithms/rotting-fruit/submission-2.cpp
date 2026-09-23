class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> qu;
        int fresh = 0;
        int time = 0;
        for(int p = 0; p < n; p++){
            for(int q = 0; q < m; q++){
                if(grid[p][q] == 1) fresh++;
                else if(grid[p][q] == 2) qu.push({{p,q}, 0});
            }
        }
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        while(!qu.empty()){
            auto curr = qu.front();
            qu.pop();
            int r = curr.first.first;
            int c = curr.first.second;
            int t = curr.second;

            time = max(time, t);

            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;
                    fresh--;
                    qu.push({{nr, nc}, t+1});
                }
            }
        }
        return (fresh > 0)? -1 : time;
    }
};
