class Solution {
public:
    int getMoneyAmount(int n) {
        result.assign(n+1, vector<int>(n+1, 0));
        for(int i = 2; i <= n; i++){//i是区间容量
            for(int j = 1; j <= n - i + 1; j++){//j是区间[j, j+i-1]的起点
                int MIN = INT_MAX;
                for(int k = j; k < j+i-1; k++)//k是区间[j, j+i-1]的切割点，显然切割点不是区间终点
                    MIN = min(MIN,  k + max(result[j][k-1], result[k+1][j+i-1]));
                result[j][j+i-1] = MIN;
            }
        }
        return result[1][n];
    }
private:
    vector<vector<int>> result;
};