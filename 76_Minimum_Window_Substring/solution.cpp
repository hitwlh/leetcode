class Solution {
public:
    string minWindow(string s, string t) {
        string ret;
        vector<int> map1(256, 0), map2(256, 0);
        for(auto i: t) map2[i]++;
        int i = 0, j = t.length()-1;
        for(; i <= j; i++)
            map1[s[i]]++;
        i = 0;
        while(i + t.length() -1 < s.length()){
            if(substr(map1, map2)){
                if(ret == "") ret = s.substr(i, j-i+1);
                else if(j-i+1 < ret.length()) ret = s.substr(i, j-i+1);
                map1[s[i]]--;
                i++;
            }else{
                if(j >= s.length()) break;
                map1[s[++j]]++;
            }
        }
        return ret;
    }
private:
    bool substr(vector<int> &map1, vector<int> &map2){
        for(int i = 0; i < map1.size(); i++)
            if(map1[i] < map2[i]) return false;
        return true;
    }
};