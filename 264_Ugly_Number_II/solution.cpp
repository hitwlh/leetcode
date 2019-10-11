class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> q;
        q.push_back(1);
        int m2 = 0, m3 = 0, m5 = 0;
        while(q.size() < n){
            int val2 = q[m2] * 2, val3 = q[m3] * 3, val5 = q[m5] * 5;
            int val = min(val2, min(val3, val5));
            q.push_back(val);
            if(val == val2) m2++;
            if(val == val3) m3++;
            if(val == val5) m5++;
        }
        return q[n-1];
    }
};