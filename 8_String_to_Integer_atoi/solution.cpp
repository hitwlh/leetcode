class Solution {
public:
    int myAtoi(string str) {
    long long cur=0;
    int num=0,i=0;
    bool flag = true;
    while(i < str.length() and (str[i] =='\0' or str[i]==' '))
        i++;//开头空格舍弃
    if(i < str.length() and (str[i]=='-' or str[i] == '+'))
        flag = (str[i++] == '+');
    for(; i < str.length() and isdigit(str[i]); i++)
    {
        if(not flag){
            cur = cur*10-(str[i]-'0');
            if(cur < INT_MIN) 
                return INT_MIN;
        }
        else{
            cur = cur*10+(str[i]-'0');
            if(cur > INT_MAX)
                return INT_MAX;
        }
    }
    num=(int)cur;
    return num;
    }
};