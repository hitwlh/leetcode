class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t t = 0;
        for(int i = 0; i < 32; i++){
            t <<= 1;
            t = t | (n & 1);
            n >>= 1;
        }
        return t;
    }
};