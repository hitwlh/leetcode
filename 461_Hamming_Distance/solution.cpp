class Solution {
public:
    int hammingDistance(int x, int y) {
        int xy = x ^ y, ret = 0;
        while(xy){
            if(xy & 1) ret++;
            xy >>= 1;
        }
        return ret;
    }
};