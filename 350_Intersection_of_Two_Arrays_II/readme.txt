350_Intersection_of_Two_Arrays_II


题目大意
Given two arrays, write a function to compute their intersection.

解决方案
直接两重循环(需要erase)，记录在solution1.cpp中
或者分别sort之后再扫描，记录在solution2.cpp中
用unordered_map，记录在solution3.cpp中

样例
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

