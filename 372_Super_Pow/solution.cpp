class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int last = b.back();
        b.pop_back();
        return (mypow(a, last) * mypow(superPow(a, b), 10)) % 1337;
    }
private:
    int mypow(int a, int b){
        if(!b) return 1;
        int tmp = a % 1337;
        a = tmp;
        while(--b)
            a = (a * tmp) % 1337;
        return a;
    }
};