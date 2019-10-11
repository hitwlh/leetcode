class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return se(nums, target, 0, nums.size()-1);
    }
private:
    bool se(vector<int>& nums, int target, int left, int right){
        if(left > right) return false;
        int mid = (left + right) / 2;
        if(nums[mid] == target) return true;
        if(nums[right] == nums[mid])
            return se(nums, target, left, right-1);
        if(nums[mid] < target){
            if(nums[right] > nums[mid] and nums[right] < target)
                return se(nums, target, left, mid-1);
            return se(nums, target, mid+1, right);
        }else{
            if(nums[right] < nums[mid] and nums[left] > target)
                return se(nums, target, mid+1, right);
            return se(nums, target, left, mid-1);
        }
    }
};