class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return ;
        for(int i = 0; i < board[0].size(); i++)
            my_queue.push({0, i}), my_queue.push({board.size()-1, i});
        for(int i = 1; i+1 < board.size(); i++)
            my_queue.push({i, 0}), my_queue.push({i, board[i].size()-1});
        while(!my_queue.empty()){
            int m1 = my_queue.front().first, m2 = my_queue.front().second;
            my_queue.pop();
            if(isvalid(m1, m2, board)){
                my_queue.push({m1-1, m2}),my_queue.push({m1+1, m2}),my_queue.push({m1, m2-1}),my_queue.push({m1, m2+1});
                board[m1][m2] = '1';
            }
        }
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                if(board[i][j] == 'O') board[i][j] = 'X';
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                if(board[i][j] == '1') board[i][j] = 'O';
    }
private:
    queue<pair<int,int>> my_queue;
    bool isvalid(int i, int j, vector<vector<char>>& board){
        return i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == 'O';
    }
};