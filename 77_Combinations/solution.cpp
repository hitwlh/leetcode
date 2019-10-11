class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        N = n, K = k;
        generate(1, tmp);
        return ret;
    }
private:
    vector<vector<int>> ret;
    int K, N;
    void generate(int start, vector<int> tmp){
        if(tmp.size() == K){
            ret.push_back(tmp);
            return;
        }
        for(int i = start; i <= N; i++){
            tmp.push_back(i);
            generate(i+1, tmp);
            tmp.pop_back();
        }
    }
};