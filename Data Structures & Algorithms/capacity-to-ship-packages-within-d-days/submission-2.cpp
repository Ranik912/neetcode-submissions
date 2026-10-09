class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
        int l = *max_element(w.begin(), w.end());
        int r = accumulate(w.begin(), w.end(), 0);
        while(l <= r){
            int count = 1;
            int mid = l + (r - l) / 2;
            int sum = 0;
            for(auto n : w){
                if(sum + n > mid){
                    count++;
                    sum = 0;
                }
                sum += n;
            }
            if(count <= days) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};