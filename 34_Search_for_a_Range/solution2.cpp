class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, l1 = -1, l2 = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target) right = mid-1;
            else left = mid + 1;
        }
        l1 = right + 1;
        left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target) left = mid + 1;
            else right = mid - 1;
        }
        l2 = left - 1;
        if(l1 > l2) return {-1, -1};
        return {l1, l2};
    }
};