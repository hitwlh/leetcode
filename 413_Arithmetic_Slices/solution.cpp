class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = 0, ret = 0;
        //n是等差数列的起点
        while(n+2 < A.size()){
            int start_index = n, diff = A[start_index+1] - A[start_index];
            start_index++;
            while(start_index + 1 < A.size() && A[start_index+1] - A[start_index] == diff) start_index++;
            if(start_index > n+1)
                ret += ((start_index - n + 1) * (start_index - n + 1) - 3 * (start_index - n + 1)) / 2 + 1;
            n = start_index;
        }
        return ret;
    }
};