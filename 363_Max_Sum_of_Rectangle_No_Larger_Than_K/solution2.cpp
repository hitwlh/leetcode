class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        if(matrix.size() <= matrix[0].size())
            my_matrix = matrix;
        else{
            my_matrix.assign(matrix[0].size(), vector<int>(matrix.size(), 0));
            for(int i = 0; i < matrix.size(); i++)
                for(int j = 0; j < matrix[i].size(); j++)
                    my_matrix[j][i] = matrix[i][j];
        }
        sum = my_matrix;
        for(int i = 0; i < my_matrix.size(); i++)
            for(int j = 1; j < my_matrix[i].size(); j++)
                sum[i][j] += sum[i][j-1];
        for(int i = 0; i < my_matrix[0].size(); i++)
            for(int j = 1; j < my_matrix.size(); j++)
                sum[j][i] += sum[j-1][i];
        int ret = INT_MIN;
        for(int i = 0; i < my_matrix.size(); i++){
            for(int j = i; j < my_matrix.size(); j++){
                vector<int> csum;
                for(int l = 0; l < my_matrix[0].size(); l++)
                    csum.push_back(get_sum(j, l, i, l));
                int ssum = 0;
                set<int> myset;
                myset.insert(0);
                for(int l = 0; l < csum.size(); l++){
                    ssum += csum[l];
                    //if(myset.find(ssum[l] - k) != myset.end()) return k;
                    auto it = myset.upper_bound(ssum - k - 1);
                    if(it != myset.end()) ret = max(ret, ssum - *it);
                    myset.insert(ssum);
                }
            }
        }
        return ret;
    }
private:
    int get_sum(int i, int j, int k, int l){//(i, j)为右下，(k, l)为左上
        if(k == 0 && l == 0) return sum[i][j];
        if(k == 0) return sum[i][j] - sum[i][l-1];
        if(l == 0) return sum[i][j] - sum[k-1][j];
        return sum[i][j] - sum[k-1][j] - sum[i][l-1] + sum[k-1][l-1];
    }
    vector<vector<int>> sum, my_matrix;
};