120_Triangle


题目大意
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

解决方案
就是动态规划
minPath[i][j]=min(minPath[i−1][j−1],minPath[i−1][j])+triangle[i][j]
这个的解法在solution1.cpp

求第i层的路径时只用到了第i-1层，i-2层以前的数据都不再需要
minPath[j]=min(minPath[j−1],minPath[j])+triangle[i][j]
这样就可以节省空间
这个的解法在solution2.cpp


具体编码时可以从上往下也可以从下往上
从下往上的话直接返回minPath[0][0]或minPath[0]就是了
从上往下的话要返回最后一行的最大值


样例
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

