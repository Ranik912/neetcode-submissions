class Solution {
public:
    void generate(vector<int>& nums, vector<bool>& used, vector<int>& curr, vector<vector<int>>& ans){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;

            curr.push_back(nums[i]);
            used[i] = true;

            generate(nums, used, curr, ans);
            curr.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(n, false);
        generate(nums, used, curr, ans);
        return ans;
        
    }
};
