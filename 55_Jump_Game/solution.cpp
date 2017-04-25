class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return true;
        int best_index = 0, i = 1;
        while(true){
            int MAX = 0;
            int old_index = best_index;
            for(; i < nums.size() && (i - old_index <= nums[old_index]); i++){
                if(nums[i] + i - old_index > MAX){
                    MAX = nums[i] + i - old_index;
                    best_index = i;
                }
            }
            if(i == nums.size()) return true;
            if(old_index == best_index) return false;
        }
    }
};