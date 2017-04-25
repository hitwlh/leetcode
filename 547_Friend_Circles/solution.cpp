class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int ret = 0, n = M.size();
        visit.assign(n, 1);
        for(int i = 0; i < n; i++){
            if(visit[i]){
                dfs(i, M);
                ret++;
            }
        }
        return ret;
    }
private:
    vector<int> visit;
    void dfs(int start, vector<vector<int>>& M){
        visit[start] = 0;
        int n = M.size();
        for(int i = 0; i < n; i++){
            if(M[start][i] && visit[i])
                    dfs(i, M);
        }
    }
};