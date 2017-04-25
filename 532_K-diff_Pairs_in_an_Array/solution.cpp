class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ret = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j] - nums[i] == k){
                    ret++;
                    break;
                }else if(nums[j] - nums[i] > k) break;
            }
            while(i + 1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
        return ret;
    }
};