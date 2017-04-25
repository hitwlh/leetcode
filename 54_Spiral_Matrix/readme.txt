54_Spiral_Matrix


题目大意
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

解决方案
这题关键在于边界条件。如果处理到一行或者一列或者单个元素该怎么办
一开始我想的是递归解法，先处理四周，然后把起点和终点坐标调整后递归调用来处理那个四条边界内部的更小的矩形，但是这样发现代码挺麻烦，因为要区分一行或一列或单个元素需要分开写。solution1.cpp
参考网上的代码，直接处理，处理完了起点和重点坐标调整后继续往下做。solution2.cpp

四条边界的处理方式：第一条全写(包含起点终点)，第二条写终点不写起点，第三条写终点不写起点，第四条不写起点、不写终点。
然后在写第三、四条时要判断下第三条、第四条是否存在(否则会重合着写第一条、第四条)

写的策略：起点终点都用闭区间，我自己写的代码起点是闭区间终点是开区间，特别容易错

样例

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].


[6, 9, 7]
return [6, 9, 7]