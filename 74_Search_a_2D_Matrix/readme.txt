74_Search_a_2D_Matrix


题目大意
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

解决方案
挺简单的二分搜索，就是分了两维而已
one-time-attention
if(matrix.empty() || matrix[0].empty()) return false;
一开始写成了if(matrix.empty())，输入[[]]会错

样例
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

