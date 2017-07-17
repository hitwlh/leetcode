class Solution {
public:
    string simplifyPath(string path) {
        stack<string> sta;
        string t;
        path += "/";
        path.erase(path.begin());
        int find = myfind(path);
        while(find != -1){
            t = path.substr(0, find);
            path.erase(0, find+1);
            find = myfind(path);
            if(t == ".") continue;
            if(t == ".."){
                if(!sta.empty())//  /../
                    sta.pop();
            }
            else if(t != "") sta.push(t);
        }
        string result;
        while(!sta.empty()){
            result = "/" + sta.top() + result;
            sta.pop();
        }
        if(result == "") result = "/";
        return result;
    }
private:
    int myfind(string &s){
        int i = 0;
        while(i < s.length() && s[i] != '/') i++;
        if(i >= s.length()) return -1;
        return i;
    }
};  