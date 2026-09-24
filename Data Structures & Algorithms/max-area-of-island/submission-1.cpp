class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || c < 0 || r >= grid.size() || c >=grid[0].size() || grid[r][c] == 0){
            return 0;
        }
        grid[r][c] = 0;
        int area = 1;
        for(int i = 0; i < 4; i++){
            area += dfs(grid, r + directions[i][0], c + directions[i][1]);
        }
        return area;
    } 
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int area = dfs(grid, i, j);
                ans = max(ans, area);
            }
        }
        return ans;
    }
};
