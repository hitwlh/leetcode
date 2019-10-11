class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.empty()) return false;
        my_nums = nums;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 4 != 0) return false;
        return dfs(0, sum/4, 0, 0, 0, 0);
    }
private:
    bool dfs(int now, int s, int sum1, int sum2, int sum3, int sum4){
        if(sum1 > s || sum2 > s || sum3 > s || sum4 > s) return false;
        if(now == my_nums.size()){
            if(sum1 == s && sum2 == s && sum3 == s) return true;
            return false;
        }
        return dfs(now+1, s, sum1 + my_nums[now], sum2, sum3, sum4) || dfs(now+1, s, sum1, sum2 + my_nums[now], sum3, sum4) || dfs(now+1, s, sum1, sum2, sum3 + my_nums[now], sum4) || dfs(now+1, s, sum1, sum2, sum3, sum4 + my_nums[now]);
    }
    vector<int> my_nums;
};