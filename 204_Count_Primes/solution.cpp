//参考了http://blog.csdn.net/angelazy/article/details/45561885
//用标记的方法做
class Solution {
public:
    int countPrimes(int n) {
        if( n<= 2)
            return 0;
        vector<bool> p(n, true);
        int ret = 0;
        for(int i=2; i*i<n; i++){
            int use = i;
            if(!p[use])
                continue;
            use +=i ;
            while(use<n){
                p[use] = false;
                use += i;
            }
        }
        for(int i=2;i<n;i++)
            if(p[i])
                ret++;
        return ret;
    }
};