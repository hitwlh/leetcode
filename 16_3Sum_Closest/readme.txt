16_3Sum_Closest


题目大意
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

解决方案
用15_3Sum一样的方法，只是target不是0，而是从target开始，左右搜索，直到得到正确的解

样例
S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).