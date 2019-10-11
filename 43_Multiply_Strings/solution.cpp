class Solution {
public:
    string multiply(string num1, string num2) {
        string use = "", ret = "";
        for(int i = num2.length()-1; i >= 0; i--){
            string tmps = multiplychar(num1, num2[i]);
            tmps += use;
            use = use + "0";
            ret = plus(ret, tmps);
        }
        if(ret[0] == '0') return "0";
        return ret;
    }
private:
    string multiplychar(string &num1, char num2){
        int mul = num2 - '0', carry = 0;
        string ret;
        for(int i = num1.length() - 1; i >= 0; i--){
            int now = (num1[i] - '0') * mul + carry;
            carry = now / 10;
            ret = (char)(now % 10 + '0') + ret;
        }
        if(carry > 0) ret = (char)(carry + '0') + ret;
        return ret;
    }
    string plus(string &num1, string &num2){
        if(num2.length() > num1.length())
            swap(num1, num2);
        string ret;
        int carry = 0, i = num2.length()-1, j = num1.length()-1;
        while(i >= 0){
            int s1 = num1[j--] - '0' + num2[i--] - '0' + carry;
            carry = s1 / 10;
            ret = (char)(s1 % 10 + '0') + ret;
        }
        while(carry > 0){
            int s1 = carry;
            if(j >= 0)
                s1 += num1[j--] - '0';
            carry = s1 / 10;
            ret = (char)(s1 % 10 + '0') + ret;
        }
        return num1.substr(0, j+1) + ret;
    }
};