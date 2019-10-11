class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size(), n = board[0].size();
        dfs(board, click);
        return board;
    }
private:
    int m, n;
    vector<vector<int>> direction{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    bool valid(int i , int j){
        return i >= 0 and j >= 0 and i < m and j < n;
    }
    void dfs(vector<vector<char>>& board, vector<int>& click){
        int x = click[0], y = click[1], nums = 0;
        if(board[x][y] == 'M'){
            board[x][y] = 'X';
            return;
        }
        if(board[x][y] != 'E')
            return;
        for(int i = 0; i < 8; i++){
            if(valid(x + direction[i][0], y + direction[i][1]))
                if(board[x + direction[i][0]][y + direction[i][1]] == 'M') nums++;
        }
        if(nums > 0){
            board[x][y] = '0' + nums;
            return;
        }
        board[x][y] = 'B';
        for(int i = 0; i < 8; i++){
            int xx = x + direction[i][0], yy = y + direction[i][1];
            if(valid(xx, yy) && board[xx][yy] == 'E'){
                vector<int> fs = {xx, yy};
                dfs(board, fs);
            }
        }
    }
};