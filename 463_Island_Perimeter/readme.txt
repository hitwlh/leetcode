463_Island_Perimeter


题目大意
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.



解决方案
给一张图，这张图上有且只有一个岛，并且岛里面没有水。求岛的周长。
乍看上去好像是广搜，其实直接遍历整张图，然后碰到岛屿的点看上下左右是否是岛屿就ok了

样例
Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:

