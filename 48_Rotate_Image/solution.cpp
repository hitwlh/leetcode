class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() <= 1) return;
        int n = matrix.size()-1;
        vector<int> vec;
        vec.assign(n+1, 0);
        for(int i = 0; i <= n; i++){
            for(int j = n; j > i; j--)
                vec[j] = matrix[j][i];//4->vec
            for(int j = n; j > i; j--)
                matrix[j][i] = matrix[n][j];//3->4
            for(int j = i; j < n; j++)
                matrix[n][n+i-j] = matrix[j][n];//2->3
            for(int j = i; j < n; j++)
                matrix[j][n] = matrix[i][j];//1->2
            for(int j = i; j < n; j++)
                matrix[i][j] = vec[n+i-j];//vec->1
            n--;
        }
    }
};