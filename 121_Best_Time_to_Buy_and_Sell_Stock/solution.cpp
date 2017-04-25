class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0, curMin = INT_MAX;
        for(int i = 1; i < prices.size(); i++){
            curMin = min(curMin, prices[i-1]);
            ret = max(ret, prices[i] - curMin);
        }
        return ret;
    }
};