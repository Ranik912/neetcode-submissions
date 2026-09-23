class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> ans(col, vector<int>(row));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                ans[j][i] = matrix[i][j];
            }
        }
        for(int i = 0; i < col; i++){
            reverse(ans[i].begin(), ans[i].end());
        }
        matrix = ans;
    }
};
