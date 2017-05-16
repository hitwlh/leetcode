class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> sum(nums.size(), 0);
        sum[0] = nums[0];
        for(int i = 1; i < n; i++)
            sum[i] = nums[i] + sum[i-1];
        int R = sum[n-1], L = INT_MIN;
        for(auto i: nums) L = max(L, i);
        while(L < R){
            int mid = L + (R - L) / 2;
            int use = 0, sums = nums[0];
            for(int i = 1; i < n; i++){
                if(nums[i] + sums <= mid)
                    sums += nums[i];
                else{
                    use ++;
                    sums = nums[i];
                }
            }
            use++;
            if(use > m) L = mid + 1;
            else R = mid;
        }
        return L;
    }
};