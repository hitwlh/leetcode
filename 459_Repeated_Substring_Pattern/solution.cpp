class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 1; i < s.length(); i++){
            if(s.length() % i == 0){
                string substr = s.substr(0, i);
                string my_s = s;
                while(my_s.substr(0, i) == substr) my_s.erase(0, i);
                if(my_s == "") return true;
            }
        }
        return false;
    }
};