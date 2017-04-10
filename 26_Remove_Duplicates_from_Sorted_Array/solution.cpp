class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int i = 1;
        int old = nums[0];
        int times = 1;
        while(i < nums.size()){
            if(old == nums[i]){
                nums.erase(nums.begin()+i);
                i--;
            }
            else{
                old = nums[i];
                times++;
            }
            i++;
        }
        return times;
    }
};