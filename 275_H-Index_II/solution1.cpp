class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size()-1, ret = 0, size = citations.size();
        while(left <= right){
            int mid = (left + right) / 2;
            if(citations[mid] >= size - mid){
                ret = max(ret, size - mid);
                right = mid-1;
            }else
                left = mid+1;
        }
        return ret;
    }
};