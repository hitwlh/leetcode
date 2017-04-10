class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool flag = false;
        for(int i=digits.size()-1; i>=0; i--){
            if(i==0 && digits[0] == 9)
                flag = true;
            if(digits[i] <= 8){
                digits[i] ++;
                break;
            }
            else
                digits[i] = 0;
        }
        if(flag)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};