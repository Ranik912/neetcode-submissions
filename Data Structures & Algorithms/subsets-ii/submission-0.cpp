class Solution {
public:
    void generate(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int>& curr){
        ans.push_back(curr);

        for(int j = i; j < nums.size(); j++){
            if(j > i && nums[j] == nums[j - 1]) continue;

            curr.push_back(nums[j]);
            generate(nums, j + 1, ans, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> ans;
        generate(nums, 0, ans, curr);
        return ans; 
    }
};
