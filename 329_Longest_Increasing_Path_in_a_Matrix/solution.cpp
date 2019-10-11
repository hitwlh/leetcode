class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        my_matrix = matrix;
        vec.assign(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(vec[i][j] == 0) up_down(i, j);
            }
        }
        int MAX = INT_MIN;
        for(int i = 0; i < vec.size(); i++){
            for(int j = 0; j < vec[i].size(); j++){
                if(vec[i][j] > MAX) MAX = vec[i][j];
            }
        }
        return MAX;
    }
private:
    vector<vector<int>> vec, my_matrix;
    int up_down(int i, int j){
        if(vec[i][j] == 0){
            int left = -1, right = -1, up = -1, down = -1;
            if(i-1>=0)
                if(my_matrix[i-1][j] > my_matrix[i][j]) up = up_down(i-1, j) + 1;
            if(i+1 < my_matrix.size())
                if(my_matrix[i+1][j] > my_matrix[i][j]) down = up_down(i+1, j) + 1;
            if(j-1 >= 0)
                if(my_matrix[i][j-1] > my_matrix[i][j]) left = up_down(i, j-1) + 1;
            if(j+1 < my_matrix[i].size())
                if(my_matrix[i][j+1] > my_matrix[i][j]) right = up_down(i, j+1) + 1;
            vec[i][j] = max(1, max(up, max(down, max(left, right))));
        }
        return vec[i][j];
    }
};