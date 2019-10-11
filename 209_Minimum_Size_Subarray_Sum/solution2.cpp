class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0, sum = 0, ret = INT_MAX;
        while(true){
            if(left == right){
                if(right >= nums.size()) break;
                sum += nums[right++];
            }
            if(sum >= s){
                ret = min(ret, right - left);
                sum -= nums[left++];
            }else{
                if(right >= nums.size()) break;
                sum += nums[right++];
            }
        }
        return ret == INT_MAX ? 0 : ret;
    }
};