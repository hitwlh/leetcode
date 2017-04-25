class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            nums[fabs(nums[i])-1] = 0 - fabs(nums[fabs(nums[i])-1]);
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0)
                ret.push_back(i+1);
        return ret;
    }
};