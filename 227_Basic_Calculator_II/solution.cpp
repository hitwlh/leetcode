class Solution {
public:
    int calculate(string s) {
    istringstream in('+' + s + '+');
    long total = 0, num1 = 0, num2;
    char op;
    while(in >> op){
        if(op == '+' || op == '-'){
            total += num1;
            in >> num1;
            num1 = num1 * (44 - op);
        }else{
            in >> num2;
            if(op == '*') num1 *= num2;
            else num1 /= num2;
        }
    }
    return total;
}
};