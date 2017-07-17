class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), left = 1, right = 1;
        vector<int> ret(n, 1);
        for(int i = n-2; i >= 0; i--){
            right *= nums[i+1];
            ret[i] = right;
        }
        for(int i = 1; i < n; i++){
            left *= nums[i-1];
            ret[i] *= left;
        }
        return ret;
    }
};