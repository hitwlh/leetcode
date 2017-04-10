class Solution {
public:
    int reverse(int x) {
        long long ret = 0;
        int max = 0x7fffffff,min = 0x80000000;
        int flag = 0;
        if(x>=0)
            flag = 1;
        else{
            x = 0-x;
            flag = -1;
        }
        while(x)
        {
            ret = ret*10 + x%10;
            x /= 10;
        }
        if(ret > max)
            return 0;
        else if(ret < min)
            return 0;
        return (int)ret*flag;
    }
};