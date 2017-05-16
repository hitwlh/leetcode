class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(!size) return 0;
        vector<int> tmp;
        tmp.assign(size, 0);
        result.assign(size, tmp);
        for(int i = 0; i < size; i++) result[i][i] = nums[i];
        for(int i = 2; i <= size; i++){//i为区间内元素个数,[a,b]内元素个数为b-a+1
            for(int j = 0; j < size-i+1; j++){//j为区间起点,区间是[j, i+j-1]
                int tmp = INT_MIN;
                for(int k = j; k <= i+j-1; k++){//k为切割点
                    int now = result[k][k], left = 0, right = 0;
                    if(j <= k-2) left = result[j][k-2];
                    if(k+2 <= i+j-1) right = result[k+2][i+j-1];
                    tmp = max(tmp, now + left + right);
                    //cout << "[" << j << ", " << i+j-1 << "]: " << left << ", " << now << ", " << right << endl;
                }
                //cout <<"result[" << j << "][" << i+j-1 << "]=" << tmp << endl;
                result[j][i+j-1] = tmp;
            }
        }
        return result[0][size-1];
    }
private:
    vector<vector<int>> result;
};