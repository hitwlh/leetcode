class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n <= 0) return ret;
        vector<int> use;
        use.assign(n, 0);
        ret.assign(n, use);
        n--;
        int now = 1;
        for(int x = 0, y = 0; x <= n && y <= n; x++, y++){
            for(int i = y; i < n; i++) ret[x][i] = now++;
            for(int i = x; i <=  n; i++) ret[i][n] = now++;
            for(int i = n-1; i >= y && x != n; i--) ret[n][i] = now++;
            for(int i = n-1; i > x && y != n; i--) ret[i][y] = now++;
            n--;
        }
        return ret;
    }
private:
    vector<vector<int>> ret;
};