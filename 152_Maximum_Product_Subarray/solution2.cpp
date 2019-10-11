class Solution {
public:
    int maxProduct(vector<int>& nums) {
        MAX.assign(nums.size(), nums.back());
        MIN.assign(nums.size(), nums.back());
        int ret = nums.back();
        for(int i = nums.size()-2; i >= 0; i--){
            MAX[i] = max(nums[i], max(nums[i] * MAX[i+1], nums[i] * MIN[i+1]));
            MIN[i] = min(nums[i], min(nums[i] * MAX[i+1], nums[i] * MIN[i+1]));
            ret = max(ret, MAX[i]);
        }
        return ret;
    }
private:
    vector<int> MAX, MIN;
};