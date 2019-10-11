62_Unique_Paths


题目大意
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


求所有不同的路径的个数


解决方案
就是从(m+n-2)中选(m-1)或(n-1)，非常简单

solution2.cpp
动态规划，走到某个地方的方案数等于走到上面和走到左边的方案数之和

样例


