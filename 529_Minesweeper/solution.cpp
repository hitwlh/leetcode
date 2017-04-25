class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int first = click[0], second = click[1];
        if(board[first][second] == 'M'){
            board[first][second] = 'X';
            return board;
        }
        int found = find(board, first, second, 'M');
        if(found > 0){
            found = found + '0';
            board[first][second] = found;
            return board;
        }
        board[first][second] = 'B';
        //cout << "["<< first << "][" << second << "]=" << found << endl;
        int i = first, j = second;
        vector<int> next_click;
        if(i-1 >=0){
            if(j-1 >= 0 && board[i-1][j-1] == 'E'){
                next_click = {i-1, j-1};
                updateBoard(board, next_click);
            }
            if(board[i-1][j] == 'E'){
                next_click = {i-1, j};
                updateBoard(board, next_click);
            }
            if(j+1 < board[0].size() && board[i-1][j+1] == 'E'){
                next_click = {i-1, j+1};
                updateBoard(board, next_click);
            }
        }
        if(j-1 >= 0 && board[i][j-1] == 'E'){
            next_click = {i, j-1};
            updateBoard(board, next_click);
        }
        if(j+1 < board[0].size() && board[i][j+1] == 'E'){
            next_click = {i, j+1};
            updateBoard(board, next_click);
        }
        if(i+1 < board.size()){
            if(j-1 >= 0 && board[i+1][j-1] == 'E'){
                next_click = {i+1, j-1};
                updateBoard(board, next_click);
            }
            if(board[i+1][j] == 'E'){
                next_click = {i+1, j};
                updateBoard(board, next_click);
            }
            if(j+1 < board[0].size() && board[i+1][j+1] == 'E'){
                next_click = {i+1, j+1};
                updateBoard(board, next_click);
            }
        }
        return board;
    }
private:
    int find(vector<vector<char>>& board, int i, int j, char c){
        int ret = 0;
        if(i-1 >=0){
            if(j-1 >= 0) if(board[i-1][j-1] == c) ret++;
            if(board[i-1][j] == c) ret++;
            if(j+1 < board[0].size()) if(board[i-1][j+1] == c) ret++;
        }
        if(j-1 >= 0) if(board[i][j-1] == c) ret++;
        if(j+1 < board[0].size()) if(board[i][j+1] == c) ret++;
        if(i+1 < board.size()){
            if(j-1 >= 0) if(board[i+1][j-1] == c) ret++;
            if(board[i+1][j] == c) ret++;
            if(j+1 < board[0].size()) if(board[i+1][j+1] == c) ret++;
        }
        return ret;
    }
};