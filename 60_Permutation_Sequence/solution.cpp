class Solution {
public:
    string getPermutation(int n, int k) {
        fac(n);
        string s;
        least[0] = 0;
        for(int i = 1; i <= n; i++)
            least[i] = 1;
        while(k){
            s = s + get((k-1) / fac_array[n-1] + 1);
            k = k % fac_array[n-1];
            if(!k) k = fac_array[n-1];
            n--;
            if(!n) break;
        }
        return s;
    }
private:
    int fac_array[10], least[10];
    char get(int now){
        int i = 1;
        while(now){
            if(least[i] > 0) now--;
            if(!now) break;
            i++;
        }
        least[i] = -1;
        return '0' + i;
    }
    void fac(int n){
        fac_array[0] = 1;
        fac_array[1] = 1;
        int ret = 1;
        for(int i = 2; i <= n; i++){
            ret *= i;
            fac_array[i] = ret;
        }
    }
};