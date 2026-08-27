class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int ans = INT_MIN;
        while(l < r){
            int length = min(heights[l], heights[r]);
            int width = r - l;
            int area = length * width;
            ans = max(ans, area);
            if(heights[l] < heights[r]) l++;
            else r--;
        }return ans;
    }
};
