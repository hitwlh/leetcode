class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        int length = s1.length();
        vector<vector<vector<bool>>> table(length+1, vector<vector<bool>>(length, vector<bool>(length, 0)));
        for(int i = 0; i < length; i++)
            for(int j = 0; j < length; j++)
                table[1][i][j] = s1[i]==s2[j], table[0][i][j] = true;
        for(int l = 1; l <= length; l++)
            for(int i = 0; i+l <= length; i++)
                for(int j = 0; j+l <= length; j++)
                    for(int k = 1; k < l; k++){
                        if((table[k][i][j] && table[l-k][i+k][j+k]) ||(table[k][i][j+l-k] && table[l-k][i+k][j])){
                            table[l][i][j] = true;
                            break;
                        }
                        table[l][i][j] = false;
                    }
        return table[length][0][0];
    }
};