class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int L = matrix[0][0], R = matrix[n-1][n-1];
        while(L < R){
            int temp = 0, mid = L + (R-L) / 2;
            for(int i = 0; i < n; i++)
                temp += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            if(temp < k) L = mid + 1;
            else R = mid;
        }
        return L;
    }
};


当L+1==R时
即[L, R] == [L, L+1]
mid == L，
如果答案是L，有temp >= k， 执行R = mid，退出循环，答案是L
如果答案是R，有temp < k, 执行L = mid + 1, 退出循环，答案是L（也是上一步的R）





class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int L = matrix[0][0], R = matrix[n-1][n-1];
        while(L + 1 < R){
            int temp = 0, mid = L + (R-L) / 2;
            for(int i = 0; i < n; i++)
                temp += lower_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            if(temp < k) L = mid;
            else  R = mid - 1;
        }
        int temp1 = 0, temp2 = 0;
        for(int i = 0; i < n; i++)
            temp1 += lower_bound(matrix[i].begin(), matrix[i].end(), L) - matrix[i].begin();
        for(int i = 0; i < n; i++)
            temp2 += lower_bound(matrix[i].begin(), matrix[i].end(), L+1) - matrix[i].begin();
        if(temp1 < k && temp2 >= k) return L;
        return R;
    }
};



当L+1==R时
即[L, R] == [L, L+1]
mid == L，
如果答案是L，有temp < k， 执行L = mid，(如果while的条件是L < R，则死循环)
如果答案是R，有temp < k, 执行L = mid, (如果while的条件是L < R，则死循环)
因此如果用lower_bound，必须跳出循环后再判断L和R哪个对。