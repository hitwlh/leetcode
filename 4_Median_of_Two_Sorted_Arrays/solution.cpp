class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if((n1 + n2) % 2)
            return findk(nums1, 0, n1-1, nums2, 0, n2-1, (n1 + n2) / 2 + 1);
        return (findk(nums1, 0, n1-1, nums2, 0, n2-1, (n1 + n2) / 2 + 1) + findk(nums1, 0, n1-1, nums2, 0, n2-1, (n1 + n2) / 2)) / 2;
    }
private:
    double findk(vector<int>& nums1, int ln1, int rn1, vector<int>& nums2, int ln2, int rn2, int k){
        if(ln1 > rn1) return nums2[ln2 + k - 1];
        if(ln2 > rn2) return nums1[ln1 + k - 1];
        int mid1 = ln1 + (rn1 - ln1) / 2, mid2 = ln2 + (rn2 - ln2) / 2;
        int left_count = mid1 - ln1 + 1 + mid2 - ln2;
        if(nums1[mid1] < nums2[mid2]){
            if(k > left_count) return findk(nums1, mid1 + 1, rn1, nums2, ln2, rn2, k - (mid1 - ln1 + 1));
            return findk(nums1, ln1, rn1, nums2, ln2, mid2-1, k);
        }else if(nums1[mid1] > nums2[mid2]){
            if(k > left_count) return findk(nums1, ln1, rn1, nums2, mid2+1, rn2, k - (mid2 - ln2 + 1));
            return findk(nums1, ln1, mid1-1, nums2, ln2, rn2, k);
        }else{
            if(k== left_count || k == left_count + 1) return nums1[mid1];
            if(k < left_count) return findk(nums1, ln1, mid1-1, nums2, ln2, mid2-1, k);
            return findk(nums1, mid1+1, rn1, nums2, mid2+1, rn2, k - (left_count + 1));
        }
    }
};












class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if((n1 + n2) % 2)
            return findk(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), (n1 + n2) / 2 + 1);
        return (findk(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), (n1 + n2) / 2 + 1) + findk(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), (n1 + n2) / 2)) / 2;
    }
private:
    double findk(vector<int>::iterator begin1, vector<int>::iterator end1, vector<int>::iterator begin2, vector<int>::iterator end2, int k){
        if(begin1 == end1) return *(begin2 + k - 1);
        if(begin2 == end2) return *(begin1 + k - 1);
        int mid1 = (end1 - begin1) / 2, mid2 = (end2 - begin2) / 2;
        if(*(begin1 + mid1) < *(begin2 + mid2)){
            if(k > mid1 + mid2 + 1) 
                return findk(begin1 + mid1 + 1, end1, begin2, end2, k - (mid1 + 1));
            return findk(begin1, end1, begin2, begin2 + mid2, k);
        }else if(*(begin1 + mid1) > *(begin2 + mid2)){
            if(k > mid1 + mid2 + 1) return findk(begin1, end1, begin2 + mid2 + 1, end2, k - (mid2 + 1));
            return findk(begin1, begin1 + mid1, begin2, end2, k);
        }else{
            if(k== mid1 + mid2 + 1 || k == mid1 + mid2 + 2) return *(begin1 + mid1);
            if(k < mid1 + mid2 + 1)
                return findk(begin1, begin1 + mid1, begin2, begin2 + mid2, k);
            return findk(begin1 + mid1 + 1, end1, begin2 + mid2 + 1, end2, k - (mid1 + mid2 + 2));
        }
    }
};