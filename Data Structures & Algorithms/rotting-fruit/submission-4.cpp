class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int fresh = 0;
        queue<pair<int, int>> q;
        int r = grid.size();
        int c = grid[0].size();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i, j});
            }
        }
        while(!q.empty() && fresh > 0){
            int n = q.size();
            for(int i = 0; i < n; i++){
                auto curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                for(int p = 0; p < 4; p++){
                    int dx = x + dir[p][0];
                    int dy = y + dir[p][1];
                    if(dx < 0 || dy < 0 || dx >= grid.size() || dy >= grid[0].size() || grid[dx][dy] != 1) continue;
                    grid[dx][dy] = 2;
                    fresh--;
                    q.push({dx, dy});
                }
            }
            time++;
        }
        return fresh > 0 ? -1:time;
    }
};
