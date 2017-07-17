397_Integer_Replacement


题目大意
Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

解决方案
1. 直接求解，递归

one-time-attention
注意INT_MAX不能做+1，会溢出

2. 
偶数直接除2，奇数可以+1或-1，应该选哪个？
方法是选能整除4的那个。以99为例子
A.99+1=100, 50, 25
B.99-1=98,  49

B分为CD两种

C.49+1=50, 这个方案比A到50花的步数比A多1步 排除
D.49-1=48, 98, 49, 48, 24, A的第四个数可以是24也可以是26，所以任然是A更优
所以在AB两种方案时，应该选A，也就是选能被4整除的选择。

one-time-attention
1. 
注意：3的时候应该直接-1，比+1快
3, 2, 1
3, 4, 2, 1 

2.
n要改为long long


样例
Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
Example 2:

Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1