class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> incoming(n + 1, 0);
        vector<int> outgoing(n + 1, 0);
        for(auto t : trust){
            outgoing[t[0]]++;
            incoming[t[1]]++;
        }
        for(int i = 0; i < n + 1; i++){
            if(outgoing[i] == 0 && incoming[i] == n - 1) return i;
        }
        return -1;
    }
};