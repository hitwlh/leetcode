class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; ; i += 2*k){
            if(i + k < s.length())
                reverse(s.begin() + i, s.begin() + i + k);
            else{
                if(i < s.length())
                    reverse(s.begin() + i, s.end());
                break;
            }
        }
        return s;
    }
};