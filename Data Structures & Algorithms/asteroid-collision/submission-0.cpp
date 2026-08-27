class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(auto nums : asteroids){
            if(nums >= 0) st.push(nums);
            else if(nums < 0){
                while(!st.empty() && st.top() > 0 && st.top() < -nums) st.pop();
                if(st.empty() || st.top() < 0) st.push(nums);
                else if(st.top() == -nums) st.pop();
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};