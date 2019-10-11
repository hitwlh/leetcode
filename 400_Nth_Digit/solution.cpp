class Solution {
public:
    int findNthDigit(int n) {
        int k = 1;
        while(n > 9 * pow(10, k-1) * k){
            n -=  9 * pow(10, k-1) * k;
            k++;
        }
        int number = (n-1) / k + pow(10, k-1), digit;
        if(n % k == 0) return number % 10;
        digit = k - n % k;
        while(digit--) number /= 10;
        return number % 10;
    }
};