class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty()) return {1};
        bool flag = false;
        for(int i = digits.size()-1; i >= 0; i--){
            flag = false;
            if(digits[i] <= 8){
                digits[i]++;
                break;
            }
            else{
                flag = true;
                digits[i] = 0;
            }
        }
        if(flag) digits.insert(digits.begin(), 1);
        return digits;
    }
};