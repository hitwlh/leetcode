153_Find_Minimum_in_Rotated_Sorted_Array


题目大意
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
You may assume no duplicate exists in the array.

解决方案
这几题一起联合看
33 Search in Rotated Sorted Array
81  Search in Rotated Sorted Array II   
153 Find Minimum in Rotated Sorted Array 
154 Find Minimum in Rotated Sorted Array II  

观察到这种数组的特点，这类题就会变得非常好解。

那就是一个区间内，如果左端比右端小，那这个区间就一定是递增的，而且如果把整个区间分为2半，一定有一边是递增的。
因此只需要在判断哪边递增，递增的那边因为知道左右index，获取其最小值开销是O（1），另一边用递归做就是了

样例


