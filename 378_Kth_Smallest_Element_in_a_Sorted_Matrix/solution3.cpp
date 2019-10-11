class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back(), n = matrix.size();
        while(left <= right){
            int target = left + (right - left) / 2, less = 0;
            for(int i = 0; i < n; i++){
                int L = 0, R = n-1;
                while(L <= R){
                    int mid = (L+R)/2;
                    if(matrix[i][mid] >= target) R = mid-1;
                    else L = mid + 1;
                }
                less += R+1;
            }
            if(less <= k-1) left = target+1;
            else right = target - 1;
        }
        return right;
    }
};