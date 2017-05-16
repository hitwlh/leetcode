class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        my_nums = nums;
        ret = 0;
        dfs(0, S);
        return ret;
    }
private:
    void dfs(int start, int target){
        if(start == my_nums.size()){
            if(target == 0) ret++;
            return;
        }
        dfs(start+1, target - my_nums[start]);
        dfs(start+1, target + my_nums[start]);
    }
    vector<int> my_nums;
    int ret;
};