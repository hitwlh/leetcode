42_Trapping_Rain_Water


题目大意
题目网址https://leetcode.com/problems/trapping-rain-water/#/description
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
就是一个蓄水池，然后看整个蓄水池能蓄多少水

解决方案
每个格子的蓄水量由左侧最高格子和右侧最高格子决定，因此定义left、right数组
left_MAX[i] 表示从height[0]到height[i-1]的最高格子
right_MAX[i] 表示从height[i]到height[end]的最高格子
求left和right数组的时间开销是O(n)
格子i的蓄水量是min(left_MAX[i+1], right_MAX[i]) - height[i]
因此最后遍历一遍累加蓄水量就ok了

第11、42、84、85题结合看

样例
For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


