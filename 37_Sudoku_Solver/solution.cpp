class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        my_board = board;
        vector<int> tmp;
        if(board[0][0] == '.') {tmp.push_back(0), tmp.push_back(0);}
        tmp = find_next(0, 0);
        my_solveSudoku(tmp[0], tmp[1]);
        board = my_board;
    }
private:
    vector<vector<char>> my_board;
    bool my_solveSudoku(int start_x, int start_y) {
        if(start_x == 9 && start_y == 0) return true;
        for(char c = '1'; c <= '9' ; c++){
            my_board[start_x][start_y] = c;
            if(valid(start_x, start_y)){
                vector<int> tmp = find_next(start_x, start_y);
                if(my_solveSudoku(tmp[0], tmp[1])){
                    return true;
                }
                else{
                    my_board[start_x][start_y] = '.';
                }
            }
            else
                my_board[start_x][start_y] = '.';
        }
        return false;
    }
    vector<int> find_next(int x, int y){
        int i = x,j = y;
        for(i; i<9; i++, j = 0)
            for(; j<9; j++)
                if(my_board[i][j] == '.') return {i,j};
        return {i, j};
    }
    bool valid(int i, int j){
        //map<char, bool> my_map1, my_map2, my_map3;
        for(int k = 0; k < 9; k++){
                if(my_board[i][k] == my_board[i][j] && k != j) return false;
                if(my_board[k][j] == my_board[i][j] && k != i) return false;
        }
        int start_x = (i/3)*3, start_y = (j/3)*3;
        for(int k = start_x; k<start_x+3; k++){
            for(int l = start_y; l<start_y+3; l++){
                    if(my_board[k][l] == my_board[i][j] && !(k==i && l==j)) return false;
            }
        }
        return true;
    }
};