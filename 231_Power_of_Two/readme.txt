231_Power_of_Two


题目大意
Given an integer, write a function to determine if it is a power of two.

解决方案
如果n是2的次幂，则二进制表示是右边一串0，左边一个1，n-1是原先的1变为0，原先右边的0变为1.
因此会有n & (n-1) == 0

样例


