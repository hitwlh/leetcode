class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        if(n < 0) return ret;
        ret.push_back(0);
        while(n--){
            vector<int> tmp = ret;
            reverse(tmp.begin(), tmp.end());
            for(int i = 0; i < tmp.size(); i++)
                tmp[i] += tmp.size();
            ret.insert(ret.end(),tmp.begin(),tmp.end());
        }
        return ret;
    }
};