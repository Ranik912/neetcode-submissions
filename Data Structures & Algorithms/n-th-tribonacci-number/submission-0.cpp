class Solution {
public:
    int recursor(int n, vector<int>& memo){
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        if(memo[n] != -1) return memo[n];

        memo[n] = recursor(n - 1, memo) + recursor(n - 2, memo) +recursor(n - 3, memo);

        return memo[n];
    }
    int tribonacci(int n) {
        vector<int> memo(n + 1, -1);
        return recursor(n, memo);    
    }
};