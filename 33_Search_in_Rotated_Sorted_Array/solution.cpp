class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < nums[right]){//mid右侧有序
                if(nums[mid] < target and nums[right] >= target)
                    left = mid + 1;
                else right = mid - 1;
            }else{//mid左侧有序
                if(nums[mid] > target and nums[left] <= target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};