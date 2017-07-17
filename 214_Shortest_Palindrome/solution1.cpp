class Solution {
public:
    string shortestPalindrome(string s) {
        if(s == "") return s;
        for(int j = s.length()-1; j >= 0; j--){
            if(s[j] == s[0] && is_Palindrome(s.substr(0, j+1)))
                return reverse(s.substr(j+1)) + s;
        }
        return reverse(s)+s;
    }
private:
    bool is_Palindrome(string s){
        int i = 0, j = s.length()-1;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    string reverse(string s){
        int i = 0, j = s.length()-1;
        while(i < j){
            swap(s[i], s[j]);
            i++, j--;
        }
        return s;
    }
};