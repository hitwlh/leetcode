class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> tmp(n, string(n, '.'));    
        N = n;
        nqueen(0, tmp);
        return ret;
    }
private:
    int N;
    vector<vector<string>> ret;
    void nqueen(int start_row, vector<string> qipan){
        for(int j = 0; j < N; j++){
            if(is_valid(qipan, start_row, j)){
                qipan[start_row][j] = 'Q';
                if(start_row + 1 == N)
                    ret.push_back(qipan);
                else
                    nqueen(start_row+1, qipan);
                qipan[start_row][j] = '.';
            }
        }
    }
    bool is_valid(vector<string> &tmp, int x, int y){
        for(int i = 0; i < N; i++)
            if(tmp[i][y] != '.') return false;
        for(int i = x-1, j = y-1; i >= 0 && j >= 0; i--, j--)
            if(tmp[i][j] != '.') return false;
        for(int i = x-1, j = y+1; i >= 0 && j < N; i--, j++)
            if(tmp[i][j] != '.') return false;
        return true;
    }
};