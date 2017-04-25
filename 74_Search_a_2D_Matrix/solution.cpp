class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int left = 0, right = matrix.size() - 1, mid;
        while(left <= right){
            mid = (left + right) / 2;
            if(matrix[mid][0] > target) right = mid-1;
            else if(matrix[mid][matrix[mid].size()-1] < target) left = mid+1;
            else return searchVector(matrix, mid, target);
        }
        return false;
    }
private:
    bool searchVector(vector<vector<int>>& matrix, int i, int target){
        int first = 0, last = matrix[i].size()-1, mid;
        while(first <= last){
            mid = (first + last) / 2;
            if(matrix[i][mid] == target) return true;
            else if(matrix[i][mid] < target) first = mid+1;
            else last = mid-1;
        }
        return false;
    }
};