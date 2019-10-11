class Solution {
public:
    int findMin(vector<int>& nums) {
        return findpivot(nums, 0, nums.size()-1);
    }
private:
    int findpivot(vector<int>& nums, int left, int right){
        if(left > right) return INT_MAX;
        if(nums[left] <= nums[right]) return nums[left];
        int mid = (left + right) / 2;
        if(nums[mid] >= nums[left])
            return findpivot(nums, mid+1, right);
        return min(nums[mid], findpivot(nums, left, mid-1));
    }
};