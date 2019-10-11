class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        qipan.assign(n, string(n, '.'));
        N = n;
        dfs(0);
        return ret;
    }
private:
    vector<vector<string>> ret;
    vector<string> qipan;
    int N;
    void dfs(int line){
        if(line == N){
            ret.push_back(qipan);
            return;
        }
        for(int i = 0; i < N; i++){
            qipan[line][i] = 'Q';
            if(isvalid(line, i))
                dfs(line+1);
            qipan[line][i] = '.';
        }
    }
    bool isvalid(int x, int y){
        for(int i = 0; i < x; i++)
            if(qipan[i][y] == 'Q')
                return false;
        for(int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
            if(qipan[i][j] == 'Q')
                return false;
        for(int i = x - 1, j = y + 1; i >= 0 && j < N; i--, j++)
            if(qipan[i][j] == 'Q')
                return false;
        return true;
    }
};