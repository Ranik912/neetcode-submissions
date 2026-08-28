class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> box(9);

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;

                char num = board[i][j];
                int index = (i / 3) * 3 + (j / 3);
                if(row[i].count(num) || col[j].count(num) || box[index].count(num))
                    return false;

                else{
                    row[i].insert(num);
                    col[j].insert(num);
                    box[index].insert(num);
                }
            }
        }
        return true;
    }
};
