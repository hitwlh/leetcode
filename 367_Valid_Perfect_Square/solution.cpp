class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 0) return false;
        if(num == 0) return true;
        int left = 1, right = num;
        while(left < right){
            int mid = left + (right - left) / 2;
            if((num % mid ==0) && (num / mid == mid)) return true;
            if(num / mid < mid) right = mid - 1;
            else left = mid + 1;
        }
        return (num / left == left) && (num % left ==0);
    }
};