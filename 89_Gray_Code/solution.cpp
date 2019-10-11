class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret = {0};
        int N = n;
        while(n--){
            vector<int> tmp = ret;
            reverse(tmp.begin(), tmp.end());
            for(int i = 0; i < tmp.size(); i++)
                tmp[i] += (1 << (N-n-1));
            ret.insert(ret.end(), tmp.begin(), tmp.end());
        }
        return ret;
    }
};