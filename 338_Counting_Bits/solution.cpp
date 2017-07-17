class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num + 1, 0);
        if(num == 0) return ret;
        ret[1] = 1;
        for(int i = 2; i <= num; i++)
            ret[i] = ret[i&(i-1)]+1;
        return ret;
    }
};