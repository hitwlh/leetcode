class Solution {
public:
    int findMin(vector<int>& nums) {
        return search(nums, 0, nums.size()-1);
    }
private:
    int search(vector<int>& nums, int left, int right){
        if(left > right) return INT_MAX;
        if(nums[left] < nums[right] or left == right) return nums[left];
        int mid = (left + right) / 2;
        if(nums[mid] == nums[right])
           return search(nums, left, right-1);
        if(nums[left] <= nums[mid])
            return search(nums, mid+1, right);
        return min(search(nums, left, mid-1), nums[mid]);
    }
};