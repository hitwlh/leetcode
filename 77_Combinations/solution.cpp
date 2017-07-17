class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        generate(1, n, k, tmp);
        return ret;
    }
private:
    vector<vector<int>> ret;
    void generate(int start, int n, int k, vector<int> tmp){
        if(tmp.size() == k){
            ret.push_back(tmp);
            return;
        }
        for(int i = start; i <= n; i++){
            tmp.push_back(i);
            generate(i+1, n, k, tmp);
            tmp.pop_back();
        }
    }
};