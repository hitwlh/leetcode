class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = atoll(n.c_str());
        for(int m = log(num + 1) / log(2); m >= 1; m--){
            long long k = succ(num, m);
            if(k > 1) return to_string(k);
        }
        return "";
    }
private:
    long long succ(long long n, long long m){
        long long k = pow(n, (long double)1 / m);
        if(pow(k, m) == n) k--;
        long long d1 = k;
        //m++;
        while(m--)
            d1 *= k;
        long long d2 = n * (k-1);
        if(d1 - 1 == d2)
            return k;
        return -1;
    }
};






class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = atoll(n.c_str());
        for(int m = log(num + 1) / log(2); m >= 1; m--){
            long long k = succ(num, m);
            if(k > 1) return to_string(k);
        }
        return "";
    }
private:
    long long succ(long long n, long long m){
        long long k = pow(n, (long double)1 / m);
        if(pow(k, m) == n) k--;
        long long d1 = 1;
        //m++;
        while(m--)
            d1 = d1 * k + 1;
        long long d2 = n;
        if(d1 == d2)
            return k;
        return -1;
    }
};