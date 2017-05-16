class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size() <= 2) return true;
        num = nums;
        left = 0, right = nums.size()-1;
        sum[0] = sum[1] = 0;
        return dfs(0);
    }
private:
    int left, right, sum[2];
    vector<int> num;
    bool dfs(int player){
        if(left == right){
            sum[player] += num[left];
            bool result = (player == 0) ? (sum[player] >= sum[1-player]) : (sum[player] > sum[1-player]);
            sum[player] -= num[left];
            return result;
        }
        bool ret = true;
        sum[player] += num[left++];
        ret = dfs(1 - player);
        sum[player] -= num[--left];
        if(ret == false) return true;
        sum[player] += num[right--];
        ret = !dfs(1 - player);
        sum[player] -= num[++right];
        return ret;
    }
};