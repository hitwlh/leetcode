class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int non_zero_index = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == 0);
            else nums[non_zero_index++] = nums[i];
        for(int i = non_zero_index; i < nums.size(); i++)
            nums[i] = 0;
    }
};