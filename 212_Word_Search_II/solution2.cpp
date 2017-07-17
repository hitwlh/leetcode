class node
{
    public:
    node *next[26];
    bool flag;
    node():flag(false){
        for(int i=0;i<26;i++)
            next[i] = NULL;
    } 
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node *p = root;
        for(auto i: word){
            if(!p->next[i - 'a'])
                p->next[i-'a'] = new node();
            p = p->next[i-'a'];
        }
        p->flag = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node *p = root;
        for(auto i: word){
            if(!p->next[i-'a'])
                return false;
            p = p->next[i-'a'];
        }
        return p->flag;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node *p = root;
        for(auto i: prefix){
            if(!p->next[i-'a'])
                return false;
            p = p->next[i-'a'];
        }
        return true;
    }
    bool del(node* now, string prefix) {
        if(!now->next[prefix[0]-'a'])
            return false;
        if(prefix.size() == 1){
            now->next[prefix[0]-'a']->flag = false;
            for(int i = 0; i < 26; i++)
                if(now->next[prefix[0]-'a']->next[i]) return false;
            delete now->next[prefix[0]-'a'];
            now->next[prefix[0] - 'a'] = NULL;
            return true;
        }
        if(del(now->next[prefix[0] - 'a'], prefix.substr(1))){
            for(int i = 0; i < 26; i++)
                if(now->next[prefix[0]-'a']->next[i]) return false;
            delete now->next[prefix[0]-'a'];
            now->next[prefix[0] - 'a'] = NULL;
            return true;
        }
        return false;
    }
    

    node *root;
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || board[0].empty()) return ret;
        for(auto i: words)
            T.insert(i);
        flag.assign(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(board, i, j, "");
            }
        }
        return ret;
    }
private:
    vector<string> ret;
    Trie T;
    int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<bool>> flag;
    void dfs(vector<vector<char>>& board, int x, int y, string word){
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return;
        if(flag[x][y]) return;
        word += board[x][y];
        if(!T.startsWith(word)) return;
        if(T.search(word)){
            ret.push_back(word);
            T.del(T.root, word);
        }
        flag[x][y] = true;
        for(int i = 0; i < 4; i++)
            dfs(board, x+d[i][0], y+d[i][1], word);
        flag[x][y] = false;
    }
};