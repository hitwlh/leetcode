class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long i = 0, ret = 0, could = 0;
        while(could < n){
            if(i < nums.size() && nums[i] <= could + 1)
                could += nums[i++];
            else{
                ret++;
                could += could + 1;
            }
        }
        return ret;
    }
};