class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return ret;
        my_matrix = matrix;
        int start_x = 0, start_y = 0;
        int end_x = matrix.size(), end_y = matrix[0].size();
        r_spiral(start_x, start_y, end_x, end_y);
        return ret;
    }
private:
    void r_spiral(int start_x, int start_y, int end_x, int end_y){
        if(start_x >= my_matrix.size() || end_x < 0) return ;
        if(start_y >= my_matrix[0].size() || end_y < 0) return ;
        if(start_x >= end_x || start_y >= end_y) return;
        if(start_x+1 == end_x && start_y+1 == end_y){
            ret.push_back(my_matrix[start_x][start_y]);
            return;
        }
        if(start_x+1 == end_x){
            for(int i = start_y; i < end_y; i++) ret.push_back(my_matrix[start_x][i]);
            return ;
        }
        if(start_y+1 == end_y){
            for(int i = start_x; i < end_x; i++) ret.push_back(my_matrix[i][end_y-1]);
            return ;
        }
        for(int i = start_y; i < end_y-1; i++)
            ret.push_back(my_matrix[start_x][i]);
        for(int i = start_x; i < end_x-1; i++)
            ret.push_back(my_matrix[i][end_y-1]);
        for(int i = end_y-1; i > start_y; i--)
            ret.push_back(my_matrix[end_x-1][i]);
        for(int i = end_x-1; i > start_x; i--)
            ret.push_back(my_matrix[i][start_y]);
        r_spiral(start_x+1, start_y+1, end_x-1, end_y-1);
    }
    vector<int> ret;
    vector<vector<int>> my_matrix;
};