class Solution {
public:
    int firstUniqChar(string s) {
        int a[26];
        for(int i = 0; i < 26; i++) a[i] = -2;
        for(int i = 0; i < s.length(); i++){
            if(a[s[i] - 'a'] == -2) a[s[i] - 'a'] = i;
            else if(a[s[i] - 'a'] >= 0) a[s[i] - 'a'] = -1;
        }
        int MIN = INT_MAX;
        for(int i = 0; i < 26; i++)
            if(a[i] >= 0) MIN = min(MIN, a[i]);
        return MIN == INT_MAX ? -1 : MIN;
    }
};