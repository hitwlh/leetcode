class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> f(p.length()+1, vector<bool>(s.length()+1, false));//f[j][i]表示p的前j位，s的前i位是否匹配
        f[0][0] = true;
        for(int j = 1; j <= p.length(); j++){
            for(int i = 0; i <= s.length(); i++){
                if(p[j-1] != '*')
                    f[j][i] = (i > 0 && ((p[j-1] == '.' || p[j-1] == s[i-1] ) && f[j-1][i-1]));
                else{
                    if(j-2 >= 0) f[j][i] = f[j-2][i];
                    if(j-2 >= 0 && i > 0 && (p[j-2] == s[i-1] || p[j-2] == '.'))
                        f[j][i] = f[j][i] || f[j][i-1];
                }
            }
        }
        return f[p.length()][s.length()];
    }
};