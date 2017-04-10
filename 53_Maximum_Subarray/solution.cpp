class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> use_big(nums.size(), 0);
        vector<int> sum(nums.size(), 0);
        use_big[0] = nums[0];
        for(int i=1; i<nums.size(); i++)
            use_big[i] = max(use_big[i-1] + nums[i], nums[i]);
        sum[0] = nums[0];
        for(int i=1; i<nums.size(); i++)
            sum[i] = max(use_big[i], sum[i-1]);
        return sum.back();
    }
};