class Solution {
public:
    int dir[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    void dfs(vector<vector<char>>& board, int r, int c) {
        board[r][c] = '#';

        for (int i = 0; i < 4; i++) {
            int dr = r + dir[i][0];
            int dc = c + dir[i][1];

            if (dr >= 0 && dc >= 0 &&
                dr < board.size() &&
                dc < board[0].size() &&
                board[dr][dc] == 'O') {

                dfs(board, dr, dc);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();

        // Left and right boundaries
        for (int i = 0; i < r; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);

            if (board[i][c - 1] == 'O')
                dfs(board, i, c - 1);
        }

        // Top and bottom boundaries
        for (int j = 0; j < c; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);

            if (board[r - 1][j] == 'O')
                dfs(board, r - 1, j);
        }

        // Convert surrounded O's and restore safe O's
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};