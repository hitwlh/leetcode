39_Combination_Sum


题目大意
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
The same repeated number may be chosen from C unlimited number of times.
Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.


解决方案
用回溯的方法解决。注意由于每次可以添加的内容不清楚(不一定就是下一个而已，可能隔很远的一个)，所以要用for循环

样例
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]

