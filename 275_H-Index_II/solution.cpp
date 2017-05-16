class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        int n = citations.size();
        int L = 0, R = n-1, mid;
        while(L < R){
            mid = L + (R - L) / 2;
            if(citations[mid] < n - mid) L = mid + 1;//它引太小，篇数太多。往右
            else R = mid;//有效
        }
        if(citations[L] >= n - L) return n-L;
        return n-L-1;
    }
};
//这种写法，退出循环时L == R
//L左侧是验证过不可行的，即[0, L)是无效的。R及R右侧是可行的，即[R, n]是有效的。但是退出的时候L == R，这时知道[0, L-1]是无效的
//[L+1, n]是有效的。但是L是有效还是无效还需要验证，因此退出循环后要先验证L是否有效，如果有效就返回n-L，否则返回n-(L+1)





class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        int n = citations.size();
        int L = 0, R = n-1, mid;
        while(L <= R){
            mid = L + (R - L) / 2;
            //if(citations[mid] == n - mid) return n - mid;
            if(citations[mid] < n - mid) L = mid + 1;
            else R = mid-1;
        }
        return n - L;
    }
};
//这种写法，退出循环时L == R + 1
//L左侧是验证过不可行的，即[0, L)是无效的，R右侧是可行的，即(R, n]是有效的。退出的时候L == R + 1，即[R, L]，这时知道[0, R]是无效的
//[L, n]是有效的。因此返回n-L