class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> count(26, 0);
        for(auto ch : s){
            count[ch - 'a']++;
        }
        int maxF = 0;
        int maxIdx;
        for(int i = 0; i < 26; i++){
            if(count[i] > maxF){
                maxF = count[i];
                maxIdx = i;
            }
        }
        if(maxF > (n + 1) / 2) return "";
        char maxCh = 'a' + maxIdx;
        string res = s;
        int idx = 0;
        while(count[maxIdx] > 0){
            res[idx] = maxCh;
            idx += 2;
            count[maxIdx]--;
        }
        for(int i = 0; i < 26; i++){
            while(count[i] > 0){
                if(idx >= n){
                    idx = 1;
                }
                res[idx] = 'a' + i;
                idx += 2;
                count[i]--;
            }
        }
        return res;
    }
};