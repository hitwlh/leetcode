class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int MAX = INT_MIN;
        long long sum = 0;
        for(auto i: nums) MAX = max(MAX, i), sum += i;
        long long L = MAX, R = sum;
        while(L <= R){
            long long sum = nums[0], mid = L+(R-L)/2, use = 1;
            for(int i = 1; i < nums.size(); i++){
                if(nums[i] + sum <= mid) sum += nums[i];
                else{
                    use++;
                    sum = nums[i];
                }
            }
            if(use <= m) R = mid - 1;
            else L = mid + 1;
        }
        return R+1;
    }
};