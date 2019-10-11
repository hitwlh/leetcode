class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        dfs(vector<string>(), s);
        return ret;
    }
private:
    vector<string> ret;
    void dfs(vector<string> path, string s){
        if(s == ""){
            if(path.size() == 4) ret.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            return ;
        }
        if(path.size() == 4) return;
        if(s.length() >= 1 and valid(s.substr(0, 1))){
            path.push_back(s.substr(0, 1));
            dfs(path, s.substr(1));
            path.pop_back();
        }
        if(s.length() >= 2 and valid(s.substr(0, 2))){
            path.push_back(s.substr(0, 2));
            dfs(path, s.substr(2));
            path.pop_back();
        }
        if(s.length() >= 3 and valid(s.substr(0, 3))){
            path.push_back(s.substr(0, 3));
            dfs(path, s.substr(3));
            path.pop_back();
        }
        return ;
    }
    bool valid(string tmp){
        if(tmp == "0") return true;
        if(tmp[0] == '0') return false;
        return atoi(tmp.c_str()) > 0 and atoi(tmp.c_str()) <= 255;
    }
};