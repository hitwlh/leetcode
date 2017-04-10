class Solution {  
public:  
    string convert(string s, int nRows) {  
        string ret = "";
        if(s.length()==0||nRows<=1)
            return s;
        int flag = 1;
        for(int i=0;i<nRows;i++){
            flag = 1;
            for(int j=i;j<s.length();){
                ret+=s[j];
                if(i==0||i==nRows-1){
                    j += nRows-1+(nRows-1);
                    flag = 0;
                }
                //
                else if(flag){
                    j += nRows-(i+1)+(nRows-1)-i;
                    flag = 0;
                }
                else{
                    j += 2*i;
                    flag = 1;
                }
            }
        }
        return ret;
    }  
};