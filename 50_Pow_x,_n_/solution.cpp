class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1) return 1;
        bool flag = n < 0;
        long N = fabs(n);
        double ret = myPow(x, N/2);
        ret *= ret;
        if(N % 2) ret *= x;
        return flag ? 1 / ret: ret;
    }
};