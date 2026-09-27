class Solution {
public:
    void generate(vector<int>& nums, int i, int xorr, vector<int>& xor_arr){
        if(i == nums.size()){
            xor_arr.push_back(xorr);
            return; 
        }

        generate(nums, i + 1, xorr^nums[i], xor_arr);
        generate(nums, i + 1, xorr, xor_arr);
    }
    int subsetXORSum(vector<int>& nums) {
        int xorr = 0;
        vector<int> xor_arr;
        generate(nums, 0, xorr, xor_arr);
        return accumulate(xor_arr.begin(), xor_arr.end(), 0);
    }
};