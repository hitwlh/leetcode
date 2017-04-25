class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        my_s = s;
        for(int i = 0; i < my_s.length(); i++){
            index[0] = i;
            if(isvalid(my_s.substr(0, i+1)))
                dfs(i+1, 1);
            else break;
        }
        return ret;
    }
private:
    string my_s;
    int index[4];
    vector<string> ret;
    void dfs(int start_index, int now) {
        for(int i = start_index; i < my_s.length(); i++){
            if(isvalid(my_s.substr(start_index, i - start_index + 1))){
                index[now] = i;
                if(now < 3)
                    dfs(i+1, now+1);
                else{
                    if(i + 1 == my_s.length()){
                        string res = my_s;
                        for(int i = 0; i < 3 ; i++)
                            res = res.substr(0, index[i] + 1 + i) + '.' + res.substr(index[i] + 1 + i);
                        ret.push_back(res);
                    }
                }
            }
            else break;
        }
    }
    bool isvalid(string s){
        if(s.length()>1 && s[0] == '0') return false;
        long n = atol(s.c_str());
        return n >= 0 && n <= 255;
    }
};