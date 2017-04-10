class Solution {
public:
    bool isPowerOfThree(int n) {
        double ret = log10(n) / log10(3);
        if(n == 0)
            return false;
        return (ret-(int)ret) < 1e-10;
    }
};