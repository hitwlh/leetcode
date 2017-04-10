class Solution {
public:
    int numTrees(int n) {
        int ret[1000000];
        for(int i=0; i< 1000000; i++)
            ret[i] = 0;
        ret[0] = 1;
        ret[1] = 1;
        ret[2] = 2;
        for(int i=3; i<=n; i++){
            if(!ret[i]){
                for(int j = 0; j<i; j++)
                    ret[i] = ret[i] + ret[j]*ret[i-1-j];
            }
        }
        return ret[n];
    }
};