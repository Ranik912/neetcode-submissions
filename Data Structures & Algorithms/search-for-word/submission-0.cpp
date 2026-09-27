class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfs(vector<vector<char>>& grid, string& word, int r, int c, int index){
        if(index == word.size()){
            return true;
        }
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != word[index]){
            return false;
        }
        grid[r][c] = '#';

        for(int i = 0; i < 4; i++){
            if(dfs(grid, word, r + dir[i][0], c + dir[i][1], index + 1)){
                grid[r][c] = word[index];
                return true;
            }
        }

        grid[r][c] = word[index];
        return false;
    }
    bool exist(vector<vector<char>>& grid, string word) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(dfs(grid, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};
