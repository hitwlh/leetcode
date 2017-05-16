class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<int>tmp(nums.size(), 0);
        player.assign(nums.size(), tmp);
        sum = nums;
        for(int i = 1; i < sum.size(); i++)
            sum[i] += sum[i-1];
        for(int i = 0; i < player[0].size(); i++)
            player[i][i] = nums[i];
        for(int i = 2; i <= nums.size(); i++){//区间长度i
            for(int j = 0; i + j - 1< nums.size(); j++){//j是起点，[j, i+j-1]是区间
                int left = nums[j] + (sum[i+j-1] - sum[j+1] + nums[j+1]) - player[j+1][i+j-1];
                int right = nums[i+j-1] + (sum[i+j-2] - sum[j] + nums[j]) - player[j][i+j-2];
                player[j][i+j-1] = max(left, right);
            }
        }
        return player[0][player.size()-1] * 2 >= sum[sum.size()-1];
    }
private:
    vector<vector<int>> player;
    vector<int> sum;
    
    
};