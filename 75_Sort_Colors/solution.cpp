class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size()-1, i = 0;
        while(i <= right){
            if(nums[i] == 0){
                swap(nums[left], nums[i]);
                left ++;
                i ++;
            }
            else if(nums[i] == 1)
                i ++;
            else{
                swap(nums[i], nums[right]);
                right --;
            }
        }
    }
};