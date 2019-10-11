class Solution {
public:
    int minMoves(vector<int>& nums) {
        int MIN = INT_MAX, ret = 0;
        for(auto i: nums) MIN = min(MIN, i);
        for(auto i: nums) ret += i - MIN;
        return ret;
    }
};