class Solution {
public:
    void generate(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        generate(nums, i + 1, curr, ans);

        curr.pop_back();
        generate(nums, i + 1, curr, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        generate(nums, 0, curr, ans);
        return ans;
    }
};
