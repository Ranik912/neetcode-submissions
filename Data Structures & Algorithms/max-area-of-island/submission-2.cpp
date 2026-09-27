class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>>& grid, int r, int c){
        if( r < 0 || c < 0 ||r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0){
            return 0;
        }
        grid[r][c] = 0;
        int area = 1;
        for(int i = 0; i < 4; i++){
            area += dfs(grid, r + dir[i][0], c + dir[i][1]);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int r = grid.size();
        int c = grid[0].size();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 1){
                    int i_area = dfs(grid, i, j);
                    res = max(res, i_area);
                }
            }
        }
        return res;
    }
};
