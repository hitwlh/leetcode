class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 1, right = n, N = n;
        while(left <= right){
            long long mid = (left + right) / 2;
            if(mid * (mid+1) / 2 <= N) left = mid+1;
            else right = mid - 1;
        }
        return left-1;
    }
};