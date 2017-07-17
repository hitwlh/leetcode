413_Arithmetic_Slices


题目大意
A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.


For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.
1, 1, 2, 5, 7


A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


解决方案
一个大的等差数列，假设共有n个数字，则这个等差数列内部共有1+2+3+...+(n-2)个子等差数列，也就是(n-1)*(n-2)/2
只需要从第一个元素开始往右找所有最长的等差数列。
以第一个数字为起点，往右找到等差数列右侧，累计这个等差数列内部共有多少子等差数列，然后将右侧作为新的等差数列的起点，就ok了




样例
Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.

