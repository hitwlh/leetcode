class Solution {
public:
    string removeKdigits(string num, int k) {
        int i = 1;
        while(i < num.size() && k){
            if(num[i] < num[i-1]){
                int now = i;
                while(now-1 >= 0 && num[now-1] > num[now] && k){
                    num.erase(num.begin()+now-1);
                    now--;
                    k--;
                }
                i = now;
            }else{
                i++;
            }
        }
        while(k--) num.pop_back();
        while(num.size() > 0 && num[0] == '0')
            num.erase(num.begin());
        return num == "" ? "0" : num;
    }
};