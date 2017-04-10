class Solution {
public:
    int strStr(string haystack, string needle) {
        int len_h = haystack.length();
        int len_n = needle.length();
        for(int i=0; i<= len_h - len_n; i++){
            if(needle == haystack.substr(i, len_n))
                return i;
        }
        return -1;
    }
};