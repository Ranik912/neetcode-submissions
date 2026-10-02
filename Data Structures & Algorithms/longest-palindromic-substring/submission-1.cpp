class Solution {
public:
    string longestPalindrome(string s) {
        int len = 0; int index = 0;
        for(int i = 0; i < s.size(); i++){
            int l = i;
            int r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(r - l + 1>len){
                    len = r - l + 1;
                    index = l;
                }
                l--;
                r++;
            }
        }
        for(int i = 0; i < s.size(); i++){
            int l = i; 
            int r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(r - l + 1 > len){
                    len = r - l + 1;
                    index = l;
                } 
                l--;
                r++;
            }
        }
        return s.substr(index, len);
    }
};
