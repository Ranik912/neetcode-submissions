class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intr) {
        vector<vector<int>> ans;
        sort(intr.begin(), intr.end());
        int n = intr.size();
        for(int i = 0; i < n; i++){
            if(ans.empty() || (ans.back()[1] < intr[i][0])){
                ans.push_back(intr[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1], intr[i][1]);
            }
        }
        return ans;
    }
};
