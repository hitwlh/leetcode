class Trie
{
    public:
    Trie *next[26];
    bool flag;
    Trie():flag(false){
        for(int i=0;i<26;i++)
            next[i] = NULL;
    } 
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie *p = root;
        for(auto i: word){
            if(!p->next[i - 'a'])
                p->next[i-'a'] = new Trie();
            p = p->next[i-'a'];
        }
        p->flag = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return my_search(word, 0, root);
    }
    bool my_search(string &word, int index, Trie *p) {
        if(!p) return false;
        for(int i = index; i < word.length(); i++){
            if(word[i] != '.'){
                if(!p->next[word[i] - 'a'])
                    return false;
                p = p->next[word[i] - 'a'];
            }else{
                for(int j = 0; j < 26; j++){
                    if(p->next[j])
                        if(my_search(word, i+1, p->next[j]))
                            return true;
                }
                return false;
            }
        }
        return p->flag;
    }
private:
    Trie *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */