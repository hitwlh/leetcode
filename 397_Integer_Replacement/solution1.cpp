class Solution {
public:
    int integerReplacement(int n) {
        int ret = 0;
        long long ln = n;
        while(ln != 1){
            if(ln==3) return ret+2;
            if(ln % 2){
                if((ln+1)%4) ln--;
                else ln++;
            }else ln /= 2;
            ret++;
        }
        return ret;
    }
};



//加一些位运算：
class Solution {
public:
    int integerReplacement(int n) {
        int ret = 0;
        long long ln = n;
        while(ln != 1){
            if(ln==3) return ret+2;
            if(ln & 1){
                if(ln & 2) ln++;
                else ln--;
            }else ln >>= 1;
            ret++;
        }
        return ret;
    }
};