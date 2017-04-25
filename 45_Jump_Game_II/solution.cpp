class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int best_index = 0, i = 1;
        int ret = 0;
        while(true){
            int MAX = 0;
            int old_index = best_index;
            for(; i < nums.size() && (i - old_index <= nums[old_index]); i++){
                if(nums[i] + i - old_index > MAX){
                    MAX = nums[i] + i - old_index;
                    best_index = i;
                }
            }
            ret++;
            if(i == nums.size()) return ret;
            if(old_index == best_index) return -1;
        }
    }
};