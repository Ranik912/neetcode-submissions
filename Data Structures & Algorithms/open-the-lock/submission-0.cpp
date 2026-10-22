class Solution {
public:
    void fillNei(string curr, unordered_set<string>& st, queue<string>& q){
        for(int i = 0; i < 4; i++){
            char ch = curr[i];
            int up = ch == '9' ? '0' : ch + 1;
            int dn = ch == '0' ? '9' : ch - 1;
            curr[i] = up;
            if(st.find(curr) == st.end()){
                st.insert(curr);
                q.push(curr);
            }
            curr[i] = dn;
            if(st.find(curr) == st.end()){
                st.insert(curr);
                q.push(curr);
            }
            curr[i] = ch;
        }
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(), deadends.end());

        string start = "0000";
        if(st.find(start) != st.end()) return -1;

        queue<string> q;
        q.push(start);
        int level = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto curr = q.front();
                q.pop();
                if(curr == target) return level;
                fillNei(curr, st, q);
            }
            level++;
        }
        return -1;
    }
};