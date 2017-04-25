class Solution {
public:
    int uniquePaths(int m, int n) {
        if(!m || !n) return 0;
        int sum = m + n -2;
        int min_ = min(m-1, n-1);
        long long ret = 1;
        for(int i = 0; i < min_; i++)
            ret = ret * (sum-i);
        for(int i = 1; i <= min_; i++)
            ret = ret / i;
        return ret;
    }
};