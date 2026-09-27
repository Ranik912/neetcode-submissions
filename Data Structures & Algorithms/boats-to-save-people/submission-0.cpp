class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(), p.end());
        int count = 0;
        int l = 0;
        int r = p.size() - 1;
        while(l <= r){
            if(p[l] + p[r] <= limit){
                count ++;
                l++;
                r--;
            }
            else{
                count++;
                r--;
            }
        }
        return count;
    }
};