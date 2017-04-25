class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        dfs(s, 0, ')');
        return ret;
    }
private:
    void dfs(string s, int last, char c){
        int ch = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != '(' && s[i] != ')') continue;
            s[i] == c ? ch++ : ch--;
            if(ch <= 0) continue;
            for(int j = last; j <= i; j++){
                if(s[j] == c  && (j == last || s[j-1] != c)){
                    dfs(s.substr(0, j) + s.substr(j+1), j, c);
                }
            }
            return;//这个return容易自己写的时候漏掉了！！！
        }
        reverse(s.begin(), s.end());
        if(c == ')'){
            dfs(s, 0, '(');
            return;//这个return容易自己写的时候漏掉了！！！
        }
        ret.push_back(s);
    }
    vector<string> ret;
};