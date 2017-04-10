class Solution {
public:
    string convertToTitle(int n) {
        string res;
        int last;
        char use;
        while(n){
            last = (n-1) % 26;
            n -= 1;
            n /= 26;
            use = 'A' + last ;
            res =  use + res;
        }
        return res;
    }
};