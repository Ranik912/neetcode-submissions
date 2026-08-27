class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> st;
        for(auto n : nums){
            st.insert(n);
        }
        for(int i = 0; i < nums.size(); i++){
            if(st.find(nums[i] - 1) == st.end()){
                int current = nums[i];
                int count = 1;
                while(st.find(current + 1) != st.end()){
                    current++;
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
