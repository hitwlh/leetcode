struct interval {
     int start;
     int end;
     interval(int x, int y) : start(x), end(y){}
 };
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto s: wordDict) mymap[s] = true;
        my_s = s;
        vector<vector<interval>> v;
        path.assign(s.length(), v);
        ok.assign(s.length(), -1);
        vector<string> ret;
        old_dp(s.length() -1);
        if(ok[s.length()-1] == 0)
            return ret;
        ok.assign(s.length(), -1);
        int size = ok.size();
        dp(s.length() -1);
        
        for(int i = 0; i < path[size-1].size(); i++){
            string push;
            if(path[size-1][i].size() >= 1)
                push = s.substr(path[size-1][i][0].start, path[size-1][i][0].end - path[size-1][i][0].start + 1);
            for(int j = 1; j < path[size-1][i].size(); j ++){
                push += " " + s.substr(path[size-1][i][j].start, path[size-1][i][j].end - path[size-1][i][j].start + 1);
            }
            ret.push_back(push);
        }
        return ret;
    }
private:
    string my_s;
    void old_dp(int start){
        int i, j;
        bool ret = false;
        for(i = start; i >= 0; i--){
            if(ok[i] == -1){
                for(j = i; j >= 0; j--){
                    if(mymap.find(my_s.substr(j, i-j+1)) != mymap.end()){
                        if(j==0){
                            ok[i] = 1;
                            return;
                        }
                        if(ok[j-1] == -1)
                            old_dp(j-1);
                        if(ok[j-1] == 1){
                            ok[i] = 1;
                            break;
                        }
                        if(ok[j-1] == 0) continue;
                    }
                }
            }
            if(ok[i] == -1) ok[i] = 0;
        }
    }
    void dp(int start){
        int i, j;
        bool ret = false;
        for(i = start; i >= 0; i--){
            if(ok[i] == -1){
                for(j = i; j >= 0; j--){
                    if(mymap.find(my_s.substr(j, i-j+1)) != mymap.end()){
                        if(j==0){
                            ok[i] = 1;
                            vector<vector<interval>> tmp;
                            tmp.push_back({interval(j, i)});
                            path[i].insert(path[i].end(), tmp.begin(), tmp.end());
                            return;
                        }
                        if(ok[j-1] == -1)
                            dp(j-1);
                        if(ok[j-1] == 1){
                            ok[i] = 1;
                            vector<vector<interval>> tmp = path[j-1];
                            for(int m = 0; m < tmp.size(); m++){
                                tmp[m].push_back({interval(j, i)});
                            }
                            path[i].insert(path[i].end(), tmp.begin(), tmp.end());
                        }
                        if(ok[j-1] == 0) continue;
                    }
                }
            }
            if(ok[i] == -1) ok[i] = 0;
        }
    }
    map<string, bool> mymap;
    vector<int> ok;
    vector<vector<vector<interval>>> path;
};