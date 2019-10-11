class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i, j, now = m+n-1;
        for(i = m-1, j = n-1; i >= 0 && j >= 0;){
            if(nums1[i] > nums2[j])
                nums1[now--] = nums1[i--];
            else
                nums1[now--] = nums2[j--];
        }
        while(j--){
            nums1[j] = nums2[j];
        }
    }
};