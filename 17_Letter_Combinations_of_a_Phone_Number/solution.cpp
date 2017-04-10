class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<int, string> dict;
        dict[2] = "abc";
        dict[3] = "def";
        dict[4] = "ghi";
        dict[5] = "jkl";
        dict[6] = "mno";
        dict[7] = "pqrs";
        dict[8] = "tuv";
        dict[9] = "wxyz";
        vector<string> ret;
        for(int i = 0; i < digits.length(); i++){
            vector<string> tmp = ret;
            ret.clear();
            for(int k = 0; k < dict[digits[i] - '0'].size() ; k++){
                if(tmp.size() == 0){
                    string s = "a";
                    s[0] = dict[digits[i] - '0'][k];
                    ret.push_back(s); 
                }
                else
                    for(int j = 0; j<tmp.size(); j++){
                        ret.push_back(tmp[j] + dict[digits[i] - '0'][k]);    
                    }
            }
        }
        return ret;
    }
};