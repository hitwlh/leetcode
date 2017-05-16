class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sum = nums;
        for(int i = 1; i < sum.size(); i++)
            sum[i] = max(sum[i-1] + sum[i], sum[i]);
        int MAX = INT_MIN;
        for(auto i: sum) MAX = max(i, MAX);
        return MAX;
    }
};