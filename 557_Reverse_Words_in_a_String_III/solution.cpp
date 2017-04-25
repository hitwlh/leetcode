class Solution {
public:
    string reverseWords(string s) {
        int last_index = 0, length = s.length();
        for(int i = 0; i < length; i++){
            if(s[i] == ' '){
                for(int j = last_index, k = i-1; j < k; j++, k--)
                    swap(s[j], s[k]);
                last_index = i+1;
            }
        }
        for(int j = last_index, k = length-1; j < k; j++, k--)
            swap(s[j], s[k]);
        return s;
    }
};