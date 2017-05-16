class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> sum = nums;
        for(int i = 1; i < sum.size(); i++)
            sum[i] += sum[i-1];
        int end = 0, ret = INT_MAX;
        for(int start = 0; start < nums.size() && end < nums.size(); start++){
            while(end < nums.size() && sum[end] - sum[start] + nums[start] < s) end++;
            if(end < nums.size() || sum[end-1] - sum[start] + nums[start] >= s) ret = min(ret, end - start + 1);
        }
        return (ret == INT_MAX) ? 0 : ret;
    }
};