class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intr) {
        sort(intr.begin(), intr.end());
        int n = intr.size();
        auto last = intr[0];
        int i = 1;
        int count = 0;
        while(i < n){
            int cs = intr[i][0];
            int ce = intr[i][1];
            int le = last[1];
            if(le <= cs){
                last = intr[i];
                i++;
            }
            else if(ce > le){
                i++;
                count++;
            }
            else if(ce <= le){
                last = intr[i];
                i++;
                count++;
            }
        }
        return count;
    }
};
