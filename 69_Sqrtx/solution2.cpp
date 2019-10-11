class Solution {
public:
    int mySqrt(int x) {
        if(!x) return 0;
        int left = 1, right = x;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(x / mid >= mid) left = mid+1;
            else right = mid - 1;
        }
        return left - 1;
    }
};