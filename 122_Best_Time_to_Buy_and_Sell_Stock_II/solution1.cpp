class Solution {
public:
    int maxProfit(vector<int>& prices) {
        my_prices  = prices;
        return recur_maxProfit(0, prices.size()-1);
    }
private:
    vector<int> my_prices;
    int recur_maxProfit(int start, int end){
        
        int MAX = 0;
        for(int i = start; i <= end-1; i++){
            int tmp = my_maxProfit(i, end) + recur_maxProfit(start, i-1);
            if(tmp > MAX) MAX = tmp;
        }
        return MAX;
    }
    int my_maxProfit(int start, int end){
        int ret = 0, curMin = INT_MAX;
        for(int i = start+1; i <= end; i++){
            curMin = min(curMin, my_prices[i-1]);
            ret = max(ret, my_prices[i] - curMin);
        }
        return ret;
    }
};