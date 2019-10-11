class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int sum = 10, last = 9, mul = 9;
        for(int i = 2; i <= n; i++){
            last *= mul;
            sum += last;
            mul --;
        }
        return sum;
    }
};