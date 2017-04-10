class Solution {
public:
    int mySqrt(int x) {
        unsigned long long xx = x;
        unsigned long long left = 0;
        unsigned long long right = xx/2+1;
        unsigned long long mid;
        while(left <= right){
            mid = (left+right)/2;
            if(mid * mid > x)
                right = mid - 1;
            else if(mid * mid < x)
                left = mid + 1;
            else
                return mid;
        }
        return right;
    }
};