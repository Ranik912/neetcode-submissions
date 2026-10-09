class Solution {
public:
    int f(int l, int r, vector<int>& piles, vector<vector<int>>& dp){
        if(l == r) return piles[l];
        if(dp[l][r] != -1) return dp[l][r];

        int lp = piles[l] - f(l + 1, r, piles, dp);
        int rp = piles[r] - f(l, r - 1, piles, dp);

        return dp[l][r] = max(lp, rp);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return f(0, n - 1, piles, dp) > 0;
    }
};