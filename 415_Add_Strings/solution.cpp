class Solution {
public:
    string addStrings(string num1, string num2) {
        int size1 = num1.size(), size2 = num2.size(), carry = 0, i, j;
        if(size1 <= size2){
            swap(num1, num2);
            swap(size1, size2);
        }
        for(i = size2 - 1, j = size1 - 1; i >= 0; i--, j--){
            int res = num1[j]-'0' + num2[i] - '0' + carry;
            carry = 0;
            if(res > 9){
                carry = 1;
                res -= 10;
            }
            num1[j] = res + '0';
        }
        for(; j >= 0; j--){
            int res = num1[j] -'0' + carry;
            carry = 0;
            if(res > 9){
                carry = 1;
                res -= 10;
            }
            num1[j] = res + '0';
            if(!carry) break;
        }
        if(carry) return "1" + num1;
        return num1;
    }
};