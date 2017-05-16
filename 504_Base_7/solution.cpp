class Solution {
public:
    string convertToBase7(int num) {
        if(!num) return "0";
        bool flag = false;
        if(num < 0){
            num = -num;
            flag = true;
        }
        string ret;
        while(num){
            char tmp = '0' + num % 7;
            num /= 7;
            ret = tmp + ret;
        }
        if(flag) ret = "-" + ret;
        return ret;
    }
};