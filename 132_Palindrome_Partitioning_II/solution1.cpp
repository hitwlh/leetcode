class Solution {
public:
    int minCut(string s) {
        if(s == "") return 0;
        my_s = s;
        vector<int> dp(s.length()+1, 0);
        isp.assign(s.length(), vector<bool>(s.length(), false));
        for(int length = 1; length <= s.length(); length++)
            for(int start = 0; start + length - 1 < s.length(); start++)
                isp[start][start+length-1]  = (s[start] == s[start+length-1] && (start + 1 > start+length-2 || isp[start+1][start+length-2]));
        dp.back() = -1;
        for(int i = s.length() - 1; i >= 0; i--){
            dp[i] = s.length() - i - 1;
            for(int j = i; j < s.length(); j++)
                if(isp[i][j])
                    dp[i] = min(dp[i], dp[j+1] + 1);
                //else dp[i] = min(dp[i], j - i + 1 + dp[j+1]);
        }
        return dp[0];
    }
private:
    string my_s;
    vector<vector<bool>> isp;
    bool is_palindrome(int start, int end){
        while(start <= end && my_s[start] == my_s[end])
            start++, end--;
        return start > end;
    }
};