class Solution {
public:
    string removeKdigits(string num, int k) {
        string ret = my_removeKdigits(num, k);
        int index = 0;
        while(index < ret.size() && ret[index] == '0') index++;
        ret.erase(ret.begin(), ret.begin()+index);
        if(ret == "") ret = "0";
        return ret;
    }
private:
    string my_removeKdigits(string num, int k) {
        if(num.length() <= k){
            return "";
        }
        if(k==0) return num;
        int MIN = 11111,min_index = -1;
        for(int i = 0; i <= k; i++){
            if(num[i] < MIN){
                MIN = num[i];
                min_index = i;
            }
        }
        string left;
        left = num.substr(min_index, 1);
        return left + my_removeKdigits(num.substr(min_index+1), k - min_index);
    }
};