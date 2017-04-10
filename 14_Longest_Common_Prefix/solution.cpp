class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        int length = strs[0].length();
        for(int i = 1; i < strs.size(); i++){
            length = my_longestCommonPrefix(strs[i],strs[i-1].substr(0, length));
            if(length == 0)
                return "";
        }
        return strs[strs.size()-1].substr(0, length);
    }
private:
    int my_longestCommonPrefix(string s1, string s2){
        int i;
        for(i = 0; i < s1.length() && i < s2.length() && s1[i] == s2[i]; i++);
        return i;
    }
};