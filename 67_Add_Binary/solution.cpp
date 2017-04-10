class Solution {  
public:  
    string addBinary(string a, string b) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        string sum = "";  
        int alen = a.length() - 1;  
        int blen = b.length() - 1;  
        int carry = 0;  
        while (alen >= 0 || blen >= 0 || carry > 0) {  
            int v = carry;  
            if (alen >= 0) v += a[alen] - '0';  
            if (blen >= 0) v += b[blen] - '0';  
  
            carry = v / 2;  
            sum = char('0' + (v%2)) + sum;   
            alen--;  
            blen--;  
        }  
        return sum;  
    }  
};