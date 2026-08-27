class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        vector<int> hash_s1(26, 0);
        vector<int> hash_s2(26, 0);
        for(int i = 0; i < s1.size(); i++){
            hash_s1[s1[i] - 'a']++;
        }
        for(int r = 0; r < s2.size(); r++){
            hash_s2[s2[r] - 'a']++;
            if(r - l + 1 == s1.size()){
                if(hash_s1 == hash_s2) return true;
            hash_s2[s2[l] - 'a']--;
            l++;
            }
        }
        return false;
    }
};
