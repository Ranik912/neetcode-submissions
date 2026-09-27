class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int x = 0;

        for (int num : nums)
            x |= num;

        return x * (1 << (nums.size() - 1));
    }
};