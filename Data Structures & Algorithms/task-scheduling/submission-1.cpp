class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(auto ch : tasks){
            count[ch - 'A']++;
        }
        sort(count.begin(), count.end());
        int maxF = count[25];
        int holes = maxF - 1;
        int slots = holes * n;

        for(int i = 24; i >= 0; i--){
            slots -= min(count[i], holes);
        }
        return tasks.size() + max(0, slots);
    }
};
