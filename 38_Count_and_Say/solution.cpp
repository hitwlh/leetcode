class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i = 1; i<n;i++)
            res = read(res);
        return res;
    }
    string read(string s){
        int index = 0, i = 1, leng = 1;
        string tmp;
        while(i<s.length()){
            if(s[i] == s[i-1])
                leng++;
            else{
                tmp = tmp + to_string(leng) + s[i-1];
                leng = 1;
            }
            i++;
        }
        tmp = tmp + to_string(leng) + s[i-1];
        return tmp;
    }
};