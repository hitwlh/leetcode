class Solution {
public:
    void reverseWords(string &s){
        if(s == "") return;
        while(s != "" && s[0] == ' ') s.erase(s.begin());
        while(s != "" && s[s.length()-1] == ' ') s.erase(s.end()-1);
        for(int i = 2; i + 1 < s.length(); i++){
            if(s[i] == ' ' && s[i-1] == ' '){
                s.erase(s.begin()+i);
                i--;
            }
        }
        for(int i = 0; i < s.length()/2; i++)
            swap(s[i], s[s.length()-1-i]);
        int start = 0, index = -1;
        while(start < s.length()){
            if(s[start] != ' ' && index == -1)
                index = start;
            if((s[start] == ' ' || start + 1 >= s.length()) && index != -1){
                if(start + 1 >= s.length()) start++;
                for(int i = index; i < (start+index)/2; i++)
                    swap(s[i], s[start+index-1-i]);
                index = -1;
            }
            start++;
        }
        return;
    }
};