class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() or matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n-1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(matrix[0][mid] == target) return true;
            else if(matrix[0][mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        while(right >= 0){
            int up = 0, down = m - 1;
            while(up <= down){
                int middle = (up + down) / 2;
                if(matrix[middle][right] == target) return true;
                else if(matrix[middle][right] > target) down = middle-1;
                else up = middle+1;
            }
            right--;
        }
        return false;
    }
};