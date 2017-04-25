63_Unique_Paths_II


题目大意
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

解决方案
62. Unique Paths的进阶版本
62题就是(m+n)里选(m)个，但是这里有障碍物。那就是简单的动态规划就可以解决了

样例
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

