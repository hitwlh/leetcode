class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m == 0) return ;
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int N = num(board, i, j);
                //0: died->died, 1: died->live, 2: live->died, 3: live->live
                if(N < 2 || N > 3) board[i][j] *= 2;//0->0, 1->2
                else if(N == 2) board[i][j] *= 3;//0->0, 1->3
                else board[i][j] = board[i][j]*2 + 1;//0->1, 1->3
            }
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                board[i][j] %= 2;
        return ;
    }
private:
    int num(vector<vector<int>>& board, int x, int y){
        int ret = 0;
        int direction[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for(int i = 0; i < 8; i++){
            if(x+direction[i][0] >= 0 && x+direction[i][0] < board.size() && 
               y+direction[i][1] >= 0 && y+direction[i][1] < board[0].size())
                //这里要注意分2类情况，因为前面处理过的是0/1/2/3表示死活，而后面没处理过的，死活还是由0/1判断
                if(direction[i][0] > 0 || (direction[i][0] == 0 && direction[i][1] > 0 ))
                    ret += board[x+direction[i][0]][y+direction[i][1]];
                else
                    ret += (board[x+direction[i][0]][y+direction[i][1]] > 1);
        }
        return ret;
    }
};