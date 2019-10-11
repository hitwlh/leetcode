349_Intersection_of_Two_Arrays


题目大意
Given two arrays, write a function to compute their intersection.

解决方案
这题是在考察怎么sort和去重。把两个数组都sort并去重之后
就直接进行遍历就是了,这步的时间复杂度是两个数组的长度之和

solution.cpp
unordered_map的解法
样例
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

