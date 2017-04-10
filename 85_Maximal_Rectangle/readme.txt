85_Maximal_Rectangle


题目大意
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

解决方案
调用84题的结果就是了，把这个二维点阵逐行扫描并且转化成"矩形"序列，时间复杂度是点阵的大小

样例
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 6.

