class Solution {
public:
    bool isPali(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void dfs(string& s, int i, vector<string>& part,
             vector<vector<string>>& ans) {

        if (i == s.size()) {
            ans.push_back(part);
            return;
        }

        for (int j = i; j < s.size(); j++) {

            if (isPali(s, i, j)) {

                part.push_back(s.substr(i, j - i + 1));

                dfs(s, j + 1, part, ans);

                part.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;

        dfs(s, 0, part, ans);

        return ans;
    }
};