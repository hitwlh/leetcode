class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length() == 0)
            return 0;
        int ret = 0;
        int exists = 0;
        for(int i=0; i<s.length(); i++){
            //cout << ret << endl;
            if(s[i] == ' '){
                exists = ret==0?exists:ret;
                ret = 0;
            }
            else
                ret ++;
        }
        if(!ret)
            return exists;
        return ret;
    }
};