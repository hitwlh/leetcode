class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = 0;
        for(int i = 0; i < nums.size() / 2; i++) ret += nums[i<<1];
        return ret;
    }
};