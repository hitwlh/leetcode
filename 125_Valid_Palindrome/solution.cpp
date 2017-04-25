class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while(left < right){
            if(!isvalid(s[left])) left++;
            else if(!isvalid(s[right])) right--;
            else{
                if(!equ(s[left], s[right])) return false;
                left++, right--;
            }
        }
        return true;
    }
private:
    bool equ(char a, char b){
        //printf("%d %d %d\n", a, b, 'a'-'A');
        if((a >= '0' && a <= '9') && !(b >= '0' && b <= '9')) return false;
        if(!(a >= '0' && a <= '9') && (b >= '0' && b <= '9')) return false;
        //printf("%d %d %d\n", a, b, 'a'-'A');
        return a==b || (a+'A'-'a') == b || (a+'a'-'A') == b;
    }
    bool isvalid(char a){
        return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9');
    }
};