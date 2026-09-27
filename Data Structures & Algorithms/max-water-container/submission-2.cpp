class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0; 
        int r = heights.size() - 1;
        int ans = INT_MIN;
        while( l < r){
            int width = r - l;
            int length = min(heights[l], heights[r]);
            int area = width * length;
            ans = max(area, ans);
            if(heights[l] < heights[r]) l++;
            else r--;
        }
        return ans;
    }
};
