bool comp(string a, string b){
    return a.length() > b.length();
}
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), comp);
        for(int i = 0; i < strs.size(); i++){//查找i是否是别人的子串
            bool flag = true;
            for(int j = 0; j < strs.size(); j++){
                if(j == i)
                    continue;
                if(strs[i].length() > strs[j].length())
                    break;
                if(issub(strs[i], strs[j])){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return strs[i].length();
            
        }
        return -1;
    }
private:
    bool issub(string a, string b){
        if(a.length() < b.length()) swap(a, b);
        int index_a = 0, index_b = 0;
        while(index_a < a.length()){
            if(index_b >= b.length()) return true;
            if(a[index_a] == b[index_b])
                index_b++;
            index_a ++;
        }
        if(index_b >= b.length()) return true;
        return false;
    }
};