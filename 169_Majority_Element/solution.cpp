class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = nums.front();
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(ret == nums[i])
                count ++;
            else{
                if(count > 0) count --;
                else{
                    ret = nums[i];
                    count = 1;
                }
            }
        }
        return ret;
    }
};