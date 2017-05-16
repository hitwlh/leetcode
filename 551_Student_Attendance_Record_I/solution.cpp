class Solution {
public:
    bool checkRecord(string s) {
        int An = 0, Ln = 0;
        for(int i = 1; i < s.length() && An <= 1 && Ln <= 1; i++){
            if(s[i-1] == 'A'){
                An++;
                Ln = 0;
            }
            else if(s[i-1] == 'L' && s[i] == 'L') Ln++;
            else Ln = 0;
        }
        if(s[s.length()-1] == 'A') An++;
        return An <= 1 && Ln <= 1;
    }
};