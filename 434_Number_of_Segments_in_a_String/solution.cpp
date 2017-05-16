class Solution {
public:
    int countSegments(string s) {
        int ret = 0, start_flag = 1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                if(start_flag == 1){
                    start_flag = 0;
                    ret++;
                }
            }
            else start_flag = 1;
        }
        return ret;
    }
};