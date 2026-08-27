class Solution {
public:

    bool palindrome(string& s, int l, int r){
        while(l < r){
            if(s[l]!= s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(i < j){
            if(s[i] != s[j])
                return (palindrome(s, i + 1, j) || palindrome(s, i, j - 1));
            i++;
            j--;
            
        }
        return true;
    }
};