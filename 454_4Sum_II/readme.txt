454_4Sum_II


题目大意
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.




解决方案
先把2个vector里所有二元和建立到hash里，然后对另两个vector遍历，看hash里相反数的个数。看一下代码非常清楚。

solutoin2.cpp
用二分法，把前2个列表、后两个列表分别作和，然后遍历第一个列表的元素s1[i],在第二个列表里找-s1[i]
这里好玩的地方在于，要求第二个列表里有多少个-s1[i]，我的代码一遍ac，非常爽。要分别求-target的最左侧和最右侧，非常有意思！


样例
Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

