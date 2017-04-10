class Solution {  
public:  
    int romanToInt(string s) {  
        //int ret = toNumber(s[0]);
        int ret = 0;
        if(s.length() == 1)
            return toNumber(s[0]);
        int i;
        for (i = 0; i < s.length()-1; i++) {  
            if (toNumber(s[i]) < toNumber(s[i+1])) {  
                ret -= toNumber(s[i]);
            } else {  
                ret += toNumber(s[i]);  
            }  
        }
        ret += toNumber(s[i]);
        return ret;  
    }  
      
    int toNumber(char ch) {  
        switch (ch) {  
            case 'I': return 1;  
            case 'V': return 5;  
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }  
        return 0;  
    }  
};