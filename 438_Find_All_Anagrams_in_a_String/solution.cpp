class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> s1,s2, ret;
        s1.assign(256, 0);
        s2.assign(256, 0);
        int ls = s.length(), lp = p.length();
        for(int i = 0; i+1 < lp; i++) s1[s[i]] ++;
        for(int i = 0; i < lp; i++) s2[p[i]] ++;
        for(int i = lp-1; i < ls; i++){
            s1[s[i]]++;
            if(s1 == s2) ret.push_back(i - lp + 1);
            s1[s[i - lp + 1]] --;
        }
        return ret;
    }
};