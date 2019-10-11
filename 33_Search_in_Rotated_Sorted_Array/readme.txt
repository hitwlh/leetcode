33_Search_in_Rotated_Sorted_Array


题目大意
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

解决方案
这几题一起联合看
33 Search in Rotated Sorted Array
81  Search in Rotated Sorted Array II   
153 Find Minimum in Rotated Sorted Array 
154 Find Minimum in Rotated Sorted Array II  

观察到这种数组的特点，这类题就会变得非常好解。

那就是一个区间内，如果左端比右端小，那这个区间就一定是递增的，而且如果把整个区间分为2半，一定有一边是递增的。
需要注意的是一定要用nums[mid]和nums[right]比较来判断左侧还是右侧递增，如果用nums[left]和nums[mid]来判断，当right-left=1时，mid=left，那么nums[left]和nums[mid]的比较就无意义了。
因此只需要在判断哪边递增，然后再判断下一次查找应该往哪边查就ok了
样例


