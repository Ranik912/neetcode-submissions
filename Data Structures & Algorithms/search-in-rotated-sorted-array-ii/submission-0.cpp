class Solution {
public:
    int binarySearch(int l , int r, vector<int>& nums, int target){
        int idx = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target){
                idx = mid;
                break;
            }else if(nums[mid] > target) r = mid - 1;
            else l = mid + 1;  
        }
        return idx;
    }
    int findPivot(vector<int>& nums, int n){
        int l = 0;
        int r = n - 1;
        while(l < r){
            while(l < r && nums[l] == nums[l + 1]){
                l++;
            }
            while(l < r && nums[r] == nums[r - 1]){
                r--;
            }
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        return r;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums, n);
        int ans = binarySearch(0, pivot - 1, nums, target);
        if(ans != -1) return true;
        int ans_ = binarySearch(pivot, n - 1, nums, target);
        return ans_ == -1 ? false : true;
    }
};