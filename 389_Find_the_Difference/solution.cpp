class Solution {
public:
    char findTheDifference(string s, string t) {
        int ss[26], st[26];
        for(int i = 0; i < 26; i++)
            ss[i] = st[i] = 0;
        for(auto c: s) ss[c - 'a']++;
        for(auto c: t) st[c - 'a']++;
        for(int i = 0; i < 26; i++)
            if(ss[i] != st[i]) return 'a' + i;
    }
};