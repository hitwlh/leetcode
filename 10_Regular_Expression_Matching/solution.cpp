class Solution {
public:
    bool isMatch(string s, string p) {
        if(p == "") return s == "";
        if(p.size() == 1) return ((s.size() == 1) && (s[0] == p[0] || p[0] == '.'));
        if(p[1] != '*'){
            if(s == "") return false;
            return ((s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)));
        }
        //if(s != "" && s[0] != p[0] && p[0] != '.') return isMatch(s, p.substr(2));
        while(s != "" && (s[0] == p[0] || p[0] == '.')){
            if(isMatch(s, p.substr(2))) return true;
            s.erase(s.begin());
        }
        return isMatch(s, p.substr(2));
    }
};