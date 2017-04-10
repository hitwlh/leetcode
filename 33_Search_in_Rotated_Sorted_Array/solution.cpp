class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;
        return binary_search(nums, target, left, right);
    }
private:
    int binary_search(vector<int>& nums, int target, int left, int right){
        int mid = (right + left) / 2;
        if(nums[mid] == target) return mid;
        if(left < right){
            if(nums[mid] < nums[right]){
                if(nums[mid] < target && nums[right] >= target) return binary_search(nums, target, mid+1, right);
                else return binary_search(nums, target, left, mid-1);
            }
            else{
                if(nums[mid] > target && nums[left] <= target) return binary_search(nums, target, left, mid-1);
                else return binary_search(nums, target, mid+1, right);
            }
        }
        else if(left == right && target == nums[left])
            return left;
        return -1;
    }
};