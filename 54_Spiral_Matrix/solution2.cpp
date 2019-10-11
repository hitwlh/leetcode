class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.empty()) return ret;
        int m = matrix.size()-1, n = matrix[0].size()-1;
        for(int x = 0, y = 0; x <= m && y <= n; x++, y++, n--, m--){
            if(x >= m){
                for(int i = y; i <= n; i++)
                    ret.push_back(matrix[x][i]);
                break;
            }
            if(y >= n){
                for(int i = x; i <= m; i++)
                    ret.push_back(matrix[i][y]);
                break;
            }
            for(int i = y; i <= n; i++) ret.push_back(matrix[x][i]);
            for(int i = x+1; i <= m; i++) ret.push_back(matrix[i][n]);
            for(int i = n-1; i >= y; i--) ret.push_back(matrix[m][i]);
            for(int i = m-1; i > x; i--) ret.push_back(matrix[i][y]);
        }
        return ret;
    }
};