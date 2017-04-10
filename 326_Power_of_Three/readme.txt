326_Power_of_Three


题目大意
Given an integer, write a function to determine if it is a power of three.

解决方案
这题直接参考了网上的解答
输入一个数 n，如果 n 是3的幂，那么 3^x = n, 即 x = log10(n) / log10(3), 这里使用了换底公式。那么这样的话就好办了，如果 n 是3的幂，那么x肯定是一个整数，
用求底运算！！！

样例


