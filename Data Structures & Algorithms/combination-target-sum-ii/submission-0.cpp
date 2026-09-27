class Solution {
public: 
    void generate(vector<int>& candidates, int target, int i, vector<int>& curr, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        for(int j = i; j < candidates.size(); j++){
            if(j > i && candidates[j] == candidates[j - 1]) continue;
            if(candidates[j] > target) break;

            curr.push_back(candidates[j]);
            generate(candidates, target - candidates[j], j + 1, curr, ans);
            curr.pop_back();
        } 
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        vector<vector<int>> ans;
        generate(candidates, target, 0, curr, ans);
        return ans;
    }
};
