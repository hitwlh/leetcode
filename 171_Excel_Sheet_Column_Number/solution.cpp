class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int x = 1;
        for(int i = s.length() - 1; i >= 0; i--){
            res += x * (s[i] - 'A' + 1);
            x *= 26;
        }
        return res;
    }
};