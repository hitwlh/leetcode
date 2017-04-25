class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty() || prices.size() == 1) return 0;
        if(k >= prices.size()) return maxProfit2(prices);
        int MustSell[prices.size()][k+1] = {0};
        int TruthSolution[prices.size()][k+1] = {0};
        //for(int i = 0; i < prices.size(); i++) for(int j = 0; j < k+1; j++) MustSell[i][j] = TruthSolution[i][j] = 0;
        memset(MustSell, 0, sizeof(MustSell));
        memset(TruthSolution, 0, sizeof(TruthSolution));
        for(int j = 1; j <= k; j++){
            for(int i = 1; i < prices.size(); i++){
                int diff = prices[i] - prices[i-1];
                MustSell[i][j] = max(MustSell[i-1][j] + diff, TruthSolution[i-1][j-1] + max(0, diff));
                TruthSolution[i][j] = max(TruthSolution[i-1][j], MustSell[i][j]);
            }
        }
        return TruthSolution[prices.size()-1][k];
    }
private:
    int maxProfit2(vector<int>& prices) {
        int ret = 0;
        for(int i = 1 ; i < prices.size(); i++)
            if(prices[i-1] < prices[i]) ret += prices[i] - prices[i-1];
        return ret;
    }
};