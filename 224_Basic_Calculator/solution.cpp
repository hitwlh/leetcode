class Solution {
public:
    int calculate(string s) {
        int num = 0, oldnum = 0, flag = 1, i = 0;//flag is 1 or -1
        stack<int> number, fuhao;
        while(i < s.length()){
            if(s[i] == '+' || s[i] == '-'){
                oldnum = oldnum + flag * num;
                flag = (s[i] == '+') ? 1 : -1;
                num = 0;
            }
            else if(s[i] == '('){
                number.push(oldnum);
                fuhao.push(flag);
                oldnum = 0;
                flag = 1;
            }
            else if(s[i] == ')'){
                num = oldnum + flag * num;
                if(!number.empty()){
                    oldnum = number.top(), flag = fuhao.top();
                    number.pop(), fuhao.pop();
                }else oldnum = 0, flag = 1;
            }
            else if(s[i] >= '0' && s[i] <= '9')
                num = 10 * num + s[i] - '0';
            i++;
        }
        return oldnum + flag * num;
    }
};