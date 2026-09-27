class Solution {
public:
    void generate(vector<int>& nums, int i, int target, vector<int>& curr, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        for(int p = i; p < nums.size(); p++){
            if(nums[p] > target) break;
        
            curr.push_back(nums[p]);
            generate(nums, p, target - nums[p], curr, ans);

            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> ans;
        generate(nums, 0, target, curr, ans);
        return ans;
    }
};
