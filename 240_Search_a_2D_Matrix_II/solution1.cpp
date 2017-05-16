class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int left = 0, right = matrix[0].size()-1, mid;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(matrix[0][mid] == target) return true;
            else if(matrix[0][mid] < target) left = mid+1;
            else right = mid-1;
        }
        if(left >= matrix[0].size() || matrix[0][left] > target) left--;
        while(left >= 0){
            int cleft = 0, cright = matrix.size()-1;
            while(cleft <= cright){
                mid = cleft + (cright - cleft) / 2;
                if(matrix[mid][left] == target) return true;
                else if(matrix[mid][left] < target) cleft = mid+1;
                else cright = mid-1;
            }
            left--;
        }
        return false;
    }
};