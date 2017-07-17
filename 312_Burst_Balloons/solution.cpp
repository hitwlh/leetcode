class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int length = 1; length < n-1; length++)
            for(int start = 1, end = start + length - 1; end < n-1; start++, end++)
                for(int point = start; point <= end; point++)
                    dp[start][end] = max(dp[start][end], dp[start][point-1] + dp[point+1][end] + nums[point] * nums[start-1] * nums[end+1]);
        return dp[1][n-2];
    }
};