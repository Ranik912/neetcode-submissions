class Solution {
public:
    void generate(vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums, vector<bool>& used){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;

            if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            curr.push_back(nums[i]);
            used[i] = true;
            generate(curr, ans, nums, used);
            curr.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<bool> used(n, false);
        vector<int> curr;
        generate(curr, ans, nums, used);
        return ans;

    }
};