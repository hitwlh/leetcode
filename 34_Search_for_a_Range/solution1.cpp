class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = -1, right = -1;
        if(nums.empty()) return {left, right};
        if(nums[0] == target) left = right = 0;
        for(int i = 1; i < nums.size(); i++){
            if(left == -1 && nums[i] == target)
                left = i;
            if(nums[i-1] == target && nums[i] != target)
                right = i-1;
        }
        if(nums[nums.size()-1] == target)
            right = nums.size() - 1;
        return {left, right};
    }
};