class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intr, vector<int>& newIntr) {
        vector<vector<int>> ans;
        int i = 0;
        int n = intr.size();
        while(i < n && intr[i][1] < newIntr[0]){
            ans.push_back(intr[i]);
            i++;
        }
        while(i < n && intr[i][0] <= newIntr[1]){
            newIntr[0] = min(intr[i][0], newIntr[0]);
            newIntr[1] = max(intr[i][1], newIntr[1]);
            i++;
        }
        ans.push_back(newIntr);
        while(i < n){
            ans.push_back(intr[i]);
            i++;
        }
        return ans;
    }
};
