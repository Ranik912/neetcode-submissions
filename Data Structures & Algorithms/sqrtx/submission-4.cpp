class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) return 1;
        if(x == 0) return 0;
        int low = 0;
        long long high = x/2;
        long long ans = 0;
        while(low <= high){
            long long mid = low + (high - low)/2;
            if(mid*mid <= x){
                ans = mid;
                low = mid + 1;
            }
            else if(mid*mid > x) high = mid - 1;
        }
        return ans;
    }
};