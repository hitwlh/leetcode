class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> mymap;
        for(int i = 0; i < strs.size(); i++){
            int a[26] = {0};
            string use;
            for(auto j: strs[i])
                a[j - 'a']++;
            for(auto j: a)
                use += to_string(j) + "/";
            mymap[use].push_back(strs[i]);
        }
        for(auto i: mymap)
            ret.push_back(i.second);
        return ret;
    }
};