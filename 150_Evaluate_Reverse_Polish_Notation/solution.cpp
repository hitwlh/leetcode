class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) return 0;
        stack<int> num;
        for(auto s: tokens){
            bool res = analyse(s);
            if(res){
                num.push(number);
            }else{
                int num1 = num.top();
                num.pop();
                int num2 = num.top();
                num.pop();
                if(operato == '+') num.push(num1 + num2);
                else if(operato == '-') num.push(num2 - num1);
                else if(operato == '*') num.push(num1 * num2);
                else num.push(num2 / num1);
            }
        }
        return num.top();
    }
private:
    char operato;
    int number;
    bool analyse(string s){
        if(s.size() == 1){
            if(s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/'){
                operato = s[0];
                return false;
            }
        }
        number = atoi(s.c_str());
        return true;
    }
};