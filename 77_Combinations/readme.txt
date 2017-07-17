77_Combinations


题目大意
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.



解决方案
就是求c(n,k)的所有可能组合

第一个位置可能是1, ..., n，记作i
第二个位置可能是i+1, i+2, ..., n
用一个循环就ok，直接看代码，很容易懂


样例
For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

