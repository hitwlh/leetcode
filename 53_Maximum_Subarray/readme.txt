53_Maximum_Subarray


题目大意
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

解决方案
动态规划的解法，递推公式sum[i] = max(use_big[i], sum[i-1]);




进阶版本(不是leetcode里的）:
求最大子矩阵。参考思路：http://www.cnblogs.com/fll/archive/2008/05/17/1201543.html
MxN矩阵
就是对行进行枚举，遍历所有行的可能性C(M, 2)，记作i(上方)、j（下方）， 然后处理i和j之间的列，把列给打扁，就变成了一条线段了，求最长段的方法就是53题里的，复杂度是O(N)
总复杂度是O(N*M^2)


样例
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

