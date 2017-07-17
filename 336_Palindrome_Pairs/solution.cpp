class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ret;
        unordered_map<string, int> mymap;
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            reverse(s.begin(), s.end());
            mymap[s] = i;
        }
        if(mymap.find("") != mymap.end()){
            for(int i = 0; i < words.size(); i++)
                if(is_p(words[i]) && words[i] != "") ret.push_back({mymap[""], i});
        }
        for(int i = 0; i <words.size(); i++){
            for(int j = 0; j < words[i].length(); j++){
                string left = words[i].substr(0, j), right = words[i].substr(j);
                if(is_p(right) && mymap.find(left) != mymap.end())// && mymap[left] != i)
                    ret.push_back({i, mymap[left]});
                if(is_p(left) && mymap.find(right) != mymap.end() && mymap[right] != i)
                    ret.push_back({mymap[right], i});
            }
        }
        return ret;
    }
private:
    bool is_p(string &s){
        for(int i = 0; i < s.length()/2; i++)
            if(s[i] != s[s.length()-1-i]) return false;
        return true;
    }
};