class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int ret = 0, product = 1, left = 0;
        for(int i = 0; i < nums.size(); i++){
            product *= nums[i];
            while(product >= k)
                product /= nums[left++];
            ret += i - left + 1;
        }
        return ret;
    }
};