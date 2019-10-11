class Solution {
public:
    bool isNumber(string s) {
        if(s == "") return false;
        int start = 0;
        while(start < s.length() and s[start] == ' ') ++start;
        int end = s.size() - 1;
        while(end > 0 and s[end] == ' ') --end;
        // 最后有效位不能是'e+-'
        if(end >= 0 and (s[end] == 'e' || s[end] == '+' || s[end] == '-'))
            return false;
        bool hasNum = false, hasPoint = false, hasE = false;
        for(int i = start; i <= end; ++i){
            if(s[i] == '.'){
                // 如果前面已经有了'.' 或者 'e'
                if(hasPoint || hasE)
                    return false;
                hasPoint = true;
            }
            else if(s[i] == 'e'){
                // 如果前面已经有了'e' 或者 没数字
                if(hasE || !hasNum)
                    return false;
                hasE = true;
            }
            else if(s[i] < '0' || s[i] > '9'){
                // +2
                if(i == start && (s[i] == '+' || s[i] == '-'))
                    continue;
                // 1e-2
                else if((i > start && s[i-1] == 'e') && (s[i] == '+' || s[i] == '-'))
                    continue;
                else
                    return false;
            }
            else
                hasNum = true;
        }//for
        //5.是合法的！！
        // '.'或者全是空格
        if(!hasNum)
            return false;
        return true;
    }
};