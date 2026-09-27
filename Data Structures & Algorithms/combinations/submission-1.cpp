class Solution {
public:
    void generate(vector<int>& c, int s, int k, vector<int>& curr, vector<vector<int>>& ans){
        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }

        for(int i = s; i < c.size(); i++){
            curr.push_back(c[i]);
            generate(c, i + 1, k, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> c;
        for(int i = 1; i <= n; i++){
            c.push_back(i);
        }
        vector<int> curr;
        vector<vector<int>> ans;
        generate(c, 0, k, curr, ans);
        return ans;
    }
};