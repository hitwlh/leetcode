400_Nth_Digit


题目大意
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).






解决方案
先找到属于哪个数字，然后找到属于那个数字的哪一位
one-time-attention
求数字是应该用n-1，因为如果n==flag，应该还在第一个数字上(比如n等于flag等于4时，应该是1000里找)，而非进入第二个数字(1001中找)。
int number = (n-1) / flag + pow(10, flag-1);





样例
Example 1:

Input:
3

Output:
3




Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

