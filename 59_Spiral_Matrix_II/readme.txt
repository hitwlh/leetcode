59_Spiral_Matrix_II


题目大意
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

解决方案
跟54. Spiral Matrix很像，直接把m改成n，把push换成赋值操作就是了

one-time-attention
一开始要对n自减，因为n代表的是闭区间右端，如果直接访问n是刚好越界了

样例

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

