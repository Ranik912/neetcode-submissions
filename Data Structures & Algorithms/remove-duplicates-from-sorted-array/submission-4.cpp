class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set <int> hash;
        for(int i = 0; i < nums.size(); i++){
            hash.insert(nums[i]);
        }
        int i = 0;
        for(auto element : hash){
            nums[i] = element;
            i++;
        }
        return i;
    }
};