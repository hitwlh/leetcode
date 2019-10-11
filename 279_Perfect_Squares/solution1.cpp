class Solution {
public:
    int numSquares(int n) {
        ret.assign(n+1, INT_MAX);
        ret[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; i - j * j >= 0; j++)
                ret[i] = min(ret[i], 1 + ret[i-j*j]);
        }
        return ret[n];
    }
private:
    vector<int> ret;
};