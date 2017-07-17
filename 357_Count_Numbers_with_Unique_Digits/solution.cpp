class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n > 10) return countNumbersWithUniqueDigits(10);
        int ret = 10, tmp = 1;
        for(int i = 2; i <= n; i++){
            tmp *= (11-i);
            ret = ret + 9 * tmp;
        }
        return ret;
    }
};