class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m == 0) return ;
        int n = board[0].size();
        vector<vector<int>> vec(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int N = num(board, i, j);
                if(N < 2 || N > 3) vec[i][j] = 0;
                else if(N == 2) vec[i][j] = board[i][j];
                else vec[i][j] = 1;
            }
        }
        board = vec;
        return ;
    }
private:
    int num(vector<vector<int>>& board, int x, int y){
        int ret = 0;
        int direction[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for(int i = 0; i < 8; i++)
            if(x+direction[i][0] >= 0 && x+direction[i][0] < board.size() && 
               y+direction[i][1] >= 0 && y+direction[i][1] < board[0].size())
                ret += board[x+direction[i][0]][y+direction[i][1]];
        return ret;
    }
};