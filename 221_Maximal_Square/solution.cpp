class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int MAX = 0;
        vector<int> dp(matrix[0].size(), 0);
        vector<int> dp2 = dp;
        for(int j = 0; j < matrix[0].size(); j++){
            dp2[j] = matrix[0][j] - '0';
            MAX = max(dp2[j], MAX);
        }
        for(int i = 1; i < matrix.size(); i++){
            dp = dp2;
            dp2[0] = matrix[i][0] - '0';
            MAX = max(MAX, dp2[0]);
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j] == '0') dp2[j] = 0;
                else dp2[j] = min(dp2[j-1], min(dp[j], dp[j-1])) + 1;
                MAX = max(MAX, dp2[j]);
            }
        }
        return MAX * MAX;
    }
};