class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intr) {
        int n = intr.size();
        sort(intr.begin(), intr.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        for(int i = 0; i < n - 1; i++){
            auto curr = intr[i + 1];
            auto last = intr[i];
            if (curr.start < last.end) return false;
        }
        return true;
    }
};
