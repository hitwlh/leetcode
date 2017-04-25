class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty() || prices.size() == 1) return 0;
        if(k >= prices.size()) return maxProfit2(prices);
        vector<int> MustSell, TruthSolution;
        MustSell.assign(k+1, 0);
        TruthSolution.assign(k+1, 0);
        for(int i = 1; i < prices.size(); i++){
            int diff = prices[i] - prices[i-1];
            for(int j = k; j >= 1; j--){
                MustSell[j] = max(MustSell[j] + diff, TruthSolution[j-1] + max(0, diff));
                TruthSolution[j] = max(TruthSolution[j], MustSell[j]);
            }
        }
        return TruthSolution[k];
    }
private:
    int maxProfit2(vector<int>& prices) {
        int ret = 0;
        for(int i = 1 ; i < prices.size(); i++)
            if(prices[i-1] < prices[i]) ret += prices[i] - prices[i-1];
        return ret;
    }
};