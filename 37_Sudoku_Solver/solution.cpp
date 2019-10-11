class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(board[i][j] == '.') empty.push_back({i, j});
        dfs(board);
    }
private:
    int dfs_times = 0;
    vector<pair<int, int>> empty;
    bool dfs(vector<vector<char>>& board){
        if(dfs_times >= empty.size())
            return true;
        int x = empty[dfs_times].first, y = empty[dfs_times].second;
        for(char c = '1'; c <= '9'; c++){
            board[x][y] = c;
            if(valid(x, y, board)){
                dfs_times++;
                if(dfs(board)){
                    dfs_times--;
                    return true;
                }
                dfs_times--;
            }
        }
        board[x][y] = '.';
        return false;
    }
    bool valid(int x, int y, vector<vector<char>>& board){
        for(int k = 0; k < 9; k++){
            if(board[x][k] == board[x][y] && k != y) return false;
            if(board[k][y] == board[x][y] && k != x) return false;
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[x][y] == board[x/3*3+i][y/3*3+j] && (x != x/3*3+i || y != y/3*3+j))
                    return false;
            }
        }
        return true;
    }
};