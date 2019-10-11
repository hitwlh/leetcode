55_Jump_Game


题目大意
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
有一个非负整数的数组，每个数字表示在当前位置的基础上最多可以走的步数，求判断能不能到达最后一个位置

解决方案
就是每步该往哪里跳要向后看，看到后面最好的地方跳过去。贪心算法

solution2.cpp
直接遍历在每个地方可以跳到的最远的地方，如果遍历到某个地方，是跳不到的，就返回false；跳到终点，返回true

样例
For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.

