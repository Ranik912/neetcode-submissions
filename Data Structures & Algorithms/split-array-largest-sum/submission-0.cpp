class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int largest){
        int subarray = 1;
        int curSum = 0;
        for(auto n : nums){
            curSum += n;
            if(curSum > largest){
                subarray++;
                if(subarray > k) return false;
                curSum = n;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end()); 
        int r = accumulate(nums.begin(), nums.end(), 0);
        int res = r;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(canSplit(nums, k, mid)){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return res;
    }
};