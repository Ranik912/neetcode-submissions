class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intr, vector<int>& newIntr) {
        vector<vector<int>> ans;
        int i = 0;
        int n = intr.size();
        while(i < n){
            if(intr[i][1] < newIntr[0]){
                ans.push_back(intr[i]);
            }else if(intr[i][0] > newIntr[1]){
                break;
            }
            else{
                newIntr[0] = min(newIntr[0], intr[i][0]);
                newIntr[1] = max(newIntr[1], intr[i][1]);
            }
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
