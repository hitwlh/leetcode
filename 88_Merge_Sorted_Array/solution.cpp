class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m+n-1;i>=n;i--)
            nums1[i] = nums1[i-n];
        //这里的拷贝要从后往前拷贝，不然会覆盖掉有用的元素
        int index_m = n;
        int index_n = 0;
        int total_index = 0;
        while(m>0 && n>0){
            if(nums1[index_m]>nums2[index_n]){
                nums1[total_index++] = nums2[index_n++];
                n--;
            }
            else{
                nums1[total_index++] = nums1[index_m++];
                m--;
            }
        }
        if(m <= 0){
            while(n){
                nums1[total_index++] = nums2[index_n++];
                n--;
            }
        }
    }
};