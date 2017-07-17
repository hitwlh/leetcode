class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        map<string, int> mymap;
        for(int i = 0; i < words.size(); i++){
            if(mymap[words[i]] != 1 && exist(board, words[i]))
                ret.push_back(words[i]);
            mymap[words[i]] = 1;
        }
        return ret;
    }
private:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty() || word == "") return false;
        my_word = word;
        flag =  new bool*[board.size()];
        for(int i = 0; i < board.size(); i++)
            flag[i] = new bool[board[0].size()];
        set_flag_true(board.size(), board[0].size());
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(dfs(board, i, j, 0)) return true;
            }
        }
        return false;
    }
    bool **flag;
    string my_word;
    bool dfs(vector<vector<char>>& board, int i, int j, int start_index){
        if(flag[i][j] && board[i][j] == my_word[start_index]){
            if(start_index+1 == my_word.length())
                return true;
            flag[i][j] = false;
            if(i+1 < board.size() && j < board[i].size())
                if(dfs(board, i+1, j, start_index+1))
                    return true;
            if(i-1 < board.size() && j < board[i].size())
                if(dfs(board, i-1, j, start_index+1))
                    return true;
            if(i < board.size() && j+1 < board[i].size())
                if(dfs(board, i, j+1, start_index+1))
                    return true;
            if(i < board.size() && j-1 < board[i].size())
                if(dfs(board, i, j-1, start_index+1))
                    return true;
            flag[i][j] = true;
            return false;
        }
        return false;
    }
    void set_flag_true(int m, int n){
        for(int i = 0; i < m; i++)
            memset(flag[i], true, n*sizeof(bool));
    }
};