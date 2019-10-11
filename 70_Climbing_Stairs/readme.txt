70_Climbing_Stairs


题目大意
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.



解决方案
f(n) = f(n-1) + f(n-2) 就是斐波那契数列，但是递归方式会超时，用非递归解法

样例


