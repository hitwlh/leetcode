class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i = 1; i<n;i++)
            res = read(res);
        return res;
    }
    string read(string s){
        ostringstream stream;
        string tmp;
        int index = 0, i = 1, leng = 1;
        while(i<s.length()){
            if(s[i] == s[i-1])
                leng++;
            else{
                stream.str("");
                stream << leng;
                tmp = tmp + stream.str() + s[i-1];
                leng = 1;
            }
            i++;
        }
        stream.str("");
        stream << leng;
        tmp = tmp + stream.str();
        tmp = tmp + s[i-1];
        return tmp;
    }
};