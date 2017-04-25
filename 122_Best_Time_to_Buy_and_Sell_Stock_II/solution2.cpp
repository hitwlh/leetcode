class Solution {
public:
    int maxProfit(vector<int>& prices) {
        my_prices = prices;
        int ret = 0, MAX = INT_MIN;
        if(prices.empty() || prices.size() == 1) return 0;
        for(int end = 1; end < prices.size(); end++){
            int tmp = my_maxProfit(0, end);
            if(tmp > MAX) MAX = tmp;
        }
        return MAX;
    }
private:
    vector<int> my_prices;
    int my_maxProfit(int start, int end){
        int ret = 0, curMin = INT_MAX;
        for(int i = start+1; i <= end; i++){
            curMin = min(curMin, my_prices[i-1]);
            ret = max(ret, my_prices[i] - curMin);
        }
        int MAX = 0;
        for(int i = end + 2; i < my_prices.size(); i++){
            int tmp = my_maxProfit(end+1, i);
            if(tmp > MAX) MAX = tmp;
        }
        return ret + MAX;
    }
};