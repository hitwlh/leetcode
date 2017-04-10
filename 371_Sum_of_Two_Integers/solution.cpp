class Solution {
public:
    int getSum(int a, int b) {
        int carry;
        while(a){
            carry = (a&b)<<1;
            b = a^b;
            a = carry;
        }
        return b;
    }
};