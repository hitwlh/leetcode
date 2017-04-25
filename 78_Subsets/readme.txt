78_Subsets


题目大意
Given a set of distinct integers, nums, return all possible subsets.
Note: The solution set must not contain duplicate subsets.

解决方案
递归的解法
下一层的有答案之后，再把当前元素和下一层结合起来对下一层结果double

样例
For example,
If nums = [1,2,3], a solution is:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

