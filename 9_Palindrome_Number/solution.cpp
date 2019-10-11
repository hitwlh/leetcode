class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        vector<int> digits;
        while(x){
            digits.push_back(x % 10);
            x /= 10;
        }
        vector<int> s_digits(digits.begin(), digits.end());
        reverse(s_digits.begin(), s_digits.end());
        return digits == s_digits;
    }
};