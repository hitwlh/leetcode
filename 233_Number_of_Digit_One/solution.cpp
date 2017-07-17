class Solution {
public:
    int countDigitOne(int n) {
        reg[0] = 0, reg[1] = 1, sum[0] = 0, sum[1] = 1;
        for(int i = 2; i < 12; i++){
            reg[i] = pow(10, i-1) + 9 * sum[i-1];
            sum[i] = sum[i-1] + reg[i];
        }
        return cal(n);
    }
private:
    int cal(int n){
        if(n < 10) return n >= 1;
        string s = to_string(n);
        int ret = 0;
        ret += (s[0] - '0') * sum[s.length()-1];
        if(s[0] == '1')
            ret += n - pow(10, s.length()-1) + 1;
        else
            ret += pow(10, s.length()-1);
        return ret + cal(n - (s[0] - '0') * pow(10, s.length()-1));
    }
    long reg[12], sum[12];
};