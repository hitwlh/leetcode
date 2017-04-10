class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int left = 0, right = nums.size() - 1;
        return binary_search(nums, target, left, right);
    }
private:
    bool binary_search(vector<int>& nums, int target, int left, int right){
        //cout << "left : " << left << ", right : " << right << endl;
        int mid = (right + left) / 2;
        if(nums[mid] == target) return true;
        if(left < right){
            if(nums[mid] < nums[right]){
                if(nums[mid] < target && nums[right] >= target) return binary_search(nums, target, mid+1, right);
                else return binary_search(nums, target, left, mid-1);
            }
            else if(nums[left] < nums[mid]){
                if(nums[mid] > target && nums[left] <= target) return binary_search(nums, target, left, mid-1);
                else return binary_search(nums, target, mid+1, right);
            }
            else if(nums[mid] == nums[left])
                return binary_search(nums, target, left+1, right);
            else if(nums[mid] == nums[right])
                return binary_search(nums, target, left, right-1);
        }
        else if(left == right && target == nums[left])
            return true;
        return false;
    }
};