class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows < 1) return ret;
        vector<int> tmp;
        tmp.push_back(1);
        ret.push_back(tmp);
        if(numRows == 1) return ret;
        for(int i = 2; i <= numRows; i++){
            vector<int> now;
            now.push_back(1);
            for(int j = 1; j < i-1; j++)
                now.push_back(tmp[j-1]+tmp[j]);
            now.push_back(1);
            ret.push_back(now);
            tmp = now;
        }
        return ret;
    }
};