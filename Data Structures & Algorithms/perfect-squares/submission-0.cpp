class Solution {
public:
    int numSquares(int n) {
        int x = sqrt(n);
        vector<int> values;
        for(int i = 1; i <= x; i++){
            values.push_back(i*i);
        }
        vector<int> dp (n + 1, n + 1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < values.size(); j++){
                if(values[j] <= i){
                    dp[i] = min(dp[i], 1 + dp[i - values[j]]);
                }
            }
        }
        return dp[n];
    }
};