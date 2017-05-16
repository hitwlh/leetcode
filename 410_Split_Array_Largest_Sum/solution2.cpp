class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<long> sum(nums.size(), 0);
        int n = nums.size();
        sum[0] = nums[0];
        for(int i = 1; i < n; i++)
            sum[i] = nums[i] + sum[i-1];
        vector<vector<long>> dp(m + 1, vector<long>(n+1, INT_MAX));
        for(int i = 1; i <= m; i++){//i==2
            for(int j = 1; j <= n; j++){//j==2
                long MAX = INT_MIN;
                for(int k = 0; k < j; k++){//k==0, 1 MAX == 9, 
                    if(k == 0) MAX = sum[j-1] - sum[k] + nums[k];
                    else MAX = max(dp[i-1][k], sum[j-1] - sum[k] + nums[k]);
                    dp[i][j] = min(MAX, dp[i][j]);
                }
            }
        }
        return dp[m][n];
    }
};