26_Remove_Duplicates_from_Sorted_Array


题目大意
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.

解决方案
这题自以为非常非常简单，但是却出现了一个很容易出现的错误！！！
那就是erase之后，i当前就直接指向了新的vector需要访问的变量，不需要在自增
非常关键！！

样例

Given input array nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
