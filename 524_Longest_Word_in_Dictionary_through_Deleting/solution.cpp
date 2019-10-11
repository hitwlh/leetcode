bool comp(const string &a, const string &b){
    if(a.length() != b.length()) return a.length() > b.length();
    return a < b;
    
}
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), comp);
        for(int i = 0; i < d.size(); i++)
            if(issub(s, d[i])) return d[i];
        return "";
    }
private:
    bool issub(string s, string t){
        int j = 0;
        for(int i = 0; i < s.length() && j < t.length(); i++)
            if(s[i] == t[j]) j++;
        return j == t.length();
    }
};