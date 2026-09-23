class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int coln = matrix[0].size();

        vector<vector<int>> ans(coln, vector<int> (row));
        for(int r = 0; r < row; r++){
            for(int c = 0; c < coln; c++){
                ans[c][r] = matrix[r][c];
            }
        }
        return ans;
    }
};