class Solution {
public:
    int myAtoi(string str) {
    long long cur=0;
    int num=0,i=0;
    int flag1=0;
    while(str[i]!='\0' && str[i]==' ')
        i++;//开头空格舍弃
    if(str[i]=='-'){
        flag1++;
        i++;
    }
    else if(str[i]=='+')
        i++;
    for(; isdigit(str[i]); i++)
    {
        if(flag1==1){
            cur=cur*10-(str[i]-'0');
            if(cur < INT_MIN) 
                return INT_MIN;
        }
        else{
            cur=cur*10+(str[i]-'0');
            if(cur > INT_MAX)
                return INT_MAX;
        }
    }
    num=(int)cur;
    return num;
    }
};