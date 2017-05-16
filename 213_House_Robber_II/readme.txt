213_House_Robber_II


题目大意
After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

解决方案
198. House Robber的进阶版本，就是改为现在认为第一个数和最后一个数相邻了。
只需要做两次dp搜索。第一次从0开始，并且不能选最后一个；第二次从1开始，能选最后一个。返回更大的那个就ok了

样例


