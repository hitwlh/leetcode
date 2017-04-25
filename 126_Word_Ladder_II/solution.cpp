class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> que[2];
        my_beginWord = beginWord;
        unordered_map<string, bool> mymap;
        for(auto i: wordList) mymap[i] = true;
        que[0].insert(que[0].end(), beginWord);
        int uf = 1, sf = 0;
        while(!que[1-uf].empty()){
            string front = *(que[1-uf].begin());
            if(front == endWord)
                break;
            if(sf == 0){//一次把整个队列的串都标记为访问过，而且最开始来做一次标记就ok了，否则耗时长
                for (auto it = que[1-uf].begin(); it != que[1-uf].end(); ++it)
                    mymap[*it] = false;
                sf = 1;
            }
            que[1-uf].erase(que[1-uf].begin());
            for(int i = 0; i < front.size(); i++){
                char m = front[i];
                for(char c = 'a'; c <= 'z'; c++){
                    if(c != m){
                        front[i] = c;
                        if(mymap.find(front) != mymap.end() && mymap[front] == true){
                            
                            string s = front;
                            s[i] = m;
                            vector<string> old = mymap2[front];
                            old.push_back(s);
                            mymap2[front] = old;
                            que[uf].insert(que[uf].end(), front);
                        }
                    }
                }
                front[i] = m;
            }
            if(que[1-uf].empty()){
                sf = 0;
                uf = 1 - uf;
            }
        }
        vector<string> path(1, endWord);
        dfs(path);
        return ret;
    }
private:
    string my_beginWord;
    void dfs(vector<string> path){
        if(path[0] == my_beginWord){
            ret.push_back(path);
            return;
        }
        vector<string> fathers = mymap2[path[0]];
        for(int i = 0; i < fathers.size(); i++){
            path.insert(path.begin(), fathers[i]);
            dfs(path);
            path.erase(path.begin());
        }
    }
    unordered_map<string, vector<string>> mymap2;
    vector<vector<string>> ret;
};