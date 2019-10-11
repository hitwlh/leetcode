329_Longest_Increasing_Path_in_a_Matrix


题目大意
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).







解决方案
遍历整张表，如果遍历到的点已经被处理过，直接返回
如果没处理过，看它上下左右四个相邻点，如果i大于其上、下、左、右，则可将i作为起点，去上、下、左、右，因此获得上下左右的长度就是了，如果上下左右没处理过，则递归处理
这应该不算动态规划，但是有一点像。妙处在于以i作为起点递归处理上下左右时，说明上下左右比i大，那递归处理上下左右的时候就一定不会经过i，因此不用担心死循环





样例
Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

