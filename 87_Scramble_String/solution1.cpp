class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2)return true;
        if(s1.length()!=s2.length())return false;//剪枝，若满足题意，长度肯定相等
        string s11 = s1, s22 = s2;//生成s1和s2的副本，以便排序。（不要对s1和s2进行排序）
        sort(s11.begin(),s11.end());
        sort(s22.begin(),s22.end());
        if(s11 != s22) return false;//剪枝，若满足题意，排序后，二者一定相等。
        for(int i = 1; i < s1.length(); i++){
            bool result = (isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)))||
            (isScramble(s1.substr(0,i),s2.substr(s2.length()-i,i)) && isScramble(s1.substr(i),s2.substr(0,s2.length()-i)));
            if(result)
                return true;
        }
        return false;
    }
};