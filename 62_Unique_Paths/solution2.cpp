class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m > n) swap(m, n);
        vector<int> ret(n, 1);
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                ret[j] = ret[j-1] + ret[j];
            }
        }
        return ret.back();
    }
};