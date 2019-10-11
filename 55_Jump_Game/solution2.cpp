class Solution {
public:
    bool canJump(vector<int>& nums) {
        int now = 0;
        for(int i = 0; i < nums.size(); i++){
            if(now < i) return false;
            now = max(nums[i]+i, now);
        }
        return true;
    }
};