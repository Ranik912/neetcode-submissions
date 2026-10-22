class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(int r,  int c, vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] != 'O') return;
        grid[r][c] = '#';
        for(int i = 0; i < 4; i++){
            dfs(r + dir[i][0], c + dir[i][1], grid);
        }
    }
    void solve(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 'O') dfs(i, 0, grid);
        }
        for(int i = 0; i < m; i++){
            if(grid[i][n - 1] == 'O') dfs(i, n - 1, grid);
        }
        for(int i = 0; i < n; i++){
            if(grid[0][i] == 'O') dfs(0, i, grid);
        }
        for(int i = 0; i < n; i++){
            if(grid[m - 1][i] == 'O') dfs(m - 1, i, grid);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'O') grid[i][j] = 'X';
                else if(grid[i][j] == '#') grid[i][j] = 'O';
            }
        }
    }
};
