class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans(t.size(), 0);
        stack<pair<int, int>> st;
        for(int i = 0; i < t.size(); i++){
            while(!st.empty() && st.top().first < t[i]){
                int prevIndex = st.top().second;
                st.pop();
                ans[prevIndex] = i - prevIndex;
            }
            st.push({t[i], i});
        }
        return ans;
    }
};
