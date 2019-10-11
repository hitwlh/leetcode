class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() and board[0].empty()) return word == "";
        Word = word, Board = board;
        m = board.size(), n = board[0].size(), length = word.length();
        map.assign(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(dfs(i, j, 0)) return true;
        return false;
    }
private:
    int m, n, length;
    vector<vector<bool>> map;
    string Word;
    vector<vector<char>> Board;
    bool dfs(int i, int j, int now){
        if(now >= length) return true;
        if(i < 0 or i >=m or j < 0 or j >= n or map[i][j] or Board[i][j] != Word[now]) return false;
        map[i][j] = true;
        if(dfs(i+1, j, now+1) or dfs(i-1, j, now+1) or dfs(i, j+1, now+1) or dfs(i, j-1, now+1)) return true;
        map[i][j] = false;
        return false;
    }
};