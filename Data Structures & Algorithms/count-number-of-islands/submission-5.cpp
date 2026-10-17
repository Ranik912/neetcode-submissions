class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0,1}, {0, -1}};
    void dfs(int r, int c, vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0') return;
        grid[r][c] = '0';

        for(int i = 0; i < 4; i++){
            dfs(r + dir[i][0], c + dir[i][1], grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
};
