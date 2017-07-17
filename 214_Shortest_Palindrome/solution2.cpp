class Solution {
public:
    string shortestPalindrome(string s) {
        if(s == "") return s;
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        vector<int> next(t.length() + 1, -1);
        int i = 0, k = -1;
        while(i + 1 < next.size()){
            if(k == -1 || t[i] == t[k]){
                i++, k++;
                next[i] = k;
                
            }else{
                k = next[k];
            }
        }
        return r.substr(0, s.size() - next.back()) + s;
    }
};