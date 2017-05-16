class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.empty()) return 0;
        int MIN = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] < MIN) MIN = nums[i];
        int ret = 0;
        for(auto i: nums) ret += i - MIN;
        return ret ;
    }
};