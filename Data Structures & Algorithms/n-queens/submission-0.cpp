class Solution {
public:

    bool isSafe(vector<string>& grid, int row, int col, int n) {

        // Check column
        for(int i = 0; i < row; i++) {
            if(grid[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for(int r = row - 1, c = col - 1;
            r >= 0 && c >= 0;
            r--, c--) {

            if(grid[r][c] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for(int r = row - 1, c = col + 1;
            r >= 0 && c < n;
            r--, c++) {

            if(grid[r][c] == 'Q')
                return false;
        }

        return true;
    }


    void generate(vector<string>& grid,
                  vector<vector<string>>& ans,
                  int n,
                  int row) {

        // All rows completed
        if(row == n) {
            ans.push_back(grid);
            return;
        }

        // Try every column
        for(int col = 0; col < n; col++) {

            if(isSafe(grid, row, col, n)) {

                // Choose
                grid[row][col] = 'Q';

                // Explore
                generate(grid, ans, n, row + 1);

                // Undo
                grid[row][col] = '.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> grid(n, string(n, '.'));

        generate(grid, ans, n, 0);

        return ans;
    }
};