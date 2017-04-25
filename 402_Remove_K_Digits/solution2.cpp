class Solution {
public:
    string removeKdigits(string num, int k) {
        int i = 0;
        stack<char> stac;
        while(i < num.size() && k > 0){
            if(stac.empty()){
                stac.push(num[i++]);
                continue;
            }
            while(k > 0 && !stac.empty() && stac.top() > num[i]){
                stac.pop();
                k--;
            }
            stac.push(num[i++]);
        }
        string ret;
        while(!stac.empty()){
            ret = stac.top() + ret;
            stac.pop();
        }
        ret = ret + num.substr(i);
        i = 0;
        while(i < ret.length() && ret[i] == '0') i++;
        ret.erase(ret.begin(), ret.begin()+i);
        if(k >= ret.length()) return "0";
        ret.erase(ret.end()-k, ret.end());
        return ret;
    }
};