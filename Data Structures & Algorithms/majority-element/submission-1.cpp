class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for(auto value : nums){
            if(count == 0){
                candidate = value;
                count++;
            }
            else if(value == candidate) count++;
            else count--;
        }
        return candidate;
    }
};