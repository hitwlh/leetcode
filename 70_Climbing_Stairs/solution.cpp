class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int a1 = 1, a2 = 2, now = 3;
        while(now <= n){
            int sum = a1+a2;
            a1 = a2;
            a2 = sum;
            now++;
        }
        return a2;
    }
};