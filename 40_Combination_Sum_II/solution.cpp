class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(path, candidates, 0, target);
        return ret;
    }
private:
    vector<vector<int>> ret;
    void dfs(vector<int> &path, vector<int>& candidates, int start, int target){
        if(target == 0){
            ret.push_back(path);
            return;
        }
        if(start >= candidates.size() || target < 0) return;
        path.push_back(candidates[start]);
        dfs(path, candidates, start+1, target - candidates[start]);
        path.pop_back();
        for(int i = start+1; i < candidates.size(); i++){
            if(candidates[i] == candidates[i-1]) continue;//考虑1225的组合，如果2能用多次，就会有125 125出现多次
            path.push_back(candidates[i]);
            dfs(path, candidates, i+1, target - candidates[i]);
            path.pop_back();
        }
    }
};