class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto s: wordDict) mymap[s] = true;
        my_s = s;
        ok.assign(s.length(), -1);
        old_dp(s.length() -1);
        return (ok[s.length()-1] == 0) ? false : true;
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
    map<string, bool> mymap;
    vector<int> ok;//ok[j]==1代表s[0...j]在字典中, ok[j]==0代表s[0...j]不在字典中, ok[j]==-1代表不知道s[0...j]是否在字典中
};