class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for(int i=0;i<s.length(); i++){
            if(isLeft(s[i])) ss.push(s[i]);
            else if(isRight(s[i])){
                if(ss.empty() || !equa(ss.top(),s[i]))
                    return false;
                ss.pop();
            }
            else return false;
        }
        if(ss.empty())
            return true;
        return false;
    }
    bool isLeft(char a){
        return a=='(' || a=='[' || a=='{';
    }
    bool isRight(char a){
        return a=='}' || a==']' || a==')';
    }
    bool equa(char a, char b){
        if(a=='(' && b== ')') return true;
        if(a=='{' && b== '}') return true;
        if(a=='[' && b== ']') return true;
        return false;
    }
};