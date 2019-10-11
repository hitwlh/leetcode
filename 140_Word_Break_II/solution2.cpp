class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> words;
        S = s;
        results.assign(s.length()+1, vector<int>());
        for(auto word: wordDict) words[word] = true;
        for(int i = 0; i < s.length(); i++){
            if(words.find(s.substr(0, i+1)) != words.end())
                results[i+1].push_back(0);
            for(int j = 0; j < i; j++){
                if(not results[j+1].empty() && words.find(s.substr(j+1, i-j)) != words.end())
                    results[i+1].push_back(j+1);
            }
        }
        dfs("", S.length());
        return ret;
    }
private:
    string S;
    vector<vector<int>> results;
    vector<string> ret;
    void dfs(string path, int now){
        if(now == 0) ret.push_back(path);
        for(int i = 0; i < results[now].size(); i++){
            if(now == S.length())
                dfs(S.substr(results[now][i], now-results[now][i]) + path, results[now][i]);
            else
                dfs(S.substr(results[now][i], now-results[now][i]) + " " + path, results[now][i]);
        }
    }
};