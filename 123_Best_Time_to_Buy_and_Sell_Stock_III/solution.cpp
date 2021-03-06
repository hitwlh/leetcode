class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty() || prices.size() == 1) return 0;
        int MIN = prices[0], MAX = 0;
        left.push_back(0);
        for(int i = 1; i < prices.size(); i++){
            MIN = min(MIN, prices[i-1]);
            MAX = max(MAX, prices[i] - MIN);
            left.push_back(MAX);
        }
        right.assign(left.size(), 0);
        MIN = 0, MAX = prices[prices.size()-1];
        for(int i = prices.size() - 2; i >= 0; i--){
            MAX = max(MAX, prices[i+1]);
            MIN = max(MIN, MAX - prices[i]);
            right[i] = MIN;
        }
        int ret = 0;
        for(int i = 0; i < prices.size()-1; i++)
            ret = max(ret, left[i] + right[i]);
        return ret;
    }
private:
    vector<int> left, right;
};