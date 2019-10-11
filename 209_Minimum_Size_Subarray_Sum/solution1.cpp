class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        sum = nums;
        for(int i = 1; i < sum.size(); i++)
            sum[i] += sum[i-1];
        int left = 1, right = nums.size(), mid;
        while(left > 0 && left < right){
            mid = left + (right - left) / 2;
            if(valid(s, nums, mid)) right = mid;
            else left = mid + 1;
        }
        return (valid(s, nums, left)) ? left : 0;
    }
private:
    vector<int> sum;
    bool valid(int s, vector<int>& nums, int k){
        if(k > nums.size()) return false;
        for(int i = k-1; i < nums.size(); i++){//[i-k+1, i]
            if(sum[i] - sum[i-k+1] + nums[i-k+1] >= s)
                return true;
        }
        return false;
    }
};