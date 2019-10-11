class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num + 1, 0);
        if(num == 0) return ret;
        for(int i = 1; i <= num; i++)
            ret[i] = ret[i&(i-1)]+1;
        return ret;
    }
};