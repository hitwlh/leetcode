class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return ;
        bool flag_x = false, flag_y = false;
        for(int i = 0; i < matrix[0].size(); i++)
            if(!matrix[0][i]) flag_x = true;
        for(int i = 0; i < matrix.size(); i++)
            if(!matrix[i][0]) flag_y = true;
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[i].size(); j++)
                if(!matrix[i][j]) matrix[i][0] = matrix[0][j] = 0;
        }
        for(int i = 1; i < matrix.size(); i++){
            if(!matrix[i][0]){
                for(int j = 0; j < matrix[i].size(); j++)
                    matrix[i][j] = 0;
            }
        }
        for(int i = 1; i < matrix[0].size(); i++){
            if(!matrix[0][i]){
                for(int j = 0; j < matrix.size(); j++)
                    matrix[j][i] = 0;
            }
        }
        if(flag_x) for(int i = 0; i < matrix[0].size(); i++) matrix[0][i] = 0;
        if(flag_y) for(int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
    }
};