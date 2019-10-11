283_Move_Zeroes


题目大意
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

将一个给定数组中所有的0都移到后面，把非零数前移
要求不能改变非零数的相对应的位置关系，而且不能拷贝额外的数组

解决方案
solution.cpp
参考了网上的思想，把所有的非零写在前面，然后往非零的后面写零

solution2.cpp
用两个指针，其中一个指向正处理的，一个指向连续的零的起始index，每次遇到非零的，和连续零的第一个零互换位置即可

样例


