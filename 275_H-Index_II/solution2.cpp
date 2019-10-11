class Solution {
public:
    int hIndex(vector<int>& citations) {
        return search(citations, 0, citations.size()-1);
    }
private:
    int search(vector<int>& citations, int left, int right) {
        if(left > right) return 0;
        int mid = (left + right) / 2, size = citations.size();
        if(citations[mid] >= citations.size() - mid)
            return max(size - mid, search(citations, left, mid-1));
        return search(citations, mid+1, right);
    }
};