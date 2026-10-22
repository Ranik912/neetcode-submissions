class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(int r, int c, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0) return 0 ;
        grid[r][c] = 0;
        int area = 1;
        for(int i = 0; i < 4; i++){
            area += dfs(r + dir[i][0], c + dir[i][1], grid);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxA = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int ans = dfs(i, j, grid);
                    maxA  = max(maxA, ans);
                }
            }
        }
        return maxA;
    }
};
