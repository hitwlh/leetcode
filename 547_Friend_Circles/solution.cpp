class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int ret = 0;
        n = M.size();
        visit.assign(n, true);
        for(int i = 0; i < n; i++){
            if(visit[i]){
                dfs(i, M);
                ret++;
            }
        }
        return ret;
    }
private:
    vector<bool> visit;
    int n;
    void dfs(int start, vector<vector<int>>& M){
        visit[start] = false;
        for(int i = 0; i < n; i++){
            if(M[start][i] && visit[i])
                dfs(i, M);
        }
    }
};