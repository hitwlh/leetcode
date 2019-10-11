bool comp(string &s1, string &s2){
    if(s1.length() == s2.length()) return s1.compare(s2) > 0;
    if(s1.length() > s2.length()) return !comp(s2, s1);
    for(int i = 0; i < s1.length(); i++)
        if(s1[i] > s2[i]) return true;
        else if(s1[i] < s2[i]) return false;
    string p = s1 + s2, q = s2 + s1;
    return comp(p, q);
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ret(nums.size(), "");
        for(int i = 0; i < nums.size(); i++)
            ret[i] = to_string(nums[i]);
        sort(ret.begin(), ret.end(), comp);
        string r;
        for(auto i: ret)
            r += i;
        int start = 0;
        while(start < r.length() and r[start] == '0')
            start++;
        if(start >= r.length()) return "0";
        return r.substr(start);
    }
};