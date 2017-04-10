class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;
        return binary_search(nums, left, right);
    }
private:
    int binary_search(vector<int>& nums, int left, int right){
        //cout << "left : " << left << ", right : " << right << endl;
        int mid = (right + left) / 2;
        if(left < right){
            if(nums[mid] < nums[right])
                return min(nums[mid], binary_search(nums, left, mid-1));
            else if(nums[left] < nums[mid]){
                return min(nums[left], binary_search(nums, mid+1, right));
            }
            else if(nums[left] == nums[mid])
                return min(nums[left], binary_search(nums, left+1, right));
            else if(nums[right] == nums[mid])
                return min(nums[right], binary_search(nums, left, right-1));
        }
        if(left == right)
            return nums[left];
        return INT_MAX;
    }
};