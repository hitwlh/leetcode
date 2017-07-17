class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<unsigned int> ret(amount+1, INT_MAX);
        ret[0] = 0;
        for(int i = 0; i <= amount; i++){
            for(auto j: coins)
                if(i >= j)
                    ret[i] = min(ret[i-j] + 1, ret[i]);
        }
        return ret.back() == INT_MAX ? -1 : ret.back();
    }
};