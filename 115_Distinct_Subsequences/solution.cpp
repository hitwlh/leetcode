class Solution {
public:
    int numDistinct(string s, string t) {
        if(s == "" || t == "") return t == s;
        vector<vector<int>> dp(2, vector<int>(s.length(), 0));
        int SWAP = 0;
        for(int j = s.length()-1; j >= 0; j--)
            if(s[j] == t[t.length()-1]) dp[SWAP][j] = 1;
        for(int i = t.length() - 2; i >= 0; i--){
            int sum = 0;
            for(int j = s.length()-1; j >= 0; j--){
                if(s[j] == t[i])
                    dp[1-SWAP][j] = sum;
                sum += dp[SWAP][j];
            }
            for(int i = 0; i < s.length(); i++)
                dp[SWAP][i] = 0;
            SWAP = 1-SWAP;
        }
        int ret = 0;
        for(int i = 0; i < s.length(); i++)
            ret += dp[SWAP][i];
        return ret;
    }
};