class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        vector<int> buy(prices.size(), 0), sell(prices.size(), 0), rest(prices.size(), 0);
        buy[0] = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            buy[i] = max(buy[i-1], rest[i-1] - prices[i]);
            sell[i] = max(buy[i-1] + prices[i], sell[i-1]);
            rest[i] = max(rest[i-1], sell[i-1]);
        }
        return sell.back();
    }
};