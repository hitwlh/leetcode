class Solution {
public:
    int findNthDigit(int n) {
        int flag = 1;
        while(n > pow(10, flag-1) * flag * 9){
            n = n - pow(10, flag-1) * flag * 9;
            flag++;
        }
        int number = (n-1) / flag + pow(10, flag-1);
        int digit = (flag-1) - (n-1) % flag;
        while(digit--)
            number /= 10;
        return number % 10;
    }
};