class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        vector<int> vec(n+1, 1);
        vec[1] = 1;
        vec[2] = 2;
        vec[3] = 3;
        for(int i = 4; i <= n; i++){
            int MAX = INT_MIN;
            for(int j = 1; j <= i/2; j++)
                MAX = max(MAX, vec[j] * vec[i-j]);
            vec[i] = MAX;
        }
        return vec[n];
    }
};