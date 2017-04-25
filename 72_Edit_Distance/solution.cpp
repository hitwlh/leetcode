class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1=="") return word2.length();
        if(word2=="") return word1.length();
        vector<int> tmp;
        tmp.assign(word2.length()+1, 0);
        len.assign(word1.length()+1, tmp);
        len[0][0] = 0;
        for(int i = 1; i < len[0].size(); i++) len[0][i] = i;
        for(int i = 1; i < len.size(); i++) len[i][0] = i;
        for(int i = 0; i < word1.length(); i++){
            for(int j = 0; j < word2.length(); j++){
                if(word1[i] == word2[j]) len[i+1][j+1] = len[i][j];
                else len[i+1][j+1] = 1 + min(len[i][j], min(len[i][j+1], len[i+1][j]));
            }
        }
        return len[word1.length()][word2.length()];
    }
private:
    vector<vector<int>> len;
};