class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<unsigned int> ret(amount+1, INT_MAX);//这里用unsigned int，然后INT_MAX，+1操作能保证数据有效；否则，int类型的数据，INT_MAX，+1后，变成了INT_MIN
        ret[0] = 0;
        for(int i = 0; i <= amount; i++){
            for(auto j: coins)
                if(i >= j)
                    ret[i] = min(ret[i-j] + 1, ret[i]);
        }
        return ret.back() == INT_MAX ? -1 : ret.back();
    }
};