240_Search_a_2D_Matrix_II


题目大意
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.






解决方案

solution1.cpp
第一种方法是二分搜索。先在matrix[0]里横向二分搜索，找到等于target或第一个小于target的，然后对所有起点小于target的列，纵向二分搜索
时间复杂度是m*O(logn)

solution2.cpp
以右上角为搜索起点。如果当前的点等于target，返回true
若大于target，说明当前点下面所有点都大于target，往左走一步
若小于target，说明当前点左边所有点都小于target，往下走一步
时间复杂度是(m + n)




样例
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

