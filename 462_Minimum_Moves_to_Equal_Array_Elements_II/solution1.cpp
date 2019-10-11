class Solution {
public:
    int minMoves2(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        int mid = nums[nums.size()/2], ret = 0;
        for(int i = 0; i < nums.size(); i++) ret += fabs(nums[i] - mid);
        return ret;
    }
};