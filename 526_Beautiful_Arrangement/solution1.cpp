class Solution {
public:
    int countArrangement(int N) {
        used.assign(N+1, false);
        n = N;
        cal(1);
        return ret;
    }
private:
    vector<bool> used;
    int ret = 0, n;
    void cal(int level){
        if(level > n){
            ret ++;
            return;
        }
        for(int i = 1; i <= n; i++){
            if(!used[i] && (i % level == 0 || level % i == 0)){
                used[i] = true;
                cal(level+1);
                used[i] = false;
            }
        }
    }
};