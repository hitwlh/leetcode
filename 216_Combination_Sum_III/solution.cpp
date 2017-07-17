class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nul;
        K = k;
        com(nul, 1, n, 0);
        return ret;
    }
private:
    vector<vector<int>> ret;
    int K;
    void com(vector<int> inh, int start, int target, int num){
        if(K <= num) return;
        for(int i = start; i < 10; i++){
            if(i < target){
                inh.push_back(i);
                com(inh, i+1, target-i, num+1);
                inh.pop_back();
            }
            else{
                if(i == target && num + 1 == K){
                    inh.push_back(i);
                    ret.push_back(inh);
                }
                break;
            }
        }
    }
};