class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() <= 1) return false;
        int n = nums.size();
        vector<int> sum(n, 0);
        sum[0] = nums[0];
        for(int i = 1; i < n; i++)
            sum[i] = sum[i-1] + nums[i];
        for(int i = 2; i <= n; i++){//i是subarray长度
            for(int j = 0; j <= n-i; j++){//j是subarray起点, j + i - 1是subarray终点
                if(k == 0){
                    if(sum[j + i - 1] - sum[j] + nums[j] == 0) return true;
                }
                else if((sum[j + i - 1] - sum[j] + nums[j]) % k == 0) return true;
            }
        }
        return false;
    }
};