class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> need;
        for(int i = 0; i < nums.size(); i++){
            int needed = target - nums[i];

            if(need.find(needed) != need.end()){
                return {need[needed], i};
            }
            need[nums[i]] = i;
        }
        return {};
    }
};
