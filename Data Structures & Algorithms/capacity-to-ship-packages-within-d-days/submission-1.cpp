class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        while(l <= r){
            int mid = l + (r - l) / 2;
            int r_days = 1;
            int curr_weight = 0;
            for(auto w : weights){
                if(curr_weight + w > mid){
                    r_days++;
                    curr_weight = 0;
                }
                curr_weight += w;
            }
            if(r_days <= days) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};