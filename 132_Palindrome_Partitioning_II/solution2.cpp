class Solution {
public:
    int minCut(string s) {
        vector<int> dp(s.length(), 0);
        for(int i = 0; i < s.length(); i++) 
            dp[i] = i;
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; i-j >= 0 && i+j < s.length() && s[i-j] == s[i+j]; j++)
                if(i-j == 0) dp[i+j] = 0;
                else dp[i+j] = min(dp[i+j], dp[i-j-1] + 1);
            for(int j = 1; i+1-j >= 0 && i + j < s.length() && s[i+1-j] == s[i+j]; j++)
                if(i+1-j == 0) dp[i+j] = 0;
                else dp[i+j] = min(dp[i+j], dp[i-j] + 1);
        }
        return dp.back();
    }
};