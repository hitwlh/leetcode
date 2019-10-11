class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        vector<int> number(n, 0), f(n, 1);
        for(int i = 0; i < n; i++){
            number[i] = i+1;
            if(i > 1) f[i] = f[i-1] * i;
        }
        while(n){
            ret += to_string(number[(k-1)/f[n-1]]);//1,2,3,...(n-1)! -> 0
            number.erase(number.begin()+(k-1)/f[n-1]);
            k = (k-1) % f[n-1] + 1;//1,2,3,...(n-1)! -> 1,2,3,...(n-1)!
            n--;
        }
        return ret;
    }
};