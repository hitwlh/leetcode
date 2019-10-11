class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<int> s1, s2;
        for(auto i: A) for(auto j: B) s1.push_back(i+j);
        for(auto i: C) for(auto j: D) s2.push_back(i+j);
        sort(s2.begin(), s2.end());
        int ret = 0;
        for(auto target: s1){
            int left = 0, right = s2.size()-1;
            while(left <= right){
                int mid = (left + right) / 2;
                if(s2[mid] <= -target) left = mid+1;
                else right = mid - 1;
            }
            int index1 = left-1;
            left = 0, right = s2.size()-1;
            while(left <= right){
                int mid = (left + right) / 2;
                if(s2[mid] >= -target) right = mid - 1;
                else left = mid + 1;
            }
            int index2 = right+1;
            ret += max(0, index1 - index2 + 1);
        }
        return ret;
    }
};