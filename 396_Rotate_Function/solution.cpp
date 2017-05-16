class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if(A.empty()) return 0;
        vector<int> num(A.size(), 0);
        int sumA = 0;
        for(int i = 0; i < A.size(); i++){
            num[0] = num[0] + i * A[i];
            sumA += A[i];
        }
        for(int i = 1; i < A.size(); i++)
            num[i] = num[i-1] + sumA - A.size() * A[A.size()-i];
        int MAX = INT_MIN;
        for(int i = 0; i < num.size(); i++)
            MAX = max(num[i], MAX);
        return MAX;
    }
};