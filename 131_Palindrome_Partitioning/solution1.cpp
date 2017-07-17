class Solution {
public:
    vector<vector<string>> partition(string s) {
        my_s = s;
        vector<string> tmp;
        dfs(0, tmp);
        return ret;
    }
private:
    string my_s;
    vector<vector<string>> ret;
    void dfs(int start, vector<string> tmp){
        if(start >= my_s.length()){
            if(!tmp.empty())
                ret.push_back(tmp);
            return;
        }
        for(int i = start; i < my_s.length(); i++){
            if(is_palindrome(start, i)){
                tmp.push_back(my_s.substr(start, i-start+1));
                dfs(i+1, tmp);
                tmp.pop_back();
            }
        }
    }
    bool is_palindrome(int start, int end){
        while(start <= end && my_s[start] == my_s[end])
            start++, end--;
        return start > end;
    }
};