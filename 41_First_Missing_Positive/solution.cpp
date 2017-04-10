class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
            if(nums[i]>0 && nums[i] <= nums.size() && nums[i] != i+1 && nums[nums[i] - 1] != nums[i]){
                //这里本来写成了if(nums[i]>0 && nums[i] <= nums.size() && nums[i] != i+1，这样在[1, 1]的输入下会死循环
                switchc(nums[nums[i] - 1], nums[i]);
                i--;
                //important
            }
        for(int i=0; i<nums.size(); i++)
            if(nums[i] != i+1)
                return i+1;
        return nums.size()+1;
        }
    void switchc(int &a, int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
};