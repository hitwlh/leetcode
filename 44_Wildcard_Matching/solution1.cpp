class Solution {
public:
    bool isMatch(string s, string p) {
        int sstar = -1, pstar = -1, pcur = 0, scur = 0;
        while(scur < s.length()){
            if(s[scur] == p[pcur] || p[pcur] == '?'){
                scur++;
                pcur++;
            }else if(p[pcur] == '*'){
                pstar = pcur++;
                sstar = scur;
            }else if(sstar != -1){
                pcur = pstar+1;
                scur = ++sstar;
            }else return false;
        }
        while(pcur < p.length() && p[pcur] == '*') pcur++;
        return pcur >= p.length();
    }
};