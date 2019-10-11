//这题要注意的就是反转之后可能溢出，溢出的话就返回0
class Solution {
public:
    int reverse(int x) {
        long long ret = 0;
        bool flag = (x >= 0);
        x = fabs(x);
        while(x){
            ret = ret*10 + x%10;
            x /= 10;
        }
        ret = flag ? ret : -ret;
        if(ret > INT_MAX || ret < INT_MIN) return 0;
        return (int)ret;
    }
};