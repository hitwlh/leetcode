class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_begin = 0, i = 0;
        while(i < nums.size()){
            if(nums[i] == 0) i++;
            else swap(nums[i++], nums[zero_begin++]);
        }
    }
};