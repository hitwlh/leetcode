class Solution {
public:
    string reverseVowels(string s) {
        if(s == "") return "";
        for(int i = 0, j = s.length()-1; i < j ;){
            if(isvowels(s[i]) && isvowels(s[j]))
                swap(s[i++], s[j--]);
            else{
                if(!isvowels(s[i])) i++;
                if(!isvowels(s[j])) j--;
            }
        }
        return s;
    }
private:
    bool isvowels(char a){
        return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U';
    }
};