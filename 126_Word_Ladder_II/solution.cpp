class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> que[2];
        BeginWord = beginWord;
        for(auto i: wordList) words[i] = true, visited[i] = true;
        que[0] = {beginWord};
        int now = 0;
        visited[beginWord] = false;
        while(!que[now].empty() or !que[1-now].empty()){
            if(que[now].empty()){
                for(auto i: que[1-now])
                    words[i] = false;
                now = 1-now;
            }
            string front = que[now].front();
            if(front == endWord) break;
            que[now].erase(que[now].begin());
            string push = front;
            for(int i = 0; i < front.size(); i++){
                for(char c = 'a'; c <= 'z'; c++){
                    if(c != front[i]){
                        push[i] = c;
                        if(words.find(push) != words.end() and words[push] == true){
                            if(father.find(push) == father.end()) father[push] = {front};
                            else father[push].push_back(front);
                            if(visited[push] == true){
                                visited[push] = false;
                                que[1-now].push_back(push);
                            }
                        }
                    }
                }
                push[i] = front[i];
            }
        }
        vector<string> path = {endWord};
        dfs(path);
        return ret;
    }
private:
    vector<vector<string>> ret;
    unordered_map<string, bool> words, visited;
    unordered_map<string, vector<string>> father;
    string BeginWord;
    void dfs(vector<string> path){
        if(path[0] == BeginWord){
            ret.push_back(path);
            return;
        }
        vector<string> fa = father[path[0]];
        for(auto i: fa){
            path.insert(path.begin(), i);
            dfs(path);
            path.erase(path.begin());
        }
    }
};