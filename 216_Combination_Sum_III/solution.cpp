class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        dfs(path, 1, n, k);
        return ret;
    }
private:
    vector<vector<int>> ret;
    void dfs(vector<int> &path, int start, int target, int k){
        if(target == 0){
            if(k == 0) ret.push_back(path);
            return;
        }
        if(k == 0 or target < start)
            return;
        for(int i = start; i <= 9; i++){
            path.push_back(i);
            dfs(path, i+1, target - i, k-1);
            path.pop_back();
        }
    }
};