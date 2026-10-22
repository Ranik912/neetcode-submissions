class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> cn;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) cn.push({i, j});
            }
        }
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!cn.empty()){
            int r = cn.front().first;
            int c = cn.front().second;
            cn.pop();

            for(int i = 0; i < 4; i++){
                int row = r + dir[i][0];
                int col = c + dir[i][1];

                if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != INT_MAX) continue;
                grid[row][col] = grid[r][c] + 1;
                cn.push({row, col});
            }
        }
    }
};
