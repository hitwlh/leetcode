class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;
        int ret = 1;
        while(n - 4 > 0){
            ret *= 3;
            n -= 3;
        }
        return ret * n ;
    }
};