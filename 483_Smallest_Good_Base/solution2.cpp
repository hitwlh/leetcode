
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
        long long L = 2, R = k, d2 = n * (k-1) + 1;
        while(L < R){
            long long mid = L + (R - L) / 2, use_m = m;
            long double use = n;
            use = use * (k-1) + 1;
            while(use_m-- && use >= 1)
                use /= mid;
            if(use > 1) L = mid + 1;
            else R = mid;
        }
        long long d1 = L, use_m = m;
        while(use_m--)
            d1 *= L;
        if(d1 == d2) return L;
        return -1;
    }
};
