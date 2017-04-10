class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int tm = x;
        int base = 1;
        while(tm/10){
            tm /= 10;
            base *= 10;
        }
        while(x){
        int right = x % 10;
        int left = x / base;
        x -= base*right;
        //注意减掉左边的数字要用这个方法
        //注意要先做减法再做除法，否则可能除了后为0再减变成负
        x /= 10;
        base /= 100;
        if(left!=right)
            return false;
        }
        return true;
    }
};