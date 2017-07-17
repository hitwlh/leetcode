class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int size = primes.size();
        vector<int> point(size, 0), mul(size, 0), ugly(n, 1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < size; j++)
                mul[j] = ugly[point[j]] * primes[j];
            int MIN = INT_MAX;
            for(int j = 0; j < size; j++)
                MIN = min(MIN, mul[j]);
            for(int j = 0; j < size; j++)
                if(mul[j] == MIN) point[j]++;
            ugly[i] = MIN;
        }
        return ugly[n-1];
    }
};