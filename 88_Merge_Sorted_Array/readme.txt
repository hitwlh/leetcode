88_Merge_Sorted_Array


题目大意
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

解决方案
这题是要求只能把结果保留在原始的vector里头，所以直接把nums1的元素搬到后面去，前面留出|nums2|个空位，这样就不用担心覆盖掉有效数据了

样例


