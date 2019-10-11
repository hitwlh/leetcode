class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        int left = 0, right = 1, len = 1, ret = 1;
        unordered_map<char, bool> usin;
        usin[s[0]] = true;
        while(right < s.length()){
            while(usin.count(s[right])){
                usin.erase(s[left++]);
                len -= 1;
            }
            usin[s[right++]] = true;
            len += 1;
            ret = max(ret, len);
        }
        return ret;
    }
};