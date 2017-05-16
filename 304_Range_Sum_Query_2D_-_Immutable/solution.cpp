class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.empty() || matrix[0].empty()) return ;
        sum = matrix;
        for(int i = 0; i < sum.size(); i++)
            for(int j = 1; j < sum[i].size(); j++)
                sum[i][j] += sum[i][j-1];
        for(int i = 0; i < sum[0].size(); i++)
            for(int j = 1; j < sum.size(); j++)
                sum[j][i] += sum[j-1][i];
    }
    int sumRegion(int k, int l, int i, int j){//(i, j)为右下，(k, l)为左上
        if(k == 0 && l == 0) return sum[i][j];
        if(k == 0) return sum[i][j] - sum[i][l-1];
        if(l == 0) return sum[i][j] - sum[k-1][j];
        return sum[i][j] - sum[k-1][j] - sum[i][l-1] + sum[k-1][l-1];
    }
private:
    vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */