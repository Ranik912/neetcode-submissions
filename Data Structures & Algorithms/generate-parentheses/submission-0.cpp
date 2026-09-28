class Solution {
public:
    void generate(string& curr, vector<string>& ans, int n, int open, int close){
        if(curr.size() == 2 * n){
            ans.push_back(curr);
            return;
        }

        if(open < n){
            curr.push_back('(');
            generate(curr, ans, n, open + 1, close);
            curr.pop_back();
        }

        if(close < open){
            curr.push_back(')');
            generate(curr, ans, n, open, close + 1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr;
        vector<string> ans;
        generate(curr, ans, n ,0 , 0);
        return ans;
    }
};
