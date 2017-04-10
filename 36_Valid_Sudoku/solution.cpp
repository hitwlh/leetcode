class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char, int> my_map1, my_map2;
        for(int i = 0; i < board.size(); i++){
            my_map1.clear();
            my_map2.clear();
            for(int j = 0; j< board[i].size();j++){
                if(board[i][j] != '.'){
                    if(my_map1.count(board[i][j]) > 0) return false;
                    else my_map1[board[i][j]] = 1;
                   }
                if(board[j][i] != '.'){
                       if(my_map2.count(board[j][i]) > 0) return false;
                        else my_map2[board[j][i]] = 1;
                   }
            }
        }
        for(int i = 0; i < board.size(); i+=3){
            for(int j = 0; j < board.size(); j+=3){
                my_map1.clear();
                int index_x = i, index_y = j;
                for(int k = index_x; k < board.size() && k < index_x+3; k++){
                    for(int l = index_y; l < board.size() && l < index_y + 3; l++){
                        if(board[k][l] != '.'){
                            if(my_map1.count(board[k][l]) > 0) return false;
                            else my_map1[board[k][l]] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
};