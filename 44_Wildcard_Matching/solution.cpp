class Solution {
public:
    bool isMatch(string s, string p) {
        if(p == "")
            return s == "";
        if(s == ""){
            for(int i = 0; i < p.length(); i++)
                if(p[i] != '*') return false;
            return true;
        }
        vector<vector<bool>> f(p.length(), vector<bool>(s.length(), false));
        if(p[0] == '*'){
            for(int j = 0; j < s.length(); j++)
                f[0][j] = true;
        }else{
            if(p[0] == '?' || p[0] == s[0]) f[0][0] = true;
        }
        /*for(int i = 1; i < p.length(); i++){
            if(p[i] == '*') f[i][0] = f[i-1][0];
            else f[i][0] = false;
        }*/
        int cut = p.length(), flag = 0;
        for(int i = 0; i < p.length(); i++){
            if(p[i] != '*'){
                if(flag){
                    cut = i;
                    break;
                }
                if(p[i] != '?' && p[i] != s[0]){
                    cut = i;
                    break;
                }
                flag = 1;
            }
        }
        for(int i = 0; i<cut; i++)
            f[i][0] = true;
        for(int i = 1; i < p.length(); i++){
            for(int j = 1; j < s.length(); j++){
                if(p[i] == '*'){
                    f[i][j] = (f[i-1][j] || f[i][j-1]);
                }else{
                    if(f[i-1][j-1] && (p[i] == s[j] || p[i] == '?'))
                        f[i][j] = true;
                }
            }
        }
        return f[p.length()-1][s.length()-1];
    }
};