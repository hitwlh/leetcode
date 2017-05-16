class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = S;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if(sum % 2 || sum < S) return 0;
        sum /= 2;
        vector<int> target(sum+1, 0);
        target[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];
            for(int j = sum; j >= n; j--)
                target[j] += target[j-n];
        }
        return target[sum];
    }
};