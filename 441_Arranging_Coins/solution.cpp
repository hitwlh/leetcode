class Solution {
public:
    int arrangeCoins(int n) {
        double sqr = n;
        sqr = 2*sqr + 0.25;
        sqr = sqrt(sqr) - 0.5;
        return sqr;
    }
};