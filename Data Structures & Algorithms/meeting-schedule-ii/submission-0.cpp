class Solution {
public:
    int minMeetingRooms(vector<Interval>& intr) {
        map<int, int> events;
        for(int i = 0; i < intr.size(); i++){
            events[intr[i].start]++;
            events[intr[i].end]--;
        }
        int count = 0;
        int ans = 0;
        for(auto it : events){
            count += it.second;
            ans = max(ans, count);
        }
        return ans;
    }
};
