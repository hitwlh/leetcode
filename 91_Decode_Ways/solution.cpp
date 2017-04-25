class Solution {
public:
    int numDecodings(string s) {
        if(s=="") return 0;
        solution.assign(s.length()+1, 0);
        int length = s.length();
        for(auto i: s) if(i < '0' || i > '9') return 0;
        if(s[length-1] != '0')
            solution[length-1] = 1;
        solution[length] = 1;
        
        for(int i = s.length()-2; i >=0; i--){
            string str = s.substr(i,2);
            int n = atoi(str.c_str());
            if(n <= 26 && n >= 10) solution[i] += solution[i+2];
            if(s[i] != '0')
            solution[i] += solution[i+1];
        }
        return solution[0];
    }
private:
    vector<int> solution;
};