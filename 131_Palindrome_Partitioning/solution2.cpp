class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> tmp;
        ret.assign(s.length(), tmp);
        flag.assign(s.length(), false);
        my_s = s;
        dfs(0);
        return ret[0];
    }
private:
    vector<vector<vector<string>>> ret;
    vector<bool> flag;
    string my_s;
    void dfs(int start){
        if(flag[start] == true) return ;
        for(int i = start; i < my_s.length(); i++){
            if(is_palindrome(start, i)){
                if(i+1 == my_s.length()){
                    //vector<vector<string>> tt;
                    vector<string> ttt;
                    ttt.push_back(my_s.substr(start, i-start+1));
                    //tt.push_back(ttt);
                    ret[start].push_back(ttt);
                }else{
                    if(flag[i+1] == false)
                        dfs(i+1);
                    for(int j = 0; j < ret[i+1].size(); j++){
                        vector<string> use = ret[i+1][j];
                        use.insert(use.begin(), my_s.substr(start, i-start+1));
                        ret[start].push_back(use);
                    }
                }
            }
        }
        flag[start] = true;     
    }
    bool is_palindrome(int start, int end){
        while(start <= end && my_s[start] == my_s[end])
            start++, end--;
        return start > end;
    }
};