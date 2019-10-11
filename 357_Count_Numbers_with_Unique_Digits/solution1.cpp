class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        used.assign(10, false);
        for(int N = 1; N <= n; N++)
            for(int i = 1; i <= 9; i++){
                used[i] = true;
                dfs(1, N);
                used[i] = false;
            }
        return ret+1;
    }
private:
    vector<bool> used;
    int ret = 0;
    void dfs(int now, int n){
        if(now < n){
            for(int i = 0; i < 10; i++){
                if(!used[i]){
                    used[i] = true;                    
                    dfs(now+1, n);
                    used[i] = false;
                }
            }
        }else ret++;
    }
};