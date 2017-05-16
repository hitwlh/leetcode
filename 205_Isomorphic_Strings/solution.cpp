class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int a[128];
        for(int i = 0; i < 128; i++) a[i] = -1000;
        for(int i = 0; i < s.length(); i++){
            if(a[s[i]] == -1000){
                a[s[i]] = s[i] - t[i];
            }else if(a[s[i]] + t[i] != s[i]) return false;
        }
        //反过来再做一遍
        for(int i = 0; i < 128; i++) a[i] = -1000;
        for(int i = 0; i < t.length(); i++){
            if(a[t[i]] == -1000){
                a[t[i]] = t[i] - s[i];
            }else if(a[t[i]] + s[i] != t[i]) return false;
        }
        return true;
    }
};