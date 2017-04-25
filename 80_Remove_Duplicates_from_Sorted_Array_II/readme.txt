80_Remove_Duplicates_from_Sorted_Array_II


题目大意
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?


解决方案
挺简单的，往后看第2个是否相等，如果相等就erase，直到不相等或者到尾
如果不相等，往后看第1个是否相等，如果相等就+=2， 如果不相等就+=1 solution.cpp

更早的版本写的是往后找到第一个不同的index，这样的话就可以一次erase一个区间，但是貌似耗时差不了太多，写起来还麻烦一些，就不记录在这了




样例
For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

