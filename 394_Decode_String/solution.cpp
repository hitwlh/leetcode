class Solution {
public:
    string decodeString(string s) {
        stack<int> st_n;
        stack<string> st_s;
        int number = 0;
        string t;
        for(int i=0; i<s.length(); i++){
            if(Is_digit(s[i])){
                number = number*10 + s[i] - '0';
            }
            else if(Is_letter(s[i])){
                t+=s[i];
            }
            else if(s[i] == '['){
                st_n.push(number);
                number = 0;
                st_s.push(t);
                t = "";
            }
            else{
                int out = st_n.top();
                st_n.pop();
                string left = st_s.top();
                t = oper(t, out);
                t = st_s.top() + t;
                st_s.pop();
                
            }
        }
        return st_s.empty()?t:st_s.top();
    }
private:

    bool Is_digit(char c){ return c>='0' && c<='9';}
    bool Is_break(char c) { return c=='[' || c== ']';}
    bool Is_right_break(char c) { return c== ']';}
    bool Is_letter(char c) {return !Is_digit(c) && !Is_break(c);}
    string oper(string s, int n){
        string tmp = s;
        while(--n) s+=tmp;
        return s;
    }
};