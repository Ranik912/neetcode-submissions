class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        if(t.size() == 0) return "";

        unordered_map<char, int> mp;
        for(auto ch : t){
            mp[ch]++;
        }
        int requiredCount = t.size();
        int i = 0; int j = 0;
        int startIdx = 0;
        int minWindow = INT_MAX;

        while(j < n){
            char ch = s[j];
            if(mp[ch] > 0) requiredCount--;
            mp[ch]--;

            while(requiredCount == 0){
                int currMaxW = j - i + 1;
                if(minWindow > currMaxW){
                    minWindow = currMaxW;
                    startIdx = i;
                }
                if(mp[s[i]] == 0) requiredCount++; 
                mp[s[i]]++;
                i++;
            }
            j++;
        }
        return minWindow == INT_MAX ? "" : s.substr(startIdx, minWindow);
    }
};
