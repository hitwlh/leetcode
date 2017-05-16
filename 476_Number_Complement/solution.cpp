class Solution {
public:
    int findComplement(int num) {
        long long ret = 1;
        while(ret <= num) ret <<= 1;
        return ret - 1 - num;
    }
};