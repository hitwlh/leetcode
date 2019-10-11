class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j,flag = 0;
        for(i = nums.size() - 1; i >= 1 && flag == 0; i--){
            if(nums[i-1] < nums[i]){
                for(j = nums.size()-1; j >= i ; j--){
                    if(nums[i-1] < nums[j]){
                        swap(nums[i-1], nums[j]);
                        flag = 1;
                        break;
                    }
                }
            }
        }
        int left ,right;
        if(flag == 0)
            left = 0;
        else
            left = i+1;
        right = nums.size() - 1;
        reverse(nums.begin()+left, nums.end());
    }
};