class Solution {
public:
    double myPow(double x, int n) {
        if(!n) return 1;
        if(n==1) return x;
        bool flag = false;
        if(n < 0) flag = true;
        n = fabs(n);
        double sqrt = myPow(x,fabs(n/2));
        double ret = sqrt * sqrt;
        if(n%2) ret *= x;
        return flag ? 1/ret : ret;
    }
};