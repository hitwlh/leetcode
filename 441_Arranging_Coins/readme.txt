441_Arranging_Coins


题目大意
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.
Given n, find the total number of full staircase rows that can be formed.
n is a non-negative integer and fits within the range of a 32-bit signed integer.

解决方案
其实就是个二次方方程求解。
条件是
x*(x+1) <= n
(x+1)*(x+2) > n
解这个方程得到
x 属于 (sqrt(2*n + 1/4)-3/2, sqrt(2*n + 1/4)-1/2]
把右边的数字向下取整就行了


solutio2.cpp 二分法

样例
Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.

