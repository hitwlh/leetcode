class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s=="") return 0;
        int right = 0, now = s.length()-1;
        while(now >= 0){
            if(s[now] != ' ')
                right++;
            else if(right != 0) return right;
            now--;
        }
        return right;
    }
};