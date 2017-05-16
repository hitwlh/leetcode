class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        sum = matrix;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 1; j < matrix[i].size(); j++)
                sum[i][j] += sum[i][j-1];
        for(int i = 0; i < matrix[0].size(); i++)
            for(int j = 1; j < matrix.size(); j++)
                sum[j][i] += sum[j-1][i];
        int ret = INT_MAX;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){//(i, j)是矩形右下角
                for(int l = 0; l <= i; l++){
                    for(int m = 0; m <= j; m++){//(k, l)是矩形左上角
                        int rec_sum = get_sum(i, j, l, m);
                        if(rec_sum <= k && k - rec_sum < ret){
                            ret = min(k - rec_sum, ret);
                        }
                    }
                    
                }
            }
        }
        return k - ret;
    }
private:
    int get_sum(int i, int j, int k, int l){//(i, j)为右下，(k, l)为左上
        if(k == 0 && l == 0) return sum[i][j];
        if(k == 0) return sum[i][j] - sum[i][l-1];
        if(l == 0) return sum[i][j] - sum[k-1][j];
        return sum[i][j] - sum[k-1][j] - sum[i][l-1] + sum[k-1][l-1];
    }
    vector<vector<int>> sum;
};