class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int time = 0;
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1) fresh++;
            }
        }
        while(!q.empty() && fresh > 0){
            int s = q.size();
            for(int i = 0; i < s; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++){
                    int row = r + dir[i][0];
                    int col = c + dir[i][1];
                    if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != 1) continue;
                grid[row][col] = 2;
                fresh--;
                q.push({row, col});
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
