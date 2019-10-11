class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0, i = a.size()-1, j = b.size()-1;
        string ret;
        while(i >= 0 || j >= 0 || carry){
            int sum = carry;
            if(i >= 0) sum += a[i] - '0';
            if(j >= 0) sum += b[j] - '0';
            if(sum >= 2){
                carry = 1;
                sum -= 2;
            }else
                carry = 0;
            ret = to_string(sum) + ret;
            i--, j--;
        }
        return ret;
    }
};