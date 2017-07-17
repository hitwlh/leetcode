class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= target; i++){
            for(auto j: nums)
                if(i >= j) dp[i] += dp[i-j];
                else break;
        }
        return dp[target];
    }
};