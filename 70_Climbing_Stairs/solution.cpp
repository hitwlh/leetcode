class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int> my_vec;
        my_vec.assign(n+1, 0);
        my_vec[1] = 1, my_vec[2] = 2;
        for(int i = 3; i <= n; i++)
            my_vec[i] = my_vec[i-1] + my_vec[i-2];
        return  my_vec[n];
    }
};