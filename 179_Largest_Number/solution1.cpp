bool comp(string &s1, string &s2){
    if(s1.length() == s2.length()) return s1.compare(s2) > 0;
    if(s1.length() > s2.length()) return !comp(s2, s1);
    for(int i = 0; i < s1.length(); i++)
        if(s1[i] > s2[i]) return true;
        else if(s1[i] < s2[i]) return false;
    int j = 0;
    for(j = s1.length(); j < s2.length(); j++){
        if(s2[j] > s1[j % s1.length()]) return false;
        else if(s2[j] < s1[j % s1.length()]) return true;
    }
    j %= s1.length();
    if(j == 0) return true;
    for(int i = 0; i < s1.length(); j = (j+1) % s1.length(), i++)
        if(s1[j] > s1[i]) return true;
        else if(s1[j] < s1[i]) return false;
    return true;//return false make sense, too
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ret(nums.size(), "");
        for(int i = 0; i < nums.size(); i++)
            ret[i] = to_string(nums[i]);
        sort(ret.begin(), ret.end(), comp);
        string r;
        for(auto i: ret) r += i;
        while(r.size()>1 && r[0] == '0')
            r.erase(r.begin());
        return r;
    }
};