class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> able(s.length(), false);
        unordered_map<string, bool> words;
        for(auto word: wordDict) words[word] = true;
        for(int i = 0; i < s.length(); i++){
            if(words.find(s.substr(0, i+1)) != words.end()){
                able[i] = true;
                continue;
            }
            for(int j = 0; j < i; j++){
                if(able[j] && words.find(s.substr(j+1, i-j)) != words.end()){
                    able[i] = true;
                    break;
                }
            }
        }
        return able.back();
    }
};