class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int g_left = 0, s_left = 0;
        int ret = 0;
        while(g_left < g.size() && s_left < s.size()){
            //cout << g[g_left] << " " << s[s_left] << endl;
            if(g[g_left] <= s[s_left]){
                g_left++, s_left++;
                ret++;
            }else{
                s_left++;
            }
        }
        return ret;
    }
};