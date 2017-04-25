class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        bool max3_e = false;
        for(int i = 0; i < nums.size(); i++)
            if(max1 <= nums[i]) max1 = nums[i];
        for(int i = 0; i < nums.size(); i++)
            if(max2 <= nums[i] && nums[i] != max1) max2 = nums[i];
        for(int i = 0; i < nums.size(); i++)
            if(max3 <= nums[i] && nums[i] != max1 && nums[i] != max2) max3 = nums[i], max3_e = true;
        if(max3_e) return max3;
        else return max1;
    }
};