class Solution {
public:
    vector<vector<string>> partition(string s) {
        int length = s.length();
        path.assign(length, vector<vector<string>>());
        for(int i = length-1; i >= 0; i--){
            for(int j = i; j + 1 < length; j++){
                if(isPalindrome(s.substr(i, j-i+1))){
                    vector<string> f = {s.substr(i, j-i+1)};
                    vector<vector<string>> ans = construct(f, path[j+1]);
                    path[i].insert(path[i].end(), ans.begin(), ans.end());
                }
            }
            if(isPalindrome(s.substr(i)))
                path[i].insert(path[i].end(), {{s.substr(i)}});
        }
        return path.front();
    }
private:
    vector<vector<vector<string>>> path;
    bool isPalindrome(string s){
        int i = 0, j = s.length();
        j--;
        while(i < j)
            if(s[i++] != s[j--])
                return false;
        return true;
    }
    vector<vector<string>> construct(vector<string> &s1, vector<vector<string>>& s2){
        vector<vector<string>> ret;
        for(auto l2: s2){
            vector<string> l = s1;
            l.insert(l.end(), l2.begin(), l2.end());
            ret.push_back(l);
        }
        return ret;
    }
};