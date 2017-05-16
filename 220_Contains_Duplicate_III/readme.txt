220_Contains_Duplicate_III


题目大意
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

解决方案
用一个map，里头保存满足下标关系的数。
起始：空
nums[0]
nums[0] nums[1]
nums[0] nums[1] nums[2]
...
nums[0] nums[1] nums[2] ... nums[k]
nums[1] nums[2] ... nums[k] nums[k+1]
...
然后根据最右边的数字去查找在map里头最靠近nums[k] - t的数，用lower_bound
然后再看看找到的数是否满足差的绝对值<=k，如果行就ok了

one-time-attention
这题的两个int操作可能超出int范围，要用long long存储操作结果


样例


