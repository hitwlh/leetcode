215_Kth_Largest_Element_in_an_Array


题目大意
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.



解决方案
最基础的就是直接sort然后找第k大的，在solution.cpp。时间复杂度是O(nlogn)

solution1.cpp
用大小为k的大根堆，先把前k个元素入堆，建立好堆，然后往后遍历，某个元素如果比堆顶大，则把它入堆并弹出堆顶，最后返回堆顶就是了O(nlogk)

solution2.cpp
用quickselect，每次挑一个元素pivot，然后用sort colors的方法把原数组分为左、中、右。(左边的是小于pivot, 右边大于pivot， 中间等于pivot)。然后看k是否在中间部分，如果是就返回，如果不是则进入左右处理。

one-time-attention
1. solution1.cpp和solution2.cpp里都要先k = nums.size() + 1 - k;因为我做的时候是找第k小。而题目是要第k大。这个容易忘记
2. solution2.cpp里第24行是R=R，一开始写成了R=nums.size()-1是错的。如果进入右半部分，右边的右界就是上一轮的右界才对！！！

样例
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

