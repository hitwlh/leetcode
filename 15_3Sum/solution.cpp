class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());
        for(int k = 0; k<=nums.size() - 3; k++){
            if(nums[k] > 0) break;
            if(k>0 && nums[k] == nums[k-1]) continue;
            //注意这里非常重要！！！
            int target = -nums[k];
            int i= k+1, j = nums.size()-1;
            while( i < j){
                if(nums[i] + nums[j] == target){
                    res.push_back({nums[k], nums[i], nums[j]});
                    while(i < nums.size() && nums[i] == nums[i+1]) i++;
                    while(i < j && nums[j] == nums[j-1]) j--;
                    i++;
                    j--;
                }
                else if(nums[i] + nums[j] < target)
                    i++;
                else
                    j--;
            }
        }
        return res;
    }
};