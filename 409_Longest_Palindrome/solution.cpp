class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mymap;
        for(auto c: s) mymap[c]++;
        int ret = 0;
        for(auto it = mymap.begin(); it != mymap.end(); it++){
            int half = it->second/2;
            it->second = it->second - 2*half;
            ret = ret + half * 2;
        }
        for(auto it = mymap.begin(); it != mymap.end(); it++)
            if(it->second) return ret + 1;
        return ret;
    }
};