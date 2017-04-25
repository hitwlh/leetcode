class Solution {
public:
    int numSquares(int n) {
        ret.assign(n+1, -1);
        ret[1] = 1;
        for(int i = 1; i <= n; i++)
            ret[i] = my_numSquares(i);
        return ret[n];
    }
private:
    int my_numSquares(int n) {
        int q = sqrt(n);
        int MIN = INT_MAX;
        if(n-q*q == 0) return 1;
        for(int i = q; i >= 1; i--){
            int numSquaresq = 1 + ret[n-i*i];
            if(numSquaresq < MIN && numSquaresq != -1 )
                MIN = numSquaresq;
        }
        return MIN;
    }
    vector<int> ret;
};