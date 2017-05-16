class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if(A.empty() || B.empty() || C.empty() || D.empty()) return 0;
        int ret = 0;
        unordered_map<int, int> hash;
        for(auto i: A)
            for(auto j: B) hash[i+j]++;
        for(auto i: C)
            for(auto j: D)
                ret = ret + hash[0 - i - j];
        return ret;
    }
};