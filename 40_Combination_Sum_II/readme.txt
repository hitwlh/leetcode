40_Combination_Sum_II


题目大意
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

解决方案
和39题很像，就是每次递归的时候增加两点：
1. 用了当前这个之后用下一个(而不是仍然用当前)
2. 当前点找完之后要往后面找到跟下一个不一样的点进行递归

样例
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

