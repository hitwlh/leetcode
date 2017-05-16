class Solution {
public:
    bool isHappy(int n) {
        if(n <= 0) return false;
        map<int, bool> mymap;
        int next = cal(n);
        while(mymap.find(next) == mymap.end() && next != 1){
            mymap[next] = true;
            next = cal(next);
        }
        return next == 1;
    }
private:
    int cal(int n){
        int ret = 0;
        while(n){
            int digit = n % 10;
            n /= 10;
            ret = ret + digit * digit;
        }
        return ret;
    }
};