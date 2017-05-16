class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        string ret;
        if(num > 0){
            while(num){
                int numb = num % 16;
                char c;
                num /= 16;
                if(numb < 10) c = numb + '0';
                else c = numb - 10 + 'a';
                ret = c + ret;
            }
            return ret;
        }
        else{
            num = (1 << 30) + num + (1 << 30);
            string s1 = toHex(num);
            if(s1.length() <= 7){
                while(s1.length() < 7)
                    s1 = '0' + s1;
                s1 = '8' + s1;
                return s1;
            }else{
                if(s1[0] <= '1') s1[0] = s1[0] + 8;
                else s1[0] = s1[0] - '2' + 'a';
                return s1;
            }
        }
    }
};