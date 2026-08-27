class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pr;
        for(int i = 0; i < speed.size(); i++){
            pr.push_back({position[i], speed[i]});
        }
        sort(pr.begin(), pr.end());

        int fleet = 0;
        double maxTime = 0;
        for(int i = pr.size() - 1; i >= 0; i--){
            double time = (double)(target - pr[i].first)/pr[i].second;

            if(time > maxTime){
                fleet++;
                maxTime = time;
            }
        }
        return fleet;
    }
};
