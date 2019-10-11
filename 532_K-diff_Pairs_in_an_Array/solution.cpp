class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int i = 0,j = 1, ret = 0;
        sort(nums.begin(), nums.end());
        while(j < nums.size()){
            if(i == j) j++;//这一行代码不容易想到,[i, j]是有效区间，i==j时，区间无效。k为0时会过多统计
            if(nums[j] - nums[i] == k){
                ret++;
                j++;
            }
            else if(nums[j] - nums[i] < k) j++;
            else i++;
            while(j < nums.size() && nums[j] == nums[j-1]) j++;//这一行代码不容易想到
        }
        return ret;
    }
};