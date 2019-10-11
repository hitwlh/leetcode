class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() or matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m-1, column, mid;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(matrix[mid][0] > target) right = mid - 1;
            else left = mid + 1;
        }
        if(right < 0) return false;
        column = right;
        left = 0, right = n-1;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(matrix[column][mid] >= target) right = mid - 1;
            else left = mid + 1;
        }
        return right + 1 < n and matrix[column][right+1] == target;
    }
};