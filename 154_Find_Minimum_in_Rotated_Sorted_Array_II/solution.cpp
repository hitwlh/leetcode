class Solution {
public:
    int findMin(vector<int>& nums) {
        int ret = INT_MAX, left = 0, right = nums.size()-1, mid;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] < nums[right]){
                ret = min(ret, nums[mid]);
                right = mid - 1;
            }else if(nums[mid] > nums[right]){
                ret = min(ret, nums[left]);
                left = mid + 1;
            }else
                ret = min(ret, nums[right--]);
        }
        return ret;
    }
};