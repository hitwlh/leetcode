//如果除数在左边循环，直接放弃，因为左边跨越了小数点，有点难处理，反正只要出现循环，在右边能第一次探测到就ok了
class Solution {
public:
    string fractionToDecimal(long numerator, long denominator) {
        bool flag = false;
        if((numerator >= 0 && denominator >0) || (numerator <= 0 && denominator < 0)) flag = true;
        long N = abs(numerator), D = abs(denominator);
        if(N % D == 0){
            return (flag ? "" : "-") + to_string(N/D);
        }
        map<long, int> mymap;//mymap[numerator] = index
        string ret = (flag ? "" : "-") + to_string(N/D) + ".";
        int now = ret.length();
        long i_N = (N - N / D * D) * 10;//*10是为了借位
        while(mymap.find(i_N) == mymap.end()){
            if(i_N % D == 0){
                ret += to_string(i_N / D);
                return ret;
            }
            mymap[i_N] = now;
            ret += to_string(i_N / D);
            now++;
            i_N = (i_N - i_N / D * D) * 10;
        }
        ret.insert(ret.begin() + mymap[i_N], '(');
        ret += ")";
        return ret;
    }
};