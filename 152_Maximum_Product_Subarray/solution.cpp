class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        vector<int> MAX(n, 0), H_MAX(n, 0), H_MIN(n, 0);
        MAX[n-1] = H_MAX[n-1] = H_MIN[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            if(nums[i] == 0){
                H_MIN[i] = H_MAX[i] = 0;
            }else if(nums[i] > 0){
                H_MAX[i] = max(nums[i], nums[i] * H_MAX[i+1]);
                H_MIN[i] = min(nums[i], nums[i] * H_MIN[i+1]);
            }else{
                H_MAX[i] = max(nums[i], nums[i] * H_MIN[i+1]);
                H_MIN[i] = min(nums[i], nums[i] * H_MAX[i+1]);
            }
            MAX[i] = max(H_MAX[i], MAX[i+1]);
        }
        return MAX[0];
    }
};