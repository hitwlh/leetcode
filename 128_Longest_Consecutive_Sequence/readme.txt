128_Longest_Consecutive_Sequence


题目大意
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

解决方案
找最长连续串
用哈希函数！！！！想到这点的话这题就会变得非常简单
c++ stl中的unordered_set是哈希函数实现的！！！

solution.cpp中用的是unordered_set，就能实现O(n)，事实上改为基于比较的set，也能ac




样例
For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity.

