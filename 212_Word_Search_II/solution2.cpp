class node{
public:
    node *next[26];
    bool flag;
    node():flag(false){
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};
class Trie{
public:
    node *root;
    Trie(){
        root = new node();
    }
    void insert(string word){
        node *t = root;
        for(int i = 0; i < word.length(); i++){
            if(!t->next[word[i]-'a'])
                t->next[word[i]-'a'] = new node();
            t = t->next[word[i]-'a'];
        }
        t->flag = true;
    }
    bool del(node *p, string prefix){
        if(p->next[prefix[0] - 'a'] == NULL)
            return false;
        if(prefix.length() == 1){
            p->next[prefix[0]-'a']->flag = false;
            for(int i = 0; i < 26; i++){
                if(p->next[prefix[0]-'a']->next[i])
                    return false;
            }
            delete p->next[prefix[0]-'a'];
            p->next[prefix[0]-'a'] = NULL;
            return true;
        }
        if(del(p->next[prefix[0]-'a'], prefix.substr(1))){
            for(int i = 0; i < 26; i++)
                if(p->next[i]) return false;
            delete p->next[prefix[0]-'a'];
            p->next[prefix[0]-'a'] = NULL;
            return true;
        }
        return false;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(), n = board[0].size();
        visited.assign(m, vector<bool>(n, false));
        boar = board;
        for(auto word: words)
            root->insert(word);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                dfs(root->root, i, j);
        return ret;
    }
private:
    vector<vector<bool>> visited;
    vector<vector<char>> boar;
    vector<string> ret;
    string path;
    int m, n;
    Trie *root = new Trie();
    void dfs(node *p, int i, int j){
        if(!p || i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || p->next[boar[i][j]-'a'] == NULL)
            return;
        path += boar[i][j];
        //pt = p->next[boar[i][j]-'a'], 后面用pt的话，会报错，很奇怪！
        if(p->next[boar[i][j]-'a']->flag){
            ret.push_back(path);
            root->del(root->root, path);
        }
        visited[i][j] = true;
        dfs(p->next[boar[i][j]-'a'], i+1, j);
        dfs(p->next[boar[i][j]-'a'], i-1, j);
        dfs(p->next[boar[i][j]-'a'], i, j+1);
        dfs(p->next[boar[i][j]-'a'], i, j-1);
        path.pop_back();
        visited[i][j] = false;
    }
};