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
private:
    node *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */